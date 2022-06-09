/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com
/////////////////////////////////////////////////////////////////////////

#pragma once
#include "api/ThostFtdcTraderApi.h"
#include "enums.h"

class Trader : public CThostFtdcTraderSpi
{
public:
	CThostFtdcTraderApi* RawApi{ nullptr };
	CbOnErrRtnEvent mOnErrRtnEvent{ nullptr };
	CbOnFrontEvent mOnFrontEvent{ nullptr };
	CbOnRspEvent mOnRspEvent{ nullptr };
	CbOnRtnEvent mOnRtnEvent{ nullptr };
	void* pObject;

	Trader(const char* pszFlowPath) {
		RawApi = CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath);
		RawApi->RegisterSpi(this);
		pObject = this;
	}


	virtual ~Trader() {
		if (RawApi) {
			RawApi->RegisterSpi(nullptr);
			RawApi->Release();
			RawApi = nullptr;
		}
	};

	void OnFrontConnected() override {
		mOnFrontEvent(pObject, EnumOnFrontEvent::OnFrontConnected, 0);
	};
	void OnFrontDisconnected(int nReason) override {
		mOnFrontEvent(pObject, EnumOnFrontEvent::OnFrontDisconnected, nReason);
	};
	void OnHeartBeatWarning(int nTimeLapse) override {
	};
	void OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspAuthenticate, pRspAuthenticateField, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspUserLogin, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspUserLogout, pUserLogout, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspUserPasswordUpdate, pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspTradingAccountPasswordUpdate, pTradingAccountPasswordUpdate, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField* pRspUserAuthMethod, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspUserAuthMethod, pRspUserAuthMethod, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField* pRspGenUserCaptcha, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspGenUserCaptcha, pRspGenUserCaptcha, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspGenUserText(CThostFtdcRspGenUserTextField* pRspGenUserText, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspGenUserText, pRspGenUserText, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspOrderInsert, pInputOrder, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspParkedOrderInsert, pParkedOrder, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspParkedOrderAction, pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspOrderAction, pInputOrderAction, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryMaxOrderVolume, pQryMaxOrderVolume, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspSettlementInfoConfirm, pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspRemoveParkedOrder, pRemoveParkedOrder, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspRemoveParkedOrderAction, pRemoveParkedOrderAction, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspExecOrderInsert, pInputExecOrder, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspExecOrderAction, pInputExecOrderAction, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspForQuoteInsert, pInputForQuote, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQuoteInsert, pInputQuote, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQuoteAction, pInputQuoteAction, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspBatchOrderAction, pInputBatchOrderAction, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspOptionSelfCloseInsert, pInputOptionSelfClose, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspOptionSelfCloseAction, pInputOptionSelfCloseAction, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspCombActionInsert, pInputCombAction, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryOrder, pOrder, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryTrade(CThostFtdcTradeField* pTrade, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryTrade, pTrade, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryInvestorPosition, pInvestorPosition, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryTradingAccount, pTradingAccount, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryInvestor(CThostFtdcInvestorField* pInvestor, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryInvestor, pInvestor, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryTradingCode(CThostFtdcTradingCodeField* pTradingCode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryTradingCode, pTradingCode, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryInstrumentMarginRate, pInstrumentMarginRate, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryInstrumentCommissionRate, pInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryExchange(CThostFtdcExchangeField* pExchange, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryExchange, pExchange, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryProduct(CThostFtdcProductField* pProduct, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryProduct, pProduct, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryInstrument, pInstrument, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryDepthMarketData, pDepthMarketData, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryTraderOffer(CThostFtdcTraderOfferField* pTraderOffer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryTraderOffer, pTraderOffer, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField* pSettlementInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQrySettlementInfo, pSettlementInfo, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryTransferBank(CThostFtdcTransferBankField* pTransferBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryTransferBank, pTransferBank, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryInvestorPositionDetail, pInvestorPositionDetail, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryNotice(CThostFtdcNoticeField* pNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryNotice, pNotice, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQrySettlementInfoConfirm, pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField* pInvestorPositionCombineDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryInvestorPositionCombineDetail, pInvestorPositionCombineDetail, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField* pCFMMCTradingAccountKey, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryCFMMCTradingAccountKey, pCFMMCTradingAccountKey, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField* pEWarrantOffset, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryEWarrantOffset, pEWarrantOffset, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField* pInvestorProductGroupMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryInvestorProductGroupMargin, pInvestorProductGroupMargin, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField* pExchangeMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryExchangeMarginRate, pExchangeMarginRate, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* pExchangeMarginRateAdjust, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryExchangeMarginRateAdjust, pExchangeMarginRateAdjust, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryExchangeRate(CThostFtdcExchangeRateField* pExchangeRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryExchangeRate, pExchangeRate, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField* pSecAgentACIDMap, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQrySecAgentACIDMap, pSecAgentACIDMap, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryProductExchRate(CThostFtdcProductExchRateField* pProductExchRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryProductExchRate, pProductExchRate, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryProductGroup(CThostFtdcProductGroupField* pProductGroup, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryProductGroup, pProductGroup, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField* pMMInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryMMInstrumentCommissionRate, pMMInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField* pMMOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryMMOptionInstrCommRate, pMMOptionInstrCommRate, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField* pInstrumentOrderCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryInstrumentOrderCommRate, pInstrumentOrderCommRate, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQrySecAgentTradingAccount, pTradingAccount, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField* pSecAgentCheckMode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQrySecAgentCheckMode, pSecAgentCheckMode, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField* pSecAgentTradeInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQrySecAgentTradeInfo, pSecAgentTradeInfo, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* pOptionInstrTradeCost, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryOptionInstrTradeCost, pOptionInstrTradeCost, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* pOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryOptionInstrCommRate, pOptionInstrCommRate, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryExecOrder(CThostFtdcExecOrderField* pExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryExecOrder, pExecOrder, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryForQuote(CThostFtdcForQuoteField* pForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryForQuote, pForQuote, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryQuote(CThostFtdcQuoteField* pQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryQuote, pQuote, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField* pOptionSelfClose, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryOptionSelfClose, pOptionSelfClose, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryInvestUnit(CThostFtdcInvestUnitField* pInvestUnit, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryInvestUnit, pInvestUnit, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField* pCombInstrumentGuard, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryCombInstrumentGuard, pCombInstrumentGuard, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryCombAction(CThostFtdcCombActionField* pCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryCombAction, pCombAction, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryTransferSerial(CThostFtdcTransferSerialField* pTransferSerial, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryTransferSerial, pTransferSerial, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryAccountregister(CThostFtdcAccountregisterField* pAccountregister, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryAccountregister, pAccountregister, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspError, nullptr, pRspInfo, nRequestID, bIsLast);
	};
	void OnRtnOrder(CThostFtdcOrderField* pOrder) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnOrder, pOrder);
	};
	void OnRtnTrade(CThostFtdcTradeField* pTrade) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnTrade, pTrade);
	};
	void OnErrRtnOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo) override {
		mOnErrRtnEvent(pObject, EnumOnErrRtnEvent::OnErrRtnOrderInsert, pInputOrder, pRspInfo);
	};
	void OnErrRtnOrderAction(CThostFtdcOrderActionField* pOrderAction, CThostFtdcRspInfoField* pRspInfo) override {
		mOnErrRtnEvent(pObject, EnumOnErrRtnEvent::OnErrRtnOrderAction, pOrderAction, pRspInfo);
	};
	void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* pInstrumentStatus) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnInstrumentStatus, pInstrumentStatus);
	};
	void OnRtnBulletin(CThostFtdcBulletinField* pBulletin) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnBulletin, pBulletin);
	};
	void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField* pTradingNoticeInfo) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnTradingNotice, pTradingNoticeInfo);
	};
	void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField* pErrorConditionalOrder) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnErrorConditionalOrder, pErrorConditionalOrder);
	};
	void OnRtnExecOrder(CThostFtdcExecOrderField* pExecOrder) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnExecOrder, pExecOrder);
	};
	void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo) override {
		mOnErrRtnEvent(pObject, EnumOnErrRtnEvent::OnErrRtnExecOrderInsert, pInputExecOrder, pRspInfo);
	};
	void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField* pExecOrderAction, CThostFtdcRspInfoField* pRspInfo) override {
		mOnErrRtnEvent(pObject, EnumOnErrRtnEvent::OnErrRtnExecOrderAction, pExecOrderAction, pRspInfo);
	};
	void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo) override {
		mOnErrRtnEvent(pObject, EnumOnErrRtnEvent::OnErrRtnForQuoteInsert, pInputForQuote, pRspInfo);
	};
	void OnRtnQuote(CThostFtdcQuoteField* pQuote) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnQuote, pQuote);
	};
	void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo) override {
		mOnErrRtnEvent(pObject, EnumOnErrRtnEvent::OnErrRtnQuoteInsert, pInputQuote, pRspInfo);
	};
	void OnErrRtnQuoteAction(CThostFtdcQuoteActionField* pQuoteAction, CThostFtdcRspInfoField* pRspInfo) override {
		mOnErrRtnEvent(pObject, EnumOnErrRtnEvent::OnErrRtnQuoteAction, pQuoteAction, pRspInfo);
	};
	void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnForQuoteRsp, pForQuoteRsp);
	};
	void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField* pCFMMCTradingAccountToken) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnCFMMCTradingAccountToken, pCFMMCTradingAccountToken);
	};
	void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField* pBatchOrderAction, CThostFtdcRspInfoField* pRspInfo) override {
		mOnErrRtnEvent(pObject, EnumOnErrRtnEvent::OnErrRtnBatchOrderAction, pBatchOrderAction, pRspInfo);
	};
	void OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField* pOptionSelfClose) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnOptionSelfClose, pOptionSelfClose);
	};
	void OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, CThostFtdcRspInfoField* pRspInfo) override {
		mOnErrRtnEvent(pObject, EnumOnErrRtnEvent::OnErrRtnOptionSelfCloseInsert, pInputOptionSelfClose, pRspInfo);
	};
	void OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField* pOptionSelfCloseAction, CThostFtdcRspInfoField* pRspInfo) override {
		mOnErrRtnEvent(pObject, EnumOnErrRtnEvent::OnErrRtnOptionSelfCloseAction, pOptionSelfCloseAction, pRspInfo);
	};
	void OnRtnCombAction(CThostFtdcCombActionField* pCombAction) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnCombAction, pCombAction);
	};
	void OnErrRtnCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo) override {
		mOnErrRtnEvent(pObject, EnumOnErrRtnEvent::OnErrRtnCombActionInsert, pInputCombAction, pRspInfo);
	};
	void OnRspQryContractBank(CThostFtdcContractBankField* pContractBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryContractBank, pContractBank, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryParkedOrder(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryParkedOrder, pParkedOrder, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryParkedOrderAction, pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryTradingNotice(CThostFtdcTradingNoticeField* pTradingNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryTradingNotice, pTradingNotice, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField* pBrokerTradingParams, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryBrokerTradingParams, pBrokerTradingParams, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField* pBrokerTradingAlgos, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryBrokerTradingAlgos, pBrokerTradingAlgos, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQueryCFMMCTradingAccountToken, pQueryCFMMCTradingAccountToken, pRspInfo, nRequestID, bIsLast);
	};
	void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField* pRspTransfer) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnFromBankToFutureByBank, pRspTransfer);
	};
	void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField* pRspTransfer) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnFromFutureToBankByBank, pRspTransfer);
	};
	void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField* pRspRepeal) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnRepealFromBankToFutureByBank, pRspRepeal);
	};
	void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField* pRspRepeal) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnRepealFromFutureToBankByBank, pRspRepeal);
	};
	void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField* pRspTransfer) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnFromBankToFutureByFuture, pRspTransfer);
	};
	void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField* pRspTransfer) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnFromFutureToBankByFuture, pRspTransfer);
	};
	void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField* pRspRepeal) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnRepealFromBankToFutureByFutureManual, pRspRepeal);
	};
	void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField* pRspRepeal) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnRepealFromFutureToBankByFutureManual, pRspRepeal);
	};
	void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField* pNotifyQueryAccount) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnQueryBankBalanceByFuture, pNotifyQueryAccount);
	};
	void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo) override {
		mOnErrRtnEvent(pObject, EnumOnErrRtnEvent::OnErrRtnBankToFutureByFuture, pReqTransfer, pRspInfo);
	};
	void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo) override {
		mOnErrRtnEvent(pObject, EnumOnErrRtnEvent::OnErrRtnFutureToBankByFuture, pReqTransfer, pRspInfo);
	};
	void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo) override {
		mOnErrRtnEvent(pObject, EnumOnErrRtnEvent::OnErrRtnRepealBankToFutureByFutureManual, pReqRepeal, pRspInfo);
	};
	void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo) override {
		mOnErrRtnEvent(pObject, EnumOnErrRtnEvent::OnErrRtnRepealFutureToBankByFutureManual, pReqRepeal, pRspInfo);
	};
	void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo) override {
		mOnErrRtnEvent(pObject, EnumOnErrRtnEvent::OnErrRtnQueryBankBalanceByFuture, pReqQueryAccount, pRspInfo);
	};
	void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField* pRspRepeal) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnRepealFromBankToFutureByFuture, pRspRepeal);
	};
	void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField* pRspRepeal) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnRepealFromFutureToBankByFuture, pRspRepeal);
	};
	void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspFromBankToFutureByFuture, pReqTransfer, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspFromFutureToBankByFuture, pReqTransfer, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQueryBankAccountMoneyByFuture, pReqQueryAccount, pRspInfo, nRequestID, bIsLast);
	};
	void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField* pOpenAccount) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnOpenAccountByBank, pOpenAccount);
	};
	void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField* pCancelAccount) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnCancelAccountByBank, pCancelAccount);
	};
	void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField* pChangeAccount) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnChangeAccountByBank, pChangeAccount);
	};
	void OnRspQryClassifiedInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryClassifiedInstrument, pInstrument, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryCombPromotionParam(CThostFtdcCombPromotionParamField* pCombPromotionParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryCombPromotionParam, pCombPromotionParam, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryRiskSettleInvstPosition(CThostFtdcRiskSettleInvstPositionField* pRiskSettleInvstPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryRiskSettleInvstPosition, pRiskSettleInvstPosition, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryRiskSettleProductStatus(CThostFtdcRiskSettleProductStatusField* pRiskSettleProductStatus, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryRiskSettleProductStatus, pRiskSettleProductStatus, pRspInfo, nRequestID, bIsLast);
	};

}; // end of class