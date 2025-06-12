

#include "LootLockerAdminHttpClient.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Array.h"
#include "JsonObjectConverter.h"
#include "Interfaces/IHttpResponse.h"
#include "Misc/FileHelper.h"
#include "LootLockerAdminLogger.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Guid.h"

ULootLockerAdminHttpClient* ULootLockerAdminHttpClient::Instance = nullptr;

ULootLockerAdminHttpClient& ULootLockerAdminHttpClient::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = NewObject<ULootLockerAdminHttpClient>();

		Instance->AddToRoot();
	}
	return *Instance;
}

ULootLockerAdminHttpClient::ULootLockerAdminHttpClient()
	: UserAgent(FString::Format(TEXT("X-UnrealEngineServer-Agent/{0}"), { ENGINE_VERSION_STRING }))
	, UserInstanceIdentifier(FGuid::NewGuid().ToString())
{
	if (SDKVersion.IsEmpty())
	{
		const TSharedPtr<IPlugin> Ptr = IPluginManager::Get().FindPlugin("LootLockerAdminSDK");
		if (Ptr.IsValid())
		{
			SDKVersion = Ptr->GetDescriptor().VersionName;
			ULootLockerAdminLogger::Log(ELootLockerAdminLogLevel::Verbose, FString::Format(TEXT("LootLockerAdmin version: v{0}"), { SDKVersion }));
		}
	}
}

void ULootLockerAdminHttpClient::SendRequest_Internal(HTTPRequest InRequest) const
{
	FHttpModule* HttpModule = &FHttpModule::Get();
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = HttpModule->CreateRequest();

	Request->SetURL(InRequest.EndPoint);

	Request->SetHeader(TEXT("User-Agent"), UserAgent);
	Request->SetHeader(TEXT("User-Instance-Identifier"), UserInstanceIdentifier);
	Request->SetHeader(TEXT("SDK-Version"), SDKVersion);
	Request->SetHeader(TEXT("Content-Type"), InRequest.ContentType);
	Request->SetHeader(TEXT("Accepts"), TEXT("application/json"));

	const ULootLockerAdminConfig* config = GetDefault<ULootLockerAdminConfig>();
	Request->SetHeader(TEXT("LL-Version"), config->LootLockerVersion);

	for (const TTuple<FString, FString>& CustomHeader : InRequest.CustomHeaders)
	{
		Request->SetHeader(CustomHeader.Key, CustomHeader.Value);
	}

	Request->SetVerb(InRequest.RequestType);
	Request->SetContentAsString(InRequest.Data);

	FString DelimitedHeaders = "";
	TArray<FString> AllHeaders = Request->GetAllHeaders();
	for (auto Header : AllHeaders)
	{
        DelimitedHeaders += TEXT("    ") + Header + TEXT("\n");
	}
	ULootLockerAdminLogger::Log(ELootLockerAdminLogLevel::Verbose, FString::Format(TEXT("Request {0} to endpoint {1}\n  With headers {2}\n  And with content: {3}"), { Request->GetVerb(), *Request->GetURL(), *DelimitedHeaders, *InRequest.Data }));

	Request->OnProcessRequestComplete().BindLambda([InRequest](FHttpRequestPtr Req, FHttpResponsePtr Response, bool bWasSuccessful)
	{
		if (!Response.IsValid())
		{
			FLootLockerAdminResponse Error = LootLockerAdminResponseFactory::Error<FLootLockerAdminResponse>("HTTP Response was invalid", LootLockerAdminStaticRequestErrorStatusCodes::LL_ERROR_INVALID_HTTP);
			LogFailedRequestInformation(Error, InRequest.RequestType, InRequest.EndPoint, InRequest.Data, TArray<FString>());
			InRequest.OnCompleteRequest.ExecuteIfBound(Error);
			return;
		}
		FLootLockerAdminResponse response;
		response.Success = ResponseIsSuccess(Response, bWasSuccessful);
		response.StatusCode = Response->GetResponseCode();
		response.FullTextFromServer = Response->GetContentAsString();
		if (!response.Success)
		{
			FJsonObjectConverter::JsonObjectStringToUStruct<FLootLockerAdminErrorData>(
				response.FullTextFromServer, &response.ErrorData, 0, 0);
			if (response.ErrorData.Code.IsEmpty())
			{
				response.ErrorData.Message = response.FullTextFromServer;
			}

			FString RetryAfterHeader = Response->GetHeader("retry-after");
			if (!RetryAfterHeader.IsEmpty())
			{
				response.ErrorData.Retry_after_seconds = FCString::Atoi(*RetryAfterHeader);
			}
			LogFailedRequestInformation(response, InRequest.RequestType, InRequest.EndPoint, InRequest.Data, Response->GetAllHeaders());
		}
		else
		{
			LogSuccessfulRequestInformation(response, InRequest.RequestType, InRequest.EndPoint, InRequest.Data, Response->GetAllHeaders());
		}
		InRequest.OnCompleteRequest.ExecuteIfBound(response);
	});
	Request->ProcessRequest();
}

void ULootLockerAdminHttpClient::UploadFile_Internal(const FString& FilePath, const TMap<FString, FString> AdditionalFields, HTTPRequest InRequest) const
{
	TArray<uint8> RawData;
	if (!FFileHelper::LoadFileToArray(RawData, *FilePath)) {
		InRequest.OnCompleteRequest.ExecuteIfBound(LootLockerAdminResponseFactory::Error<FLootLockerAdminResponse>(FString::Format(TEXT("Could not read file {0}"), { FilePath }), LootLockerAdminStaticRequestErrorStatusCodes::LL_ERROR_INVALID_INPUT));
		return;
	}

	int32 LastSlashPos;
	FilePath.FindLastChar('/', LastSlashPos);
	FString FileName = FilePath.RightChop(LastSlashPos + 1);

	UploadRawFile_Internal(RawData, FileName, AdditionalFields, InRequest);
}

void ULootLockerAdminHttpClient::UploadRawFile_Internal(const TArray<uint8>& RawData, const FString& FileName, const TMap<FString, FString> AdditionalFields, HTTPRequest InRequest) const
{
	FHttpModule* HttpModule = &FHttpModule::Get();
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = HttpModule->CreateRequest();

	Request->SetURL(InRequest.EndPoint);

	FString Boundary = "lootlockerboundary";

	Request->SetHeader(TEXT("User-Agent"), UserAgent);
	Request->SetHeader(TEXT("User-Instance-Identifier"), UserInstanceIdentifier);
	Request->SetHeader(TEXT("SDK-Version"), SDKVersion);
	Request->SetHeader(TEXT("Content-Type"), TEXT("multipart/form-data; boundary=" + Boundary));

	for (const TTuple<FString, FString>& CustomHeader : InRequest.CustomHeaders)
	{
		Request->SetHeader(CustomHeader.Key, CustomHeader.Value);
	}

	Request->SetVerb(InRequest.RequestType);

	TArray<uint8> Data;

	const FString BeginBoundary = TEXT("\r\n--" + Boundary + "\r\n");
	const FString EndBoundary = TEXT("\r\n--" + Boundary + "--\r\n");

	for (const TTuple<FString, FString>& KeyValuePair : AdditionalFields) {
		Data.Append((uint8*)TCHAR_TO_ANSI(*BeginBoundary), BeginBoundary.Len());

		FString ParameterEntry = "Content-Type: text/plain; charset=\"utf-8\"\r\n";
		ParameterEntry.Append(TEXT("Content-Disposition: form-data; name=\""));
		ParameterEntry.Append(KeyValuePair.Key);
		ParameterEntry.Append(TEXT("\"\r\n\r\n"));
		ParameterEntry.Append(KeyValuePair.Value);

		Data.Append((uint8*)TCHAR_TO_ANSI(*ParameterEntry), ParameterEntry.Len());
	}

	Data.Append((uint8*)TCHAR_TO_ANSI(*BeginBoundary), BeginBoundary.Len());

	FString FileHeader = (TEXT("Content-Type: application/octet-stream\r\n"));
	FileHeader.Append(TEXT("Content-disposition: form-data; name=\"file\"; filename=\""));

	FileHeader.Append(FileName + "\"\r\n\r\n");

	Data.Append((uint8*)TCHAR_TO_ANSI(*FileHeader), FileHeader.Len());
	Data.Append(RawData);
	Data.Append((uint8*)TCHAR_TO_ANSI(*EndBoundary), EndBoundary.Len());

	Request->SetContent(Data);

	FString DelimitedHeaders = "";
	TArray<FString> AllHeaders = Request->GetAllHeaders();
	for (auto Header : AllHeaders)
	{
        DelimitedHeaders += TEXT("    ") + Header + TEXT("\n");
	}

	ULootLockerAdminLogger::Log(ELootLockerAdminLogLevel::Verbose, FString::Format(TEXT("Request {0} to endpoint {1}\n  With headers {2}\n  And with content: {3}"), { Request->GetVerb(), Request->GetURL(), DelimitedHeaders, FString("File Content") }));

	Request->OnProcessRequestComplete().BindLambda([this, InRequest](FHttpRequestPtr Req, FHttpResponsePtr Response, bool bWasSuccessful)
	{
		if (!Response.IsValid())
		{
			FLootLockerAdminResponse Error = LootLockerAdminResponseFactory::Error<FLootLockerAdminResponse>("HTTP Response was invalid", LootLockerAdminStaticRequestErrorStatusCodes::LL_ERROR_INVALID_HTTP);
			LogFailedRequestInformation(Error, InRequest.RequestType, InRequest.EndPoint, FString("Data Stream"), TArray<FString>());
			InRequest.OnCompleteRequest.ExecuteIfBound(Error);
			return;
		}
		FLootLockerAdminResponse response;
		response.Success = ResponseIsSuccess(Response, bWasSuccessful);
		response.StatusCode = Response->GetResponseCode();
		response.FullTextFromServer = Response->GetContentAsString();
		if (!response.Success)
		{
			FJsonObjectConverter::JsonObjectStringToUStruct<FLootLockerAdminErrorData>(
				response.FullTextFromServer, &response.ErrorData, 0, 0);
			if (response.ErrorData.Code.IsEmpty())
			{
				response.ErrorData.Message = response.FullTextFromServer;
			}

			FString RetryAfterHeader = Response->GetHeader("retry-after");
			if (!RetryAfterHeader.IsEmpty())
			{
				response.ErrorData.Retry_after_seconds = FCString::Atoi(*RetryAfterHeader);
			}
			LogFailedRequestInformation(response, InRequest.RequestType, InRequest.EndPoint, FString("Data Stream"), Response->GetAllHeaders());
		}
		else
		{
			LogSuccessfulRequestInformation(response, InRequest.RequestType, InRequest.EndPoint, FString("Data Stream"), Response->GetAllHeaders());
		}

		InRequest.OnCompleteRequest.ExecuteIfBound(response);
	});
	Request->ProcessRequest();
}

bool ULootLockerAdminHttpClient::ResponseIsSuccess(const FHttpResponsePtr& InResponse, bool bWasSuccessful)
{
	if (!bWasSuccessful || !InResponse.IsValid())
		return false;

	return EHttpResponseCodes::IsOk(InResponse->GetResponseCode());
}

void ULootLockerAdminHttpClient::LogFailedRequestInformation(const FLootLockerAdminResponse& Response, const FString& RequestMethod, const FString& Endpoint, const FString& Data, const TArray<FString>& ResponseHeaders)
{
	FString LogString = FString::Format(TEXT("{0} request to {1} failed"), { RequestMethod, Endpoint });
	const bool IsInformativeError = !Response.ErrorData.Code.IsEmpty();
	if (IsInformativeError)
	{
		LogString += FString::Format(TEXT("\n   {0}"), { Response.ErrorData.Message });
		LogString += FString::Format(TEXT("\n    Error Code: {0}"), { Response.ErrorData.Code });
		LogString += FString::Format(TEXT("\n    Further Information: {0}"), { Response.ErrorData.Doc_url });
		LogString += FString::Format(TEXT("\n    Request ID: {0}"), { Response.ErrorData.Request_id });
		LogString += FString::Format(TEXT("\n    Trace ID: {0}"), { Response.ErrorData.Trace_id });
	}
	LogString += FString::Format(TEXT("\n   HTTP Status code : {0}"), { Response.StatusCode });
	if (!Data.IsEmpty()) {
		LogString += FString::Format(TEXT("\n   Request Data: {0}"), { Data });
	}
	if (ResponseHeaders.Num() > 0)
	{
		LogString += FString::Format(TEXT("\n   -- Response Headers --"), { Data });
		for (FString ResponseHeader : ResponseHeaders)
		{
			LogString += FString::Format(TEXT("\n     {0}"), { ResponseHeader });
		}
	}

	if (!IsInformativeError)
	{
		LogString += FString::Format(TEXT("\n   Response Data: {0}"), { Response.FullTextFromServer });
	}
	LogString += "\n###";
	ULootLockerAdminLogger::Log(ELootLockerAdminLogLevel::Warning, LogString);
}

void ULootLockerAdminHttpClient::LogSuccessfulRequestInformation(const FLootLockerAdminResponse& Response, const FString& RequestMethod, const FString& Endpoint, const FString& Data, const TArray<FString>& ResponseHeaders)
{
	FString LogString = FString::Format(TEXT("{0} request to {1} succeeded"), { RequestMethod, Endpoint });
	LogString += FString::Format(TEXT("\n   HTTP Status code : {0}"), { Response.StatusCode });
	if (!Data.IsEmpty()) {
		LogString += FString::Format(TEXT("\n   Request Data: {0}"), { Data });
	}
	if (ResponseHeaders.Num() > 0)
	{
		LogString += FString::Format(TEXT("\n   -- Response Headers --"), { Data });
		for (FString ResponseHeader : ResponseHeaders)
		{
			LogString += FString::Format(TEXT("\n     {0}"), { ResponseHeader });
		}
	}

	LogString += FString::Format(TEXT("\n   Response Data: {0}"), { Response.FullTextFromServer });
	LogString += "\n###";
	ULootLockerAdminLogger::Log(ELootLockerAdminLogLevel::VeryVerbose, LogString);
}
