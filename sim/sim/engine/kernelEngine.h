#ifndef __KERNEL_ENGINE_H__
#define __KERNEL_ENGINE_H__

#include "../network/ftdEngine.h"

class CKernelEngine final : public CFTDEngine
{
public:
	explicit CKernelEngine(ioContextPool& pool);

private:
	void init();	//初始化工作
};


#endif
