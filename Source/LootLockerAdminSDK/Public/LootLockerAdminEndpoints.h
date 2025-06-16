
#pragma once

#include "LootLockerAdminConfig.h"
#include "Utils/LootLockerAdminUtilities.h"

#include "LootLockerAdminEndpoints.generated.h"

UENUM(BlueprintType)
enum class ELootLockerAdminHTTPMethod : uint8
{
    GET = 0         UMETA(DisplayName = "GET"),
    POST = 1        UMETA(DisplayName = "POST"),
    DELETE = 2      UMETA(DisplayName = "DELETE"),
    PUT = 3         UMETA(DisplayName = "PUT"),
    HEAD = 4        UMETA(DisplayName = "HEAD"),
    CREATE = 5      UMETA(DisplayName = "CREATE"),
    OPTIONS = 6     UMETA(DisplayName = "OPTIONS"),
    PATCH = 7       UMETA(DisplayName = "PATCH"),
    UPLOAD = 8      UMETA(DisplayName = "UPLOAD")
};

USTRUCT(BlueprintType)
struct FLootLockerAdminEndPoint
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, BlueprintReadWrite, Category = "LootLockerAdmin")
    FString endpoint = "";
    UPROPERTY(BlueprintReadWrite, EditAnywhere, BlueprintReadWrite, Category = "LootLockerAdmin")
    ELootLockerAdminHTTPMethod requestMethod = ELootLockerAdminHTTPMethod::GET;

	FString GetRequestMethodString() const
    {
        return ULootLockerAdminEnumUtils::GetEnum(TEXT("ELootLockerAdminHTTPMethod"), static_cast<int32>(requestMethod));
    }
};

UCLASS()
class LOOTLOCKERADMINSDK_API ULootLockerAdminEndpoints : public UObject
{
    GENERATED_BODY()
public:
    // Assets
    static FLootLockerAdminEndPoint CreateAsset;
	static FLootLockerAdminEndPoint GetAssetContexts;
	static FLootLockerAdminEndPoint ActivateAsset;

	// Catalog
	static FLootLockerAdminEndPoint AddPrice;
	static FLootLockerAdminEndPoint CreateCatalogListing;
	static FLootLockerAdminEndPoint ListCatalogs;
	static FLootLockerAdminEndPoint TogglePurchasableStatus;
	
	// Currency
	static FLootLockerAdminEndPoint CreateCurrency;
	static FLootLockerAdminEndPoint ListCurrencies;

	// Metadata
	static FLootLockerAdminEndPoint MetadataOperations;
	
	// Reward
	static FLootLockerAdminEndPoint CreateGroup;

	// Session
	static FLootLockerAdminEndPoint CreateSession;

private:
    static FString AdminApiUrl;

    static FLootLockerAdminEndPoint InitEndpoint(const FString& Endpoint, ELootLockerAdminHTTPMethod Method);
};
