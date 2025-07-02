
#pragma once

#include "CoreMinimal.h"
#include "LootLockerAdminStateData.generated.h"


UCLASS()
class LOOTLOCKERADMINSDK_API ULootLockerAdminStateData : public UObject
{
	GENERATED_BODY()
    static FString AdminToken;

public:
	static FString GetAdminToken();
	static void SetAdminToken(FString InAdminToken);
    static void ClearState();
};