
#include "LootLockerAdminBP.h"

#include "Utils/LootLockerAdminUtilities.h"

// AUTH

void ULootLockerAdminBP::CreateSession(const FString& Email, const FString& Password, const FLootLockerAdminCreateSessionResponseBP& OnCompletedRequest)
{
    ULootLockerAdminSessionRequest::CreateSession(Email, Password, OnCompletedRequest);
}

// ASSET

void ULootLockerAdminBP::GetAssetContexts(const FLootLockerAdminGetAssetContextsResponseBP& OnCompletedRequest)
{
	ULootLockerAdminAssetRequest::GetAssetContexts(OnCompletedRequest);
}

void ULootLockerAdminBP::CreateAsset(const int Context, const FString& Name, const bool bUniqueInstance, const FLootLockerAdminCreateAssetResponseBP& OnCompletedRequest)
{
    ULootLockerAdminAssetRequest::CreateAsset(Context, Name, bUniqueInstance, OnCompletedRequest);
}

void ULootLockerAdminBP::ActivateAsset(const int AssetId, const bool bActive, const FLootLockerAdminActivateAssetResponseBP& OnCompletedRequest)
{
	ULootLockerAdminAssetRequest::ActivateAsset(AssetId, bActive, OnCompletedRequest);
}


// CATALOG

void ULootLockerAdminBP::ListCatalogs(const FLootLockerAdminListCatalogsResponseBP& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::ListCatalogs(OnCompletedRequest);
}

void ULootLockerAdminBP::CreateCatalogListing(const FString& CatalogId, const FString& EntityId, const FString& EntityKind, const FLootLockerAdminCreateCatalogListingResponseBP& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::CreateCatalogListing(CatalogId, EntityId, EntityKind, OnCompletedRequest);
}

void ULootLockerAdminBP::AddPrice(const FString& CatalogItemId, const FString& CurrencyId, int Amount, const FLootLockerAdminAddPriceResponseBP& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::AddPrice(CatalogItemId, CurrencyId, Amount, OnCompletedRequest);
}

void ULootLockerAdminBP::TogglePurchasableStatus(const FString& CatalogItemId, const FLootLockerAdminTogglePurchasableStatusResponseBP& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::TogglePurchasableStatus(CatalogItemId, OnCompletedRequest);
}

// CURRENCY

void ULootLockerAdminBP::CreateCurrency(const FString& Name, const FString& Code, const FString& DenominationName, const FLootLockerAdminCreateCurrencyResponseBP& OnCompletedRequest)
{
	ULootLockerAdminCurrencyRequest::CreateCurrency(Name, Code, DenominationName, OnCompletedRequest);
}

void ULootLockerAdminBP::ListCurrencies(const FLootLockerAdminListCurrenciesResponseBP& OnCompletedRequest)
{
	ULootLockerAdminCurrencyRequest::ListCurrencies(OnCompletedRequest);
}

// METADATA

void ULootLockerAdminBP::MetadataOperations(const ELootLockerAdminMetadataSources Source, const FString& SourceId, const TArray<FLootLockerAdminMetadataOperationsAction>& Actions, const FLootLockerAdminMetadataOperationsResponseBP& OnCompletedRequest)
{
	ULootLockerAdminMetadataRequest::MetadataOperations(Source, SourceId, Actions, OnCompletedRequest);
}

FLootLockerAdminMetadataOperationsAction ULootLockerAdminBP::MakeMetadataActionString(ELootLockerAdminMetadataActions Action, const FString& Key, const FString& Value, const TArray<FString>& Tags, const TArray<FString>& Access)
{
    return FLootLockerAdminMetadataOperationsAction{ Action, FLootLockerAdminMetadataEntry::MakeStringEntry(Key, Tags, Access, Value) };
}

FLootLockerAdminMetadataOperationsAction ULootLockerAdminBP::MakeMetadataActionFloat(ELootLockerAdminMetadataActions Action, const FString& Key, const float& Value, const TArray<FString>& Tags, const TArray<FString>& Access)
{
    return FLootLockerAdminMetadataOperationsAction{ Action, FLootLockerAdminMetadataEntry::MakeFloatEntry(Key, Tags, Access, Value) };
}

FLootLockerAdminMetadataOperationsAction ULootLockerAdminBP::MakeMetadataActionInteger(ELootLockerAdminMetadataActions Action, const FString& Key, const int Value, const TArray<FString>& Tags, const TArray<FString>& Access)
{
    return FLootLockerAdminMetadataOperationsAction{Action, FLootLockerAdminMetadataEntry::MakeIntegerEntry(Key, Tags, Access, Value)};
}

FLootLockerAdminMetadataOperationsAction ULootLockerAdminBP::MakeMetadataActionBool(ELootLockerAdminMetadataActions Action, const FString& Key, const bool Value, const TArray<FString>& Tags, const TArray<FString>& Access)
{
    return FLootLockerAdminMetadataOperationsAction{Action, FLootLockerAdminMetadataEntry::MakeBoolEntry(Key, Tags, Access, Value)};
}

void ULootLockerAdminBP::MakeMetadataActionJson(ELootLockerAdminMetadataActions Action, const FString& Key, const FString& Value, const TArray<FString>& Tags, const TArray<FString>& Access, bool& Succeeded, FLootLockerAdminMetadataOperationsAction& ConstructedEntry)
{
    TArray<TSharedPtr<FJsonValue>> JsonArrayValue;
    if (LootLockerAdminUtilities::JsonArrayFromFString(Value, JsonArrayValue))
    {
        ConstructedEntry = FLootLockerAdminMetadataOperationsAction{Action, FLootLockerAdminMetadataEntry::MakeJsonArrayEntry(Key, Tags, Access, JsonArrayValue)};
        Succeeded = true;
        return;
    }

    TSharedPtr<FJsonObject> JsonObjectValue = LootLockerAdminUtilities::JsonObjectFromFString(Value);
    if (JsonObjectValue.IsValid())
    {
         ConstructedEntry = FLootLockerAdminMetadataOperationsAction{Action, FLootLockerAdminMetadataEntry::MakeJsonObjectEntry(Key, Tags, Access, *JsonObjectValue)};
         Succeeded = true;
         return;
    }
    Succeeded = false;
}

FLootLockerAdminMetadataOperationsAction ULootLockerAdminBP::MakeMetadataActionBase64(ELootLockerAdminMetadataActions Action, const FString& Key, const FLootLockerAdminMetadataBase64Value& Value, const TArray<FString>& Tags, const TArray<FString>& Access)
{
    return FLootLockerAdminMetadataOperationsAction{Action, FLootLockerAdminMetadataEntry::MakeBase64Entry(Key, Tags, Access, Value)};
}

// REWARD

void ULootLockerAdminBP::CreateGroup(const TArray<FLootLockerAdminEntity>& Entities, const FString& Name, const FString& Description, const FLootLockerAdminCreateGroupResponseBP& OnCompletedRequest)
{
	ULootLockerAdminRewardRequest::CreateGroup(Entities, Name, Description, OnCompletedRequest);
}

