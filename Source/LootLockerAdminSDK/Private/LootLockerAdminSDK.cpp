
#include "LootLockerAdminSDK.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "LootLockerAdminConfig.h"
#include "UObject/ConstructorHelpers.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

#define LOCTEXT_NAMESPACE "FLootLockerAdminSDKModule"

DEFINE_LOG_CATEGORY(LogLootLockerAdmin);

void FLootLockerAdminSDKModule::StartupModule()
{
#if WITH_EDITOR
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "Plugins", "LootLocker Admin",
			LOCTEXT("LootLockerAdminSDKSettingsName", "LootLockerAdminSDK"),
			LOCTEXT("LootLockerAdminSDKSettingsDescription", "Configure LootLockerAdmin SDK."),
			GetMutableDefault<ULootLockerAdminConfig>()
		);
	}

#endif
}

void FLootLockerAdminSDKModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FLootLockerAdminSDKModule, LootLockerAdminSDKEditor)