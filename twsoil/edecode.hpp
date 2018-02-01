/* Copyright (C) 2017 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#pragma once

#include "Contract.h"
#include "HistoricalTick.h"
#include "HistoricalTickBidAsk.h"
#include "HistoricalTickLast.h"



//const int MIN_SERVER_VER_REAL_TIME_BARS       = 34;
//const int MIN_SERVER_VER_SCALE_ORDERS         = 35;
//const int MIN_SERVER_VER_SNAPSHOT_MKT_DATA    = 35;
//const int MIN_SERVER_VER_SSHORT_COMBO_LEGS    = 35;
//const int MIN_SERVER_VER_WHAT_IF_ORDERS       = 36;
//const int MIN_SERVER_VER_CONTRACT_CONID       = 37;
const int MIN_SERVER_VER_PTA_ORDERS                 = 39;
const int MIN_SERVER_VER_FUNDAMENTAL_DATA           = 40;
const int MIN_SERVER_VER_UNDER_COMP                 = 40;
const int MIN_SERVER_VER_CONTRACT_DATA_CHAIN        = 40;
const int MIN_SERVER_VER_SCALE_ORDERS2              = 40;
const int MIN_SERVER_VER_ALGO_ORDERS                = 41;
const int MIN_SERVER_VER_EXECUTION_DATA_CHAIN       = 42;
const int MIN_SERVER_VER_NOT_HELD                   = 44;
const int MIN_SERVER_VER_SEC_ID_TYPE                = 45;
const int MIN_SERVER_VER_PLACE_ORDER_CONID          = 46;
const int MIN_SERVER_VER_REQ_MKT_DATA_CONID         = 47;
const int MIN_SERVER_VER_REQ_CALC_IMPLIED_VOLAT     = 49;
const int MIN_SERVER_VER_REQ_CALC_OPTION_PRICE      = 50;
const int MIN_SERVER_VER_CANCEL_CALC_IMPLIED_VOLAT  = 50;
const int MIN_SERVER_VER_CANCEL_CALC_OPTION_PRICE   = 50;
const int MIN_SERVER_VER_SSHORTX_OLD                = 51;
const int MIN_SERVER_VER_SSHORTX                    = 52;
const int MIN_SERVER_VER_REQ_GLOBAL_CANCEL          = 53;
const int MIN_SERVER_VER_HEDGE_ORDERS               = 54;
const int MIN_SERVER_VER_REQ_MARKET_DATA_TYPE       = 55;
const int MIN_SERVER_VER_OPT_OUT_SMART_ROUTING      = 56;
const int MIN_SERVER_VER_SMART_COMBO_ROUTING_PARAMS = 57;
const int MIN_SERVER_VER_DELTA_NEUTRAL_CONID        = 58;
const int MIN_SERVER_VER_SCALE_ORDERS3              = 60;
const int MIN_SERVER_VER_ORDER_COMBO_LEGS_PRICE     = 61;
const int MIN_SERVER_VER_TRAILING_PERCENT           = 62;
const int MIN_SERVER_VER_DELTA_NEUTRAL_OPEN_CLOSE   = 66;
const int MIN_SERVER_VER_POSITIONS                  = 67;
const int MIN_SERVER_VER_ACCOUNT_SUMMARY            = 67;
const int MIN_SERVER_VER_TRADING_CLASS              = 68;
const int MIN_SERVER_VER_SCALE_TABLE                = 69;
const int MIN_SERVER_VER_LINKING                    = 70;
const int MIN_SERVER_VER_ALGO_ID                    = 71;
const int MIN_SERVER_VER_OPTIONAL_CAPABILITIES      = 72;
const int MIN_SERVER_VER_ORDER_SOLICITED            = 73;
const int MIN_SERVER_VER_LINKING_AUTH               = 74;
const int MIN_SERVER_VER_PRIMARYEXCH                = 75;
const int MIN_SERVER_VER_RANDOMIZE_SIZE_AND_PRICE   = 76;
const int MIN_SERVER_VER_FRACTIONAL_POSITIONS       = 101;
const int MIN_SERVER_VER_PEGGED_TO_BENCHMARK        = 102;
const int MIN_SERVER_VER_MODELS_SUPPORT             = 103;
const int MIN_SERVER_VER_SEC_DEF_OPT_PARAMS_REQ     = 104;
const int MIN_SERVER_VER_EXT_OPERATOR               = 105;
const int MIN_SERVER_VER_SOFT_DOLLAR_TIER           = 106;
const int MIN_SERVER_VER_REQ_FAMILY_CODES           = 107;
const int MIN_SERVER_VER_REQ_MATCHING_SYMBOLS       = 108;
const int MIN_SERVER_VER_PAST_LIMIT                 = 109;
const int MIN_SERVER_VER_MD_SIZE_MULTIPLIER         = 110;
const int MIN_SERVER_VER_CASH_QTY                   = 111;
const int MIN_SERVER_VER_REQ_MKT_DEPTH_EXCHANGES    = 112;
const int MIN_SERVER_VER_TICK_NEWS                  = 113;
const int MIN_SERVER_VER_REQ_SMART_COMPONENTS       = 114;
const int MIN_SERVER_VER_REQ_NEWS_PROVIDERS         = 115;
const int MIN_SERVER_VER_REQ_NEWS_ARTICLE           = 116;
const int MIN_SERVER_VER_REQ_HISTORICAL_NEWS        = 117;
const int MIN_SERVER_VER_REQ_HEAD_TIMESTAMP         = 118;
const int MIN_SERVER_VER_REQ_HISTOGRAM              = 119;
const int MIN_SERVER_VER_SERVICE_DATA_TYPE          = 120;
const int MIN_SERVER_VER_AGG_GROUP                  = 121;
const int MIN_SERVER_VER_UNDERLYING_INFO            = 122;
const int MIN_SERVER_VER_CANCEL_HEADTIMESTAMP       = 123;
const int MIN_SERVER_VER_SYNT_REALTIME_BARS         = 124;
const int MIN_SERVER_VER_CFD_REROUTE                = 125;
const int MIN_SERVER_VER_MARKET_RULES               = 126;
const int MIN_SERVER_VER_DAILY_PNL                  = 127;
const int MIN_SERVER_VER_PNL                        = 127;
const int MIN_SERVER_VER_NEWS_QUERY_ORIGINS         = 128;
const int MIN_SERVER_VER_UNREALIZED_PNL             = 129;
const int MIN_SERVER_VER_HISTORICAL_TICKS           = 130;
const int MIN_SERVER_VER_MARKET_CAP_PRICE           = 131;
const int MIN_SERVER_VER_PRE_OPEN_BID_ASK           = 132;
const int MIN_SERVER_VER_REAL_EXPIRATION_DATE       = 134;
const int MIN_SERVER_VER_REALIZED_PNL               = 135;
const int MIN_SERVER_VER_LAST_LIQUIDITY             = 136;
const int MIN_SERVER_VER_TICK_BY_TICK               = 137;
const int MIN_SERVER_VER_DECISION_MAKER             = 138;
const int MIN_SERVER_VER_MIFID_EXECUTION            = 139;

/* 100+ messaging */
// 100 = enhanced handshake, msg length prefixes

const int MIN_CLIENT_VER = 100;
const int MAX_CLIENT_VER = MIN_SERVER_VER_MIFID_EXECUTION;


// incoming msg id's
const int TICK_PRICE                                = 1;
const int TICK_SIZE                                 = 2;
const int ORDER_STATUS                              = 3;
const int ERR_MSG                                   = 4;
const int OPEN_ORDER                                = 5;
const int ACCT_VALUE                                = 6;
const int PORTFOLIO_VALUE                           = 7;
const int ACCT_UPDATE_TIME                          = 8;
const int NEXT_VALID_ID                             = 9;
const int CONTRACT_DATA                             = 10;
const int EXECUTION_DATA                            = 11;
const int MARKET_DEPTH                              = 12;
const int MARKET_DEPTH_L2                           = 13;
const int NEWS_BULLETINS                            = 14;
const int MANAGED_ACCTS                             = 15;
const int RECEIVE_FA                                = 16;
const int HISTORICAL_DATA                           = 17;
const int BOND_CONTRACT_DATA                        = 18;
const int SCANNER_PARAMETERS                        = 19;
const int SCANNER_DATA                              = 20;
const int TICK_OPTION_COMPUTATION                   = 21;
const int TICK_GENERIC                              = 45;
const int TICK_STRING                               = 46;
const int TICK_EFP                                  = 47;
const int CURRENT_TIME                              = 49;
const int REAL_TIME_BARS                            = 50;
const int FUNDAMENTAL_DATA                          = 51;
const int CONTRACT_DATA_END                         = 52;
const int OPEN_ORDER_END                            = 53;
const int ACCT_DOWNLOAD_END                         = 54;
const int EXECUTION_DATA_END                        = 55;
const int DELTA_NEUTRAL_VALIDATION                  = 56;
const int TICK_SNAPSHOT_END                         = 57;
const int MARKET_DATA_TYPE                          = 58;
const int COMMISSION_REPORT                         = 59;
const int POSITION_DATA                             = 61;
const int POSITION_END                              = 62;
const int ACCOUNT_SUMMARY                           = 63;
const int ACCOUNT_SUMMARY_END                       = 64;
const int VERIFY_MESSAGE_API                        = 65;
const int VERIFY_COMPLETED                          = 66;
const int DISPLAY_GROUP_LIST                        = 67;
const int DISPLAY_GROUP_UPDATED                     = 68;
const int VERIFY_AND_AUTH_MESSAGE_API               = 69;
const int VERIFY_AND_AUTH_COMPLETED                 = 70;
const int POSITION_MULTI                            = 71;
const int POSITION_MULTI_END                        = 72;
const int ACCOUNT_UPDATE_MULTI                      = 73;
const int ACCOUNT_UPDATE_MULTI_END                  = 74;
const int SECURITY_DEFINITION_OPTION_PARAMETER      = 75;
const int SECURITY_DEFINITION_OPTION_PARAMETER_END  = 76;
const int SOFT_DOLLAR_TIERS                         = 77;
const int FAMILY_CODES                              = 78;
const int SYMBOL_SAMPLES                            = 79;
const int MKT_DEPTH_EXCHANGES                       = 80;
const int TICK_REQ_PARAMS                           = 81;
const int SMART_COMPONENTS                          = 82;
const int NEWS_ARTICLE                              = 83;
const int TICK_NEWS                                 = 84;
const int NEWS_PROVIDERS                            = 85;
const int HISTORICAL_NEWS                           = 86;
const int HISTORICAL_NEWS_END                       = 87;
const int HEAD_TIMESTAMP                            = 88;
const int HISTOGRAM_DATA                            = 89;
const int HISTORICAL_DATA_UPDATE                    = 90;
const int REROUTE_MKT_DATA_REQ                      = 91;
const int REROUTE_MKT_DEPTH_REQ                     = 92;
const int MARKET_RULE                               = 93;
const int PNL                                       = 94;
const int PNL_SINGLE                                = 95;
const int HISTORICAL_TICKS                          = 96;
const int HISTORICAL_TICKS_BID_ASK                  = 97;
const int HISTORICAL_TICKS_LAST                     = 98;
const int TICK_BY_TICK                              = 99;

const int HEADER_LEN = 4; // 4 bytes for msg length
const int MAX_MSG_LEN = 0xFFFFFF; // 16Mb - 1byte
const char API_SIGN[4] = { 'A', 'P', 'I', '\0' }; // "API"


// helper structures
namespace {

struct BarData {
   std::string date;
   double open;
   double high;
   double low;
   double close;
   int volume;
   double average;
   std::string hasGaps;
   int barCount;
};

struct ScanData {
   ContractDetails contract;
   int rank;
   std::string distance;
   std::string benchmark;
   std::string projection;
   std::string legsStr;
};

} // end of anonymous namespace

///////////////////////////////////////////////////////////
// utility funcs
static inline std::string errMsg(std::exception e) {
   // return the error associated with this exception
   return std::string(e.what());
}

class EWrapper;
class EClient;
struct EClientMsgSink;

class TWSAPIDLLEXP EDecoder
{
    EWrapper *m_pEWrapper;
    int m_serverVersion;
    EClientMsgSink *m_pClientMsgSink;

    const char* processTickPriceMsg(const char* ptr, const char* endPtr);
    const char* processTickSizeMsg(const char* ptr, const char* endPtr);
    const char* processTickOptionComputationMsg(const char* ptr, const char* endPtr);
    const char* processTickGenericMsg(const char* ptr, const char* endPtr);
    const char* processTickStringMsg(const char* ptr, const char* endPtr);
    const char* processTickEfpMsg(const char* ptr, const char* endPtr);
    const char* processOrderStatusMsg(const char* ptr, const char* endPtr);
    const char* processErrMsgMsg(const char* ptr, const char* endPtr);
    const char* processOpenOrderMsg(const char* ptr, const char* endPtr);
    const char* processAcctValueMsg(const char* ptr, const char* endPtr);
    const char* processPortfolioValueMsg(const char* ptr, const char* endPtr);
    const char* processAcctUpdateTimeMsg(const char* ptr, const char* endPtr);
    const char* processNextValidIdMsg(const char* ptr, const char* endPtr);
    const char* processContractDataMsg(const char* ptr, const char* endPtr);
    const char* processBondContractDataMsg(const char* ptr, const char* endPtr);
    const char* processExecutionDetailsMsg(const char* ptr, const char* endPtr);
    const char* processMarketDepthMsg(const char* ptr, const char* endPtr);
    const char* processMarketDepthL2Msg(const char* ptr, const char* endPtr);
    const char* processNewsBulletinsMsg(const char* ptr, const char* endPtr);
    const char* processManagedAcctsMsg(const char* ptr, const char* endPtr);
    const char* processReceiveFaMsg(const char* ptr, const char* endPtr);
    const char* processHistoricalDataMsg(const char* ptr, const char* endPtr);
    const char* processScannerDataMsg(const char* ptr, const char* endPtr);
    const char* processScannerParametersMsg(const char* ptr, const char* endPtr);
    const char* processCurrentTimeMsg(const char* ptr, const char* endPtr);
    const char* processRealTimeBarsMsg(const char* ptr, const char* endPtr);
    const char* processFundamentalDataMsg(const char* ptr, const char* endPtr);
    const char* processContractDataEndMsg(const char* ptr, const char* endPtr);
    const char* processOpenOrderEndMsg(const char* ptr, const char* endPtr);
    const char* processAcctDownloadEndMsg(const char* ptr, const char* endPtr);
    const char* processExecutionDetailsEndMsg(const char* ptr, const char* endPtr);
    const char* processDeltaNeutralValidationMsg(const char* ptr, const char* endPtr);
    const char* processTickSnapshotEndMsg(const char* ptr, const char* endPtr);
    const char* processMarketDataTypeMsg(const char* ptr, const char* endPtr);
    const char* processCommissionReportMsg(const char* ptr, const char* endPtr);
    const char* processPositionDataMsg(const char* ptr, const char* endPtr);
    const char* processPositionEndMsg(const char* ptr, const char* endPtr);
    const char* processAccountSummaryMsg(const char* ptr, const char* endPtr);
    const char* processAccountSummaryEndMsg(const char* ptr, const char* endPtr);
    const char* processVerifyMessageApiMsg(const char* ptr, const char* endPtr);
    const char* processVerifyCompletedMsg(const char* ptr, const char* endPtr);
    const char* processDisplayGroupListMsg(const char* ptr, const char* endPtr);
    const char* processDisplayGroupUpdatedMsg(const char* ptr, const char* endPtr);
    const char* processVerifyAndAuthMessageApiMsg(const char* ptr, const char* endPtr);
    const char* processVerifyAndAuthCompletedMsg(const char* ptr, const char* endPtr);
    const char* processPositionMultiMsg(const char* ptr, const char* endPtr);
    const char* processPositionMultiEndMsg(const char* ptr, const char* endPtr);
    const char* processAccountUpdateMultiMsg(const char* ptr, const char* endPtr);
    const char* processAccountUpdateMultiEndMsg(const char* ptr, const char* endPtr);
    const char* processSecurityDefinitionOptionalParameterMsg(const char* ptr, const char* endPtr);
    const char* processSecurityDefinitionOptionalParameterEndMsg(const char* ptr, const char* endPtr);
    const char* processSoftDollarTiersMsg(const char* ptr, const char* endPtr);
    const char* processFamilyCodesMsg(const char* ptr, const char* endPtr);
    const char* processSymbolSamplesMsg(const char* ptr, const char* endPtr);
    const char* processMktDepthExchangesMsg(const char* ptr, const char* endPtr);
    const char* processTickNewsMsg(const char* ptr, const char* endPtr);
    const char* processTickReqParamsMsg(const char* ptr, const char* endPtr);
    const char* processSmartComponentsMsg(const char* ptr, const char* endPtr);
    const char* processNewsProvidersMsg(const char* ptr, const char* endPtr);
    const char* processNewsArticleMsg(const char* ptr, const char* endPtr);
    const char* processHistoricalNewsMsg(const char* ptr, const char* endPtr);
    const char* processHistoricalNewsEndMsg(const char* ptr, const char* endPtr);
    const char* processHeadTimestampMsg(const char* ptr, const char* endPtr);
    const char* processHistogramDataMsg(const char* ptr, const char* endPtr);
    const char* processHistoricalDataUpdateMsg(const char* ptr, const char* endPtr);
	const char* processRerouteMktDataReqMsg(const char* ptr, const char* endPtr);
	const char* processRerouteMktDepthReqMsg(const char* ptr, const char* endPtr);
	const char* processMarketRuleMsg(const char* ptr, const char* endPtr);
    const char* processPnLMsg(const char* ptr, const char* endPtr);
    const char* processPnLSingleMsg(const char* ptr, const char* endPtr);
    const char* processHistoricalTicks(const char* ptr, const char* endPtr);
    const char* processHistoricalTicksBidAsk(const char* ptr, const char* endPtr);
    const char* processHistoricalTicksLast(const char* ptr, const char* endPtr);
    const char* processTickByTickDataMsg(const char* ptr, const char* endPtr);


    int processConnectAck(const char*& beginPtr, const char* endPtr);

    static const char* decodeTick(HistoricalTick& tick, const char* ptr, const char* endPtr);
    static const char* decodeTick(HistoricalTickBidAsk& tick, const char* ptr, const char* endPtr);
    static const char* decodeTick(HistoricalTickLast& tick, const char* ptr, const char* endPtr);
    void callEWrapperCallBack(int reqId, const std::vector<HistoricalTick> &ticks, bool done);
    void callEWrapperCallBack(int reqId, const std::vector<HistoricalTickBidAsk> &ticks, bool done);
    void callEWrapperCallBack(int reqId, const std::vector<HistoricalTickLast> &ticks, bool done);
    template<typename T> const char* processHistoricalTicks(const char* ptr, const char* endPtr);

public:
    static bool CheckOffset(const char* ptr, const char* endPtr);
    static const char* FindFieldEnd(const char* ptr, const char* endPtr);
    // decoders
    static bool DecodeField(bool&, const char*& ptr, const char* endPtr);
    static bool DecodeField(int&, const char*& ptr, const char* endPtr);
    static bool DecodeField(long&, const char*& ptr, const char* endPtr);
    static bool DecodeField(long long&, const char*& ptr, const char* endPtr);
    static bool DecodeField(double&, const char*& ptr, const char* endPtr);
    static bool DecodeField(std::string&, const char*& ptr, const char* endPtr);
    static bool DecodeField(char&, const char*& ptr, const char* endPtr);

    static bool DecodeFieldTime(time_t&, const char*& ptr, const char* endPtr);

    static bool DecodeFieldMax(int&, const char*& ptr, const char* endPtr);
    static bool DecodeFieldMax(long&, const char*& ptr, const char* endPtr);
    static bool DecodeFieldMax(double&, const char*& ptr, const char* endPtr);

    EDecoder(int serverVersion, EWrapper *callback, EClientMsgSink *clientMsgSink = 0);

    int parseAndProcessMsg(const char*& beginPtr, const char* endPtr);
};

#define DECODE_FIELD(x) if (!EDecoder::DecodeField(x, ptr, endPtr)) return 0;
#define DECODE_FIELD_TIME(x) if (!EDecoder::DecodeFieldTime(x, ptr, endPtr)) return 0;
#define DECODE_FIELD_MAX(x) if (!EDecoder::DecodeFieldMax(x, ptr, endPtr)) return 0;


/* Copyright (C) 2017 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
* and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#include "StdAfx.h"
#include <assert.h>
#include <string>
#include <bitset>
#include "EWrapper.h"
#include "Order.h"
#include "Contract.h"
#include "OrderState.h"
#include "Execution.h"
#include "FamilyCode.h"
#include "CommissionReport.h"
#include "TwsSocketClientErrors.h"
#include "EDecoder.h"
#include "EClientMsgSink.h"
#include "PriceIncrement.h"
#include <string.h>
#include <cstdlib>

EDecoder::EDecoder(int serverVersion, EWrapper *callback, EClientMsgSink *clientMsgSink) {
	m_pEWrapper = callback;
	m_serverVersion = serverVersion;
	m_pClientMsgSink = clientMsgSink;
}

const char* EDecoder::processTickPriceMsg(const char* ptr, const char* endPtr) {
	int version;
	int tickerId;
	int tickTypeInt;
	double price;

	int size;
	int attrMask;

	DECODE_FIELD( version);
	DECODE_FIELD( tickerId);
	DECODE_FIELD( tickTypeInt);
	DECODE_FIELD( price);
	DECODE_FIELD( size); // ver 2 field
	DECODE_FIELD( attrMask); // ver 3 field

	TickAttrib attrib;

	attrib.canAutoExecute = attrMask == 1;

	if (m_serverVersion >= MIN_SERVER_VER_PAST_LIMIT)
	{
		std::bitset<32> mask(attrMask);

		attrib.canAutoExecute = mask[0];
		attrib.pastLimit = mask[1];

		if (m_serverVersion >= MIN_SERVER_VER_PRE_OPEN_BID_ASK)
		{
			attrib.preOpen = mask[2];
		}
	}

	m_pEWrapper->tickPrice( tickerId, (TickType)tickTypeInt, price, attrib);

	// process ver 2 fields
	{
		TickType sizeTickType = NOT_SET;
		switch( (TickType)tickTypeInt) {
		case BID:
			sizeTickType = BID_SIZE;
			break;
		case ASK:
			sizeTickType = ASK_SIZE;
			break;
		case LAST:
			sizeTickType = LAST_SIZE;
			break;
		case DELAYED_BID:
			sizeTickType = DELAYED_BID_SIZE;
			break;
		case DELAYED_ASK:
			sizeTickType = DELAYED_ASK_SIZE;
			break;
		case DELAYED_LAST:
			sizeTickType = DELAYED_LAST_SIZE;
			break;
		default:
			break;
		}
		if( sizeTickType != NOT_SET)
			m_pEWrapper->tickSize( tickerId, sizeTickType, size);
	}

	return ptr;
}

const char* EDecoder::processTickSizeMsg(const char* ptr, const char* endPtr) {
	int version;
	int tickerId;
	int tickTypeInt;
	int size;

	DECODE_FIELD( version);
	DECODE_FIELD( tickerId);
	DECODE_FIELD( tickTypeInt);
	DECODE_FIELD( size);

	m_pEWrapper->tickSize( tickerId, (TickType)tickTypeInt, size);

	return ptr;
}

const char* EDecoder::processTickOptionComputationMsg(const char* ptr, const char* endPtr) {
	int version;
	int tickerId;
	int tickTypeInt;
	double impliedVol;
	double delta;

	double optPrice = DBL_MAX;
	double pvDividend = DBL_MAX;

	double gamma = DBL_MAX;
	double vega = DBL_MAX;
	double theta = DBL_MAX;
	double undPrice = DBL_MAX;

	DECODE_FIELD( version);
	DECODE_FIELD( tickerId);
	DECODE_FIELD( tickTypeInt);

	DECODE_FIELD( impliedVol);
	DECODE_FIELD( delta);

	if( impliedVol < 0) { // -1 is the "not computed" indicator
		impliedVol = DBL_MAX;
	}
	if( delta > 1 || delta < -1) { // -2 is the "not computed" indicator
		delta = DBL_MAX;
	}

	if( version >= 6 || tickTypeInt == MODEL_OPTION || tickTypeInt == DELAYED_MODEL_OPTION_COMPUTATION) { // introduced in version == 5

		DECODE_FIELD( optPrice);
		DECODE_FIELD( pvDividend);

		if( optPrice < 0) { // -1 is the "not computed" indicator
			optPrice = DBL_MAX;
		}
		if( pvDividend < 0) { // -1 is the "not computed" indicator
			pvDividend = DBL_MAX;
		}
	}
	if( version >= 6) {

		DECODE_FIELD( gamma);
		DECODE_FIELD( vega);
		DECODE_FIELD( theta);
		DECODE_FIELD( undPrice);

		if( gamma > 1 || gamma < -1) { // -2 is the "not yet computed" indicator
			gamma = DBL_MAX;
		}
		if( vega > 1 || vega < -1) { // -2 is the "not yet computed" indicator
			vega = DBL_MAX;
		}
		if( theta > 1 || theta < -1) { // -2 is the "not yet computed" indicator
			theta = DBL_MAX;
		}
		if( undPrice < 0) { // -1 is the "not computed" indicator
			undPrice = DBL_MAX;
		}
	}
	m_pEWrapper->tickOptionComputation( tickerId, (TickType)tickTypeInt,
		impliedVol, delta, optPrice, pvDividend, gamma, vega, theta, undPrice);

	return ptr;
}

const char* EDecoder::processTickGenericMsg(const char* ptr, const char* endPtr) {
	int version;
	int tickerId;
	int tickTypeInt;
	double value;

	DECODE_FIELD( version);
	DECODE_FIELD( tickerId);
	DECODE_FIELD( tickTypeInt);
	DECODE_FIELD( value);

	m_pEWrapper->tickGeneric( tickerId, (TickType)tickTypeInt, value);

	return ptr;
}

const char* EDecoder::processTickStringMsg(const char* ptr, const char* endPtr) {
	int version;
	int tickerId;
	int tickTypeInt;
	std::string value;

	DECODE_FIELD( version);
	DECODE_FIELD( tickerId);
	DECODE_FIELD( tickTypeInt);
	DECODE_FIELD( value);

	m_pEWrapper->tickString( tickerId, (TickType)tickTypeInt, value);

	return ptr;
}

const char* EDecoder::processTickEfpMsg(const char* ptr, const char* endPtr) {
	int version;
	int tickerId;
	int tickTypeInt;
	double basisPoints;
	std::string formattedBasisPoints;
	double impliedFuturesPrice;
	int holdDays;
	std::string futureLastTradeDate;
	double dividendImpact;
	double dividendsToLastTradeDate;

	DECODE_FIELD( version);
	DECODE_FIELD( tickerId);
	DECODE_FIELD( tickTypeInt);
	DECODE_FIELD( basisPoints);
	DECODE_FIELD( formattedBasisPoints);
	DECODE_FIELD( impliedFuturesPrice);
	DECODE_FIELD( holdDays);
	DECODE_FIELD( futureLastTradeDate);
	DECODE_FIELD( dividendImpact);
	DECODE_FIELD( dividendsToLastTradeDate);

	m_pEWrapper->tickEFP( tickerId, (TickType)tickTypeInt, basisPoints, formattedBasisPoints,
		impliedFuturesPrice, holdDays, futureLastTradeDate, dividendImpact, dividendsToLastTradeDate);

	return ptr;
}

const char* EDecoder::processOrderStatusMsg(const char* ptr, const char* endPtr) {
    int version = INT_MAX;
	int orderId;
	std::string status;
	double filled;
	double remaining;
	double avgFillPrice;
	int permId;
	int parentId;
	double lastFillPrice;
	int clientId;
	std::string whyHeld;

    if (m_serverVersion < MIN_SERVER_VER_MARKET_CAP_PRICE) 
    {
	    DECODE_FIELD( version);
    }
	
    DECODE_FIELD( orderId);
	DECODE_FIELD( status);

	if (m_serverVersion >= MIN_SERVER_VER_FRACTIONAL_POSITIONS)
	{
		DECODE_FIELD( filled);
	}
	else
	{
		int iFilled;

		DECODE_FIELD(iFilled);

		filled = iFilled;
	}

	if (m_serverVersion >= MIN_SERVER_VER_FRACTIONAL_POSITIONS)
	{
		DECODE_FIELD( remaining);
	}
	else
	{
		int iRemaining;

		DECODE_FIELD(iRemaining);

		remaining = iRemaining;
	}

	DECODE_FIELD( avgFillPrice);

	DECODE_FIELD( permId); // ver 2 field
	DECODE_FIELD( parentId); // ver 3 field
	DECODE_FIELD( lastFillPrice); // ver 4 field
	DECODE_FIELD( clientId); // ver 5 field
	DECODE_FIELD( whyHeld); // ver 6 field

	double mktCapPrice = UNSET_DOUBLE;

	if (m_serverVersion >= MIN_SERVER_VER_MARKET_CAP_PRICE)
	{
		DECODE_FIELD(mktCapPrice);
	}

	m_pEWrapper->orderStatus( orderId, status, filled, remaining,
		avgFillPrice, permId, parentId, lastFillPrice, clientId, whyHeld, mktCapPrice);


	return ptr;
}

const char* EDecoder::processErrMsgMsg(const char* ptr, const char* endPtr) {
	int version;
	int id; // ver 2 field
	int errorCode; // ver 2 field
	std::string errorMsg;

	DECODE_FIELD( version);
	DECODE_FIELD( id);
	DECODE_FIELD( errorCode);
	DECODE_FIELD( errorMsg);

	m_pEWrapper->error( id, errorCode, errorMsg);

	return ptr;
}

const char* EDecoder::processOpenOrderMsg(const char* ptr, const char* endPtr) {
	// read version
	int version;
	DECODE_FIELD( version);

	// read order id
	Order order;
	DECODE_FIELD( order.orderId);

	// read contract fields
	Contract contract;
	DECODE_FIELD( contract.conId); // ver 17 field
	DECODE_FIELD( contract.symbol);
	DECODE_FIELD( contract.secType);
	DECODE_FIELD( contract.lastTradeDateOrContractMonth);
	DECODE_FIELD( contract.strike);
	DECODE_FIELD( contract.right);
	if (version >= 32) {
		DECODE_FIELD( contract.multiplier);
	}
	DECODE_FIELD( contract.exchange);
	DECODE_FIELD( contract.currency);
	DECODE_FIELD( contract.localSymbol); // ver 2 field
	if (version >= 32) {
		DECODE_FIELD( contract.tradingClass);
	}

	// read order fields
	DECODE_FIELD( order.action);

	if (m_serverVersion >= MIN_SERVER_VER_FRACTIONAL_POSITIONS)
	{
		DECODE_FIELD( order.totalQuantity);
	}
	else
	{
		long lTotalQuantity;

		DECODE_FIELD(lTotalQuantity);

		order.totalQuantity = lTotalQuantity;
	}

	DECODE_FIELD( order.orderType);
	if (version < 29) { 
		DECODE_FIELD( order.lmtPrice);
	}
	else {
		DECODE_FIELD_MAX( order.lmtPrice);
	}
	if (version < 30) { 
		DECODE_FIELD( order.auxPrice);
	}
	else {
		DECODE_FIELD_MAX( order.auxPrice);
	}
	DECODE_FIELD( order.tif);
	DECODE_FIELD( order.ocaGroup);
	DECODE_FIELD( order.account);
	DECODE_FIELD( order.openClose);

	int orderOriginInt;
	DECODE_FIELD( orderOriginInt);
	order.origin = (Origin)orderOriginInt;

	DECODE_FIELD( order.orderRef);
	DECODE_FIELD( order.clientId); // ver 3 field
	DECODE_FIELD( order.permId); // ver 4 field

	//if( version < 18) {
	//	// will never happen
	//	/* order.ignoreRth = */ readBoolFromInt();
	//}

	DECODE_FIELD( order.outsideRth); // ver 18 field
	DECODE_FIELD( order.hidden); // ver 4 field
	DECODE_FIELD( order.discretionaryAmt); // ver 4 field
	DECODE_FIELD( order.goodAfterTime); // ver 5 field

	{
		std::string sharesAllocation;
		DECODE_FIELD( sharesAllocation); // deprecated ver 6 field
	}

	DECODE_FIELD( order.faGroup); // ver 7 field
	DECODE_FIELD( order.faMethod); // ver 7 field
	DECODE_FIELD( order.faPercentage); // ver 7 field
	DECODE_FIELD( order.faProfile); // ver 7 field

	if( m_serverVersion >= MIN_SERVER_VER_MODELS_SUPPORT ) {
		DECODE_FIELD( order.modelCode);
	}

	DECODE_FIELD( order.goodTillDate); // ver 8 field

	DECODE_FIELD( order.rule80A); // ver 9 field
	DECODE_FIELD_MAX( order.percentOffset); // ver 9 field
	DECODE_FIELD( order.settlingFirm); // ver 9 field
	DECODE_FIELD( order.shortSaleSlot); // ver 9 field
	DECODE_FIELD( order.designatedLocation); // ver 9 field
	if( m_serverVersion == MIN_SERVER_VER_SSHORTX_OLD){
		int exemptCode;
		DECODE_FIELD( exemptCode);
	}
	else if( version >= 23){
		DECODE_FIELD( order.exemptCode);
	}
	DECODE_FIELD( order.auctionStrategy); // ver 9 field
	DECODE_FIELD_MAX( order.startingPrice); // ver 9 field
	DECODE_FIELD_MAX( order.stockRefPrice); // ver 9 field
	DECODE_FIELD_MAX( order.delta); // ver 9 field
	DECODE_FIELD_MAX( order.stockRangeLower); // ver 9 field
	DECODE_FIELD_MAX( order.stockRangeUpper); // ver 9 field
	DECODE_FIELD( order.displaySize); // ver 9 field

	//if( version < 18) {
	//		// will never happen
	//		/* order.rthOnly = */ readBoolFromInt();
	//}

	DECODE_FIELD( order.blockOrder); // ver 9 field
	DECODE_FIELD( order.sweepToFill); // ver 9 field
	DECODE_FIELD( order.allOrNone); // ver 9 field
	DECODE_FIELD_MAX( order.minQty); // ver 9 field
	DECODE_FIELD( order.ocaType); // ver 9 field
	DECODE_FIELD( order.eTradeOnly); // ver 9 field
	DECODE_FIELD( order.firmQuoteOnly); // ver 9 field
	DECODE_FIELD_MAX( order.nbboPriceCap); // ver 9 field

	DECODE_FIELD( order.parentId); // ver 10 field
	DECODE_FIELD( order.triggerMethod); // ver 10 field

	DECODE_FIELD_MAX( order.volatility); // ver 11 field
	DECODE_FIELD( order.volatilityType); // ver 11 field
	DECODE_FIELD( order.deltaNeutralOrderType); // ver 11 field (had a hack for ver 11)
	DECODE_FIELD_MAX( order.deltaNeutralAuxPrice); // ver 12 field

	if (version >= 27 && !order.deltaNeutralOrderType.empty()) {
		DECODE_FIELD( order.deltaNeutralConId);
		DECODE_FIELD( order.deltaNeutralSettlingFirm);
		DECODE_FIELD( order.deltaNeutralClearingAccount);
		DECODE_FIELD( order.deltaNeutralClearingIntent);
	}

	if (version >= 31 && !order.deltaNeutralOrderType.empty()) {
		DECODE_FIELD( order.deltaNeutralOpenClose);
		DECODE_FIELD( order.deltaNeutralShortSale);
		DECODE_FIELD( order.deltaNeutralShortSaleSlot);
		DECODE_FIELD( order.deltaNeutralDesignatedLocation);
	}

	DECODE_FIELD( order.continuousUpdate); // ver 11 field

	// will never happen
	//if( m_serverVersion == 26) {
	//	order.stockRangeLower = readDouble();
	//	order.stockRangeUpper = readDouble();
	//}

	DECODE_FIELD( order.referencePriceType); // ver 11 field

	DECODE_FIELD_MAX( order.trailStopPrice); // ver 13 field

	if (version >= 30) {
		DECODE_FIELD_MAX( order.trailingPercent);
	}

	DECODE_FIELD_MAX( order.basisPoints); // ver 14 field
	DECODE_FIELD_MAX( order.basisPointsType); // ver 14 field
	DECODE_FIELD( contract.comboLegsDescrip); // ver 14 field

	if (version >= 29) {
		int comboLegsCount = 0;
		DECODE_FIELD( comboLegsCount);

		if (comboLegsCount > 0) {
			Contract::ComboLegListSPtr comboLegs( new Contract::ComboLegList);
			comboLegs->reserve( comboLegsCount);
			for (int i = 0; i < comboLegsCount; ++i) {
				ComboLegSPtr comboLeg( new ComboLeg());
				DECODE_FIELD( comboLeg->conId);
				DECODE_FIELD( comboLeg->ratio);
				DECODE_FIELD( comboLeg->action);
				DECODE_FIELD( comboLeg->exchange);
				DECODE_FIELD( comboLeg->openClose);
				DECODE_FIELD( comboLeg->shortSaleSlot);
				DECODE_FIELD( comboLeg->designatedLocation);
				DECODE_FIELD( comboLeg->exemptCode);

				comboLegs->push_back( comboLeg);
			}
			contract.comboLegs = comboLegs;
		}

		int orderComboLegsCount = 0;
		DECODE_FIELD( orderComboLegsCount);
		if (orderComboLegsCount > 0) {
			Order::OrderComboLegListSPtr orderComboLegs( new Order::OrderComboLegList);
			orderComboLegs->reserve( orderComboLegsCount);
			for (int i = 0; i < orderComboLegsCount; ++i) {
				OrderComboLegSPtr orderComboLeg( new OrderComboLeg());
				DECODE_FIELD_MAX( orderComboLeg->price);

				orderComboLegs->push_back( orderComboLeg);
			}
			order.orderComboLegs = orderComboLegs;
		}
	}

	if (version >= 26) {
		int smartComboRoutingParamsCount = 0;
		DECODE_FIELD( smartComboRoutingParamsCount);
		if( smartComboRoutingParamsCount > 0) {
			TagValueListSPtr smartComboRoutingParams( new TagValueList);
			smartComboRoutingParams->reserve( smartComboRoutingParamsCount);
			for( int i = 0; i < smartComboRoutingParamsCount; ++i) {
				TagValueSPtr tagValue( new TagValue());
				DECODE_FIELD( tagValue->tag);
				DECODE_FIELD( tagValue->value);
				smartComboRoutingParams->push_back( tagValue);
			}
			order.smartComboRoutingParams = smartComboRoutingParams;
		}
	}

	if( version >= 20) {
		DECODE_FIELD_MAX( order.scaleInitLevelSize);
		DECODE_FIELD_MAX( order.scaleSubsLevelSize);
	}
	else {
		// ver 15 fields
		int notSuppScaleNumComponents = 0;
		DECODE_FIELD_MAX( notSuppScaleNumComponents);
		DECODE_FIELD_MAX( order.scaleInitLevelSize); // scaleComponectSize
	}
	DECODE_FIELD_MAX( order.scalePriceIncrement); // ver 15 field

	if (version >= 28 && order.scalePriceIncrement > 0.0 && order.scalePriceIncrement != UNSET_DOUBLE) {
		DECODE_FIELD_MAX( order.scalePriceAdjustValue);
		DECODE_FIELD_MAX( order.scalePriceAdjustInterval);
		DECODE_FIELD_MAX( order.scaleProfitOffset);
		DECODE_FIELD( order.scaleAutoReset);
		DECODE_FIELD_MAX( order.scaleInitPosition);
		DECODE_FIELD_MAX( order.scaleInitFillQty);
		DECODE_FIELD( order.scaleRandomPercent);
	}

	if( version >= 24) {
		DECODE_FIELD( order.hedgeType);
		if( !order.hedgeType.empty()) {
			DECODE_FIELD( order.hedgeParam);
		}
	}

	if( version >= 25) {
		DECODE_FIELD( order.optOutSmartRouting);
	}

	DECODE_FIELD( order.clearingAccount); // ver 19 field
	DECODE_FIELD( order.clearingIntent); // ver 19 field

	if( version >= 22) {
		DECODE_FIELD( order.notHeld);
	}

	UnderComp underComp;
	if( version >= 20) {
		bool underCompPresent = false;
		DECODE_FIELD(underCompPresent);
		if( underCompPresent){
			DECODE_FIELD(underComp.conId);
			DECODE_FIELD(underComp.delta);
			DECODE_FIELD(underComp.price);
			contract.underComp = &underComp;
		}
	}


	if( version >= 21) {
		DECODE_FIELD( order.algoStrategy);
		if( !order.algoStrategy.empty()) {
			int algoParamsCount = 0;
			DECODE_FIELD( algoParamsCount);
			if( algoParamsCount > 0) {
				TagValueListSPtr algoParams( new TagValueList);
				algoParams->reserve( algoParamsCount);
				for( int i = 0; i < algoParamsCount; ++i) {
					TagValueSPtr tagValue( new TagValue());
					DECODE_FIELD( tagValue->tag);
					DECODE_FIELD( tagValue->value);
					algoParams->push_back( tagValue);
				}
				order.algoParams = algoParams;
			}
		}
	}

	if (version >= 33) {
		DECODE_FIELD(order.solicited);
	}

	OrderState orderState;

	DECODE_FIELD( order.whatIf); // ver 16 field

	DECODE_FIELD( orderState.status); // ver 16 field
	DECODE_FIELD( orderState.initMargin); // ver 16 field
	DECODE_FIELD( orderState.maintMargin); // ver 16 field
	DECODE_FIELD( orderState.equityWithLoan); // ver 16 field
	DECODE_FIELD_MAX( orderState.commission); // ver 16 field
	DECODE_FIELD_MAX( orderState.minCommission); // ver 16 field
	DECODE_FIELD_MAX( orderState.maxCommission); // ver 16 field
	DECODE_FIELD( orderState.commissionCurrency); // ver 16 field
	DECODE_FIELD( orderState.warningText); // ver 16 field

	if (version >= 34) {
		DECODE_FIELD(order.randomizeSize);
		DECODE_FIELD(order.randomizePrice);
	}

	if (m_serverVersion >= MIN_SERVER_VER_PEGGED_TO_BENCHMARK) {
		if (order.orderType == "PEG BENCH") {
			DECODE_FIELD(order.referenceContractId);
			DECODE_FIELD(order.isPeggedChangeAmountDecrease);
			DECODE_FIELD(order.peggedChangeAmount);
			DECODE_FIELD(order.referenceChangeAmount);
			DECODE_FIELD(order.referenceExchangeId);
		}

		int conditionsSize;

		DECODE_FIELD(conditionsSize);

		if (conditionsSize > 0) {
			for (; conditionsSize; conditionsSize--) {
				int conditionType;

				DECODE_FIELD(conditionType);

				ibapi::shared_ptr<OrderCondition> item = ibapi::shared_ptr<OrderCondition>(OrderCondition::create((OrderCondition::OrderConditionType)conditionType));

				if (!(ptr = item->readExternal(ptr, endPtr)))
					return 0;

				order.conditions.push_back(item);
			}

			DECODE_FIELD(order.conditionsIgnoreRth);
			DECODE_FIELD(order.conditionsCancelOrder);
		}

		DECODE_FIELD(order.adjustedOrderType);
		DECODE_FIELD(order.triggerPrice);
		DECODE_FIELD(order.trailStopPrice);
		DECODE_FIELD(order.lmtPriceOffset);
		DECODE_FIELD(order.adjustedStopPrice);
		DECODE_FIELD(order.adjustedStopLimitPrice);
		DECODE_FIELD(order.adjustedTrailingAmount);
		DECODE_FIELD(order.adjustableTrailingUnit);
	}

	if (m_serverVersion >= MIN_SERVER_VER_SOFT_DOLLAR_TIER) {
		std::string name, value, displayName;

		DECODE_FIELD(name);
		DECODE_FIELD(value);
		DECODE_FIELD(displayName);

		order.softDollarTier = SoftDollarTier(name, value, displayName);
	}

	if (m_serverVersion >= MIN_SERVER_VER_CASH_QTY) {
		DECODE_FIELD_MAX(order.cashQty);
	}

	m_pEWrapper->openOrder( (OrderId)order.orderId, contract, order, orderState);

	return ptr;
} 

const char* EDecoder::processAcctValueMsg(const char* ptr, const char* endPtr) {
	int version;
	std::string key;
	std::string val;
	std::string cur;
	std::string accountName;

	DECODE_FIELD( version);
	DECODE_FIELD( key);
	DECODE_FIELD( val);
	DECODE_FIELD( cur);
	DECODE_FIELD( accountName); // ver 2 field

	m_pEWrapper->updateAccountValue( key, val, cur, accountName);
	return ptr;
}

const char* EDecoder::processPortfolioValueMsg(const char* ptr, const char* endPtr) {
	// decode version
	int version;
	DECODE_FIELD( version);

	// read contract fields
	Contract contract;
	DECODE_FIELD( contract.conId); // ver 6 field
	DECODE_FIELD( contract.symbol);
	DECODE_FIELD( contract.secType);
	DECODE_FIELD( contract.lastTradeDateOrContractMonth);
	DECODE_FIELD( contract.strike);
	DECODE_FIELD( contract.right);

	if( version >= 7) {
		DECODE_FIELD( contract.multiplier);
		DECODE_FIELD( contract.primaryExchange);
	}

	DECODE_FIELD( contract.currency);
	DECODE_FIELD( contract.localSymbol); // ver 2 field
	if (version >= 8) {
		DECODE_FIELD( contract.tradingClass);
	}

	double  position;
	double  marketPrice;
	double  marketValue;
	double  averageCost;
	double  unrealizedPNL;
	double  realizedPNL;

	if (m_serverVersion >= MIN_SERVER_VER_FRACTIONAL_POSITIONS)
	{
		DECODE_FIELD( position);
	}
	else
	{
		int iPosition;

		DECODE_FIELD(iPosition);

		position = iPosition;
	}

	DECODE_FIELD( marketPrice);
	DECODE_FIELD( marketValue);
	DECODE_FIELD( averageCost); // ver 3 field
	DECODE_FIELD( unrealizedPNL); // ver 3 field
	DECODE_FIELD( realizedPNL); // ver 3 field

	std::string accountName;
	DECODE_FIELD( accountName); // ver 4 field

	if( version == 6 && m_serverVersion == 39) {
		DECODE_FIELD( contract.primaryExchange);
	}

	m_pEWrapper->updatePortfolio( contract,
		position, marketPrice, marketValue, averageCost,
		unrealizedPNL, realizedPNL, accountName);

	return ptr;
}

const char* EDecoder::processAcctUpdateTimeMsg(const char* ptr, const char* endPtr) {
	int version;
	std::string accountTime;

	DECODE_FIELD( version);
	DECODE_FIELD( accountTime);

	m_pEWrapper->updateAccountTime( accountTime);

	return ptr;
}

const char* EDecoder::processNextValidIdMsg(const char* ptr, const char* endPtr) {
	int version;
	int orderId;

	DECODE_FIELD( version);
	DECODE_FIELD( orderId);

	m_pEWrapper->nextValidId(orderId);

	return ptr;
}

const char* EDecoder::processContractDataMsg(const char* ptr, const char* endPtr) {
	int version;
	DECODE_FIELD( version);

	int reqId = -1;
	if( version >= 3) {
		DECODE_FIELD( reqId);
	}

	ContractDetails contract;
	DECODE_FIELD( contract.summary.symbol);
	DECODE_FIELD( contract.summary.secType);
	DECODE_FIELD( contract.summary.lastTradeDateOrContractMonth);
	DECODE_FIELD( contract.summary.strike);
	DECODE_FIELD( contract.summary.right);
	DECODE_FIELD( contract.summary.exchange);
	DECODE_FIELD( contract.summary.currency);
	DECODE_FIELD( contract.summary.localSymbol);
	DECODE_FIELD( contract.marketName);
	DECODE_FIELD( contract.summary.tradingClass);
	DECODE_FIELD( contract.summary.conId);
	DECODE_FIELD( contract.minTick);
	if (m_serverVersion >= MIN_SERVER_VER_MD_SIZE_MULTIPLIER) {
		DECODE_FIELD( contract.mdSizeMultiplier);
	}
	DECODE_FIELD( contract.summary.multiplier);
	DECODE_FIELD( contract.orderTypes);
	DECODE_FIELD( contract.validExchanges);
	DECODE_FIELD( contract.priceMagnifier); // ver 2 field
	if( version >= 4) {
		DECODE_FIELD( contract.underConId);
	}
	if( version >= 5) {
		DECODE_FIELD( contract.longName);
		DECODE_FIELD( contract.summary.primaryExchange);
	}
	if( version >= 6) {
		DECODE_FIELD( contract.contractMonth);
		DECODE_FIELD( contract.industry);
		DECODE_FIELD( contract.category);
		DECODE_FIELD( contract.subcategory);
		DECODE_FIELD( contract.timeZoneId);
		DECODE_FIELD( contract.tradingHours);
		DECODE_FIELD( contract.liquidHours);
	}
	if( version >= 8) {
		DECODE_FIELD( contract.evRule);
		DECODE_FIELD( contract.evMultiplier);
	}
	if( version >= 7) {
		int secIdListCount = 0;
		DECODE_FIELD( secIdListCount);
		if( secIdListCount > 0) {
			TagValueListSPtr secIdList( new TagValueList);
			secIdList->reserve( secIdListCount);
			for( int i = 0; i < secIdListCount; ++i) {
				TagValueSPtr tagValue( new TagValue());
				DECODE_FIELD( tagValue->tag);
				DECODE_FIELD( tagValue->value);
				secIdList->push_back( tagValue);
			}
			contract.secIdList = secIdList;
		}
	}
	if (m_serverVersion >= MIN_SERVER_VER_AGG_GROUP) {
		DECODE_FIELD( contract.aggGroup);
	}
	if (m_serverVersion >= MIN_SERVER_VER_UNDERLYING_INFO) {
		DECODE_FIELD( contract.underSymbol);
		DECODE_FIELD( contract.underSecType);
	}
	if (m_serverVersion >= MIN_SERVER_VER_MARKET_RULES) {
		DECODE_FIELD( contract.marketRuleIds);
	}
	if (m_serverVersion >= MIN_SERVER_VER_REAL_EXPIRATION_DATE) {
		DECODE_FIELD( contract.realExpirationDate);
	}

	m_pEWrapper->contractDetails( reqId, contract);

	return ptr;
}

const char* EDecoder::processBondContractDataMsg(const char* ptr, const char* endPtr) {
	int version;
	DECODE_FIELD( version);

	int reqId = -1;
	if( version >= 3) {
		DECODE_FIELD( reqId);
	}

	ContractDetails contract;
	DECODE_FIELD( contract.summary.symbol);
	DECODE_FIELD( contract.summary.secType);
	DECODE_FIELD( contract.cusip);
	DECODE_FIELD( contract.coupon);
	DECODE_FIELD( contract.maturity);
	DECODE_FIELD( contract.issueDate);
	DECODE_FIELD( contract.ratings);
	DECODE_FIELD( contract.bondType);
	DECODE_FIELD( contract.couponType);
	DECODE_FIELD( contract.convertible);
	DECODE_FIELD( contract.callable);
	DECODE_FIELD( contract.putable);
	DECODE_FIELD( contract.descAppend);
	DECODE_FIELD( contract.summary.exchange);
	DECODE_FIELD( contract.summary.currency);
	DECODE_FIELD( contract.marketName);
	DECODE_FIELD( contract.summary.tradingClass);
	DECODE_FIELD( contract.summary.conId);
	DECODE_FIELD( contract.minTick);
	if (m_serverVersion >= MIN_SERVER_VER_MD_SIZE_MULTIPLIER) {
		DECODE_FIELD( contract.mdSizeMultiplier);
	}
	DECODE_FIELD( contract.orderTypes);
	DECODE_FIELD( contract.validExchanges);
	DECODE_FIELD( contract.nextOptionDate); // ver 2 field
	DECODE_FIELD( contract.nextOptionType); // ver 2 field
	DECODE_FIELD( contract.nextOptionPartial); // ver 2 field
	DECODE_FIELD( contract.notes); // ver 2 field
	if( version >= 4) {
		DECODE_FIELD( contract.longName);
	}
	if( version >= 6) {
		DECODE_FIELD( contract.evRule);
		DECODE_FIELD( contract.evMultiplier);
	}
	if( version >= 5) {
		int secIdListCount = 0;
		DECODE_FIELD( secIdListCount);
		if( secIdListCount > 0) {
			TagValueListSPtr secIdList( new TagValueList);
			secIdList->reserve( secIdListCount);
			for( int i = 0; i < secIdListCount; ++i) {
				TagValueSPtr tagValue( new TagValue());
				DECODE_FIELD( tagValue->tag);
				DECODE_FIELD( tagValue->value);
				secIdList->push_back( tagValue);
			}
			contract.secIdList = secIdList;
		}
	}
	if (m_serverVersion >= MIN_SERVER_VER_AGG_GROUP) {
		DECODE_FIELD( contract.aggGroup);
	}
	if (m_serverVersion >= MIN_SERVER_VER_MARKET_RULES) {
		DECODE_FIELD( contract.marketRuleIds);
	}

	m_pEWrapper->bondContractDetails( reqId, contract);

	return ptr;
}

const char* EDecoder::processExecutionDetailsMsg(const char* ptr, const char* endPtr) {
    int version = m_serverVersion;

    if (m_serverVersion < MIN_SERVER_VER_LAST_LIQUIDITY) {
	    DECODE_FIELD(version);
    }

	int reqId = -1;
	if( version >= 7) {
		DECODE_FIELD(reqId);
	}

	int orderId;
	DECODE_FIELD( orderId);

	// decode contract fields
	Contract contract;
	DECODE_FIELD( contract.conId); // ver 5 field
	DECODE_FIELD( contract.symbol);
	DECODE_FIELD( contract.secType);
	DECODE_FIELD( contract.lastTradeDateOrContractMonth);
	DECODE_FIELD( contract.strike);
	DECODE_FIELD( contract.right);
	if( version >= 9) {
		DECODE_FIELD( contract.multiplier);
	}
	DECODE_FIELD( contract.exchange);
	DECODE_FIELD( contract.currency);
	DECODE_FIELD( contract.localSymbol);
	if (version >= 10) {
		DECODE_FIELD( contract.tradingClass);
	}

	// decode execution fields
	Execution exec;
	exec.orderId = orderId;
	DECODE_FIELD( exec.execId);
	DECODE_FIELD( exec.time);
	DECODE_FIELD( exec.acctNumber);
	DECODE_FIELD( exec.exchange);
	DECODE_FIELD( exec.side);

	if (m_serverVersion >= MIN_SERVER_VER_FRACTIONAL_POSITIONS) {
		DECODE_FIELD( exec.shares)
	} 
	else {
		int iShares;

		DECODE_FIELD(iShares);

		exec.shares = iShares;
	}

	DECODE_FIELD( exec.price);
	DECODE_FIELD( exec.permId); // ver 2 field
	DECODE_FIELD( exec.clientId); // ver 3 field
	DECODE_FIELD( exec.liquidation); // ver 4 field

	if( version >= 6) {
		DECODE_FIELD( exec.cumQty);
		DECODE_FIELD( exec.avgPrice);
	}

	if( version >= 8) {
		DECODE_FIELD( exec.orderRef);
	}

	if( version >= 9) {
		DECODE_FIELD( exec.evRule);
		DECODE_FIELD( exec.evMultiplier);
	}
	if( m_serverVersion >= MIN_SERVER_VER_MODELS_SUPPORT) {
		DECODE_FIELD( exec.modelCode);
	}

    if (m_serverVersion >= MIN_SERVER_VER_LAST_LIQUIDITY) {
        DECODE_FIELD(exec.lastLiquidity);
    }

	m_pEWrapper->execDetails( reqId, contract, exec);

	return ptr;
}

const char* EDecoder::processMarketDepthMsg(const char* ptr, const char* endPtr) {
	int version;
	int id;
	int position;
	int operation;
	int side;
	double price;
	int size;

	DECODE_FIELD( version);
	DECODE_FIELD( id);
	DECODE_FIELD( position);
	DECODE_FIELD( operation);
	DECODE_FIELD( side);
	DECODE_FIELD( price);
	DECODE_FIELD( size);

	m_pEWrapper->updateMktDepth( id, position, operation, side, price, size);

	return ptr;
}

const char* EDecoder::processMarketDepthL2Msg(const char* ptr, const char* endPtr) {
	int version;
	int id;
	int position;
	std::string marketMaker;
	int operation;
	int side;
	double price;
	int size;

	DECODE_FIELD( version);
	DECODE_FIELD( id);
	DECODE_FIELD( position);
	DECODE_FIELD( marketMaker);
	DECODE_FIELD( operation);
	DECODE_FIELD( side);
	DECODE_FIELD( price);
	DECODE_FIELD( size);

	m_pEWrapper->updateMktDepthL2( id, position, marketMaker, operation, side,
		price, size);

	return ptr;
}

const char* EDecoder::processNewsBulletinsMsg(const char* ptr, const char* endPtr) {
	int version;
	int msgId;
	int msgType;
	std::string newsMessage;
	std::string originatingExch;

	DECODE_FIELD( version);
	DECODE_FIELD( msgId);
	DECODE_FIELD( msgType);
	DECODE_FIELD( newsMessage);
	DECODE_FIELD( originatingExch);

	m_pEWrapper->updateNewsBulletin( msgId, msgType, newsMessage, originatingExch);

	return ptr;
}

const char* EDecoder::processManagedAcctsMsg(const char* ptr, const char* endPtr) {
	int version;
	std::string accountsList;

	DECODE_FIELD( version);
	DECODE_FIELD( accountsList);

	m_pEWrapper->managedAccounts( accountsList);

	return ptr;
}

const char* EDecoder::processReceiveFaMsg(const char* ptr, const char* endPtr) {
	int version;
	int faDataTypeInt;
	std::string cxml;

	DECODE_FIELD( version);
	DECODE_FIELD( faDataTypeInt);
	DECODE_FIELD( cxml);

	m_pEWrapper->receiveFA( (faDataType)faDataTypeInt, cxml);

	return ptr;
}

const char* EDecoder::processHistoricalDataMsg(const char* ptr, const char* endPtr) {
    int version = INT_MAX;
	int reqId;
	std::string startDateStr;
	std::string endDateStr;

    if (m_serverVersion < MIN_SERVER_VER_SYNT_REALTIME_BARS) {
	    DECODE_FIELD(version);
    }

	DECODE_FIELD( reqId);
	DECODE_FIELD( startDateStr); // ver 2 field
	DECODE_FIELD( endDateStr); // ver 2 field

	int itemCount;
	DECODE_FIELD( itemCount);

	typedef std::vector<Bar> BarDataList;
	BarDataList bars;

	bars.reserve( itemCount);

	for( int ctr = 0; ctr < itemCount; ++ctr) {
		Bar bar;

		DECODE_FIELD( bar.time);
		DECODE_FIELD( bar.open);
		DECODE_FIELD( bar.high);
		DECODE_FIELD( bar.low);
		DECODE_FIELD( bar.close);

        int vol;

        if (m_serverVersion < MIN_SERVER_VER_SYNT_REALTIME_BARS) {
		    DECODE_FIELD( vol);

            bar.volume = vol;
        } else {
            DECODE_FIELD( bar.volume);
        }

		DECODE_FIELD( bar.wap);

        if (m_serverVersion < MIN_SERVER_VER_SYNT_REALTIME_BARS) {
	        std::string hasGaps;

		    DECODE_FIELD( hasGaps);
        }

		DECODE_FIELD( bar.count); // ver 3 field

		bars.push_back(bar);
	}

	assert( (int)bars.size() == itemCount);

	for( int ctr = 0; ctr < itemCount; ++ctr) {

		const Bar& bar = bars[ctr];

		m_pEWrapper->historicalData( reqId, bar);
	}

	// send end of dataset marker
	m_pEWrapper->historicalDataEnd( reqId, startDateStr, endDateStr);

	return ptr;
}

const char* EDecoder::processHistoricalDataUpdateMsg(const char* ptr, const char* endPtr) {
	int reqId;
	std::string startDateStr;
	std::string endDateStr;

	DECODE_FIELD( reqId);

	Bar bar;

	DECODE_FIELD(bar.count);
	DECODE_FIELD(bar.time);
	DECODE_FIELD(bar.open);
	DECODE_FIELD(bar.close);
	DECODE_FIELD(bar.high);
	DECODE_FIELD(bar.low);
	DECODE_FIELD(bar.wap);
	DECODE_FIELD(bar.volume);

	m_pEWrapper->historicalDataUpdate( reqId, bar);

	return ptr;
}

const char* EDecoder::processScannerDataMsg(const char* ptr, const char* endPtr) {
	int version;
	int tickerId;

	DECODE_FIELD( version);
	DECODE_FIELD( tickerId);

	int numberOfElements;
	DECODE_FIELD( numberOfElements);

	typedef std::vector<ScanData> ScanDataList;
	ScanDataList scannerDataList;

	scannerDataList.reserve( numberOfElements);

	for( int ctr=0; ctr < numberOfElements; ++ctr) {

		ScanData data;

		DECODE_FIELD( data.rank);
		DECODE_FIELD( data.contract.summary.conId); // ver 3 field
		DECODE_FIELD( data.contract.summary.symbol);
		DECODE_FIELD( data.contract.summary.secType);
		DECODE_FIELD( data.contract.summary.lastTradeDateOrContractMonth);
		DECODE_FIELD( data.contract.summary.strike);
		DECODE_FIELD( data.contract.summary.right);
		DECODE_FIELD( data.contract.summary.exchange);
		DECODE_FIELD( data.contract.summary.currency);
		DECODE_FIELD( data.contract.summary.localSymbol);
		DECODE_FIELD( data.contract.marketName);
		DECODE_FIELD( data.contract.summary.tradingClass);
		DECODE_FIELD( data.distance);
		DECODE_FIELD( data.benchmark);
		DECODE_FIELD( data.projection);
		DECODE_FIELD( data.legsStr);

		scannerDataList.push_back( data);
	}

	assert( (int)scannerDataList.size() == numberOfElements);

	for( int ctr=0; ctr < numberOfElements; ++ctr) {

		const ScanData& data = scannerDataList[ctr];
		m_pEWrapper->scannerData( tickerId, data.rank, data.contract,
			data.distance, data.benchmark, data.projection, data.legsStr);
	}

	m_pEWrapper->scannerDataEnd( tickerId);

	return ptr;
}

const char* EDecoder::processScannerParametersMsg(const char* ptr, const char* endPtr) {
	int version;
	std::string xml;

	DECODE_FIELD( version);
	DECODE_FIELD( xml);

	m_pEWrapper->scannerParameters( xml);

	return ptr;
}

const char* EDecoder::processCurrentTimeMsg(const char* ptr, const char* endPtr) {
	int version;
	int time;

	DECODE_FIELD(version);
	DECODE_FIELD(time);

	m_pEWrapper->currentTime( time);

	return ptr;
}

const char* EDecoder::processRealTimeBarsMsg(const char* ptr, const char* endPtr) {
	int version;
	int reqId;
	int time;
	double open;
	double high;
	double low;
	double close;
	int volume;
	double average;
	int count;

	DECODE_FIELD( version);
	DECODE_FIELD( reqId);
	DECODE_FIELD( time);
	DECODE_FIELD( open);
	DECODE_FIELD( high);
	DECODE_FIELD( low);
	DECODE_FIELD( close);
	DECODE_FIELD( volume);
	DECODE_FIELD( average);
	DECODE_FIELD( count);

	m_pEWrapper->realtimeBar( reqId, time, open, high, low, close,
		volume, average, count);

	return ptr;
}

const char* EDecoder::processFundamentalDataMsg(const char* ptr, const char* endPtr) {
	int version;
	int reqId;
	std::string data;

	DECODE_FIELD( version);
	DECODE_FIELD( reqId);
	DECODE_FIELD( data);

	m_pEWrapper->fundamentalData( reqId, data);

	return ptr;
}

const char* EDecoder::processContractDataEndMsg(const char* ptr, const char* endPtr) {
	int version;
	int reqId;

	DECODE_FIELD( version);
	DECODE_FIELD( reqId);

	m_pEWrapper->contractDetailsEnd( reqId);

	return ptr;
}

const char* EDecoder::processOpenOrderEndMsg(const char* ptr, const char* endPtr) {
	int version;

	DECODE_FIELD( version);

	m_pEWrapper->openOrderEnd();

	return ptr;
}

const char* EDecoder::processAcctDownloadEndMsg(const char* ptr, const char* endPtr) {
	int version;
	std::string account;

	DECODE_FIELD( version);
	DECODE_FIELD( account);

	m_pEWrapper->accountDownloadEnd( account);

	return ptr;
}

const char* EDecoder::processExecutionDetailsEndMsg(const char* ptr, const char* endPtr) {
	int version;
	int reqId;

	DECODE_FIELD( version);
	DECODE_FIELD( reqId);

	m_pEWrapper->execDetailsEnd( reqId);

	return ptr;
}

const char* EDecoder::processDeltaNeutralValidationMsg(const char* ptr, const char* endPtr) {
	int version;
	int reqId;

	DECODE_FIELD( version);
	DECODE_FIELD( reqId);

	UnderComp underComp;

	DECODE_FIELD( underComp.conId);
	DECODE_FIELD( underComp.delta);
	DECODE_FIELD( underComp.price);

	m_pEWrapper->deltaNeutralValidation( reqId, underComp);

	return ptr;
}

const char* EDecoder::processTickSnapshotEndMsg(const char* ptr, const char* endPtr) {
	int version;
	int reqId;

	DECODE_FIELD( version);
	DECODE_FIELD( reqId);

	m_pEWrapper->tickSnapshotEnd( reqId);

	return ptr;
}

const char* EDecoder::processMarketDataTypeMsg(const char* ptr, const char* endPtr) {
	int version;
	int reqId;
	int marketDataType;

	DECODE_FIELD( version);
	DECODE_FIELD( reqId);
	DECODE_FIELD( marketDataType);

	m_pEWrapper->marketDataType( reqId, marketDataType);

	return ptr;
}

const char* EDecoder::processCommissionReportMsg(const char* ptr, const char* endPtr) {
	int version;
	DECODE_FIELD( version);

	CommissionReport commissionReport;
	DECODE_FIELD( commissionReport.execId);
	DECODE_FIELD( commissionReport.commission);
	DECODE_FIELD( commissionReport.currency);
	DECODE_FIELD( commissionReport.realizedPNL);
	DECODE_FIELD( commissionReport.yield);
	DECODE_FIELD( commissionReport.yieldRedemptionDate);

	m_pEWrapper->commissionReport( commissionReport);

	return ptr;
}

const char* EDecoder::processPositionDataMsg(const char* ptr, const char* endPtr) {
	int version;
	std::string account;
	double position;
	double avgCost = 0;

	DECODE_FIELD( version);
	DECODE_FIELD( account);

	// decode contract fields
	Contract contract;
	DECODE_FIELD( contract.conId);
	DECODE_FIELD( contract.symbol);
	DECODE_FIELD( contract.secType);
	DECODE_FIELD( contract.lastTradeDateOrContractMonth);
	DECODE_FIELD( contract.strike);
	DECODE_FIELD( contract.right);
	DECODE_FIELD( contract.multiplier);
	DECODE_FIELD( contract.exchange);
	DECODE_FIELD( contract.currency);
	DECODE_FIELD( contract.localSymbol);
	if (version >= 2) {
		DECODE_FIELD( contract.tradingClass);
	}

	if (m_serverVersion >= MIN_SERVER_VER_FRACTIONAL_POSITIONS)
	{
		DECODE_FIELD( position);
	}
	else
	{
		int iPosition;

		DECODE_FIELD(iPosition);

		position = iPosition;
	}

	if (version >= 3) {
		DECODE_FIELD( avgCost);
	}

	m_pEWrapper->position( account, contract, position, avgCost);

	return ptr;
}

const char* EDecoder::processPositionEndMsg(const char* ptr, const char* endPtr) {
	int version;

	DECODE_FIELD( version);

	m_pEWrapper->positionEnd();

	return ptr;
}

const char* EDecoder::processAccountSummaryMsg(const char* ptr, const char* endPtr) {
	int version;
	int reqId;
	std::string account;
	std::string tag;
	std::string value;
	std::string curency;

	DECODE_FIELD( version);
	DECODE_FIELD( reqId);
	DECODE_FIELD( account);
	DECODE_FIELD( tag);
	DECODE_FIELD( value);
	DECODE_FIELD( curency);

	m_pEWrapper->accountSummary( reqId, account, tag, value, curency);

	return ptr;
}

const char* EDecoder::processAccountSummaryEndMsg(const char* ptr, const char* endPtr) {
	int version;
	int reqId;

	DECODE_FIELD( version);
	DECODE_FIELD( reqId);

	m_pEWrapper->accountSummaryEnd( reqId);

	return ptr;
}

const char* EDecoder::processVerifyMessageApiMsg(const char* ptr, const char* endPtr) {
	int version;
	std::string apiData;

	DECODE_FIELD( version);
	DECODE_FIELD( apiData);

	m_pEWrapper->verifyMessageAPI( apiData);

	return ptr;
}

const char* EDecoder::processVerifyCompletedMsg(const char* ptr, const char* endPtr) {
	int version;
	std::string isSuccessful;
	std::string errorText;

	DECODE_FIELD( version);
	DECODE_FIELD( isSuccessful);
	DECODE_FIELD( errorText);

	bool bRes = isSuccessful == "true";

	m_pEWrapper->verifyCompleted( bRes, errorText);

	return ptr;
}

const char* EDecoder::processDisplayGroupListMsg(const char* ptr, const char* endPtr) {
	int version;
	int reqId;
	std::string groups;

	DECODE_FIELD( version);
	DECODE_FIELD( reqId);
	DECODE_FIELD( groups);

	m_pEWrapper->displayGroupList( reqId, groups);

	return ptr;
}

const char* EDecoder::processDisplayGroupUpdatedMsg(const char* ptr, const char* endPtr) {
	int version;
	int reqId;
	std::string contractInfo;

	DECODE_FIELD( version);
	DECODE_FIELD( reqId);
	DECODE_FIELD( contractInfo);

	m_pEWrapper->displayGroupUpdated( reqId, contractInfo);

	return ptr;
}

const char* EDecoder::processVerifyAndAuthMessageApiMsg(const char* ptr, const char* endPtr) {
	int version;
	std::string apiData;
	std::string xyzChallenge;

	DECODE_FIELD( version);
	DECODE_FIELD( apiData);
	DECODE_FIELD( xyzChallenge);

	m_pEWrapper->verifyAndAuthMessageAPI( apiData, xyzChallenge);

	return ptr;
}

const char* EDecoder::processVerifyAndAuthCompletedMsg(const char* ptr, const char* endPtr) {
	int version;
	std::string isSuccessful;
	std::string errorText;

	DECODE_FIELD( version);
	DECODE_FIELD( isSuccessful);
	DECODE_FIELD( errorText);

	bool bRes = isSuccessful == "true";

	m_pEWrapper->verifyAndAuthCompleted( bRes, errorText);

	return ptr;
}

const char* EDecoder::processPositionMultiMsg(const char* ptr, const char* endPtr) {
	int version;
	int reqId;
	std::string account;
	std::string modelCode;
	double position;
	double avgCost = 0;

	DECODE_FIELD( version);
	DECODE_FIELD( reqId);
	DECODE_FIELD( account);

	// decode contract fields
	Contract contract;
	DECODE_FIELD( contract.conId);
	DECODE_FIELD( contract.symbol);
	DECODE_FIELD( contract.secType);
	DECODE_FIELD( contract.lastTradeDateOrContractMonth);
	DECODE_FIELD( contract.strike);
	DECODE_FIELD( contract.right);
	DECODE_FIELD( contract.multiplier);
	DECODE_FIELD( contract.exchange);
	DECODE_FIELD( contract.currency);
	DECODE_FIELD( contract.localSymbol);
	DECODE_FIELD( contract.tradingClass);
	DECODE_FIELD( position);
	DECODE_FIELD( avgCost);
	DECODE_FIELD( modelCode);

	m_pEWrapper->positionMulti( reqId, account, modelCode, contract, position, avgCost);

	return ptr;
}

const char* EDecoder::processPositionMultiEndMsg(const char* ptr, const char* endPtr) {
	int version;
	int reqId;

	DECODE_FIELD( version);
	DECODE_FIELD( reqId);

	m_pEWrapper->positionMultiEnd( reqId);

	return ptr;
}

const char* EDecoder::processAccountUpdateMultiMsg(const char* ptr, const char* endPtr) {
	int version;
	int reqId;
	std::string account;
	std::string modelCode;
	std::string key;
	std::string value;
	std::string currency;

	DECODE_FIELD( version);
	DECODE_FIELD( reqId);
	DECODE_FIELD( account);
	DECODE_FIELD( modelCode);
	DECODE_FIELD( key);
	DECODE_FIELD( value);
	DECODE_FIELD( currency);

	m_pEWrapper->accountUpdateMulti( reqId, account, modelCode, key, value, currency);

	return ptr;
}

const char* EDecoder::processAccountUpdateMultiEndMsg(const char* ptr, const char* endPtr) {
	int version;
	int reqId;

	DECODE_FIELD( version);
	DECODE_FIELD( reqId);

	m_pEWrapper->accountUpdateMultiEnd( reqId);

	return ptr;
}

const char* EDecoder::processSecurityDefinitionOptionalParameterMsg(const char* ptr, const char* endPtr) {
	int reqId;
	std::string exchange;
	int underlyingConId;
	std::string tradingClass;
	std::string multiplier;
	int expirationsSize, strikesSize;
	std::set<std::string> expirations;
	std::set<double> strikes;

	DECODE_FIELD(reqId);
	DECODE_FIELD(exchange);
	DECODE_FIELD(underlyingConId);
	DECODE_FIELD(tradingClass);
	DECODE_FIELD(multiplier);
	DECODE_FIELD(expirationsSize);

	for (int i = 0; i < expirationsSize; i++) {
		std::string expiration;

		DECODE_FIELD(expiration);

		expirations.insert(expiration);
	}

	DECODE_FIELD(strikesSize);

	for (int i = 0; i < strikesSize; i++) {
		double strike;

		DECODE_FIELD(strike);

		strikes.insert(strike);
	}

	m_pEWrapper->securityDefinitionOptionalParameter(reqId, exchange, underlyingConId, tradingClass, multiplier, expirations, strikes);

	return ptr;
}

const char* EDecoder::processSecurityDefinitionOptionalParameterEndMsg(const char* ptr, const char* endPtr) {
	int reqId;

	DECODE_FIELD(reqId);

	m_pEWrapper->securityDefinitionOptionalParameterEnd(reqId);

	return ptr;
}

const char* EDecoder::processSoftDollarTiersMsg(const char* ptr, const char* endPtr) 
{
	int reqId;
	int nTiers;

	DECODE_FIELD(reqId);
	DECODE_FIELD(nTiers);

	std::vector<SoftDollarTier> tiers(nTiers); 

	for (int i = 0; i < nTiers; i++) {
		std::string name, value, dislplayName;

		DECODE_FIELD(name);
		DECODE_FIELD(value);
		DECODE_FIELD(dislplayName);

		tiers[i] = SoftDollarTier(name, value, value); 
	}

	m_pEWrapper->softDollarTiers(reqId, tiers);

	return ptr;
}

const char* EDecoder::processFamilyCodesMsg(const char* ptr, const char* endPtr) 
{
	typedef std::vector<FamilyCode> FamilyCodeList;
	FamilyCodeList familyCodes;
	int nFamilyCodes = 0;
	DECODE_FIELD( nFamilyCodes);

	if (nFamilyCodes > 0) {
		familyCodes.resize(nFamilyCodes);
		for( int i = 0; i < nFamilyCodes; ++i) {
			DECODE_FIELD( familyCodes[i].accountID);
			DECODE_FIELD( familyCodes[i].familyCodeStr);
		}
	}

	m_pEWrapper->familyCodes(familyCodes);

	return ptr;
}

const char* EDecoder::processSymbolSamplesMsg(const char* ptr, const char* endPtr) 
{
	int reqId;
	typedef std::vector<ContractDescription> ContractDescriptionList;
	ContractDescriptionList contractDescriptions;
	int nContractDescriptions = 0;
	DECODE_FIELD( reqId);
	DECODE_FIELD( nContractDescriptions);

	if (nContractDescriptions > 0) {
		contractDescriptions.resize(nContractDescriptions);
		for( int i = 0; i < nContractDescriptions; ++i) {
			ContractDescription& contractDescription = contractDescriptions[i];
			Contract& contract = contractDescription.contract;
			DECODE_FIELD( contract.conId);
			DECODE_FIELD( contract.symbol);
			DECODE_FIELD( contract.secType);
			DECODE_FIELD( contract.primaryExchange);
			DECODE_FIELD( contract.currency);

			int nDerivativeSecTypes = 0;
			DECODE_FIELD(nDerivativeSecTypes);
			if (nDerivativeSecTypes <= 0)
				continue;

			ContractDescription::DerivativeSecTypesList& derivativeSecTypes = contractDescription.derivativeSecTypes;
			derivativeSecTypes.resize(nDerivativeSecTypes);
			for (int j = 0; j < nDerivativeSecTypes; ++j){
				DECODE_FIELD( derivativeSecTypes[j]);
			}
		}
	}

	m_pEWrapper->symbolSamples(reqId, contractDescriptions);

	return ptr;
}

const char* EDecoder::processMktDepthExchangesMsg(const char* ptr, const char* endPtr) 
{
	typedef std::vector<DepthMktDataDescription> DepthMktDataDescriptionList;
	DepthMktDataDescriptionList depthMktDataDescriptions;
	int nDepthMktDataDescriptions = 0;
	DECODE_FIELD( nDepthMktDataDescriptions);

	if (nDepthMktDataDescriptions > 0) {
		depthMktDataDescriptions.resize(nDepthMktDataDescriptions);
		for( int i = 0; i < nDepthMktDataDescriptions; ++i) {
			if (m_serverVersion >= MIN_SERVER_VER_SERVICE_DATA_TYPE) {
				DECODE_FIELD( depthMktDataDescriptions[i].exchange);
				DECODE_FIELD( depthMktDataDescriptions[i].secType);
				DECODE_FIELD( depthMktDataDescriptions[i].listingExch);
				DECODE_FIELD( depthMktDataDescriptions[i].serviceDataType);
				DECODE_FIELD( depthMktDataDescriptions[i].aggGroup);
			} else {
				DECODE_FIELD( depthMktDataDescriptions[i].exchange);
				DECODE_FIELD( depthMktDataDescriptions[i].secType);
				bool isL2;
				DECODE_FIELD( isL2);
				depthMktDataDescriptions[i].serviceDataType = isL2 ? "Deep2" : "Deep";
			}
		}
	}

	m_pEWrapper->mktDepthExchanges(depthMktDataDescriptions);

	return ptr;
}

const char* EDecoder::processTickNewsMsg(const char* ptr, const char* endPtr) 
{
	int tickerId;
	time_t timeStamp;
	std::string providerCode;
	std::string articleId;
	std::string headline;
	std::string extraData;

	DECODE_FIELD( tickerId);
	DECODE_FIELD_TIME( timeStamp);
	DECODE_FIELD( providerCode);
	DECODE_FIELD( articleId);
	DECODE_FIELD( headline);
	DECODE_FIELD( extraData);

	m_pEWrapper->tickNews(tickerId, timeStamp, providerCode, articleId, headline, extraData);

	return ptr;
}

const char* EDecoder::processNewsProvidersMsg(const char* ptr, const char* endPtr) 
{
	typedef std::vector<NewsProvider> NewsProviderList;
	NewsProviderList newsProviders;
	int nNewsProviders = 0;
	DECODE_FIELD( nNewsProviders);

	if (nNewsProviders > 0) {
		newsProviders.resize(nNewsProviders);
		for( int i = 0; i < nNewsProviders; ++i) {
			DECODE_FIELD( newsProviders[i].providerCode);
			DECODE_FIELD( newsProviders[i].providerName);
		}
	}

	m_pEWrapper->newsProviders(newsProviders);

	return ptr;
}

const char* EDecoder::processNewsArticleMsg(const char* ptr, const char* endPtr) 
{
	int requestId;
	int articleType;
	std::string articleText;

	DECODE_FIELD( requestId);
	DECODE_FIELD( articleType);
	DECODE_FIELD( articleText);

	m_pEWrapper->newsArticle(requestId, articleType, articleText);

	return ptr;
}

const char* EDecoder::processHistoricalNewsMsg(const char* ptr, const char* endPtr) 
{
	int requestId;
	std::string time;
	std::string providerCode;
	std::string articleId;
	std::string headline;

	DECODE_FIELD( requestId);
	DECODE_FIELD( time);
	DECODE_FIELD( providerCode);
	DECODE_FIELD( articleId);
	DECODE_FIELD( headline);

	m_pEWrapper->historicalNews(requestId, time, providerCode, articleId, headline);

	return ptr;
}

const char* EDecoder::processHistoricalNewsEndMsg(const char* ptr, const char* endPtr) 
{
	int requestId;
	bool hasMore;

	DECODE_FIELD( requestId);
	DECODE_FIELD( hasMore);

	m_pEWrapper->historicalNewsEnd(requestId, hasMore);

	return ptr;
}

const char* EDecoder::processMarketRuleMsg(const char* ptr, const char* endPtr)
{
	int marketRuleId;
	typedef std::vector<PriceIncrement> PriceIncrementList;
	PriceIncrementList priceIncrements;
	int nPriceIncrements = 0;

	DECODE_FIELD( marketRuleId);
	DECODE_FIELD( nPriceIncrements);

	if (nPriceIncrements > 0) {
		priceIncrements.resize(nPriceIncrements);
		for( int i = 0; i < nPriceIncrements; ++i) {
			DECODE_FIELD( priceIncrements[i].lowEdge);
			DECODE_FIELD( priceIncrements[i].increment);
		}
	}

	m_pEWrapper->marketRule(marketRuleId, priceIncrements);

	return ptr;
}

int EDecoder::processConnectAck(const char*& beginPtr, const char* endPtr)
{
	// process a connect Ack message from the buffer;
	// return number of bytes consumed
	assert( beginPtr && beginPtr < endPtr);

	try {

		const char* ptr = beginPtr;

		// check server version
		DECODE_FIELD( m_serverVersion);

		// handle redirects
		if( m_serverVersion < 0) {
			m_serverVersion = 0;

			std::string hostport, host;
			int port = -1;

			DECODE_FIELD( hostport);

			std::string::size_type sep = hostport.find( ':');
			if( sep != std::string::npos) {
				host = hostport.substr(0, sep);
				port = atoi( hostport.c_str() + ++sep);
			}
			else {
				host = hostport;
			}

			if (m_pClientMsgSink)
				m_pClientMsgSink->redirect(host.c_str(), port);
		} else {
			std::string twsTime;

			if( m_serverVersion >= 20) {

				DECODE_FIELD(twsTime);
			}

			if (m_pClientMsgSink)
				m_pClientMsgSink->serverVersion(m_serverVersion, twsTime.c_str());

			m_pEWrapper->connectAck();
		}

		int processed = ptr - beginPtr;
		beginPtr = ptr;
		return processed;
	}
	catch(const std::exception& e) {
		m_pEWrapper->error( NO_VALID_ID, SOCKET_EXCEPTION.code(), SOCKET_EXCEPTION.msg() + e.what());
	}

	return 0;
}

const char* EDecoder::processSmartComponentsMsg(const char* ptr, const char* endPtr) {
	int reqId;
	int n;
	SmartComponentsMap theMap;

	DECODE_FIELD(reqId);
	DECODE_FIELD(n);

	for (int i = 0; i < n; i++) {
		int bitNumber;
		std::string exchange;
		char exchangeLetter;

		DECODE_FIELD(bitNumber);
		DECODE_FIELD(exchange);
		DECODE_FIELD(exchangeLetter);

		theMap[bitNumber] = std::make_tuple(exchange, exchangeLetter);
	}

	m_pEWrapper->smartComponents(reqId, theMap);
	
	return ptr;
}

const char* EDecoder::processTickReqParamsMsg(const char* ptr, const char* endPtr) {
	int tickerId;
	double minTick;
	std::string bboExchange;
	int snapshotPermissions;

	DECODE_FIELD(tickerId);
	DECODE_FIELD(minTick);
	DECODE_FIELD(bboExchange);
	DECODE_FIELD(snapshotPermissions);

	m_pEWrapper->tickReqParams(tickerId, minTick, bboExchange, snapshotPermissions);
	
	return ptr;
}

const char* EDecoder::processHeadTimestampMsg(const char* ptr, const char* endPtr) {
	int reqId;
	std::string headTimestamp;

	DECODE_FIELD(reqId);
	DECODE_FIELD(headTimestamp);

	m_pEWrapper->headTimestamp(reqId, headTimestamp);
	
	return ptr;
}

const char* EDecoder::processHistogramDataMsg(const char* ptr, const char* endPtr) {
	int reqId;
	int n;
	HistogramDataVector data;
	HistogramEntry entry;

	DECODE_FIELD(reqId);
	DECODE_FIELD(n);

	for (int i = 0; i < n; i++) {
		DECODE_FIELD(entry.price);
		DECODE_FIELD(entry.size);

		data.push_back(entry);
	}

	m_pEWrapper->histogramData(reqId, data);
	
	return ptr;
}

const char* EDecoder::processRerouteMktDataReqMsg(const char* ptr, const char* endPtr) {
	int reqId;
	int conId;
	std::string exchange;

	DECODE_FIELD(reqId);
	DECODE_FIELD(conId);
	DECODE_FIELD(exchange);

	m_pEWrapper->rerouteMktDataReq(reqId, conId, exchange);
	
	return ptr;
}

const char* EDecoder::processRerouteMktDepthReqMsg(const char* ptr, const char* endPtr) {
	int reqId;
	int conId;
	std::string exchange;

	DECODE_FIELD(reqId);
	DECODE_FIELD(conId);
	DECODE_FIELD(exchange);

	m_pEWrapper->rerouteMktDepthReq(reqId, conId, exchange);
	
	return ptr;
}

const char* EDecoder::processPnLMsg(const char* ptr, const char* endPtr) {
    int reqId;
    double dailyPnL;
    double unrealizedPnL = DBL_MAX;
    double realizedPnL = DBL_MAX;

    DECODE_FIELD(reqId)
    DECODE_FIELD(dailyPnL)

    if (m_serverVersion >= MIN_SERVER_VER_UNREALIZED_PNL) {
        DECODE_FIELD(unrealizedPnL)
    }

    if (m_serverVersion >= MIN_SERVER_VER_REALIZED_PNL) {
        DECODE_FIELD(realizedPnL)
    }

    m_pEWrapper->pnl(reqId, dailyPnL, unrealizedPnL, realizedPnL);
    
    return ptr;
}

const char* EDecoder::processPnLSingleMsg(const char* ptr, const char* endPtr) {
    int reqId;
    int pos;
    double dailyPnL;
    double unrealizedPnL = DBL_MAX;
    double realizedPnL = DBL_MAX;
    double value;

    DECODE_FIELD(reqId);
    DECODE_FIELD(pos);
    DECODE_FIELD(dailyPnL);

    if (m_serverVersion >= MIN_SERVER_VER_UNREALIZED_PNL) {
        DECODE_FIELD(unrealizedPnL)
    }

    if (m_serverVersion >= MIN_SERVER_VER_REALIZED_PNL) {
        DECODE_FIELD(realizedPnL)
    }

    DECODE_FIELD(value);


    m_pEWrapper->pnlSingle(reqId, pos, dailyPnL, unrealizedPnL, realizedPnL, value);

    return ptr;
}

template<typename T>
const char* EDecoder::processHistoricalTicks(const char* ptr, const char* endPtr) {
    int reqId, nTicks;
    bool done;

    DECODE_FIELD(reqId);
    DECODE_FIELD(nTicks);

    std::vector<T> ticks(nTicks);

    for (int i = 0; i < nTicks; i++) {
        T &tick = ticks[i];

        ptr = decodeTick(tick, ptr, endPtr);
    }

    DECODE_FIELD(done);

    callEWrapperCallBack(reqId, ticks, done);

    return ptr;
}


const char* EDecoder::decodeTick(HistoricalTick& tick, const char* ptr, const char* endPtr) {
    int nope;

    DECODE_FIELD(tick.time);
    DECODE_FIELD(nope);
    DECODE_FIELD(tick.price);
    DECODE_FIELD(tick.size);

    return ptr;
}

void EDecoder::callEWrapperCallBack(int reqId, const std::vector<HistoricalTick> &ticks, bool done) {
    m_pEWrapper->historicalTicks(reqId, ticks, done);
}

const char* EDecoder::decodeTick(HistoricalTickBidAsk& tick, const char* ptr, const char* endPtr) {
    DECODE_FIELD(tick.time);
    DECODE_FIELD(tick.mask);
    DECODE_FIELD(tick.priceBid);
    DECODE_FIELD(tick.priceAsk);
    DECODE_FIELD(tick.sizeBid);
    DECODE_FIELD(tick.sizeAsk);

    return ptr;
}

void EDecoder::callEWrapperCallBack(int reqId, const std::vector<HistoricalTickBidAsk> &ticks, bool done) {
    m_pEWrapper->historicalTicksBidAsk(reqId, ticks, done);
}

const char* EDecoder::decodeTick(HistoricalTickLast& tick, const char* ptr, const char* endPtr) {
    DECODE_FIELD(tick.time);
    DECODE_FIELD(tick.mask);
    DECODE_FIELD(tick.price);
    DECODE_FIELD(tick.size);
    DECODE_FIELD(tick.exchange);
    DECODE_FIELD(tick.specialConditions);

    return ptr;
}

void EDecoder::callEWrapperCallBack(int reqId, const std::vector<HistoricalTickLast> &ticks, bool done) {
    m_pEWrapper->historicalTicksLast(reqId, ticks, done);
}

const char* EDecoder::processHistoricalTicks(const char* ptr, const char* endPtr) {
    return processHistoricalTicks<HistoricalTick>(ptr, endPtr);
}

const char* EDecoder::processHistoricalTicksBidAsk(const char* ptr, const char* endPtr) {
    return processHistoricalTicks<HistoricalTickBidAsk>(ptr, endPtr);
}

const char* EDecoder::processHistoricalTicksLast(const char* ptr, const char* endPtr) {
    return processHistoricalTicks<HistoricalTickLast>(ptr, endPtr);
}

const char* EDecoder::processTickByTickDataMsg(const char* ptr, const char* endPtr) {
    int reqId;
    int tickType = 0;
	time_t time;

    DECODE_FIELD(reqId);
    DECODE_FIELD(tickType);
    DECODE_FIELD(time);

    if (tickType == 1 || tickType == 2) { // Last/AllLast
            double price;
            int size;
            int attrMask;
            TickAttrib attribs;
            std::string exchange;
            std::string specialConditions;

            DECODE_FIELD(price);
            DECODE_FIELD(size);
            DECODE_FIELD(attrMask);

            std::bitset<32> mask(attrMask);
            attribs.pastLimit = mask[0];
            attribs.unreported = mask[1];

            DECODE_FIELD(exchange);
            DECODE_FIELD(specialConditions);

            m_pEWrapper->tickByTickAllLast(reqId, tickType, time, price, size, attribs, exchange, specialConditions);

    } else if (tickType == 3) { // BidAsk
            double bidPrice;
            double askPrice;
            int bidSize;
            int askSize;
            int attrMask;
            DECODE_FIELD(bidPrice);
            DECODE_FIELD(askPrice);
            DECODE_FIELD(bidSize);
            DECODE_FIELD(askSize);
            DECODE_FIELD(attrMask);

            TickAttrib attribs;
            std::bitset<32> mask(attrMask);
            attribs.bidPastLow = mask[0];
            attribs.askPastHigh = mask[1];

            m_pEWrapper->tickByTickBidAsk(reqId, time, bidPrice, askPrice, bidSize, askSize, attribs);
    } else if (tickType == 4) { // MidPoint
            double midPoint;
            DECODE_FIELD(midPoint);

            m_pEWrapper->tickByTickMidPoint(reqId, time, midPoint);
    }

    return ptr;
}

int EDecoder::parseAndProcessMsg(const char*& beginPtr, const char* endPtr) {
	// process a single message from the buffer;
	// return number of bytes consumed

	assert( beginPtr && beginPtr < endPtr);

	if (m_serverVersion == 0)
		return processConnectAck(beginPtr, endPtr);

	try {

		const char* ptr = beginPtr;

		int msgId;
		DECODE_FIELD( msgId);

		switch( msgId) {
		case TICK_PRICE:
			ptr = processTickPriceMsg(ptr, endPtr);
			break;

		case TICK_SIZE:
			ptr = processTickSizeMsg(ptr, endPtr);
			break;

		case TICK_OPTION_COMPUTATION:
			ptr = processTickOptionComputationMsg(ptr, endPtr);
			break;

		case TICK_GENERIC:
			ptr = processTickGenericMsg(ptr, endPtr);
			break;

		case TICK_STRING:
			ptr = processTickStringMsg(ptr, endPtr);
			break;

		case TICK_EFP:
			ptr = processTickEfpMsg(ptr, endPtr);
			break;

		case ORDER_STATUS:
			ptr = processOrderStatusMsg(ptr, endPtr);
			break;

		case ERR_MSG:
			ptr = processErrMsgMsg(ptr, endPtr);
			break;

		case OPEN_ORDER:
			ptr = processOpenOrderMsg(ptr, endPtr);
			break;

		case ACCT_VALUE:
			ptr = processAcctValueMsg(ptr, endPtr);
			break;

		case PORTFOLIO_VALUE:
			ptr = processPortfolioValueMsg(ptr, endPtr);
			break;

		case ACCT_UPDATE_TIME:
			ptr = processAcctUpdateTimeMsg(ptr, endPtr);
			break;

		case NEXT_VALID_ID:
			ptr = processNextValidIdMsg(ptr, endPtr);
			break;

		case CONTRACT_DATA:
			ptr = processContractDataMsg(ptr, endPtr);
			break;

		case BOND_CONTRACT_DATA:
			ptr = processBondContractDataMsg(ptr, endPtr);
			break;

		case EXECUTION_DATA:
			ptr = processExecutionDetailsMsg(ptr, endPtr);
			break;

		case MARKET_DEPTH:
			ptr = processMarketDepthMsg(ptr, endPtr);
			break;

		case MARKET_DEPTH_L2:
			ptr = processMarketDepthL2Msg(ptr, endPtr);
			break;

		case NEWS_BULLETINS:
			ptr = processNewsBulletinsMsg(ptr, endPtr);
			break;

		case MANAGED_ACCTS:
			ptr = processManagedAcctsMsg(ptr, endPtr);
			break;

		case RECEIVE_FA:
			ptr = processReceiveFaMsg(ptr, endPtr);
			break;

		case HISTORICAL_DATA:
			ptr = processHistoricalDataMsg(ptr, endPtr);
			break;

		case SCANNER_DATA:
			ptr = processScannerDataMsg(ptr, endPtr);
			break;

		case SCANNER_PARAMETERS:
			ptr = processScannerParametersMsg(ptr, endPtr);
			break;

		case CURRENT_TIME:
			ptr = processCurrentTimeMsg(ptr, endPtr);
			break;

		case REAL_TIME_BARS:
			ptr = processRealTimeBarsMsg(ptr, endPtr);
			break;

		case FUNDAMENTAL_DATA:
			ptr = processFundamentalDataMsg(ptr, endPtr);
			break;

		case CONTRACT_DATA_END:
			ptr = processContractDataEndMsg(ptr, endPtr);
			break;

		case OPEN_ORDER_END:
			ptr = processOpenOrderEndMsg(ptr, endPtr);
			break;

		case ACCT_DOWNLOAD_END:
			ptr = processAcctDownloadEndMsg(ptr, endPtr);
			break;

		case EXECUTION_DATA_END:
			ptr = processExecutionDetailsEndMsg(ptr, endPtr);
			break;

		case DELTA_NEUTRAL_VALIDATION:
			ptr = processDeltaNeutralValidationMsg(ptr, endPtr);
			break;

		case TICK_SNAPSHOT_END:
			ptr = processTickSnapshotEndMsg(ptr, endPtr);
			break;

		case MARKET_DATA_TYPE:
			ptr = processMarketDataTypeMsg(ptr, endPtr);
			break;

		case COMMISSION_REPORT:
			ptr = processCommissionReportMsg(ptr, endPtr);
			break;

		case POSITION_DATA:
			ptr = processPositionDataMsg(ptr, endPtr);
			break;

		case POSITION_END:
			ptr = processPositionEndMsg(ptr, endPtr);
			break;

		case ACCOUNT_SUMMARY:
			ptr = processAccountSummaryMsg(ptr, endPtr);
			break;

		case ACCOUNT_SUMMARY_END:
			ptr = processAccountSummaryEndMsg(ptr, endPtr);
			break;

		case VERIFY_MESSAGE_API:
			ptr = processVerifyMessageApiMsg(ptr, endPtr);
			break;

		case VERIFY_COMPLETED:
			ptr = processVerifyCompletedMsg(ptr, endPtr);
			break;

		case DISPLAY_GROUP_LIST:
			ptr = processDisplayGroupListMsg(ptr, endPtr);
			break;

		case DISPLAY_GROUP_UPDATED:
			ptr = processDisplayGroupUpdatedMsg(ptr, endPtr);
			break;

		case VERIFY_AND_AUTH_MESSAGE_API:
			ptr = processVerifyAndAuthMessageApiMsg(ptr, endPtr);
			break;

		case VERIFY_AND_AUTH_COMPLETED:
			ptr = processVerifyAndAuthCompletedMsg(ptr, endPtr);
			break;

		case POSITION_MULTI:
			ptr = processPositionMultiMsg(ptr, endPtr);
			break;

		case POSITION_MULTI_END:
			ptr = processPositionMultiEndMsg(ptr, endPtr);
			break;

		case ACCOUNT_UPDATE_MULTI:
			ptr = processAccountUpdateMultiMsg(ptr, endPtr);
			break;

		case ACCOUNT_UPDATE_MULTI_END:
			ptr = processAccountUpdateMultiEndMsg(ptr, endPtr);
			break;

		case SECURITY_DEFINITION_OPTION_PARAMETER:
			ptr = processSecurityDefinitionOptionalParameterMsg(ptr, endPtr);
			break;

		case SECURITY_DEFINITION_OPTION_PARAMETER_END:
			ptr = processSecurityDefinitionOptionalParameterEndMsg(ptr, endPtr);
			break;

		case SOFT_DOLLAR_TIERS:
			ptr = processSoftDollarTiersMsg(ptr, endPtr);
			break;

		case FAMILY_CODES:
			ptr = processFamilyCodesMsg(ptr, endPtr);
			break;

		case SMART_COMPONENTS:
			ptr = processSmartComponentsMsg(ptr, endPtr);
			break;

		case TICK_REQ_PARAMS:
			ptr = processTickReqParamsMsg(ptr, endPtr);
			break;

		case SYMBOL_SAMPLES:
			ptr = processSymbolSamplesMsg(ptr, endPtr);
			break;

		case MKT_DEPTH_EXCHANGES:
			ptr = processMktDepthExchangesMsg(ptr, endPtr);
			break;			

		case TICK_NEWS:
			ptr = processTickNewsMsg(ptr, endPtr);
			break;

		case NEWS_PROVIDERS:
			ptr = processNewsProvidersMsg(ptr, endPtr);
			break;

		case NEWS_ARTICLE:
			ptr = processNewsArticleMsg(ptr, endPtr);
			break;

		case HISTORICAL_NEWS:
			ptr = processHistoricalNewsMsg(ptr, endPtr);
			break;

		case HISTORICAL_NEWS_END:
			ptr = processHistoricalNewsEndMsg(ptr, endPtr);
			break;

		case HEAD_TIMESTAMP:
			ptr = processHeadTimestampMsg(ptr, endPtr);
			break;

		case HISTOGRAM_DATA:
			ptr = processHistogramDataMsg(ptr, endPtr);
			break;

		case HISTORICAL_DATA_UPDATE:
			ptr = processHistoricalDataUpdateMsg(ptr, endPtr);
			break;

		case REROUTE_MKT_DATA_REQ:
			ptr = processRerouteMktDataReqMsg(ptr, endPtr);
			break;

		case REROUTE_MKT_DEPTH_REQ:
			ptr = processRerouteMktDepthReqMsg(ptr, endPtr);
			break;

		case MARKET_RULE:
			ptr = processMarketRuleMsg(ptr, endPtr);
			break;

        case PNL:
            ptr = processPnLMsg(ptr, endPtr);
            break;

        case PNL_SINGLE:
            ptr = processPnLSingleMsg(ptr, endPtr);
            break;

		case HISTORICAL_TICKS:
			ptr = processHistoricalTicks(ptr, endPtr);
			break;

        case HISTORICAL_TICKS_BID_ASK:
            ptr = processHistoricalTicksBidAsk(ptr, endPtr);
            break;

        case HISTORICAL_TICKS_LAST:
            ptr = processHistoricalTicksLast(ptr, endPtr);
            break;

        case TICK_BY_TICK:
            ptr = processTickByTickDataMsg(ptr, endPtr);
            break;

		default:
			{
				m_pEWrapper->error( msgId, UNKNOWN_ID.code(), UNKNOWN_ID.msg());
				m_pEWrapper->connectionClosed();
				break;
			}
		}

		if (!ptr)
			return 0;

		int processed = ptr - beginPtr;
		beginPtr = ptr;
		return processed;
	}
	catch(const std::exception& e) {
		m_pEWrapper->error( NO_VALID_ID, SOCKET_EXCEPTION.code(), SOCKET_EXCEPTION.msg() + e.what());
	}
	return 0;
}


bool EDecoder::CheckOffset(const char* ptr, const char* endPtr)
{
	assert (ptr && ptr <= endPtr);
	return (ptr && ptr < endPtr);
}

const char* EDecoder::FindFieldEnd(const char* ptr, const char* endPtr)
{
	return (const char*)memchr(ptr, 0, endPtr - ptr);
}

bool EDecoder::DecodeField(bool& boolValue, const char*& ptr, const char* endPtr)
{
	int intValue;
	if( !DecodeField(intValue, ptr, endPtr))
		return false;
	boolValue = (intValue > 0);
	return true;
}

bool EDecoder::DecodeField(int& intValue, const char*& ptr, const char* endPtr)
{
	if( !CheckOffset(ptr, endPtr))
		return false;
	const char* fieldBeg = ptr;
	const char* fieldEnd = FindFieldEnd(fieldBeg, endPtr);
	if( !fieldEnd)
		return false;
	intValue = atoi(fieldBeg);
	ptr = ++fieldEnd;
	return true;
}

bool EDecoder::DecodeFieldTime(time_t& time_tValue, const char*& ptr, const char* endPtr)
{
	if( !CheckOffset(ptr, endPtr))
		return false;
	const char* fieldBeg = ptr;
	const char* fieldEnd = FindFieldEnd(fieldBeg, endPtr);
	if( !fieldEnd)
		return false;
	time_tValue = atoll(fieldBeg);
	ptr = ++fieldEnd;
	return true;
}

bool EDecoder::DecodeField(long long& longLongValue, const char*& ptr, const char* endPtr)
{
	if( !CheckOffset(ptr, endPtr))
		return false;
	const char* fieldBeg = ptr;
	const char* fieldEnd = FindFieldEnd(fieldBeg, endPtr);
	if( !fieldEnd)
		return false;
	longLongValue = atoll(fieldBeg);
	ptr = ++fieldEnd;
	return true;
}

bool EDecoder::DecodeField(long& longValue, const char*& ptr, const char* endPtr)
{
	int intValue;
	if( !DecodeField(intValue, ptr, endPtr))
		return false;
	longValue = intValue;
	return true;
}

bool EDecoder::DecodeField(double& doubleValue, const char*& ptr, const char* endPtr)
{
	if( !CheckOffset(ptr, endPtr))
		return false;
	const char* fieldBeg = ptr;
	const char* fieldEnd = FindFieldEnd(fieldBeg, endPtr);
	if( !fieldEnd)
		return false;
	doubleValue = atof(fieldBeg);
	ptr = ++fieldEnd;
	return true;
}

bool EDecoder::DecodeField(std::string& stringValue,
						   const char*& ptr, const char* endPtr)
{
	if( !CheckOffset(ptr, endPtr))
		return false;
	const char* fieldBeg = ptr;
	const char* fieldEnd = FindFieldEnd(ptr, endPtr);
	if( !fieldEnd)
		return false;
	stringValue = fieldBeg; // better way?
	ptr = ++fieldEnd;
	return true;
}

bool EDecoder::DecodeField(char& charValue,
						   const char*& ptr, const char* endPtr)
{
	if( !CheckOffset(ptr, endPtr))
		return false;
	const char* fieldBeg = ptr;
	const char* fieldEnd = FindFieldEnd(ptr, endPtr);
	if( !fieldEnd)
		return false;
	charValue = fieldBeg[0]; // better way?
	ptr = ++fieldEnd;
	return true;
}

bool EDecoder::DecodeFieldMax(int& intValue, const char*& ptr, const char* endPtr)
{
	std::string stringValue;
	if( !DecodeField(stringValue, ptr, endPtr))
		return false;
	intValue = stringValue.empty() ? UNSET_INTEGER : atoi(stringValue.c_str());
	return true;
}

bool EDecoder::DecodeFieldMax(long& longValue, const char*& ptr, const char* endPtr)
{
	int intValue;
	if( !DecodeFieldMax(intValue, ptr, endPtr))
		return false;
	longValue = intValue;
	return true;
}

bool EDecoder::DecodeFieldMax(double& doubleValue, const char*& ptr, const char* endPtr)
{
	std::string stringValue;
	if( !DecodeField(stringValue, ptr, endPtr))
		return false;
	doubleValue = stringValue.empty() ? UNSET_DOUBLE : atof(stringValue.c_str());
	return true;
}
