
#include "LootLockerAdminLogger.h"
#include "Logging/LogVerbosity.h"
#include "LootLockerAdminConfig.h"

DEFINE_LOG_CATEGORY(LogLootLockerAdmin);

ULootLockerAdminLogger::ULootLockerAdminLogger()
{
}

void ULootLockerAdminLogger::Log(FString LogMessage)
{
	Log(ELootLockerAdminLogLevel::Display, LogMessage);
}

void ULootLockerAdminLogger::Log(ELootLockerAdminLogLevel Verbosity, FString LogMessage)
{
	if (Verbosity == ELootLockerAdminLogLevel::Ignore)
	{
		return;
	}

	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();

	if (Config->LimitLogLevelTo != ELootLockerAdminLogLevelConfiguration::NoLogging && Config->LimitLogLevelTo >= (ELootLockerAdminLogLevelConfiguration)Verbosity) {
        if (Config->LimitLogLevelTo == ELootLockerAdminLogLevelConfiguration::AllAsNormal) {
            Verbosity = ELootLockerAdminLogLevel::Display;
		}

		switch (Verbosity) {
                case ELootLockerAdminLogLevel::Fatal:
					UE_LOG(LogLootLockerAdmin, Fatal, TEXT("%s"), *LogMessage);
					break;
                case ELootLockerAdminLogLevel::Error:
					UE_LOG(LogLootLockerAdmin, Error, TEXT("%s"), *LogMessage);
					break;
                case ELootLockerAdminLogLevel::Warning:
					UE_LOG(LogLootLockerAdmin, Warning, TEXT("%s"), *LogMessage);
					break;
				default:
                case ELootLockerAdminLogLevel::Display:
					UE_LOG(LogLootLockerAdmin, Display, TEXT("%s"), *LogMessage);
					break;
                case ELootLockerAdminLogLevel::Log:
					UE_LOG(LogLootLockerAdmin, Log, TEXT("%s"), *LogMessage);
					break;
                case ELootLockerAdminLogLevel::Verbose:
					UE_LOG(LogLootLockerAdmin, Verbose, TEXT("%s"), *LogMessage);
					break;
                case ELootLockerAdminLogLevel::VeryVerbose:
					UE_LOG(LogLootLockerAdmin, VeryVerbose, TEXT("%s"), *LogMessage);
					break;
        }
	}
}