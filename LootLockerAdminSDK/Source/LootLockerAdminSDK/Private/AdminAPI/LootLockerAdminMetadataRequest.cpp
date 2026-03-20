
#include "AdminAPI/LootLockerAdminMetadataRequest.h"

#include "LootLockerAdminHttpClient.h"


//==================================================
// Metadata Entry Methods
//==================================================

bool FLootLockerAdminMetadataEntry::TryGetRawValue(TSharedPtr<FJsonValue>& Output) const
{
	if (!EntryAsJson.HasField(TEXT("value")))
	{
		return false;
	}
	Output = EntryAsJson.Values[TEXT("value")];
	return Output.IsValid();
}

void FLootLockerAdminMetadataEntry::SetValueAsString(const FString& Value)
{
	EntryAsJson.SetStringField(TEXT("value"), Value);
	Type = ELootLockerAdminMetadataTypes::String;
}

void FLootLockerAdminMetadataEntry::SetValueAsFloat(const float& Value)
{
	EntryAsJson.SetNumberField(TEXT("value"), Value);
	Type = ELootLockerAdminMetadataTypes::Number;
}

void FLootLockerAdminMetadataEntry::SetValueAsInteger(const int& Value)
{
	EntryAsJson.SetNumberField(TEXT("value"), Value);
	Type = ELootLockerAdminMetadataTypes::Number;
}

void FLootLockerAdminMetadataEntry::SetValueAsBool(const bool& Value)
{
	EntryAsJson.SetBoolField(TEXT("value"), Value);
	Type = ELootLockerAdminMetadataTypes::Bool;
}

void FLootLockerAdminMetadataEntry::SetRawValue(const TSharedPtr<FJsonValue>& Value)
{
	EntryAsJson.SetField(TEXT("value"), Value);
	Type = ELootLockerAdminMetadataTypes::Json;
}

void FLootLockerAdminMetadataEntry::SetValueAsJsonObject(const FJsonObject& Value)
{
	EntryAsJson.SetObjectField(TEXT("value"), MakeShared<FJsonObject>(Value));
	Type = ELootLockerAdminMetadataTypes::Json;
}

void FLootLockerAdminMetadataEntry::SetValueAsJsonArray(const TArray<TSharedPtr<FJsonValue>>& Value)
{
	EntryAsJson.SetArrayField(TEXT("value"), Value);
	Type = ELootLockerAdminMetadataTypes::Json;
}

void FLootLockerAdminMetadataEntry::SetValueAsBase64(const FLootLockerAdminMetadataBase64Value& Value)
{
	TSharedPtr<FJsonObject> JsonObject = FJsonObjectConverter::UStructToJsonObject(Value);
	if (!JsonObject.IsValid())
	{
		return;
	}
	SetValueAsJsonObject(*JsonObject);
}

FLootLockerAdminMetadataEntry FLootLockerAdminMetadataEntry::MakeStringEntry(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const FString& Value)
{
	FLootLockerAdminMetadataEntry Entry = _INTERNAL_MakeEntryExceptValue(Key, Tags, Access, ELootLockerAdminMetadataTypes::String);
	Entry.SetValueAsString(Value);
	return Entry;
}

FLootLockerAdminMetadataEntry FLootLockerAdminMetadataEntry::MakeFloatEntry(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const float& Value)
{
	FLootLockerAdminMetadataEntry Entry = _INTERNAL_MakeEntryExceptValue(Key, Tags, Access, ELootLockerAdminMetadataTypes::Number);
	Entry.SetValueAsFloat(Value);
	return Entry;
}

FLootLockerAdminMetadataEntry FLootLockerAdminMetadataEntry::MakeIntegerEntry(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const int Value)
{
	FLootLockerAdminMetadataEntry Entry = _INTERNAL_MakeEntryExceptValue(Key, Tags, Access, ELootLockerAdminMetadataTypes::Number);
	Entry.SetValueAsInteger(Value);
	return Entry;
}

FLootLockerAdminMetadataEntry FLootLockerAdminMetadataEntry::MakeBoolEntry(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const bool Value)
{
	FLootLockerAdminMetadataEntry Entry = _INTERNAL_MakeEntryExceptValue(Key, Tags, Access, ELootLockerAdminMetadataTypes::Bool);
	Entry.SetValueAsBool(Value);
	return Entry;
}

FLootLockerAdminMetadataEntry FLootLockerAdminMetadataEntry::MakeJsonValueEntry(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const ELootLockerAdminMetadataTypes Type, const TSharedPtr<FJsonValue> Value)
{
	FLootLockerAdminMetadataEntry Entry = _INTERNAL_MakeEntryExceptValue(Key, Tags, Access, ELootLockerAdminMetadataTypes::Json);
	Entry.SetRawValue(Value);
	return Entry;
}

FLootLockerAdminMetadataEntry FLootLockerAdminMetadataEntry::MakeJsonObjectEntry(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const FJsonObject& Value)
{
	FLootLockerAdminMetadataEntry Entry = _INTERNAL_MakeEntryExceptValue(Key, Tags, Access, ELootLockerAdminMetadataTypes::Json);
	Entry.SetValueAsJsonObject(Value);
	return Entry;
}

FLootLockerAdminMetadataEntry FLootLockerAdminMetadataEntry::MakeJsonArrayEntry(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const TArray<TSharedPtr<FJsonValue>>& Value)
{
	FLootLockerAdminMetadataEntry Entry = _INTERNAL_MakeEntryExceptValue(Key, Tags, Access, ELootLockerAdminMetadataTypes::Json);
	Entry.SetValueAsJsonArray(Value);
	return Entry;
}

FLootLockerAdminMetadataEntry FLootLockerAdminMetadataEntry::MakeBase64Entry(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const FLootLockerAdminMetadataBase64Value& Value)
{
	TSharedPtr<FJsonObject> JsonObject = FJsonObjectConverter::UStructToJsonObject(Value);
	if (!JsonObject.IsValid())
	{
		return FLootLockerAdminMetadataEntry();
	}
	FLootLockerAdminMetadataEntry Entry = _INTERNAL_MakeEntryExceptValue(Key, Tags, Access, ELootLockerAdminMetadataTypes::Json);
	Entry.SetValueAsJsonObject(*JsonObject);
	return Entry;
}

void FLootLockerAdminMetadataEntry::_INTERNAL_SetJsonRepresentation(const FJsonObject& obj)
{
	EntryAsJson = obj;
}

FLootLockerAdminMetadataEntry FLootLockerAdminMetadataEntry::_INTERNAL_MakeEntryExceptValue(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const ELootLockerAdminMetadataTypes Type)
{
	FLootLockerAdminMetadataEntry Entry;
	Entry.Key = Key;
	Entry.Tags = Tags;
	Entry.Type = Type;
	Entry.Access = Access;
	FJsonObject JsonRepresentation;
	JsonRepresentation.SetStringField(TEXT("key"), Key);
	TArray<TSharedPtr<FJsonValue>> TagArray;
	for (const FString& Tag : Tags)
	{
		TagArray.Add(MakeShared<FJsonValueString>(Tag));
	}
	JsonRepresentation.SetArrayField(TEXT("tags"), TagArray);
	JsonRepresentation.SetStringField(TEXT("type"), ULootLockerAdminEnumUtils::GetEnum(TEXT("ELootLockerAdminMetadataTypes"), static_cast<int32>(Type)).ToLower());
	Entry.EntryAsJson = JsonRepresentation;
	return Entry;
}

int FLootLockerAdminListMetadataResponse::__INTERNAL_GetEntryIndexByKey(const FString Key) const
{
	if (KeyToEntryIndex.Contains(Key))
	{
		const int* index = KeyToEntryIndex.Find(Key);
		if (index != nullptr && *index >= 0 && *index < Entries.Num())
		{
			const FLootLockerAdminMetadataEntry& EntryRef = Entries[*index];
			if (EntryRef.Key.Equals(Key))
			{
				return *index;
			}
		}
	}
	return -1;
}

void FLootLockerAdminListMetadataResponse::__INTERNAL_GenerateKeyMap()
{
	KeyToEntryIndex = TMap<FString, int>();
	int index = 0;
	for (FLootLockerAdminMetadataEntry& Entry : Entries)
	{
		KeyToEntryIndex.Add(Entry.Key, index++);
	}
}

//==================================================
// Metadata Request Handler
//==================================================

ULootLockerAdminMetadataRequest::ULootLockerAdminMetadataRequest()
{
}

void ULootLockerAdminMetadataRequest::ListMetadata(const ELootLockerAdminMetadataSources Source, const FString& SourceID, const int Page, const int PerPage, const FString& Key, const TArray<FString>& Tags, const bool IgnoreFiles, const FLootLockerAdminListMetadataResponseBP& OnCompleteBP, const FLootLockerAdminListMetadataResponseDelegate& OnComplete)
{
	TMultiMap<FString, FString> QueryParams;
	if (Page > 0) QueryParams.Add("page", FString::FromInt(Page));
	if (PerPage > 0) QueryParams.Add("per_page", FString::FromInt(PerPage));
	if (!Key.IsEmpty()) QueryParams.Add("key", Key);
	if (Tags.Num() > 0) {
		for (FString Tag : Tags)
		{
			QueryParams.Add("tags", Tag);
		}
	}
	if (IgnoreFiles) QueryParams.Add("ignore_files", "true");

	FString SourceAsString = ULootLockerAdminEnumUtils::GetEnum(TEXT("ELootLockerAdminMetadataSources"), static_cast<int32>(Source)).ToLower();
	SourceAsString.ReplaceCharInline(' ', '_');

	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminListMetadataResponse>(FLootLockerAdminEmptyRequest(), ULootLockerAdminEndpoints::ListMetadata, { Config->GameID, SourceAsString, SourceID }, QueryParams, FLootLockerAdminListMetadataResponseBP(), FLootLockerAdminListMetadataResponseDelegate(), ULootLockerAdminHttpClient::ResponseInspector<FLootLockerAdminListMetadataResponse>::FLootLockerAdminResponseInspectorCallback::CreateLambda([OnCompleteBP, OnComplete](FLootLockerAdminListMetadataResponse& Response)
	{
		// Make sure we will have entries to parse before continuing
		if(!Response.Success || Response.Entries.Num() <= 0)
		{
			(void) OnCompleteBP.ExecuteIfBound(Response);
			(void) OnComplete.ExecuteIfBound(Response);
			return;
		}
		Response.__INTERNAL_GenerateKeyMap();
		TSharedPtr<FJsonObject> obj = LootLockerAdminUtilities::JsonObjectFromFString(Response.FullTextFromServer);
		// Ensure that the full response was parsed before continuing
		if(!obj.IsValid())
		{
			(void) OnCompleteBP.ExecuteIfBound(Response);
			(void) OnComplete.ExecuteIfBound(Response);
			return;
		}

		TArray<TSharedPtr<FJsonValue>> JsonEntries = obj.Get()->GetArrayField(TEXT("entries"));
		// Make sure that the entries array was parsed before continuing
		if(JsonEntries.Num() != Response.Entries.Num())
		{
			(void) OnCompleteBP.ExecuteIfBound(Response);
			(void) OnComplete.ExecuteIfBound(Response);
			return;
		}

		for (TSharedPtr<FJsonValue> JsonEntry : JsonEntries)
		{
			TSharedPtr<FJsonObject> JsonEntryObject = JsonEntry.Get()->AsObject();

			FString EntryKey = JsonEntryObject.Get()->GetStringField(TEXT("key"));
			int EntryIndex = Response.__INTERNAL_GetEntryIndexByKey(EntryKey);

			// If the fetched entry index is out of range or if it points to the wrong key, try to find the entry the old-fashioned way before giving up
			if (EntryIndex < 0 || EntryIndex >= Response.Entries.Num()
				|| !Response.Entries[EntryIndex].Key.Equals(EntryKey)) {
				for (FLootLockerAdminMetadataEntry& ResponseEntry : Response.Entries)
				{
					if (ResponseEntry.Key.Equals(EntryKey))
					{
						ResponseEntry._INTERNAL_SetJsonRepresentation(*JsonEntryObject.Get());
					}
				}
			}
			else
			{
				FLootLockerAdminMetadataEntry& ResponseEntry = Response.Entries[EntryIndex];
				ResponseEntry._INTERNAL_SetJsonRepresentation(*JsonEntryObject.Get());
			}
		}

		(void) OnCompleteBP.ExecuteIfBound(Response);
		(void) OnComplete.ExecuteIfBound(Response);
	}));
}

void ULootLockerAdminMetadataRequest::MetadataOperations(const ELootLockerAdminMetadataSources Source, const FString& SourceID, const TArray<FLootLockerAdminMetadataOperationsAction>& Actions, const FLootLockerAdminMetadataOperationsResponseBP& OnCompletedRequestBP, const FLootLockerAdminMetadataOperationsResponseDelegate& OnCompletedRequest)
{
	if (SourceID.IsEmpty())
	{
		FLootLockerAdminMetadataOperationsResponse Error = LootLockerAdminResponseFactory::Error<
			FLootLockerAdminMetadataOperationsResponse>("Can not perform actions for source with empty id", LootLockerAdminStaticRequestErrorStatusCodes::LL_ERROR_INVALID_INPUT);
		(void) OnCompletedRequestBP.ExecuteIfBound(Error);
		(void) OnCompletedRequest.ExecuteIfBound(Error);
		return;
	}

	FJsonObject ManuallySerializedRequest;
	FString SourceAsString = ULootLockerAdminEnumUtils::GetEnum(TEXT("ELootLockerAdminMetadataSources"), static_cast<int32>(Source)).ToLower();
	SourceAsString.ReplaceCharInline(' ', '_');
	ManuallySerializedRequest.SetStringField(TEXT("source"), SourceAsString);
	ManuallySerializedRequest.SetStringField(TEXT("source_id"), SourceID);

	// Iterate over actions to perform and manually construct json since there's a ton of magic to it
	TArray<TSharedPtr<FJsonValue>> entries;
	for (const FLootLockerAdminMetadataOperationsAction& ActionToPerform : Actions)
	{
		// Serialize the brunt of the entry automatically
		// Should handle the fields key, tags, and access
		TSharedPtr<FJsonObject> JsonEntry = FJsonObjectConverter::UStructToJsonObject(ActionToPerform.Entry);
		if (!JsonEntry.IsValid())
		{
			FLootLockerAdminMetadataOperationsResponse Error = LootLockerAdminResponseFactory::Error<
				FLootLockerAdminMetadataOperationsResponse>("Could not serialize action for key " + ActionToPerform.Entry.Key, LootLockerAdminStaticRequestErrorStatusCodes::LL_ERROR_PARSE_ERROR);
			(void) OnCompletedRequestBP.ExecuteIfBound(Error);
			(void) OnCompletedRequest.ExecuteIfBound(Error);
			return;
		}

		JsonEntry->SetStringField(TEXT("type"), ULootLockerAdminEnumUtils::GetEnum(TEXT("ELootLockerAdminMetadataTypes"), static_cast<int32>(ActionToPerform.Entry.Type)).ToLower());
		JsonEntry->SetStringField(TEXT("action"), ULootLockerAdminEnumUtils::GetEnum(TEXT("ELootLockerAdminMetadataActions"), static_cast<int32>(ActionToPerform.Action)).ToLower());

		TSharedPtr<FJsonValue> RawEntryValue;
		if (!ActionToPerform.Entry.TryGetRawValue(RawEntryValue))
		{
			FLootLockerAdminMetadataOperationsResponse Error = LootLockerAdminResponseFactory::Error<
				FLootLockerAdminMetadataOperationsResponse>("Could not get value to perform action " + JsonEntry->GetStringField(TEXT("action")) + " for key " + ActionToPerform.Entry.Key, LootLockerAdminStaticRequestErrorStatusCodes::LL_ERROR_PARSE_ERROR);
			(void) OnCompletedRequestBP.ExecuteIfBound(Error);
			(void) OnCompletedRequest.ExecuteIfBound(Error);
			return;
		}
		JsonEntry->SetField(TEXT("value"), RawEntryValue);

		entries.Add(MakeShared<FJsonValueObject>(JsonEntry));
	}

	ManuallySerializedRequest.SetArrayField(TEXT("entries"), entries);
	FString SerializedRequest = LootLockerAdminUtilities::FStringFromJsonObject(MakeShared<FJsonObject>(ManuallySerializedRequest));
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	ULootLockerAdminHttpClient::SendRawRequest<FLootLockerAdminMetadataOperationsResponse>(SerializedRequest, ULootLockerAdminEndpoints::MetadataOperations, {Config->GameID}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}
