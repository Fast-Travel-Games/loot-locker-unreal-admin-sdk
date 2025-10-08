
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

void ULootLockerAdminBP::GetAssets(const bool bIncludeInactive, const FLootLockerAdminGetAssetsResponseBP& OnCompletedRequest)
{
	ULootLockerAdminAssetRequest::GetAssets(bIncludeInactive, OnCompletedRequest);
}

// CATALOG

void ULootLockerAdminBP::AddPrice(const FString& CatalogItemId, const FString& CurrencyId, int Amount, const FLootLockerAdminAddPriceResponseBP& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::AddPrice(CatalogItemId, CurrencyId, Amount, OnCompletedRequest);
}

void ULootLockerAdminBP::DeletePrice(const FString& CatalogId, const FString& CatalogItemId, const FString& CurrencyId, const FLootLockerAdminDeletePriceResponseBP& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::DeletePrice(CatalogId, CatalogItemId, CurrencyId, OnCompletedRequest);
}

void ULootLockerAdminBP::CreateCatalogListing(const FString& CatalogId, const FString& EntityId, const ELootLockerAdminCatalogEntityKind& EntityKind, const FLootLockerAdminCreateCatalogListingResponseBP& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::CreateCatalogListing(CatalogId, EntityId, EntityKind, OnCompletedRequest);
}

void ULootLockerAdminBP::DeleteCatalogListing(const FString& CatalogItemId, const FLootLockerAdminDeleteCatalogListingResponseBP& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::DeleteCatalogListing(CatalogItemId, OnCompletedRequest);
}

void ULootLockerAdminBP::ListCatalogs(const FLootLockerAdminListCatalogsResponseBP& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::ListCatalogs(OnCompletedRequest);
}

void ULootLockerAdminBP::ListCatalogItems(const FString& CatalogId, const int Count, const FString& After, const FLootLockerAdminListCatalogItemsResponseBP& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::ListCatalogItems(CatalogId, Count, After, OnCompletedRequest);
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

// PLAYERS

void ULootLockerAdminBP::GrantAsset(const FString& PlayerId, const int AssetId, const FLootLockerAdminGrantAssetResponseBP& OnCompletedRequest)
{
	ULootLockerAdminPlayerRequest::GrantAsset(PlayerId, AssetId, OnCompletedRequest);
}

void ULootLockerAdminBP::ListPlayers(const int Count, const int Page, const FLootLockerAdminListPlayersResponseBP& OnCompletedRequest)
{
	ULootLockerAdminPlayerRequest::ListPlayers(Count, Page, OnCompletedRequest);
}

// REWARD

void ULootLockerAdminBP::CreateGroup(const TArray<FLootLockerAdminEntity>& Entities, const FString& Name, const FString& Description, const FLootLockerAdminCreateGroupResponseBP& OnCompletedRequest)
{
	ULootLockerAdminRewardRequest::CreateGroup(Entities, Name, Description, OnCompletedRequest);
}

