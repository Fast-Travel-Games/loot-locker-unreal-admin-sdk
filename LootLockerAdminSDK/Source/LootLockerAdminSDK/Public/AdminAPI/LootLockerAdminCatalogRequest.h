
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
    
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Id = "";
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Game_id = 0;
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Key = "";
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Deleted_at = "";	
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Created_at = "";
};

USTRUCT(BlueprintType)
struct FLootLockerAdminCatalogPrice
{
	GENERATED_BODY()

	/*

	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Amount = "";
	/*

	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Display_amount = "";
	/*

	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Currency_code = "";
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Currency_name = "";
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Currency_id = "";
};

USTRUCT(BlueprintType)
struct FLootLockerAdminCatalogEntry
{
	GENERATED_BODY()

	/*

	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_kind = "";
	/*

	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_name = "";
	/*

	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminCatalogPrice> Prices;
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_id = "";
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Catalog_listing_id = "";
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Purchasable = false;
};

USTRUCT(BlueprintType)
struct FLootLockerAdminCatalogPagination
{
	GENERATED_BODY()

	/*

	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Previous_cursor = "";
	/*

	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Next_cursor = "";
	/*

	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Total = 0;
};

//==================================================
// Request Definitions
//==================================================

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminAddPriceRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()
	
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Amount = "";
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Currency_id = "";
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Catalog_item_id = "";
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateCatalogListingRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()

	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Catalog_id = "";
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_id = "";
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_kind = "";
};

//==================================================
// Response Definitions
//==================================================

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminAddPriceResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()
    
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Catalog_id = "";
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Catalog_item_id = "";
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Currency_id = "";
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Amount = "";
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateCatalogListingResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()
    
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Catalog_item_id = "";
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminListCatalogsResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()
    
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminCatalogInfo> Catalogs;
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminListCatalogItemsResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()

	/*

	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FLootLockerAdminCatalogInfo Catalog;

	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminCatalogEntry> Entries;

	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FLootLockerAdminCatalogPagination Pagination;
};

//==================================================
// Blueprint Delegate Definitions
//==================================================

/*
 Blueprint response delegate for adding a price to a catalog listing
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminAddPriceResponseBP, FLootLockerAdminAddPriceResponse, Response);
/*
 Blueprint response delegate for deleting a price from a catalog listing
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminDeletePriceResponseBP, FLootLockerAdminResponse, Response);
/*
 Blueprint response delegate for creating a catalog listing
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminCreateCatalogListingResponseBP, FLootLockerAdminCreateCatalogListingResponse, Response);
/*
 Blueprint response delegate for deleting a catalog listing
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminDeleteCatalogListingResponseBP, FLootLockerAdminResponse, Response);
/*
 Blueprint response delegate for listing available catalogs
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminListCatalogsResponseBP, FLootLockerAdminListCatalogsResponse, Response);
/*
 Blueprint response delegate for listing items in a catalog
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminListCatalogItemsResponseBP, FLootLockerAdminListCatalogItemsResponse, Response);
/*
 Blueprint response delegate for toggle the flag if the item is purchasable
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminTogglePurchasableStatusResponseBP, FLootLockerAdminResponse, Response);

//==================================================
// C++ Delegate Definitions
//==================================================

/*
 C++ response delegate for adding a price to a catalog listing
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminAddPriceResponseDelegate, FLootLockerAdminAddPriceResponse);
/*
 C++ response delegate for deleting a price from a catalog listing
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminDeletePriceResponseDelegate, FLootLockerAdminResponse);
/*
 C++ response delegate for creating a catalog listing
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminCreateCatalogListingResponseDelegate, FLootLockerAdminCreateCatalogListingResponse);
/*
 C++ response delegate for deleting a catalog listing
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminDeleteCatalogListingResponseDelegate, FLootLockerAdminResponse);
/*
 C++ response delegate for listing available catalogs
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminListCatalogsResponseDelegate, FLootLockerAdminListCatalogsResponse);
/*
 C++ response delegate for listing items in a catalog
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminListCatalogItemsResponseDelegate, FLootLockerAdminListCatalogItemsResponse);
/*
 C++ response delegate for toggle the flag if the item is purchasable
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
