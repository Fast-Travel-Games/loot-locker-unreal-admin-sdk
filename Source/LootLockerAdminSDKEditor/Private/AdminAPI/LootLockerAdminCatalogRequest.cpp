
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
	//Request.Amount = Amount; FIXME
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminAddPriceResponse>(Request, ULootLockerAdminEndpoints::AddPrice, {Config->GameID}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerAdminCatalogRequest::CreateCatalogListing(const FString& CatalogId, const FString& EntityId, const FString& EntityKind, const FLootLockerAdminCreateCatalogListingResponseBP& OnCompletedRequestBP, const FLootLockerAdminCreateCatalogListingResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	FLootLockerAdminCreateCatalogListingRequest Request;
	Request.Catalog_id = CatalogId;
	Request.Entity_id = EntityId;
	Request.Entity_kind = EntityKind; // TODO: verify proper values or have an enum?! (check game/server API)
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminCreateCatalogListingResponse>(Request, ULootLockerAdminEndpoints::CreateCatalogListing, {Config->GameID}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerAdminCatalogRequest::ListCatalogs(const FLootLockerAdminListCatalogsResponseBP& OnCompletedRequestBP, const FLootLockerAdminListCatalogsResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminListCatalogsResponse>(FLootLockerAdminEmptyRequest{}, ULootLockerAdminEndpoints::ListCatalogs, {Config->GameID}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerAdminCatalogRequest::TogglePurchasableStatus(const FString& CatalogItemId, const FLootLockerAdminTogglePurchasableStatusResponseBP& OnCompletedRequestBP, const FLootLockerAdminTogglePurchasableStatusResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminResponse>(FLootLockerAdminEmptyRequest{}, ULootLockerAdminEndpoints::TogglePurchasableStatus, {Config->GameID, CatalogItemId}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}
