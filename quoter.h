/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com   
//// Generated at 2016/8/14 13:47:00
/////////////////////////////////////////////////////////////////////////

#pragma once
#include <ThostFtdcMdApi.h>
#include "enums.h"

class Quoter : public CThostFtdcMdSpi
{
public:
	CThostFtdcMdApi* RawApi{ nullptr };
	CbOnFrontEvent mOnFrontEvent{ nullptr };
	CbOnRspEvent mOnRspEvent{ nullptr };
	CbOnRtnEvent mOnRtnEvent{ nullptr };
	void* pObject;

	Quoter(const char* pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast) {
		RawApi = CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath, bIsUsingUdp, bIsMulticast);
		RawApi->RegisterSpi(this);
		pObject = this;
	}


	virtual ~Quoter() {
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
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUserLogin, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUserLogout, pUserLogout, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspError, nullptr, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspSubMarketData, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUnSubMarketData, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspSubForQuoteRsp, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUnSubForQuoteRsp, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnDepthMarketData, pDepthMarketData);
	};
	virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnForQuoteRsp, pForQuoteRsp);
	};

}; // end of class