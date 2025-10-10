
#pragma once
#include "LootLockerAdminResponse.generated.h"

/*
 An empty type to use as empty request bodies
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminEmptyRequest
{
    GENERATED_BODY()
};

USTRUCT(BlueprintType)
struct FLootLockerAdminErrorData
{
    GENERATED_BODY()
    // A descriptive code identifying the error.
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FString Code;
    // A link to further documentation on the error.
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FString Doc_url;
    // A unique identifier of the request to use in contact with support.
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FString Request_id;
    // A unique identifier for tracing the request through LootLocker systems, use this in contact with support.
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FString Trace_id;
    /// <summary>
    /// If the request was rate limited (status code 429) or the servers were temporarily unavailable (status code 503) you can use this value to determine how many seconds to wait before retrying
    /// </summary>
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    int Retry_after_seconds = -1;
    // A free text description of the problem and potential suggestions for fixing it
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FString Message;
};

/*
 The base response for all LootLocker Admin responses
 */
USTRUCT(BlueprintType)
struct FLootLockerAdminResponse
{
	GENERATED_BODY()
    
	// True if the request succeeded
    UPROPERTY(BlueprintReadWrite, Category = "LootLockerAdmin")
    bool Success = false;
    // HTTP Status code from the request to LootLockers backend 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    int StatusCode = 0;
    // Raw text/http body from the server response
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FString FullTextFromServer;
    // If this request was not a success, this structure holds all the information needed to identify the problem
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FLootLockerAdminErrorData ErrorData;
};

//==================================================
// Blueprint Delegate Definitions
//==================================================

/*
 Blueprint response delegate for a generic LootLocker Response
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminResponseCallbackBP, FLootLockerAdminResponse, Response);

//==================================================
// C++ Delegate Definitions
//==================================================

/*
 C++ response delegate for a generic LootLocker Response
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminResponseCallback, FLootLockerAdminResponse);


/**
 * Static defines of the different predefined error status codes that can occur in responses
 */
struct LootLockerAdminStaticRequestErrorStatusCodes
{
    static const int LL_ERROR_UNDOCUMENTED = 0;
    static const int LL_ERROR_INVALID_HTTP = -1;
    static const int LL_ERROR_INVALID_INPUT = -2;
    static const int LL_ERROR_PARSE_ERROR = -3;
};

class LootLockerAdminResponseFactory
{
public:
    // Construct a standardized error response
    template<typename T>
    static T Error(FString ErrorMessage, int StatusCode = 0)
    {
        T ErrorResponse;
        ErrorResponse.Success = false;
        ErrorResponse.StatusCode = StatusCode;
        ErrorResponse.FullTextFromServer = "{ \"message\": \"" + ErrorMessage + "\"}";
        ErrorResponse.ErrorData.Message = ErrorMessage;
        return ErrorResponse;
    }
};
