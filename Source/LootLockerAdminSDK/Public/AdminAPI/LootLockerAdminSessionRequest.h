
#pragma once

#include "Containers/Array.h"
#include "CoreMinimal.h"
#include "../LootLockerAdminResponse.h"

#include "LootLockerAdminSessionRequest.generated.h"

//==================================================
// Data Type Definitions
//==================================================

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminSessionUser
{
	GENERATED_BODY()
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Id = 0;
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Email = "";
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Signed_up = 0;
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	bool Is_verified = false;
};


//==================================================
// Request Definitions
//==================================================

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateSessionRequest : public FLootLockerAdminEmptyRequest
{
	GENERATED_BODY()
	
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Email = "";
	/*
 
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Password = "";
};


//==================================================
// Response Definitions
//==================================================

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateSessionResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()
    
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Auth_token = "";
	/*
	 
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FLootLockerAdminSessionUser User;
};

//==================================================
// Blueprint Delegate Definitions
//==================================================

/*
 Blueprint response delegate for getting assets
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminCreateSessionResponseBP, FLootLockerAdminCreateSessionResponse, Response);

//==================================================
// C++ Delegate Definitions
//==================================================

/*
 C++ response delegate for getting assets
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminCreateSessionResponseDelegate, FLootLockerAdminCreateSessionResponse);

/**
 *
 */
UCLASS()
class LOOTLOCKERADMINSDK_API ULootLockerAdminSessionRequest : public UObject
{
    GENERATED_BODY()
    public:
    ULootLockerAdminSessionRequest();

    static void CreateSession(FString email, FString Password, const FLootLockerAdminCreateSessionResponseBP& OnCompletedRequestBP = FLootLockerAdminCreateSessionResponseBP(), const FLootLockerAdminCreateSessionResponseDelegate& OnCompletedRequest = FLootLockerAdminCreateSessionResponseDelegate());
};
