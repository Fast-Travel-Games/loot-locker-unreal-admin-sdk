
#include "AdminAPI/LootLockerAdminCatalogRequest.h"

#include "LootLockerAdminHttpClient.h"

ULootLockerAdminCatalogRequest::ULootLockerAdminCatalogRequest()
{
}

void ULootLockerAdminCatalogRequest::AddPrice(const FString& CatalogItemId, const FString& CurrencyId, int Amount, const FLootLockerAdminAddPriceResponseBP& OnCompletedRequestBP, const FLootLockerAdminAddPriceResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	FLootLockerAdminAddPriceRequest Request;
	Request.Catalog_item_id = CatalogItemId;
	Request.Currency_id = CurrencyId;
	Request.Amount = FString::Format(TEXT("{0}"), { Amount });
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminAddPriceResponse>(Request, ULootLockerAdminEndpoints::AddPrice, {Config->GameID}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerAdminCatalogRequest::DeletePrice(const FString& CatalogId, const FString& CatalogItemId, const FString& CurrencyId, const FLootLockerAdminDeletePriceResponseBP& OnCompletedRequestBP, const FLootLockerAdminDeletePriceResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminListCatalogsResponse>(FLootLockerAdminEmptyRequest{}, ULootLockerAdminEndpoints::DeletePrice, {Config->GameID, CatalogId, CatalogItemId, CurrencyId}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerAdminCatalogRequest::CreateCatalogListing(const FString& CatalogId, const FString& EntityId, const ELootLockerAdminCatalogEntityKind& EntityKind, const FLootLockerAdminCreateCatalogListingResponseBP& OnCompletedRequestBP, const FLootLockerAdminCreateCatalogListingResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	FLootLockerAdminCreateCatalogListingRequest Request;
	Request.Catalog_id = CatalogId;
	Request.Entity_id = EntityId;
	Request.Entity_kind = UEnum::GetValueAsString(EntityKind).ToLower().RightChop(UEnum::GetValueAsString(EntityKind).Find("::") + 2);
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminCreateCatalogListingResponse>(Request, ULootLockerAdminEndpoints::CreateCatalogListing, {Config->GameID}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerAdminCatalogRequest::ListCatalogs(const FLootLockerAdminListCatalogsResponseBP& OnCompletedRequestBP, const FLootLockerAdminListCatalogsResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminListCatalogsResponse>(FLootLockerAdminEmptyRequest{}, ULootLockerAdminEndpoints::ListCatalogs, {Config->GameID}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerAdminCatalogRequest::ListCatalogItems(const FString& CatalogId, const int Count, const FString& After, const FLootLockerAdminListCatalogItemsResponseBP& OnCompletedRequestBP, const FLootLockerAdminListCatalogItemsResponseDelegate& OnCompletedRequest)
{
	TMultiMap<FString, FString> QueryParams;
	if (Count > 0) { QueryParams.Add("per_page", FString::FromInt(Count)); }
	if (!After.IsEmpty()) { QueryParams.Add("cursor", After); }

	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminListCatalogItemsResponse>(FLootLockerAdminEmptyRequest{}, ULootLockerAdminEndpoints::ListCatalogItems, {Config->GameID, CatalogId}, QueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerAdminCatalogRequest::TogglePurchasableStatus(const FString& CatalogItemId, const FLootLockerAdminTogglePurchasableStatusResponseBP& OnCompletedRequestBP, const FLootLockerAdminTogglePurchasableStatusResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminResponse>(FLootLockerAdminEmptyRequest{}, ULootLockerAdminEndpoints::TogglePurchasableStatus, {Config->GameID, CatalogItemId}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}
