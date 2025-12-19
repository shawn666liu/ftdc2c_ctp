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

	typedef void(MYDECL* CbOnErrRtnEvent)(void* pUserObject, EnumOnErrRtnEvent evt, void* pParam, CThostFtdcRspInfoField* pRspInfo);
	typedef void(MYDECL* CbOnFrontEvent)(void* pUserObject, EnumOnFrontEvent evt, int Reason);
	typedef void(MYDECL* CbOnRspEvent)(void* pUserObject, EnumOnRspEvent evt, void* pParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
	typedef void(MYDECL* CbOnRtnEvent)(void* pUserObject, EnumOnRtnEvent evt, void* pParam);

	FTDC2C_API void MYDECL MdDestroyApi(void* quoter);
	FTDC2C_API void* MYDECL MdSetUserObject(void* quoter, void* pUserObject);
	FTDC2C_API void MYDECL MdRegisterCallback(void* quoter, CbOnFrontEvent c1, CbOnRspEvent c2, CbOnRtnEvent c3, void* pUserObject);
	FTDC2C_API void* MYDECL MdCreateApi(const char* pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast, bool bIsProductionMode);
	FTDC2C_API const char* MYDECL MdGetApiVersion();
	FTDC2C_API void MYDECL MdInit(void* quoter);
	FTDC2C_API const char* MYDECL MdGetTradingDay(void* quoter);
	FTDC2C_API void MYDECL MdRegisterFront(void* quoter, const char* pszFrontAddress);
	FTDC2C_API void MYDECL MdRegisterNameServer(void* quoter, const char* pszNsAddress);
	FTDC2C_API void MYDECL MdRegisterFensUserInfo(void* quoter, const CThostFtdcFensUserInfoField* pFensUserInfo);
	FTDC2C_API int MYDECL MdSubscribeMarketData(void* quoter, const char* ppInstrumentID[], int nCount);
	FTDC2C_API int MYDECL MdUnSubscribeMarketData(void* quoter, const char* ppInstrumentID[], int nCount);
	FTDC2C_API int MYDECL MdSubscribeForQuoteRsp(void* quoter, const char* ppInstrumentID[], int nCount);
	FTDC2C_API int MYDECL MdUnSubscribeForQuoteRsp(void* quoter, const char* ppInstrumentID[], int nCount);
	FTDC2C_API int MYDECL MdReqUserLogin(void* quoter, const CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID);
	FTDC2C_API int MYDECL MdReqUserLogout(void* quoter, const CThostFtdcUserLogoutField* pUserLogout, int nRequestID);
	FTDC2C_API int MYDECL MdReqQryMulticastInstrument(void* quoter, const CThostFtdcQryMulticastInstrumentField* pQryMulticastInstrument, int nRequestID);

	FTDC2C_API void MYDECL TdDestroyApi(void* trader);
	FTDC2C_API void* MYDECL TdSetUserObject(void* trader, void* pUserObject);
	FTDC2C_API void MYDECL TdRegisterCallback(void* trader, CbOnErrRtnEvent c1, CbOnFrontEvent c2, CbOnRspEvent c3, CbOnRtnEvent c4, void* pUserObject);
	FTDC2C_API void* MYDECL TdCreateApi(const char* pszFlowPath, bool bIsProductionMode);
	FTDC2C_API const char* MYDECL TdGetApiVersion();
	FTDC2C_API void MYDECL TdInit(void* trader);
	FTDC2C_API const char* MYDECL TdGetTradingDay(void* trader);
	FTDC2C_API void MYDECL TdGetFrontInfo(void* trader, const CThostFtdcFrontInfoField* pFrontInfo);
	FTDC2C_API void MYDECL TdRegisterFront(void* trader, const char* pszFrontAddress);
	FTDC2C_API void MYDECL TdRegisterNameServer(void* trader, const char* pszNsAddress);
	FTDC2C_API void MYDECL TdRegisterFensUserInfo(void* trader, const CThostFtdcFensUserInfoField* pFensUserInfo);
	FTDC2C_API void MYDECL TdSubscribePrivateTopic(void* trader, THOST_TE_RESUME_TYPE nResumeType);
	FTDC2C_API void MYDECL TdSubscribePublicTopic(void* trader, THOST_TE_RESUME_TYPE nResumeType);
	FTDC2C_API int MYDECL TdReqAuthenticate(void* trader, const CThostFtdcReqAuthenticateField* pReqAuthenticateField, int nRequestID);
	FTDC2C_API int MYDECL TdRegisterUserSystemInfo(void* trader, const CThostFtdcUserSystemInfoField* pUserSystemInfo);
	FTDC2C_API int MYDECL TdSubmitUserSystemInfo(void* trader, const CThostFtdcUserSystemInfoField* pUserSystemInfo);
	FTDC2C_API int MYDECL TdRegisterWechatUserSystemInfo(void* trader, const CThostFtdcWechatUserSystemInfoField* pUserSystemInfo);
	FTDC2C_API int MYDECL TdSubmitWechatUserSystemInfo(void* trader, const CThostFtdcWechatUserSystemInfoField* pUserSystemInfo);
	FTDC2C_API int MYDECL TdReqUserLogin(void* trader, const CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserLogout(void* trader, const CThostFtdcUserLogoutField* pUserLogout, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserPasswordUpdate(void* trader, const CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, int nRequestID);
	FTDC2C_API int MYDECL TdReqTradingAccountPasswordUpdate(void* trader, const CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserAuthMethod(void* trader, const CThostFtdcReqUserAuthMethodField* pReqUserAuthMethod, int nRequestID);
	FTDC2C_API int MYDECL TdReqGenUserCaptcha(void* trader, const CThostFtdcReqGenUserCaptchaField* pReqGenUserCaptcha, int nRequestID);
	FTDC2C_API int MYDECL TdReqGenUserText(void* trader, const CThostFtdcReqGenUserTextField* pReqGenUserText, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserLoginWithCaptcha(void* trader, const CThostFtdcReqUserLoginWithCaptchaField* pReqUserLoginWithCaptcha, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserLoginWithText(void* trader, const CThostFtdcReqUserLoginWithTextField* pReqUserLoginWithText, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserLoginWithOTP(void* trader, const CThostFtdcReqUserLoginWithOTPField* pReqUserLoginWithOTP, int nRequestID);
	FTDC2C_API int MYDECL TdReqOrderInsert(void* trader, const CThostFtdcInputOrderField* pInputOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqParkedOrderInsert(void* trader, const CThostFtdcParkedOrderField* pParkedOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqParkedOrderAction(void* trader, const CThostFtdcParkedOrderActionField* pParkedOrderAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqOrderAction(void* trader, const CThostFtdcInputOrderActionField* pInputOrderAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryMaxOrderVolume(void* trader, const CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, int nRequestID);
	FTDC2C_API int MYDECL TdReqSettlementInfoConfirm(void* trader, const CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, int nRequestID);
	FTDC2C_API int MYDECL TdReqRemoveParkedOrder(void* trader, const CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqRemoveParkedOrderAction(void* trader, const CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqExecOrderInsert(void* trader, const CThostFtdcInputExecOrderField* pInputExecOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqExecOrderAction(void* trader, const CThostFtdcInputExecOrderActionField* pInputExecOrderAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqForQuoteInsert(void* trader, const CThostFtdcInputForQuoteField* pInputForQuote, int nRequestID);
	FTDC2C_API int MYDECL TdReqQuoteInsert(void* trader, const CThostFtdcInputQuoteField* pInputQuote, int nRequestID);
	FTDC2C_API int MYDECL TdReqQuoteAction(void* trader, const CThostFtdcInputQuoteActionField* pInputQuoteAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqBatchOrderAction(void* trader, const CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqOptionSelfCloseInsert(void* trader, const CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, int nRequestID);
	FTDC2C_API int MYDECL TdReqOptionSelfCloseAction(void* trader, const CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqCombActionInsert(void* trader, const CThostFtdcInputCombActionField* pInputCombAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryOrder(void* trader, const CThostFtdcQryOrderField* pQryOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTrade(void* trader, const CThostFtdcQryTradeField* pQryTrade, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorPosition(void* trader, const CThostFtdcQryInvestorPositionField* pQryInvestorPosition, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTradingAccount(void* trader, const CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestor(void* trader, const CThostFtdcQryInvestorField* pQryInvestor, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTradingCode(void* trader, const CThostFtdcQryTradingCodeField* pQryTradingCode, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInstrumentMarginRate(void* trader, const CThostFtdcQryInstrumentMarginRateField* pQryInstrumentMarginRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInstrumentCommissionRate(void* trader, const CThostFtdcQryInstrumentCommissionRateField* pQryInstrumentCommissionRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryUserSession(void* trader, const CThostFtdcQryUserSessionField* pQryUserSession, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryExchange(void* trader, const CThostFtdcQryExchangeField* pQryExchange, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryProduct(void* trader, const CThostFtdcQryProductField* pQryProduct, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInstrument(void* trader, const CThostFtdcQryInstrumentField* pQryInstrument, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryDepthMarketData(void* trader, const CThostFtdcQryDepthMarketDataField* pQryDepthMarketData, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTraderOffer(void* trader, const CThostFtdcQryTraderOfferField* pQryTraderOffer, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySettlementInfo(void* trader, const CThostFtdcQrySettlementInfoField* pQrySettlementInfo, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTransferBank(void* trader, const CThostFtdcQryTransferBankField* pQryTransferBank, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorPositionDetail(void* trader, const CThostFtdcQryInvestorPositionDetailField* pQryInvestorPositionDetail, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryNotice(void* trader, const CThostFtdcQryNoticeField* pQryNotice, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySettlementInfoConfirm(void* trader, const CThostFtdcQrySettlementInfoConfirmField* pQrySettlementInfoConfirm, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorPositionCombineDetail(void* trader, const CThostFtdcQryInvestorPositionCombineDetailField* pQryInvestorPositionCombineDetail, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCFMMCTradingAccountKey(void* trader, const CThostFtdcQryCFMMCTradingAccountKeyField* pQryCFMMCTradingAccountKey, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryEWarrantOffset(void* trader, const CThostFtdcQryEWarrantOffsetField* pQryEWarrantOffset, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorProductGroupMargin(void* trader, const CThostFtdcQryInvestorProductGroupMarginField* pQryInvestorProductGroupMargin, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryExchangeMarginRate(void* trader, const CThostFtdcQryExchangeMarginRateField* pQryExchangeMarginRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryExchangeMarginRateAdjust(void* trader, const CThostFtdcQryExchangeMarginRateAdjustField* pQryExchangeMarginRateAdjust, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryExchangeRate(void* trader, const CThostFtdcQryExchangeRateField* pQryExchangeRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySecAgentACIDMap(void* trader, const CThostFtdcQrySecAgentACIDMapField* pQrySecAgentACIDMap, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryProductExchRate(void* trader, const CThostFtdcQryProductExchRateField* pQryProductExchRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryProductGroup(void* trader, const CThostFtdcQryProductGroupField* pQryProductGroup, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryMMInstrumentCommissionRate(void* trader, const CThostFtdcQryMMInstrumentCommissionRateField* pQryMMInstrumentCommissionRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryMMOptionInstrCommRate(void* trader, const CThostFtdcQryMMOptionInstrCommRateField* pQryMMOptionInstrCommRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInstrumentOrderCommRate(void* trader, const CThostFtdcQryInstrumentOrderCommRateField* pQryInstrumentOrderCommRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySecAgentTradingAccount(void* trader, const CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySecAgentCheckMode(void* trader, const CThostFtdcQrySecAgentCheckModeField* pQrySecAgentCheckMode, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySecAgentTradeInfo(void* trader, const CThostFtdcQrySecAgentTradeInfoField* pQrySecAgentTradeInfo, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryOptionInstrTradeCost(void* trader, const CThostFtdcQryOptionInstrTradeCostField* pQryOptionInstrTradeCost, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryOptionInstrCommRate(void* trader, const CThostFtdcQryOptionInstrCommRateField* pQryOptionInstrCommRate, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryExecOrder(void* trader, const CThostFtdcQryExecOrderField* pQryExecOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryForQuote(void* trader, const CThostFtdcQryForQuoteField* pQryForQuote, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryQuote(void* trader, const CThostFtdcQryQuoteField* pQryQuote, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryOptionSelfClose(void* trader, const CThostFtdcQryOptionSelfCloseField* pQryOptionSelfClose, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestUnit(void* trader, const CThostFtdcQryInvestUnitField* pQryInvestUnit, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCombInstrumentGuard(void* trader, const CThostFtdcQryCombInstrumentGuardField* pQryCombInstrumentGuard, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCombAction(void* trader, const CThostFtdcQryCombActionField* pQryCombAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTransferSerial(void* trader, const CThostFtdcQryTransferSerialField* pQryTransferSerial, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryAccountregister(void* trader, const CThostFtdcQryAccountregisterField* pQryAccountregister, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryContractBank(void* trader, const CThostFtdcQryContractBankField* pQryContractBank, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryParkedOrder(void* trader, const CThostFtdcQryParkedOrderField* pQryParkedOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryParkedOrderAction(void* trader, const CThostFtdcQryParkedOrderActionField* pQryParkedOrderAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTradingNotice(void* trader, const CThostFtdcQryTradingNoticeField* pQryTradingNotice, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryBrokerTradingParams(void* trader, const CThostFtdcQryBrokerTradingParamsField* pQryBrokerTradingParams, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryBrokerTradingAlgos(void* trader, const CThostFtdcQryBrokerTradingAlgosField* pQryBrokerTradingAlgos, int nRequestID);
	FTDC2C_API int MYDECL TdReqQueryCFMMCTradingAccountToken(void* trader, const CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, int nRequestID);
	FTDC2C_API int MYDECL TdReqFromBankToFutureByFuture(void* trader, const CThostFtdcReqTransferField* pReqTransfer, int nRequestID);
	FTDC2C_API int MYDECL TdReqFromFutureToBankByFuture(void* trader, const CThostFtdcReqTransferField* pReqTransfer, int nRequestID);
	FTDC2C_API int MYDECL TdReqQueryBankAccountMoneyByFuture(void* trader, const CThostFtdcReqQueryAccountField* pReqQueryAccount, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryClassifiedInstrument(void* trader, const CThostFtdcQryClassifiedInstrumentField* pQryClassifiedInstrument, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCombPromotionParam(void* trader, const CThostFtdcQryCombPromotionParamField* pQryCombPromotionParam, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryRiskSettleInvstPosition(void* trader, const CThostFtdcQryRiskSettleInvstPositionField* pQryRiskSettleInvstPosition, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryRiskSettleProductStatus(void* trader, const CThostFtdcQryRiskSettleProductStatusField* pQryRiskSettleProductStatus, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySPBMFutureParameter(void* trader, const CThostFtdcQrySPBMFutureParameterField* pQrySPBMFutureParameter, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySPBMOptionParameter(void* trader, const CThostFtdcQrySPBMOptionParameterField* pQrySPBMOptionParameter, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySPBMIntraParameter(void* trader, const CThostFtdcQrySPBMIntraParameterField* pQrySPBMIntraParameter, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySPBMInterParameter(void* trader, const CThostFtdcQrySPBMInterParameterField* pQrySPBMInterParameter, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySPBMPortfDefinition(void* trader, const CThostFtdcQrySPBMPortfDefinitionField* pQrySPBMPortfDefinition, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySPBMInvestorPortfDef(void* trader, const CThostFtdcQrySPBMInvestorPortfDefField* pQrySPBMInvestorPortfDef, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorPortfMarginRatio(void* trader, const CThostFtdcQryInvestorPortfMarginRatioField* pQryInvestorPortfMarginRatio, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorProdSPBMDetail(void* trader, const CThostFtdcQryInvestorProdSPBMDetailField* pQryInvestorProdSPBMDetail, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorCommoditySPMMMargin(void* trader, const CThostFtdcQryInvestorCommoditySPMMMarginField* pQryInvestorCommoditySPMMMargin, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorCommodityGroupSPMMMargin(void* trader, const CThostFtdcQryInvestorCommodityGroupSPMMMarginField* pQryInvestorCommodityGroupSPMMMargin, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySPMMInstParam(void* trader, const CThostFtdcQrySPMMInstParamField* pQrySPMMInstParam, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySPMMProductParam(void* trader, const CThostFtdcQrySPMMProductParamField* pQrySPMMProductParam, int nRequestID);
	FTDC2C_API int MYDECL TdReqQrySPBMAddOnInterParameter(void* trader, const CThostFtdcQrySPBMAddOnInterParameterField* pQrySPBMAddOnInterParameter, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryRCAMSCombProductInfo(void* trader, const CThostFtdcQryRCAMSCombProductInfoField* pQryRCAMSCombProductInfo, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryRCAMSInstrParameter(void* trader, const CThostFtdcQryRCAMSInstrParameterField* pQryRCAMSInstrParameter, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryRCAMSIntraParameter(void* trader, const CThostFtdcQryRCAMSIntraParameterField* pQryRCAMSIntraParameter, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryRCAMSInterParameter(void* trader, const CThostFtdcQryRCAMSInterParameterField* pQryRCAMSInterParameter, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryRCAMSShortOptAdjustParam(void* trader, const CThostFtdcQryRCAMSShortOptAdjustParamField* pQryRCAMSShortOptAdjustParam, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryRCAMSInvestorCombPosition(void* trader, const CThostFtdcQryRCAMSInvestorCombPositionField* pQryRCAMSInvestorCombPosition, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorProdRCAMSMargin(void* trader, const CThostFtdcQryInvestorProdRCAMSMarginField* pQryInvestorProdRCAMSMargin, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryRULEInstrParameter(void* trader, const CThostFtdcQryRULEInstrParameterField* pQryRULEInstrParameter, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryRULEIntraParameter(void* trader, const CThostFtdcQryRULEIntraParameterField* pQryRULEIntraParameter, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryRULEInterParameter(void* trader, const CThostFtdcQryRULEInterParameterField* pQryRULEInterParameter, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorProdRULEMargin(void* trader, const CThostFtdcQryInvestorProdRULEMarginField* pQryInvestorProdRULEMargin, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorPortfSetting(void* trader, const CThostFtdcQryInvestorPortfSettingField* pQryInvestorPortfSetting, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorInfoCommRec(void* trader, const CThostFtdcQryInvestorInfoCommRecField* pQryInvestorInfoCommRec, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryCombLeg(void* trader, const CThostFtdcQryCombLegField* pQryCombLeg, int nRequestID);
	FTDC2C_API int MYDECL TdReqOffsetSetting(void* trader, const CThostFtdcInputOffsetSettingField* pInputOffsetSetting, int nRequestID);
	FTDC2C_API int MYDECL TdReqCancelOffsetSetting(void* trader, const CThostFtdcInputOffsetSettingField* pInputOffsetSetting, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryOffsetSetting(void* trader, const CThostFtdcQryOffsetSettingField* pQryOffsetSetting, int nRequestID);


#ifdef __cplusplus
}
#endif
