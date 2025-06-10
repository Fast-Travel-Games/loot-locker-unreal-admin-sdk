// Copyright (c) 2021 LootLocker

#pragma once

#include "JsonObjectConverter.h"
#include "LootLockerAdminUtilities.generated.h"

const TMultiMap<FString,FString> EmptyQueryParams;

UCLASS()
class LOOTLOCKERADMINSDKEDITOR_API ULootLockerAdminEnumUtils : public UObject
{
    GENERATED_BODY()
public:
    static FString GetEnum(const TCHAR* Enum, int32 EnumValue);
};

namespace LootLockerAdminUtilities
{
    FString AppendParametersToUrl(FString Url, const TMultiMap<FString, FString>& QueryParams);

    FString IntArrayToCommaSeparatedString(TArray<int> IntArray);

    FString FStringArrayToCommaSeparatedString(TArray<FString> FStringArray);

    FString FStringFromJsonObject(const TSharedPtr<FJsonObject>& JsonObject);

    FString FStringFromJsonArray(const TArray<TSharedPtr<FJsonValue>>& JsonArray);

    TSharedPtr<FJsonObject> JsonObjectFromFString(const FString& JsonString);

    bool JsonArrayFromFString(const FString& JsonString, TArray<TSharedPtr<FJsonValue>>& JsonArrayOutput);
}