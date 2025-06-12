
#pragma once

#include "Containers/Array.h"
#include "CoreMinimal.h"
#include "JsonObjectConverter.h"
#include "../LootLockerAdminResponse.h"

#include "LootLockerAdminMetadataRequest.generated.h"

//==================================================
// Enum Definitions
//==================================================

/*
 Possible metadata sources
 */
UENUM(BlueprintType, Category = "LootLockerAdmin")
enum class ELootLockerAdminMetadataSources : uint8
{
	reward = 0,
	leaderboard = 1,
	catalog_item = 2,
	progression = 3,
	currency = 4,
	player = 5,
	asset = 6,
};

/*
 Possible metadata types
 */
UENUM(BlueprintType, Category = "LootLockerAdmin")
enum class ELootLockerAdminMetadataTypes : uint8
{
	String = 0,
	Number = 1,
	Bool = 2,
	Json = 3,
	Base64 = 4,
};

/*
 Possible metadata actions
 */
UENUM(BlueprintType, Category = "LootLockerAdmin")
enum class ELootLockerAdminMetadataActions : uint8
{
	Create = 0,
	Update = 1,
	Delete = 2
};

//==================================================
// Data Type Definitions
//==================================================

/*
 *
 */
USTRUCT(BlueprintType, Category = "LootLockerAdmin")
struct FLootLockerAdminMetadataBase64Value
{
	GENERATED_BODY()
	/*
	 The type of content that the base64 string encodes. Could be for example "image/jpeg" if it is a base64 encoded jpeg, or "application/x-redacted" if loading of files has been disabled
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Content_type;
	/*
	 The encoded content in the form of a Base64 String. If this is unexpectedly empty, check if Content_type is set to "application/x-redacted". If it is, then the request for metadata was made with the ignoreFiles parameter set to true
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Content;
};

/**
 *
 */
USTRUCT(BlueprintType, Category = "LootLockerAdmin")
struct FLootLockerAdminMetadataOperationsErrorEntry
{
	GENERATED_BODY()
	/*
	 The metadata key that the set operation error refers to
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Key;
	/*
	 The type of value that the set operation was for
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	ELootLockerAdminMetadataTypes Type = ELootLockerAdminMetadataTypes::String;
};


/**
 *
 */
USTRUCT(BlueprintType, Category = "LootLockerAdmin")
struct FLootLockerAdminMetadataEntry
{
    GENERATED_BODY()
    /*
     The metadata key
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FString Key;
    /*
     The type of value this metadata contains. Use this to parse the value.
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    ELootLockerAdminMetadataTypes Type = ELootLockerAdminMetadataTypes::String;
    /*
     List of tags applied to this metadata
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    TArray<FString> Tags;
    /*
     The access level set for this metadata entry. Valid values are game_api.read and game_api.write, though no values are required.
     Note that different sources can allow or disallow a subset of these values.
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    TArray<FString> Access;

	/*
	 Get the value as an unparsed json value. Returns true if value could be found in which case Output contains the JsonValue, returns false if the value field was not present.
	 */
	LOOTLOCKERADMINSDK_API bool TryGetRawValue(TSharedPtr<FJsonValue>& Output) const;
	
    /*
     Set the value as a String.
     */
    LOOTLOCKERADMINSDK_API void SetValueAsString(const FString& Value);
    /*
     Set the value as a float.
     */
    LOOTLOCKERADMINSDK_API void SetValueAsFloat(const float& Value);
    /*
     Set the value as an integer.
     */
    LOOTLOCKERADMINSDK_API void SetValueAsInteger(const int& Value);
    /*
     Set the value as a bool.
     */
    LOOTLOCKERADMINSDK_API void SetValueAsBool(const bool& Value);
    /*
     Set the value as a JsonValue.
     */
    LOOTLOCKERADMINSDK_API void SetRawValue(const TSharedPtr<FJsonValue>& Value);
    /*
     Set the value as the provided UStruct object. Returns true if value could be serialized.
     */
    template<typename T>
    LOOTLOCKERADMINSDK_API bool SetValueAsUStruct(const T& Value)
	{
		TSharedPtr<FJsonObject> JsonObject = FJsonObjectConverter::UStructToJsonObject(Value);
		if(!JsonObject.IsValid())
		{
			return false;
		}
		SetValueAsJsonObject(*JsonObject);
		return true;
	}


	/*
     Set the value as a Json Object.
     */
    LOOTLOCKERADMINSDK_API void SetValueAsJsonObject(const FJsonObject& Value);
    /*
     Set the value as a Json Array.
     */
    LOOTLOCKERADMINSDK_API void SetValueAsJsonArray(const TArray<TSharedPtr<FJsonValue>>& Value);
    /*
     Set the value as a Base64 object.
     */
    LOOTLOCKERADMINSDK_API void SetValueAsBase64(const FLootLockerAdminMetadataBase64Value& Value);

    /*
     Factory method that makes an FLootLockerAdminMetadataEntry with a String Value
     */
	static LOOTLOCKERADMINSDK_API FLootLockerAdminMetadataEntry MakeStringEntry(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const FString& Value);
    /*
     Factory method that makes an FLootLockerAdminMetadataEntry with a Float Value
     */
    static LOOTLOCKERADMINSDK_API FLootLockerAdminMetadataEntry MakeFloatEntry(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const float& Value);
    /*
     Factory method that makes an FLootLockerAdminMetadataEntry with an Integer Value
     */
    static LOOTLOCKERADMINSDK_API FLootLockerAdminMetadataEntry MakeIntegerEntry(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const int Value);
    /*
     Factory method that makes an FLootLockerAdminMetadataEntry with a Bool Value
     */
    static LOOTLOCKERADMINSDK_API FLootLockerAdminMetadataEntry MakeBoolEntry(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const bool Value);
    /*
     Factory method that makes an FLootLockerAdminMetadataEntry with a JsonValue Value
     */
    static LOOTLOCKERADMINSDK_API FLootLockerAdminMetadataEntry MakeJsonValueEntry(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const ELootLockerAdminMetadataTypes Type, const TSharedPtr<FJsonValue> Value);
    /*
     Factory method that makes an FLootLockerAdminMetadataEntry with a JsonObject Value
     */
    static LOOTLOCKERADMINSDK_API FLootLockerAdminMetadataEntry MakeJsonObjectEntry(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const FJsonObject& Value);
    /*
     Factory method that makes an FLootLockerAdminMetadataEntry with a JsonArray Value
     */
    static LOOTLOCKERADMINSDK_API FLootLockerAdminMetadataEntry MakeJsonArrayEntry(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const TArray<TSharedPtr<FJsonValue>>& Value);
    /*
     Factory method that makes an FLootLockerAdminMetadataEntry with a Base64 Value
     */
    static LOOTLOCKERADMINSDK_API FLootLockerAdminMetadataEntry MakeBase64Entry(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const FLootLockerAdminMetadataBase64Value& Value);

    /*
     For internal use only
     */
    void LOOTLOCKERADMINSDK_API _INTERNAL_SetJsonRepresentation(const FJsonObject& obj);
    static LOOTLOCKERADMINSDK_API FLootLockerAdminMetadataEntry _INTERNAL_MakeEntryExceptValue(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const ELootLockerAdminMetadataTypes Type);
private:

    FJsonObject EntryAsJson;
};


/**
 *
 */
USTRUCT(BlueprintType, Category = "LootLockerAdmin")
struct FLootLockerAdminMetadataOperationsError
{
	GENERATED_BODY()
	/*
	 The type of action that this set metadata operation was
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	ELootLockerAdminMetadataActions Action = ELootLockerAdminMetadataActions::Create;
	/*
	 The type of value that the set operation was for
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FLootLockerAdminMetadataOperationsErrorEntry Entry;
	/*
	 The error message describing why this metadata set operation failed
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Error;
};

//==================================================
// Request Definitions
//==================================================

/*
 *
 */
USTRUCT(BlueprintType, Category = "LootLockerAdmin")
struct FLootLockerAdminMetadataOperationsAction
{
	GENERATED_BODY()
	/*
	 The type of action to take for setting this metadata entry
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	ELootLockerAdminMetadataActions Action = ELootLockerAdminMetadataActions::Create;
	/*
	 The metadata entry to take the designated action for
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FLootLockerAdminMetadataEntry Entry;
};

//==================================================
// Response Definitions
//==================================================

/*
 */
USTRUCT(BlueprintType, Category = "LootLockerAdmin")
struct FLootLockerAdminMetadataOperationsResponse : public FLootLockerAdminResponse
{
	GENERATED_BODY()
	/*
	 A list of any errors that occurred when executing the provided metadata actions
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	TArray<FLootLockerAdminMetadataOperationsError> Errors;
	/*
	 The type of source that the source id refers to
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	ELootLockerAdminMetadataSources Source = ELootLockerAdminMetadataSources::reward;
	/*
	 The id of the specific source that the set operation was taken on
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
	FString Source_id;
};

//==================================================
// Blueprint Delegate Definitions
//==================================================

/*
 Blueprint response delegate for creating a currency
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminMetadataOperationsResponseBP, FLootLockerAdminMetadataOperationsResponse, Response);

//==================================================
// C++ Delegate Definitions
//==================================================

/*
 C++ response delegate for creating a currency
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminMetadataOperationsResponseDelegate, FLootLockerAdminMetadataOperationsResponse);

/**
 *
 */
UCLASS()
class LOOTLOCKERADMINSDK_API ULootLockerAdminMetadataRequest : public UObject
{
    GENERATED_BODY()
    public:
    ULootLockerAdminMetadataRequest();

    static void MetadataOperations(const ELootLockerAdminMetadataSources Source, const FString& SourceId, const TArray<FLootLockerAdminMetadataOperationsAction>& Actions, const FLootLockerAdminMetadataOperationsResponseBP& OnCompletedRequestBP = FLootLockerAdminMetadataOperationsResponseBP(), const FLootLockerAdminMetadataOperationsResponseDelegate& OnCompletedRequest = FLootLockerAdminMetadataOperationsResponseDelegate());
};
