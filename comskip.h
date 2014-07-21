#ifndef COMSKIP
#define COMSKIP
#define COMSKIPVERSION "0.81"
#define SUBVERSION "056-TYA Edition"
#endif

#define _UNICODE

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /** autoconf generated config.h */

#define bool			int
#define true			1
#define false			0

// define Sleep
#ifndef _WIN32
#define Sleep(x)      sleep(x)
#define _getcwd(x, y) getcwd(x, y)
#endif

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#ifdef __GNUC__
/* gcc */
typedef long long __int64;
#else
/* msvc or clang */
typedef signed __int64 int64_t;
typedef unsigned __int64 uint64_t;
#endif

#ifndef _WIN32
#if defined(_WIN64)
typedef __int64 LONG_PTR; 
#else
typedef long LONG_PTR;
#endif
#endif
