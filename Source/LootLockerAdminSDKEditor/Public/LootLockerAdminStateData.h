
#pragma once

#include "CoreMinimal.h"
#include "LootLockerAdminStateData.generated.h"


UCLASS()
class LOOTLOCKERADMINSDKEDITOR_API ULootLockerAdminStateData : public UObject
{
	GENERATED_BODY()
    static FString AdminToken;

public:
	static FString GetAdminToken();
	static void SetAdminToken(FString InAdminToken);
    static void ClearState();
};