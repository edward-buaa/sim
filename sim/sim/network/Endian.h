#ifndef __ENDIAN_H__
#define __ENDIAN_H__

#include <boost/type_traits.hpp>
#include <algorithm>

/*
（1）cpu处理小端字节序性能更好一些，intel amd的cpu使用的是小端排序，网络传输一般使用的是大端排序
（2）在我们的运行环境中，基本上是intel amd的cpu,而且在进行数据发送的时候，而且在发送数据的时候，
	基本上以char*的方式，不会单独出现send(int a)这样的方式，保存char*的小端排序可以节约部分处理时间
*/

namespace endian {

	// 大端字节序
	static inline bool IsBigEndian()
	{
		unsigned int a = 0x12345678;
		char* p = (char*)&a;
		return *p == 0x12;
	}

	// 小端字节序
	static inline bool IsLittleEndian()
	{
		return !IsBigEndian();
	}

	//对一个字节长度为N的整数型数值，进行高地位交换
	template<class T, int N = sizeof(T)>
	struct reserve_integer
	{
		inline T operator()(T value)
		{
			T v = value;
			char *p = (char *)&v;
			std::reverse(p, p + N);
			return v;
		}
		BOOST_STATIC_ASSERT(1 == 1);
	};

	template<class T>
	struct reserve_integer<T, 2>
	{
		inline T operator()(T value)
		{
			return	((value & 0x00ff) << 8) |
				((value & 0xff00) >> 8);
		}
	};

	template <class T>
	struct reserve_integer<T, 4>
	{
		inline T operator ()(T value)
		{
			return	((value & 0x000000ff) << 24) |
				((value & 0x0000ff00) << 8) |
				((value & 0x00ff0000) >> 8) |
				((value & 0xff000000) >> 24);
		}
	};

	template <class T>
	struct reserve_integer<T, 8>
	{
		inline T operator ()(T value)
		{
			return
				((value & 0x000000ff) << 56) |
				((value & 0x0000ff00) << 40) |
				((value & 0x00ff0000) << 24) |
				((value & 0xff000000) << 8) |
				// 高位字节必须加上类型修饰，否则0xff000000<<8 被解释为了整数，出现溢出；
				((value&((T)0x000000ff << 56)) >> 56) |
				((value&((T)0x0000ff00 << 40)) >> 40) |
				((value&((T)0x00ff0000 << 24)) >> 24) |
				((value&((T)0xff000000 << 8)) >> 8);
		}
	};

	template<class T, bool b>
	inline T ChangeEndian_impl(T val, const boost::integral_constant<bool, b>&)
	{
		return reserve_integer<T, sizeof(T)>().operator()(val);
	}

	template<class T>
	inline T * ChangeEndian_impl(T * pVal, const boost::true_type&)
	{
		*pVal = reserve_integer<T, sizeof(T)>().operator()(*pVal);
		return pVal;
	}

	template<class T>
	inline T ChangeEndian(T val)
	{
#ifdef _BIG_ENDIAN_
		return detail_::ChangeEndian_impl(val, boost::is_pointer<T>());
#else
		return val;
#endif
	}

}	//end of namespace endian


#endif
