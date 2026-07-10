
#pragma once

#include "Containers/Array.h"
#include "CoreMinimal.h"
#include "../LootLockerAdminResponse.h"

#include "LootLockerAdminPlayerRequest.generated.h"

//==================================================
// Data Type Definitions
//==================================================

/**
 * Pagination data in the response for ListPlayers call
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminListPlayersPagination
{
	GENERATED_BODY()
	/**
	 * Total number of players
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Total = 0;
	/**
	 * How many players per page are returned
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Per_page = 0;
	/**
	 * What is the next page to fetch
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Next_page = 0;
	/**
	 * Current page
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Current_page = 0;
	/**
	 * Index of the last page
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Last_page = 0;
};

/**
 * Player data in ListPlayers call
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminListPlayersItem
{
	GENERATED_BODY()
	/**
	 * Id of player
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Id = "";
	/**
	 * Other player id
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Player_id = 0;
	/**
	 * Name of the player
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/**
	 * UID for the player
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Public_uid = "";
};

/**
 * Player inventory data in ListPlayerInventory call
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminListPlayerInventoryItem
{
	GENERATED_BODY()
	/**
	 * Id of asset instance
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Id = 0;
	/**
	 * Id of the Player
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Player_id = 0;
	/**
	 * Id of the asset
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Asset_id = 0;
	/**
	 * ULID of the asset instance
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Ulid = "";
	/**
	 * Name of the asset
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Asset_name = "";
	/**
	 * Name of the context item belong to
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Context_name = "";
};


//==================================================
// Request Definitions
//==================================================

/**
 * Data for GrantAsset calls
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminGrantAssetRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()

	/**
	 * Which Asset to grant to a player
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Asset_id = 0;
};

/**
 * Data for Delete Player Data calls
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminDeletePlayerDataRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()

	/**
	 * Delete Character and Hero inventories data
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Character_and_hero_inventories = false;
	/**
	 * Delete Character and Hero progressions data
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Character_and_hero_progressions = false;
	/**
	 * Delete Character and Heroes data
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Character_and_heroes = false;
	/**
	 * Delete Currencies data
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Currencies = false;
	/**
	 * Delete Inventory Item Metadata data
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Inventory_item_metadata = false;
	/**
	 * Delete Inventory Item Progressions data
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Inventory_item_progressions = false;
	/**
	 * Delete Player Files data
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Player_files = false;
	/**
	 * Delete Player Inventories data
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Player_inventories = false;
	/**
	 * Delete Player Metadata data
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Player_metadata = false;
	/**
	 * Delete Player Progressions data
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Player_progressions = false;
	/**
	 * Delete Player Storage data
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Player_storage = false;
	/**
	 * Resets all trigger invocations for the player
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Trigger_calls = false;
};


//==================================================
// Response Definitions
//==================================================

/**
 * Response data for ListPlayers call
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminListPlayersResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()

	/**
	 * Pagination data to know how to fetch other pages
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FLootLockerAdminListPlayersPagination Pagination;

	/**
	 * List of players returned
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminListPlayersItem> Items;
};

USTRUCT(BlueprintType)
struct FLootLockerAdminListPlayerInventoryResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()

	/**
	 * List of items returned
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminListPlayerInventoryItem> Items;
};

//==================================================
// Blueprint Delegate Definitions
//==================================================

/**
 * Blueprint response delegate for granting an asset to a player
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminGrantAssetResponseBP, FLootLockerAdminResponse, Response);

/**
 * Blueprint response delegate for granting an asset to a player
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminDeleteAssetFromPlayerResponseBP, FLootLockerAdminResponse, Response);

/**
 * Blueprint response delegate for listing players
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminListPlayersResponseBP, FLootLockerAdminListPlayersResponse, Response);

/**
 * Blueprint response delegate for listing players
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminListPlayerInventoryResponseBP, FLootLockerAdminListPlayerInventoryResponse, Response);

/**
 * Blueprint response delegate for deleting player data
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminDeletePlayerDataResponseBP, FLootLockerAdminResponse, Response);

//==================================================
// C++ Delegate Definitions
//==================================================

/**
 * C++ response delegate for granting an asset to a player
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminGrantAssetResponseDelegate, FLootLockerAdminResponse);

/**
 * C++ response delegate for deleting an asset from a player
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminDeleteAssetFromPlayerResponseDelegate, FLootLockerAdminResponse);

/**
 * C++ response delegate for listing players
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminListPlayersResponseDelegate, FLootLockerAdminListPlayersResponse);

/**
 * C++ response delegate for listing a players inventory
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminListPlayerInventoryResponseDelegate, FLootLockerAdminListPlayerInventoryResponse);

/**
 * C++ response delegate for deleting player data
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminDeletePlayerDataResponseDelegate, FLootLockerAdminResponse);

/**
 *
 */
UCLASS()
class LOOTLOCKERADMINSDK_API ULootLockerAdminPlayerRequest : public UObject
{
    GENERATED_BODY()
    public:
    ULootLockerAdminPlayerRequest();

	static void GrantAsset(const FString& PlayerId, const int AssetId, const FLootLockerAdminGrantAssetResponseBP& OnCompletedRequestBP = FLootLockerAdminGrantAssetResponseBP(), const FLootLockerAdminGrantAssetResponseDelegate& OnCompletedRequest = FLootLockerAdminGrantAssetResponseDelegate());
	static void DeleteAssetFromPlayer(const FString& PlayerId, const int AssetId, const FLootLockerAdminDeleteAssetFromPlayerResponseBP& OnCompletedRequestBP = FLootLockerAdminDeleteAssetFromPlayerResponseBP(), const FLootLockerAdminDeleteAssetFromPlayerResponseDelegate& OnCompletedRequest = FLootLockerAdminDeleteAssetFromPlayerResponseDelegate());
	static void ListPlayers(const int Count, const int Page, const FLootLockerAdminListPlayersResponseBP& OnCompletedRequestBP = FLootLockerAdminListPlayersResponseBP(), const FLootLockerAdminListPlayersResponseDelegate& OnCompletedRequest = FLootLockerAdminListPlayersResponseDelegate());
	static void ListPlayerInventory(const FString& PlayerId, const FLootLockerAdminListPlayerInventoryResponseBP& OnCompletedRequestBP = FLootLockerAdminListPlayerInventoryResponseBP(), const FLootLockerAdminListPlayerInventoryResponseDelegate& OnCompletedRequest = FLootLockerAdminListPlayerInventoryResponseDelegate());
	static void DeletePlayerData(const FString& PlayerId, const FLootLockerAdminDeletePlayerDataRequest& Request, const FLootLockerAdminDeletePlayerDataResponseBP& OnCompletedRequestBP = FLootLockerAdminDeletePlayerDataResponseBP(), const FLootLockerAdminDeletePlayerDataResponseDelegate& OnCompletedRequest = FLootLockerAdminDeletePlayerDataResponseDelegate());
};
