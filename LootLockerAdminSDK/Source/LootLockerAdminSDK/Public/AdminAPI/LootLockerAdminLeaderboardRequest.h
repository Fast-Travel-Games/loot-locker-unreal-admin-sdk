
#pragma once

#include "Containers/Array.h"
#include "CoreMinimal.h"
#include "../LootLockerAdminResponse.h"

#include "LootLockerAdminLeaderboardRequest.generated.h"

//==================================================
// Enum Definitions
//==================================================
UENUM(BlueprintType)
enum class ELootLockerAdminLeaderboardType : uint8
{
    /**
     * Meant for LootLocker player leaderboards.
     * When submitting scores you must use player_id, but when retrieving data LootLocker will automatically attach player data such as name and other public data on that player.
     */
    player = 0         UMETA(DisplayName = "Player"),
    /**
     * Use this if you do not want the extended player details from the player type leaderboard.
     * This type allows you to create leaderboards not meant for players (guild/clan for example), or if your player data is not stored in LootLocker.
     */
    generic = 1        UMETA(DisplayName = "Generic"),
};

/**
 * Which direction should the leaderboard be sorted in
 */
UENUM(BlueprintType)
enum class ELootLockerAdminLeaderboardDirection : uint8
{
    /**
     * Sort from lowest to highest, meaning the lowest number is highest on the leaderboard
     */
    ascending = 0         UMETA(DisplayName = "Ascending"),
    /**
     * Sort from highest to lowest, meaning the highest number is highest on the leaderboard
     */
    descending = 1        UMETA(DisplayName = "Descending"),
};

/**
* What reward kind
*/
UENUM(BlueprintType)
enum class ELootLockerAdminLeaderboardRewardKind : uint8
{
    asset = 0 UMETA(DisplayName = "Asset"),
    currency = 1 UMETA(DisplayName = "Currency"),
    progression_points = 2 UMETA(DisplayName = "Progression points"),
    progression_reset = 3 UMETA(DisplayName = "Progression reset"),
	group = 4 UMETA(DisplayName = "Group"),
};

/**
 * Which direction should the reward for a leaderboard be for
 */
UENUM(BlueprintType)
enum class ELootLockerAdminLeaderboardRewardDirection : uint8
{
    /**
     * Bottom direction
     */
    asc = 0         UMETA(DisplayName = "Bottom"),
    /**
     * Top direction
     */
    desc = 1        UMETA(DisplayName = "Top"),
};


/**
 * Set if values are used for rank or percentage of players
 */
UENUM(BlueprintType)
enum class ELootLockerAdminLeaderboardRewardPositionType : uint8
{
    /**
     * Values are used for rank value
     */
    by_rank = 0         UMETA(DisplayName = "Rank"),
    /**
     * Values are used as a percentage of all
     */
    by_percent = 1        UMETA(DisplayName = "Percent"),
};

//==================================================
// Data Type Definitions
//==================================================

USTRUCT(BlueprintType)
struct FLootLockerAdminLeaderboardRewardDefinition
{
    GENERATED_BODY()
    /**
     * Min value for the cohort to get reward
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    int Min = 0;
    /**
     * Max value for the cohort to get reward
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    int Max = 0;
    /**
     * What method to use
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    ELootLockerAdminLeaderboardRewardPositionType Method = ELootLockerAdminLeaderboardRewardPositionType::by_percent;
    /**
     * Are the values based from the top or bottom
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    ELootLockerAdminLeaderboardRewardDirection Direction = ELootLockerAdminLeaderboardRewardDirection::asc;
};

USTRUCT(BlueprintType)
struct FLootLockerAdminLeaderboardRewardType
{
    GENERATED_BODY()
    /**
     * Defines the cohort the reward is for
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FLootLockerAdminLeaderboardRewardDefinition Args;

protected:
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "LootLockerAdmin")
    FString Type = "between";
};

//==================================================
// Request Definitions
//==================================================


USTRUCT(BlueprintType)
struct FLootLockerAdminLeaderboardBaseRequest
{
    GENERATED_BODY()

public:
    FLootLockerAdminLeaderboardBaseRequest(const FString& InKey,
        const FString& InName,
        ELootLockerAdminLeaderboardDirection InDirectionMethod,
        bool InEnableGameApiWrites,
        bool InOverwriteScoreOnSubmit)
        : Key(InKey),
        Name(InName),
        Direction_method(InDirectionMethod),
        Enable_game_api_writes(InEnableGameApiWrites),
        Overwrite_score_on_submit(InOverwriteScoreOnSubmit)
    {
    }

    FLootLockerAdminLeaderboardBaseRequest()
    {
    }

    /**
     * The unique key of the leaderboard
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FString Key = "";
    /**
     * The name of the leaderboard
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FString Name = "";
    /**
     * The sort order of the leaderboard
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    ELootLockerAdminLeaderboardDirection Direction_method = ELootLockerAdminLeaderboardDirection::ascending;
    /**
     * Allow the game api to write to this leaderboard
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    bool Enable_game_api_writes = false;
    /**
     * Always overwrite existing scores for members on this leaderboard
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    bool Overwrite_score_on_submit = false;
};

USTRUCT(BlueprintType)
struct FLootLockerAdminCreateLeaderboardRequest : public FLootLockerAdminLeaderboardBaseRequest
{
    GENERATED_BODY()
public:
    FLootLockerAdminCreateLeaderboardRequest(const FString& InKey,
        const FString& InName,
        ELootLockerAdminLeaderboardDirection InDirectionMethod,
        bool InEnableGameApiWrites,
        bool InOverwriteScoreOnSubmit)
        : FLootLockerAdminLeaderboardBaseRequest(InKey, InName, InDirectionMethod, InEnableGameApiWrites, InOverwriteScoreOnSubmit)
    {
    }

    FLootLockerAdminCreateLeaderboardRequest()
    {
    }

    /**
     * The type of leaderboard to create
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    ELootLockerAdminLeaderboardType Type = ELootLockerAdminLeaderboardType::player;
    /**
     * Enable metadata on this leaderboard
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    bool Has_metadata = false;
};

USTRUCT(BlueprintType)
struct FLootLockerAdminLeaderboardAddRewardRequest
{
    GENERATED_BODY()
public:
    FLootLockerAdminLeaderboardAddRewardRequest(
        const FString& InRewardId,
        const ELootLockerAdminLeaderboardRewardKind InRewardKind,
        const TArray<FLootLockerAdminLeaderboardRewardType>& InPredicates)
        :
        Reward_id(InRewardId),
        Reward_kind(InRewardKind),
        Predicates(InPredicates)
    {
    }

    FLootLockerAdminLeaderboardAddRewardRequest()
    {
    }

    /**
     * What is the ULID of the reward
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FString Reward_id = "";
    /**
     * What kind is the ULID referring to. NOTE: A currency kind must refer to a group to properly account for the correct amount to reward with.
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    ELootLockerAdminLeaderboardRewardKind Reward_kind = ELootLockerAdminLeaderboardRewardKind::asset;
    /**
     * The rules for who the reward will be handed to
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    TArray<FLootLockerAdminLeaderboardRewardType> Predicates;
};

//==================================================
// Response Definitions
//==================================================

USTRUCT(BlueprintType)
struct FLootLockerAdminCreateLeaderboardResponse : public FLootLockerAdminResponse
{
    GENERATED_BODY()
    /**
     * The ID of this leaderboard
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    int ID = 0;
    /**
     * The ULID of this leaderboard
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FString ULID = "";
    /**
     * The ID of the game this leaderboard is in
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    int Game_id = 0;
    /**
     * The unique key of this leaderboard
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FString Key = "";
    /**
     * The name of the leaderboard
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FString Name = "";
    /**
     * The type of leaderboard
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    ELootLockerAdminLeaderboardType Type = ELootLockerAdminLeaderboardType::player;
    /**
     * The sort order of the leaderboard
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    ELootLockerAdminLeaderboardDirection Direction_method = ELootLockerAdminLeaderboardDirection::ascending;
    /**
     * Is the game api allowed to write to this leaderboard
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    bool Enable_game_api_writes = false;
    /**
     * Do new submits overwrite existing scores for members on this leaderboard
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    bool Overwrite_score_on_submit = false;
    /**
     * Is metadata enabled on this leaderboard
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    bool Has_metadata = false;
    /**
     * The creation time of this leaderboard
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FString Created_at = "";
    /**
     * The last time this leaderboard was updated
     */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "LootLockerAdmin")
    FString Updated_at = "";
};

//==================================================
// Blueprint Delegate Definitions
//==================================================

/**
 * Blueprint response delegate for creating leaderboard
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminCreateLeaderboardResponseBP, FLootLockerAdminCreateLeaderboardResponse, Response);
/**
 * Blueprint response delegate for creating leaderboard
 */
DECLARE_DYNAMIC_DELEGATE_OneParam(FLootLockerAdminLeaderboardAddRewardResponseBP, FLootLockerAdminResponse, Response);

//==================================================
// C++ Delegate Definitions
//==================================================

/**
 * C++ response delegate for creating leaderboard
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminCreateLeaderboardResponseDelegate, FLootLockerAdminCreateLeaderboardResponse);
/**
 * C++ response delegate for creating leaderboard
 */
DECLARE_DELEGATE_OneParam(FLootLockerAdminLeaderboardAddRewardResponseDelegate, FLootLockerAdminResponse);

/**
 *
 */
UCLASS()
class LOOTLOCKERADMINSDK_API ULootLockerAdminLeaderboardRequest : public UObject
{
    GENERATED_BODY()
    public:
    ULootLockerAdminLeaderboardRequest();

    static void CreateLeaderboard(const FLootLockerAdminCreateLeaderboardRequest& CreateLeaderboardRequest, const FLootLockerAdminCreateLeaderboardResponseBP& OnCompletedRequestBP = FLootLockerAdminCreateLeaderboardResponseBP(), const FLootLockerAdminCreateLeaderboardResponseDelegate& OnCompletedRequest = FLootLockerAdminCreateLeaderboardResponseDelegate());
    static void LeaderboardAddReward(const int LeaderboardId, const FLootLockerAdminLeaderboardAddRewardRequest& Request, const FLootLockerAdminLeaderboardAddRewardResponseBP& OnCompletedRequestBP = FLootLockerAdminLeaderboardAddRewardResponseBP(), const FLootLockerAdminLeaderboardAddRewardResponseDelegate& OnCompletedRequest = FLootLockerAdminLeaderboardAddRewardResponseDelegate());
};
