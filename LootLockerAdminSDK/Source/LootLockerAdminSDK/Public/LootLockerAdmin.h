
#pragma once

#include "CoreMinimal.h"
#include "AdminAPI/LootLockerAdminAssetRequest.h"
#include "AdminAPI/LootLockerAdminCatalogRequest.h"
#include "AdminAPI/LootLockerAdminCurrencyRequest.h"
#include "AdminAPI/LootLockerAdminMetadataRequest.h"
#include "AdminAPI/LootLockerAdminPlayerRequest.h"
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
	 * @param Email Account Email
	 * @param Password Account Password
	 * @param OnCompleteRequest Delegate for handling the response
	 */
    static void StartSession(const FString& Email, const FString& Password, const FLootLockerAdminCreateSessionResponseDelegate& OnCompleteRequest);

	//==================================================
    // Assets
    //==================================================

	/**
	 * Get a list of all Asset Contexts
	 * https://ref.lootlocker.com/admin/api-5291209
	 *
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void GetAssetContexts(const FLootLockerAdminGetAssetContextsResponseDelegate& OnCompletedRequest);
	
    /**
	 * Creating an Asset
	 * https://ref.lootlocker.com/admin/api-5291219
	 *
	 * @param Context In which Context
	 * @param Name Name of the Asset
	 * @param bUniqueInstance What the Asset should set Unique Instance to
	 * @param OnCompletedRequest Delegate for handling the server response
     */
    static void CreateAsset(const int Context, const FString& Name, const bool bUniqueInstance, const FLootLockerAdminCreateAssetResponseDelegate& OnCompletedRequest);

	/**
	 * Set or unset the Asset as Active
	 *
	 * @param AssetId Asset to change
	 * @param bActive Active value
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void ActivateAsset(const int AssetId, const bool bActive, const FLootLockerAdminActivateAssetResponseDelegate& OnCompletedRequest);

	/**
	 * Get a list of all assets
	 * https://ref.lootlocker.com/admin/api-5291223
	 *
	 * @param bIncludeInactive If inactive assets should be included
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void GetAssets(const bool bIncludeInactive, const FLootLockerAdminGetAssetsResponseDelegate& OnCompletedRequest);

	//==================================================
	// Catalog
	//==================================================

	/**
	 * Add a price to a catalog item
	 *
	 * @param CatalogItemId For which Item
	 * @param CurrencyId What Currency the price is
	 * @param Amount The amount for the price
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void AddPrice(const FString& CatalogItemId, const FString& CurrencyId, int Amount, const FLootLockerAdminAddPriceResponseDelegate& OnCompletedRequest);

	/**
	 * Delete a price from a catalog item
	 * https://ref.lootlocker.com/admin/api-5291361
	 *
	 * @param CatalogId What Catalog
	 * @param CatalogItemId What Catalog Item
	 * @param CurrencyId Which Price to delete
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void DeletePrice(const FString& CatalogId, const FString& CatalogItemId, const FString& CurrencyId, const FLootLockerAdminDeletePriceResponseDelegate& OnCompletedRequest);

	/**
	 * Creates a catalog listing for an object
	 * https://ref.lootlocker.com/admin/api-5291365
	 * https://ref.lootlocker.com/admin/api-5291367
	 * https://ref.lootlocker.com/admin/api-5291368
	 * https://ref.lootlocker.com/admin/api-5291369
	 * https://ref.lootlocker.com/admin/api-7628357
	 *
	 * @param CatalogId What Catalog the listing should be in
	 * @param EntityId What Object the listing is for
	 * @param EntityKind What kind the Object is
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void CreateCatalogListing(const FString& CatalogId, const FString& EntityId, const ELootLockerAdminCatalogEntityKind& EntityKind, const FLootLockerAdminCreateCatalogListingResponseDelegate& OnCompletedRequest);

	/**
	 * Delete a catalog listing
	 * https://ref.lootlocker.com/admin/api-5291358
	 *
	 * @param CatalogItemId What Catalog item to delete
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void DeleteCatalogListing(const FString& CatalogItemId, const FLootLockerAdminDeleteCatalogListingResponseDelegate& OnCompletedRequest);

	/**
	 * List the catalogs of the game
	 *
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void ListCatalogs(const FLootLockerAdminListCatalogsResponseDelegate& OnCompletedRequest);

	/**
	 * List the catalog items in a catalog. Support pagination with the After parameter
	 * https://ref.lootlocker.com/admin/api-5291356
	 *
	 * @param CatalogId What Catalog to list
	 * @param Count Max number of items to return, maximum 50
	 * @param After Use the value of next_cursor in a response to get the next page
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void ListCatalogItems(const FString& CatalogId, const int Count, const FString& After, const FLootLockerAdminListCatalogItemsResponseDelegate& OnCompletedRequest);

	/**
	 * Toggle the item to be either purchasable or not
	 * https://ref.lootlocker.com/admin/api-5291359
	 *
	 * @param CatalogItemId What Catalog Item to toggle
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void TogglePurchasableStatus(const FString& CatalogItemId, const FLootLockerAdminTogglePurchasableStatusResponseDelegate& OnCompletedRequest);

	//==================================================
	// Currency
	//==================================================

	/**
	 * Create a new currency
	 * https://ref.lootlocker.com/admin/api-5291370
	 *
	 * @param Name Name of the Currency
	 * @param Code Three letter short code, must be unique for the game
	 * @param DenominationName Name of Denominations
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void CreateCurrency(const FString& Name, const FString& Code, const FString& DenominationName, const FLootLockerAdminCreateCurrencyResponseDelegate& OnCompletedRequest);

	/**
	 * Get a list of available currencies for the game
	 * https://ref.lootlocker.com/admin/api-5291380
	 *
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void ListCurrencies(const FLootLockerAdminListCurrenciesResponseDelegate& OnCompletedRequest);

	//==================================================
	// Metadata
	//==================================================

	/**
	 * Set the provided metadata for the specified source
	 *
	 * Use the provided Make<type>MetadataAction when constructing the array of actions to perform.
	 * Note that a subset of the specified operations can fail without the full request failing. Make sure to check the errors array in the response.
	 *
	 * @param Source The source type for which to set metadata
	 * @param SourceId The specific source id for which to set metadata
	 * @param Actions List of actions to take during this set operation.
	 * @param OnCompletedRequest delegate for handling the server response
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
	// Players
	//==================================================

	/**
	 * Grant an asset to a player
	 * https://ref.lootlocker.com/admin/items/grant-asset-to-player
	 *
	 * @param PlayerId What player
	 * @param AssetId Which asset, will give one instance of it
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void GrantAsset(const FString& PlayerId, const int AssetId, const FLootLockerAdminGrantAssetResponseDelegate& OnCompletedRequest);

	/**
	 * List players for the game
	 * https://ref.lootlocker.com/admin/api-5291241
	 *
	 * @param Count How many players to return
	 * @param Page From which page (start at 1)
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void ListPlayers(const int Count, const int Page, const FLootLockerAdminListPlayersResponseDelegate& OnCompletedRequest);

	//==================================================
	// Reward
	//==================================================

	/**
	 * Create a group
	 * https://ref.lootlocker.com/admin/api-7331977
	 *
	 * @param Entities List of Entities that the group consist of
	 * @param Name Name of the Group
	 * @param Description Description of the group
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	static void CreateGroup(const TArray<FLootLockerAdminEntity>& Entities, const FString& Name, const FString& Description, const FLootLockerAdminCreateGroupResponseDelegate& OnCompletedRequest);
};
