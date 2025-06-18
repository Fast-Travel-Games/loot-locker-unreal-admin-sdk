
#pragma once

#include "CoreMinimal.h"
#include "AdminAPI/LootLockerAdminAssetRequest.h"
#include "AdminAPI/LootLockerAdminCatalogRequest.h"
#include "AdminAPI/LootLockerAdminCurrencyRequest.h"
#include "AdminAPI/LootLockerAdminMetadataRequest.h"
#include "AdminAPI/LootLockerAdminRewardRequest.h"
#include "AdminAPI/LootLockerAdminSessionRequest.h"

class LOOTLOCKERADMINSDK_API ULootLockerAdmin : public UObject
{
public:
    
    //==================================================
    // Authentication
    //==================================================
    
    /**
     * Start a session by logging in with your LootLocker Email and Password. Need to be a registered user before.
     * https://ref.lootlocker.com/admin/api-5291166
     *
     * @param Email
     * @param Password
     * @param OnCompletedRequest Delegate for handling the response
     */
    static void StartSession(const FString& Email, const FString& Password, const FLootLockerAdminCreateSessionResponseDelegate& OnCompleteRequest);

	//==================================================
    // Assets
    //==================================================

	/**
	 *
	 *
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void GetAssetContexts(const FLootLockerAdminGetAssetContextsResponseDelegate& OnCompletedRequest);
	
    /**
     * 
     * 
     *
     * @param Context
     * @param Name
     * @param bUniqueInstance
     * @param OnCompletedRequest Delegate for handling the server response
     */
    static void CreateAsset(const int Context, const FString& Name, const bool bUniqueInstance, const FLootLockerAdminCreateAssetResponseDelegate& OnCompletedRequest);

	/**
	 *
	 *
	 * @param AssetId
	 * @param bActive
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void ActivateAsset(const int AssetId, const bool bActive, const FLootLockerAdminActivateAssetResponseDelegate& OnCompletedRequest);

	/**
	*
	*
	* @param bIncludeInactive
	* @param OnCompletedRequest Delegate for handling the server response
	*/
	static void GetAssets(const bool bIncludeInactive, const FLootLockerAdminGetAssetsResponseDelegate& OnCompletedRequest);

	//==================================================
	// Catalog
	//==================================================

	/**
	 * 
	 * 
	 *
	 * @param CatalogItemId
	 * @param CurrencyId
	 * @param Amount
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void AddPrice(const FString& CatalogItemId, const FString& CurrencyId, int Amount, const FLootLockerAdminAddPriceResponseDelegate& OnCompletedRequest);
	
	/**
	 * 
	 * 
	 *
	 * @param CatalogId
	 * @param EntityId
	 * @param EntityKind
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void CreateCatalogListing(const FString& CatalogId, const FString& EntityId, const ELootLockerAdminCatalogEntityKind& EntityKind, const FLootLockerAdminCreateCatalogListingResponseDelegate& OnCompletedRequest);

	/**
	 * 
	 * 
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void ListCatalogs(const FLootLockerAdminListCatalogsResponseDelegate& OnCompletedRequest);

	/**
	 * 
	 * 
	 *
	 * @param CatalogItemId
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void TogglePurchasableStatus(const FString& CatalogItemId, const FLootLockerAdminTogglePurchasableStatusResponseDelegate& OnCompletedRequest);

	//==================================================
	// Currency
	//==================================================

	/**
	 * 
	 * 
	 *
	 * @param Name
	 * @param Code
	 * @param DenominationName
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void CreateCurrency(const FString& Name, const FString& Code, const FString& DenominationName, const FLootLockerAdminCreateCurrencyResponseDelegate& OnCompletedRequest);

	/**
	 * Get a list of available currencies for the game
	 *
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void ListCurrencies(const FLootLockerAdminListCurrenciesResponseDelegate& OnCompletedRequest);

	//==================================================
	// Metadata
	//==================================================

	/**
	 * 
	 * 
	 *
	 * @param Source
	 * @param SourceId
	 * @param Actions
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void MetadataOperations(const ELootLockerAdminMetadataSources Source, const FString& SourceId, const TArray<FLootLockerAdminMetadataOperationsAction>& Actions, const FLootLockerAdminMetadataOperationsResponseDelegate& OnCompletedRequest);

	/**
	 * Factory method that makes an FLootLockerAdminMetadataEntry with a UStruct Value
	 * 
	 * @param Key The key you want for this entry
	 * @param Tags The tags you want for this entry
	 * @param Access The access level you want to set for this entry
	 * @param Value The UStruct object that you to be converted to json and set as the value for this metadata entry
	 * @return The filled out metadata entry (or empty if it could not be constructed).
	 */
	template<typename T>
	static FLootLockerAdminMetadataEntry MakeMetadataEntryWithUStructValue(const FString& Key, const TArray<FString>& Tags, const TArray<FString>& Access, const T& Value)
	{
		TSharedPtr<FJsonObject> JsonObject = FJsonObjectConverter::UStructToJsonObject(Value);
		if (!JsonObject.IsValid())
		{
			return FLootLockerAdminMetadataEntry();
		}
		FLootLockerAdminMetadataEntry Entry = FLootLockerAdminMetadataEntry::_INTERNAL_MakeEntryExceptValue(Key, Tags, Access, ELootLockerAdminMetadataTypes::Json);
		Entry.SetValueAsJsonObject(*JsonObject);
		return Entry;
	}
	
	//==================================================
	// Reward
	//==================================================

	/**
	 * 
	 * 
	 *
	 * @param Entities
	 * @param Name
	 * @param Description
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void CreateGroup(const TArray<FLootLockerAdminEntity>& Entities, const FString& Name, const FString& Description, const FLootLockerAdminCreateGroupResponseDelegate& OnCompletedRequest);

};
