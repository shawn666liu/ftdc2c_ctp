﻿/////////////////////////////////////////////////////////////////////////
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
	void* pObject;

	Quoter(const char* pszFlowPath, const bool bIsUsingUdp, const bool bIsMulticast) {
		RawApi = CThostFtdcMdApi::CreateFtdcMdApi(pszFlowPath, bIsUsingUdp, bIsMulticast);
		RawApi->RegisterSpi(this);
		pObject = this;
	}


	virtual ~Quoter() {
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
	void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspUserLogin, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspUserLogout, pUserLogout, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspQryMulticastInstrument(CThostFtdcMulticastInstrumentField* pMulticastInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspQryMulticastInstrument, pMulticastInstrument, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspError, nullptr, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspSubMarketData, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspUnSubMarketData, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspSubForQuoteRsp, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	};
	void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) override {
		mOnRspEvent(pObject, EnumOnRspEvent::OnRspUnSubForQuoteRsp, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	};
	void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnDepthMarketData, pDepthMarketData);
	};
	void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp) override {
		mOnRtnEvent(pObject, EnumOnRtnEvent::OnRtnForQuoteRsp, pForQuoteRsp);
	};

}; // end of class