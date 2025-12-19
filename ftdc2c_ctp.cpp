/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com
/////////////////////////////////////////////////////////////////////////

#include "ftdc2c_ctp.h"
#include "quoter.h"
#include "trader.h"

FTDC2C_API void MYDECL MdDestroyApi(void* quoter) {
	delete static_cast<Quoter*>(quoter);
}
FTDC2C_API void* MYDECL MdSetUserObject(void* quoter, void* pUserObject) {
	void* old = static_cast<Quoter*>(quoter)->pUserObject;
	static_cast<Quoter*>(quoter)->pUserObject = pUserObject;
	return old;
}

FTDC2C_API void MYDECL MdRegisterCallback(void* quoter, CbOnFrontEvent c1, CbOnRspEvent c2, CbOnRtnEvent c3, void* pUserObject) {
	Quoter* p = static_cast<Quoter*>(quoter);
	p->mOnFrontEvent = c1;
	p->mOnRspEvent = c2;
	p->mOnRtnEvent = c3;
	if (pUserObject != nullptr)
		p->pUserObject = pUserObject;
}

FTDC2C_API void* MYDECL MdCreateApi(const char* pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast, bool bIsProductionMode) {
	return new Quoter((char*)pszFlowPath, bIsUsingUdp, bIsMulticast, bIsProductionMode);
}

FTDC2C_API const char* MYDECL MdGetApiVersion() {
	return CThostFtdcMdApi::GetApiVersion();
}

FTDC2C_API void MYDECL MdInit(void* quoter) {
	(static_cast<Quoter*>(quoter))->RawApi->Init();
}

FTDC2C_API const char* MYDECL MdGetTradingDay(void* quoter) {
	return (static_cast<Quoter*>(quoter))->RawApi->GetTradingDay();
}

FTDC2C_API void MYDECL MdRegisterFront(void* quoter, const char* pszFrontAddress) {
	(static_cast<Quoter*>(quoter))->RawApi->RegisterFront((char*)pszFrontAddress);
}

FTDC2C_API void MYDECL MdRegisterNameServer(void* quoter, const char* pszNsAddress) {
	(static_cast<Quoter*>(quoter))->RawApi->RegisterNameServer((char*)pszNsAddress);
}

FTDC2C_API void MYDECL MdRegisterFensUserInfo(void* quoter, const CThostFtdcFensUserInfoField* pFensUserInfo) {
	(static_cast<Quoter*>(quoter))->RawApi->RegisterFensUserInfo((CThostFtdcFensUserInfoField*)pFensUserInfo);
}

FTDC2C_API int MYDECL MdSubscribeMarketData(void* quoter, const char* ppInstrumentID[], int nCount) {
	return (static_cast<Quoter*>(quoter))->RawApi->SubscribeMarketData((char**)ppInstrumentID, nCount);
}

FTDC2C_API int MYDECL MdUnSubscribeMarketData(void* quoter, const char* ppInstrumentID[], int nCount) {
	return (static_cast<Quoter*>(quoter))->RawApi->UnSubscribeMarketData((char**)ppInstrumentID, nCount);
}

FTDC2C_API int MYDECL MdSubscribeForQuoteRsp(void* quoter, const char* ppInstrumentID[], int nCount) {
	return (static_cast<Quoter*>(quoter))->RawApi->SubscribeForQuoteRsp((char**)ppInstrumentID, nCount);
}

FTDC2C_API int MYDECL MdUnSubscribeForQuoteRsp(void* quoter, const char* ppInstrumentID[], int nCount) {
	return (static_cast<Quoter*>(quoter))->RawApi->UnSubscribeForQuoteRsp((char**)ppInstrumentID, nCount);
}

FTDC2C_API int MYDECL MdReqUserLogin(void* quoter, const CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID) {
	return (static_cast<Quoter*>(quoter))->RawApi->ReqUserLogin((CThostFtdcReqUserLoginField*)pReqUserLoginField, nRequestID);
}

FTDC2C_API int MYDECL MdReqUserLogout(void* quoter, const CThostFtdcUserLogoutField* pUserLogout, int nRequestID) {
	return (static_cast<Quoter*>(quoter))->RawApi->ReqUserLogout((CThostFtdcUserLogoutField*)pUserLogout, nRequestID);
}

FTDC2C_API int MYDECL MdReqQryMulticastInstrument(void* quoter, const CThostFtdcQryMulticastInstrumentField* pQryMulticastInstrument, int nRequestID) {
	return (static_cast<Quoter*>(quoter))->RawApi->ReqQryMulticastInstrument((CThostFtdcQryMulticastInstrumentField*)pQryMulticastInstrument, nRequestID);
}

FTDC2C_API void MYDECL TdDestroyApi(void* trader) {
	delete static_cast<Trader*>(trader);
}
FTDC2C_API void* MYDECL TdSetUserObject(void* trader, void* pUserObject) {
	void* old = static_cast<Trader*>(trader)->pUserObject;
	static_cast<Trader*>(trader)->pUserObject = pUserObject;
	return old;
}

FTDC2C_API void MYDECL TdRegisterCallback(void* trader, CbOnErrRtnEvent c1, CbOnFrontEvent c2, CbOnRspEvent c3, CbOnRtnEvent c4, void* pUserObject) {
	Trader* p = static_cast<Trader*>(trader);
	p->mOnErrRtnEvent = c1;
	p->mOnFrontEvent = c2;
	p->mOnRspEvent = c3;
	p->mOnRtnEvent = c4;
	if (pUserObject != nullptr)
		p->pUserObject = pUserObject;
}

FTDC2C_API void* MYDECL TdCreateApi(const char* pszFlowPath, bool bIsProductionMode) {
	return new Trader((char*)pszFlowPath, bIsProductionMode);
}

FTDC2C_API const char* MYDECL TdGetApiVersion() {
	return CThostFtdcTraderApi::GetApiVersion();
}

FTDC2C_API void MYDECL TdInit(void* trader) {
	(static_cast<Trader*>(trader))->RawApi->Init();
}

FTDC2C_API const char* MYDECL TdGetTradingDay(void* trader) {
	return (static_cast<Trader*>(trader))->RawApi->GetTradingDay();
}

FTDC2C_API void MYDECL TdGetFrontInfo(void* trader, const CThostFtdcFrontInfoField* pFrontInfo) {
	(static_cast<Trader*>(trader))->RawApi->GetFrontInfo((CThostFtdcFrontInfoField*)pFrontInfo);
}

FTDC2C_API void MYDECL TdRegisterFront(void* trader, const char* pszFrontAddress) {
	(static_cast<Trader*>(trader))->RawApi->RegisterFront((char*)pszFrontAddress);
}

FTDC2C_API void MYDECL TdRegisterNameServer(void* trader, const char* pszNsAddress) {
	(static_cast<Trader*>(trader))->RawApi->RegisterNameServer((char*)pszNsAddress);
}

FTDC2C_API void MYDECL TdRegisterFensUserInfo(void* trader, const CThostFtdcFensUserInfoField* pFensUserInfo) {
	(static_cast<Trader*>(trader))->RawApi->RegisterFensUserInfo((CThostFtdcFensUserInfoField*)pFensUserInfo);
}

FTDC2C_API void MYDECL TdSubscribePrivateTopic(void* trader, THOST_TE_RESUME_TYPE nResumeType) {
	(static_cast<Trader*>(trader))->RawApi->SubscribePrivateTopic(nResumeType);
}

FTDC2C_API void MYDECL TdSubscribePublicTopic(void* trader, THOST_TE_RESUME_TYPE nResumeType) {
	(static_cast<Trader*>(trader))->RawApi->SubscribePublicTopic(nResumeType);
}

FTDC2C_API int MYDECL TdReqAuthenticate(void* trader, const CThostFtdcReqAuthenticateField* pReqAuthenticateField, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqAuthenticate((CThostFtdcReqAuthenticateField*)pReqAuthenticateField, nRequestID);
}

FTDC2C_API int MYDECL TdRegisterUserSystemInfo(void* trader, const CThostFtdcUserSystemInfoField* pUserSystemInfo) {
	return (static_cast<Trader*>(trader))->RawApi->RegisterUserSystemInfo((CThostFtdcUserSystemInfoField*)pUserSystemInfo);
}

FTDC2C_API int MYDECL TdSubmitUserSystemInfo(void* trader, const CThostFtdcUserSystemInfoField* pUserSystemInfo) {
	return (static_cast<Trader*>(trader))->RawApi->SubmitUserSystemInfo((CThostFtdcUserSystemInfoField*)pUserSystemInfo);
}

FTDC2C_API int MYDECL TdRegisterWechatUserSystemInfo(void* trader, const CThostFtdcWechatUserSystemInfoField* pUserSystemInfo) {
	return (static_cast<Trader*>(trader))->RawApi->RegisterWechatUserSystemInfo((CThostFtdcWechatUserSystemInfoField*)pUserSystemInfo);
}

FTDC2C_API int MYDECL TdSubmitWechatUserSystemInfo(void* trader, const CThostFtdcWechatUserSystemInfoField* pUserSystemInfo) {
	return (static_cast<Trader*>(trader))->RawApi->SubmitWechatUserSystemInfo((CThostFtdcWechatUserSystemInfoField*)pUserSystemInfo);
}

FTDC2C_API int MYDECL TdReqUserLogin(void* trader, const CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqUserLogin((CThostFtdcReqUserLoginField*)pReqUserLoginField, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserLogout(void* trader, const CThostFtdcUserLogoutField* pUserLogout, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqUserLogout((CThostFtdcUserLogoutField*)pUserLogout, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserPasswordUpdate(void* trader, const CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqUserPasswordUpdate((CThostFtdcUserPasswordUpdateField*)pUserPasswordUpdate, nRequestID);
}

FTDC2C_API int MYDECL TdReqTradingAccountPasswordUpdate(void* trader, const CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqTradingAccountPasswordUpdate((CThostFtdcTradingAccountPasswordUpdateField*)pTradingAccountPasswordUpdate, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserAuthMethod(void* trader, const CThostFtdcReqUserAuthMethodField* pReqUserAuthMethod, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqUserAuthMethod((CThostFtdcReqUserAuthMethodField*)pReqUserAuthMethod, nRequestID);
}

FTDC2C_API int MYDECL TdReqGenUserCaptcha(void* trader, const CThostFtdcReqGenUserCaptchaField* pReqGenUserCaptcha, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqGenUserCaptcha((CThostFtdcReqGenUserCaptchaField*)pReqGenUserCaptcha, nRequestID);
}

FTDC2C_API int MYDECL TdReqGenUserText(void* trader, const CThostFtdcReqGenUserTextField* pReqGenUserText, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqGenUserText((CThostFtdcReqGenUserTextField*)pReqGenUserText, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserLoginWithCaptcha(void* trader, const CThostFtdcReqUserLoginWithCaptchaField* pReqUserLoginWithCaptcha, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqUserLoginWithCaptcha((CThostFtdcReqUserLoginWithCaptchaField*)pReqUserLoginWithCaptcha, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserLoginWithText(void* trader, const CThostFtdcReqUserLoginWithTextField* pReqUserLoginWithText, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqUserLoginWithText((CThostFtdcReqUserLoginWithTextField*)pReqUserLoginWithText, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserLoginWithOTP(void* trader, const CThostFtdcReqUserLoginWithOTPField* pReqUserLoginWithOTP, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqUserLoginWithOTP((CThostFtdcReqUserLoginWithOTPField*)pReqUserLoginWithOTP, nRequestID);
}

FTDC2C_API int MYDECL TdReqOrderInsert(void* trader, const CThostFtdcInputOrderField* pInputOrder, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqOrderInsert((CThostFtdcInputOrderField*)pInputOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqParkedOrderInsert(void* trader, const CThostFtdcParkedOrderField* pParkedOrder, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqParkedOrderInsert((CThostFtdcParkedOrderField*)pParkedOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqParkedOrderAction(void* trader, const CThostFtdcParkedOrderActionField* pParkedOrderAction, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqParkedOrderAction((CThostFtdcParkedOrderActionField*)pParkedOrderAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqOrderAction(void* trader, const CThostFtdcInputOrderActionField* pInputOrderAction, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqOrderAction((CThostFtdcInputOrderActionField*)pInputOrderAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryMaxOrderVolume(void* trader, const CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryMaxOrderVolume((CThostFtdcQryMaxOrderVolumeField*)pQryMaxOrderVolume, nRequestID);
}

FTDC2C_API int MYDECL TdReqSettlementInfoConfirm(void* trader, const CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqSettlementInfoConfirm((CThostFtdcSettlementInfoConfirmField*)pSettlementInfoConfirm, nRequestID);
}

FTDC2C_API int MYDECL TdReqRemoveParkedOrder(void* trader, const CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqRemoveParkedOrder((CThostFtdcRemoveParkedOrderField*)pRemoveParkedOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqRemoveParkedOrderAction(void* trader, const CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqRemoveParkedOrderAction((CThostFtdcRemoveParkedOrderActionField*)pRemoveParkedOrderAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqExecOrderInsert(void* trader, const CThostFtdcInputExecOrderField* pInputExecOrder, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqExecOrderInsert((CThostFtdcInputExecOrderField*)pInputExecOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqExecOrderAction(void* trader, const CThostFtdcInputExecOrderActionField* pInputExecOrderAction, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqExecOrderAction((CThostFtdcInputExecOrderActionField*)pInputExecOrderAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqForQuoteInsert(void* trader, const CThostFtdcInputForQuoteField* pInputForQuote, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqForQuoteInsert((CThostFtdcInputForQuoteField*)pInputForQuote, nRequestID);
}

FTDC2C_API int MYDECL TdReqQuoteInsert(void* trader, const CThostFtdcInputQuoteField* pInputQuote, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQuoteInsert((CThostFtdcInputQuoteField*)pInputQuote, nRequestID);
}

FTDC2C_API int MYDECL TdReqQuoteAction(void* trader, const CThostFtdcInputQuoteActionField* pInputQuoteAction, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQuoteAction((CThostFtdcInputQuoteActionField*)pInputQuoteAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqBatchOrderAction(void* trader, const CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqBatchOrderAction((CThostFtdcInputBatchOrderActionField*)pInputBatchOrderAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqOptionSelfCloseInsert(void* trader, const CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqOptionSelfCloseInsert((CThostFtdcInputOptionSelfCloseField*)pInputOptionSelfClose, nRequestID);
}

FTDC2C_API int MYDECL TdReqOptionSelfCloseAction(void* trader, const CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqOptionSelfCloseAction((CThostFtdcInputOptionSelfCloseActionField*)pInputOptionSelfCloseAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqCombActionInsert(void* trader, const CThostFtdcInputCombActionField* pInputCombAction, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqCombActionInsert((CThostFtdcInputCombActionField*)pInputCombAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryOrder(void* trader, const CThostFtdcQryOrderField* pQryOrder, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryOrder((CThostFtdcQryOrderField*)pQryOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTrade(void* trader, const CThostFtdcQryTradeField* pQryTrade, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryTrade((CThostFtdcQryTradeField*)pQryTrade, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorPosition(void* trader, const CThostFtdcQryInvestorPositionField* pQryInvestorPosition, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInvestorPosition((CThostFtdcQryInvestorPositionField*)pQryInvestorPosition, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTradingAccount(void* trader, const CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryTradingAccount((CThostFtdcQryTradingAccountField*)pQryTradingAccount, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestor(void* trader, const CThostFtdcQryInvestorField* pQryInvestor, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInvestor((CThostFtdcQryInvestorField*)pQryInvestor, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTradingCode(void* trader, const CThostFtdcQryTradingCodeField* pQryTradingCode, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryTradingCode((CThostFtdcQryTradingCodeField*)pQryTradingCode, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInstrumentMarginRate(void* trader, const CThostFtdcQryInstrumentMarginRateField* pQryInstrumentMarginRate, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInstrumentMarginRate((CThostFtdcQryInstrumentMarginRateField*)pQryInstrumentMarginRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInstrumentCommissionRate(void* trader, const CThostFtdcQryInstrumentCommissionRateField* pQryInstrumentCommissionRate, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInstrumentCommissionRate((CThostFtdcQryInstrumentCommissionRateField*)pQryInstrumentCommissionRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryUserSession(void* trader, const CThostFtdcQryUserSessionField* pQryUserSession, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryUserSession((CThostFtdcQryUserSessionField*)pQryUserSession, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryExchange(void* trader, const CThostFtdcQryExchangeField* pQryExchange, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryExchange((CThostFtdcQryExchangeField*)pQryExchange, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryProduct(void* trader, const CThostFtdcQryProductField* pQryProduct, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryProduct((CThostFtdcQryProductField*)pQryProduct, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInstrument(void* trader, const CThostFtdcQryInstrumentField* pQryInstrument, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInstrument((CThostFtdcQryInstrumentField*)pQryInstrument, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryDepthMarketData(void* trader, const CThostFtdcQryDepthMarketDataField* pQryDepthMarketData, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryDepthMarketData((CThostFtdcQryDepthMarketDataField*)pQryDepthMarketData, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTraderOffer(void* trader, const CThostFtdcQryTraderOfferField* pQryTraderOffer, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryTraderOffer((CThostFtdcQryTraderOfferField*)pQryTraderOffer, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySettlementInfo(void* trader, const CThostFtdcQrySettlementInfoField* pQrySettlementInfo, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQrySettlementInfo((CThostFtdcQrySettlementInfoField*)pQrySettlementInfo, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTransferBank(void* trader, const CThostFtdcQryTransferBankField* pQryTransferBank, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryTransferBank((CThostFtdcQryTransferBankField*)pQryTransferBank, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorPositionDetail(void* trader, const CThostFtdcQryInvestorPositionDetailField* pQryInvestorPositionDetail, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInvestorPositionDetail((CThostFtdcQryInvestorPositionDetailField*)pQryInvestorPositionDetail, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryNotice(void* trader, const CThostFtdcQryNoticeField* pQryNotice, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryNotice((CThostFtdcQryNoticeField*)pQryNotice, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySettlementInfoConfirm(void* trader, const CThostFtdcQrySettlementInfoConfirmField* pQrySettlementInfoConfirm, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQrySettlementInfoConfirm((CThostFtdcQrySettlementInfoConfirmField*)pQrySettlementInfoConfirm, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorPositionCombineDetail(void* trader, const CThostFtdcQryInvestorPositionCombineDetailField* pQryInvestorPositionCombineDetail, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInvestorPositionCombineDetail((CThostFtdcQryInvestorPositionCombineDetailField*)pQryInvestorPositionCombineDetail, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCFMMCTradingAccountKey(void* trader, const CThostFtdcQryCFMMCTradingAccountKeyField* pQryCFMMCTradingAccountKey, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryCFMMCTradingAccountKey((CThostFtdcQryCFMMCTradingAccountKeyField*)pQryCFMMCTradingAccountKey, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryEWarrantOffset(void* trader, const CThostFtdcQryEWarrantOffsetField* pQryEWarrantOffset, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryEWarrantOffset((CThostFtdcQryEWarrantOffsetField*)pQryEWarrantOffset, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorProductGroupMargin(void* trader, const CThostFtdcQryInvestorProductGroupMarginField* pQryInvestorProductGroupMargin, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInvestorProductGroupMargin((CThostFtdcQryInvestorProductGroupMarginField*)pQryInvestorProductGroupMargin, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryExchangeMarginRate(void* trader, const CThostFtdcQryExchangeMarginRateField* pQryExchangeMarginRate, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryExchangeMarginRate((CThostFtdcQryExchangeMarginRateField*)pQryExchangeMarginRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryExchangeMarginRateAdjust(void* trader, const CThostFtdcQryExchangeMarginRateAdjustField* pQryExchangeMarginRateAdjust, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryExchangeMarginRateAdjust((CThostFtdcQryExchangeMarginRateAdjustField*)pQryExchangeMarginRateAdjust, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryExchangeRate(void* trader, const CThostFtdcQryExchangeRateField* pQryExchangeRate, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryExchangeRate((CThostFtdcQryExchangeRateField*)pQryExchangeRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySecAgentACIDMap(void* trader, const CThostFtdcQrySecAgentACIDMapField* pQrySecAgentACIDMap, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQrySecAgentACIDMap((CThostFtdcQrySecAgentACIDMapField*)pQrySecAgentACIDMap, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryProductExchRate(void* trader, const CThostFtdcQryProductExchRateField* pQryProductExchRate, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryProductExchRate((CThostFtdcQryProductExchRateField*)pQryProductExchRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryProductGroup(void* trader, const CThostFtdcQryProductGroupField* pQryProductGroup, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryProductGroup((CThostFtdcQryProductGroupField*)pQryProductGroup, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryMMInstrumentCommissionRate(void* trader, const CThostFtdcQryMMInstrumentCommissionRateField* pQryMMInstrumentCommissionRate, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryMMInstrumentCommissionRate((CThostFtdcQryMMInstrumentCommissionRateField*)pQryMMInstrumentCommissionRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryMMOptionInstrCommRate(void* trader, const CThostFtdcQryMMOptionInstrCommRateField* pQryMMOptionInstrCommRate, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryMMOptionInstrCommRate((CThostFtdcQryMMOptionInstrCommRateField*)pQryMMOptionInstrCommRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInstrumentOrderCommRate(void* trader, const CThostFtdcQryInstrumentOrderCommRateField* pQryInstrumentOrderCommRate, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInstrumentOrderCommRate((CThostFtdcQryInstrumentOrderCommRateField*)pQryInstrumentOrderCommRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySecAgentTradingAccount(void* trader, const CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQrySecAgentTradingAccount((CThostFtdcQryTradingAccountField*)pQryTradingAccount, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySecAgentCheckMode(void* trader, const CThostFtdcQrySecAgentCheckModeField* pQrySecAgentCheckMode, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQrySecAgentCheckMode((CThostFtdcQrySecAgentCheckModeField*)pQrySecAgentCheckMode, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySecAgentTradeInfo(void* trader, const CThostFtdcQrySecAgentTradeInfoField* pQrySecAgentTradeInfo, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQrySecAgentTradeInfo((CThostFtdcQrySecAgentTradeInfoField*)pQrySecAgentTradeInfo, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryOptionInstrTradeCost(void* trader, const CThostFtdcQryOptionInstrTradeCostField* pQryOptionInstrTradeCost, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryOptionInstrTradeCost((CThostFtdcQryOptionInstrTradeCostField*)pQryOptionInstrTradeCost, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryOptionInstrCommRate(void* trader, const CThostFtdcQryOptionInstrCommRateField* pQryOptionInstrCommRate, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryOptionInstrCommRate((CThostFtdcQryOptionInstrCommRateField*)pQryOptionInstrCommRate, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryExecOrder(void* trader, const CThostFtdcQryExecOrderField* pQryExecOrder, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryExecOrder((CThostFtdcQryExecOrderField*)pQryExecOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryForQuote(void* trader, const CThostFtdcQryForQuoteField* pQryForQuote, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryForQuote((CThostFtdcQryForQuoteField*)pQryForQuote, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryQuote(void* trader, const CThostFtdcQryQuoteField* pQryQuote, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryQuote((CThostFtdcQryQuoteField*)pQryQuote, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryOptionSelfClose(void* trader, const CThostFtdcQryOptionSelfCloseField* pQryOptionSelfClose, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryOptionSelfClose((CThostFtdcQryOptionSelfCloseField*)pQryOptionSelfClose, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestUnit(void* trader, const CThostFtdcQryInvestUnitField* pQryInvestUnit, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInvestUnit((CThostFtdcQryInvestUnitField*)pQryInvestUnit, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCombInstrumentGuard(void* trader, const CThostFtdcQryCombInstrumentGuardField* pQryCombInstrumentGuard, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryCombInstrumentGuard((CThostFtdcQryCombInstrumentGuardField*)pQryCombInstrumentGuard, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCombAction(void* trader, const CThostFtdcQryCombActionField* pQryCombAction, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryCombAction((CThostFtdcQryCombActionField*)pQryCombAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTransferSerial(void* trader, const CThostFtdcQryTransferSerialField* pQryTransferSerial, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryTransferSerial((CThostFtdcQryTransferSerialField*)pQryTransferSerial, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryAccountregister(void* trader, const CThostFtdcQryAccountregisterField* pQryAccountregister, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryAccountregister((CThostFtdcQryAccountregisterField*)pQryAccountregister, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryContractBank(void* trader, const CThostFtdcQryContractBankField* pQryContractBank, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryContractBank((CThostFtdcQryContractBankField*)pQryContractBank, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryParkedOrder(void* trader, const CThostFtdcQryParkedOrderField* pQryParkedOrder, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryParkedOrder((CThostFtdcQryParkedOrderField*)pQryParkedOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryParkedOrderAction(void* trader, const CThostFtdcQryParkedOrderActionField* pQryParkedOrderAction, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryParkedOrderAction((CThostFtdcQryParkedOrderActionField*)pQryParkedOrderAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTradingNotice(void* trader, const CThostFtdcQryTradingNoticeField* pQryTradingNotice, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryTradingNotice((CThostFtdcQryTradingNoticeField*)pQryTradingNotice, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryBrokerTradingParams(void* trader, const CThostFtdcQryBrokerTradingParamsField* pQryBrokerTradingParams, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryBrokerTradingParams((CThostFtdcQryBrokerTradingParamsField*)pQryBrokerTradingParams, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryBrokerTradingAlgos(void* trader, const CThostFtdcQryBrokerTradingAlgosField* pQryBrokerTradingAlgos, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryBrokerTradingAlgos((CThostFtdcQryBrokerTradingAlgosField*)pQryBrokerTradingAlgos, nRequestID);
}

FTDC2C_API int MYDECL TdReqQueryCFMMCTradingAccountToken(void* trader, const CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQueryCFMMCTradingAccountToken((CThostFtdcQueryCFMMCTradingAccountTokenField*)pQueryCFMMCTradingAccountToken, nRequestID);
}

FTDC2C_API int MYDECL TdReqFromBankToFutureByFuture(void* trader, const CThostFtdcReqTransferField* pReqTransfer, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqFromBankToFutureByFuture((CThostFtdcReqTransferField*)pReqTransfer, nRequestID);
}

FTDC2C_API int MYDECL TdReqFromFutureToBankByFuture(void* trader, const CThostFtdcReqTransferField* pReqTransfer, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqFromFutureToBankByFuture((CThostFtdcReqTransferField*)pReqTransfer, nRequestID);
}

FTDC2C_API int MYDECL TdReqQueryBankAccountMoneyByFuture(void* trader, const CThostFtdcReqQueryAccountField* pReqQueryAccount, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQueryBankAccountMoneyByFuture((CThostFtdcReqQueryAccountField*)pReqQueryAccount, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryClassifiedInstrument(void* trader, const CThostFtdcQryClassifiedInstrumentField* pQryClassifiedInstrument, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryClassifiedInstrument((CThostFtdcQryClassifiedInstrumentField*)pQryClassifiedInstrument, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCombPromotionParam(void* trader, const CThostFtdcQryCombPromotionParamField* pQryCombPromotionParam, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryCombPromotionParam((CThostFtdcQryCombPromotionParamField*)pQryCombPromotionParam, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryRiskSettleInvstPosition(void* trader, const CThostFtdcQryRiskSettleInvstPositionField* pQryRiskSettleInvstPosition, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryRiskSettleInvstPosition((CThostFtdcQryRiskSettleInvstPositionField*)pQryRiskSettleInvstPosition, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryRiskSettleProductStatus(void* trader, const CThostFtdcQryRiskSettleProductStatusField* pQryRiskSettleProductStatus, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryRiskSettleProductStatus((CThostFtdcQryRiskSettleProductStatusField*)pQryRiskSettleProductStatus, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySPBMFutureParameter(void* trader, const CThostFtdcQrySPBMFutureParameterField* pQrySPBMFutureParameter, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQrySPBMFutureParameter((CThostFtdcQrySPBMFutureParameterField*)pQrySPBMFutureParameter, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySPBMOptionParameter(void* trader, const CThostFtdcQrySPBMOptionParameterField* pQrySPBMOptionParameter, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQrySPBMOptionParameter((CThostFtdcQrySPBMOptionParameterField*)pQrySPBMOptionParameter, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySPBMIntraParameter(void* trader, const CThostFtdcQrySPBMIntraParameterField* pQrySPBMIntraParameter, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQrySPBMIntraParameter((CThostFtdcQrySPBMIntraParameterField*)pQrySPBMIntraParameter, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySPBMInterParameter(void* trader, const CThostFtdcQrySPBMInterParameterField* pQrySPBMInterParameter, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQrySPBMInterParameter((CThostFtdcQrySPBMInterParameterField*)pQrySPBMInterParameter, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySPBMPortfDefinition(void* trader, const CThostFtdcQrySPBMPortfDefinitionField* pQrySPBMPortfDefinition, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQrySPBMPortfDefinition((CThostFtdcQrySPBMPortfDefinitionField*)pQrySPBMPortfDefinition, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySPBMInvestorPortfDef(void* trader, const CThostFtdcQrySPBMInvestorPortfDefField* pQrySPBMInvestorPortfDef, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQrySPBMInvestorPortfDef((CThostFtdcQrySPBMInvestorPortfDefField*)pQrySPBMInvestorPortfDef, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorPortfMarginRatio(void* trader, const CThostFtdcQryInvestorPortfMarginRatioField* pQryInvestorPortfMarginRatio, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInvestorPortfMarginRatio((CThostFtdcQryInvestorPortfMarginRatioField*)pQryInvestorPortfMarginRatio, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorProdSPBMDetail(void* trader, const CThostFtdcQryInvestorProdSPBMDetailField* pQryInvestorProdSPBMDetail, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInvestorProdSPBMDetail((CThostFtdcQryInvestorProdSPBMDetailField*)pQryInvestorProdSPBMDetail, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorCommoditySPMMMargin(void* trader, const CThostFtdcQryInvestorCommoditySPMMMarginField* pQryInvestorCommoditySPMMMargin, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInvestorCommoditySPMMMargin((CThostFtdcQryInvestorCommoditySPMMMarginField*)pQryInvestorCommoditySPMMMargin, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorCommodityGroupSPMMMargin(void* trader, const CThostFtdcQryInvestorCommodityGroupSPMMMarginField* pQryInvestorCommodityGroupSPMMMargin, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInvestorCommodityGroupSPMMMargin((CThostFtdcQryInvestorCommodityGroupSPMMMarginField*)pQryInvestorCommodityGroupSPMMMargin, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySPMMInstParam(void* trader, const CThostFtdcQrySPMMInstParamField* pQrySPMMInstParam, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQrySPMMInstParam((CThostFtdcQrySPMMInstParamField*)pQrySPMMInstParam, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySPMMProductParam(void* trader, const CThostFtdcQrySPMMProductParamField* pQrySPMMProductParam, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQrySPMMProductParam((CThostFtdcQrySPMMProductParamField*)pQrySPMMProductParam, nRequestID);
}

FTDC2C_API int MYDECL TdReqQrySPBMAddOnInterParameter(void* trader, const CThostFtdcQrySPBMAddOnInterParameterField* pQrySPBMAddOnInterParameter, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQrySPBMAddOnInterParameter((CThostFtdcQrySPBMAddOnInterParameterField*)pQrySPBMAddOnInterParameter, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryRCAMSCombProductInfo(void* trader, const CThostFtdcQryRCAMSCombProductInfoField* pQryRCAMSCombProductInfo, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryRCAMSCombProductInfo((CThostFtdcQryRCAMSCombProductInfoField*)pQryRCAMSCombProductInfo, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryRCAMSInstrParameter(void* trader, const CThostFtdcQryRCAMSInstrParameterField* pQryRCAMSInstrParameter, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryRCAMSInstrParameter((CThostFtdcQryRCAMSInstrParameterField*)pQryRCAMSInstrParameter, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryRCAMSIntraParameter(void* trader, const CThostFtdcQryRCAMSIntraParameterField* pQryRCAMSIntraParameter, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryRCAMSIntraParameter((CThostFtdcQryRCAMSIntraParameterField*)pQryRCAMSIntraParameter, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryRCAMSInterParameter(void* trader, const CThostFtdcQryRCAMSInterParameterField* pQryRCAMSInterParameter, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryRCAMSInterParameter((CThostFtdcQryRCAMSInterParameterField*)pQryRCAMSInterParameter, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryRCAMSShortOptAdjustParam(void* trader, const CThostFtdcQryRCAMSShortOptAdjustParamField* pQryRCAMSShortOptAdjustParam, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryRCAMSShortOptAdjustParam((CThostFtdcQryRCAMSShortOptAdjustParamField*)pQryRCAMSShortOptAdjustParam, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryRCAMSInvestorCombPosition(void* trader, const CThostFtdcQryRCAMSInvestorCombPositionField* pQryRCAMSInvestorCombPosition, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryRCAMSInvestorCombPosition((CThostFtdcQryRCAMSInvestorCombPositionField*)pQryRCAMSInvestorCombPosition, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorProdRCAMSMargin(void* trader, const CThostFtdcQryInvestorProdRCAMSMarginField* pQryInvestorProdRCAMSMargin, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInvestorProdRCAMSMargin((CThostFtdcQryInvestorProdRCAMSMarginField*)pQryInvestorProdRCAMSMargin, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryRULEInstrParameter(void* trader, const CThostFtdcQryRULEInstrParameterField* pQryRULEInstrParameter, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryRULEInstrParameter((CThostFtdcQryRULEInstrParameterField*)pQryRULEInstrParameter, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryRULEIntraParameter(void* trader, const CThostFtdcQryRULEIntraParameterField* pQryRULEIntraParameter, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryRULEIntraParameter((CThostFtdcQryRULEIntraParameterField*)pQryRULEIntraParameter, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryRULEInterParameter(void* trader, const CThostFtdcQryRULEInterParameterField* pQryRULEInterParameter, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryRULEInterParameter((CThostFtdcQryRULEInterParameterField*)pQryRULEInterParameter, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorProdRULEMargin(void* trader, const CThostFtdcQryInvestorProdRULEMarginField* pQryInvestorProdRULEMargin, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInvestorProdRULEMargin((CThostFtdcQryInvestorProdRULEMarginField*)pQryInvestorProdRULEMargin, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorPortfSetting(void* trader, const CThostFtdcQryInvestorPortfSettingField* pQryInvestorPortfSetting, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInvestorPortfSetting((CThostFtdcQryInvestorPortfSettingField*)pQryInvestorPortfSetting, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorInfoCommRec(void* trader, const CThostFtdcQryInvestorInfoCommRecField* pQryInvestorInfoCommRec, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryInvestorInfoCommRec((CThostFtdcQryInvestorInfoCommRecField*)pQryInvestorInfoCommRec, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryCombLeg(void* trader, const CThostFtdcQryCombLegField* pQryCombLeg, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryCombLeg((CThostFtdcQryCombLegField*)pQryCombLeg, nRequestID);
}

FTDC2C_API int MYDECL TdReqOffsetSetting(void* trader, const CThostFtdcInputOffsetSettingField* pInputOffsetSetting, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqOffsetSetting((CThostFtdcInputOffsetSettingField*)pInputOffsetSetting, nRequestID);
}

FTDC2C_API int MYDECL TdReqCancelOffsetSetting(void* trader, const CThostFtdcInputOffsetSettingField* pInputOffsetSetting, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqCancelOffsetSetting((CThostFtdcInputOffsetSettingField*)pInputOffsetSetting, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryOffsetSetting(void* trader, const CThostFtdcQryOffsetSettingField* pQryOffsetSetting, int nRequestID) {
	return (static_cast<Trader*>(trader))->RawApi->ReqQryOffsetSetting((CThostFtdcQryOffsetSettingField*)pQryOffsetSetting, nRequestID);
}

