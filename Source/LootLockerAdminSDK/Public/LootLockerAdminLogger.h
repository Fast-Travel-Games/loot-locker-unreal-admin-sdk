
#pragma once

#include "CoreMinimal.h"
#include "LootLockerAdminLogger.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogLootLockerAdmin, Log, All);

UENUM(BlueprintType, Category = "LootLockerAdmin")
enum class ELootLockerAdminLogLevel : uint8
{
		Ignore = 0			UMETA(DisplayName = "No Logging"),
		Fatal = 1			UMETA(DisplayName = "Fatal"),
		Error = 2			UMETA(DisplayName = "Error"),
		Warning = 3			UMETA(DisplayName = "Warning"),
		Display = 4			UMETA(DisplayName = "Display"),
		Log = 5				UMETA(DisplayName = "Log"),
		Verbose = 6			UMETA(DisplayName = "Verbose"),
		VeryVerbose = 7		UMETA(DisplayName = "Very Verbose")
};

UENUM(BlueprintType, Category = "LootLockerAdmin")
enum class ELootLockerAdminLogLevelConfiguration : uint8
{
		NoLogging = 0		UMETA(DisplayName = "No Logging"),
		Fatal = 1			UMETA(DisplayName = "Fatal"),
		Error = 2			UMETA(DisplayName = "Error"),
		Warning = 3			UMETA(DisplayName = "Warning"),
		Display = 4			UMETA(DisplayName = "Display"),
		Log = 5				UMETA(DisplayName = "Log"),
		Verbose = 6			UMETA(DisplayName = "Verbose"),
		VeryVerbose = 7		UMETA(DisplayName = "Very Verbose"),
		All = VeryVerbose	UMETA(DisplayName = "All"),
		// Log errors and warnings as normal log messages
		AllAsNormal = 8		UMETA(DisplayName = "All as normal")
};

/**
 * 
 */
UCLASS()
class LOOTLOCKERADMINSDK_API ULootLockerAdminLogger : public UObject
{
	GENERATED_BODY()
	public:	
	ULootLockerAdminLogger();	

	static void Log(FString LogMessage);
	static void Log(ELootLockerAdminLogLevel LogLevel, FString LogMessage);
};

