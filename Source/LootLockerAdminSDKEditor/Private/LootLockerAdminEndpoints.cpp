
#include "LootLockerAdminEndpoints.h"

#ifdef LOOTLOCKER_USE_STAGE_URL
FString ULootLockerAdminEndpoints::GameBaseUrl = "https://{domainKey}api.stage.internal.dev.lootlocker.cloud/";
#else
FString ULootLockerAdminEndpoints::GameBaseUrl = "https://{domainKey}api.lootlocker.com/";
#endif
FString ULootLockerAdminEndpoints::AdminApiUrlSuffix = "admin/";

// Assets
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::CreateAsset = InitEndpoint("v1/game/{0}/asset", ELootLockerAdminHTTPMethod::POST);
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::GetAssetContexts = InitEndpoint("v1/game/{0}/assets/contexts", ELootLockerAdminHTTPMethod::GET);
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::ActivateAsset = InitEndpoint("v1/game/{0}/asset/{1}/activate", ELootLockerAdminHTTPMethod::POST);

// Catalog
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::AddPrice = InitEndpoint("game/{0}/catalog/price", ELootLockerAdminHTTPMethod::PUT);
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::CreateCatalogListing = InitEndpoint("game/{0}/catalog/item", ELootLockerAdminHTTPMethod::POST);
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::ListCatalogs = InitEndpoint("game/{0}/catalogs", ELootLockerAdminHTTPMethod::GET);
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::TogglePurchasableStatus = InitEndpoint("game/{0}/catalog/item/{1}", ELootLockerAdminHTTPMethod::PUT);

// Currency
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::CreateCurrency = InitEndpoint("game/{0}/currency", ELootLockerAdminHTTPMethod::POST);

// Metadata
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::MetadataOperations = InitEndpoint("game/{0}/metadata", ELootLockerAdminHTTPMethod::POST);

// Rewards
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::CreateGroup = InitEndpoint("game/{0}/reward/group", ELootLockerAdminHTTPMethod::POST);

// Session
FLootLockerAdminEndPoint ULootLockerAdminEndpoints::CreateSession = InitEndpoint("v1/session", ELootLockerAdminHTTPMethod::POST);

FLootLockerAdminEndPoint ULootLockerAdminEndpoints::InitEndpoint(const FString& Endpoint, ELootLockerAdminHTTPMethod Method, const FString& BaseUrlSuffix)
{
	FLootLockerAdminEndPoint Result;
	Result.endpoint = GameBaseUrl + BaseUrlSuffix + Endpoint;
	Result.requestMethod = Method;
	return Result;
}
