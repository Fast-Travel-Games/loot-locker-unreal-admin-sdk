
#pragma once

#include "Containers/Array.h"
#include "CoreMinimal.h"
#include "../LootLockerAdminResponse.h"

#include "LootLockerAdminRewardRequest.generated.h"

//==================================================
// Data Type Definitions
//==================================================

/**
 * Metadata struct
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminEntityMetadata
{
	GENERATED_BODY()

	/**
	 * Key for metadata
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Key = "purchased_amount";
	/**
	 * Value for metadata
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Value = "";
};

/**
 * Entity data
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminEntity
{
	GENERATED_BODY()

	/**
	 * The Id of the entity
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_id = "";
	/**
	 * What kind the entity is
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_kind = "";
	/**
	 * Any metadata related to this entity
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminEntityMetadata> Metadata;
};

//==================================================
// Request Definitions
//==================================================

/**
 * Request data for CreateGroup call
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateGroupRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()
	
	/**
	 * Id of the entity we want to include in the group
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_id = "";
	/**
	 * What kind is the entity
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_kind = "";
	/**
	 * Name of the entity
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/**
	 * Description of the entity
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Description = "";
	/**
	 * Which entities to include in this group
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminEntity> Associations;
};


//==================================================
// Response Definitions
//==================================================

/**
 * Response data for CreateGroup call
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateGroupResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()

	/**
	 * Id of the created group
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Id = "";
};

//==================================================
// Blueprint Delegate Definitions
//==================================================

/**
 * Blueprint response delegate for creating a group
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminCreateGroupResponseBP, FLootLockerAdminCreateGroupResponse, Response);

//==================================================
// C++ Delegate Definitions
//==================================================

/**
 * C++ response delegate for creating a group
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminCreateGroupResponseDelegate, FLootLockerAdminCreateGroupResponse);

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
