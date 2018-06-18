
#include <iostream>
#include <memory>
#include "engine/kernelEngine.h"

int main()
{
	std::unique_ptr<CKernelEngine> kernelEngine(new CKernelEngine());
	if (!kernelEngine->loadConfig())	//���������ļ�
		return -1;

	return 0;
}