/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com
/////////////////////////////////////////////////////////////////////////

#include "ftdc2c_ctp.h"
#include "quoter.h"
#include "trader.h"

FTDC2C_API void MYDECL MdDestroyApi(void* pApi) {
	delete static_cast<Quoter*>(pApi);
}
FTDC2C_API void* MYDECL MdSetObject(void* pApi, void* pObject) {
	void* old = static_cast<Quoter*>(pApi)->pObject;
	static_cast<Quoter*>(pApi)->pObject = pObject;
	return old;
}

FTDC2C_API void MYDECL MdRegisterCallback(void* pApi, CbOnFrontEvent c1, CbOnRspEvent c2, CbOnRtnEvent c3, void* pObject) {
	Quoter* p = static_cast<Quoter*>(pApi);
	p->mOnFrontEvent = c1;
	p->mOnRspEvent = c2;
	p->mOnRtnEvent = c3;
	if (pObject == nullptr)
		pObject = pApi;
	p->pObject = pObject;
}


FTDC2C_API void* MYDECL MdCreateApi(const char* pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast) {
	return new Quoter((char*)pszFlowPath, bIsUsingUdp, bIsMulticast);
}

FTDC2C_API const char* MYDECL MdGetApiVersion() {
	return CThostFtdcMdApi::GetApiVersion();
}

FTDC2C_API void MYDECL MdInit(void* pApi) {
	(static_cast<Quoter*>(pApi))->RawApi->Init();
}

FTDC2C_API const char* MYDECL MdGetTradingDay(void* pApi) {
	return (static_cast<Quoter*>(pApi))->RawApi->GetTradingDay();
}

FTDC2C_API void MYDECL MdRegisterFront(void* pApi, const char* pszFrontAddress) {
	(static_cast<Quoter*>(pApi))->RawApi->RegisterFront((char*)pszFrontAddress);
}

FTDC2C_API void MYDECL MdRegisterNameServer(void* pApi, const char* pszNsAddress) {
	(static_cast<Quoter*>(pApi))->RawApi->RegisterNameServer((char*)pszNsAddress);
}

FTDC2C_API void MYDECL MdRegisterFensUserInfo(void* pApi, const CThostFtdcFensUserInfoField* pFensUserInfo) {
	(static_cast<Quoter*>(pApi))->RawApi->RegisterFensUserInfo((CThostFtdcFensUserInfoField*)pFensUserInfo);
}

FTDC2C_API int MYDECL MdSubscribeMarketData(void* pApi, const char* ppInstrumentID[], int nCount) {
	return (static_cast<Quoter*>(pApi))->RawApi->SubscribeMarketData((char**)ppInstrumentID, nCount);
}

FTDC2C_API int MYDECL MdUnSubscribeMarketData(void* pApi, const char* ppInstrumentID[], int nCount) {
	return (static_cast<Quoter*>(pApi))->RawApi->UnSubscribeMarketData((char**)ppInstrumentID, nCount);
}

FTDC2C_API int MYDECL MdSubscribeForQuoteRsp(void* pApi, const char* ppInstrumentID[], int nCount) {
	return (static_cast<Quoter*>(pApi))->RawApi->SubscribeForQuoteRsp((char**)ppInstrumentID, nCount);
}

FTDC2C_API int MYDECL MdUnSubscribeForQuoteRsp(void* pApi, const char* ppInstrumentID[], int nCount) {
	return (static_cast<Quoter*>(pApi))->RawApi->UnSubscribeForQuoteRsp((char**)ppInstrumentID, nCount);
}

FTDC2C_API int MYDECL MdReqUserLogin(void* pApi, const CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID) {
	return (static_cast<Quoter*>(pApi))->RawApi->ReqUserLogin((CThostFtdcReqUserLoginField*)pReqUserLoginField, nRequestID);
}

FTDC2C_API int MYDECL MdReqUserLogout(void* pApi, const CThostFtdcUserLogoutField* pUserLogout, int nRequestID) {
	return (static_cast<Quoter*>(pApi))->RawApi->ReqUserLogout((CThostFtdcUserLogoutField*)pUserLogout, nRequestID);
}

FTDC2C_API int MYDECL MdReqQryMulticastInstrument(void* pApi, const CThostFtdcQryMulticastInstrumentField* pQryMulticastInstrument, int nRequestID) {
	return (static_cast<Quoter*>(pApi))->RawApi->ReqQryMulticastInstrument((CThostFtdcQryMulticastInstrumentField*)pQryMulticastInstrument, nRequestID);
}

FTDC2C_API void MYDECL TdDestroyApi(void* pApi) {
	delete static_cast<Trader*>(pApi);
}
FTDC2C_API void* MYDECL TdSetObject(void* pApi, void* pObject) {
	void* old = static_cast<Trader*>(pApi)->pObject;
	static_cast<Trader*>(pApi)->pObject = pObject;
	return old;
}

FTDC2C_API void MYDECL TdRegisterCallback(void* pApi, CbOnErrRtnEvent c1, CbOnFrontEvent c2, CbOnRspEvent c3, CbOnRtnEvent c4, void* pObject) {
	Trader* p = static_cast<Trader*>(pApi);
	p->mOnErrRtnEvent = c1;
	p->mOnFrontEvent = c2;
	p->mOnRspEvent = c3;
	p->mOnRtnEvent = c4;
	if (pObject == nullptr)
		pObject = pApi;
	p->pObject = pObject;
}


FTDC2C_API void* MYDECL TdCreateApi(const char* pszFlowPath) {
	return new Trader((char*)pszFlowPath);
}

FTDC2C_API const char* MYDECL TdGetApiVersion() {
	return CThostFtdcTraderApi::GetApiVersion();
}

FTDC2C_API void MYDECL TdInit(void* pApi) {
	(static_cast<Trader*>(pApi))->RawApi->Init();
}

FTDC2C_API const char* MYDECL TdGetTradingDay(void* pApi) {
	return (static_cast<Trader*>(pApi))->RawApi->GetTradingDay();
}

FTDC2C_API void MYDECL TdRegisterFront(void* pApi, const char* pszFrontAddress) {
	(static_cast<Trader*>(pApi))->RawApi->RegisterFront((char*)pszFrontAddress);
}

FTDC2C_API void MYDECL TdRegisterNameServer(void* pApi, const char* pszNsAddress) {
	(static_cast<Trader*>(pApi))->RawApi->RegisterNameServer((char*)pszNsAddress);
}

FTDC2C_API void MYDECL TdRegisterFensUserInfo(void* pApi, const CThostFtdcFensUserInfoField* pFensUserInfo) {
	(static_cast<Trader*>(pApi))->RawApi->RegisterFensUserInfo((CThostFtdcFensUserInfoField*)pFensUserInfo);
}

FTDC2C_API void MYDECL TdSubscribePrivateTopic(void* pApi, THOST_TE_RESUME_TYPE nResumeType) {
	(static_cast<Trader*>(pApi))->RawApi->SubscribePrivateTopic(nResumeType);
}

FTDC2C_API void MYDECL TdSubscribePublicTopic(void* pApi, THOST_TE_RESUME_TYPE nResumeType) {
	(static_cast<Trader*>(pApi))->RawApi->SubscribePublicTopic(nResumeType);
}

FTDC2C_API int MYDECL TdReqAuthenticate(void* pApi, const CThostFtdcReqAuthenticateField* pReqAuthenticateField, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqAuthenticate((CThostFtdcReqAuthenticateField*)pReqAuthenticateField, nRequestID);
}

FTDC2C_API int MYDECL TdRegisterUserSystemInfo(void* pApi, const CThostFtdcUserSystemInfoField* pUserSystemInfo) {
	return (static_cast<Trader*>(pApi))->RawApi->RegisterUserSystemInfo((CThostFtdcUserSystemInfoField*)pUserSystemInfo);
}

FTDC2C_API int MYDECL TdSubmitUserSystemInfo(void* pApi, const CThostFtdcUserSystemInfoField* pUserSystemInfo) {
	return (static_cast<Trader*>(pApi))->RawApi->SubmitUserSystemInfo((CThostFtdcUserSystemInfoField*)pUserSystemInfo);
}

FTDC2C_API int MYDECL TdReqUserLogin(void* pApi, const CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqUserLogin((CThostFtdcReqUserLoginField*)pReqUserLoginField, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserLogout(void* pApi, const CThostFtdcUserLogoutField* pUserLogout, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqUserLogout((CThostFtdcUserLogoutField*)pUserLogout, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserPasswordUpdate(void* pApi, const CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqUserPasswordUpdate((CThostFtdcUserPasswordUpdateField*)pUserPasswordUpdate, nRequestID);
}

FTDC2C_API int MYDECL TdReqTradingAccountPasswordUpdate(void* pApi, const CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqTradingAccountPasswordUpdate((CThostFtdcTradingAccountPasswordUpdateField*)pTradingAccountPasswordUpdate, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserAuthMethod(void* pApi, const CThostFtdcReqUserAuthMethodField* pReqUserAuthMethod, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqUserAuthMethod((CThostFtdcReqUserAuthMethodField*)pReqUserAuthMethod, nRequestID);
}

FTDC2C_API int MYDECL TdReqGenUserCaptcha(void* pApi, const CThostFtdcReqGenUserCaptchaField* pReqGenUserCaptcha, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqGenUserCaptcha((CThostFtdcReqGenUserCaptchaField*)pReqGenUserCaptcha, nRequestID);
}

FTDC2C_API int MYDECL TdReqGenUserText(void* pApi, const CThostFtdcReqGenUserTextField* pReqGenUserText, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqGenUserText((CThostFtdcReqGenUserTextField*)pReqGenUserText, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserLoginWithCaptcha(void* pApi, const CThostFtdcReqUserLoginWithCaptchaField* pReqUserLoginWithCaptcha, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqUserLoginWithCaptcha((CThostFtdcReqUserLoginWithCaptchaField*)pReqUserLoginWithCaptcha, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserLoginWithText(void* pApi, const CThostFtdcReqUserLoginWithTextField* pReqUserLoginWithText, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqUserLoginWithText((CThostFtdcReqUserLoginWithTextField*)pReqUserLoginWithText, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserLoginWithOTP(void* pApi, const CThostFtdcReqUserLoginWithOTPField* pReqUserLoginWithOTP, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqUserLoginWithOTP((CThostFtdcReqUserLoginWithOTPField*)pReqUserLoginWithOTP, nRequestID);
}

FTDC2C_API int MYDECL TdReqOrderInsert(void* pApi, const CThostFtdcInputOrderField* pInputOrder, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqOrderInsert((CThostFtdcInputOrderField*)pInputOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqParkedOrderInsert(void* pApi, const CThostFtdcParkedOrderField* pParkedOrder, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqParkedOrderInsert((CThostFtdcParkedOrderField*)pParkedOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqParkedOrderAction(void* pApi, const CThostFtdcParkedOrderActionField* pParkedOrderAction, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqParkedOrderAction((CThostFtdcParkedOrderActionField*)pParkedOrderAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqOrderAction(void* pApi, const CThostFtdcInputOrderActionField* pInputOrderAction, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqOrderAction((CThostFtdcInputOrderActionField*)pInputOrderAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryMaxOrderVolume(void* pApi, const CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryMaxOrderVolume((CThostFtdcQryMaxOrderVolumeField*)pQryMaxOrderVolume, nRequestID);
}

FTDC2C_API int MYDECL TdReqSettlementInfoConfirm(void* pApi, const CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqSettlementInfoConfirm((CThostFtdcSettlementInfoConfirmField*)pSettlementInfoConfirm, nRequestID);
}

FTDC2C_API int MYDECL TdReqRemoveParkedOrder(void* pApi, const CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqRemoveParkedOrder((CThostFtdcRemoveParkedOrderField*)pRemoveParkedOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqRemoveParkedOrderAction(void* pApi, const CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqRemoveParkedOrderAction((CThostFtdcRemoveParkedOrderActionField*)pRemoveParkedOrderAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqExecOrderInsert(void* pApi, const CThostFtdcInputExecOrderField* pInputExecOrder, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqExecOrderInsert((CThostFtdcInputExecOrderField*)pInputExecOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqExecOrderAction(void* pApi, const CThostFtdcInputExecOrderActionField* pInputExecOrderAction, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqExecOrderAction((CThostFtdcInputExecOrderActionField*)pInputExecOrderAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqForQuoteInsert(void* pApi, const CThostFtdcInputForQuoteField* pInputForQuote, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqForQuoteInsert((CThostFtdcInputForQuoteField*)pInputForQuote, nRequestID);
}

FTDC2C_API int MYDECL TdReqQuoteInsert(void* pApi, const CThostFtdcInputQuoteField* pInputQuote, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQuoteInsert((CThostFtdcInputQuoteField*)pInputQuote, nRequestID);
}

FTDC2C_API int MYDECL TdReqQuoteAction(void* pApi, const CThostFtdcInputQuoteActionField* pInputQuoteAction, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQuoteAction((CThostFtdcInputQuoteActionField*)pInputQuoteAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqBatchOrderAction(void* pApi, const CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqBatchOrderAction((CThostFtdcInputBatchOrderActionField*)pInputBatchOrderAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqOptionSelfCloseInsert(void* pApi, const CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqOptionSelfCloseInsert((CThostFtdcInputOptionSelfCloseField*)pInputOptionSelfClose, nRequestID);
}

FTDC2C_API int MYDECL TdReqOptionSelfCloseAction(void* pApi, const CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqOptionSelfCloseAction((CThostFtdcInputOptionSelfCloseActionField*)pInputOptionSelfCloseAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqCombActionInsert(void* pApi, const CThostFtdcInputCombActionField* pInputCombAction, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqCombActionInsert((CThostFtdcInputCombActionField*)pInputCombAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryOrder(void* pApi, const CThostFtdcQryOrderField* pQryOrder, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryOrder((CThostFtdcQryOrderField*)pQryOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTrade(void* pApi, const CThostFtdcQryTradeField* pQryTrade, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryTrade((CThostFtdcQryTradeField*)pQryTrade, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorPosition(void* pApi, const CThostFtdcQryInvestorPositionField* pQryInvestorPosition, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestorPosition((CThostFtdcQryInvestorPositionField*)pQryInvestorPosition, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTradingAccount(void* pApi, const CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryTradingAccount((CThostFtdcQryTradingAccountField*)pQryTradingAccount, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestor(void* pApi, const CThostFtdcQryInvestorField* pQryInvestor, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestor((CThostFtdcQryInvestorField*)pQryInvestor, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTradingCode(void* pApi, const CThostFtdcQryTradingCodeField* pQryTradingCode, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryTradingCode((CThostFtdcQryTradingCodeField*)pQryTradingCode, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInstrumentMarginRate(void* pApi, const CThostFtdcQryInstrumentMarginRateField* pQryInstrumentMarginRate, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInstrumentMarginRate((CThostFtdcQryInstrumentMarginRateField*)pQryInstrumentMarginRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInstrumentCommissionRate(void* pApi, const CThostFtdcQryInstrumentCommissionRateField* pQryInstrumentCommissionRate, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInstrumentCommissionRate((CThostFtdcQryInstrumentCommissionRateField*)pQryInstrumentCommissionRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryExchange(void* pApi, const CThostFtdcQryExchangeField* pQryExchange, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryExchange((CThostFtdcQryExchangeField*)pQryExchange, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryProduct(void* pApi, const CThostFtdcQryProductField* pQryProduct, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryProduct((CThostFtdcQryProductField*)pQryProduct, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInstrument(void* pApi, const CThostFtdcQryInstrumentField* pQryInstrument, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInstrument((CThostFtdcQryInstrumentField*)pQryInstrument, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryDepthMarketData(void* pApi, const CThostFtdcQryDepthMarketDataField* pQryDepthMarketData, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryDepthMarketData((CThostFtdcQryDepthMarketDataField*)pQryDepthMarketData, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTraderOffer(void* pApi, const CThostFtdcQryTraderOfferField* pQryTraderOffer, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryTraderOffer((CThostFtdcQryTraderOfferField*)pQryTraderOffer, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySettlementInfo(void* pApi, const CThostFtdcQrySettlementInfoField* pQrySettlementInfo, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQrySettlementInfo((CThostFtdcQrySettlementInfoField*)pQrySettlementInfo, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTransferBank(void* pApi, const CThostFtdcQryTransferBankField* pQryTransferBank, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryTransferBank((CThostFtdcQryTransferBankField*)pQryTransferBank, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorPositionDetail(void* pApi, const CThostFtdcQryInvestorPositionDetailField* pQryInvestorPositionDetail, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestorPositionDetail((CThostFtdcQryInvestorPositionDetailField*)pQryInvestorPositionDetail, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryNotice(void* pApi, const CThostFtdcQryNoticeField* pQryNotice, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryNotice((CThostFtdcQryNoticeField*)pQryNotice, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySettlementInfoConfirm(void* pApi, const CThostFtdcQrySettlementInfoConfirmField* pQrySettlementInfoConfirm, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQrySettlementInfoConfirm((CThostFtdcQrySettlementInfoConfirmField*)pQrySettlementInfoConfirm, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorPositionCombineDetail(void* pApi, const CThostFtdcQryInvestorPositionCombineDetailField* pQryInvestorPositionCombineDetail, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestorPositionCombineDetail((CThostFtdcQryInvestorPositionCombineDetailField*)pQryInvestorPositionCombineDetail, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCFMMCTradingAccountKey(void* pApi, const CThostFtdcQryCFMMCTradingAccountKeyField* pQryCFMMCTradingAccountKey, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryCFMMCTradingAccountKey((CThostFtdcQryCFMMCTradingAccountKeyField*)pQryCFMMCTradingAccountKey, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryEWarrantOffset(void* pApi, const CThostFtdcQryEWarrantOffsetField* pQryEWarrantOffset, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryEWarrantOffset((CThostFtdcQryEWarrantOffsetField*)pQryEWarrantOffset, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorProductGroupMargin(void* pApi, const CThostFtdcQryInvestorProductGroupMarginField* pQryInvestorProductGroupMargin, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestorProductGroupMargin((CThostFtdcQryInvestorProductGroupMarginField*)pQryInvestorProductGroupMargin, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryExchangeMarginRate(void* pApi, const CThostFtdcQryExchangeMarginRateField* pQryExchangeMarginRate, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryExchangeMarginRate((CThostFtdcQryExchangeMarginRateField*)pQryExchangeMarginRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryExchangeMarginRateAdjust(void* pApi, const CThostFtdcQryExchangeMarginRateAdjustField* pQryExchangeMarginRateAdjust, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryExchangeMarginRateAdjust((CThostFtdcQryExchangeMarginRateAdjustField*)pQryExchangeMarginRateAdjust, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryExchangeRate(void* pApi, const CThostFtdcQryExchangeRateField* pQryExchangeRate, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryExchangeRate((CThostFtdcQryExchangeRateField*)pQryExchangeRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySecAgentACIDMap(void* pApi, const CThostFtdcQrySecAgentACIDMapField* pQrySecAgentACIDMap, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQrySecAgentACIDMap((CThostFtdcQrySecAgentACIDMapField*)pQrySecAgentACIDMap, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryProductExchRate(void* pApi, const CThostFtdcQryProductExchRateField* pQryProductExchRate, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryProductExchRate((CThostFtdcQryProductExchRateField*)pQryProductExchRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryProductGroup(void* pApi, const CThostFtdcQryProductGroupField* pQryProductGroup, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryProductGroup((CThostFtdcQryProductGroupField*)pQryProductGroup, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryMMInstrumentCommissionRate(void* pApi, const CThostFtdcQryMMInstrumentCommissionRateField* pQryMMInstrumentCommissionRate, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryMMInstrumentCommissionRate((CThostFtdcQryMMInstrumentCommissionRateField*)pQryMMInstrumentCommissionRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryMMOptionInstrCommRate(void* pApi, const CThostFtdcQryMMOptionInstrCommRateField* pQryMMOptionInstrCommRate, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryMMOptionInstrCommRate((CThostFtdcQryMMOptionInstrCommRateField*)pQryMMOptionInstrCommRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInstrumentOrderCommRate(void* pApi, const CThostFtdcQryInstrumentOrderCommRateField* pQryInstrumentOrderCommRate, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInstrumentOrderCommRate((CThostFtdcQryInstrumentOrderCommRateField*)pQryInstrumentOrderCommRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySecAgentTradingAccount(void* pApi, const CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQrySecAgentTradingAccount((CThostFtdcQryTradingAccountField*)pQryTradingAccount, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySecAgentCheckMode(void* pApi, const CThostFtdcQrySecAgentCheckModeField* pQrySecAgentCheckMode, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQrySecAgentCheckMode((CThostFtdcQrySecAgentCheckModeField*)pQrySecAgentCheckMode, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySecAgentTradeInfo(void* pApi, const CThostFtdcQrySecAgentTradeInfoField* pQrySecAgentTradeInfo, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQrySecAgentTradeInfo((CThostFtdcQrySecAgentTradeInfoField*)pQrySecAgentTradeInfo, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryOptionInstrTradeCost(void* pApi, const CThostFtdcQryOptionInstrTradeCostField* pQryOptionInstrTradeCost, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryOptionInstrTradeCost((CThostFtdcQryOptionInstrTradeCostField*)pQryOptionInstrTradeCost, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryOptionInstrCommRate(void* pApi, const CThostFtdcQryOptionInstrCommRateField* pQryOptionInstrCommRate, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryOptionInstrCommRate((CThostFtdcQryOptionInstrCommRateField*)pQryOptionInstrCommRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryExecOrder(void* pApi, const CThostFtdcQryExecOrderField* pQryExecOrder, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryExecOrder((CThostFtdcQryExecOrderField*)pQryExecOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryForQuote(void* pApi, const CThostFtdcQryForQuoteField* pQryForQuote, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryForQuote((CThostFtdcQryForQuoteField*)pQryForQuote, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryQuote(void* pApi, const CThostFtdcQryQuoteField* pQryQuote, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryQuote((CThostFtdcQryQuoteField*)pQryQuote, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryOptionSelfClose(void* pApi, const CThostFtdcQryOptionSelfCloseField* pQryOptionSelfClose, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryOptionSelfClose((CThostFtdcQryOptionSelfCloseField*)pQryOptionSelfClose, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestUnit(void* pApi, const CThostFtdcQryInvestUnitField* pQryInvestUnit, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestUnit((CThostFtdcQryInvestUnitField*)pQryInvestUnit, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCombInstrumentGuard(void* pApi, const CThostFtdcQryCombInstrumentGuardField* pQryCombInstrumentGuard, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryCombInstrumentGuard((CThostFtdcQryCombInstrumentGuardField*)pQryCombInstrumentGuard, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCombAction(void* pApi, const CThostFtdcQryCombActionField* pQryCombAction, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryCombAction((CThostFtdcQryCombActionField*)pQryCombAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTransferSerial(void* pApi, const CThostFtdcQryTransferSerialField* pQryTransferSerial, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryTransferSerial((CThostFtdcQryTransferSerialField*)pQryTransferSerial, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryAccountregister(void* pApi, const CThostFtdcQryAccountregisterField* pQryAccountregister, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryAccountregister((CThostFtdcQryAccountregisterField*)pQryAccountregister, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryContractBank(void* pApi, const CThostFtdcQryContractBankField* pQryContractBank, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryContractBank((CThostFtdcQryContractBankField*)pQryContractBank, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryParkedOrder(void* pApi, const CThostFtdcQryParkedOrderField* pQryParkedOrder, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryParkedOrder((CThostFtdcQryParkedOrderField*)pQryParkedOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryParkedOrderAction(void* pApi, const CThostFtdcQryParkedOrderActionField* pQryParkedOrderAction, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryParkedOrderAction((CThostFtdcQryParkedOrderActionField*)pQryParkedOrderAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTradingNotice(void* pApi, const CThostFtdcQryTradingNoticeField* pQryTradingNotice, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryTradingNotice((CThostFtdcQryTradingNoticeField*)pQryTradingNotice, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryBrokerTradingParams(void* pApi, const CThostFtdcQryBrokerTradingParamsField* pQryBrokerTradingParams, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryBrokerTradingParams((CThostFtdcQryBrokerTradingParamsField*)pQryBrokerTradingParams, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryBrokerTradingAlgos(void* pApi, const CThostFtdcQryBrokerTradingAlgosField* pQryBrokerTradingAlgos, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryBrokerTradingAlgos((CThostFtdcQryBrokerTradingAlgosField*)pQryBrokerTradingAlgos, nRequestID);
}

FTDC2C_API int MYDECL TdReqQueryCFMMCTradingAccountToken(void* pApi, const CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQueryCFMMCTradingAccountToken((CThostFtdcQueryCFMMCTradingAccountTokenField*)pQueryCFMMCTradingAccountToken, nRequestID);
}

FTDC2C_API int MYDECL TdReqFromBankToFutureByFuture(void* pApi, const CThostFtdcReqTransferField* pReqTransfer, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqFromBankToFutureByFuture((CThostFtdcReqTransferField*)pReqTransfer, nRequestID);
}

FTDC2C_API int MYDECL TdReqFromFutureToBankByFuture(void* pApi, const CThostFtdcReqTransferField* pReqTransfer, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqFromFutureToBankByFuture((CThostFtdcReqTransferField*)pReqTransfer, nRequestID);
}

FTDC2C_API int MYDECL TdReqQueryBankAccountMoneyByFuture(void* pApi, const CThostFtdcReqQueryAccountField* pReqQueryAccount, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQueryBankAccountMoneyByFuture((CThostFtdcReqQueryAccountField*)pReqQueryAccount, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryClassifiedInstrument(void* pApi, const CThostFtdcQryClassifiedInstrumentField* pQryClassifiedInstrument, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryClassifiedInstrument((CThostFtdcQryClassifiedInstrumentField*)pQryClassifiedInstrument, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCombPromotionParam(void* pApi, const CThostFtdcQryCombPromotionParamField* pQryCombPromotionParam, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryCombPromotionParam((CThostFtdcQryCombPromotionParamField*)pQryCombPromotionParam, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryRiskSettleInvstPosition(void* pApi, const CThostFtdcQryRiskSettleInvstPositionField* pQryRiskSettleInvstPosition, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryRiskSettleInvstPosition((CThostFtdcQryRiskSettleInvstPositionField*)pQryRiskSettleInvstPosition, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryRiskSettleProductStatus(void* pApi, const CThostFtdcQryRiskSettleProductStatusField* pQryRiskSettleProductStatus, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryRiskSettleProductStatus((CThostFtdcQryRiskSettleProductStatusField*)pQryRiskSettleProductStatus, nRequestID);
}

