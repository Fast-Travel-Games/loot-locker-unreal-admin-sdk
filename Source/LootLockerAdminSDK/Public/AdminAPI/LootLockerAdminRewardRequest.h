
#pragma once

#include "Containers/Array.h"
#include "CoreMinimal.h"
#include "../LootLockerAdminResponse.h"

#include "LootLockerAdminRewardRequest.generated.h"

//==================================================
// Data Type Definitions
//==================================================

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminEntity
{
	GENERATED_BODY()

	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_id = "";
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_kind = "";
	// Do not need metadata so skip it here
};

//==================================================
// Request Definitions
//==================================================

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateGroupRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()
	
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_id = "";
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_kind = "";
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Description = "";
	/*

	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminEntity> Associations;
};


//==================================================
// Response Definitions
//==================================================


//==================================================
// Blueprint Delegate Definitions
//==================================================

/*
 Blueprint response delegate for creating a currency
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminCreateGroupResponseBP, FLootLockerAdminResponse, Response);

//==================================================
// C++ Delegate Definitions
//==================================================

/*
 C++ response delegate for creating a currency
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminCreateGroupResponseDelegate, FLootLockerAdminResponse);

/**
 *
 */
UCLASS()
class LOOTLOCKERADMINSDK_API ULootLockerAdminRewardRequest : public UObject
{
    GENERATED_BODY()
    public:
    ULootLockerAdminRewardRequest();

    static void CreateGroup(const TArray<FLootLockerAdminEntity>& Entities, const FString& Name, const FString& Description, const FLootLockerAdminCreateGroupResponseBP& OnCompletedRequestBP = FLootLockerAdminCreateGroupResponseBP(), const FLootLockerAdminCreateGroupResponseDelegate& OnCompletedRequest = FLootLockerAdminCreateGroupResponseDelegate());
};
