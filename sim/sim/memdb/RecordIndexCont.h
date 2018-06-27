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





#endif
