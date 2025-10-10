
#pragma once

#include "Containers/Array.h"
#include "CoreMinimal.h"
#include "../LootLockerAdminResponse.h"

#include "LootLockerAdminCurrencyRequest.generated.h"

//==================================================
// Data Type Definitions
//==================================================


/**
 * Details about a particular currency
 */
USTRUCT(BlueprintType, Category = "LootLockerAdmin")
struct FLootLockerAdminCurrency
{
	GENERATED_BODY()
	/**
	 * The unique id of the currency
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Id;
	/**
	 * The game id the currency belong to
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Game_id = "";
	/**
	 * The name of the currency
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name;
	/**
	 * The unique short code of the currency
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Code;
	/**
	 * True if this currency can be awarded to the player from the game api
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Game_api_writes_enabled = false;
	/**
	 * The time that this currency was created
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Created_at;
};

//==================================================
// Request Definitions
//==================================================

/**
 * Request data for CreateCurrency
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateCurrencyRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()
	
	/**
	 * Name of the Currency
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/**
	 * Three character code. Must be unique for the game 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Code = "";
	/**
	 * Name of denominator
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Initial_denomination_name = "";
};


//==================================================
// Response Definitions
//==================================================

/**
 * Response for CreateCurrency call
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateCurrencyResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()
    
	/**
	 * Id of the created currency
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Id = "";
	/**
	 * The game the currency belong to
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Game_id = "";
	/**
	 * Name of the currency
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/**
	 * The currency code
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Code = "";
	/**
	 * If game API are allowed to change values of this currency
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Game_api_writes_enabled = false;
	/**
	 * When the currency was created
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Created_at = "";
};

/**
 * Response data for ListCurrencies
 */
USTRUCT(BlueprintType, Category = "LootLockerAdmin")
struct FLootLockerAdminListCurrenciesResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()
	/**
	 * List of available currencies
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminCurrency> Currencies;
};


//==================================================
// Blueprint Delegate Definitions
//==================================================

/**
 * Blueprint response delegate for creating a currency
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminCreateCurrencyResponseBP, FLootLockerAdminCreateCurrencyResponse, Response);
/**
 * Blueprint response delegate for listing currencies
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminListCurrenciesResponseBP, FLootLockerAdminListCurrenciesResponse, Response);

//==================================================
// C++ Delegate Definitions
//==================================================

/**
 * C++ response delegate for creating a currency
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminCreateCurrencyResponseDelegate, FLootLockerAdminCreateCurrencyResponse);
/**
 * C++ response delegate for listing currencies
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminListCurrenciesResponseDelegate, FLootLockerAdminListCurrenciesResponse);

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
	static void ListCurrencies(const FLootLockerAdminListCurrenciesResponseBP& OnResponseCompletedBP = FLootLockerAdminListCurrenciesResponseBP(), const FLootLockerAdminListCurrenciesResponseDelegate& OnResponseCompleted = FLootLockerAdminListCurrenciesResponseDelegate());
};
