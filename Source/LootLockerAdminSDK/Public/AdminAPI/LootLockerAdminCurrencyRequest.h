
#pragma once

#include "Containers/Array.h"
#include "CoreMinimal.h"
#include "../LootLockerAdminResponse.h"

#include "LootLockerAdminCurrencyRequest.generated.h"

//==================================================
// Data Type Definitions
//==================================================


//==================================================
// Request Definitions
//==================================================

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateCurrencyRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()
	
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Code = "";
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Initial_denomination_name = "";
};


//==================================================
// Response Definitions
//==================================================

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateCurrencyResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()
    
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Id = "";
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Game_id = "";
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Code = "";
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Game_api_writes_enabled = false;
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Created_at = ""; // TODO: convert to FDateTime ??
};

//==================================================
// Blueprint Delegate Definitions
//==================================================

/*
 Blueprint response delegate for creating a currency
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminCreateCurrencyResponseBP, FLootLockerAdminCreateCurrencyResponse, Response);

//==================================================
// C++ Delegate Definitions
//==================================================

/*
 C++ response delegate for creating a currency
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminCreateCurrencyResponseDelegate, FLootLockerAdminCreateCurrencyResponse);

/**
 *
 */
UCLASS()
class LOOTLOCKERADMINSDK_API ULootLockerAdminCurrencyRequest : public UObject
{
    GENERATED_BODY()
    public:
    ULootLockerAdminCurrencyRequest();

    static void CreateCurrency(const FString& Name, const FString& Code, const FString& DenominationName, const FLootLockerAdminCreateCurrencyResponseBP& OnCompletedRequestBP = FLootLockerAdminCreateCurrencyResponseBP(), const FLootLockerAdminCreateCurrencyResponseDelegate& OnCompletedRequest = FLootLockerAdminCreateCurrencyResponseDelegate());
};
