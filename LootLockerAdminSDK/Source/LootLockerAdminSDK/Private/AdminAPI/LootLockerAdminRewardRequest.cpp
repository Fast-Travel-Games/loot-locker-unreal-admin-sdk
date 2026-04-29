
#include "AdminAPI/LootLockerAdminRewardRequest.h"

#include "LootLockerAdminHttpClient.h"

ULootLockerAdminRewardRequest::ULootLockerAdminRewardRequest()
{
}

void ULootLockerAdminRewardRequest::CreateCurrencyReward(const FLootLockerAdminEntity& Reward, const FLootLockerAdminCreateCurrencyRewardResponseBP& OnCompletedRequestBP, const FLootLockerAdminCreateCurrencyRewardResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	FLootLockerAdminCreateCurrencyRewardRequest Request;
	Request.Entity_id = Reward.Entity_id;
	Request.Metadata = Reward.Metadata;
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminCreateRewardResponse>(Request, ULootLockerAdminEndpoints::CreateCurrencyReward, {Config->GameID}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerAdminRewardRequest::CreateGroup(const TArray<FLootLockerAdminEntity>& Entities, const FString& Name, const FString& Description, const FLootLockerAdminCreateGroupResponseBP& OnCompletedRequestBP, const FLootLockerAdminCreateGroupResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	FLootLockerAdminCreateGroupRequest Request;
	Request.Name = Name;
	Request.Description = Description;
	Request.Associations = Entities;
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminCreateRewardResponse>(Request, ULootLockerAdminEndpoints::CreateGroup, {Config->GameID}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}
