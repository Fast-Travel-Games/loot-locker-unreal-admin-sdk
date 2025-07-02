
#include "LootLockerAdminStateData.h"

#include "LootLockerAdminConfig.h"

FString ULootLockerAdminStateData::AdminToken = "";

FString ULootLockerAdminStateData::GetAdminToken()
{
	return AdminToken;
}

void ULootLockerAdminStateData::SetAdminToken(FString InAdminToken) {
	if (AdminToken.Equals(InAdminToken))
	{
		return;
	}
	AdminToken = InAdminToken;
}

void ULootLockerAdminStateData::ClearState()
{
	AdminToken = "";
}
