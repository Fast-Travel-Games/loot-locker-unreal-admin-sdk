
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
	UPROPERTY(BlueprintReadOnly, Category = "LootLockerAdmin")
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
 * Request data for CreateCurrencyReward
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateCurrencyRewardRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()

	/**
	 * Id of the entity
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Entity_id = "";
	/**
	 * What kind is the entity
	 */
	UPROPERTY(BlueprintReadOnly, Category = "LootLockerAdmin")
	FString Entity_kind = "currency";
	/**
	 * Set the amount of currencies in the reward
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminEntityMetadata> Metadata;
};

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
struct FLootLockerAdminCreateRewardResponse : public FLootLockerAdminResponse
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
 * Blueprint response delegate for creating a currency reward
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminCreateCurrencyRewardResponseBP, FLootLockerAdminCreateRewardResponse, Response);

/**
 * Blueprint response delegate for creating a group reward
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminCreateGroupResponseBP, FLootLockerAdminCreateRewardResponse, Response);

//==================================================
// C++ Delegate Definitions
//==================================================

/**
 * C++ response delegate for creating a currency reward
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminCreateCurrencyRewardResponseDelegate, FLootLockerAdminCreateRewardResponse);

/**
 * C++ response delegate for creating a group reward
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminCreateGroupResponseDelegate, FLootLockerAdminCreateRewardResponse);

/**
 *
 */
UCLASS()
class LOOTLOCKERADMINSDK_API ULootLockerAdminRewardRequest : public UObject
{
    GENERATED_BODY()
    public:
    ULootLockerAdminRewardRequest();

	static void CreateCurrencyReward(const FLootLockerAdminEntity& Reward, const FLootLockerAdminCreateCurrencyRewardResponseBP& OnCompletedRequestBP = FLootLockerAdminCreateCurrencyRewardResponseBP(), const FLootLockerAdminCreateCurrencyRewardResponseDelegate& OnCompletedRequest = FLootLockerAdminCreateCurrencyRewardResponseDelegate());
    static void CreateGroup(const TArray<FLootLockerAdminEntity>& Entities, const FString& Name, const FString& Description, const FLootLockerAdminCreateGroupResponseBP& OnCompletedRequestBP = FLootLockerAdminCreateGroupResponseBP(), const FLootLockerAdminCreateGroupResponseDelegate& OnCompletedRequest = FLootLockerAdminCreateGroupResponseDelegate());
};
