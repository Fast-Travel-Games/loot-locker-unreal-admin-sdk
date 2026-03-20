
#include "AdminAPI/LootLockerAdminLeaderboardRequest.h"

#include "LootLockerAdminHttpClient.h"

ULootLockerAdminLeaderboardRequest::ULootLockerAdminLeaderboardRequest()
{
}

void ULootLockerAdminLeaderboardRequest::CreateLeaderboard(const FLootLockerAdminCreateLeaderboardRequest& CreateLeaderboardRequest, const FLootLockerAdminCreateLeaderboardResponseBP& OnCompletedRequestBP, const FLootLockerAdminCreateLeaderboardResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminCreateLeaderboardResponse>(CreateLeaderboardRequest, ULootLockerAdminEndpoints::CreateLeaderboard, {Config->GameID}, {}, OnCompletedRequestBP, OnCompletedRequest);
}
