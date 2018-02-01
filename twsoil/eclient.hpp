

/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#pragma once
#ifndef eclient_h__INCLUDED
#define eclient_h__INCLUDED


#include <memory>
#include <string>
#include <vector>
#include <iosfwd>
#include "CommonDefs.h"
#include "TagValue.h"
#include "Contract.h"

namespace ibapi {
namespace client_constants {

/////////////////////////////////////////////////////////////////////////////////
// SOCKET CLIENT VERSION CHANGE LOG : Incremented when the format of incomming
//                                    server responses change
/////////////////////////////////////////////////////////////////////////////////
// constants
// 6 = Added parentId to orderStatus
// 7 = The new execDetails event returned for an order filled status and reqExecDetails
//     Also added market depth support.
// 8 = Added 'lastFillPrice' to orderStatus and 'permId' to execDetails
// 9 = Added 'avgCost', 'unrealizedPNL', and 'unrealizedPNL' to updatePortfolio event
// 10 = Added 'serverId' to the 'open order' & 'order status' events.
//      We send back all the API open orders upon connection.
//      Added new methods reqAllOpenOrders, reqAutoOpenOrders()
//      Added FA support - reqExecution has filter.
//                       - reqAccountUpdates takes acct code.
// 11 = Added permId to openOrder event.
// 12 = Added IgnoreRth, hidden, and discretionaryAmt
// 13 = Added GoodAfterTime
// 14 = always send size on bid/ask/last tick
// 15 = send allocation string with open order
// 16 = can receive account name in account and portfolio updates, and fa params in openOrder
// 17 = can receive liquidation field in exec reports, and notAutoAvailable field in mkt data
// 18 = can receive good till date field in open order messages, and send backfill requests
// 19 = can receive new extended order attributes in OPEN_ORDER
// 20 = expects TWS time string on connection after server version >= 20, and parentId in open order
// 21 = can receive bond contract details.
// 22 = can receive price magnifier in contract details
// 23 = support for scanner
// 24 = can receive volatility order parameters in open order messages
// 25 = can receive HMDS query start and end times
// 26 = can receive option vols in option market data messages
// 27 = can receive delta neutral order type and delta neutral aux price
// 28 = can receive option model computation ticks
// 29 = can receive trail stop limit price in open order and can place them: API 8.91
// 30 = can receive extended bond contract def, new ticks, and trade count in bars
// 31 = can receive EFP extensions to scanner and market data, and combo legs on open orders
//    ; can receive RT bars
// 32 = can receive TickType.LAST_TIMESTAMP
// 33 = can receive ScaleNumComponents and ScaleComponentSize is open order messages
// 34 = can receive whatIf orders / order state
// 35 = can receive contId field for Contract objects
// 36 = can receive outsideRth field for Order objects
// 37 = can receive clearingAccount and clearingIntent for Order objects
// 38 = can receive multipier and primaryExchange in portfolio updates
//    ; can receive cumQty and avgPrice in execution
//    ; can receive fundamental data
//    ; can receive underComp for Contract objects
//    ; can receive reqId and end marker in contractDetails/bondContractDetails
//    ; can receive ScaleInitComponentSize and ScaleSubsComponentSize for Order objects
// 39 = can receive underConId in contractDetails
// 40 = can receive algoStrategy/algoParams in openOrder
// 41 = can receive end marker for openOrder
//    ; can receive end marker for account download
//    ; can receive end marker for executions download
// 42 = can receive deltaNeutralValidation
// 43 = can receive longName(companyName)
//    ; can receive listingExchange
//    ; can receive RTVolume tick
// 44 = can receive end market for ticker snapshot
// 45 = can receive notHeld field in openOrder
// 46 = can receive contractMonth, industry, category, subcategory fields in contractDetails
//    ; can receive timeZoneId, tradingHours, liquidHours fields in contractDetails
// 47 = can receive gamma, vega, theta, undPrice fields in TICK_OPTION_COMPUTATION
// 48 = can receive exemptCode in openOrder
// 49 = can receive hedgeType and hedgeParam in openOrder
// 50 = can receive optOutSmartRouting field in openOrder
// 51 = can receive smartComboRoutingParams in openOrder
// 52 = can receive deltaNeutralConId, deltaNeutralSettlingFirm, deltaNeutralClearingAccount and deltaNeutralClearingIntent in openOrder
// 53 = can receive orderRef in execution
// 54 = can receive scale order fields (PriceAdjustValue, PriceAdjustInterval, ProfitOffset, AutoReset,
//      InitPosition, InitFillQty and RandomPercent) in openOrder
// 55 = can receive orderComboLegs (price) in openOrder
// 56 = can receive trailingPercent in openOrder
// 57 = can receive commissionReport message
// 58 = can receive CUSIP/ISIN/etc. in contractDescription/bondContractDescription
// 59 = can receive evRule, evMultiplier in contractDescription/bondContractDescription/executionDetails
//      can receive multiplier in executionDetails
// 60 = can receive deltaNeutralOpenClose, deltaNeutralShortSale, deltaNeutralShortSaleSlot
//      and deltaNeutralDesignatedLocation in openOrder
//      can receive position, positionEnd, accountSummary and accountSummaryEnd
// 61 = can receive multiplier in openOrder
//      can receive tradingClass in openOrder, updatePortfolio, execDetails and position
// 62 = can receive avgCost in position message
// 63 = can receive verifyMessageAPI, verifyCompleted, displayGroupList and displayGroupUpdated messages
// 64 = can receive solicited attrib in openOrder message
// 65 = can receive verifyAndAuthMessageAPI and verifyAndAuthCompleted messages
// 66 = can receive randomize size and randomize price order fields

const int CLIENT_VERSION    = 66;


// outgoing msg id's
const int REQ_MKT_DATA                  = 1;
const int CANCEL_MKT_DATA               = 2;
const int PLACE_ORDER                   = 3;
const int CANCEL_ORDER                  = 4;
const int REQ_OPEN_ORDERS               = 5;
const int REQ_ACCT_DATA                 = 6;
const int REQ_EXECUTIONS                = 7;
const int REQ_IDS                       = 8;
const int REQ_CONTRACT_DATA             = 9;
const int REQ_MKT_DEPTH                 = 10;
const int CANCEL_MKT_DEPTH              = 11;
const int REQ_NEWS_BULLETINS            = 12;
const int CANCEL_NEWS_BULLETINS         = 13;
const int SET_SERVER_LOGLEVEL           = 14;
const int REQ_AUTO_OPEN_ORDERS          = 15;
const int REQ_ALL_OPEN_ORDERS           = 16;
const int REQ_MANAGED_ACCTS             = 17;
const int REQ_FA                        = 18;
const int REPLACE_FA                    = 19;
const int REQ_HISTORICAL_DATA           = 20;
const int EXERCISE_OPTIONS              = 21;
const int REQ_SCANNER_SUBSCRIPTION      = 22;
const int CANCEL_SCANNER_SUBSCRIPTION   = 23;
const int REQ_SCANNER_PARAMETERS        = 24;
const int CANCEL_HISTORICAL_DATA        = 25;
const int REQ_CURRENT_TIME              = 49;
const int REQ_REAL_TIME_BARS            = 50;
const int CANCEL_REAL_TIME_BARS         = 51;
const int REQ_FUNDAMENTAL_DATA          = 52;
const int CANCEL_FUNDAMENTAL_DATA       = 53;
const int REQ_CALC_IMPLIED_VOLAT        = 54;
const int REQ_CALC_OPTION_PRICE         = 55;
const int CANCEL_CALC_IMPLIED_VOLAT     = 56;
const int CANCEL_CALC_OPTION_PRICE      = 57;
const int REQ_GLOBAL_CANCEL             = 58;
const int REQ_MARKET_DATA_TYPE          = 59;
const int REQ_POSITIONS                 = 61;
const int REQ_ACCOUNT_SUMMARY           = 62;
const int CANCEL_ACCOUNT_SUMMARY        = 63;
const int CANCEL_POSITIONS              = 64;
const int VERIFY_REQUEST                = 65;
const int VERIFY_MESSAGE                = 66;
const int QUERY_DISPLAY_GROUPS          = 67;
const int SUBSCRIBE_TO_GROUP_EVENTS     = 68;
const int UPDATE_DISPLAY_GROUP          = 69;
const int UNSUBSCRIBE_FROM_GROUP_EVENTS = 70;
const int START_API                     = 71;
const int VERIFY_AND_AUTH_REQUEST       = 72;
const int VERIFY_AND_AUTH_MESSAGE       = 73;
const int REQ_POSITIONS_MULTI           = 74;
const int CANCEL_POSITIONS_MULTI        = 75;
const int REQ_ACCOUNT_UPDATES_MULTI     = 76;
const int CANCEL_ACCOUNT_UPDATES_MULTI  = 77;
const int REQ_SEC_DEF_OPT_PARAMS        = 78;
const int REQ_SOFT_DOLLAR_TIERS         = 79;
const int REQ_FAMILY_CODES              = 80;
const int REQ_MATCHING_SYMBOLS          = 81;
const int REQ_MKT_DEPTH_EXCHANGES       = 82;
const int REQ_SMART_COMPONENTS          = 83;
const int REQ_NEWS_ARTICLE              = 84;
const int REQ_NEWS_PROVIDERS            = 85;
const int REQ_HISTORICAL_NEWS           = 86;
const int REQ_HEAD_TIMESTAMP            = 87;
const int REQ_HISTOGRAM_DATA            = 88;
const int CANCEL_HISTOGRAM_DATA         = 89;
const int CANCEL_HEAD_TIMESTAMP         = 90;
const int REQ_MARKET_RULE               = 91;
const int REQ_PNL                       = 92;
const int CANCEL_PNL                    = 93;
const int REQ_PNL_SINGLE                = 94;
const int CANCEL_PNL_SINGLE             = 95;
const int REQ_HISTORICAL_TICKS          = 96;
const int REQ_TICK_BY_TICK_DATA         = 97;
const int CANCEL_TICK_BY_TICK_DATA      = 98;

// TWS New Bulletins constants
const int NEWS_MSG              = 1;    // standard IB news bulleting message
const int EXCHANGE_AVAIL_MSG    = 2;    // control message specifing that an exchange is available for trading
const int EXCHANGE_UNAVAIL_MSG  = 3;    // control message specifing that an exchange is unavailable for trading

} // namespace client_constants
} // namespace ibapi

struct Contract;
struct Order;
struct ExecutionFilter;
struct ScannerSubscription;
struct ETransport;

class EWrapper;
typedef std::vector<char> BytesVec;


class TWSAPIDLLEXP EClient
{
public:

	explicit EClient(EWrapper *ptr, ETransport *pTransport);
	virtual ~EClient();

	virtual void eDisconnect() = 0;

	int clientId() const { return m_clientId; }

	const std::string& optionalCapabilities() const;
	void setOptionalCapabilities(const std::string& optCapts);

	void setConnectOptions(const std::string& connectOptions);
	void disableUseV100Plus();
	bool usingV100Plus();

protected:

	void eConnectBase();
	void eDisconnectBase();

public:

	enum ConnState {
		CS_DISCONNECTED,
		CS_CONNECTING,
		CS_CONNECTED,
		CS_REDIRECT
	};

	// connection state
	ConnState connState() const;
	bool isConnected() const;

	const std::string& host() const { return m_host; }
	unsigned port() const { return m_port; }

public:

	// access to protected variables
	EWrapper * getWrapper() const;
protected:
	void setClientId(int clientId);
	void setExtraAuth(bool extraAuth);
	void setHost(const std::string& host);
	void setPort(unsigned port);

public:

	bool isInBufferEmpty() const;

	// override virtual funcs from EClient
	int serverVersion();
	std::string TwsConnectionTime();
	void reqMktData(TickerId id, const Contract& contract,
		const std::string& genericTicks, bool snapshot, bool regulatorySnaphsot, const TagValueListSPtr& mktDataOptions);
	void cancelMktData(TickerId id);
	void placeOrder(OrderId id, const Contract& contract, const Order& order);
	void cancelOrder(OrderId id) ;
	void reqOpenOrders();
	void reqAccountUpdates(bool subscribe, const std::string& acctCode);
	void reqExecutions(int reqId, const ExecutionFilter& filter);
	void reqIds(int numIds);
	void reqContractDetails(int reqId, const Contract& contract);
	void reqMktDepth(TickerId tickerId, const Contract& contract, int numRows, const TagValueListSPtr& mktDepthOptions);
	void cancelMktDepth(TickerId tickerId);
	void reqNewsBulletins(bool allMsgs);
	void cancelNewsBulletins();
	void setServerLogLevel(int level);
	void reqAutoOpenOrders(bool bAutoBind);
	void reqAllOpenOrders();
	void reqManagedAccts();
	void requestFA(faDataType pFaDataType);
	void replaceFA(faDataType pFaDataType, const std::string& cxml);
	void reqHistoricalData(TickerId id, const Contract& contract,
		const std::string& endDateTime, const std::string& durationStr,
		const std::string&  barSizeSetting, const std::string& whatToShow,
		int useRTH, int formatDate, bool keepUpToDate, const TagValueListSPtr& chartOptions);
	void exerciseOptions(TickerId tickerId, const Contract& contract,
		int exerciseAction, int exerciseQuantity,
		const std::string& account, int override);
	void cancelHistoricalData(TickerId tickerId );
	void reqRealTimeBars(TickerId id, const Contract& contract, int barSize,
		const std::string& whatToShow, bool useRTH, const TagValueListSPtr& realTimeBarsOptions);
	void cancelRealTimeBars(TickerId tickerId );
	void cancelScannerSubscription(int tickerId);
	void reqScannerParameters();
	void reqScannerSubscription(int tickerId, const ScannerSubscription& subscription, const TagValueListSPtr& scannerSubscriptionOptions);
	void reqCurrentTime();
	void reqFundamentalData(TickerId reqId, const Contract&, const std::string& reportType);
	void cancelFundamentalData(TickerId reqId);
	void calculateImpliedVolatility(TickerId reqId, const Contract& contract, double optionPrice, double underPrice);
	void calculateOptionPrice(TickerId reqId, const Contract& contract, double volatility, double underPrice);
	void cancelCalculateImpliedVolatility(TickerId reqId);
	void cancelCalculateOptionPrice(TickerId reqId);
	void reqGlobalCancel();
	void reqMarketDataType(int marketDataType);
	void reqPositions();
	void cancelPositions();
	void reqAccountSummary(int reqId, const std::string& groupName, const std::string& tags);
	void cancelAccountSummary(int reqId);
	void verifyRequest(const std::string& apiName, const std::string& apiVersion);
	void verifyMessage(const std::string& apiData);
	void verifyAndAuthRequest(const std::string& apiName, const std::string& apiVersion, const std::string& opaqueIsvKey);
	void verifyAndAuthMessage(const std::string& apiData, const std::string& xyzResponse);
	void queryDisplayGroups(int reqId);
	void subscribeToGroupEvents(int reqId, int groupId);
	void updateDisplayGroup(int reqId, const std::string& contractInfo);
	void unsubscribeFromGroupEvents(int reqId);
	void reqPositionsMulti(int reqId, const std::string& account, const std::string& modelCode);
	void cancelPositionsMulti(int reqId);
	void reqAccountUpdatessMulti(int reqId, const std::string& account, const std::string& modelCode, bool ledgerAndNLV);
	void cancelAccountUpdatesMulti(int reqId);
	void reqSecDefOptParams(int reqId, const std::string& underlyingSymbol, const std::string& futFopExchange, const std::string& underlyingSecType, int underlyingConId);
	void reqSoftDollarTiers(int reqId);
	void reqFamilyCodes();
	void reqMatchingSymbols(int reqId, const std::string& pattern);
	void reqMktDepthExchanges();
	void reqSmartComponents(int reqId, std::string bboExchange);
	void reqNewsProviders();
	void reqNewsArticle(int requestId, const std::string& providerCode, const std::string& articleId, const TagValueListSPtr& newsArticleOptions);
	void reqHistoricalNews(int requestId, int conId, const std::string& providerCodes, const std::string& startDateTime, const std::string& endDateTime, int totalResults, 
		const TagValueListSPtr& historicalNewsOptions);
	void reqHeadTimestamp(int tickerId, const Contract &contract, const std::string& whatToShow, int useRTH, int formatDate);
	void cancelHeadTimestamp(int tickerId);
	void reqHistogramData(int reqId, const Contract &contract, bool useRTH, const std::string& timePeriod);
	void cancelHistogramData(int reqId);
	void reqMarketRule(int marketRuleId);

	void reqPnL(int reqId, const std::string& account, const std::string& modelCode);
	void cancelPnL(int reqId);
	void reqPnLSingle(int reqId, const std::string& account, const std::string& modelCode, int conId);
	void cancelPnLSingle(int reqId);
    void reqHistoricalTicks(int reqId, const Contract &contract, const std::string& startDateTime,
            const std::string& endDateTime, int numberOfTicks, const std::string& whatToShow, int useRth, bool ignoreSize, const TagValueListSPtr& miscOptions);
    void reqTickByTickData(int reqId, const Contract &contract, const std::string& tickType);
    void cancelTickByTickData(int reqId);

private:

	virtual int receive(char* buf, size_t sz) = 0;

protected:

	virtual void prepareBufferImpl(std::ostream&) const = 0;
	virtual void prepareBuffer(std::ostream&) const = 0;
	virtual bool closeAndSend(std::string msg, unsigned offset = 0) = 0;
	virtual int bufferedSend(const std::string& msg);

protected:
	int bufferedRead();

	// try to process connection request ack
private:
	// try to process single msg
	int processMsgImpl(const char*& ptr, const char* endPtr);
	int processMsg(const char*& ptr, const char* endPtr);

	typedef int (EClient::*messageHandler)(const char*& ptr, const char* endPtr);
	int processOnePrefixedMsg(const char*& ptr, const char* endPtr, messageHandler);

public:
	void startApi();


	// encoders
	template<class T> static void EncodeField(std::ostream&, T);

    void EncodeContract(std::ostream& os, const Contract &contract);
    void EncodeTagValueList(std::ostream& os, const TagValueListSPtr &tagValueList);

	// "max" encoders
	static void EncodeFieldMax(std::ostream& os, int);
	static void EncodeFieldMax(std::ostream& os, double);

	// socket state
private:
	virtual bool isSocketOK() const = 0;

protected:

	bool isConnecting() const;
	int sendConnectRequest();
    bool extraAuth();

protected:

	EWrapper *m_pEWrapper;
	std::unique_ptr<ETransport> m_transport;

private:
	BytesVec m_inBuffer;

	std::string m_host;
	int m_port;

	int m_clientId;

	ConnState m_connState;
	bool m_extraAuth;

protected:
	int m_serverVersion;
	std::string m_TwsTime;

private:
	std::string m_optionalCapabilities;

	std::string m_connectOptions;

protected:
	bool m_useV100Plus;

};

template<> void EClient::EncodeField<bool>(std::ostream& os, bool);
template<> void EClient::EncodeField<double>(std::ostream& os, double);

#define ENCODE_CONTRACT(x) EClient::EncodeContract(msg, x);
#define ENCODE_TAGVALUELIST(x) EClient::EncodeTagValueList(msg, x);
#define ENCODE_FIELD(x) EClient::EncodeField(msg, x);
#define ENCODE_FIELD_MAX(x) EClient::EncodeFieldMax(msg, x);


#endif



/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
* and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#include "StdAfx.h"

#include "EPosixClientSocketPlatform.h"

#include "EClient.h"

#include "EWrapper.h"
#include "TwsSocketClientErrors.h"
#include "Contract.h"
#include "Order.h"
#include "OrderState.h"
#include "Execution.h"
#include "ScannerSubscription.h"
#include "CommissionReport.h"
#include "EDecoder.h"
#include "EMessage.h"
#include "ETransport.h"
#include "FamilyCode.h"

#include <sstream>
#include <iomanip>
#include <algorithm>

#include <stdio.h>
#include <string.h>
#include <assert.h>

using namespace ibapi::client_constants;

///////////////////////////////////////////////////////////
// encoders
template<class T>
void EClient::EncodeField(std::ostream& os, T value)
{
	os << value << '\0';
}

template<>
void EClient::EncodeField<bool>(std::ostream& os, bool boolValue)
{
	EncodeField<int>(os, boolValue ? 1 : 0);
}

template<>
void EClient::EncodeField<double>(std::ostream& os, double doubleValue)
{
	char str[128];

	snprintf(str, sizeof(str), "%.10g", doubleValue);

	EncodeField<const char*>(os, str);
}

void EClient::EncodeContract(std::ostream& os, const Contract &contract)
{
	EncodeField(os, contract.conId);
	EncodeField(os, contract.symbol);
	EncodeField(os, contract.secType);
	EncodeField(os, contract.lastTradeDateOrContractMonth);
	EncodeField(os, contract.strike);
	EncodeField(os, contract.right);
	EncodeField(os, contract.multiplier);
	EncodeField(os, contract.exchange);
	EncodeField(os, contract.primaryExchange);
	EncodeField(os, contract.currency);
	EncodeField(os, contract.localSymbol);
	EncodeField(os, contract.tradingClass);
	EncodeField(os, contract.includeExpired);
}

void EClient::EncodeTagValueList(std::ostream& os, const TagValueListSPtr &tagValueList) 
{
    std::string tagValueListStr("");
    const int tagValueListCount = tagValueList.get() ? tagValueList->size() : 0;
    
    if (tagValueListCount > 0) {
        for (int i = 0; i < tagValueListCount; ++i) {
            const TagValue* tagValue = ((*tagValueList)[i]).get();

            tagValueListStr += tagValue->tag;
            tagValueListStr += "=";
            tagValueListStr += tagValue->value;
            tagValueListStr += ";";
        }
    }

    EncodeField(os, tagValueListStr);
}

///////////////////////////////////////////////////////////
// "max" encoders
void EClient::EncodeFieldMax(std::ostream& os, int intValue)
{
	if( intValue == INT_MAX) {
		EncodeField(os, "");
		return;
	}
	EncodeField(os, intValue);
}

void EClient::EncodeFieldMax(std::ostream& os, double doubleValue)
{
	if( doubleValue == DBL_MAX) {
		EncodeField(os, "");
		return;
	}
	EncodeField(os, doubleValue);
}


///////////////////////////////////////////////////////////
// member funcs
EClient::EClient( EWrapper *ptr, ETransport *pTransport)
	: m_pEWrapper(ptr)
	, m_transport(pTransport)
	, m_clientId(-1)
	, m_connState(CS_DISCONNECTED)
	, m_extraAuth(false)
	, m_serverVersion(0)
	, m_useV100Plus(true)
{
}

EClient::~EClient()
{
}

EClient::ConnState EClient::connState() const
{
	return m_connState;
}

bool EClient::isConnected() const
{
	return m_connState == CS_CONNECTED;
}

bool EClient::isConnecting() const
{
	return m_connState == CS_CONNECTING;
}

void EClient::eConnectBase()
{
}

void EClient::eDisconnectBase()
{
	m_TwsTime.clear();
	m_serverVersion = 0;
	m_connState = CS_DISCONNECTED;
	m_extraAuth = false;
	m_clientId = -1;
	m_inBuffer.clear();
}

int EClient::serverVersion()
{
	return m_serverVersion;
}

std::string EClient::TwsConnectionTime()
{
	return m_TwsTime;
}

const std::string& EClient::optionalCapabilities() const
{
	return m_optionalCapabilities;
}

void EClient::setOptionalCapabilities(const std::string& optCapts)
{
	m_optionalCapabilities = optCapts;
}

void EClient::setConnectOptions(const std::string& connectOptions)
{
	if( isSocketOK()) {
		m_pEWrapper->error( NO_VALID_ID, ALREADY_CONNECTED.code(), ALREADY_CONNECTED.msg());
		return;
	}

	m_connectOptions = connectOptions;
}

void EClient::disableUseV100Plus()
{
	if( isSocketOK()) {
		m_pEWrapper->error( NO_VALID_ID, ALREADY_CONNECTED.code(), ALREADY_CONNECTED.msg());
		return;
	}

	m_useV100Plus = false;
	m_connectOptions = "";
}

bool EClient::usingV100Plus() {
	return m_useV100Plus;
}

int EClient::bufferedSend(const std::string& msg) {
	EMessage emsg(std::vector<char>(msg.begin(), msg.end()));

	return m_transport->send(&emsg);
}

void EClient::reqMktData(TickerId tickerId, const Contract& contract,
						 const std::string& genericTicks, bool snapshot, bool regulatorySnaphsot, const TagValueListSPtr& mktDataOptions)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( tickerId, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	// not needed anymore validation
	//if( m_serverVersion < MIN_SERVER_VER_SNAPSHOT_MKT_DATA && snapshot) {
	//	m_pEWrapper->error( tickerId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
	//		"  It does not support snapshot market data requests.");
	//	return;
	//}

	if( m_serverVersion < MIN_SERVER_VER_UNDER_COMP) {
		if( contract.underComp) {
			m_pEWrapper->error( tickerId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support delta-neutral orders.");
			return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_REQ_MKT_DATA_CONID) {
		if( contract.conId > 0) {
			m_pEWrapper->error( tickerId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support conId parameter.");
			return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_TRADING_CLASS) {
		if( !contract.tradingClass.empty() ) {
			m_pEWrapper->error( tickerId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support tradingClass parameter in reqMktData.");
			return;
		}
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 11;

	// send req mkt data msg
	ENCODE_FIELD( REQ_MKT_DATA);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( tickerId);

	// send contract fields
	if( m_serverVersion >= MIN_SERVER_VER_REQ_MKT_DATA_CONID) {
		ENCODE_FIELD( contract.conId);
	}
	ENCODE_FIELD( contract.symbol);
	ENCODE_FIELD( contract.secType);
	ENCODE_FIELD( contract.lastTradeDateOrContractMonth);
	ENCODE_FIELD( contract.strike);
	ENCODE_FIELD( contract.right);
	ENCODE_FIELD( contract.multiplier); // srv v15 and above

	ENCODE_FIELD( contract.exchange);
	ENCODE_FIELD( contract.primaryExchange); // srv v14 and above
	ENCODE_FIELD( contract.currency);

	ENCODE_FIELD( contract.localSymbol); // srv v2 and above

	if( m_serverVersion >= MIN_SERVER_VER_TRADING_CLASS) {
		ENCODE_FIELD( contract.tradingClass);
	}

	// Send combo legs for BAG requests (srv v8 and above)
	if( contract.secType == "BAG")
	{
		const Contract::ComboLegList* const comboLegs = contract.comboLegs.get();
		const int comboLegsCount = comboLegs ? comboLegs->size() : 0;
		ENCODE_FIELD( comboLegsCount);
		if( comboLegsCount > 0) {
			for( int i = 0; i < comboLegsCount; ++i) {
				const ComboLeg* comboLeg = ((*comboLegs)[i]).get();
				assert( comboLeg);
				ENCODE_FIELD( comboLeg->conId);
				ENCODE_FIELD( comboLeg->ratio);
				ENCODE_FIELD( comboLeg->action);
				ENCODE_FIELD( comboLeg->exchange);
			}
		}
	}

	if( m_serverVersion >= MIN_SERVER_VER_UNDER_COMP) {
		if( contract.underComp) {
			const UnderComp& underComp = *contract.underComp;
			ENCODE_FIELD( true);
			ENCODE_FIELD( underComp.conId);
			ENCODE_FIELD( underComp.delta);
			ENCODE_FIELD( underComp.price);
		}
		else {
			ENCODE_FIELD( false);
		}
	}

	ENCODE_FIELD( genericTicks); // srv v31 and above
	ENCODE_FIELD( snapshot); // srv v35 and above

	if (m_serverVersion >= MIN_SERVER_VER_REQ_SMART_COMPONENTS) {
		ENCODE_FIELD(regulatorySnaphsot);
	}

	// send mktDataOptions parameter
	if( m_serverVersion >= MIN_SERVER_VER_LINKING) {
		ENCODE_TAGVALUELIST(mktDataOptions);
	}

	closeAndSend( msg.str());
}

void EClient::cancelMktData(TickerId tickerId)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( tickerId, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 2;

	// send cancel mkt data msg
	ENCODE_FIELD( CANCEL_MKT_DATA);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( tickerId);

	closeAndSend( msg.str());
}

void EClient::reqMktDepth( TickerId tickerId, const Contract& contract, int numRows, const TagValueListSPtr& mktDepthOptions)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( tickerId, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	// Not needed anymore validation
	// This feature is only available for versions of TWS >=6
	//if( m_serverVersion < 6) {
	//	m_pEWrapper->error( NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg());
	//	return;
	//}

	if (m_serverVersion < MIN_SERVER_VER_TRADING_CLASS) {
		if( !contract.tradingClass.empty() || (contract.conId > 0)) {
			m_pEWrapper->error( tickerId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support conId and tradingClass parameters in reqMktDepth.");
			return;
		}
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 5;

	// send req mkt data msg
	ENCODE_FIELD( REQ_MKT_DEPTH);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( tickerId);

	// send contract fields
	if( m_serverVersion >= MIN_SERVER_VER_TRADING_CLASS) {
		ENCODE_FIELD( contract.conId);
	}
	ENCODE_FIELD( contract.symbol);
	ENCODE_FIELD( contract.secType);
	ENCODE_FIELD( contract.lastTradeDateOrContractMonth);
	ENCODE_FIELD( contract.strike);
	ENCODE_FIELD( contract.right);
	ENCODE_FIELD( contract.multiplier); // srv v15 and above
	ENCODE_FIELD( contract.exchange);
	ENCODE_FIELD( contract.currency);
	ENCODE_FIELD( contract.localSymbol);
	if( m_serverVersion >= MIN_SERVER_VER_TRADING_CLASS) {
		ENCODE_FIELD( contract.tradingClass);
	}

	ENCODE_FIELD( numRows); // srv v19 and above

	// send mktDepthOptions parameter
	if( m_serverVersion >= MIN_SERVER_VER_LINKING) {
		ENCODE_TAGVALUELIST(mktDepthOptions);
	}

	closeAndSend( msg.str());
}


void EClient::cancelMktDepth( TickerId tickerId)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( tickerId, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	// Not needed anymore validation
	// This feature is only available for versions of TWS >=6
	//if( m_serverVersion < 6) {
	//	m_pEWrapper->error( NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg());
	//	return;
	//}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	// send cancel mkt data msg
	ENCODE_FIELD( CANCEL_MKT_DEPTH);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( tickerId);

	closeAndSend( msg.str());
}

void EClient::reqHistoricalData(TickerId tickerId, const Contract& contract,
								const std::string& endDateTime, const std::string& durationStr,
								const std::string&  barSizeSetting, const std::string& whatToShow,
								int useRTH, int formatDate, bool keepUpToDate, const TagValueListSPtr& chartOptions)
{
	// not connected?
	if (!isConnected()) {
		m_pEWrapper->error(tickerId, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	// Not needed anymore validation
	//if (m_serverVersion < 16) {
	//	m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg());
	//	return;
	//}

	if (m_serverVersion < MIN_SERVER_VER_TRADING_CLASS) {
		if (!contract.tradingClass.empty() || (contract.conId > 0)) {
			m_pEWrapper->error(tickerId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support conId and tradingClass parameters in reqHistoricalData.");
			return;
		}
	}

	std::stringstream msg;
	prepareBuffer(msg);

	const int VERSION = 6;

	ENCODE_FIELD(REQ_HISTORICAL_DATA);

	if (m_serverVersion < MIN_SERVER_VER_SYNT_REALTIME_BARS) {
		ENCODE_FIELD(VERSION);
	}
	
	ENCODE_FIELD(tickerId);

	// send contract fields
	if (m_serverVersion >= MIN_SERVER_VER_TRADING_CLASS) {
		ENCODE_FIELD(contract.conId);
	}
	ENCODE_FIELD(contract.symbol);
	ENCODE_FIELD(contract.secType);
	ENCODE_FIELD(contract.lastTradeDateOrContractMonth);
	ENCODE_FIELD(contract.strike);
	ENCODE_FIELD(contract.right);
	ENCODE_FIELD(contract.multiplier);
	ENCODE_FIELD(contract.exchange);
	ENCODE_FIELD(contract.primaryExchange);
	ENCODE_FIELD(contract.currency);
	ENCODE_FIELD(contract.localSymbol);
	if (m_serverVersion >= MIN_SERVER_VER_TRADING_CLASS) {
		ENCODE_FIELD(contract.tradingClass);
	}
	ENCODE_FIELD(contract.includeExpired); // srv v31 and above

	ENCODE_FIELD(endDateTime); // srv v20 and above
	ENCODE_FIELD(barSizeSetting); // srv v20 and above

	ENCODE_FIELD(durationStr);
	ENCODE_FIELD(useRTH);
	ENCODE_FIELD(whatToShow);
	ENCODE_FIELD(formatDate); // srv v16 and above

	// Send combo legs for BAG requests
	if (contract.secType == "BAG")
	{
		const Contract::ComboLegList* const comboLegs = contract.comboLegs.get();
		const int comboLegsCount = comboLegs ? comboLegs->size() : 0;
		ENCODE_FIELD(comboLegsCount);
		if (comboLegsCount > 0) {
			for(int i = 0; i < comboLegsCount; ++i) {
				const ComboLeg* comboLeg = ((*comboLegs)[i]).get();
				assert(comboLeg);
				ENCODE_FIELD(comboLeg->conId);
				ENCODE_FIELD(comboLeg->ratio);
				ENCODE_FIELD(comboLeg->action);
				ENCODE_FIELD(comboLeg->exchange);
			}
		}
	}
	
	if (m_serverVersion >= MIN_SERVER_VER_SYNT_REALTIME_BARS) {
		ENCODE_FIELD(keepUpToDate);
    }

	// send chartOptions parameter
	if (m_serverVersion >= MIN_SERVER_VER_LINKING) {
		ENCODE_TAGVALUELIST(chartOptions);
	}

	closeAndSend(msg.str());
}

void EClient::cancelHistoricalData(TickerId tickerId)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( tickerId, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	// Not needed anymore validation
	//if( m_serverVersion < 24) {
	//	m_pEWrapper->error( NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
	//		"  It does not support historical data query cancellation.");
	//	return;
	//}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( CANCEL_HISTORICAL_DATA);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( tickerId);

	closeAndSend( msg.str());
}

void EClient::reqRealTimeBars(TickerId tickerId, const Contract& contract,
							  int barSize, const std::string& whatToShow, bool useRTH,
							  const TagValueListSPtr& realTimeBarsOptions)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( tickerId, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	// Not needed anymore validation
	//if( m_serverVersion < MIN_SERVER_VER_REAL_TIME_BARS) {
	//	m_pEWrapper->error( NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
	//		"  It does not support real time bars.");
	//	return;
	//}

	if (m_serverVersion < MIN_SERVER_VER_TRADING_CLASS) {
		if( !contract.tradingClass.empty() || (contract.conId > 0)) {
			m_pEWrapper->error( tickerId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support conId and tradingClass parameters in reqRealTimeBars.");
			return;
		}
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 3;

	ENCODE_FIELD( REQ_REAL_TIME_BARS);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( tickerId);

	// send contract fields
	if( m_serverVersion >= MIN_SERVER_VER_TRADING_CLASS) {
		ENCODE_FIELD( contract.conId);
	}
	ENCODE_FIELD( contract.symbol);
	ENCODE_FIELD( contract.secType);
	ENCODE_FIELD( contract.lastTradeDateOrContractMonth);
	ENCODE_FIELD( contract.strike);
	ENCODE_FIELD( contract.right);
	ENCODE_FIELD( contract.multiplier);
	ENCODE_FIELD( contract.exchange);
	ENCODE_FIELD( contract.primaryExchange);
	ENCODE_FIELD( contract.currency);
	ENCODE_FIELD( contract.localSymbol);
	if( m_serverVersion >= MIN_SERVER_VER_TRADING_CLASS) {
		ENCODE_FIELD( contract.tradingClass);
	}
	ENCODE_FIELD( barSize);
	ENCODE_FIELD( whatToShow);
	ENCODE_FIELD( useRTH);

	// send realTimeBarsOptions parameter
	if( m_serverVersion >= MIN_SERVER_VER_LINKING) {
		ENCODE_TAGVALUELIST(realTimeBarsOptions);
	}

	closeAndSend( msg.str());
}


void EClient::cancelRealTimeBars(TickerId tickerId)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( tickerId, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	// Not needed anymore validation
	//if( m_serverVersion < MIN_SERVER_VER_REAL_TIME_BARS) {
	//	m_pEWrapper->error( NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
	//		"  It does not support realtime bar data query cancellation.");
	//	return;
	//}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( CANCEL_REAL_TIME_BARS);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( tickerId);

	closeAndSend( msg.str());
}


void EClient::reqScannerParameters()
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	// Not needed anymore validation
	//if( m_serverVersion < 24) {
	//	m_pEWrapper->error( NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
	//		"  It does not support API scanner subscription.");
	//	return;
	//}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( REQ_SCANNER_PARAMETERS);
	ENCODE_FIELD( VERSION);

	closeAndSend( msg.str());
}


void EClient::reqScannerSubscription(int tickerId,
									 const ScannerSubscription& subscription, const TagValueListSPtr& scannerSubscriptionOptions)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( tickerId, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	// Not needed anymore validation
	//if( m_serverVersion < 24) {
	//	m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
	//		"  It does not support API scanner subscription.");
	//	return;
	//}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 4;

	ENCODE_FIELD( REQ_SCANNER_SUBSCRIPTION);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( tickerId);
	ENCODE_FIELD_MAX( subscription.numberOfRows);
	ENCODE_FIELD( subscription.instrument);
	ENCODE_FIELD( subscription.locationCode);
	ENCODE_FIELD( subscription.scanCode);
	ENCODE_FIELD_MAX( subscription.abovePrice);
	ENCODE_FIELD_MAX( subscription.belowPrice);
	ENCODE_FIELD_MAX( subscription.aboveVolume);
	ENCODE_FIELD_MAX( subscription.marketCapAbove);
	ENCODE_FIELD_MAX( subscription.marketCapBelow);
	ENCODE_FIELD( subscription.moodyRatingAbove);
	ENCODE_FIELD( subscription.moodyRatingBelow);
	ENCODE_FIELD( subscription.spRatingAbove);
	ENCODE_FIELD( subscription.spRatingBelow);
	ENCODE_FIELD( subscription.maturityDateAbove);
	ENCODE_FIELD( subscription.maturityDateBelow);
	ENCODE_FIELD_MAX( subscription.couponRateAbove);
	ENCODE_FIELD_MAX( subscription.couponRateBelow);
	ENCODE_FIELD_MAX( subscription.excludeConvertible);
	ENCODE_FIELD_MAX( subscription.averageOptionVolumeAbove); // srv v25 and above
	ENCODE_FIELD( subscription.scannerSettingPairs); // srv v25 and above
	ENCODE_FIELD( subscription.stockTypeFilter); // srv v27 and above

	// send scannerSubscriptionOptions parameter
	if( m_serverVersion >= MIN_SERVER_VER_LINKING) {
		ENCODE_TAGVALUELIST(scannerSubscriptionOptions);
	}

	closeAndSend( msg.str());
}

void EClient::cancelScannerSubscription(int tickerId)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( tickerId, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	// Not needed anymore validation
	//if( m_serverVersion < 24) {
	//	m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
	//		"  It does not support API scanner subscription.");
	//	return;
	//}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( CANCEL_SCANNER_SUBSCRIPTION);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( tickerId);

	closeAndSend( msg.str());
}

void EClient::reqFundamentalData(TickerId reqId, const Contract& contract, 
								 const std::string& reportType)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( reqId, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_FUNDAMENTAL_DATA) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support fundamental data requests.");
		return;
	}

	if (m_serverVersion < MIN_SERVER_VER_TRADING_CLASS) {
		if( contract.conId > 0) {
			m_pEWrapper->error( reqId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support conId parameter in reqFundamentalData.");
			return;
		}
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 2;

	ENCODE_FIELD( REQ_FUNDAMENTAL_DATA);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( reqId);

	// send contract fields
	if( m_serverVersion >= MIN_SERVER_VER_TRADING_CLASS) {
		ENCODE_FIELD( contract.conId);
	}
	ENCODE_FIELD( contract.symbol);
	ENCODE_FIELD( contract.secType);
	ENCODE_FIELD( contract.exchange);
	ENCODE_FIELD( contract.primaryExchange);
	ENCODE_FIELD( contract.currency);
	ENCODE_FIELD( contract.localSymbol);

	ENCODE_FIELD( reportType);

	closeAndSend( msg.str());
}

void EClient::cancelFundamentalData( TickerId reqId)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( reqId, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_FUNDAMENTAL_DATA) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support fundamental data requests.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( CANCEL_FUNDAMENTAL_DATA);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( reqId);

	closeAndSend( msg.str());
}

void EClient::calculateImpliedVolatility(TickerId reqId, const Contract& contract, double optionPrice, double underPrice) {

	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if (m_serverVersion < MIN_SERVER_VER_REQ_CALC_IMPLIED_VOLAT) {
		m_pEWrapper->error( reqId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support calculate implied volatility requests.");
		return;
	}

	if (m_serverVersion < MIN_SERVER_VER_TRADING_CLASS) {
		if( !contract.tradingClass.empty()) {
			m_pEWrapper->error( reqId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support tradingClass parameter in calculateImpliedVolatility.");
			return;
		}
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 2;

	ENCODE_FIELD( REQ_CALC_IMPLIED_VOLAT);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( reqId);

	// send contract fields
	ENCODE_FIELD( contract.conId);
	ENCODE_FIELD( contract.symbol);
	ENCODE_FIELD( contract.secType);
	ENCODE_FIELD( contract.lastTradeDateOrContractMonth);
	ENCODE_FIELD( contract.strike);
	ENCODE_FIELD( contract.right);
	ENCODE_FIELD( contract.multiplier);
	ENCODE_FIELD( contract.exchange);
	ENCODE_FIELD( contract.primaryExchange);
	ENCODE_FIELD( contract.currency);
	ENCODE_FIELD( contract.localSymbol);
	if( m_serverVersion >= MIN_SERVER_VER_TRADING_CLASS) {
		ENCODE_FIELD( contract.tradingClass);
	}

	ENCODE_FIELD( optionPrice);
	ENCODE_FIELD( underPrice);

	closeAndSend( msg.str());
}

void EClient::cancelCalculateImpliedVolatility(TickerId reqId) {

	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if (m_serverVersion < MIN_SERVER_VER_CANCEL_CALC_IMPLIED_VOLAT) {
		m_pEWrapper->error( reqId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support calculate implied volatility cancellation.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( CANCEL_CALC_IMPLIED_VOLAT);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( reqId);

	closeAndSend( msg.str());
}

void EClient::calculateOptionPrice(TickerId reqId, const Contract& contract, double volatility, double underPrice) {

	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if (m_serverVersion < MIN_SERVER_VER_REQ_CALC_OPTION_PRICE) {
		m_pEWrapper->error( reqId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support calculate option price requests.");
		return;
	}

	if (m_serverVersion < MIN_SERVER_VER_TRADING_CLASS) {
		if( !contract.tradingClass.empty()) {
			m_pEWrapper->error( reqId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support tradingClass parameter in calculateOptionPrice.");
			return;
		}
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 2;

	ENCODE_FIELD( REQ_CALC_OPTION_PRICE);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( reqId);

	// send contract fields
	ENCODE_FIELD( contract.conId);
	ENCODE_FIELD( contract.symbol);
	ENCODE_FIELD( contract.secType);
	ENCODE_FIELD( contract.lastTradeDateOrContractMonth);
	ENCODE_FIELD( contract.strike);
	ENCODE_FIELD( contract.right);
	ENCODE_FIELD( contract.multiplier);
	ENCODE_FIELD( contract.exchange);
	ENCODE_FIELD( contract.primaryExchange);
	ENCODE_FIELD( contract.currency);
	ENCODE_FIELD( contract.localSymbol);
	if( m_serverVersion >= MIN_SERVER_VER_TRADING_CLASS) {
		ENCODE_FIELD( contract.tradingClass);
	}

	ENCODE_FIELD( volatility);
	ENCODE_FIELD( underPrice);

	closeAndSend( msg.str());
}

void EClient::cancelCalculateOptionPrice(TickerId reqId) {

	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if (m_serverVersion < MIN_SERVER_VER_CANCEL_CALC_OPTION_PRICE) {
		m_pEWrapper->error( reqId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support calculate option price cancellation.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( CANCEL_CALC_OPTION_PRICE);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( reqId);

	closeAndSend( msg.str());
}

void EClient::reqContractDetails( int reqId, const Contract& contract)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	// Not needed anymore validation
	// This feature is only available for versions of TWS >=4
	//if( m_serverVersion < 4) {
	//	m_pEWrapper->error( NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg());
	//	return;
	//}
	if (m_serverVersion < MIN_SERVER_VER_SEC_ID_TYPE) {
		if( !contract.secIdType.empty() || !contract.secId.empty()) {
			m_pEWrapper->error( reqId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support secIdType and secId parameters.");
			return;
		}
	}
	if (m_serverVersion < MIN_SERVER_VER_TRADING_CLASS) {
		if( !contract.tradingClass.empty()) {
			m_pEWrapper->error( reqId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support tradingClass parameter in reqContractDetails.");
			return;
		}
	}
	if (m_serverVersion < MIN_SERVER_VER_LINKING) {
		if (!contract.primaryExchange.empty()) {
			m_pEWrapper->error( reqId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support primaryExchange parameter in reqContractDetails.");
			return;
		}
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 8;

	// send req mkt data msg
	ENCODE_FIELD( REQ_CONTRACT_DATA);
	ENCODE_FIELD( VERSION);

	if( m_serverVersion >= MIN_SERVER_VER_CONTRACT_DATA_CHAIN) {
		ENCODE_FIELD( reqId);
	}

	// send contract fields
	ENCODE_FIELD( contract.conId); // srv v37 and above
	ENCODE_FIELD( contract.symbol);
	ENCODE_FIELD( contract.secType);
	ENCODE_FIELD( contract.lastTradeDateOrContractMonth);
	ENCODE_FIELD( contract.strike);
	ENCODE_FIELD( contract.right);
	ENCODE_FIELD( contract.multiplier); // srv v15 and above

	if (m_serverVersion >= MIN_SERVER_VER_PRIMARYEXCH)
	{
		ENCODE_FIELD(contract.exchange);
		ENCODE_FIELD(contract.primaryExchange);
	}
	else if (m_serverVersion >= MIN_SERVER_VER_LINKING)
	{
		if (!contract.primaryExchange.empty() && (contract.exchange == "BEST" || contract.exchange == "SMART"))
		{
			ENCODE_FIELD( contract.exchange + ":" + contract.primaryExchange);
		}
		else
		{
			ENCODE_FIELD(contract.exchange);
		}
	}

	ENCODE_FIELD( contract.currency);
	ENCODE_FIELD( contract.localSymbol);
	if( m_serverVersion >= MIN_SERVER_VER_TRADING_CLASS) {
		ENCODE_FIELD( contract.tradingClass);
	}
	ENCODE_FIELD( contract.includeExpired); // srv v31 and above

	if( m_serverVersion >= MIN_SERVER_VER_SEC_ID_TYPE){
		ENCODE_FIELD( contract.secIdType);
		ENCODE_FIELD( contract.secId);
	}

	closeAndSend( msg.str());
}

void EClient::reqCurrentTime()
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	// Not needed anymore validation
	// This feature is only available for versions of TWS >= 33
	//if( m_serverVersion < 33) {
	//	m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
	//		"  It does not support current time requests.");
	//	return;
	//}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	// send current time req
	ENCODE_FIELD( REQ_CURRENT_TIME);
	ENCODE_FIELD( VERSION);

	closeAndSend( msg.str());
}

void EClient::placeOrder( OrderId id, const Contract& contract, const Order& order)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( id, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	// Not needed anymore validation
	//if( m_serverVersion < MIN_SERVER_VER_SCALE_ORDERS) {
	//	if( order.scaleNumComponents != UNSET_INTEGER ||
	//		order.scaleComponentSize != UNSET_INTEGER ||
	//		order.scalePriceIncrement != UNSET_DOUBLE) {
	//		m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
	//			"  It does not support Scale orders.");
	//		return;
	//	}
	//}
	//
	//if( m_serverVersion < MIN_SERVER_VER_SSHORT_COMBO_LEGS) {
	//	if( contract.comboLegs && !contract.comboLegs->empty()) {
	//		typedef Contract::ComboLegList ComboLegList;
	//		const ComboLegList& comboLegs = *contract.comboLegs;
	//		ComboLegList::const_iterator iter = comboLegs.begin();
	//		const ComboLegList::const_iterator iterEnd = comboLegs.end();
	//		for( ; iter != iterEnd; ++iter) {
	//			const ComboLeg* comboLeg = *iter;
	//			assert( comboLeg);
	//			if( comboLeg->shortSaleSlot != 0 ||
	//				!comboLeg->designatedLocation.IsEmpty()) {
	//				m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
	//					"  It does not support SSHORT flag for combo legs.");
	//				return;
	//			}
	//		}
	//	}
	//}
	//
	//if( m_serverVersion < MIN_SERVER_VER_WHAT_IF_ORDERS) {
	//	if( order.whatIf) {
	//		m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
	//			"  It does not support what-if orders.");
	//		return;
	//	}
	//}

	if( m_serverVersion < MIN_SERVER_VER_UNDER_COMP) {
		if( contract.underComp) {
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support delta-neutral orders.");
			return;
		}
	}

	if( m_serverVersion < MIN_SERVER_VER_SCALE_ORDERS2) {
		if( order.scaleSubsLevelSize != UNSET_INTEGER) {
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support Subsequent Level Size for Scale orders.");
			return;
		}
	}

	if( m_serverVersion < MIN_SERVER_VER_ALGO_ORDERS) {

		if( !order.algoStrategy.empty()) {
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support algo orders.");
			return;
		}
	}

	if( m_serverVersion < MIN_SERVER_VER_NOT_HELD) {
		if (order.notHeld) {
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support notHeld parameter.");
			return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_SEC_ID_TYPE) {
		if( !contract.secIdType.empty() || !contract.secId.empty()) {
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support secIdType and secId parameters.");
			return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_PLACE_ORDER_CONID) {
		if( contract.conId > 0) {
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support conId parameter.");
			return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_SSHORTX) {
		if( order.exemptCode != -1) {
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support exemptCode parameter.");
			return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_SSHORTX) {
		const Contract::ComboLegList* const comboLegs = contract.comboLegs.get();
		const int comboLegsCount = comboLegs ? comboLegs->size() : 0;
		for( int i = 0; i < comboLegsCount; ++i) {
			const ComboLeg* comboLeg = ((*comboLegs)[i]).get();
			assert( comboLeg);
			if( comboLeg->exemptCode != -1 ){
				m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
					"  It does not support exemptCode parameter.");
				return;
			}
		}
	}

	if( m_serverVersion < MIN_SERVER_VER_HEDGE_ORDERS) {
		if( !order.hedgeType.empty()) {
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support hedge orders.");
			return;
		}
	}

	if( m_serverVersion < MIN_SERVER_VER_OPT_OUT_SMART_ROUTING) {
		if (order.optOutSmartRouting) {
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support optOutSmartRouting parameter.");
			return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_DELTA_NEUTRAL_CONID) {
		if (order.deltaNeutralConId > 0 
			|| !order.deltaNeutralSettlingFirm.empty()
			|| !order.deltaNeutralClearingAccount.empty()
			|| !order.deltaNeutralClearingIntent.empty()
			) {
				m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
					"  It does not support deltaNeutral parameters: ConId, SettlingFirm, ClearingAccount, ClearingIntent.");
				return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_DELTA_NEUTRAL_OPEN_CLOSE) {
		if (!order.deltaNeutralOpenClose.empty()
			|| order.deltaNeutralShortSale
			|| order.deltaNeutralShortSaleSlot > 0 
			|| !order.deltaNeutralDesignatedLocation.empty()
			) {
				m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() + 
					"  It does not support deltaNeutral parameters: OpenClose, ShortSale, ShortSaleSlot, DesignatedLocation.");
				return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_SCALE_ORDERS3) {
		if (order.scalePriceIncrement > 0 && order.scalePriceIncrement != UNSET_DOUBLE) {
			if (order.scalePriceAdjustValue != UNSET_DOUBLE 
				|| order.scalePriceAdjustInterval != UNSET_INTEGER 
				|| order.scaleProfitOffset != UNSET_DOUBLE 
				|| order.scaleAutoReset 
				|| order.scaleInitPosition != UNSET_INTEGER 
				|| order.scaleInitFillQty != UNSET_INTEGER 
				|| order.scaleRandomPercent) {
					m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
						"  It does not support Scale order parameters: PriceAdjustValue, PriceAdjustInterval, " +
						"ProfitOffset, AutoReset, InitPosition, InitFillQty and RandomPercent");
					return;
			}
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_ORDER_COMBO_LEGS_PRICE && contract.secType == "BAG") {
		const Order::OrderComboLegList* const orderComboLegs = order.orderComboLegs.get();
		const int orderComboLegsCount = orderComboLegs ? orderComboLegs->size() : 0;
		for( int i = 0; i < orderComboLegsCount; ++i) {
			const OrderComboLeg* orderComboLeg = ((*orderComboLegs)[i]).get();
			assert( orderComboLeg);
			if( orderComboLeg->price != UNSET_DOUBLE) {
				m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
					"  It does not support per-leg prices for order combo legs.");
				return;
			}
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_TRAILING_PERCENT) {
		if (order.trailingPercent != UNSET_DOUBLE) {
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support trailing percent parameter");
			return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_TRADING_CLASS) {
		if( !contract.tradingClass.empty()) {
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support tradingClass parameter in placeOrder.");
			return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_SCALE_TABLE) {
		if( !order.scaleTable.empty() || !order.activeStartTime.empty() || !order.activeStopTime.empty()) {
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support scaleTable, activeStartTime and activeStopTime parameters");
			return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_ALGO_ID) {
		if( !order.algoId.empty()) {
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support algoId parameter");
			return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_ORDER_SOLICITED) {
		if (order.solicited) {
			m_pEWrapper->error(id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support order solicited parameter.");
			return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_MODELS_SUPPORT) {
		if( !order.modelCode.empty()) {
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support model code parameter.");
			return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_EXT_OPERATOR) {
		if( !order.extOperator.empty()) {
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support ext operator parameter");
			return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_SOFT_DOLLAR_TIER) 
	{
		if (!order.softDollarTier.name().empty() || !order.softDollarTier.val().empty())
		{
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				" It does not support soft dollar tier");
			return;
		}
	}

	if (m_serverVersion < MIN_SERVER_VER_CASH_QTY) {
		if (order.cashQty != UNSET_DOUBLE) {
			m_pEWrapper->error( id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support cash quantity parameter");
			return;
		}
	}

    if (m_serverVersion < MIN_SERVER_VER_DECISION_MAKER
        && (!order.mifid2DecisionMaker.empty()
            || !order.mifid2DecisionAlgo.empty())) {
            m_pEWrapper->error(id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
                " It does not support MIFID II decision maker parameters");
            return;
    }

    if (m_serverVersion < MIN_SERVER_VER_MIFID_EXECUTION
        && (!order.mifid2ExecutionTrader.empty()
            || !order.mifid2ExecutionAlgo.empty())) {
            m_pEWrapper->error(id, UPDATE_TWS.code(), UPDATE_TWS.msg() +
                " It does not support MIFID II execution parameters");
            return;
    }


	std::stringstream msg;
	prepareBuffer( msg);

	int VERSION = (m_serverVersion < MIN_SERVER_VER_NOT_HELD) ? 27 : 45;

	// send place order msg
	ENCODE_FIELD( PLACE_ORDER);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( id);

	// send contract fields
	if( m_serverVersion >= MIN_SERVER_VER_PLACE_ORDER_CONID) {
		ENCODE_FIELD( contract.conId);
	}
	ENCODE_FIELD( contract.symbol);
	ENCODE_FIELD( contract.secType);
	ENCODE_FIELD( contract.lastTradeDateOrContractMonth);
	ENCODE_FIELD( contract.strike);
	ENCODE_FIELD( contract.right);
	ENCODE_FIELD( contract.multiplier); // srv v15 and above
	ENCODE_FIELD( contract.exchange);
	ENCODE_FIELD( contract.primaryExchange); // srv v14 and above
	ENCODE_FIELD( contract.currency);
	ENCODE_FIELD( contract.localSymbol); // srv v2 and above
	if( m_serverVersion >= MIN_SERVER_VER_TRADING_CLASS) {
		ENCODE_FIELD( contract.tradingClass);
	}

	if( m_serverVersion >= MIN_SERVER_VER_SEC_ID_TYPE){
		ENCODE_FIELD( contract.secIdType);
		ENCODE_FIELD( contract.secId);
	}

	// send main order fields
	ENCODE_FIELD( order.action);

	if (m_serverVersion >= MIN_SERVER_VER_FRACTIONAL_POSITIONS)
		ENCODE_FIELD(order.totalQuantity)
	else
	ENCODE_FIELD((long)order.totalQuantity)

	ENCODE_FIELD( order.orderType);
	if( m_serverVersion < MIN_SERVER_VER_ORDER_COMBO_LEGS_PRICE) {
		ENCODE_FIELD( order.lmtPrice == UNSET_DOUBLE ? 0 : order.lmtPrice);
	}
	else {
		ENCODE_FIELD_MAX( order.lmtPrice);
	}
	if( m_serverVersion < MIN_SERVER_VER_TRAILING_PERCENT) {
		ENCODE_FIELD( order.auxPrice == UNSET_DOUBLE ? 0 : order.auxPrice);
	}
	else {
		ENCODE_FIELD_MAX( order.auxPrice);
	}

	// send extended order fields
	ENCODE_FIELD( order.tif);
	ENCODE_FIELD( order.ocaGroup);
	ENCODE_FIELD( order.account);
	ENCODE_FIELD( order.openClose);
	ENCODE_FIELD( order.origin);
	ENCODE_FIELD( order.orderRef);
	ENCODE_FIELD( order.transmit);
	ENCODE_FIELD( order.parentId); // srv v4 and above

	ENCODE_FIELD( order.blockOrder); // srv v5 and above
	ENCODE_FIELD( order.sweepToFill); // srv v5 and above
	ENCODE_FIELD( order.displaySize); // srv v5 and above
	ENCODE_FIELD( order.triggerMethod); // srv v5 and above

	//if( m_serverVersion < 38) {
	// will never happen
	//	ENCODE_FIELD(/* order.ignoreRth */ false);
	//}
	//else {
	ENCODE_FIELD( order.outsideRth); // srv v5 and above
	//}

	ENCODE_FIELD( order.hidden); // srv v7 and above

	// Send combo legs for BAG requests (srv v8 and above)
	if( contract.secType == "BAG")
	{
		const Contract::ComboLegList* const comboLegs = contract.comboLegs.get();
		const int comboLegsCount = comboLegs ? comboLegs->size() : 0;
		ENCODE_FIELD( comboLegsCount);
		if( comboLegsCount > 0) {
			for( int i = 0; i < comboLegsCount; ++i) {
				const ComboLeg* comboLeg = ((*comboLegs)[i]).get();
				assert( comboLeg);
				ENCODE_FIELD( comboLeg->conId);
				ENCODE_FIELD( comboLeg->ratio);
				ENCODE_FIELD( comboLeg->action);
				ENCODE_FIELD( comboLeg->exchange);
				ENCODE_FIELD( comboLeg->openClose);

				ENCODE_FIELD( comboLeg->shortSaleSlot); // srv v35 and above
				ENCODE_FIELD( comboLeg->designatedLocation); // srv v35 and above
				if (m_serverVersion >= MIN_SERVER_VER_SSHORTX_OLD) { 
					ENCODE_FIELD( comboLeg->exemptCode);
				}
			}
		}
	}

	// Send order combo legs for BAG requests
	if( m_serverVersion >= MIN_SERVER_VER_ORDER_COMBO_LEGS_PRICE && contract.secType == "BAG")
	{
		const Order::OrderComboLegList* const orderComboLegs = order.orderComboLegs.get();
		const int orderComboLegsCount = orderComboLegs ? orderComboLegs->size() : 0;
		ENCODE_FIELD( orderComboLegsCount);
		if( orderComboLegsCount > 0) {
			for( int i = 0; i < orderComboLegsCount; ++i) {
				const OrderComboLeg* orderComboLeg = ((*orderComboLegs)[i]).get();
				assert( orderComboLeg);
				ENCODE_FIELD_MAX( orderComboLeg->price);
			}
		}
	}	

	if( m_serverVersion >= MIN_SERVER_VER_SMART_COMBO_ROUTING_PARAMS && contract.secType == "BAG") {
		const TagValueList* const smartComboRoutingParams = order.smartComboRoutingParams.get();
		const int smartComboRoutingParamsCount = smartComboRoutingParams ? smartComboRoutingParams->size() : 0;
		ENCODE_FIELD( smartComboRoutingParamsCount);
		if( smartComboRoutingParamsCount > 0) {
			for( int i = 0; i < smartComboRoutingParamsCount; ++i) {
				const TagValue* tagValue = ((*smartComboRoutingParams)[i]).get();
				ENCODE_FIELD( tagValue->tag);
				ENCODE_FIELD( tagValue->value);
			}
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	// Send the shares allocation.
	//
	// This specifies the number of order shares allocated to each Financial
	// Advisor managed account. The format of the allocation string is as
	// follows:
	//			<account_code1>/<number_shares1>,<account_code2>/<number_shares2>,...N
	// E.g.
	//		To allocate 20 shares of a 100 share order to account 'U101' and the
	//      residual 80 to account 'U203' enter the following share allocation string:
	//          U101/20,U203/80
	/////////////////////////////////////////////////////////////////////////////
	{
		// send deprecated sharesAllocation field
		ENCODE_FIELD( ""); // srv v9 and above
	}

	ENCODE_FIELD( order.discretionaryAmt); // srv v10 and above
	ENCODE_FIELD( order.goodAfterTime); // srv v11 and above
	ENCODE_FIELD( order.goodTillDate); // srv v12 and above

	ENCODE_FIELD( order.faGroup); // srv v13 and above
	ENCODE_FIELD( order.faMethod); // srv v13 and above
	ENCODE_FIELD( order.faPercentage); // srv v13 and above
	ENCODE_FIELD( order.faProfile); // srv v13 and above

	if (m_serverVersion >= MIN_SERVER_VER_MODELS_SUPPORT) {
		ENCODE_FIELD( order.modelCode);
	}

	// institutional short saleslot data (srv v18 and above)
	ENCODE_FIELD( order.shortSaleSlot);      // 0 for retail, 1 or 2 for institutions
	ENCODE_FIELD( order.designatedLocation); // populate only when shortSaleSlot = 2.
	if (m_serverVersion >= MIN_SERVER_VER_SSHORTX_OLD) { 
		ENCODE_FIELD( order.exemptCode);
	}

	// not needed anymore
	//bool isVolOrder = (order.orderType.CompareNoCase("VOL") == 0);

	// srv v19 and above fields
	ENCODE_FIELD( order.ocaType);
	//if( m_serverVersion < 38) {
	// will never happen
	//	send( /* order.rthOnly */ false);
	//}
	ENCODE_FIELD( order.rule80A);
	ENCODE_FIELD( order.settlingFirm);
	ENCODE_FIELD( order.allOrNone);
	ENCODE_FIELD_MAX( order.minQty);
	ENCODE_FIELD_MAX( order.percentOffset);
	ENCODE_FIELD( order.eTradeOnly);
	ENCODE_FIELD( order.firmQuoteOnly);
	ENCODE_FIELD_MAX( order.nbboPriceCap);
	ENCODE_FIELD( order.auctionStrategy); // AUCTION_MATCH, AUCTION_IMPROVEMENT, AUCTION_TRANSPARENT
	ENCODE_FIELD_MAX( order.startingPrice);
	ENCODE_FIELD_MAX( order.stockRefPrice);
	ENCODE_FIELD_MAX( order.delta);
	// Volatility orders had specific watermark price attribs in server version 26
	//double lower = (m_serverVersion == 26 && isVolOrder) ? DBL_MAX : order.stockRangeLower;
	//double upper = (m_serverVersion == 26 && isVolOrder) ? DBL_MAX : order.stockRangeUpper;
	ENCODE_FIELD_MAX( order.stockRangeLower);
	ENCODE_FIELD_MAX( order.stockRangeUpper);

	ENCODE_FIELD( order.overridePercentageConstraints); // srv v22 and above

	// Volatility orders (srv v26 and above)
	ENCODE_FIELD_MAX( order.volatility);
	ENCODE_FIELD_MAX( order.volatilityType);
	// will never happen
	//if( m_serverVersion < 28) {
	//	send( order.deltaNeutralOrderType.CompareNoCase("MKT") == 0);
	//}
	//else {
	ENCODE_FIELD( order.deltaNeutralOrderType); // srv v28 and above
	ENCODE_FIELD_MAX( order.deltaNeutralAuxPrice); // srv v28 and above

	if (m_serverVersion >= MIN_SERVER_VER_DELTA_NEUTRAL_CONID && !order.deltaNeutralOrderType.empty()){
		ENCODE_FIELD( order.deltaNeutralConId);
		ENCODE_FIELD( order.deltaNeutralSettlingFirm);
		ENCODE_FIELD( order.deltaNeutralClearingAccount);
		ENCODE_FIELD( order.deltaNeutralClearingIntent);
	}

	if (m_serverVersion >= MIN_SERVER_VER_DELTA_NEUTRAL_OPEN_CLOSE && !order.deltaNeutralOrderType.empty()){
		ENCODE_FIELD( order.deltaNeutralOpenClose);
		ENCODE_FIELD( order.deltaNeutralShortSale);
		ENCODE_FIELD( order.deltaNeutralShortSaleSlot);
		ENCODE_FIELD( order.deltaNeutralDesignatedLocation);
	}

	//}
	ENCODE_FIELD( order.continuousUpdate);
	//if( m_serverVersion == 26) {
	//	// Volatility orders had specific watermark price attribs in server version 26
	//	double lower = (isVolOrder ? order.stockRangeLower : DBL_MAX);
	//	double upper = (isVolOrder ? order.stockRangeUpper : DBL_MAX);
	//	ENCODE_FIELD_MAX( lower);
	//	ENCODE_FIELD_MAX( upper);
	//}
	ENCODE_FIELD_MAX( order.referencePriceType);

	ENCODE_FIELD_MAX( order.trailStopPrice); // srv v30 and above

	if( m_serverVersion >= MIN_SERVER_VER_TRAILING_PERCENT) {
		ENCODE_FIELD_MAX( order.trailingPercent);
	}

	// SCALE orders
	if( m_serverVersion >= MIN_SERVER_VER_SCALE_ORDERS2) {
		ENCODE_FIELD_MAX( order.scaleInitLevelSize);
		ENCODE_FIELD_MAX( order.scaleSubsLevelSize);
	}
	else {
		// srv v35 and above)
		ENCODE_FIELD( ""); // for not supported scaleNumComponents
		ENCODE_FIELD_MAX( order.scaleInitLevelSize); // for scaleComponentSize
	}

	ENCODE_FIELD_MAX( order.scalePriceIncrement);

	if( m_serverVersion >= MIN_SERVER_VER_SCALE_ORDERS3 
		&& order.scalePriceIncrement > 0.0 && order.scalePriceIncrement != UNSET_DOUBLE) {
			ENCODE_FIELD_MAX( order.scalePriceAdjustValue);
			ENCODE_FIELD_MAX( order.scalePriceAdjustInterval);
			ENCODE_FIELD_MAX( order.scaleProfitOffset);
			ENCODE_FIELD( order.scaleAutoReset);
			ENCODE_FIELD_MAX( order.scaleInitPosition);
			ENCODE_FIELD_MAX( order.scaleInitFillQty);
			ENCODE_FIELD( order.scaleRandomPercent);
	}

	if( m_serverVersion >= MIN_SERVER_VER_SCALE_TABLE) {
		ENCODE_FIELD( order.scaleTable);
		ENCODE_FIELD( order.activeStartTime);
		ENCODE_FIELD( order.activeStopTime);
	}

	// HEDGE orders
	if( m_serverVersion >= MIN_SERVER_VER_HEDGE_ORDERS) {
		ENCODE_FIELD( order.hedgeType);
		if ( !order.hedgeType.empty()) {
			ENCODE_FIELD( order.hedgeParam);
		}
	}

	if( m_serverVersion >= MIN_SERVER_VER_OPT_OUT_SMART_ROUTING){
		ENCODE_FIELD( order.optOutSmartRouting);
	}

	if( m_serverVersion >= MIN_SERVER_VER_PTA_ORDERS) {
		ENCODE_FIELD( order.clearingAccount);
		ENCODE_FIELD( order.clearingIntent);
	}

	if( m_serverVersion >= MIN_SERVER_VER_NOT_HELD){
		ENCODE_FIELD( order.notHeld);
	}

	if( m_serverVersion >= MIN_SERVER_VER_UNDER_COMP) {
		if( contract.underComp) {
			const UnderComp& underComp = *contract.underComp;
			ENCODE_FIELD( true);
			ENCODE_FIELD( underComp.conId);
			ENCODE_FIELD( underComp.delta);
			ENCODE_FIELD( underComp.price);
		}
		else {
			ENCODE_FIELD( false);
		}
	}

	if( m_serverVersion >= MIN_SERVER_VER_ALGO_ORDERS) {
		ENCODE_FIELD( order.algoStrategy);

		if( !order.algoStrategy.empty()) {
			const TagValueList* const algoParams = order.algoParams.get();
			const int algoParamsCount = algoParams ? algoParams->size() : 0;
			ENCODE_FIELD( algoParamsCount);
			if( algoParamsCount > 0) {
				for( int i = 0; i < algoParamsCount; ++i) {
					const TagValue* tagValue = ((*algoParams)[i]).get();
					ENCODE_FIELD( tagValue->tag);
					ENCODE_FIELD( tagValue->value);
				}
			}
		}

	}

	if( m_serverVersion >= MIN_SERVER_VER_ALGO_ID) {
		ENCODE_FIELD( order.algoId);
	}

	ENCODE_FIELD( order.whatIf); // srv v36 and above

	// send miscOptions parameter
	if( m_serverVersion >= MIN_SERVER_VER_LINKING) {
		std::string miscOptionsStr("");
		const TagValueList* const orderMiscOptions = order.orderMiscOptions.get();
		const int orderMiscOptionsCount = orderMiscOptions ? orderMiscOptions->size() : 0;
		if( orderMiscOptionsCount > 0) {
			for( int i = 0; i < orderMiscOptionsCount; ++i) {
				const TagValue* tagValue = ((*orderMiscOptions)[i]).get();
				miscOptionsStr += tagValue->tag;
				miscOptionsStr += "=";
				miscOptionsStr += tagValue->value;
				miscOptionsStr += ";";
			}
		}
		ENCODE_FIELD( miscOptionsStr);
	}

	if (m_serverVersion >= MIN_SERVER_VER_ORDER_SOLICITED) {
		ENCODE_FIELD(order.solicited);
	}

	if (m_serverVersion >= MIN_SERVER_VER_RANDOMIZE_SIZE_AND_PRICE) {
		ENCODE_FIELD(order.randomizeSize);
		ENCODE_FIELD(order.randomizePrice);
	}

	if (m_serverVersion >= MIN_SERVER_VER_PEGGED_TO_BENCHMARK) {
		if (order.orderType == "PEG BENCH") {
			ENCODE_FIELD(order.referenceContractId);
			ENCODE_FIELD(order.isPeggedChangeAmountDecrease);
			ENCODE_FIELD(order.peggedChangeAmount);
			ENCODE_FIELD(order.referenceChangeAmount);
			ENCODE_FIELD(order.referenceExchangeId);
		}

		ENCODE_FIELD(order.conditions.size());

		if (order.conditions.size() > 0) {
			for (ibapi::shared_ptr<OrderCondition> item : order.conditions) {
				ENCODE_FIELD(item->type());
				item->writeExternal(msg);
			}

			ENCODE_FIELD(order.conditionsIgnoreRth);
			ENCODE_FIELD(order.conditionsCancelOrder);
		}

		ENCODE_FIELD(order.adjustedOrderType);
		ENCODE_FIELD(order.triggerPrice);
		ENCODE_FIELD(order.lmtPriceOffset);
		ENCODE_FIELD(order.adjustedStopPrice);
		ENCODE_FIELD(order.adjustedStopLimitPrice);
		ENCODE_FIELD(order.adjustedTrailingAmount);
		ENCODE_FIELD(order.adjustableTrailingUnit);
	}

	if( m_serverVersion >= MIN_SERVER_VER_EXT_OPERATOR) {
		ENCODE_FIELD( order.extOperator);
	}

	if (m_serverVersion >= MIN_SERVER_VER_SOFT_DOLLAR_TIER) {
		ENCODE_FIELD(order.softDollarTier.name());
		ENCODE_FIELD(order.softDollarTier.val());
	}

	if (m_serverVersion >= MIN_SERVER_VER_CASH_QTY) {
		ENCODE_FIELD_MAX( order.cashQty);
	}

    if (m_serverVersion >= MIN_SERVER_VER_DECISION_MAKER) {
        ENCODE_FIELD(order.mifid2DecisionMaker);
        ENCODE_FIELD(order.mifid2DecisionAlgo);
    }

    if (m_serverVersion >= MIN_SERVER_VER_MIFID_EXECUTION) {
        ENCODE_FIELD(order.mifid2ExecutionTrader);
        ENCODE_FIELD(order.mifid2ExecutionAlgo);
    }

	closeAndSend( msg.str());
}

void EClient::cancelOrder( OrderId id)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( id, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	const int VERSION = 1;

	// send cancel order msg
	std::stringstream msg;
	prepareBuffer( msg);

	ENCODE_FIELD( CANCEL_ORDER);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( id);

	closeAndSend( msg.str());
}

void EClient::reqAccountUpdates(bool subscribe, const std::string& acctCode)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 2;

	// send req acct msg
	ENCODE_FIELD( REQ_ACCT_DATA);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( subscribe);  // TRUE = subscribe, FALSE = unsubscribe.

	// Send the account code. This will only be used for FA clients
	ENCODE_FIELD( acctCode); // srv v9 and above

	closeAndSend( msg.str());
}

void EClient::reqOpenOrders()
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	// send req open orders msg
	ENCODE_FIELD( REQ_OPEN_ORDERS);
	ENCODE_FIELD( VERSION);

	closeAndSend( msg.str());
}

void EClient::reqAutoOpenOrders(bool bAutoBind)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	// send req open orders msg
	ENCODE_FIELD( REQ_AUTO_OPEN_ORDERS);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( bAutoBind);

	closeAndSend( msg.str());
}

void EClient::reqAllOpenOrders()
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	// send req open orders msg
	ENCODE_FIELD( REQ_ALL_OPEN_ORDERS);
	ENCODE_FIELD( VERSION);

	closeAndSend( msg.str());
}

void EClient::reqExecutions(int reqId, const ExecutionFilter& filter)
{
	//NOTE: Time format must be 'yyyymmdd-hh:mm:ss' E.g. '20030702-14:55'

	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 3;

	// send req open orders msg
	ENCODE_FIELD( REQ_EXECUTIONS);
	ENCODE_FIELD( VERSION);

	if( m_serverVersion >= MIN_SERVER_VER_EXECUTION_DATA_CHAIN) {
		ENCODE_FIELD( reqId);
	}

	// Send the execution rpt filter data (srv v9 and above)
	ENCODE_FIELD( filter.m_clientId);
	ENCODE_FIELD( filter.m_acctCode);
	ENCODE_FIELD( filter.m_time);
	ENCODE_FIELD( filter.m_symbol);
	ENCODE_FIELD( filter.m_secType);
	ENCODE_FIELD( filter.m_exchange);
	ENCODE_FIELD( filter.m_side);

	closeAndSend( msg.str());
}

void EClient::reqIds( int numIds)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( numIds, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	// send req open orders msg
	ENCODE_FIELD( REQ_IDS);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( numIds);

	closeAndSend( msg.str());
}

void EClient::reqNewsBulletins(bool allMsgs)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	// send req news bulletins msg
	ENCODE_FIELD( REQ_NEWS_BULLETINS);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( allMsgs);

	closeAndSend( msg.str());
}

void EClient::cancelNewsBulletins()
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	// send req news bulletins msg
	ENCODE_FIELD( CANCEL_NEWS_BULLETINS);
	ENCODE_FIELD( VERSION);

	closeAndSend( msg.str());
}

void EClient::setServerLogLevel(int logLevel)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	// send the set server logging level message
	ENCODE_FIELD( SET_SERVER_LOGLEVEL);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( logLevel);

	closeAndSend( msg.str());
}

void EClient::reqManagedAccts()
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	// send req FA managed accounts msg
	ENCODE_FIELD( REQ_MANAGED_ACCTS);
	ENCODE_FIELD( VERSION);

	closeAndSend( msg.str());
}


void EClient::requestFA(faDataType pFaDataType)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	// Not needed anymore validation
	//if( m_serverVersion < 13) {
	//	m_pEWrapper->error( NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg());
	//	return;
	//}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( REQ_FA);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( (int)pFaDataType);

	closeAndSend( msg.str());
}

void EClient::replaceFA(faDataType pFaDataType, const std::string& cxml)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	// Not needed anymore validation
	//if( m_serverVersion < 13) {
	//	m_pEWrapper->error( NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg());
	//	return;
	//}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( REPLACE_FA);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( (int)pFaDataType);
	ENCODE_FIELD( cxml);

	closeAndSend( msg.str());
}



void EClient::exerciseOptions( TickerId tickerId, const Contract& contract,
							  int exerciseAction, int exerciseQuantity,
							  const std::string& account, int override)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	// Not needed anymore validation
	//if( m_serverVersion < 21) {
	//	m_pEWrapper->error( NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg());
	//	return;
	//}

	if (m_serverVersion < MIN_SERVER_VER_TRADING_CLASS) {
		if( !contract.tradingClass.empty() || (contract.conId > 0)) {
			m_pEWrapper->error( tickerId, UPDATE_TWS.code(), UPDATE_TWS.msg() +
				"  It does not support conId, multiplier and tradingClass parameters in exerciseOptions.");
			return;
		}
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 2;

	ENCODE_FIELD( EXERCISE_OPTIONS);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( tickerId);

	// send contract fields
	if( m_serverVersion >= MIN_SERVER_VER_TRADING_CLASS) {
		ENCODE_FIELD( contract.conId);
	}
	ENCODE_FIELD( contract.symbol);
	ENCODE_FIELD( contract.secType);
	ENCODE_FIELD( contract.lastTradeDateOrContractMonth);
	ENCODE_FIELD( contract.strike);
	ENCODE_FIELD( contract.right);
	ENCODE_FIELD( contract.multiplier);
	ENCODE_FIELD( contract.exchange);
	ENCODE_FIELD( contract.currency);
	ENCODE_FIELD( contract.localSymbol);
	if( m_serverVersion >= MIN_SERVER_VER_TRADING_CLASS) {
		ENCODE_FIELD( contract.tradingClass);
	}
	ENCODE_FIELD( exerciseAction);
	ENCODE_FIELD( exerciseQuantity);
	ENCODE_FIELD( account);
	ENCODE_FIELD( override);

	closeAndSend( msg.str());
}

void EClient::reqGlobalCancel()
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if (m_serverVersion < MIN_SERVER_VER_REQ_GLOBAL_CANCEL) {
		m_pEWrapper->error( NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support globalCancel requests.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	// send current time req
	ENCODE_FIELD( REQ_GLOBAL_CANCEL);
	ENCODE_FIELD( VERSION);

	closeAndSend( msg.str());
}

void EClient::reqMarketDataType( int marketDataType)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_REQ_MARKET_DATA_TYPE) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support market data type requests.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( REQ_MARKET_DATA_TYPE);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( marketDataType);

	closeAndSend( msg.str());
}

int EClient::bufferedRead()
{
	char buf[8192];
	int nResult = receive( buf, sizeof(buf));

	if( nResult > 0) {
		m_inBuffer.insert( m_inBuffer.end(), &buf[0], &buf[0] + nResult);
	}

	return nResult;
}

void EClient::reqPositions()
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_POSITIONS) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support positions request.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( REQ_POSITIONS);
	ENCODE_FIELD( VERSION);

	closeAndSend( msg.str());
}

void EClient::cancelPositions()
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_POSITIONS) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support positions cancellation.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( CANCEL_POSITIONS);
	ENCODE_FIELD( VERSION);

	closeAndSend( msg.str());
}

void EClient::reqAccountSummary( int reqId, const std::string& groupName, const std::string& tags)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_ACCOUNT_SUMMARY) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support account summary request.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( REQ_ACCOUNT_SUMMARY);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( reqId);
	ENCODE_FIELD( groupName);
	ENCODE_FIELD( tags);

	closeAndSend( msg.str());
}

void EClient::cancelAccountSummary( int reqId)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_ACCOUNT_SUMMARY) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support account summary cancellation.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( CANCEL_ACCOUNT_SUMMARY);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( reqId);

	closeAndSend( msg.str());
}

void EClient::verifyRequest(const std::string& apiName, const std::string& apiVersion)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_LINKING) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support verification request.");
		return;
	}

	if( !m_extraAuth) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  Intent to authenticate needs to be expressed during initial connect request.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( VERIFY_REQUEST);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( apiName);
	ENCODE_FIELD( apiVersion);

	closeAndSend( msg.str());
}

void EClient::verifyMessage(const std::string& apiData)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_LINKING) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support verification message sending.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( VERIFY_MESSAGE);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( apiData);

	closeAndSend( msg.str());
}

void EClient::verifyAndAuthRequest(const std::string& apiName, const std::string& apiVersion, const std::string& opaqueIsvKey)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_LINKING_AUTH) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support verification request.");
		return;
	}

	if( !m_extraAuth) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  Intent to authenticate needs to be expressed during initial connect request.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( VERIFY_AND_AUTH_REQUEST);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( apiName);
	ENCODE_FIELD( apiVersion);
	ENCODE_FIELD( opaqueIsvKey);

	closeAndSend( msg.str());
}

void EClient::verifyAndAuthMessage(const std::string& apiData, const std::string& xyzResponse)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_LINKING_AUTH) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support verification message sending.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( VERIFY_AND_AUTH_MESSAGE);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( apiData);
	ENCODE_FIELD( xyzResponse);

	closeAndSend( msg.str());
}

void EClient::queryDisplayGroups( int reqId)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_LINKING) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support queryDisplayGroups request.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( QUERY_DISPLAY_GROUPS);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( reqId);

	closeAndSend( msg.str());
}

void EClient::subscribeToGroupEvents( int reqId, int groupId)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_LINKING) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support subscribeToGroupEvents request.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( SUBSCRIBE_TO_GROUP_EVENTS);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( reqId);
	ENCODE_FIELD( groupId);

	closeAndSend( msg.str());
}

void EClient::updateDisplayGroup( int reqId, const std::string& contractInfo)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_LINKING) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support updateDisplayGroup request.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( UPDATE_DISPLAY_GROUP);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( reqId);
	ENCODE_FIELD( contractInfo);

	closeAndSend( msg.str());
}

void EClient::startApi()
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion >= 3) {
		if( m_serverVersion < MIN_SERVER_VER_LINKING) {
			std::stringstream msg;
			ENCODE_FIELD( m_clientId);
			bufferedSend( msg.str());
		}
		else
		{
			std::stringstream msg;
			prepareBuffer( msg);

			const int VERSION = 2;

			ENCODE_FIELD( START_API);
			ENCODE_FIELD( VERSION);
			ENCODE_FIELD( m_clientId);

			if (m_serverVersion >= MIN_SERVER_VER_OPTIONAL_CAPABILITIES)
				ENCODE_FIELD(m_optionalCapabilities);

			closeAndSend( msg.str());
		}
	}
}

void EClient::unsubscribeFromGroupEvents( int reqId)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_LINKING) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support unsubscribeFromGroupEvents request.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( UNSUBSCRIBE_FROM_GROUP_EVENTS);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( reqId);

	closeAndSend( msg.str());
}

void EClient::reqPositionsMulti( int reqId, const std::string& account, const std::string& modelCode)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_MODELS_SUPPORT) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support positions multi request.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( REQ_POSITIONS_MULTI);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( reqId);
	ENCODE_FIELD( account);
	ENCODE_FIELD( modelCode);

	closeAndSend( msg.str());
}

void EClient::cancelPositionsMulti( int reqId)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_MODELS_SUPPORT) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support positions multi cancellation.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( CANCEL_POSITIONS_MULTI);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( reqId);

	closeAndSend( msg.str());
}

void EClient::reqAccountUpdatessMulti( int reqId, const std::string& account, const std::string& modelCode, bool ledgerAndNLV)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_MODELS_SUPPORT) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support account updates multi request.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( REQ_ACCOUNT_UPDATES_MULTI);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( reqId);
	ENCODE_FIELD( account);
	ENCODE_FIELD( modelCode);
	ENCODE_FIELD( ledgerAndNLV);

	closeAndSend( msg.str());
}

void EClient::cancelAccountUpdatesMulti( int reqId)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_MODELS_SUPPORT) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support account updates multi cancellation.");
		return;
	}

	std::stringstream msg;
	prepareBuffer( msg);

	const int VERSION = 1;

	ENCODE_FIELD( CANCEL_ACCOUNT_UPDATES_MULTI);
	ENCODE_FIELD( VERSION);
	ENCODE_FIELD( reqId);

	closeAndSend( msg.str());
}

void EClient::reqSecDefOptParams(int reqId, const std::string& underlyingSymbol, const std::string& futFopExchange, const std::string& underlyingSecType, int underlyingConId)
{
	// not connected?
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_SEC_DEF_OPT_PARAMS_REQ) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support security definiton option requests.");
		return;
	}

	std::stringstream msg;
	prepareBuffer(msg);


	ENCODE_FIELD(REQ_SEC_DEF_OPT_PARAMS);
	ENCODE_FIELD(reqId);
	ENCODE_FIELD(underlyingSymbol); 
	ENCODE_FIELD(futFopExchange);
	ENCODE_FIELD(underlyingSecType);
	ENCODE_FIELD(underlyingConId);

	closeAndSend(msg.str());
}

void EClient::reqSoftDollarTiers(int reqId)
{
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	std::stringstream msg;
	prepareBuffer(msg);


	ENCODE_FIELD(REQ_SOFT_DOLLAR_TIERS);
	ENCODE_FIELD(reqId);

	closeAndSend(msg.str());
}

void EClient::reqFamilyCodes()
{
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_REQ_FAMILY_CODES) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support family codes requests.");
		return;
	}

	std::stringstream msg;
	prepareBuffer(msg);

	ENCODE_FIELD(REQ_FAMILY_CODES);

	closeAndSend(msg.str());
}

void EClient::reqMatchingSymbols(int reqId, const std::string& pattern)
{
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_REQ_MATCHING_SYMBOLS) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support matching symbols requests.");
		return;
	}

	std::stringstream msg;
	prepareBuffer(msg);

	ENCODE_FIELD(REQ_MATCHING_SYMBOLS);
	ENCODE_FIELD(reqId);
	ENCODE_FIELD(pattern);

	closeAndSend(msg.str());
}

void EClient::reqMktDepthExchanges()
{
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_REQ_MKT_DEPTH_EXCHANGES) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support market depth exchanges requests.");
		return;
	}


	std::stringstream msg;
	prepareBuffer(msg);

	ENCODE_FIELD(REQ_MKT_DEPTH_EXCHANGES);

	closeAndSend(msg.str());
}

void EClient::reqSmartComponents(int reqId, std::string bboExchange) 
{
	if (!isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if (m_serverVersion < MIN_SERVER_VER_REQ_SMART_COMPONENTS) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support smart components request.");
		return;
	}

	std::stringstream msg;
	prepareBuffer(msg);

	ENCODE_FIELD(REQ_SMART_COMPONENTS);
	ENCODE_FIELD(reqId);
	ENCODE_FIELD(bboExchange);

	closeAndSend(msg.str());
}

void EClient::reqNewsProviders()
{
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_REQ_NEWS_PROVIDERS) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support news providers requests.");
		return;
	}

	std::stringstream msg;
	prepareBuffer(msg);

	ENCODE_FIELD(REQ_NEWS_PROVIDERS);

	closeAndSend(msg.str());
}

void EClient::reqNewsArticle(int requestId, const std::string& providerCode, const std::string& articleId, const TagValueListSPtr& newsArticleOptions)
{
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_REQ_NEWS_ARTICLE) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support news article requests.");
		return;
	}

	std::stringstream msg;
	prepareBuffer(msg);

	ENCODE_FIELD(REQ_NEWS_ARTICLE);
	ENCODE_FIELD(requestId);
	ENCODE_FIELD(providerCode);
	ENCODE_FIELD(articleId);
    

	// send newsArticleOptions parameter
	if( m_serverVersion >= MIN_SERVER_VER_NEWS_QUERY_ORIGINS) {
		ENCODE_TAGVALUELIST(newsArticleOptions);
	}

	closeAndSend(msg.str());
}

void EClient::reqHistoricalNews(int requestId, int conId, const std::string& providerCodes, const std::string& startDateTime, const std::string& endDateTime, int totalResults,
								const TagValueListSPtr& historicalNewsOptions)
{
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_REQ_HISTORICAL_NEWS) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support historical news requests.");
		return;
	}

	std::stringstream msg;
	prepareBuffer(msg);

	ENCODE_FIELD(REQ_HISTORICAL_NEWS);
	ENCODE_FIELD(requestId);
	ENCODE_FIELD(conId);
	ENCODE_FIELD(providerCodes);
	ENCODE_FIELD(startDateTime);
	ENCODE_FIELD(endDateTime);
	ENCODE_FIELD(totalResults);

	// send historicalNewsOptions parameter
	if( m_serverVersion >= MIN_SERVER_VER_NEWS_QUERY_ORIGINS) {
		ENCODE_TAGVALUELIST(historicalNewsOptions);
	}

	closeAndSend(msg.str());
}

void EClient::reqHeadTimestamp(int tickerId, const Contract &contract, const std::string& whatToShow, int useRTH, int formatDate)
{
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_REQ_HEAD_TIMESTAMP) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support head timestamp requests.");
		return;
	}

	std::stringstream msg;
	prepareBuffer(msg);

	ENCODE_FIELD(REQ_HEAD_TIMESTAMP);
	ENCODE_FIELD(tickerId);
	ENCODE_FIELD(contract.conId);
	ENCODE_FIELD(contract.symbol);
	ENCODE_FIELD(contract.secType);
	ENCODE_FIELD(contract.lastTradeDateOrContractMonth);
	ENCODE_FIELD(contract.strike);
	ENCODE_FIELD(contract.right);
	ENCODE_FIELD(contract.multiplier);
	ENCODE_FIELD(contract.exchange);
	ENCODE_FIELD(contract.primaryExchange);
	ENCODE_FIELD(contract.currency);
	ENCODE_FIELD(contract.localSymbol);
	ENCODE_FIELD(contract.tradingClass);
	ENCODE_FIELD(contract.includeExpired);
	ENCODE_FIELD(useRTH);
	ENCODE_FIELD(whatToShow);          
	ENCODE_FIELD(formatDate);

	closeAndSend(msg.str());
}

void EClient::cancelHeadTimestamp(int tickerId) {
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_CANCEL_HEADTIMESTAMP) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support head timestamp requests canceling.");
		return;
	}

	std::stringstream msg;
	prepareBuffer(msg);

	ENCODE_FIELD(CANCEL_HEAD_TIMESTAMP);
	ENCODE_FIELD(tickerId);

	closeAndSend(msg.str());
}

void EClient::reqHistogramData(int reqId, const Contract &contract, bool useRTH, const std::string& timePeriod) {
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_REQ_HISTOGRAM) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support histogram requests.");
		return;
	}

	std::stringstream msg;
	prepareBuffer(msg);

	ENCODE_FIELD(REQ_HISTOGRAM_DATA);
	ENCODE_FIELD(reqId);
	ENCODE_CONTRACT(contract);
	ENCODE_FIELD(useRTH);
	ENCODE_FIELD(timePeriod);          

	closeAndSend(msg.str());
}

void EClient::cancelHistogramData(int reqId) {
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_REQ_HEAD_TIMESTAMP) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support histogram requests.");
		return;
	}

	std::stringstream msg;
	prepareBuffer(msg);

	ENCODE_FIELD(CANCEL_HISTOGRAM_DATA);
	ENCODE_FIELD(reqId);      

	closeAndSend(msg.str());
}

void EClient::reqMarketRule(int marketRuleId) {
	if( !isConnected()) {
		m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
		return;
	}

	if( m_serverVersion < MIN_SERVER_VER_MARKET_RULES) {
		m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
			"  It does not support market rule requests.");
		return;
	}

	std::stringstream msg;
	prepareBuffer(msg);

	ENCODE_FIELD(REQ_MARKET_RULE);
	ENCODE_FIELD(marketRuleId);

	closeAndSend(msg.str());
}

void EClient::reqPnL(int reqId, const std::string& account, const std::string& modelCode) {
    if( !isConnected()) {
        m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
        return;
    }

    if( m_serverVersion < MIN_SERVER_VER_PNL) {
        m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
            "  It does not support PnL requests.");
        return;
    }

    std::stringstream msg;
    prepareBuffer(msg);

    ENCODE_FIELD(REQ_PNL);
    ENCODE_FIELD(reqId);
    ENCODE_FIELD(account);
    ENCODE_FIELD(modelCode);

    closeAndSend(msg.str());
}

void EClient::cancelPnL(int reqId) {
    if( !isConnected()) {
        m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
        return;
    }

    if( m_serverVersion < MIN_SERVER_VER_PNL) {
        m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
            "  It does not support PnL requests.");
        return;
    }

    std::stringstream msg;
    prepareBuffer(msg);

    ENCODE_FIELD(CANCEL_PNL);
    ENCODE_FIELD(reqId);

    closeAndSend(msg.str());
}

void EClient::reqPnLSingle(int reqId, const std::string& account, const std::string& modelCode, int conId) {
    if( !isConnected()) {
        m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
        return;
    }

    if( m_serverVersion < MIN_SERVER_VER_PNL) {
        m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
            "  It does not support PnL requests.");
        return;
    }

    std::stringstream msg;
    prepareBuffer(msg);

    ENCODE_FIELD(REQ_PNL_SINGLE);
    ENCODE_FIELD(reqId);
    ENCODE_FIELD(account);
    ENCODE_FIELD(modelCode);
    ENCODE_FIELD(conId);

    closeAndSend(msg.str());
}

void EClient::cancelPnLSingle(int reqId) {
    if( !isConnected()) {
        m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
        return;
    }

    if( m_serverVersion < MIN_SERVER_VER_PNL) {
        m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
            "  It does not support PnL requests.");
        return;
    }

    std::stringstream msg;
    prepareBuffer(msg);

    ENCODE_FIELD(CANCEL_PNL_SINGLE);
    ENCODE_FIELD(reqId);

    closeAndSend(msg.str());
}

void EClient::reqHistoricalTicks(int reqId, const Contract &contract, const std::string& startDateTime,
            const std::string& endDateTime, int numberOfTicks, const std::string& whatToShow, int useRth, bool ignoreSize, const TagValueListSPtr& miscOptions) {
    if( !isConnected()) {
        m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
        return;
    }

    if( m_serverVersion < MIN_SERVER_VER_HISTORICAL_TICKS) {
        m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
            "  It does not support historical ticks request request.");
        return;
    }

    std::stringstream msg;
    prepareBuffer(msg);

    ENCODE_FIELD(REQ_HISTORICAL_TICKS);
    ENCODE_FIELD(reqId);
    ENCODE_CONTRACT(contract);
    ENCODE_FIELD(startDateTime);
    ENCODE_FIELD(endDateTime);
    ENCODE_FIELD(numberOfTicks);
    ENCODE_FIELD(whatToShow);
    ENCODE_FIELD(useRth);
    ENCODE_FIELD(ignoreSize);
    ENCODE_TAGVALUELIST(miscOptions);

    closeAndSend(msg.str());    
}

void EClient::reqTickByTickData(int reqId, const Contract &contract, const std::string& tickType) {
    if( !isConnected()) {
        m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
        return;
    }

    if( m_serverVersion < MIN_SERVER_VER_TICK_BY_TICK) {
        m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
            "  It does not support tick-by-tick data request.");
        return;
    }

    std::stringstream msg;
    prepareBuffer(msg);

    ENCODE_FIELD(REQ_TICK_BY_TICK_DATA);
    ENCODE_FIELD(reqId);
    ENCODE_FIELD( contract.conId);
    ENCODE_FIELD( contract.symbol);
    ENCODE_FIELD( contract.secType);
    ENCODE_FIELD( contract.lastTradeDateOrContractMonth);
    ENCODE_FIELD( contract.strike);
    ENCODE_FIELD( contract.right);
    ENCODE_FIELD( contract.multiplier);
    ENCODE_FIELD( contract.exchange);
    ENCODE_FIELD( contract.primaryExchange);
    ENCODE_FIELD( contract.currency);
    ENCODE_FIELD( contract.localSymbol);
    ENCODE_FIELD( contract.tradingClass);
    ENCODE_FIELD( tickType);

    closeAndSend(msg.str());    
}

void EClient::cancelTickByTickData(int reqId) {
    if( !isConnected()) {
        m_pEWrapper->error( NO_VALID_ID, NOT_CONNECTED.code(), NOT_CONNECTED.msg());
        return;
    }

    if( m_serverVersion < MIN_SERVER_VER_TICK_BY_TICK) {
        m_pEWrapper->error(NO_VALID_ID, UPDATE_TWS.code(), UPDATE_TWS.msg() +
            "  It does not support tick-by-tick data cancel.");
        return;
    }

    std::stringstream msg;
    prepareBuffer(msg);

    ENCODE_FIELD(CANCEL_TICK_BY_TICK_DATA);
    ENCODE_FIELD(reqId);

    closeAndSend(msg.str());    
}

int EClient::processMsgImpl(const char*& beginPtr, const char* endPtr)
{
	EDecoder decoder(serverVersion(), m_pEWrapper);

	return decoder.parseAndProcessMsg(beginPtr, endPtr);
}

int EClient::processOnePrefixedMsg(const char*& beginPtr, const char* endPtr, messageHandler handler)
{
	if( beginPtr + HEADER_LEN >= endPtr)
		return 0;

	assert( sizeof(unsigned) == HEADER_LEN);

	unsigned netLen = 0;
	memcpy( &netLen, beginPtr, HEADER_LEN);

	const unsigned msgLen = ntohl(netLen);

	// shold never happen, but still....
	if( !msgLen) {
		beginPtr += HEADER_LEN;
		return HEADER_LEN;
	}

	// enforce max msg len limit
	if( msgLen > MAX_MSG_LEN) {
		m_pEWrapper->error( NO_VALID_ID, BAD_LENGTH.code(), BAD_LENGTH.msg());
		eDisconnect();
		m_pEWrapper->connectionClosed();
		return 0;
	}

	const char* msgStart = beginPtr + HEADER_LEN;
	const char* msgEnd = msgStart + msgLen;

	// handle incomplete messages
	if( msgEnd > endPtr) {
		return 0;
	}

	int decoded = (this->*handler)( msgStart, msgEnd);
	if( decoded <= 0) {
		// this would mean something went real wrong
		// and message was incomplete from decoder POV
		m_pEWrapper->error( NO_VALID_ID, BAD_MESSAGE.code(), BAD_MESSAGE.msg());
		eDisconnect();
		m_pEWrapper->connectionClosed();
		return 0;
	}

	int consumed = msgEnd - beginPtr;
	beginPtr = msgEnd;
    return consumed;
}

bool EClient::extraAuth() {
	return m_extraAuth;
}

int EClient::processMsg(const char*& beginPtr, const char* endPtr)
{
	if( !m_useV100Plus) {
		return processMsgImpl( beginPtr, endPtr);
	}
	return processOnePrefixedMsg( beginPtr, endPtr, &EClient::processMsgImpl);
}

EWrapper * EClient::getWrapper() const
{
	return m_pEWrapper;
}

void EClient::setClientId( int clientId)
{
	m_clientId = clientId;
}

void EClient::setExtraAuth( bool extraAuth)
{
	m_extraAuth = extraAuth;
}

void EClient::setHost( const std::string& host)
{
	m_host = host;
}

void EClient::setPort( unsigned port)
{
	m_port = port;
}


///////////////////////////////////////////////////////////
// callbacks from socket
int EClient::sendConnectRequest()
{
	m_connState = CS_CONNECTING;

	int rval;

	// send client version
	std::stringstream msg;
	if( m_useV100Plus) {
		msg.write( API_SIGN, sizeof(API_SIGN));
		prepareBufferImpl( msg);
		if( MIN_CLIENT_VER < MAX_CLIENT_VER) {
			msg << 'v' << MIN_CLIENT_VER << ".." << MAX_CLIENT_VER;
		}
		else {
			msg << 'v' << MIN_CLIENT_VER;
		}
		if( !m_connectOptions.empty()) {
			msg << ' ' << m_connectOptions;
		}

		rval = closeAndSend( msg.str(), sizeof(API_SIGN));
	}
	else {
		ENCODE_FIELD( CLIENT_VERSION);

		rval = bufferedSend( msg.str());
	}

	m_connState = rval > 0 ? CS_CONNECTED : CS_DISCONNECTED;

	return rval;
}

bool EClient::isInBufferEmpty() const
{
	return m_inBuffer.empty();
}






