
#pragma once

#include "CoreMinimal.h"
#include "LootLockerAdminConfig.generated.h"

UCLASS(Config = Editor, DefaultConfig, meta = (DisplayName = "LootLocker Admin SDK Settings"))
class LOOTLOCKERADMINSDK_API ULootLockerAdminConfig : public UObject
{
	GENERATED_BODY()
public:
	// Game ID can be found in the URL for LootLocker console, after .com/
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "LootLockerAdmin")
	int GameID = 0;
	UPROPERTY(Config, VisibleAnywhere, BlueprintReadOnly, Meta = (EditCondition = "false", EditConditionHides), Category = "LootLockerAdmin")
	FString LootLockerVersion = "2021-06-01";
};
