#ifndef __RECORD_INDEX_CONT_H__
#define __RECORD_INDEX_CONT_H__

#include "RecordStruct.h"
#include <boost/pool/pool.hpp>
#include <boost/pool/object_pool.hpp>
#include <boost/pool/pool_alloc.hpp>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/mem_fun.hpp>
#include <boost/multi_index/indexed_by.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include "../utility/str_for_mi.h"

using boost::multi_index_container;
using namespace boost::multi_index;

// 创建索引全局的别名
class Tag_AppIDIndex {};
class Tag_CommodityIDIndex {};
class Tag_CurrencyIDIndex {};
class Tag_ExchInstrumentIDIndex {};
class Tag_FrontIDIndex {};
class Tag_InnerIDIndex {};
class Tag_InstDirectIndex {};
class Tag_InstrumentIDIndex {};
class Tag_InstrumentTimeIndex {};
class Tag_InvestorIDIndex {};
class Tag_MDUserIDIndex {};
class Tag_OrderRefIndex {};
class Tag_OrderSysIDIndex {};
class Tag_RuleIDIdx {};
class Tag_SessionIDIndex {};
class Tag_SessionIndex {};
class Tag_SubMarketDataIndex {};
class Tag_SysIDIndex {};
class Tag_TerminalIDIndex {};
class Tag_TradeIDIndex {};
class Tag_TradeUserIDIndex {};
class Tag_TraderBaseIndex {};
class Tag_TraderConnectIndex {};
class Tag_TraderIDIndex {};
class Tag_TraderUserIDIndex {};
class Tag_UserIDIdx {};
class Tag_UserIDIndex {};
class Tag_UserIndex {};
class Tag_Base {};



// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_CurrentTime { };
typedef boost::singleton_pool<MyPoolTag_CurrentTime, sizeof(CCurrentTime)> MEM_CurrentTime;
typedef boost::fast_pool_allocator<CCurrentTime*, boost::default_user_allocator_new_delete, 
			boost::details::pool::null_mutex> fast_allo_CurrentTime;

typedef boost::shared_ptr<CCurrentTime> CCurrentTimePtr;
typedef multi_index_container<
	CCurrentTimePtr,
	indexed_by<
	sequenced<>
	, ordered_unique< const_mem_fun<CCurrentTimePtr, CCurrentTime *, &CCurrentTimePtr::get> >
	>
> Idx_Cont_CurrentTime;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_Terminal { };
typedef boost::singleton_pool<MyPoolTag_Terminal, sizeof(CTerminal)> MEM_Terminal;
typedef boost::fast_pool_allocator<CTerminal *, boost::default_user_allocator_new_delete, boost::details::pool::null_mutex> fast_allo_Terminal;

typedef boost::shared_ptr<CTerminal> CTerminalPtr;
typedef multi_index_container<
	CTerminalPtr,
	indexed_by<
	sequenced<>
	, ordered_unique< const_mem_fun<CTerminalPtr, CTerminal *, &CTerminalPtr::get> >
	, ordered_unique<
	tag<Tag_TerminalIDIndex>,
	member<CTerminal, const CTerminalIDType, &CTerminal::TerminalID>,
	my_less<CTerminalIDType>
	>
	, ordered_unique<
	tag<Tag_SessionIDIndex>,
	member<CTerminal, const CSessionIDType, &CTerminal::SessionID>,
	my_less<CSessionIDType>
	>
	>
	//,fast_allo_Terminal>
> Idx_Cont_Terminal;


/// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_Front { };
typedef boost::singleton_pool<MyPoolTag_Front, sizeof(CFront)> MEM_Front;
typedef boost::fast_pool_allocator<CFront *, boost::default_user_allocator_new_delete, boost::details::pool::null_mutex> fast_allo_Front;

typedef boost::shared_ptr<CFront> CFrontPtr;
typedef multi_index_container<
	CFrontPtr,
	indexed_by<
	sequenced<>
	, ordered_unique< const_mem_fun<CFrontPtr, CFront *, &CFrontPtr::get> >
	, ordered_unique<
	tag<Tag_FrontIDIndex>,
	member<CFront, const CFrontIDType, &CFront::FrontID>,
	my_less<CFrontIDType>
	>
	, ordered_unique<
	tag<Tag_SessionIDIndex>,
	member<CFront, const CSessionIDType, &CFront::SessionID>,
	my_less<CSessionIDType>
	>
	>
> Idx_Cont_Front;

/// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_Trader { };
typedef boost::singleton_pool<MyPoolTag_Trader, sizeof(CTrader)> MEM_Trader;
typedef boost::fast_pool_allocator<CTrader *, boost::default_user_allocator_new_delete, boost::details::pool::null_mutex> fast_allo_Trader;

typedef boost::shared_ptr<CTrader> CTraderPtr;
typedef multi_index_container<
	CTraderPtr,
	indexed_by<
	sequenced<>
	, ordered_unique< const_mem_fun<CTraderPtr, CTrader *, &CTraderPtr::get> >
	, ordered_unique<
	tag<Tag_TraderIDIndex>,
	composite_key<
	CTrader,
	member<CTrader, const CTraderIDType, &CTrader::TraderID>,
	member<CTrader, const CTerminalTypeType, &CTrader::TerminalType>,
	member<CTrader, const CAppTypeType, &CTrader::AppType>
	>
	, composite_key_compare<
	my_less<CTraderIDType>,
	my_less<CTerminalTypeType>,
	my_less<CAppTypeType>
	>
	>
	>
> Idx_Cont_Trader;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_TraderParalle { };
typedef boost::singleton_pool<MyPoolTag_TraderParalle, sizeof(CTraderParalle)> MEM_TraderParalle;
typedef boost::fast_pool_allocator<CTraderParalle *, boost::default_user_allocator_new_delete, 
	boost::details::pool::null_mutex> fast_allo_TraderParalle;

typedef boost::shared_ptr<CTraderParalle> CTraderParallePtr;
typedef multi_index_container<
	CTraderParallePtr,
	indexed_by<
	sequenced<>
	, ordered_unique< const_mem_fun<CTraderParallePtr, CTraderParalle *, &CTraderParallePtr::get> >
	, ordered_unique<
	tag<Tag_TraderIDIndex>,
	composite_key<
	CTraderParalle,
	member<CTraderParalle, const CTraderIDType, &CTraderParalle::TraderID>,
	member<CTraderParalle, const CTerminalTypeType, &CTraderParalle::TerminalType>,
	member<CTraderParalle, const CAppTypeType, &CTraderParalle::AppType>
	>
	, composite_key_compare<
	my_less<CTraderIDType>,
	my_less<CTerminalTypeType>,
	my_less<CAppTypeType>
	>
	>
	>
> Idx_Cont_TraderParalle;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_TraderLoginLog { };
typedef boost::singleton_pool<MyPoolTag_TraderLoginLog, sizeof(CTraderLoginLog)> MEM_TraderLoginLog;
typedef boost::fast_pool_allocator<CTraderLoginLog *, boost::default_user_allocator_new_delete, boost::details::pool::null_mutex> fast_allo_TraderLoginLog;

typedef boost::shared_ptr<CTraderLoginLog> CTraderLoginLogPtr;
typedef multi_index_container<
	CTraderLoginLogPtr,
	indexed_by<
	sequenced<>
	, ordered_unique< const_mem_fun<CTraderLoginLogPtr, CTraderLoginLog *, &CTraderLoginLogPtr::get> >
	, ordered_non_unique<
	tag<Tag_TraderIDIndex>,
	member<CTraderLoginLog, const CTraderIDType, &CTraderLoginLog::TraderID>,
	my_less<CTraderIDType>
	>
	>
> Idx_Cont_TraderLoginLog;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_TraderConnect { };
typedef boost::singleton_pool<MyPoolTag_TraderConnect, sizeof(CTraderConnect)> MEM_TraderConnect;
typedef boost::fast_pool_allocator<CTraderConnect *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_TraderConnect;

typedef boost::shared_ptr<CTraderConnect> CTraderConnectPtr;
typedef multi_index_container<
	CTraderConnectPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CTraderConnectPtr,CTraderConnect *,&CTraderConnectPtr::get> > 
		,ordered_unique<
			tag<Tag_TraderConnectIndex>,
			composite_key<
				CTraderConnect,
				member<CTraderConnect,const CTraderIDType, &CTraderConnect::TraderID>,
				member<CTraderConnect,const CTerminalTypeType, &CTraderConnect::TerminalType>,
				member<CTraderConnect,const CAppTypeType, &CTraderConnect::AppType>,
				member<CTraderConnect,const CSessionIDType, &CTraderConnect::SessionID>
			>
			,composite_key_compare<
				my_less<CTraderIDType>,
				my_less<CTerminalTypeType>,
				my_less<CAppTypeType>,
				my_less<CSessionIDType>
			>
		>
		,ordered_non_unique<
			tag<Tag_TraderBaseIndex>,
			composite_key<
				CTraderConnect,
				member<CTraderConnect,const CTraderIDType, &CTraderConnect::TraderID>,
				member<CTraderConnect,const CTerminalTypeType, &CTraderConnect::TerminalType>,
				member<CTraderConnect,const CAppTypeType, &CTraderConnect::AppType>
			>
			,composite_key_compare<
				my_less<CTraderIDType>,
				my_less<CTerminalTypeType>,
				my_less<CAppTypeType>
			>
		>
		,ordered_unique<
			tag<Tag_SessionIndex>,
				member<CTraderConnect, const CSessionIDType, &CTraderConnect::SessionID>,
				my_less<CSessionIDType>
		>
	>
> Idx_Cont_TraderConnect;


//--------------  定义 内存分配器 ------------------------------
struct MyPoolTag_TraderCertInfo { };
typedef boost::singleton_pool<MyPoolTag_TraderCertInfo, sizeof(CTraderCertInfo)> MEM_TraderCertInfo;
typedef boost::fast_pool_allocator<CTraderCertInfo *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_TraderCertInfo;

typedef boost::shared_ptr<CTraderCertInfo> CTraderCertInfoPtr;
typedef multi_index_container<
	CTraderCertInfoPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CTraderCertInfoPtr,CTraderCertInfo *,&CTraderCertInfoPtr::get> > 
		,ordered_unique<
			tag<Tag_TraderIDIndex>,
			composite_key<
				CTraderCertInfo,
				member<CTraderCertInfo,const CTraderIDType, &CTraderCertInfo::TraderID>,
				member<CTraderCertInfo,const CTerminalTypeType, &CTraderCertInfo::TerminalType>,
				member<CTraderCertInfo,const CAppTypeType, &CTraderCertInfo::AppType>
			>
			,composite_key_compare<
				my_less<CTraderIDType>,
				my_less<CTerminalTypeType>,
				my_less<CAppTypeType>
			>
		>
	>
> Idx_Cont_TraderCertInfo;


// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_User { };
typedef boost::singleton_pool<MyPoolTag_User, sizeof(CUser)> MEM_User;
typedef boost::fast_pool_allocator<CUser *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_User;

typedef boost::shared_ptr<CUser> CUserPtr;
typedef multi_index_container<
	CUserPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CUserPtr,CUser *,&CUserPtr::get> > 
		,ordered_unique<
			tag<Tag_UserIDIndex>,
				member<CUser, const CUserIDType, &CUser::UserID>,
				my_less<CUserIDType>
		>
	>
> Idx_Cont_User;

// --------------  定义 内存分配器 ------------------------------
	struct MyPoolTag_UserTrader { };
	typedef boost::singleton_pool<MyPoolTag_UserTrader, sizeof(CUserTrader)> MEM_UserTrader;
	typedef boost::fast_pool_allocator<CUserTrader *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_UserTrader;

	typedef boost::shared_ptr<CUserTrader> CUserTraderPtr;
	typedef multi_index_container<
		CUserTraderPtr,
		indexed_by<
			sequenced<>
			,ordered_unique< const_mem_fun<CUserTraderPtr,CUserTrader *,&CUserTraderPtr::get> > 
			,ordered_unique<
				tag<Tag_TraderUserIDIndex>,
				composite_key<
					CUserTrader,
					member<CUserTrader,const CTraderIDType, &CUserTrader::TraderID>,
					member<CUserTrader,const CUserIDType, &CUserTrader::UserID>
				>
				,composite_key_compare<
					my_less<CTraderIDType>,
					my_less<CUserIDType>
				>
			>
			,ordered_non_unique<
				tag<Tag_UserIDIndex>,
					member<CUserTrader, const CUserIDType, &CUserTrader::UserID>,
					my_less<CUserIDType>
			>
			,ordered_non_unique<
				tag<Tag_TraderIDIndex>,
					member<CUserTrader, const CTraderIDType, &CUserTrader::TraderID>,
					my_less<CTraderIDType>
			>
		>
	> Idx_Cont_UserTrader;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_UserFunctionRight { };
typedef boost::singleton_pool<MyPoolTag_UserFunctionRight, sizeof(CUserFunctionRight)> MEM_UserFunctionRight;
typedef boost::fast_pool_allocator<CUserFunctionRight *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_UserFunctionRight;

typedef boost::shared_ptr<CUserFunctionRight> CUserFunctionRightPtr;
typedef multi_index_container<
	CUserFunctionRightPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CUserFunctionRightPtr,CUserFunctionRight *,&CUserFunctionRightPtr::get> > 
		,ordered_unique<
			tag<Tag_UserIDIndex>,
				member<CUserFunctionRight, const CUserIDType, &CUserFunctionRight::UserID>,
				my_less<CUserIDType>
		>
	>
> Idx_Cont_UserFunctionRight;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_SysInfo { };
typedef boost::singleton_pool<MyPoolTag_SysInfo, sizeof(CSysInfo)> MEM_SysInfo;
typedef boost::fast_pool_allocator<CSysInfo *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_SysInfo;

typedef boost::shared_ptr<CSysInfo> CSysInfoPtr;
typedef multi_index_container<
	CSysInfoPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CSysInfoPtr,CSysInfo *,&CSysInfoPtr::get> > 
		,ordered_unique<
			tag<Tag_AppIDIndex>,
				member<CSysInfo, const CAppIDType, &CSysInfo::AppID>,
				my_less<CAppIDType>
		>
	>
> Idx_Cont_SysInfo;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_UserSession { };
typedef boost::singleton_pool<MyPoolTag_UserSession, sizeof(CUserSession)> MEM_UserSession;
typedef boost::fast_pool_allocator<CUserSession *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_UserSession;

typedef boost::shared_ptr<CUserSession> CUserSessionPtr;
typedef multi_index_container<
	CUserSessionPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CUserSessionPtr,CUserSession *,&CUserSessionPtr::get> > 
		,ordered_unique<
			tag<Tag_FrontIDIndex>,
			composite_key<
				CUserSession,
				member<CUserSession,const CFrontIDType, &CUserSession::FrontID>,
				member<CUserSession,const CSessionIDType, &CUserSession::SessionID>
			>
			,composite_key_compare<
				my_less<CFrontIDType>,
				my_less<CSessionIDType>
			>
		>
		,ordered_non_unique<
			tag<Tag_UserIDIndex>,
				member<CUserSession, const CUserIDType, &CUserSession::UserID>,
				my_less<CUserIDType>
		>
	>
> Idx_Cont_UserSession;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_MDSession { };
typedef boost::singleton_pool<MyPoolTag_MDSession, sizeof(CMDSession)> MEM_MDSession;
typedef boost::fast_pool_allocator<CMDSession *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_MDSession;

typedef boost::shared_ptr<CMDSession> CMDSessionPtr;
typedef multi_index_container<
	CMDSessionPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CMDSessionPtr,CMDSession *,&CMDSessionPtr::get> > 
		,ordered_unique<
			tag<Tag_SessionIDIndex>,
			composite_key<
				CMDSession,
				member<CMDSession,const CSessionIDType, &CMDSession::SessionID>,
				member<CMDSession,const CFrontIDType, &CMDSession::FrontID>
			>
			,composite_key_compare<
				my_less<CSessionIDType>,
				my_less<CFrontIDType>
			>
		>
		,ordered_unique<
			tag<Tag_UserIndex>,
				member<CMDSession, const CUserIDType, &CMDSession::UserID>,
				my_less<CUserIDType>
		>
	>
> Idx_Cont_MDSession;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_MaxLocalID { };
typedef boost::singleton_pool<MyPoolTag_MaxLocalID, sizeof(CMaxLocalID)> MEM_MaxLocalID;
typedef boost::fast_pool_allocator<CMaxLocalID *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_MaxLocalID;

typedef boost::shared_ptr<CMaxLocalID> CMaxLocalIDPtr;
typedef multi_index_container<
	CMaxLocalIDPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CMaxLocalIDPtr,CMaxLocalID *,&CMaxLocalIDPtr::get> > 
		,ordered_unique<
			tag<Tag_UserIndex>,
				member<CMaxLocalID, const CUserIDType, &CMaxLocalID::UserID>,
				my_less<CUserIDType>
		>
	>
> Idx_Cont_MaxLocalID;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_UserSubMarketData { };
typedef boost::singleton_pool<MyPoolTag_UserSubMarketData, sizeof(CUserSubMarketData)> MEM_UserSubMarketData;
typedef boost::fast_pool_allocator<CUserSubMarketData *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_UserSubMarketData;

typedef boost::shared_ptr<CUserSubMarketData> CUserSubMarketDataPtr;
typedef multi_index_container<
	CUserSubMarketDataPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CUserSubMarketDataPtr,CUserSubMarketData *,&CUserSubMarketDataPtr::get> > 
		,ordered_unique<
			tag<Tag_UserIndex>,
				member<CUserSubMarketData, const CUserIDType, &CUserSubMarketData::UserID>,
				my_less<CUserIDType>
		>
		,ordered_unique<
			tag<Tag_SubMarketDataIndex>,
			composite_key<
				CUserSubMarketData,
				member<CUserSubMarketData,const CUserIDType, &CUserSubMarketData::UserID>,
				member<CUserSubMarketData,const CInstrumentIDType, &CUserSubMarketData::InstrumentID>
			>
			,composite_key_compare<
				my_less<CUserIDType>,
				my_less<CInstrumentIDType>
			>
		>
	>
> Idx_Cont_UserSubMarketData;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_DepthMarketData { };
typedef boost::singleton_pool<MyPoolTag_DepthMarketData, sizeof(CDepthMarketData)> MEM_DepthMarketData;
typedef boost::fast_pool_allocator<CDepthMarketData *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_DepthMarketData;

typedef boost::shared_ptr<CDepthMarketData> CDepthMarketDataPtr;
typedef multi_index_container<
	CDepthMarketDataPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CDepthMarketDataPtr,CDepthMarketData *,&CDepthMarketDataPtr::get> > 
		,ordered_unique<
			tag<Tag_InstrumentIDIndex>,
				member<CDepthMarketData, const CInstrumentIDType, &CDepthMarketData::InstrumentID>,
				my_less<CInstrumentIDType>
		>
	>
> Idx_Cont_DepthMarketData;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_Commodity { };
typedef boost::singleton_pool<MyPoolTag_Commodity, sizeof(CCommodity)> MEM_Commodity;
typedef boost::fast_pool_allocator<CCommodity *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_Commodity;

typedef boost::shared_ptr<CCommodity> CCommodityPtr;
typedef multi_index_container<
	CCommodityPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CCommodityPtr,CCommodity *,&CCommodityPtr::get> > 
		,ordered_unique<
			tag<Tag_CommodityIDIndex>,
				member<CCommodity, const CCommodityIDType, &CCommodity::CommodityID>,
				my_less<CCommodityIDType>
		>
	>
> Idx_Cont_Commodity;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_Instrument { };
typedef boost::singleton_pool<MyPoolTag_Instrument, sizeof(CInstrument)> MEM_Instrument;
typedef boost::fast_pool_allocator<CInstrument *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_Instrument;

typedef boost::shared_ptr<CInstrument> CInstrumentPtr;
typedef multi_index_container<
	CInstrumentPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CInstrumentPtr,CInstrument *,&CInstrumentPtr::get> > 
		,ordered_unique<
			tag<Tag_InstrumentIDIndex>,
				member<CInstrument, const CInstrumentIDType, &CInstrument::InstrumentID>,
				my_less<CInstrumentIDType>
		>
		,ordered_non_unique<
			tag<Tag_CommodityIDIndex>,
				member<CInstrument, const CCommodityIDType, &CInstrument::CommodityID>,
				my_less<CCommodityIDType>
		>
		,ordered_unique<
			tag<Tag_ExchInstrumentIDIndex>,
			composite_key<
				CInstrument,
				member<CInstrument,const CInstrumentIDType, &CInstrument::InstrumentID>,
				member<CInstrument,const CExchangeIDType, &CInstrument::ExchangeID>
			>
			,composite_key_compare<
				my_less<CInstrumentIDType>,
				my_less<CExchangeIDType>
			>
		>
	>
> Idx_Cont_Instrument;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_OrderAction { };
typedef boost::singleton_pool<MyPoolTag_OrderAction, sizeof(COrderAction)> MEM_OrderAction;
typedef boost::fast_pool_allocator<COrderAction *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_OrderAction;

typedef boost::shared_ptr<COrderAction> COrderActionPtr;
typedef multi_index_container<
	COrderActionPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<COrderActionPtr,COrderAction *,&COrderActionPtr::get> > 
		,ordered_unique<
			tag<Tag_InnerIDIndex>,
				member<COrderAction, const COrderInnerIDType, &COrderAction::OrderInnerID>,
				my_less<COrderInnerIDType>
		>
		,ordered_non_unique<
			tag<Tag_SysIDIndex>,
				member<COrderAction, const COrderInnerIDType, &COrderAction::OrderInnerID>,
				my_less<COrderInnerIDType>
		>
	>
> Idx_Cont_OrderAction;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_ExchOrderAction { };
typedef boost::singleton_pool<MyPoolTag_ExchOrderAction, sizeof(CExchOrderAction)> MEM_ExchOrderAction;
typedef boost::fast_pool_allocator<CExchOrderAction *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_ExchOrderAction;

typedef boost::shared_ptr<CExchOrderAction> CExchOrderActionPtr;
typedef multi_index_container<
	CExchOrderActionPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CExchOrderActionPtr,CExchOrderAction *,&CExchOrderActionPtr::get> > 
		,ordered_unique<
			tag<Tag_InnerIDIndex>,
				member<CExchOrderAction, const COrderInnerIDType, &CExchOrderAction::OrderInnerID>,
				my_less<COrderInnerIDType>
		>
		,ordered_unique<
			tag<Tag_SysIDIndex>,
				member<CExchOrderAction, const COrderSysIDType, &CExchOrderAction::OrderSysID>,
				my_less<COrderSysIDType>
		>
	>
> Idx_Cont_ExchOrderAction;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_Order { };
typedef boost::singleton_pool<MyPoolTag_Order, sizeof(COrder)> MEM_Order;
typedef boost::fast_pool_allocator<COrder *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_Order;

typedef boost::shared_ptr<COrder> COrderPtr;
typedef multi_index_container<
	COrderPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<COrderPtr,COrder *,&COrderPtr::get> > 
		,ordered_unique<
			tag<Tag_InnerIDIndex>,
				member<COrder, const COrderInnerIDType, &COrder::OrderInnerID>,
				my_less<COrderInnerIDType>
		>
		,ordered_non_unique<
			tag<Tag_OrderSysIDIndex>,
			composite_key<
				COrder,
				member<COrder,const COrderSysIDType, &COrder::OrderSysID>,
				member<COrder,const CExchangeIDType, &COrder::ExchangeID>
			>
			,composite_key_compare<
				my_less<COrderSysIDType>,
				my_less<CExchangeIDType>
			>
		>
		,ordered_non_unique<
			tag<Tag_InstrumentIDIndex>,
				member<COrder, const CInstrumentIDType, &COrder::InstrumentID>,
				my_less<CInstrumentIDType>
		>
		,ordered_non_unique<
			tag<Tag_OrderRefIndex>,
				member<COrder, const COrderRefType, &COrder::OrderRef>,
				my_less<COrderRefType>
		>
	>
> Idx_Cont_Order;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_Trade { };
typedef boost::singleton_pool<MyPoolTag_Trade, sizeof(CTrade)> MEM_Trade;
typedef boost::fast_pool_allocator<CTrade *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_Trade;

typedef boost::shared_ptr<CTrade> CTradePtr;
typedef multi_index_container<
	CTradePtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CTradePtr,CTrade *,&CTradePtr::get> > 
		,ordered_unique<
			tag<Tag_TradeIDIndex>,
			composite_key<
				CTrade,
				member<CTrade,const CTradeIDType, &CTrade::TradeID>,
				member<CTrade,const CInstrumentIDType, &CTrade::InstrumentID>
			>
			,composite_key_compare<
				my_less<CTradeIDType>,
				my_less<CInstrumentIDType>
			>
		>
		,ordered_unique<
			tag<Tag_InstrumentIDIndex>,
			composite_key<
				CTrade,
				member<CTrade,const CInstrumentIDType, &CTrade::InstrumentID>,
				member<CTrade,const CTradeIDType, &CTrade::TradeID>
			>
			,composite_key_compare<
				my_less<CInstrumentIDType>,
				my_less<CTradeIDType>
			>
		>
	>
> Idx_Cont_Trade;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_EsfInstPartInfo { };
typedef boost::singleton_pool<MyPoolTag_EsfInstPartInfo, sizeof(CEsfInstPartInfo)> MEM_EsfInstPartInfo;
typedef boost::fast_pool_allocator<CEsfInstPartInfo *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_EsfInstPartInfo;

typedef boost::shared_ptr<CEsfInstPartInfo> CEsfInstPartInfoPtr;
typedef multi_index_container<
	CEsfInstPartInfoPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CEsfInstPartInfoPtr,CEsfInstPartInfo *,&CEsfInstPartInfoPtr::get> > 
		,ordered_unique<
			tag<Tag_InstrumentIDIndex>,
				member<CEsfInstPartInfo, const CInstrumentIDType, &CEsfInstPartInfo::InstrumentID>,
				my_less<CInstrumentIDType>
		>
	>
> Idx_Cont_EsfInstPartInfo;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_Currency { };
typedef boost::singleton_pool<MyPoolTag_Currency, sizeof(CCurrency)> MEM_Currency;
typedef boost::fast_pool_allocator<CCurrency *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_Currency;

typedef boost::shared_ptr<CCurrency> CCurrencyPtr;
typedef multi_index_container<
	CCurrencyPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CCurrencyPtr,CCurrency *,&CCurrencyPtr::get> > 
		,ordered_unique<
			tag<Tag_CurrencyIDIndex>,
				member<CCurrency, const CCurrencyIDType, &CCurrency::CurrencyID>,
				my_less<CCurrencyIDType>
		>
	>
> Idx_Cont_Currency;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_ExchUserLogin { };
typedef boost::singleton_pool<MyPoolTag_ExchUserLogin, sizeof(CExchUserLogin)> MEM_ExchUserLogin;
typedef boost::fast_pool_allocator<CExchUserLogin *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_ExchUserLogin;

typedef boost::shared_ptr<CExchUserLogin> CExchUserLoginPtr;
typedef multi_index_container<
	CExchUserLoginPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CExchUserLoginPtr,CExchUserLogin *,&CExchUserLoginPtr::get> > 
		,ordered_non_unique<
			tag<Tag_TradeUserIDIndex>,
				member<CExchUserLogin, const CUserIDType, &CExchUserLogin::UserID>,
				my_less<CUserIDType>
		>
	>
> Idx_Cont_ExchUserLogin;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_ExchUserLogout { };
typedef boost::singleton_pool<MyPoolTag_ExchUserLogout, sizeof(CExchUserLogout)> MEM_ExchUserLogout;
typedef boost::fast_pool_allocator<CExchUserLogout *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_ExchUserLogout;

typedef boost::shared_ptr<CExchUserLogout> CExchUserLogoutPtr;
typedef multi_index_container<
	CExchUserLogoutPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CExchUserLogoutPtr,CExchUserLogout *,&CExchUserLogoutPtr::get> > 
		,ordered_non_unique<
			tag<Tag_TradeUserIDIndex>,
				member<CExchUserLogout, const CUserIDType, &CExchUserLogout::UserID>,
				my_less<CUserIDType>
		>
	>
> Idx_Cont_ExchUserLogout;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_ExchMDUserLogin { };
typedef boost::singleton_pool<MyPoolTag_ExchMDUserLogin, sizeof(CExchMDUserLogin)> MEM_ExchMDUserLogin;
typedef boost::fast_pool_allocator<CExchMDUserLogin *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_ExchMDUserLogin;

typedef boost::shared_ptr<CExchMDUserLogin> CExchMDUserLoginPtr;
typedef multi_index_container<
	CExchMDUserLoginPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CExchMDUserLoginPtr,CExchMDUserLogin *,&CExchMDUserLoginPtr::get> > 
		,ordered_non_unique<
			tag<Tag_MDUserIDIndex>,
				member<CExchMDUserLogin, const CUserIDType, &CExchMDUserLogin::UserID>,
				my_less<CUserIDType>
		>
	>
> Idx_Cont_ExchMDUserLogin;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_ExchMDUserLogout { };
typedef boost::singleton_pool<MyPoolTag_ExchMDUserLogout, sizeof(CExchMDUserLogout)> MEM_ExchMDUserLogout;
typedef boost::fast_pool_allocator<CExchMDUserLogout *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_ExchMDUserLogout;

typedef boost::shared_ptr<CExchMDUserLogout> CExchMDUserLogoutPtr;
typedef multi_index_container<
	CExchMDUserLogoutPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CExchMDUserLogoutPtr,CExchMDUserLogout *,&CExchMDUserLogoutPtr::get> > 
		,ordered_non_unique<
			tag<Tag_MDUserIDIndex>,
				member<CExchMDUserLogout, const CUserIDType, &CExchMDUserLogout::UserID>,
				my_less<CUserIDType>
		>
	>
> Idx_Cont_ExchMDUserLogout;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_ExchOrder { };
typedef boost::singleton_pool<MyPoolTag_ExchOrder, sizeof(CExchOrder)> MEM_ExchOrder;
typedef boost::fast_pool_allocator<CExchOrder *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_ExchOrder;

typedef boost::shared_ptr<CExchOrder> CExchOrderPtr;
typedef multi_index_container<
	CExchOrderPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CExchOrderPtr,CExchOrder *,&CExchOrderPtr::get> > 
		,ordered_unique<
			tag<Tag_InnerIDIndex>,
				member<CExchOrder, const COrderInnerIDType, &CExchOrder::OrderInnerID>,
				my_less<COrderInnerIDType>
		>
		,ordered_non_unique<
			tag<Tag_OrderSysIDIndex>,
			composite_key<
				CExchOrder,
				member<CExchOrder,const COrderSysIDType, &CExchOrder::OrderSysID>,
				member<CExchOrder,const CInstrumentIDType, &CExchOrder::InstrumentID>
			>
			,composite_key_compare<
				my_less<COrderSysIDType>,
				my_less<CInstrumentIDType>
			>
		>
	>
> Idx_Cont_ExchOrder;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_ExchTrade { };
typedef boost::singleton_pool<MyPoolTag_ExchTrade, sizeof(CExchTrade)> MEM_ExchTrade;
typedef boost::fast_pool_allocator<CExchTrade *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_ExchTrade;

typedef boost::shared_ptr<CExchTrade> CExchTradePtr;
typedef multi_index_container<
	CExchTradePtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CExchTradePtr,CExchTrade *,&CExchTradePtr::get> > 
		,ordered_unique<
			tag<Tag_TradeIDIndex>,
			composite_key<
				CExchTrade,
				member<CExchTrade,const CTradeIDType, &CExchTrade::TradeID>,
				member<CExchTrade,const CInstrumentIDType, &CExchTrade::InstrumentID>
			>
			,composite_key_compare<
				my_less<CTradeIDType>,
				my_less<CInstrumentIDType>
			>
		>
		,ordered_unique<
			tag<Tag_InstrumentIDIndex>,
			composite_key<
				CExchTrade,
				member<CExchTrade,const CInstrumentIDType, &CExchTrade::InstrumentID>,
				member<CExchTrade,const CTradeIDType, &CExchTrade::TradeID>
			>
			,composite_key_compare<
				my_less<CInstrumentIDType>,
				my_less<CTradeIDType>
			>
		>
	>
> Idx_Cont_ExchTrade;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_ExchInvestorPosition { };
typedef boost::singleton_pool<MyPoolTag_ExchInvestorPosition, sizeof(CExchInvestorPosition)> MEM_ExchInvestorPosition;
typedef boost::fast_pool_allocator<CExchInvestorPosition *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_ExchInvestorPosition;

typedef boost::shared_ptr<CExchInvestorPosition> CExchInvestorPositionPtr;
typedef multi_index_container<
	CExchInvestorPositionPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CExchInvestorPositionPtr,CExchInvestorPosition *,&CExchInvestorPositionPtr::get> > 
		,ordered_non_unique<
			tag<Tag_InvestorIDIndex>,
				member<CExchInvestorPosition, const CInvestorIDType, &CExchInvestorPosition::InvestorID>,
				my_less<CInvestorIDType>
		>
	>
> Idx_Cont_ExchInvestorPosition;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_ExchInvestorAccount { };
typedef boost::singleton_pool<MyPoolTag_ExchInvestorAccount, sizeof(CExchInvestorAccount)> MEM_ExchInvestorAccount;
typedef boost::fast_pool_allocator<CExchInvestorAccount *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_ExchInvestorAccount;

typedef boost::shared_ptr<CExchInvestorAccount> CExchInvestorAccountPtr;
typedef multi_index_container<
	CExchInvestorAccountPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CExchInvestorAccountPtr,CExchInvestorAccount *,&CExchInvestorAccountPtr::get> > 
		,ordered_non_unique<
			tag<Tag_InvestorIDIndex>,
				member<CExchInvestorAccount, const CInvestorIDType, &CExchInvestorAccount::InvestorID>,
				my_less<CInvestorIDType>
		>
	>
> Idx_Cont_ExchInvestorAccount;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_ExchDepthMarketData { };
typedef boost::singleton_pool<MyPoolTag_ExchDepthMarketData, sizeof(CExchDepthMarketData)> MEM_ExchDepthMarketData;
typedef boost::fast_pool_allocator<CExchDepthMarketData *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_ExchDepthMarketData;

typedef boost::shared_ptr<CExchDepthMarketData> CExchDepthMarketDataPtr;
typedef multi_index_container<
	CExchDepthMarketDataPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CExchDepthMarketDataPtr,CExchDepthMarketData *,&CExchDepthMarketDataPtr::get> > 
		,ordered_unique<
			tag<Tag_InstrumentIDIndex>,
				member<CExchDepthMarketData, const CInstrumentIDType, &CExchDepthMarketData::InstrumentID>,
				my_less<CInstrumentIDType>
		>
	>
> Idx_Cont_ExchDepthMarketData;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_ExchDepthMarketHistoryData { };
typedef boost::singleton_pool<MyPoolTag_ExchDepthMarketHistoryData, sizeof(CExchDepthMarketHistoryData)> MEM_ExchDepthMarketHistoryData;
typedef boost::fast_pool_allocator<CExchDepthMarketHistoryData *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_ExchDepthMarketHistoryData;

typedef boost::shared_ptr<CExchDepthMarketHistoryData> CExchDepthMarketHistoryDataPtr;
typedef multi_index_container<
	CExchDepthMarketHistoryDataPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CExchDepthMarketHistoryDataPtr,CExchDepthMarketHistoryData *,&CExchDepthMarketHistoryDataPtr::get> > 
		,ordered_unique<
			tag<Tag_InstrumentTimeIndex>,
			composite_key<
				CExchDepthMarketHistoryData,
				member<CExchDepthMarketHistoryData,const CInstrumentIDType, &CExchDepthMarketHistoryData::InstrumentID>,
				member<CExchDepthMarketHistoryData,const CTimeType, &CExchDepthMarketHistoryData::UpdateTime>
			>
			,composite_key_compare<
				my_less<CInstrumentIDType>,
				my_less<CTimeType>
			>
		>
	>
> Idx_Cont_ExchDepthMarketHistoryData;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_ExchInstrument { };
typedef boost::singleton_pool<MyPoolTag_ExchInstrument, sizeof(CExchInstrument)> MEM_ExchInstrument;
typedef boost::fast_pool_allocator<CExchInstrument *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_ExchInstrument;

typedef boost::shared_ptr<CExchInstrument> CExchInstrumentPtr;
typedef multi_index_container<
	CExchInstrumentPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CExchInstrumentPtr,CExchInstrument *,&CExchInstrumentPtr::get> > 
		,ordered_unique<
			tag<Tag_InstrumentIDIndex>,
				member<CExchInstrument, const CInstrumentIDType, &CExchInstrument::InstrumentID>,
				my_less<CInstrumentIDType>
		>
		,ordered_non_unique<
			tag<Tag_CommodityIDIndex>,
				member<CExchInstrument, const CCommodityIDType, &CExchInstrument::CommodityID>,
				my_less<CCommodityIDType>
		>
		,ordered_unique<
			tag<Tag_ExchInstrumentIDIndex>,
			composite_key<
				CExchInstrument,
				member<CExchInstrument,const CInstrumentIDType, &CExchInstrument::InstrumentID>,
				member<CExchInstrument,const CExchangeIDType, &CExchInstrument::ExchangeID>
			>
			,composite_key_compare<
				my_less<CInstrumentIDType>,
				my_less<CExchangeIDType>
			>
		>
	>
> Idx_Cont_ExchInstrument;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_ExchInstrumentStatus { };
typedef boost::singleton_pool<MyPoolTag_ExchInstrumentStatus, sizeof(CExchInstrumentStatus)> MEM_ExchInstrumentStatus;
typedef boost::fast_pool_allocator<CExchInstrumentStatus *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_ExchInstrumentStatus;

typedef boost::shared_ptr<CExchInstrumentStatus> CExchInstrumentStatusPtr;
typedef multi_index_container<
	CExchInstrumentStatusPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CExchInstrumentStatusPtr,CExchInstrumentStatus *,&CExchInstrumentStatusPtr::get> > 
		,ordered_unique<
			tag<Tag_InstrumentIDIndex>,
				member<CExchInstrumentStatus, const CInstrumentIDType, &CExchInstrumentStatus::InstrumentID>,
				my_less<CInstrumentIDType>
		>
		,ordered_unique<
			tag<Tag_ExchInstrumentIDIndex>,
			composite_key<
				CExchInstrumentStatus,
				member<CExchInstrumentStatus,const CInstrumentIDType, &CExchInstrumentStatus::InstrumentID>,
				member<CExchInstrumentStatus,const CExchangeIDType, &CExchInstrumentStatus::ExchangeID>
			>
			,composite_key_compare<
				my_less<CInstrumentIDType>,
				my_less<CExchangeIDType>
			>
		>
	>
> Idx_Cont_ExchInstrumentStatus;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_PhyAccount { };
typedef boost::singleton_pool<MyPoolTag_PhyAccount, sizeof(CPhyAccount)> MEM_PhyAccount;
typedef boost::fast_pool_allocator<CPhyAccount *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_PhyAccount;

typedef boost::shared_ptr<CPhyAccount> CPhyAccountPtr;
typedef multi_index_container<
	CPhyAccountPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CPhyAccountPtr,CPhyAccount *,&CPhyAccountPtr::get> > 
		,ordered_unique<
			tag<Tag_UserIDIdx>,
			composite_key<
				CPhyAccount,
				member<CPhyAccount,const CBrokerIDType, &CPhyAccount::BrokerID>,
				member<CPhyAccount,const CUserIDType, &CPhyAccount::UserID>
			>
			,composite_key_compare<
				my_less<CBrokerIDType>,
				my_less<CUserIDType>
			>
		>
	>
> Idx_Cont_PhyAccount;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_InvestorPosition { };
typedef boost::singleton_pool<MyPoolTag_InvestorPosition, sizeof(CInvestorPosition)> MEM_InvestorPosition;
typedef boost::fast_pool_allocator<CInvestorPosition *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_InvestorPosition;

typedef boost::shared_ptr<CInvestorPosition> CInvestorPositionPtr;
typedef multi_index_container<
	CInvestorPositionPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CInvestorPositionPtr,CInvestorPosition *,&CInvestorPositionPtr::get> > 
		,ordered_non_unique<
			tag<Tag_InstDirectIndex>,
			composite_key<
				CInvestorPosition,
				member<CInvestorPosition,const CInstrumentIDType, &CInvestorPosition::InstrumentID>,
				member<CInvestorPosition,const CDirectionType, &CInvestorPosition::Direction>,
				member<CInvestorPosition,const CHedgeFlagType, &CInvestorPosition::HedgeFlag>
			>
			,composite_key_compare<
				my_less<CInstrumentIDType>,
				my_less<CDirectionType>,
				my_less<CHedgeFlagType>
			>
		>
	>
> Idx_Cont_InvestorPosition;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_RuleInfo { };
typedef boost::singleton_pool<MyPoolTag_RuleInfo, sizeof(CRuleInfo)> MEM_RuleInfo;
typedef boost::fast_pool_allocator<CRuleInfo *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_RuleInfo;

typedef boost::shared_ptr<CRuleInfo> CRuleInfoPtr;
typedef multi_index_container<
	CRuleInfoPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CRuleInfoPtr,CRuleInfo *,&CRuleInfoPtr::get> > 
		,ordered_unique<
			tag<Tag_RuleIDIdx>,
				member<CRuleInfo, const CRuleIDType, &CRuleInfo::RuleID>,
				my_less<CRuleIDType>
		>
	>
> Idx_Cont_RuleInfo;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_ExchInvestorFee { };
typedef boost::singleton_pool<MyPoolTag_ExchInvestorFee, sizeof(CExchInvestorFee)> MEM_ExchInvestorFee;
typedef boost::fast_pool_allocator<CExchInvestorFee *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_ExchInvestorFee;

typedef boost::shared_ptr<CExchInvestorFee> CExchInvestorFeePtr;
typedef multi_index_container<
	CExchInvestorFeePtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CExchInvestorFeePtr,CExchInvestorFee *,&CExchInvestorFeePtr::get> > 
		,ordered_unique<
			tag<Tag_ExchInstrumentIDIndex>,
			composite_key<
				CExchInvestorFee,
				member<CExchInvestorFee,const CInstrumentIDType, &CExchInvestorFee::InstrumentID>,
				member<CExchInvestorFee,const CExchangeIDType, &CExchInvestorFee::ExchangeID>
			>
			,composite_key_compare<
				my_less<CInstrumentIDType>,
				my_less<CExchangeIDType>
			>
		>
	>
> Idx_Cont_ExchInvestorFee;

// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_ExchInvestorMargin { };
typedef boost::singleton_pool<MyPoolTag_ExchInvestorMargin, sizeof(CExchInvestorMargin)> MEM_ExchInvestorMargin;
typedef boost::fast_pool_allocator<CExchInvestorMargin *,boost::default_user_allocator_new_delete,boost::details::pool::null_mutex> fast_allo_ExchInvestorMargin;

typedef boost::shared_ptr<CExchInvestorMargin> CExchInvestorMarginPtr;
typedef multi_index_container<
	CExchInvestorMarginPtr,
	indexed_by<
		sequenced<>
		,ordered_unique< const_mem_fun<CExchInvestorMarginPtr,CExchInvestorMargin *,&CExchInvestorMarginPtr::get> > 
		,ordered_unique<
			tag<Tag_ExchInstrumentIDIndex>,
			composite_key<
				CExchInvestorMargin,
				member<CExchInvestorMargin,const CInstrumentIDType, &CExchInvestorMargin::InstrumentID>,
				member<CExchInvestorMargin,const CExchangeIDType, &CExchInvestorMargin::ExchangeID>
			>
			,composite_key_compare<
				my_less<CInstrumentIDType>,
				my_less<CExchangeIDType>
			>
		>
	>
> Idx_Cont_ExchInvestorMargin;

#endif
