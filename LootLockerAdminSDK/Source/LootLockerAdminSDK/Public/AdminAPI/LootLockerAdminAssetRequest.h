
#pragma once

#include "Containers/Array.h"
#include "CoreMinimal.h"
#include "../LootLockerAdminResponse.h"

#include "LootLockerAdminAssetRequest.generated.h"

//==================================================
// Data Type Definitions
//==================================================

/**
 * Context data
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminAssetContext
{
	GENERATED_BODY()
	/**
	 * Id
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Id = 0;
	/**
	 * UUID
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Uuid = "";
	/**
	 * Name
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/**
	 * Friendly name
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Friendly_name = "";
	/**
	 * What type
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Type = 0;
	/**
	 * If assets in this context in the class loadout can be unassigned
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Detachable = false;
	/**
	 * If exposed to platform integrations
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool User_facing = false;
	/**
	 * Dependent
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Dependent_asset_id = false;
	/**
	 * Maximum number of assets with this context a player can equip
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Max_equip_count = 0;
	/**
	 * If context is editable
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Editable = false;
};

/**
 * Create asset response data
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateAssetData
{
	GENERATED_BODY()
	/**
	 * The Id of the created asset
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Id = 0;
	/**
	 * The UUID of the created asset
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Uuid = "";
	/**
	 * The ULID of the created asset
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Ulid = "";
	/**
	 * The Context the created asset belongs to
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Context_id = 0;
};

/**
 * Response data for assets
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminAssetData
{
	GENERATED_BODY()
	/**
	 * Id of asset
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Id = 0;
	/**
	 * UUID of asset
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Uuid = "";
	/**
	 * ULID of asset
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Ulid = "";
	/**
	 * Name of asset
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/**
	 * When it was created
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Created_at = "";
	/**
	 * When it was last changed
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Last_changed = "";
	/**
	 * If asset is active
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Active = false;
	/**
	 * If asset is purchasable
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Purchasable = false;
	/**
	 * ?
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Tradable = false;
	/**
	 * ?
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Marketable = false;
};

//==================================================
// Request Definitions
//==================================================

/**
 * Request data for CreateAsset call
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateAssetRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()

	/**
	 * Which context the Asset should be in
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Context_id = 0;
	/**
	 * Name of the Asset
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/**
	 * If the Asset should be unique instance (players can only own one)
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Unique_instance = false;
};

/**
 * Request data for ActivateAsset call
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminActivateAssetRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()

	/**
	 * If activate or not
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Live_and_debug = false;
};


//==================================================
// Response Definitions
//==================================================

/**
 * Response struct for GetAssetContext calls
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminGetAssetContextsResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()
    
	/**
	 * The contexts
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminAssetContext> Contexts;
};

/**
 * Response struct for CreateAsset calls
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateAssetResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()

	/**
	 * The created asset data
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FLootLockerAdminCreateAssetData Asset;
};

/**
 * Response struct for GetAssets calls
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminGetAssetsResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()

	/**
	 * The Assets
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminAssetData> Assets;

	/**
	 * Number of assets returned
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Asset_count = 0;
};

//==================================================
// Blueprint Delegate Definitions
//==================================================

/**
 * Blueprint response delegate for getting assets contexts
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminGetAssetContextsResponseBP, FLootLockerAdminGetAssetContextsResponse, Response);
/**
 * Blueprint response delegate creating an asset
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminCreateAssetResponseBP, FLootLockerAdminCreateAssetResponse, Response);
/**
 * Blueprint response delegate activating an asset
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminActivateAssetResponseBP, FLootLockerAdminResponse, Response);
/**
 * Blueprint response delegate getting assets
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminGetAssetsResponseBP, FLootLockerAdminGetAssetsResponse, Response);

//==================================================
// C++ Delegate Definitions
//==================================================

/**
 * C++ response delegate for getting assets contexts
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminGetAssetContextsResponseDelegate, FLootLockerAdminGetAssetContextsResponse);
/**
 * C++ response delegate for creating an asset
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminCreateAssetResponseDelegate, FLootLockerAdminCreateAssetResponse);
/**
 * C++ response delegate for activating an asset
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminActivateAssetResponseDelegate, FLootLockerAdminResponse);
/**
 * C++ response delegate for getting assets
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminGetAssetsResponseDelegate, FLootLockerAdminGetAssetsResponse);


/**
 *
 */
UCLASS()
class LOOTLOCKERADMINSDK_API ULootLockerAdminAssetRequest : public UObject
{
    GENERATED_BODY()
    public:
    ULootLockerAdminAssetRequest();

	static void GetAssetContexts(const FLootLockerAdminGetAssetContextsResponseBP& OnCompletedRequestBP = FLootLockerAdminGetAssetContextsResponseBP(), const FLootLockerAdminGetAssetContextsResponseDelegate& OnCompletedRequest = FLootLockerAdminGetAssetContextsResponseDelegate());
    static void CreateAsset(const int Context, const FString& Name, const bool bUniqueInstance, const FLootLockerAdminCreateAssetResponseBP& OnCompletedRequestBP = FLootLockerAdminCreateAssetResponseBP(), const FLootLockerAdminCreateAssetResponseDelegate& OnCompletedRequest = FLootLockerAdminCreateAssetResponseDelegate());
	static void ActivateAsset(const int AssetId, const bool bActive, const FLootLockerAdminActivateAssetResponseBP& OnCompletedRequestBP = FLootLockerAdminActivateAssetResponseBP(), const FLootLockerAdminActivateAssetResponseDelegate& OnCompletedRequest = FLootLockerAdminActivateAssetResponseDelegate());
	static void GetAssets(const bool bIncludeInactive, const FLootLockerAdminGetAssetsResponseBP& OnCompletedRequestBP = FLootLockerAdminGetAssetsResponseBP(), const FLootLockerAdminGetAssetsResponseDelegate& OnCompletedRequest = FLootLockerAdminGetAssetsResponseDelegate());
};
