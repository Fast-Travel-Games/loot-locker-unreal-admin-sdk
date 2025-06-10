
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
class LOOTLOCKERADMINSDKEDITOR_API ULootLockerAdminSessionRequest : public UObject
{
    GENERATED_BODY()
    public:
    ULootLockerAdminSessionRequest();

    static void CreateSession(FString email, FString Password, const FLootLockerAdminCreateSessionResponseBP& OnCompletedRequestBP = FLootLockerAdminCreateSessionResponseBP(), const FLootLockerAdminCreateSessionResponseDelegate& OnCompletedRequest = FLootLockerAdminCreateSessionResponseDelegate());
};

/*
/admin/v1/session

curl --location --request POST 'https://api.lootlocker.io/admin/v1/session' \
--header 'LL-Version: 2021-03-01' \
--header 'Content-type: application/json' \
--data-raw '{
    "email": "",
    "password": ""
}'

Response

{
  "success": true,
  "auth_token": "ca8bbb2b2c88acb945383dcd43ca414756b3822e",
  "user": {
    "id": 10197,
    "name": "Some Dude",
    "email": "dev@lootlocker.com",
    "signed_up": 1705320108,
    "is_verified": true,
    "organisations": [
      {
        "id": 10485,
        "name": "Lootlocker",
        "games": [
          {
            "id": 23646,
            "is_demo": false,
            "name": "asd",
            "badge_url": "",
            "logo_url": "",
            "development": {
              "id": 23647,
              "is_demo": false,
              "name": "asd",
              "badge_url": "",
              "logo_url": ""
            }
          }
        ],
        "finalized_signup_at": "2024-01-15T12:02:28Z"
      }
    ]
  }
}
*/
