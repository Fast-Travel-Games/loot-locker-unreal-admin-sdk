
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

//==================================================
// Metadata Request Handler
//==================================================

ULootLockerAdminMetadataRequest::ULootLockerAdminMetadataRequest()
{
}

void ULootLockerAdminMetadataRequest::MetadataOperations(const ELootLockerAdminMetadataSources Source, const FString& SourceID, const TArray<FLootLockerAdminMetadataOperationsAction>& Actions, const FLootLockerAdminMetadataOperationsResponseBP& OnCompletedRequestBP, const FLootLockerAdminMetadataOperationsResponseDelegate& OnCompletedRequest)
{
	if (SourceID.IsEmpty())
	{
		FLootLockerAdminMetadataOperationsResponse Error = LootLockerAdminResponseFactory::Error<
			FLootLockerAdminMetadataOperationsResponse>("Can not perform actions for source with empty id", LootLockerAdminStaticRequestErrorStatusCodes::LL_ERROR_INVALID_INPUT);
		OnCompletedRequestBP.ExecuteIfBound(Error);
		OnCompletedRequest.ExecuteIfBound(Error);
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
			OnCompletedRequestBP.ExecuteIfBound(Error);
			OnCompletedRequest.ExecuteIfBound(Error);
			return;
		}

		JsonEntry->SetStringField(TEXT("type"), ULootLockerAdminEnumUtils::GetEnum(TEXT("ELootLockerAdminMetadataTypes"), static_cast<int32>(ActionToPerform.Entry.Type)).ToLower());
		JsonEntry->SetStringField(TEXT("action"), ULootLockerAdminEnumUtils::GetEnum(TEXT("ELootLockerAdminMetadataActions"), static_cast<int32>(ActionToPerform.Action)).ToLower());

		TSharedPtr<FJsonValue> RawEntryValue;
		if (!ActionToPerform.Entry.TryGetRawValue(RawEntryValue))
		{
			FLootLockerAdminMetadataOperationsResponse Error = LootLockerAdminResponseFactory::Error<
				FLootLockerAdminMetadataOperationsResponse>("Could not get value to perform action " + JsonEntry->GetStringField(TEXT("action")) + " for key " + ActionToPerform.Entry.Key, LootLockerAdminStaticRequestErrorStatusCodes::LL_ERROR_PARSE_ERROR);
			OnCompletedRequestBP.ExecuteIfBound(Error);
			OnCompletedRequest.ExecuteIfBound(Error);
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
