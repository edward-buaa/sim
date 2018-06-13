#ifndef __FTD_ENGINE_H__
#define __FTD_ENGINE_H__

#include "threadBasePool.h"

class CFTDEngine : public CThreadBasePool
{
public:
	explicit CFTDEngine(ioContextPool& pool);
	CFTDEngine(CFTDEngine&) = delete;
	CFTDEngine(CFTDEngine&&) = delete;
	CFTDEngine& operator=(CFTDEngine&) = delete;
	CFTDEngine& operator=(CFTDEngine&&) = delete;
	~CFTDEngine();
};


#endif
