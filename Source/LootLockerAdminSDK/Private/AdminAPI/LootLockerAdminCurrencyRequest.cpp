
#include "AdminAPI/LootLockerAdminCurrencyRequest.h"

#include "LootLockerAdminHttpClient.h"

ULootLockerAdminCurrencyRequest::ULootLockerAdminCurrencyRequest()
{
}

void ULootLockerAdminCurrencyRequest::CreateCurrency(const FString& Name, const FString& Code, const FString& DenominationName, const FLootLockerAdminCreateCurrencyResponseBP& OnCompletedRequestBP, const FLootLockerAdminCreateCurrencyResponseDelegate& OnCompletedRequest)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	FLootLockerAdminCreateCurrencyRequest Request;
	Request.Name = Name;
	Request.Code = Code;
	Request.Initial_denomination_name = DenominationName;

	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminCreateCurrencyResponse>(Request, ULootLockerAdminEndpoints::CreateCurrency, {Config->GameID}, EmptyQueryParams, OnCompletedRequestBP, OnCompletedRequest);
}

void ULootLockerAdminCurrencyRequest::ListCurrencies(const FLootLockerAdminListCurrenciesResponseBP& OnResponseCompletedBP, const FLootLockerAdminListCurrenciesResponseDelegate& OnResponseCompleted)
{
	const ULootLockerAdminConfig* Config = GetDefault<ULootLockerAdminConfig>();
	ULootLockerAdminHttpClient::SendRequest<FLootLockerAdminListCurrenciesResponse>(FLootLockerAdminEmptyRequest{}, ULootLockerAdminEndpoints::ListCurrencies, {Config->GameID}, {}, OnResponseCompletedBP, OnResponseCompleted);
}
