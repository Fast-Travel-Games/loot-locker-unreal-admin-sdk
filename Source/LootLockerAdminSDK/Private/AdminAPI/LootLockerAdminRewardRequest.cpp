
#include "AdminAPI/LootLockerAdminRewardRequest.h"

#include "LootLockerAdminHttpClient.h"

ULootLockerAdminRewardRequest::ULootLockerAdminRewardRequest()
{
}

void ULootLockerAdminRewardRequest::CreateGroup(const TArray<FLootLockerAdminEntity>& Entities, const FString& Name, const FString& Description, const FLootLockerAdminCreateGroupResponseBP& OnCompletedRequestBP, const FLootLockerAdminCreateGroupResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	FLootLockerAdminCreateGroupRequest Request;
	Request.Name = Name;
	Request.Description = Description;
	Request.Associations = Entities;
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminResponse>(Request, ULootLockerAdminEndpoints::CreateGroup, {Config->GameID}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}
