

#include "LootLockerAdmin.h"

// AUTH

void ULootLockerAdmin::StartSession(const FString& Email, const FString& Password, const FLootLockerAdminCreateSessionResponseDelegate& OnCompleteRequest)
{
    ULootLockerAdminSessionRequest::CreateSession(Email, Password, FLootLockerAdminCreateSessionResponseBP(), OnCompleteRequest);
}

// ASSET

void ULootLockerAdmin::GetAssetContexts(const FLootLockerAdminGetAssetContextsResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminAssetRequest::GetAssetContexts(FLootLockerAdminGetAssetContextsResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::CreateAsset(const int Context, const FString& Name, const bool bUniqueInstance, const FLootLockerAdminCreateAssetResponseDelegate& OnCompletedRequest)
{
    ULootLockerAdminAssetRequest::CreateAsset(Context, Name, bUniqueInstance, FLootLockerAdminCreateAssetResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::ActivateAsset(const int AssetId, const bool bActive, const FLootLockerAdminActivateAssetResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminAssetRequest::ActivateAsset(AssetId, bActive, FLootLockerAdminActivateAssetResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::GetAssets(const bool bIncludeInactive, const FLootLockerAdminGetAssetsResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminAssetRequest::GetAssets(bIncludeInactive, FLootLockerAdminGetAssetsResponseBP(), OnCompletedRequest);
}

// CATALOG

void ULootLockerAdmin::AddPrice(const FString& CatalogItemId, const FString& CurrencyId, int Amount, const FLootLockerAdminAddPriceResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::AddPrice(CatalogItemId, CurrencyId, Amount, FLootLockerAdminAddPriceResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::DeletePrice(const FString& CatalogId, const FString& CatalogItemId, const FString& CurrencyId, const FLootLockerAdminDeletePriceResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::DeletePrice(CatalogId, CatalogItemId, CurrencyId, FLootLockerAdminDeletePriceResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::CreateCatalogListing(const FString& CatalogId, const FString& EntityId, const ELootLockerAdminCatalogEntityKind& EntityKind, const FLootLockerAdminCreateCatalogListingResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::CreateCatalogListing(CatalogId, EntityId, EntityKind, FLootLockerAdminCreateCatalogListingResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::DeleteCatalogListing(const FString& CatalogItemId, const FLootLockerAdminDeleteCatalogListingResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::DeleteCatalogListing(CatalogItemId, FLootLockerAdminDeleteCatalogListingResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::ListCatalogs(const FLootLockerAdminListCatalogsResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::ListCatalogs(FLootLockerAdminListCatalogsResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::ListCatalogItems(const FString& CatalogId, const int Count, const FString& After, const FLootLockerAdminListCatalogItemsResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::ListCatalogItems(CatalogId, Count, After, FLootLockerAdminListCatalogItemsResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::TogglePurchasableStatus(const FString& CatalogItemId, const FLootLockerAdminTogglePurchasableStatusResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::TogglePurchasableStatus(CatalogItemId, FLootLockerAdminTogglePurchasableStatusResponseBP(), OnCompletedRequest);
}

// CURRENCY

void ULootLockerAdmin::CreateCurrency(const FString& Name, const FString& Code, const FString& DenominationName, const FLootLockerAdminCreateCurrencyResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminCurrencyRequest::CreateCurrency(Name, Code, DenominationName, FLootLockerAdminCreateCurrencyResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::ListCurrencies(const FLootLockerAdminListCurrenciesResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminCurrencyRequest::ListCurrencies(FLootLockerAdminListCurrenciesResponseBP(), OnCompletedRequest);
}

// METADATA

void ULootLockerAdmin::MetadataOperations(const ELootLockerAdminMetadataSources Source, const FString& SourceId, const TArray<FLootLockerAdminMetadataOperationsAction>& Actions, const FLootLockerAdminMetadataOperationsResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminMetadataRequest::MetadataOperations(Source, SourceId, Actions, FLootLockerAdminMetadataOperationsResponseBP(), OnCompletedRequest);
}

// PLAYERS

void ULootLockerAdmin::GrantAsset(const FString& PlayerId, const int AssetId, const FLootLockerAdminGrantAssetResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminPlayerRequest::GrantAsset(PlayerId, AssetId, FLootLockerAdminGrantAssetResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::ListPlayers(const int Count, const int Page, const FLootLockerAdminListPlayersResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminPlayerRequest::ListPlayers(Count, Page, FLootLockerAdminListPlayersResponseBP(), OnCompletedRequest);
}

// REWARD

void ULootLockerAdmin::CreateGroup(const TArray<FLootLockerAdminEntity>& Entities, const FString& Name, const FString& Description, const FLootLockerAdminCreateGroupResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminRewardRequest::CreateGroup(Entities, Name, Description, FLootLockerAdminCreateGroupResponseBP(), OnCompletedRequest);
}

