

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

// CATALOG

void ULootLockerAdmin::ListCatalogs(const FLootLockerAdminListCatalogsResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::ListCatalogs(FLootLockerAdminListCatalogsResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::CreateCatalogListing(const FString& CatalogId, const FString& EntityId, const FString& EntityKind, const FLootLockerAdminCreateCatalogListingResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::CreateCatalogListing(CatalogId, EntityId, EntityKind, FLootLockerAdminCreateCatalogListingResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::AddPrice(const FString& CatalogItemId, const FString& CurrencyId, int Amount, const FLootLockerAdminAddPriceResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminCatalogRequest::AddPrice(CatalogItemId, CurrencyId, Amount, FLootLockerAdminAddPriceResponseBP(), OnCompletedRequest);
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

// METADATA

void ULootLockerAdmin::MetadataOperations(const ELootLockerAdminMetadataSources Source, const FString& SourceId, const TArray<FLootLockerAdminMetadataOperationsAction>& Actions, const FLootLockerAdminMetadataOperationsResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminMetadataRequest::MetadataOperations(Source, SourceId, Actions, FLootLockerAdminMetadataOperationsResponseBP(), OnCompletedRequest);
}

// REWARD

void ULootLockerAdmin::CreateGroup(const TArray<FLootLockerAdminEntity>& Entities, const FString& Name, const FString& Description, const FLootLockerAdminCreateGroupResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminRewardRequest::CreateGroup(Entities, Name, Description, FLootLockerAdminCreateGroupResponseBP(), OnCompletedRequest);
}

