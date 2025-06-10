
#include "AdminAPI/LootLockerAdminAssetRequest.h"

#include "LootLockerAdminHttpClient.h"

ULootLockerAdminAssetRequest::ULootLockerAdminAssetRequest()
{
}

void ULootLockerAdminAssetRequest::GetAssetContexts(const FLootLockerAdminGetAssetContextsResponseBP& OnCompletedRequestBP, const FLootLockerAdminGetAssetContextsResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminGetAssetContextsResponse>(FLootLockerAdminEmptyRequest{}, ULootLockerAdminEndpoints::GetAssetContexts, {Config->GameID}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerAdminAssetRequest::CreateAsset(const int Context, const FString& Name, const bool bUniqueInstance, const FLootLockerAdminCreateAssetResponseBP& OnCompletedRequestBP, const FLootLockerAdminCreateAssetResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	FLootLockerAdminCreateAssetRequest Request;
	Request.Context_id = Context;
	Request.Name = Name;
	Request.Unique_instance = bUniqueInstance;
    ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminCreateAssetResponse>(Request, ULootLockerAdminEndpoints::CreateAsset, {Config->GameID}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerAdminAssetRequest::ActivateAsset(const int AssetId, const bool bActive, const FLootLockerAdminActivateAssetResponseBP& OnCompletedRequestBP, const FLootLockerAdminActivateAssetResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	FLootLockerAdminActivateAssetRequest Request;
	Request.Live_and_debug = bActive;
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminResponse>(Request, ULootLockerAdminEndpoints::ActivateAsset, {Config->GameID, AssetId}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

