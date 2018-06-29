
#include <memory>
#include "engine/kernelEngine.h"

int main()
{
	std::unique_ptr<CKernelEngine> kernelEngine(new CKernelEngine());
	if (!kernelEngine->initEngine())
	{
		int a = 0;
	}

	system("pause");
	return 0;
}