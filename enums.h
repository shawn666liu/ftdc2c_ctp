/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com
/////////////////////////////////////////////////////////////////////////

#pragma once

/// <summary>
/// 所有的OnErrRtnXXXX回调事件
/// </summary>
enum class EnumOnErrRtnEvent
{
	OnErrRtnOrderInsert,
	OnErrRtnOrderAction,
	OnErrRtnExecOrderInsert,
	OnErrRtnExecOrderAction,
	OnErrRtnForQuoteInsert,
	OnErrRtnQuoteInsert,
	OnErrRtnQuoteAction,
	OnErrRtnBatchOrderAction,
	OnErrRtnOptionSelfCloseInsert,
	OnErrRtnOptionSelfCloseAction,
	OnErrRtnCombActionInsert,
	OnErrRtnBankToFutureByFuture,
	OnErrRtnFutureToBankByFuture,
	OnErrRtnRepealBankToFutureByFutureManual,
	OnErrRtnRepealFutureToBankByFutureManual,
	OnErrRtnQueryBankBalanceByFuture,
};

/// <summary>
/// 所有的OnFrontXXXX回调事件
/// </summary>
enum class EnumOnFrontEvent
{
	OnFrontConnected,
	OnFrontDisconnected,
};

/// <summary>
/// 所有的OnRspXXXX回调事件
/// </summary>
enum class EnumOnRspEvent
{
	OnRspUserLogin,
	OnRspUserLogout,
	OnRspQryMulticastInstrument,
	OnRspError,
	OnRspSubMarketData,
	OnRspUnSubMarketData,
	OnRspSubForQuoteRsp,
	OnRspUnSubForQuoteRsp,
	OnRspAuthenticate,
	OnRspUserPasswordUpdate,
	OnRspTradingAccountPasswordUpdate,
	OnRspUserAuthMethod,
	OnRspGenUserCaptcha,
	OnRspGenUserText,
	OnRspOrderInsert,
	OnRspParkedOrderInsert,
	OnRspParkedOrderAction,
	OnRspOrderAction,
	OnRspQryMaxOrderVolume,
	OnRspSettlementInfoConfirm,
	OnRspRemoveParkedOrder,
	OnRspRemoveParkedOrderAction,
	OnRspExecOrderInsert,
	OnRspExecOrderAction,
	OnRspForQuoteInsert,
	OnRspQuoteInsert,
	OnRspQuoteAction,
	OnRspBatchOrderAction,
	OnRspOptionSelfCloseInsert,
	OnRspOptionSelfCloseAction,
	OnRspCombActionInsert,
	OnRspQryOrder,
	OnRspQryTrade,
	OnRspQryInvestorPosition,
	OnRspQryTradingAccount,
	OnRspQryInvestor,
	OnRspQryTradingCode,
	OnRspQryInstrumentMarginRate,
	OnRspQryInstrumentCommissionRate,
	OnRspQryExchange,
	OnRspQryProduct,
	OnRspQryInstrument,
	OnRspQryDepthMarketData,
	OnRspQryTraderOffer,
	OnRspQrySettlementInfo,
	OnRspQryTransferBank,
	OnRspQryInvestorPositionDetail,
	OnRspQryNotice,
	OnRspQrySettlementInfoConfirm,
	OnRspQryInvestorPositionCombineDetail,
	OnRspQryCFMMCTradingAccountKey,
	OnRspQryEWarrantOffset,
	OnRspQryInvestorProductGroupMargin,
	OnRspQryExchangeMarginRate,
	OnRspQryExchangeMarginRateAdjust,
	OnRspQryExchangeRate,
	OnRspQrySecAgentACIDMap,
	OnRspQryProductExchRate,
	OnRspQryProductGroup,
	OnRspQryMMInstrumentCommissionRate,
	OnRspQryMMOptionInstrCommRate,
	OnRspQryInstrumentOrderCommRate,
	OnRspQrySecAgentTradingAccount,
	OnRspQrySecAgentCheckMode,
	OnRspQrySecAgentTradeInfo,
	OnRspQryOptionInstrTradeCost,
	OnRspQryOptionInstrCommRate,
	OnRspQryExecOrder,
	OnRspQryForQuote,
	OnRspQryQuote,
	OnRspQryOptionSelfClose,
	OnRspQryInvestUnit,
	OnRspQryCombInstrumentGuard,
	OnRspQryCombAction,
	OnRspQryTransferSerial,
	OnRspQryAccountregister,
	OnRspQryContractBank,
	OnRspQryParkedOrder,
	OnRspQryParkedOrderAction,
	OnRspQryTradingNotice,
	OnRspQryBrokerTradingParams,
	OnRspQryBrokerTradingAlgos,
	OnRspQueryCFMMCTradingAccountToken,
	OnRspFromBankToFutureByFuture,
	OnRspFromFutureToBankByFuture,
	OnRspQueryBankAccountMoneyByFuture,
	OnRspQryClassifiedInstrument,
	OnRspQryCombPromotionParam,
	OnRspQryRiskSettleInvstPosition,
	OnRspQryRiskSettleProductStatus,
};

/// <summary>
/// 所有的OnRtnXXXX回调事件
/// </summary>
enum class EnumOnRtnEvent
{
	OnRtnDepthMarketData,
	OnRtnForQuoteRsp,
	OnRtnOrder,
	OnRtnTrade,
	OnRtnInstrumentStatus,
	OnRtnBulletin,
	OnRtnTradingNotice,
	OnRtnErrorConditionalOrder,
	OnRtnExecOrder,
	OnRtnQuote,
	OnRtnCFMMCTradingAccountToken,
	OnRtnOptionSelfClose,
	OnRtnCombAction,
	OnRtnFromBankToFutureByBank,
	OnRtnFromFutureToBankByBank,
	OnRtnRepealFromBankToFutureByBank,
	OnRtnRepealFromFutureToBankByBank,
	OnRtnFromBankToFutureByFuture,
	OnRtnFromFutureToBankByFuture,
	OnRtnRepealFromBankToFutureByFutureManual,
	OnRtnRepealFromFutureToBankByFutureManual,
	OnRtnQueryBankBalanceByFuture,
	OnRtnRepealFromBankToFutureByFuture,
	OnRtnRepealFromFutureToBankByFuture,
	OnRtnOpenAccountByBank,
	OnRtnCancelAccountByBank,
	OnRtnChangeAccountByBank,
};

