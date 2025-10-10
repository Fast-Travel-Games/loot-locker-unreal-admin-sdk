
#pragma once

#include "CoreMinimal.h"
#include "AdminAPI/LootLockerAdminAssetRequest.h"
#include "AdminAPI/LootLockerAdminCatalogRequest.h"
#include "AdminAPI/LootLockerAdminCurrencyRequest.h"
#include "AdminAPI/LootLockerAdminMetadataRequest.h"
#include "AdminAPI/LootLockerAdminPlayerRequest.h"
#include "AdminAPI/LootLockerAdminRewardRequest.h"
#include "AdminAPI/LootLockerAdminSessionRequest.h"

#include "LootLockerAdminBP.generated.h"

UCLASS(Blueprintable)
class LOOTLOCKERADMINSDK_API ULootLockerAdminBP : public UObject
{
    GENERATED_BODY()
 
public:
    //==================================================
    // Authentication https://ref.lootlocker.com/admin/folder-815099
    //==================================================

    /**
     * Start a session by logging in with your LootLocker Email and Password. Need to be a registered user before.
     * https://ref.lootlocker.com/admin/api-5291166
     *
     * @param Email Account Email
     * @param Password Account Password
     * @param OnCompletedRequest Delegate for handling the response
     */
    UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Authentication")
    static void CreateSession(const FString& Email, const FString& Password, const FLootLockerAdminCreateSessionResponseBP& OnCompletedRequest);

    //==================================================
    // Assets
    //==================================================

	/**
	 * Get a list of all Asset Contexts
	 * https://ref.lootlocker.com/admin/api-5291209
	 *
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Assets")
	static void GetAssetContexts(const FLootLockerAdminGetAssetContextsResponseBP& OnCompletedRequest);
	
    /**
     * Creating an Asset
     * https://ref.lootlocker.com/admin/api-5291219
     *
     * @param Context In which Context
     * @param Name Name of the Asset
     * @param bUniqueInstance What the Asset should set Unique Instance to
     * @param OnCompletedRequest Delegate for handling the server response
     */
    UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Assets")
    static void CreateAsset(const int Context, const FString& Name, const bool bUniqueInstance, const FLootLockerAdminCreateAssetResponseBP& OnCompletedRequest);
	
	/**
	 * Set or unset the Asset as Active
	 *
	 * @param AssetId Asset to change
	 * @param bActive Active value
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Assets")
	static void ActivateAsset(const int AssetId, const bool bActive, const FLootLockerAdminActivateAssetResponseBP& OnCompletedRequest);

	/**
	 * Get a list of all assets
	 * https://ref.lootlocker.com/admin/api-5291223
	 *
	 * @param bIncludeInactive If inactive assets should be included
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Assets")
	static void GetAssets(const bool bIncludeInactive, const FLootLockerAdminGetAssetsResponseBP& OnCompletedRequest);

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
	UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Catalog")
	static void AddPrice(const FString& CatalogItemId, const FString& CurrencyId, int Amount, const FLootLockerAdminAddPriceResponseBP& OnCompletedRequest);
	
	/**
	 * Delete a price from a catalog item
	 * https://ref.lootlocker.com/admin/api-5291361
	 *
	 * @param CatalogId What Catalog
	 * @param CatalogItemId What Catalog Item
	 * @param CurrencyId Which Price to delete
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Catalog")
	static void DeletePrice(const FString& CatalogId, const FString& CatalogItemId, const FString& CurrencyId, const FLootLockerAdminDeletePriceResponseBP& OnCompletedRequest);

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
	UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Catalog")
	static void CreateCatalogListing(const FString& CatalogId, const FString& EntityId, const ELootLockerAdminCatalogEntityKind& EntityKind, const FLootLockerAdminCreateCatalogListingResponseBP& OnCompletedRequest);

	/**
	 * Delete a catalog listing
	 * https://ref.lootlocker.com/admin/api-5291358
	 *
	 * @param CatalogItemId What Catalog item to delete
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Catalog")
	static void DeleteCatalogListing(const FString& CatalogItemId, const FLootLockerAdminDeleteCatalogListingResponseBP& OnCompletedRequest);

	/**
	 * List the catalogs of the game
	 *
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Catalog")
	static void ListCatalogs(const FLootLockerAdminListCatalogsResponseBP& OnCompletedRequest);

	/**
	 * List the catalog items in a catalog. Support pagination with the After parameter
	 * https://ref.lootlocker.com/admin/api-5291356
	 *
	 * @param CatalogId What Catalog to list
	 * @param Count Max number of items to return, maximum 50
	 * @param After Use the value of next_cursor in a response to get the next page
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Catalog")
	static void ListCatalogItems(const FString& CatalogId, const int Count, const FString& After, const FLootLockerAdminListCatalogItemsResponseBP& OnCompletedRequest);

	/**
	 * Toggle the item to be either purchasable or not
	 * https://ref.lootlocker.com/admin/api-5291359
	 *
	 * @param CatalogItemId What Catalog Item to toggle
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Catalog")
	static void TogglePurchasableStatus(const FString& CatalogItemId, const FLootLockerAdminTogglePurchasableStatusResponseBP& OnCompletedRequest);

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
	UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Currency")
	static void CreateCurrency(const FString& Name, const FString& Code, const FString& DenominationName, const FLootLockerAdminCreateCurrencyResponseBP& OnCompletedRequest);

	/**
	 * Get a list of available currencies for the game
	 * https://ref.lootlocker.com/admin/api-5291380
	 *
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Currency")
	static void ListCurrencies(const FLootLockerAdminListCurrenciesResponseBP& OnCompletedRequest);

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
	 * @param SourceID The specific source id for which to set metadata
	 * @param MetadataToActionsToPerform List of actions to take during this set operation.
	 * @param OnComplete delegate for handling the server response
	 */
    UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Metadata")
    static void MetadataOperations(const ELootLockerAdminMetadataSources Source, const FString& SourceID, const TArray<FLootLockerAdminMetadataOperationsAction>& MetadataToActionsToPerform, const FLootLockerAdminMetadataOperationsResponseBP& OnComplete);

    /**
	 * Construct a Metadata Action consisting of a metadata entry with a String value
	 *
	 * @param Action The action to take for this set operation. Update and Delete operations will fail if the key does not exist. Create operation will fail if the key does exist.
	 * @param Key The key to perform this action towards
	 * @param Value The value to set for the specified key
	 * @param Tags The tags to apply to the specified key
	 * @param Access The access settings to apply to the specified key. None means that the game api can not read nor write this metadata entry (this is the default). But you can supply either or both of "game_api.read", "game_api.write" and "player.read"
	 * @return A Metadata Action Object that you can use in the method SetMetadata
     */
    UFUNCTION(BlueprintPure, Category = "LootLockerAdmin Methods | Metadata", meta = (AdvancedDisplay = "Tags,Access", AutoCreateRefTerm="Tags,Access"))
    static FLootLockerAdminMetadataOperationsAction MakeMetadataActionString(ELootLockerAdminMetadataActions Action, const FString& Key, const FString& Value, const TArray<FString>& Tags, const TArray<FString>& Access);

    /**
	 * Construct a Metadata Action consisting of a metadata entry with a Decimal value
	 *
	 * @param Action The action to take for this set operation. Update and Delete operations will fail if the key does not exist. Create operation will fail if the key does exist.
	 * @param Key The key to perform this action towards
	 * @param Value The value to set for the specified key
	 * @param Tags The tags to apply to the specified key
	 * @param Access The access settings to apply to the specified key. None means that the game api can not read nor write this metadata entry (this is the default). But you can supply either or both of "game_api.read", "game_api.write" and "player.read"
	 * @return A Metadata Action Object that you can use in the method SetMetadata
     */
    UFUNCTION(BlueprintPure, Category = "LootLockerAdmin Methods | Metadata", meta = (AdvancedDisplay = "Tags,Access", AutoCreateRefTerm = "Tags,Access"))
    static FLootLockerAdminMetadataOperationsAction MakeMetadataActionFloat(ELootLockerAdminMetadataActions Action, const FString& Key, const float& Value, const TArray<FString>& Tags, const TArray<FString>& Access);

    /**
	 * Construct a Metadata Action consisting of a metadata entry with an Integer value
	 *
	 * @param Action The action to take for this set operation. Update and Delete operations will fail if the key does not exist. Create operation will fail if the key does exist.
	 * @param Key The key to perform this action towards
	 * @param Value The value to set for the specified key
	 * @param Tags The tags to apply to the specified key
	 * @param Access The access settings to apply to the specified key. None means that the game api can not read nor write this metadata entry (this is the default). But you can supply either or both of "game_api.read", "game_api.write" and "player.read"
	 * @return A Metadata Action Object that you can use in the method SetMetadata
     */
    UFUNCTION(BlueprintPure, Category = "LootLockerAdmin Methods | Metadata", meta = (AdvancedDisplay = "Tags,Access", AutoCreateRefTerm = "Tags,Access"))
    static FLootLockerAdminMetadataOperationsAction MakeMetadataActionInteger(ELootLockerAdminMetadataActions Action, const FString& Key, const int Value, const TArray<FString>& Tags, const TArray<FString>& Access);

    /**
	 * Construct a Metadata Action consisting of a metadata entry with a Bool value
	 *
	 * @param Action The action to take for this set operation. Update and Delete operations will fail if the key does not exist. Create operation will fail if the key does exist.
	 * @param Key The key to perform this action towards
	 * @param Value The value to set for the specified key
	 * @param Tags The tags to apply to the specified key
	 * @param Access The access settings to apply to the specified key. None means that the game api can not read nor write this metadata entry (this is the default). But you can supply either or both of "game_api.read", "game_api.write" and "player.read"
	 * @return A Metadata Action Object that you can use in the method SetMetadata
     */
    UFUNCTION(BlueprintPure, Category = "LootLockerAdmin Methods | Metadata", meta = (AdvancedDisplay = "Tags,Access", AutoCreateRefTerm = "Tags,Access"))
    static FLootLockerAdminMetadataOperationsAction MakeMetadataActionBool(ELootLockerAdminMetadataActions Action, const FString& Key, const bool Value, const TArray<FString>& Tags, const TArray<FString>& Access);

    /**
	 * Construct a Metadata Action consisting of a metadata entry with a Json value in string format
	 *
	 * @param Action The action to take for this set operation. Update and Delete operations will fail if the key does not exist. Create operation will fail if the key does exist.
	 * @param Key The key to perform this action towards
	 * @param Value The value to set for the specified key
	 * @param Tags The tags to apply to the specified key
	 * @param Access The access settings to apply to the specified key. None means that the game api can not read nor write this metadata entry (this is the default). But you can supply either or both of "game_api.read", "game_api.write" and "player.read"
	 * @param Succeeded Output: True if the json string could be parsed as an array or object, false if it could not be parsed
	 * @param ConstructedEntry Output: A Metadata Action Object that you can use in the method SetMetadata
     */
    UFUNCTION(BlueprintPure, Category = "LootLockerAdmin Methods | Metadata", meta = (AdvancedDisplay = "Tags,Access", AutoCreateRefTerm = "Tags,Access"))
    static void MakeMetadataActionJson(ELootLockerAdminMetadataActions Action, const FString& Key, const FString& Value, const TArray<FString>& Tags, const TArray<FString>& Access, bool& Succeeded, FLootLockerAdminMetadataOperationsAction& ConstructedEntry);

    /**
	 * Construct a Metadata Action consisting of a metadata entry with a Base64 value
	 *
	 * @param Action The action to take for this set operation. Update and Delete operations will fail if the key does not exist. Create operation will fail if the key does exist.
	 * @param Key The key to perform this action towards
	 * @param Value The value to set for the specified key
	 * @param Tags The tags to apply to the specified key
	 * @param Access The access settings to apply to the specified key. None means that the game api can not read nor write this metadata entry (this is the default). But you can supply either or both of "game_api.read", "game_api.write" and "player.read"
	 * @return A Metadata Action Object that you can use in the method SetMetadata
     */
    UFUNCTION(BlueprintPure, Category = "LootLockerAdmin Methods | Metadata", meta = (AdvancedDisplay = "Tags,Access", AutoCreateRefTerm = "Tags,Access"))
    static FLootLockerAdminMetadataOperationsAction MakeMetadataActionBase64(ELootLockerAdminMetadataActions Action, const FString& Key, const FLootLockerAdminMetadataBase64Value& Value, const TArray<FString>& Tags, const TArray<FString>& Access);


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
	UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Players")
	static void GrantAsset(const FString& PlayerId, const int AssetId, const FLootLockerAdminGrantAssetResponseBP& OnCompletedRequest);

	/**
	 * List players for the game
	 * https://ref.lootlocker.com/admin/api-5291241
	 *
	 * @param Count How many players to return
	 * @param Page From which page (start at 1)
	 * @param OnCompletedRequest Delegate for handling the server response
	 */
	UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Players")
	static void ListPlayers(const int Count, const int Page, const FLootLockerAdminListPlayersResponseBP& OnCompletedRequest);

	
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
	UFUNCTION(BlueprintCallable, Category = "LootLockerAdmin Methods | Reward")
	static void CreateGroup(const TArray<FLootLockerAdminEntity>& Entities, const FString& Name, const FString& Description, const FLootLockerAdminCreateGroupResponseBP& OnCompletedRequest);
};
