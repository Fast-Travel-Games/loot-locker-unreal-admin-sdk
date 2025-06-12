
#include "AdminAPI/LootLockerAdminSessionRequest.h"

#include "LootLockerAdminHttpClient.h"

ULootLockerAdminSessionRequest::ULootLockerAdminSessionRequest()
{
}

void ULootLockerAdminSessionRequest::CreateSession(FString Email, FString Password, const FLootLockerAdminCreateSessionResponseBP& OnCompletedRequestBP, const FLootLockerAdminCreateSessionResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	FLootLockerAdminCreateSessionRequest Request;
	Request.Email = Email;
	Request.Password = Password;
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminCreateSessionResponse>(
		Request,
		ULootLockerAdminEndpoints::CreateSession,
		{},
		EmptyQueryParams,
		OnCompletedRequestBP,
		OnCompletedRequest,
		ULootLockerAdminHttpClient::ResponseInspector<FLootLockerAdminCreateSessionResponse>::FLootLockerAdminResponseInspectorCallback::CreateLambda([](const FLootLockerAdminCreateSessionResponse& Response)
		{
			ULootLockerAdminStateData::SetAdminToken(Response.Auth_token);
		}),
		{{"LL-Version", Config->LootLockerVersion}});
}
