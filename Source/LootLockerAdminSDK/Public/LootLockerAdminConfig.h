
#pragma once

#include "CoreMinimal.h"
#include "Runtime/Launch/Resources/Version.h"
#if ENGINE_MAJOR_VERSION >= 5
#include <regex>
#endif
#include "LootLockerAdminLogger.h"
#include "LootLockerAdminConfig.generated.h"

UCLASS(Config = Editor, DefaultConfig, meta = (DisplayName = "LootLocker Admin SDK Settings"))
class LOOTLOCKERADMINSDK_API ULootLockerAdminConfig : public UObject
{
	GENERATED_BODY()
public:
	// Game ID can be found in the URL for LootLocker console, after .com/
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "LootLockerAdmin")
	int GameID = 0;
	// Domain Key used to talk to LootLocker. The Domain key can be found in `Settings > API Keys` in the Web Console: https://console.lootlocker.com/settings/api-keys
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "LootLockerAdmin")
	FString LootLockerDomainKey = "";
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "LootLockerAdmin")
	FString GameVersion = "";
	UPROPERTY(Config, VisibleAnywhere, BlueprintReadOnly, Category = "LootLockerAdmin", Meta = (EditCondition = "!IsValidGameVersion", EditConditionHides), Meta = (MultiLine = true), Meta = (DisplayName = "WARNING:"), Transient)
	FString InvalidGameVersionWarning = "Game version needs to follow a numeric Semantic Versioning pattern: X.Y.Z.B with the sections denoting MAJOR.MINOR.PATCH.BUILD and the last two being optional. Read more at https://docs.lootlocker.com/the-basics/core-concepts/glossary#game-version";
	UPROPERTY(Config, VisibleAnywhere, BlueprintReadOnly, Meta = (EditCondition = "false", EditConditionHides), Category = "LootLockerAdmin")
	FString LootLockerVersion = "2021-06-01";
	// Limit the log level for the LootLocker Server SDK to this log level, will neither affect nor override the log level for the rest of your game 
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "LootLockerAdmin")
	ELootLockerAdminLogLevelConfiguration LimitLogLevelTo = ELootLockerAdminLogLevelConfiguration::Display;
	// Set to true if you want LootLocker to log outside of an editor context. We recommend that this only be enabled for debugging purposes.
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = "LootLockerAdmin")
	bool LogOutsideOfEditor = false;

	UFUNCTION()
	static bool ShouldLog()
	{
#if WITH_EDITOR
		return true;
#else
		return GetDefault<ULootLockerAdminConfig>()->LogOutsideOfEditor;	
#endif
	}
	
	UFUNCTION()
	static bool IsSemverString(const FString& str)
	{
#if ENGINE_MAJOR_VERSION >= 5
		return std::regex_match(TCHAR_TO_UTF8(*str), SemverPattern);
#else
		return true;
#endif
	}
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override
	{
		if (PropertyChangedEvent.GetPropertyName() == "GameVersion")
		{
			IsValidGameVersion = IsSemverString(GameVersion);
		}
		UObject::PostEditChangeProperty(PropertyChangedEvent);
	}
#endif //WITH_EDITOR
	virtual void PostInitProperties() override
	{
		IsValidGameVersion = IsSemverString(GameVersion);
		UObject::PostInitProperties();
	}
private:
	UPROPERTY(Config, VisibleInstanceOnly, Meta = (EditCondition = "false", EditConditionHides), Transient, Category = "LootLockerAdmin")
	bool IsValidGameVersion = true;
#if ENGINE_MAJOR_VERSION >= 5
	inline static const std::regex SemverPattern = std::regex("^(0|[1-9]\\d*)\\.(0|[1-9]\\d*)(?:\\.(0|[1-9]\\d*))?(?:\\.(0|[1-9]\\d*))?$");
#endif
};
