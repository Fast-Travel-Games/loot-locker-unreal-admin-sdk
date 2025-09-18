
#pragma once

#include "Containers/Array.h"
#include "CoreMinimal.h"
#include "../LootLockerAdminResponse.h"

#include "LootLockerAdminPlayerRequest.generated.h"

//==================================================
// Data Type Definitions
//==================================================

/**
 *
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminListPlayersPagination
{
	GENERATED_BODY()
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Total = 0;
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Per_page = 0;
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Next_page = 0;
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Current_page = 0;
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Last_page = 0;
};

/**
 *
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminListPlayersItem
{
	GENERATED_BODY()
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Id = "";
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Player_id = 0;
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Public_uid = "";
};

//==================================================
// Request Definitions
//==================================================

/**
 *
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminGrantAssetRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()

	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Asset_id = 0;
};


//==================================================
// Response Definitions
//==================================================

/**
 *
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminListPlayersResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()

	/*
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FLootLockerAdminListPlayersPagination Pagination;

	/*
	 *
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminListPlayersItem> Items;
};

//==================================================
// Blueprint Delegate Definitions
//==================================================

/*
 Blueprint response delegate for granting an asset to a player
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminGrantAssetResponseBP, FLootLockerAdminResponse, Response);

/*
 Blueprint response delegate for listing players
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminListPlayersResponseBP, FLootLockerAdminListPlayersResponse, Response);

//==================================================
// C++ Delegate Definitions
//==================================================

/*
 C++ response delegate for granting an asset to a player
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminGrantAssetResponseDelegate, FLootLockerAdminResponse);

/*
 C++ response delegate for listing players
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminListPlayersResponseDelegate, FLootLockerAdminListPlayersResponse);

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
	static void ListPlayers(const int Count, const int Page, const FLootLockerAdminListPlayersResponseBP& OnCompletedRequestBP = FLootLockerAdminListPlayersResponseBP(), const FLootLockerAdminListPlayersResponseDelegate& OnCompletedRequest = FLootLockerAdminListPlayersResponseDelegate());
};
