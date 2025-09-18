
#include "AdminAPI/LootLockerAdminPlayerRequest.h"

#include "LootLockerAdminHttpClient.h"

ULootLockerAdminPlayerRequest::ULootLockerAdminPlayerRequest()
{
}

void ULootLockerAdminPlayerRequest::GrantAsset(const FString& PlayerId, const int AssetId, const FLootLockerAdminGrantAssetResponseBP& OnCompletedRequestBP, const FLootLockerAdminGrantAssetResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	FLootLockerAdminGrantAssetRequest  Request;
	Request.Asset_id = AssetId;
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminResponse>(Request, ULootLockerAdminEndpoints::GrantAssetToPlayer, {Config->GameID, PlayerId}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerAdminPlayerRequest::ListPlayers(const int Count, const int Page, const FLootLockerAdminListPlayersResponseBP& OnCompletedRequestBP, const FLootLockerAdminListPlayersResponseDelegate& OnCompletedRequest)
{
	TMultiMap<FString, FString> QueryParams;
	if (Count > 0) { QueryParams.Add("per_page", FString::FromInt(Count)); }
	if (Page > 0) { QueryParams.Add("page", FString::FromInt(Page)); }

	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminListPlayersResponse>(FLootLockerAdminEmptyRequest{}, ULootLockerAdminEndpoints::ListPlayers, {Config->GameID}, QueryParams, OnCompletedRequestBP, OnCompletedRequest);
}
