
#pragma once

#include "Containers/Array.h"
#include "CoreMinimal.h"
#include "../LootLockerAdminResponse.h"

#include "LootLockerAdminSessionRequest.generated.h"

//==================================================
// Data Type Definitions
//==================================================

/**
 * User data
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminSessionUser
{
	GENERATED_BODY()
	/**
	 * Id of the user
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Id = 0;
	/**
	 * Name of the user
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Name = "";
	/**
	 * Email of the user
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Email = "";
	/**
	 * When the user signed up
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	int Signed_up = 0;
	/**
	 * If user have been verified
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
	
	/**
	 * Email of a registered user
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Email = "";
	/**
	 * Password for that user
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Password = "";
};


//==================================================
// Response Definitions
//==================================================

/**
 * Create session response
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminCreateSessionResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()
    
	/**
	 * Auth token returned will be set internally and used in any subsequent functions for authing requests
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Auth_token = "";
	/**
	 * User data
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FLootLockerAdminSessionUser User;
};

//==================================================
// Blueprint Delegate Definitions
//==================================================

/**
 * Blueprint response delegate for creating session
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminCreateSessionResponseBP, FLootLockerAdminCreateSessionResponse, Response);

//==================================================
// C++ Delegate Definitions
//==================================================

/**
 * C++ response delegate for creating session
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
