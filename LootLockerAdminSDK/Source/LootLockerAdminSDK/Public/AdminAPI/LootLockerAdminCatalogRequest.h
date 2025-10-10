
#pragma once

#include "Containers/Array.h"
#include "CoreMinimal.h"
#include "../LootLockerAdminResponse.h"

#include "LootLockerAdminCatalogRequest.generated.h"

//==================================================
// Data Type Definitions
//==================================================

/**
 * Possible entity kinds that catalog entries can have
 */
UENUM(BlueprintType, Category = "LootLockerAdmin")
enum class ELootLockerAdminCatalogEntityKind : uint8
{
	Asset = 0,
	Currency = 1,
	Progression_Points = 2,
	Progression_Reset = 3,
	Group = 4,
};

USTRUCT(BlueprintType)
struct FLootLockerAdminCatalogInfo
{
	GENERATED_BODY()
    
	/**
	 * Id of Catalog
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Id = "";
	/**
	 * Which game the catalog belong to
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Game_id = 0;
	/**
	 * Name of the catalog
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/**
	 * Authored id to reference it 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Key = "";
	/**
	 * If it has been deleted at what time
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Deleted_at = "";	
	/**
	 * When it was created
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Created_at = "";
};

USTRUCT(BlueprintType)
struct FLootLockerAdminCatalogPrice
{
	GENERATED_BODY()

	/**
	 * The amount of the currency
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Amount = "";
	/**
	 * Display string of amount and currency code
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Display_amount = "";
	/**
	 * What currency code
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Currency_code = "";
	/**
	 * The currency name
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Currency_name = "";
	/**
	 * The id of the currency
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Currency_id = "";
};

USTRUCT(BlueprintType)
struct FLootLockerAdminCatalogEntry
{
	GENERATED_BODY()

	/**
	 * The entity kind in the catalog
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_kind = "";
	/**
	 * Name of the entity
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_name = "";
	/**
	 * Prices for the entry. All of them are the cost
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminCatalogPrice> Prices;
	/**
	 * Id of the entity
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_id = "";
	/**
	 * Id of this catalog listing
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Catalog_listing_id = "";
	/**
	 * If the listing is set for sale
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Purchasable = false;
};

USTRUCT(BlueprintType)
struct FLootLockerAdminCatalogPagination
{
	GENERATED_BODY()

	/**
	 * Marker for previous page
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Previous_cursor = "";
	/**
	 * Marker for next page
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Next_cursor = "";
	/**
	 * Total number of items returned in this page
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Total = 0;
};

//==================================================
// Request Definitions
//==================================================

/**
 * Request data for AddPrice call
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminAddPriceRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()
	
	/**
	 * The amount for the price
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Amount = "";
	/**
	 * Which currency to add
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Currency_id = "";
	/**
	 * To which catalog item to add the price
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Catalog_item_id = "";
};

/**
 * Request data for CreateCatalogListing call
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateCatalogListingRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()

	/**
	 * Id of the catalog entry
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Catalog_id = "";
	/**
	 * Id of the entity in the catalog entry 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_id = "";
	/**
	 * What kind of entity it is
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_kind = "";
};

//==================================================
// Response Definitions
//==================================================

/**
 * Response data for AddPrice call
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminAddPriceResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()
    
	/**
	 * What catalog the catalog item is in
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Catalog_id = "";
	/**
	 * The catalog item the price was added to
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Catalog_item_id = "";
	/**
	 * The currency id of the added price
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Currency_id = "";
	/**
	 * Amount for the price
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Amount = "";
};

/**
 * Response data for CreateCatalogListing
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateCatalogListingResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()
    
	/**
	 * The id of the catalog listing that was created
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Catalog_item_id = "";
};

/**
 * Response data for ListCatalogs call
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminListCatalogsResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()
    
	/**
	 * The catalogs
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminCatalogInfo> Catalogs;
};

/**
 * Response data for ListCatalogItems call
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminListCatalogItemsResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()

	/**
	 * Catalog data
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FLootLockerAdminCatalogInfo Catalog;
	/**
	 * The catalog item entries
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminCatalogEntry> Entries;
	/**
	 * Pagination data for fetching other pages
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FLootLockerAdminCatalogPagination Pagination;
};

//==================================================
// Blueprint Delegate Definitions
//==================================================

/**
 * Blueprint response delegate for adding a price to a catalog listing
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminAddPriceResponseBP, FLootLockerAdminAddPriceResponse, Response);
/**
 * Blueprint response delegate for deleting a price from a catalog listing
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminDeletePriceResponseBP, FLootLockerAdminResponse, Response);
/**
 * Blueprint response delegate for creating a catalog listing
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminCreateCatalogListingResponseBP, FLootLockerAdminCreateCatalogListingResponse, Response);
/**
 * Blueprint response delegate for deleting a catalog listing
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminDeleteCatalogListingResponseBP, FLootLockerAdminResponse, Response);
/**
 * Blueprint response delegate for listing available catalogs
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminListCatalogsResponseBP, FLootLockerAdminListCatalogsResponse, Response);
/**
 * Blueprint response delegate for listing items in a catalog
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminListCatalogItemsResponseBP, FLootLockerAdminListCatalogItemsResponse, Response);
/**
 * Blueprint response delegate for toggle the flag if the item is purchasable
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminTogglePurchasableStatusResponseBP, FLootLockerAdminResponse, Response);

//==================================================
// C++ Delegate Definitions
//==================================================

/**
 * C++ response delegate for adding a price to a catalog listing
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminAddPriceResponseDelegate, FLootLockerAdminAddPriceResponse);
/**
 * C++ response delegate for deleting a price from a catalog listing
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminDeletePriceResponseDelegate, FLootLockerAdminResponse);
/**
 * C++ response delegate for creating a catalog listing
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminCreateCatalogListingResponseDelegate, FLootLockerAdminCreateCatalogListingResponse);
/**
 * C++ response delegate for deleting a catalog listing
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminDeleteCatalogListingResponseDelegate, FLootLockerAdminResponse);
/**
 * C++ response delegate for listing available catalogs
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminListCatalogsResponseDelegate, FLootLockerAdminListCatalogsResponse);
/**
 * C++ response delegate for listing items in a catalog
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminListCatalogItemsResponseDelegate, FLootLockerAdminListCatalogItemsResponse);
/**
 * C++ response delegate for toggle the flag if the item is purchasable
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminTogglePurchasableStatusResponseDelegate, FLootLockerAdminResponse);

/**
 *
 */
UCLASS()
class LOOTLOCKERADMINSDK_API ULootLockerAdminCatalogRequest : public UObject
{
    GENERATED_BODY()
    public:
    ULootLockerAdminCatalogRequest();

	static void AddPrice(const FString& CatalogItemId, const FString& CurrencyId, int Amount, const FLootLockerAdminAddPriceResponseBP& OnCompletedRequestBP = FLootLockerAdminAddPriceResponseBP(), const FLootLockerAdminAddPriceResponseDelegate& OnCompletedRequest = FLootLockerAdminAddPriceResponseDelegate());
	static void DeletePrice(const FString& CatalogId, const FString& CatalogItemId, const FString& CurrencyId, const FLootLockerAdminDeletePriceResponseBP& OnCompletedRequestBP = FLootLockerAdminDeletePriceResponseBP(), const FLootLockerAdminDeletePriceResponseDelegate& OnCompletedRequest = FLootLockerAdminDeletePriceResponseDelegate());
    static void CreateCatalogListing(const FString& CatalogId, const FString& EntityId, const ELootLockerAdminCatalogEntityKind& EntityKind, const FLootLockerAdminCreateCatalogListingResponseBP& OnCompletedRequestBP = FLootLockerAdminCreateCatalogListingResponseBP(), const FLootLockerAdminCreateCatalogListingResponseDelegate& OnCompletedRequest = FLootLockerAdminCreateCatalogListingResponseDelegate());
    static void DeleteCatalogListing(const FString& CatalogItemId, const FLootLockerAdminDeleteCatalogListingResponseBP& OnCompletedRequestBP = FLootLockerAdminDeleteCatalogListingResponseBP(), const FLootLockerAdminDeleteCatalogListingResponseDelegate& OnCompletedRequest = FLootLockerAdminDeleteCatalogListingResponseDelegate());
	static void ListCatalogs(const FLootLockerAdminListCatalogsResponseBP& OnCompletedRequestBP = FLootLockerAdminListCatalogsResponseBP(), const FLootLockerAdminListCatalogsResponseDelegate& OnCompletedRequest = FLootLockerAdminListCatalogsResponseDelegate());
	static void ListCatalogItems(const FString& CatalogId, const int Count, const FString& After, const FLootLockerAdminListCatalogItemsResponseBP& OnCompletedRequestBP = FLootLockerAdminListCatalogItemsResponseBP(), const FLootLockerAdminListCatalogItemsResponseDelegate& OnCompletedRequest = FLootLockerAdminListCatalogItemsResponseDelegate());
	static void TogglePurchasableStatus(const FString& CatalogItemId, const FLootLockerAdminTogglePurchasableStatusResponseBP& OnCompletedRequestBP = FLootLockerAdminTogglePurchasableStatusResponseBP(), const FLootLockerAdminTogglePurchasableStatusResponseDelegate& OnCompletedRequest = FLootLockerAdminTogglePurchasableStatusResponseDelegate());
};
