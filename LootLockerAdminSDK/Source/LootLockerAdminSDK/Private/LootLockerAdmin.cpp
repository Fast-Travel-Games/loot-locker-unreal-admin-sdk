

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

void ULootLockerAdmin::GetAssets(const bool bIncludeInactive, const int Page, const FLootLockerAdminGetAssetsResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminAssetRequest::GetAssets(bIncludeInactive, Page, FLootLockerAdminGetAssetsResponseBP(), OnCompletedRequest);
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

// LEADERBOARD

void ULootLockerAdmin::CreateLeaderboard(FString LeaderboardKey, FString Name, ELootLockerAdminLeaderboardType Type, bool HasMetadata, ELootLockerAdminLeaderboardDirection DirectionMethod, bool EnableGameApiWrites, bool OverwriteScoreOnSubmit, const FLootLockerAdminCreateLeaderboardResponseDelegate& OnCompletedRequest)
{
	FLootLockerAdminCreateLeaderboardRequest Request;
	Request.Key = LeaderboardKey;
	Request.Name = Name;
	Request.Type = Type;
	Request.Has_metadata = HasMetadata;
	Request.Direction_method = DirectionMethod;
	Request.Enable_game_api_writes = EnableGameApiWrites;
	Request.Overwrite_score_on_submit = OverwriteScoreOnSubmit;
	ULootLockerAdminLeaderboardRequest::CreateLeaderboard(Request, FLootLockerAdminCreateLeaderboardResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::LeaderboardAddReward(int LeaderboardId, const FLootLockerAdminLeaderboardAddRewardRequest& Request, const FLootLockerAdminLeaderboardAddRewardResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminLeaderboardRequest::LeaderboardAddReward(LeaderboardId, Request, FLootLockerAdminLeaderboardAddRewardResponseBP(), OnCompletedRequest);
}

// METADATA

void ULootLockerAdmin::ListMetadata(const ELootLockerAdminMetadataSources Source, const FString& SourceID, const int Page, const int PerPage, const FLootLockerAdminListMetadataResponseDelegate& OnCompletedRequest, const bool IgnoreFiles)
{
	ULootLockerAdminMetadataRequest::ListMetadata(Source, SourceID, Page, PerPage, "", TArray<FString>(), true, FLootLockerAdminListMetadataResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::MetadataOperations(const ELootLockerAdminMetadataSources Source, const FString& SourceId, const TArray<FLootLockerAdminMetadataOperationsAction>& Actions, const FLootLockerAdminMetadataOperationsResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminMetadataRequest::MetadataOperations(Source, SourceId, Actions, FLootLockerAdminMetadataOperationsResponseBP(), OnCompletedRequest);
}

// PLAYERS

void ULootLockerAdmin::GrantAsset(const FString& PlayerId, const int AssetId, const FLootLockerAdminGrantAssetResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminPlayerRequest::GrantAsset(PlayerId, AssetId, FLootLockerAdminGrantAssetResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::DeleteAssetFromPlayer(const FString& PlayerId, const int AssetId, const FLootLockerAdminDeleteAssetFromPlayerResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminPlayerRequest::DeleteAssetFromPlayer(PlayerId, AssetId, FLootLockerAdminDeleteAssetFromPlayerResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::ListPlayers(const int Count, const int Page, const FLootLockerAdminListPlayersResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminPlayerRequest::ListPlayers(Count, Page, FLootLockerAdminListPlayersResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::ListPlayerInventory(const FString& PlayerId, const FLootLockerAdminListPlayerInventoryResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminPlayerRequest::ListPlayerInventory(PlayerId, FLootLockerAdminListPlayerInventoryResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::DeletePlayerData(const FString& PlayerId, const FLootLockerAdminDeletePlayerDataRequest& Request, const FLootLockerAdminDeletePlayerDataResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminPlayerRequest::DeletePlayerData(PlayerId, Request, FLootLockerAdminDeletePlayerDataResponseBP(), OnCompletedRequest);
}

// REWARD

void ULootLockerAdmin::CreateCurrencyReward(const FLootLockerAdminEntity& Reward, const FLootLockerAdminCreateCurrencyRewardResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminRewardRequest::CreateCurrencyReward(Reward, FLootLockerAdminCreateCurrencyRewardResponseBP(), OnCompletedRequest);
}

void ULootLockerAdmin::CreateGroup(const TArray<FLootLockerAdminEntity>& Entities, const FString& Name, const FString& Description, const FLootLockerAdminCreateGroupResponseDelegate& OnCompletedRequest)
{
	ULootLockerAdminRewardRequest::CreateGroup(Entities, Name, Description, FLootLockerAdminCreateGroupResponseBP(), OnCompletedRequest);
}
