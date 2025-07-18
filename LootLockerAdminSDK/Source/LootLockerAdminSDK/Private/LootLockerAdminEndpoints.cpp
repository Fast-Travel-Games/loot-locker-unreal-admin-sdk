
#include "LootLockerAdminEndpoints.h"

#ifdef LOOTLOCKER_USE_STAGE_URL
FString ULootLockerAdminEndpoints::AdminApiUrl = "https://api.stage.internal.dev.lootlocker.cloud/admin/";
#else
FString ULootLockerAdminEndpoints::AdminApiUrl = "https://api.lootlocker.com/admin/";
#endif

// Assets
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::CreateAsset = InitEndpoint("v1/game/{0}/asset", ELootLockerAdminHTTPMethod::POST);
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::GetAssetContexts = InitEndpoint("v1/game/{0}/assets/contexts", ELootLockerAdminHTTPMethod::GET);
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::ActivateAsset = InitEndpoint("v1/game/{0}/asset/{1}/activate", ELootLockerAdminHTTPMethod::POST);
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::GetAssets = InitEndpoint("v1/game/{0}/assets", ELootLockerAdminHTTPMethod::GET);

// Catalog
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::AddPrice = InitEndpoint("game/{0}/catalog/price", ELootLockerAdminHTTPMethod::PUT);
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::DeletePrice = InitEndpoint("game/{0}/catalog/{1}/item/{2}/currency/{3}", ELootLockerAdminHTTPMethod::DELETE);
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::CreateCatalogListing = InitEndpoint("game/{0}/catalog/item", ELootLockerAdminHTTPMethod::POST);
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::ListCatalogs = InitEndpoint("game/{0}/catalogs", ELootLockerAdminHTTPMethod::GET);
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::ListCatalogItems = InitEndpoint("game/{0}/catalog/{1}/prices", ELootLockerAdminHTTPMethod::GET);
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::TogglePurchasableStatus = InitEndpoint("game/{0}/catalog/item/{1}", ELootLockerAdminHTTPMethod::PUT);

// Currency
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::CreateCurrency = InitEndpoint("game/{0}/currency", ELootLockerAdminHTTPMethod::POST);
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::ListCurrencies = InitEndpoint("game/{0}/currencies", ELootLockerAdminHTTPMethod::GET);

// Metadata
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::MetadataOperations = InitEndpoint("game/{0}/metadata", ELootLockerAdminHTTPMethod::POST);

// Rewards
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::CreateGroup = InitEndpoint("game/{0}/reward/group", ELootLockerAdminHTTPMethod::POST);

// Session
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::CreateSession = InitEndpoint("v1/session", ELootLockerAdminHTTPMethod::POST);

FLootLockerAdminEndPoint ULootLockerAdminEndpoints::InitEndpoint(const FString& Endpoint, ELootLockerAdminHTTPMethod Method)
{
	FLootLockerAdminEndPoint Result;
	Result.endpoint = AdminApiUrl + Endpoint;
	Result.requestMethod = Method;
	return Result;
}
