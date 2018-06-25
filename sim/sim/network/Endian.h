#ifndef __ENDIAN_H__
#define __ENDIAN_H__

#include <boost/type_traits.hpp>
#include <algorithm>

/*
��1��cpu����С���ֽ������ܸ���һЩ��intel amd��cpuʹ�õ���С���������紫��һ��ʹ�õ��Ǵ������
��2�������ǵ����л����У���������intel amd��cpu,�����ڽ������ݷ��͵�ʱ�򣬶����ڷ������ݵ�ʱ��
	��������char*�ķ�ʽ�����ᵥ������send(int a)�����ķ�ʽ������char*��С��������Խ�Լ���ִ���ʱ��
*/

namespace endian {

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

	//��һ���ֽڳ���ΪN����������ֵ�����иߵ�λ����
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
				// ��λ�ֽڱ�������������Σ�����0xff000000<<8 ������Ϊ�����������������
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
