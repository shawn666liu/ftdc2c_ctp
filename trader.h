/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com   
//// Generated at 2016/8/14 13:47:00
/////////////////////////////////////////////////////////////////////////

#pragma once
#include <ThostFtdcTraderApi.h>
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
		if (RawApi){
			RawApi->RegisterSpi(nullptr);
			RawApi->Release();
			RawApi = nullptr;
		}
	};

	virtual void OnFrontConnected() {
		mOnFrontEvent(pObject, (int)EnumOnFrontEvent::OnFrontConnected, 0);
	};
	virtual void OnFrontDisconnected(int nReason) {
		mOnFrontEvent(pObject, (int)EnumOnFrontEvent::OnFrontDisconnected, nReason);
	};
	virtual void OnHeartBeatWarning(int nTimeLapse) {
	};
	virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspAuthenticate, pRspAuthenticateField, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUserLogin, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUserLogout, pUserLogout, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUserPasswordUpdate, pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspTradingAccountPasswordUpdate, pTradingAccountPasswordUpdate, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspOrderInsert, pInputOrder, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspParkedOrderInsert, pParkedOrder, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspParkedOrderAction, pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspOrderAction, pInputOrderAction, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField* pQueryMaxOrderVolume, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQueryMaxOrderVolume, pQueryMaxOrderVolume, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspSettlementInfoConfirm, pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspRemoveParkedOrder, pRemoveParkedOrder, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspRemoveParkedOrderAction, pRemoveParkedOrderAction, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspExecOrderInsert, pInputExecOrder, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspExecOrderAction, pInputExecOrderAction, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspForQuoteInsert, pInputForQuote, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQuoteInsert, pInputQuote, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQuoteAction, pInputQuoteAction, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspBatchOrderAction, pInputBatchOrderAction, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspCombActionInsert, pInputCombAction, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryOrder, pOrder, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryTrade(CThostFtdcTradeField* pTrade, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryTrade, pTrade, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestorPosition, pInvestorPosition, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryTradingAccount, pTradingAccount, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestor(CThostFtdcInvestorField* pInvestor, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestor, pInvestor, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField* pTradingCode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryTradingCode, pTradingCode, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInstrumentMarginRate, pInstrumentMarginRate, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInstrumentCommissionRate, pInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryExchange(CThostFtdcExchangeField* pExchange, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryExchange, pExchange, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryProduct(CThostFtdcProductField* pProduct, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryProduct, pProduct, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInstrument, pInstrument, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryDepthMarketData, pDepthMarketData, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField* pSettlementInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQrySettlementInfo, pSettlementInfo, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryTransferBank(CThostFtdcTransferBankField* pTransferBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryTransferBank, pTransferBank, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestorPositionDetail, pInvestorPositionDetail, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryNotice(CThostFtdcNoticeField* pNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryNotice, pNotice, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQrySettlementInfoConfirm, pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField* pInvestorPositionCombineDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestorPositionCombineDetail, pInvestorPositionCombineDetail, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField* pCFMMCTradingAccountKey, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryCFMMCTradingAccountKey, pCFMMCTradingAccountKey, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField* pEWarrantOffset, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryEWarrantOffset, pEWarrantOffset, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField* pInvestorProductGroupMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestorProductGroupMargin, pInvestorProductGroupMargin, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField* pExchangeMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryExchangeMarginRate, pExchangeMarginRate, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* pExchangeMarginRateAdjust, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryExchangeMarginRateAdjust, pExchangeMarginRateAdjust, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryExchangeRate(CThostFtdcExchangeRateField* pExchangeRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryExchangeRate, pExchangeRate, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField* pSecAgentACIDMap, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQrySecAgentACIDMap, pSecAgentACIDMap, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryProductExchRate(CThostFtdcProductExchRateField* pProductExchRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryProductExchRate, pProductExchRate, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryProductGroup(CThostFtdcProductGroupField* pProductGroup, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryProductGroup, pProductGroup, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField* pMMInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryMMInstrumentCommissionRate, pMMInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField* pMMOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryMMOptionInstrCommRate, pMMOptionInstrCommRate, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField* pInstrumentOrderCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInstrumentOrderCommRate, pInstrumentOrderCommRate, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* pOptionInstrTradeCost, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryOptionInstrTradeCost, pOptionInstrTradeCost, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* pOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryOptionInstrCommRate, pOptionInstrCommRate, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryExecOrder(CThostFtdcExecOrderField* pExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryExecOrder, pExecOrder, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryForQuote(CThostFtdcForQuoteField* pForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryForQuote, pForQuote, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryQuote(CThostFtdcQuoteField* pQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryQuote, pQuote, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField* pCombInstrumentGuard, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryCombInstrumentGuard, pCombInstrumentGuard, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryCombAction(CThostFtdcCombActionField* pCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryCombAction, pCombAction, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialField* pTransferSerial, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryTransferSerial, pTransferSerial, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryAccountregister(CThostFtdcAccountregisterField* pAccountregister, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryAccountregister, pAccountregister, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspError, nullptr, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRtnOrder(CThostFtdcOrderField* pOrder) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnOrder, pOrder);
	};
	virtual void OnRtnTrade(CThostFtdcTradeField* pTrade) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnTrade, pTrade);
	};
	virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnOrderInsert, pInputOrder, pRspInfo);
	};
	virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField* pOrderAction, CThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnOrderAction, pOrderAction, pRspInfo);
	};
	virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* pInstrumentStatus) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnInstrumentStatus, pInstrumentStatus);
	};
	virtual void OnRtnBulletin(CThostFtdcBulletinField* pBulletin) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnBulletin, pBulletin);
	};
	virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField* pTradingNoticeInfo) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnTradingNotice, pTradingNoticeInfo);
	};
	virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField* pErrorConditionalOrder) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnErrorConditionalOrder, pErrorConditionalOrder);
	};
	virtual void OnRtnExecOrder(CThostFtdcExecOrderField* pExecOrder) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnExecOrder, pExecOrder);
	};
	virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnExecOrderInsert, pInputExecOrder, pRspInfo);
	};
	virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField* pExecOrderAction, CThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnExecOrderAction, pExecOrderAction, pRspInfo);
	};
	virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnForQuoteInsert, pInputForQuote, pRspInfo);
	};
	virtual void OnRtnQuote(CThostFtdcQuoteField* pQuote) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnQuote, pQuote);
	};
	virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnQuoteInsert, pInputQuote, pRspInfo);
	};
	virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField* pQuoteAction, CThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnQuoteAction, pQuoteAction, pRspInfo);
	};
	virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnForQuoteRsp, pForQuoteRsp);
	};
	virtual void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField* pCFMMCTradingAccountToken) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnCFMMCTradingAccountToken, pCFMMCTradingAccountToken);
	};
	virtual void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField* pBatchOrderAction, CThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnBatchOrderAction, pBatchOrderAction, pRspInfo);
	};
	virtual void OnRtnCombAction(CThostFtdcCombActionField* pCombAction) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnCombAction, pCombAction);
	};
	virtual void OnErrRtnCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnCombActionInsert, pInputCombAction, pRspInfo);
	};
	virtual void OnRspQryContractBank(CThostFtdcContractBankField* pContractBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryContractBank, pContractBank, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryParkedOrder(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryParkedOrder, pParkedOrder, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryParkedOrderAction, pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField* pTradingNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryTradingNotice, pTradingNotice, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField* pBrokerTradingParams, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryBrokerTradingParams, pBrokerTradingParams, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField* pBrokerTradingAlgos, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryBrokerTradingAlgos, pBrokerTradingAlgos, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQueryCFMMCTradingAccountToken, pQueryCFMMCTradingAccountToken, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField* pRspTransfer) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnFromBankToFutureByBank, pRspTransfer);
	};
	virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField* pRspTransfer) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnFromFutureToBankByBank, pRspTransfer);
	};
	virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField* pRspRepeal) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnRepealFromBankToFutureByBank, pRspRepeal);
	};
	virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField* pRspRepeal) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnRepealFromFutureToBankByBank, pRspRepeal);
	};
	virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField* pRspTransfer) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnFromBankToFutureByFuture, pRspTransfer);
	};
	virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField* pRspTransfer) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnFromFutureToBankByFuture, pRspTransfer);
	};
	virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField* pRspRepeal) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnRepealFromBankToFutureByFutureManual, pRspRepeal);
	};
	virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField* pRspRepeal) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnRepealFromFutureToBankByFutureManual, pRspRepeal);
	};
	virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField* pNotifyQueryAccount) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnQueryBankBalanceByFuture, pNotifyQueryAccount);
	};
	virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnBankToFutureByFuture, pReqTransfer, pRspInfo);
	};
	virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnFutureToBankByFuture, pReqTransfer, pRspInfo);
	};
	virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnRepealBankToFutureByFutureManual, pReqRepeal, pRspInfo);
	};
	virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnRepealFutureToBankByFutureManual, pReqRepeal, pRspInfo);
	};
	virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnQueryBankBalanceByFuture, pReqQueryAccount, pRspInfo);
	};
	virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField* pRspRepeal) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnRepealFromBankToFutureByFuture, pRspRepeal);
	};
	virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField* pRspRepeal) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnRepealFromFutureToBankByFuture, pRspRepeal);
	};
	virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspFromBankToFutureByFuture, pReqTransfer, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspFromFutureToBankByFuture, pReqTransfer, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQueryBankAccountMoneyByFuture, pReqQueryAccount, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField* pOpenAccount) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnOpenAccountByBank, pOpenAccount);
	};
	virtual void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField* pCancelAccount) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnCancelAccountByBank, pCancelAccount);
	};
	virtual void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField* pChangeAccount) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnChangeAccountByBank, pChangeAccount);
	};

}; // end of class