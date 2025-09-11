
#pragma once

#include "Containers/Array.h"
#include "CoreMinimal.h"
#include "../LootLockerAdminResponse.h"

#include "LootLockerAdminAssetRequest.generated.h"

//==================================================
// Data Type Definitions
//==================================================

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminAssetContext
{
	GENERATED_BODY()
	/*
	 Id
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Id = 0;
	/*
	 UUID
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Uuid = "";
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Friendly_name = "";
	/*
	
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Type = 0;
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Detachable = false;
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool User_facing = false;
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Dependent_asset_id = false;
	/*
	
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Max_equip_count = 0;
	/*
	
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Editable = false;
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateAssetData
{
	GENERATED_BODY()
	/*
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Id = 0;
	/*
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Uuid = "";
	/*
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Ulid = "";
	/*
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Context_id = 0;
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminAssetData
{
	GENERATED_BODY()
	/**
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Id = 0;
	/**
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Uuid = "";
	/**
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Ulid = "";
	/**
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/**
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Created_at = "";
	/**
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Last_changed = "";
	/**
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Active = false;
	/**
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Purchasable = false;
	/**
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Tradable = false;
	/*
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Marketable = false;
};

//==================================================
// Request Definitions
//==================================================

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateAssetRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()

	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Context_id = 0;
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Unique_instance = false;
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminActivateAssetRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()

	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Live_and_debug = false;
};


//==================================================
// Response Definitions
//==================================================

/**
 *
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminGetAssetContextsResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()
    
	/*
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminAssetContext> Contexts;

	// TODO: implement "unlock_assets":null
};

/**
 *
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateAssetResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()

	/**
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FLootLockerAdminCreateAssetData Asset;
};

/**
 *
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminGetAssetsResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()

	/**
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminAssetData> Assets;

	/**
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Asset_count = 0;
};

//==================================================
// Blueprint Delegate Definitions
//==================================================

/*
 Blueprint response delegate for getting assets contexts
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminGetAssetContextsResponseBP, FLootLockerAdminGetAssetContextsResponse, Response);
/*
 Blueprint response delegate creating an asset
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminCreateAssetResponseBP, FLootLockerAdminCreateAssetResponse, Response);
/*
 Blueprint response delegate activating an asset
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminActivateAssetResponseBP, FLootLockerAdminResponse, Response);
/*
 Blueprint response delegate getting assets
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminGetAssetsResponseBP, FLootLockerAdminGetAssetsResponse, Response);

//==================================================
// C++ Delegate Definitions
//==================================================

/*
 C++ response delegate for getting assets contexts
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminGetAssetContextsResponseDelegate, FLootLockerAdminGetAssetContextsResponse);
/*
 C++ response delegate for creating an asset
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminCreateAssetResponseDelegate, FLootLockerAdminCreateAssetResponse);
/*
 C++ response delegate for activating an asset
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminActivateAssetResponseDelegate, FLootLockerAdminResponse);
/*
 C++ response delegate for getting assets
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
