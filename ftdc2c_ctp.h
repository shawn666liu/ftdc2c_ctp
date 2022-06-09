/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com
/////////////////////////////////////////////////////////////////////////

#pragma once

#ifdef WIN32
// msvc for windows  // #ifdef _MSC_VER
#ifdef FTDC2C_EXPORTS
#define FTDC2C_API extern __declspec(dllexport)
#else
#define FTDC2C_API extern __declspec(dllimport)
#endif
#define MYDECL  __stdcall
#else
// Linux or clang for windows
#define FTDC2C_API extern
#define MYDECL
#endif




#include "enums.h"
#include "api/ThostFtdcUserApiStruct.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef void(MYDECL* CbOnErrRtnEvent)(void* pObject, EnumOnErrRtnEvent evt, void* pParam, CThostFtdcRspInfoField* pRspInfo);
	typedef void(MYDECL* CbOnFrontEvent)(void* pObject, EnumOnFrontEvent evt, int Reason);
	typedef void(MYDECL* CbOnRspEvent)(void* pObject, EnumOnRspEvent evt, void* pParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
	typedef void(MYDECL* CbOnRtnEvent)(void* pObject, EnumOnRtnEvent evt, void* pParam);

	FTDC2C_API void MYDECL MdDestroyApi(void* pApi);
	FTDC2C_API void* MYDECL MdSetObject(void* pApi, void* pObject);
	FTDC2C_API void MYDECL MdRegisterCallback(void* pApi, CbOnFrontEvent c1, CbOnRspEvent c2, CbOnRtnEvent c3, void* pObject);
	FTDC2C_API void* MYDECL MdCreateApi(const char* pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast);
	FTDC2C_API const char* MYDECL MdGetApiVersion();
	FTDC2C_API void MYDECL MdInit(void* pApi);
	FTDC2C_API const char* MYDECL MdGetTradingDay(void* pApi);
	FTDC2C_API void MYDECL MdRegisterFront(void* pApi, const char* pszFrontAddress);
	FTDC2C_API void MYDECL MdRegisterNameServer(void* pApi, const char* pszNsAddress);
	FTDC2C_API void MYDECL MdRegisterFensUserInfo(void* pApi, const CThostFtdcFensUserInfoField* pFensUserInfo);
	FTDC2C_API int MYDECL MdSubscribeMarketData(void* pApi, const char* ppInstrumentID[], int nCount);
	FTDC2C_API int MYDECL MdUnSubscribeMarketData(void* pApi, const char* ppInstrumentID[], int nCount);
	FTDC2C_API int MYDECL MdSubscribeForQuoteRsp(void* pApi, const char* ppInstrumentID[], int nCount);
	FTDC2C_API int MYDECL MdUnSubscribeForQuoteRsp(void* pApi, const char* ppInstrumentID[], int nCount);
	FTDC2C_API int MYDECL MdReqUserLogin(void* pApi, const CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID);
	FTDC2C_API int MYDECL MdReqUserLogout(void* pApi, const CThostFtdcUserLogoutField* pUserLogout, int nRequestID);
	FTDC2C_API int MYDECL MdReqQryMulticastInstrument(void* pApi, const CThostFtdcQryMulticastInstrumentField* pQryMulticastInstrument, int nRequestID);

	FTDC2C_API void MYDECL TdDestroyApi(void* pApi);
	FTDC2C_API void* MYDECL TdSetObject(void* pApi, void* pObject);
	FTDC2C_API void MYDECL TdRegisterCallback(void* pApi, CbOnErrRtnEvent c1, CbOnFrontEvent c2, CbOnRspEvent c3, CbOnRtnEvent c4, void* pObject);
	FTDC2C_API void* MYDECL TdCreateApi(const char* pszFlowPath);
	FTDC2C_API const char* MYDECL TdGetApiVersion();
	FTDC2C_API void MYDECL TdInit(void* pApi);
	FTDC2C_API const char* MYDECL TdGetTradingDay(void* pApi);
	FTDC2C_API void MYDECL TdRegisterFront(void* pApi, const char* pszFrontAddress);
	FTDC2C_API void MYDECL TdRegisterNameServer(void* pApi, const char* pszNsAddress);
	FTDC2C_API void MYDECL TdRegisterFensUserInfo(void* pApi, const CThostFtdcFensUserInfoField* pFensUserInfo);
	FTDC2C_API void MYDECL TdSubscribePrivateTopic(void* pApi, THOST_TE_RESUME_TYPE nResumeType);
	FTDC2C_API void MYDECL TdSubscribePublicTopic(void* pApi, THOST_TE_RESUME_TYPE nResumeType);
	FTDC2C_API int MYDECL TdReqAuthenticate(void* pApi, const CThostFtdcReqAuthenticateField* pReqAuthenticateField, int nRequestID);
	FTDC2C_API int MYDECL TdRegisterUserSystemInfo(void* pApi, const CThostFtdcUserSystemInfoField* pUserSystemInfo);
	FTDC2C_API int MYDECL TdSubmitUserSystemInfo(void* pApi, const CThostFtdcUserSystemInfoField* pUserSystemInfo);
	FTDC2C_API int MYDECL TdReqUserLogin(void* pApi, const CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserLogout(void* pApi, const CThostFtdcUserLogoutField* pUserLogout, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserPasswordUpdate(void* pApi, const CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, int nRequestID);
	FTDC2C_API int MYDECL TdReqTradingAccountPasswordUpdate(void* pApi, const CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserAuthMethod(void* pApi, const CThostFtdcReqUserAuthMethodField* pReqUserAuthMethod, int nRequestID);
	FTDC2C_API int MYDECL TdReqGenUserCaptcha(void* pApi, const CThostFtdcReqGenUserCaptchaField* pReqGenUserCaptcha, int nRequestID);
	FTDC2C_API int MYDECL TdReqGenUserText(void* pApi, const CThostFtdcReqGenUserTextField* pReqGenUserText, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserLoginWithCaptcha(void* pApi, const CThostFtdcReqUserLoginWithCaptchaField* pReqUserLoginWithCaptcha, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserLoginWithText(void* pApi, const CThostFtdcReqUserLoginWithTextField* pReqUserLoginWithText, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserLoginWithOTP(void* pApi, const CThostFtdcReqUserLoginWithOTPField* pReqUserLoginWithOTP, int nRequestID);
	FTDC2C_API int MYDECL TdReqOrderInsert(void* pApi, const CThostFtdcInputOrderField* pInputOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqParkedOrderInsert(void* pApi, const CThostFtdcParkedOrderField* pParkedOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqParkedOrderAction(void* pApi, const CThostFtdcParkedOrderActionField* pParkedOrderAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqOrderAction(void* pApi, const CThostFtdcInputOrderActionField* pInputOrderAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryMaxOrderVolume(void* pApi, const CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, int nRequestID);
	FTDC2C_API int MYDECL TdReqSettlementInfoConfirm(void* pApi, const CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, int nRequestID);
	FTDC2C_API int MYDECL TdReqRemoveParkedOrder(void* pApi, const CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqRemoveParkedOrderAction(void* pApi, const CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqExecOrderInsert(void* pApi, const CThostFtdcInputExecOrderField* pInputExecOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqExecOrderAction(void* pApi, const CThostFtdcInputExecOrderActionField* pInputExecOrderAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqForQuoteInsert(void* pApi, const CThostFtdcInputForQuoteField* pInputForQuote, int nRequestID);
	FTDC2C_API int MYDECL TdReqQuoteInsert(void* pApi, const CThostFtdcInputQuoteField* pInputQuote, int nRequestID);
	FTDC2C_API int MYDECL TdReqQuoteAction(void* pApi, const CThostFtdcInputQuoteActionField* pInputQuoteAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqBatchOrderAction(void* pApi, const CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqOptionSelfCloseInsert(void* pApi, const CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, int nRequestID);
	FTDC2C_API int MYDECL TdReqOptionSelfCloseAction(void* pApi, const CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqCombActionInsert(void* pApi, const CThostFtdcInputCombActionField* pInputCombAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryOrder(void* pApi, const CThostFtdcQryOrderField* pQryOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTrade(void* pApi, const CThostFtdcQryTradeField* pQryTrade, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorPosition(void* pApi, const CThostFtdcQryInvestorPositionField* pQryInvestorPosition, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTradingAccount(void* pApi, const CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestor(void* pApi, const CThostFtdcQryInvestorField* pQryInvestor, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTradingCode(void* pApi, const CThostFtdcQryTradingCodeField* pQryTradingCode, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInstrumentMarginRate(void* pApi, const CThostFtdcQryInstrumentMarginRateField* pQryInstrumentMarginRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInstrumentCommissionRate(void* pApi, const CThostFtdcQryInstrumentCommissionRateField* pQryInstrumentCommissionRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryExchange(void* pApi, const CThostFtdcQryExchangeField* pQryExchange, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryProduct(void* pApi, const CThostFtdcQryProductField* pQryProduct, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInstrument(void* pApi, const CThostFtdcQryInstrumentField* pQryInstrument, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryDepthMarketData(void* pApi, const CThostFtdcQryDepthMarketDataField* pQryDepthMarketData, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTraderOffer(void* pApi, const CThostFtdcQryTraderOfferField* pQryTraderOffer, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySettlementInfo(void* pApi, const CThostFtdcQrySettlementInfoField* pQrySettlementInfo, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTransferBank(void* pApi, const CThostFtdcQryTransferBankField* pQryTransferBank, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorPositionDetail(void* pApi, const CThostFtdcQryInvestorPositionDetailField* pQryInvestorPositionDetail, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryNotice(void* pApi, const CThostFtdcQryNoticeField* pQryNotice, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySettlementInfoConfirm(void* pApi, const CThostFtdcQrySettlementInfoConfirmField* pQrySettlementInfoConfirm, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorPositionCombineDetail(void* pApi, const CThostFtdcQryInvestorPositionCombineDetailField* pQryInvestorPositionCombineDetail, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCFMMCTradingAccountKey(void* pApi, const CThostFtdcQryCFMMCTradingAccountKeyField* pQryCFMMCTradingAccountKey, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryEWarrantOffset(void* pApi, const CThostFtdcQryEWarrantOffsetField* pQryEWarrantOffset, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorProductGroupMargin(void* pApi, const CThostFtdcQryInvestorProductGroupMarginField* pQryInvestorProductGroupMargin, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryExchangeMarginRate(void* pApi, const CThostFtdcQryExchangeMarginRateField* pQryExchangeMarginRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryExchangeMarginRateAdjust(void* pApi, const CThostFtdcQryExchangeMarginRateAdjustField* pQryExchangeMarginRateAdjust, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryExchangeRate(void* pApi, const CThostFtdcQryExchangeRateField* pQryExchangeRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySecAgentACIDMap(void* pApi, const CThostFtdcQrySecAgentACIDMapField* pQrySecAgentACIDMap, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryProductExchRate(void* pApi, const CThostFtdcQryProductExchRateField* pQryProductExchRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryProductGroup(void* pApi, const CThostFtdcQryProductGroupField* pQryProductGroup, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryMMInstrumentCommissionRate(void* pApi, const CThostFtdcQryMMInstrumentCommissionRateField* pQryMMInstrumentCommissionRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryMMOptionInstrCommRate(void* pApi, const CThostFtdcQryMMOptionInstrCommRateField* pQryMMOptionInstrCommRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInstrumentOrderCommRate(void* pApi, const CThostFtdcQryInstrumentOrderCommRateField* pQryInstrumentOrderCommRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySecAgentTradingAccount(void* pApi, const CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySecAgentCheckMode(void* pApi, const CThostFtdcQrySecAgentCheckModeField* pQrySecAgentCheckMode, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySecAgentTradeInfo(void* pApi, const CThostFtdcQrySecAgentTradeInfoField* pQrySecAgentTradeInfo, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryOptionInstrTradeCost(void* pApi, const CThostFtdcQryOptionInstrTradeCostField* pQryOptionInstrTradeCost, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryOptionInstrCommRate(void* pApi, const CThostFtdcQryOptionInstrCommRateField* pQryOptionInstrCommRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryExecOrder(void* pApi, const CThostFtdcQryExecOrderField* pQryExecOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryForQuote(void* pApi, const CThostFtdcQryForQuoteField* pQryForQuote, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryQuote(void* pApi, const CThostFtdcQryQuoteField* pQryQuote, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryOptionSelfClose(void* pApi, const CThostFtdcQryOptionSelfCloseField* pQryOptionSelfClose, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestUnit(void* pApi, const CThostFtdcQryInvestUnitField* pQryInvestUnit, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCombInstrumentGuard(void* pApi, const CThostFtdcQryCombInstrumentGuardField* pQryCombInstrumentGuard, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCombAction(void* pApi, const CThostFtdcQryCombActionField* pQryCombAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTransferSerial(void* pApi, const CThostFtdcQryTransferSerialField* pQryTransferSerial, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryAccountregister(void* pApi, const CThostFtdcQryAccountregisterField* pQryAccountregister, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryContractBank(void* pApi, const CThostFtdcQryContractBankField* pQryContractBank, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryParkedOrder(void* pApi, const CThostFtdcQryParkedOrderField* pQryParkedOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryParkedOrderAction(void* pApi, const CThostFtdcQryParkedOrderActionField* pQryParkedOrderAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTradingNotice(void* pApi, const CThostFtdcQryTradingNoticeField* pQryTradingNotice, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryBrokerTradingParams(void* pApi, const CThostFtdcQryBrokerTradingParamsField* pQryBrokerTradingParams, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryBrokerTradingAlgos(void* pApi, const CThostFtdcQryBrokerTradingAlgosField* pQryBrokerTradingAlgos, int nRequestID);
	FTDC2C_API int MYDECL TdReqQueryCFMMCTradingAccountToken(void* pApi, const CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, int nRequestID);
	FTDC2C_API int MYDECL TdReqFromBankToFutureByFuture(void* pApi, const CThostFtdcReqTransferField* pReqTransfer, int nRequestID);
	FTDC2C_API int MYDECL TdReqFromFutureToBankByFuture(void* pApi, const CThostFtdcReqTransferField* pReqTransfer, int nRequestID);
	FTDC2C_API int MYDECL TdReqQueryBankAccountMoneyByFuture(void* pApi, const CThostFtdcReqQueryAccountField* pReqQueryAccount, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryClassifiedInstrument(void* pApi, const CThostFtdcQryClassifiedInstrumentField* pQryClassifiedInstrument, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCombPromotionParam(void* pApi, const CThostFtdcQryCombPromotionParamField* pQryCombPromotionParam, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryRiskSettleInvstPosition(void* pApi, const CThostFtdcQryRiskSettleInvstPositionField* pQryRiskSettleInvstPosition, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryRiskSettleProductStatus(void* pApi, const CThostFtdcQryRiskSettleProductStatusField* pQryRiskSettleProductStatus, int nRequestID);


#ifdef __cplusplus
}
#endif
