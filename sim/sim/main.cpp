
#include <iostream>
#include <memory>
#include "engine/kernelEngine.h"

int main()
{
	std::unique_ptr<CKernelEngine> kernelEngine(new CKernelEngine());
	if (!kernelEngine->loadConfig())	//¼ÓÔØÅäÖÃÎÄ¼ş
		return -1;

	return 0;
}