#ifndef __TYPE_DEC_H__
#define __TYPE_DEC_H__

#include <limits>
#include <cfloat>
#include <climits>

#define CHAR_NULL_VAL SCHAR_MAX
#define WORD_NULL_VAL SHRT_MAX
#define INT_NULL_VAL INT_MAX
#define FLOAT_NULL_VAL FLT_MAX
#define DOUBLE_NaN DBL_MAX
#define DOUBLE_NULL_VAL DOUBLE_NaN
#define LONG_NULL_VAL LLONG_MAX
#define LLONG_NULL_VAL LLONG_MAX


typedef unsigned char	BYTE;
typedef unsigned short	WORD;
typedef char	INT1;
typedef short	INT2;
typedef int	INT4;
typedef float	REAL4;
typedef double	REAL8;

typedef unsigned int UINT4;
#ifndef DWORD 
typedef unsigned long DWORD;
#endif

typedef long long LONGLONG;
typedef unsigned long long ULONGLONG;
typedef LONGLONG QWORD;

///定义一个很小的浮点数，这个数应当不影响计算结果，又大于各类浮点计算误差
#define SMALL_DOUBLE 0.000000001
#define MaxFloatExceed DOUBLE_NULL_VAL

#if  defined(WINDOWS) || defined(Win32 )
#define atoll _atoi64 
#endif

#endif
