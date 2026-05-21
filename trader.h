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
    CThostFtdcTraderApi* RawApi {nullptr};
    CbOnErrRtnEvent mOnErrRtnEvent {nullptr};
    CbOnFrontEvent mOnFrontEvent {nullptr};
    CbOnRspEvent mOnRspEvent {nullptr};
    CbOnRtnEvent mOnRtnEvent {nullptr};
    void* pUserObject;

    Trader(const char* pszFlowPath, bool bIsProductionMode)
    {
        RawApi = CThostFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath, bIsProductionMode);
        RawApi->RegisterSpi(this);
        pUserObject = this;
    }

    virtual ~Trader()
    {
        if (RawApi)
        {
            RawApi->RegisterSpi(nullptr);
            RawApi->Release();
            RawApi = nullptr;
        }
    };

    void OnFrontConnected() override
    {
        mOnFrontEvent(pUserObject, EnumOnFrontEvent::OnFrontConnected, 0);
    };
    void OnFrontDisconnected(int nReason) override
    {
        mOnFrontEvent(pUserObject, EnumOnFrontEvent::OnFrontDisconnected, nReason);
    };
    void OnHeartBeatWarning(int nTimeLapse) override {
    };
    void OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspAuthenticate, pRspAuthenticateField, pRspInfo, nRequestID, bIsLast);
    };
    void OnRtnPrivateSeqNo(int nSeqNo) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnPrivateSeqNo, (void*) nSeqNo);
    };
    void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspUserLogin, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspUserLogout, pUserLogout, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspUserPasswordUpdate, pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspTradingAccountPasswordUpdate, pTradingAccountPasswordUpdate, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspUserAuthMethod(CThostFtdcRspUserAuthMethodField* pRspUserAuthMethod, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspUserAuthMethod, pRspUserAuthMethod, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspGenUserCaptcha(CThostFtdcRspGenUserCaptchaField* pRspGenUserCaptcha, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspGenUserCaptcha, pRspGenUserCaptcha, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspGenUserText(CThostFtdcRspGenUserTextField* pRspGenUserText, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspGenUserText, pRspGenUserText, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspOrderInsert, pInputOrder, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspParkedOrderInsert, pParkedOrder, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspParkedOrderAction, pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspOrderAction, pInputOrderAction, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryMaxOrderVolume(CThostFtdcQryMaxOrderVolumeField* pQryMaxOrderVolume, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryMaxOrderVolume, pQryMaxOrderVolume, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspSettlementInfoConfirm, pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspRemoveParkedOrder, pRemoveParkedOrder, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspRemoveParkedOrderAction, pRemoveParkedOrderAction, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspExecOrderInsert, pInputExecOrder, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspExecOrderAction, pInputExecOrderAction, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspForQuoteInsert, pInputForQuote, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQuoteInsert, pInputQuote, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQuoteAction, pInputQuoteAction, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField* pInputBatchOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspBatchOrderAction, pInputBatchOrderAction, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspOptionSelfCloseInsert, pInputOptionSelfClose, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField* pInputOptionSelfCloseAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspOptionSelfCloseAction, pInputOptionSelfCloseAction, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspCombActionInsert, pInputCombAction, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryOrder, pOrder, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryTrade(CThostFtdcTradeField* pTrade, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryTrade, pTrade, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInvestorPosition, pInvestorPosition, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryTradingAccount, pTradingAccount, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInvestor(CThostFtdcInvestorField* pInvestor, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInvestor, pInvestor, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryTradingCode(CThostFtdcTradingCodeField* pTradingCode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryTradingCode, pTradingCode, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInstrumentMarginRate, pInstrumentMarginRate, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInstrumentCommissionRate, pInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryUserSession(CThostFtdcUserSessionField* pUserSession, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryUserSession, pUserSession, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryExchange(CThostFtdcExchangeField* pExchange, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryExchange, pExchange, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryProduct(CThostFtdcProductField* pProduct, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryProduct, pProduct, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInstrument, pInstrument, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryDepthMarketData, pDepthMarketData, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryTraderOffer(CThostFtdcTraderOfferField* pTraderOffer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryTraderOffer, pTraderOffer, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField* pSettlementInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQrySettlementInfo, pSettlementInfo, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryTransferBank(CThostFtdcTransferBankField* pTransferBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryTransferBank, pTransferBank, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInvestorPositionDetail, pInvestorPositionDetail, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryNotice(CThostFtdcNoticeField* pNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryNotice, pNotice, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQrySettlementInfoConfirm, pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField* pInvestorPositionCombineDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInvestorPositionCombineDetail, pInvestorPositionCombineDetail, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField* pCFMMCTradingAccountKey, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryCFMMCTradingAccountKey, pCFMMCTradingAccountKey, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField* pEWarrantOffset, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryEWarrantOffset, pEWarrantOffset, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField* pInvestorProductGroupMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInvestorProductGroupMargin, pInvestorProductGroupMargin, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField* pExchangeMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryExchangeMarginRate, pExchangeMarginRate, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* pExchangeMarginRateAdjust, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryExchangeMarginRateAdjust, pExchangeMarginRateAdjust, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryExchangeRate(CThostFtdcExchangeRateField* pExchangeRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryExchangeRate, pExchangeRate, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField* pSecAgentACIDMap, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQrySecAgentACIDMap, pSecAgentACIDMap, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryProductExchRate(CThostFtdcProductExchRateField* pProductExchRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryProductExchRate, pProductExchRate, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryProductGroup(CThostFtdcProductGroupField* pProductGroup, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryProductGroup, pProductGroup, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField* pMMInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryMMInstrumentCommissionRate, pMMInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField* pMMOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryMMOptionInstrCommRate, pMMOptionInstrCommRate, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField* pInstrumentOrderCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInstrumentOrderCommRate, pInstrumentOrderCommRate, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQrySecAgentTradingAccount, pTradingAccount, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField* pSecAgentCheckMode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQrySecAgentCheckMode, pSecAgentCheckMode, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQrySecAgentTradeInfo(CThostFtdcSecAgentTradeInfoField* pSecAgentTradeInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQrySecAgentTradeInfo, pSecAgentTradeInfo, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* pOptionInstrTradeCost, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryOptionInstrTradeCost, pOptionInstrTradeCost, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* pOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryOptionInstrCommRate, pOptionInstrCommRate, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryExecOrder(CThostFtdcExecOrderField* pExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryExecOrder, pExecOrder, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryForQuote(CThostFtdcForQuoteField* pForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryForQuote, pForQuote, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryQuote(CThostFtdcQuoteField* pQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryQuote, pQuote, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField* pOptionSelfClose, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryOptionSelfClose, pOptionSelfClose, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInvestUnit(CThostFtdcInvestUnitField* pInvestUnit, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInvestUnit, pInvestUnit, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField* pCombInstrumentGuard, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryCombInstrumentGuard, pCombInstrumentGuard, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryCombAction(CThostFtdcCombActionField* pCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryCombAction, pCombAction, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryTransferSerial(CThostFtdcTransferSerialField* pTransferSerial, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryTransferSerial, pTransferSerial, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryAccountregister(CThostFtdcAccountregisterField* pAccountregister, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryAccountregister, pAccountregister, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspError, nullptr, pRspInfo, nRequestID, bIsLast);
    };
    void OnRtnOrder(CThostFtdcOrderField* pOrder) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnOrder, pOrder);
    };
    void OnRtnTrade(CThostFtdcTradeField* pTrade) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnTrade, pTrade);
    };
    void OnErrRtnOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnOrderInsert, pInputOrder, pRspInfo);
    };
    void OnErrRtnOrderAction(CThostFtdcOrderActionField* pOrderAction, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnOrderAction, pOrderAction, pRspInfo);
    };
    void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* pInstrumentStatus) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnInstrumentStatus, pInstrumentStatus);
    };
    void OnRtnBulletin(CThostFtdcBulletinField* pBulletin) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnBulletin, pBulletin);
    };
    void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField* pTradingNoticeInfo) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnTradingNotice, pTradingNoticeInfo);
    };
    void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField* pErrorConditionalOrder) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnErrorConditionalOrder, pErrorConditionalOrder);
    };
    void OnRtnExecOrder(CThostFtdcExecOrderField* pExecOrder) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnExecOrder, pExecOrder);
    };
    void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnExecOrderInsert, pInputExecOrder, pRspInfo);
    };
    void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField* pExecOrderAction, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnExecOrderAction, pExecOrderAction, pRspInfo);
    };
    void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnForQuoteInsert, pInputForQuote, pRspInfo);
    };
    void OnRtnQuote(CThostFtdcQuoteField* pQuote) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnQuote, pQuote);
    };
    void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnQuoteInsert, pInputQuote, pRspInfo);
    };
    void OnErrRtnQuoteAction(CThostFtdcQuoteActionField* pQuoteAction, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnQuoteAction, pQuoteAction, pRspInfo);
    };
    void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnForQuoteRsp, pForQuoteRsp);
    };
    void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField* pCFMMCTradingAccountToken) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnCFMMCTradingAccountToken, pCFMMCTradingAccountToken);
    };
    void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField* pBatchOrderAction, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnBatchOrderAction, pBatchOrderAction, pRspInfo);
    };
    void OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField* pOptionSelfClose) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnOptionSelfClose, pOptionSelfClose);
    };
    void OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* pInputOptionSelfClose, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnOptionSelfCloseInsert, pInputOptionSelfClose, pRspInfo);
    };
    void OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField* pOptionSelfCloseAction, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnOptionSelfCloseAction, pOptionSelfCloseAction, pRspInfo);
    };
    void OnRtnCombAction(CThostFtdcCombActionField* pCombAction) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnCombAction, pCombAction);
    };
    void OnErrRtnCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnCombActionInsert, pInputCombAction, pRspInfo);
    };
    void OnRspQryContractBank(CThostFtdcContractBankField* pContractBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryContractBank, pContractBank, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryParkedOrder(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryParkedOrder, pParkedOrder, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryParkedOrderAction, pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryTradingNotice(CThostFtdcTradingNoticeField* pTradingNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryTradingNotice, pTradingNotice, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField* pBrokerTradingParams, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryBrokerTradingParams, pBrokerTradingParams, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField* pBrokerTradingAlgos, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryBrokerTradingAlgos, pBrokerTradingAlgos, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQueryCFMMCTradingAccountToken, pQueryCFMMCTradingAccountToken, pRspInfo, nRequestID, bIsLast);
    };
    void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField* pRspTransfer) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnFromBankToFutureByBank, pRspTransfer);
    };
    void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField* pRspTransfer) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnFromFutureToBankByBank, pRspTransfer);
    };
    void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField* pRspRepeal) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnRepealFromBankToFutureByBank, pRspRepeal);
    };
    void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField* pRspRepeal) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnRepealFromFutureToBankByBank, pRspRepeal);
    };
    void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField* pRspTransfer) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnFromBankToFutureByFuture, pRspTransfer);
    };
    void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField* pRspTransfer) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnFromFutureToBankByFuture, pRspTransfer);
    };
    void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField* pRspRepeal) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnRepealFromBankToFutureByFutureManual, pRspRepeal);
    };
    void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField* pRspRepeal) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnRepealFromFutureToBankByFutureManual, pRspRepeal);
    };
    void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField* pNotifyQueryAccount) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnQueryBankBalanceByFuture, pNotifyQueryAccount);
    };
    void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnBankToFutureByFuture, pReqTransfer, pRspInfo);
    };
    void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnFutureToBankByFuture, pReqTransfer, pRspInfo);
    };
    void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnRepealBankToFutureByFutureManual, pReqRepeal, pRspInfo);
    };
    void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnRepealFutureToBankByFutureManual, pReqRepeal, pRspInfo);
    };
    void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnQueryBankBalanceByFuture, pReqQueryAccount, pRspInfo);
    };
    void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField* pRspRepeal) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnRepealFromBankToFutureByFuture, pRspRepeal);
    };
    void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField* pRspRepeal) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnRepealFromFutureToBankByFuture, pRspRepeal);
    };
    void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspFromBankToFutureByFuture, pReqTransfer, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspFromFutureToBankByFuture, pReqTransfer, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQueryBankAccountMoneyByFuture, pReqQueryAccount, pRspInfo, nRequestID, bIsLast);
    };
    void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField* pOpenAccount) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnOpenAccountByBank, pOpenAccount);
    };
    void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField* pCancelAccount) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnCancelAccountByBank, pCancelAccount);
    };
    void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField* pChangeAccount) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnChangeAccountByBank, pChangeAccount);
    };
    void OnRspQryClassifiedInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryClassifiedInstrument, pInstrument, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryCombPromotionParam(CThostFtdcCombPromotionParamField* pCombPromotionParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryCombPromotionParam, pCombPromotionParam, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryRiskSettleInvstPosition(CThostFtdcRiskSettleInvstPositionField* pRiskSettleInvstPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryRiskSettleInvstPosition, pRiskSettleInvstPosition, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryRiskSettleProductStatus(CThostFtdcRiskSettleProductStatusField* pRiskSettleProductStatus, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryRiskSettleProductStatus, pRiskSettleProductStatus, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQrySPBMFutureParameter(CThostFtdcSPBMFutureParameterField* pSPBMFutureParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQrySPBMFutureParameter, pSPBMFutureParameter, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQrySPBMOptionParameter(CThostFtdcSPBMOptionParameterField* pSPBMOptionParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQrySPBMOptionParameter, pSPBMOptionParameter, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQrySPBMIntraParameter(CThostFtdcSPBMIntraParameterField* pSPBMIntraParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQrySPBMIntraParameter, pSPBMIntraParameter, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQrySPBMInterParameter(CThostFtdcSPBMInterParameterField* pSPBMInterParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQrySPBMInterParameter, pSPBMInterParameter, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQrySPBMPortfDefinition(CThostFtdcSPBMPortfDefinitionField* pSPBMPortfDefinition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQrySPBMPortfDefinition, pSPBMPortfDefinition, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQrySPBMInvestorPortfDef(CThostFtdcSPBMInvestorPortfDefField* pSPBMInvestorPortfDef, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQrySPBMInvestorPortfDef, pSPBMInvestorPortfDef, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInvestorPortfMarginRatio(CThostFtdcInvestorPortfMarginRatioField* pInvestorPortfMarginRatio, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInvestorPortfMarginRatio, pInvestorPortfMarginRatio, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInvestorProdSPBMDetail(CThostFtdcInvestorProdSPBMDetailField* pInvestorProdSPBMDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInvestorProdSPBMDetail, pInvestorProdSPBMDetail, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInvestorCommoditySPMMMargin(CThostFtdcInvestorCommoditySPMMMarginField* pInvestorCommoditySPMMMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInvestorCommoditySPMMMargin, pInvestorCommoditySPMMMargin, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInvestorCommodityGroupSPMMMargin(CThostFtdcInvestorCommodityGroupSPMMMarginField* pInvestorCommodityGroupSPMMMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInvestorCommodityGroupSPMMMargin, pInvestorCommodityGroupSPMMMargin, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQrySPMMInstParam(CThostFtdcSPMMInstParamField* pSPMMInstParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQrySPMMInstParam, pSPMMInstParam, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQrySPMMProductParam(CThostFtdcSPMMProductParamField* pSPMMProductParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQrySPMMProductParam, pSPMMProductParam, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQrySPBMAddOnInterParameter(CThostFtdcSPBMAddOnInterParameterField* pSPBMAddOnInterParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQrySPBMAddOnInterParameter, pSPBMAddOnInterParameter, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryRCAMSCombProductInfo(CThostFtdcRCAMSCombProductInfoField* pRCAMSCombProductInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryRCAMSCombProductInfo, pRCAMSCombProductInfo, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryRCAMSInstrParameter(CThostFtdcRCAMSInstrParameterField* pRCAMSInstrParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryRCAMSInstrParameter, pRCAMSInstrParameter, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryRCAMSIntraParameter(CThostFtdcRCAMSIntraParameterField* pRCAMSIntraParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryRCAMSIntraParameter, pRCAMSIntraParameter, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryRCAMSInterParameter(CThostFtdcRCAMSInterParameterField* pRCAMSInterParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryRCAMSInterParameter, pRCAMSInterParameter, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryRCAMSShortOptAdjustParam(CThostFtdcRCAMSShortOptAdjustParamField* pRCAMSShortOptAdjustParam, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryRCAMSShortOptAdjustParam, pRCAMSShortOptAdjustParam, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryRCAMSInvestorCombPosition(CThostFtdcRCAMSInvestorCombPositionField* pRCAMSInvestorCombPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryRCAMSInvestorCombPosition, pRCAMSInvestorCombPosition, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInvestorProdRCAMSMargin(CThostFtdcInvestorProdRCAMSMarginField* pInvestorProdRCAMSMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInvestorProdRCAMSMargin, pInvestorProdRCAMSMargin, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryRULEInstrParameter(CThostFtdcRULEInstrParameterField* pRULEInstrParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryRULEInstrParameter, pRULEInstrParameter, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryRULEIntraParameter(CThostFtdcRULEIntraParameterField* pRULEIntraParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryRULEIntraParameter, pRULEIntraParameter, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryRULEInterParameter(CThostFtdcRULEInterParameterField* pRULEInterParameter, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryRULEInterParameter, pRULEInterParameter, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInvestorProdRULEMargin(CThostFtdcInvestorProdRULEMarginField* pInvestorProdRULEMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInvestorProdRULEMargin, pInvestorProdRULEMargin, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInvestorPortfSetting(CThostFtdcInvestorPortfSettingField* pInvestorPortfSetting, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInvestorPortfSetting, pInvestorPortfSetting, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryInvestorInfoCommRec(CThostFtdcInvestorInfoCommRecField* pInvestorInfoCommRec, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryInvestorInfoCommRec, pInvestorInfoCommRec, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryCombLeg(CThostFtdcCombLegField* pCombLeg, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryCombLeg, pCombLeg, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspOffsetSetting(CThostFtdcInputOffsetSettingField* pInputOffsetSetting, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspOffsetSetting, pInputOffsetSetting, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspCancelOffsetSetting(CThostFtdcInputOffsetSettingField* pInputOffsetSetting, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspCancelOffsetSetting, pInputOffsetSetting, pRspInfo, nRequestID, bIsLast);
    };
    void OnRtnOffsetSetting(CThostFtdcOffsetSettingField* pOffsetSetting) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnOffsetSetting, pOffsetSetting);
    };
    void OnErrRtnOffsetSetting(CThostFtdcInputOffsetSettingField* pInputOffsetSetting, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnOffsetSetting, pInputOffsetSetting, pRspInfo);
    };
    void OnErrRtnCancelOffsetSetting(CThostFtdcCancelOffsetSettingField* pCancelOffsetSetting, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnCancelOffsetSetting, pCancelOffsetSetting, pRspInfo);
    };
    void OnRspQryOffsetSetting(CThostFtdcOffsetSettingField* pOffsetSetting, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryOffsetSetting, pOffsetSetting, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspGenSMSCode(CThostFtdcRspGenSMSCodeField* pRspGenSMSCode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspGenSMSCode, pRspGenSMSCode, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspSpdApply(CThostFtdcInputSpdApplyField* pInputSpdApply, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspSpdApply, pInputSpdApply, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspSpdApplyAction(CThostFtdcInputSpdApplyActionField* pInputSpdApplyAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspSpdApplyAction, pInputSpdApplyAction, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQrySpdApply(CThostFtdcSpdApplyField* pSpdApply, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQrySpdApply, pSpdApply, pRspInfo, nRequestID, bIsLast);
    };
    void OnRtnSpdApply(CThostFtdcSpdApplyField* pSpdApply) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnSpdApply, pSpdApply);
    };
    void OnErrRtnSpdApply(CThostFtdcInputSpdApplyField* pInputSpdApply, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnSpdApply, pInputSpdApply, pRspInfo);
    };
    void OnErrRtnSpdApplyAction(CThostFtdcSpdApplyActionField* pSpdApplyAction, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnSpdApplyAction, pSpdApplyAction, pRspInfo);
    };
    void OnRspHedgeCfm(CThostFtdcInputHedgeCfmField* pInputHedgeCfm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspHedgeCfm, pInputHedgeCfm, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspHedgeCfmAction(CThostFtdcInputHedgeCfmActionField* pInputHedgeCfmAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspHedgeCfmAction, pInputHedgeCfmAction, pRspInfo, nRequestID, bIsLast);
    };
    void OnRspQryHedgeCfm(CThostFtdcHedgeCfmField* pHedgeCfm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override
    {
        mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryHedgeCfm, pHedgeCfm, pRspInfo, nRequestID, bIsLast);
    };
    void OnRtnHedgeCfm(CThostFtdcHedgeCfmField* pHedgeCfm) override
    {
        mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnHedgeCfm, pHedgeCfm);
    };
    void OnErrRtnHedgeCfm(CThostFtdcInputHedgeCfmField* pInputHedgeCfm, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnHedgeCfm, pInputHedgeCfm, pRspInfo);
    };
    void OnErrRtnHedgeCfmAction(CThostFtdcHedgeCfmActionField* pHedgeCfmAction, CThostFtdcRspInfoField* pRspInfo) override
    {
        mOnErrRtnEvent(pUserObject, EnumOnErrRtnEvent::OnErrRtnHedgeCfmAction, pHedgeCfmAction, pRspInfo);
    };

}; // end of class