#ifndef __ENDIAN_H__
#define __ENDIAN_H__

#include <boost/type_traits.hpp>
//#include <memory>
//#include <memory.h>
#include <algorithm>

namespace endian{

	// ����ֽ���
	static inline bool IsBigEndian()
	{
		unsigned int a = 0x12345678;
		char* p = (char*)&a;
		return *p == 0x12;
	}

	// С���ֽ���
	static inline bool IsLittleEndian()
	{
		return !IsBigEndian();
	}

}	//end of namespace endian


#endif
