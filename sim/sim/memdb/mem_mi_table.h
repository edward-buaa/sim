#ifndef __MEM_MI_TABLE_H__
#define __MEM_MI_TABLE_H__

#include "table_base.h"

template<class Rec, class CONT>
class CMemMITable : public CTableBase<Rec>
{
public:
	explicit CMemMITable() {}
	virtual ~CMemMITable() {}
};


#endif