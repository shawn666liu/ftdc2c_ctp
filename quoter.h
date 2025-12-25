/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com
/////////////////////////////////////////////////////////////////////////

#pragma once
#include "api/ThostFtdcMdApi.h"
#include "enums.h"

class Quoter : public CThostFtdcMdSpi
{
public:
	CThostFtdcMdApi* RawApi{ nullptr };
	CbOnFrontEvent mOnFrontEvent{ nullptr };
	CbOnRspEvent mOnRspEvent{ nullptr };
	CbOnRtnEvent mOnRtnEvent{ nullptr };
	void* pUserObject;

	Quoter(const char* pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast) {
		RawApi = CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath, bIsUsingUdp, bIsMulticast);
		RawApi->RegisterSpi(this);
		pUserObject = this;
	}


	virtual ~Quoter() {
		if (RawApi) {
			RawApi->RegisterSpi(nullptr);
			RawApi->Release();
			RawApi = nullptr;
		}
	};

	void OnFrontConnected() override {
		mOnFrontEvent(pUserObject, EnumOnFrontEvent::OnFrontConnected, 0);
	};
	void OnFrontDisconnected(int nReason) override {
		mOnFrontEvent(pUserObject, EnumOnFrontEvent::OnFrontDisconnected, nReason);
	};
	void OnHeartBeatWarning(int nTimeLapse) override {
	};
	void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspUserLogin, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspUserLogout, pUserLogout, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryMulticastInstrument(CThostFtdcMulticastInstrumentField* pMulticastInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspQryMulticastInstrument, pMulticastInstrument, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspError, nullptr, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspSubMarketData, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspUnSubMarketData, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspSubForQuoteRsp, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pUserObject, EnumOnRspEvent::OnRspUnSubForQuoteRsp, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	};
	void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData) override {
		mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnDepthMarketData, pDepthMarketData);
	};
	void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp) override {
		mOnRtnEvent(pUserObject, EnumOnRtnEvent::OnRtnForQuoteRsp, pForQuoteRsp);
	};

}; // end of class