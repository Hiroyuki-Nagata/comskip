#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.67])
AC_INIT([comskip], [0.8.1], [http://www.kaashoek.com/comskip/])
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([])
AC_CONFIG_SRCDIR([mpeg2dec.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O

# Checks for HostOS
case "$host" in
        *-*-mingw*|*-*-cygwin*)
                AC_DEFINE(PLATFORM_WIN32, 1, [Platform is Win32])
                ;;
        *-*-linux*)
                AC_DEFINE(PLATFORM_LINUX, 1, [Platform is Linux])
                ;;
        *-*-darwin*)
                AC_DEFINE(PLATFORM_APPLE, 1, [Platform is Apple])
                ;;
        *-*-*bsd*)
                AC_DEFINE(PLATFORM_BSD, 1, [Platform is BSD])
                ;;
        *)
                AC_MSG_WARN([*** Please add $host to configure.ac checks!])
                ;;
esac

# Checks for HostCPU
AS_CASE([$host_cpu],
  [i?86],   [ARCH=i386],
  [x86_64|amd64], [ARCH=x86_64],
  [AC_MSG_ERROR("No assembler code for CPU $host_cpu")]
)
AC_DEFINE([ARCH], [ARCH], [CPU is $host_cpu])

# Checks for filesize
AC_CHECK_SIZEOF(short)
AC_CHECK_SIZEOF(int)
AC_CHECK_SIZEOF(long)
AC_CHECK_SIZEOF(long long)
AC_CHECK_SIZEOF(unsigned char *)
AC_SYS_LARGEFILE

m4_define([file_offset_bits], [$ac_cv_sys_file_offset_bits])

if test "x$ac_cv_sys_file_offset_bits" != "xno"; then
    AC_MSG_RESULT([FILE_OFFSET_BITS=$ac_cv_sys_file_offset_bits])
    FILE_OFFSET_BITS=file_offset_bits()
    AC_SUBST(FILE_OFFSET_BITS)
fi

# Define variables
AC_DEFINE([DONATOR], [1], [Description of DONATOR])
AC_DEFINE([DONATORS], [1], [Description of DONATORS])

#
# Checks for libraries.
#

# Search PATH
CFLAGS="$CFLAGS -I/usr/local/include -I./usr/local/include"
LDFLAGS="$LDFLAGS -L/usr/local/lib -L./usr/local/lib"

# Checks for libm
AC_CHECK_LIB(m,exp,LIBS="-lm $LIBS" has_m=1,has_m=0)
if test $has_m = 0; then
  AC_MSG_ERROR("ERROR: cannot find libm.")
fi

# Checks for pthread
AC_CHECK_LIB(pthread,pthread_create,LIBS="-lpthread $LIBS" has_pthread=1,has_pthread=0)
if test $has_pthread = 0; then
  AC_MSG_ERROR("ERROR: cannot find pthread.")
fi

## Checks for argtable2
#AC_CHECK_LIB(argtable2,arg_print_option,LIBS="-largtable2 $LIBS" has_argtable2=1,has_argtable2=0)
#if test $has_argtable2 = 0; then
#  AC_MSG_ERROR("ERROR: cannot find argtable2.")
#fi

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h inttypes.h locale.h memory.h stdlib.h string.h sys/timeb.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_INT64_T
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_FSEEKO
AC_FUNC_REALLOC
AC_FUNC_STRTOD
AC_CHECK_FUNCS([gettimeofday memset sqrt strchr strerror strrchr strstr strtol malloc])

# Setting for generate Makefile location
AC_CONFIG_FILES([Makefile])

AC_OUTPUT
