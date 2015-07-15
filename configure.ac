# Process this file with autoconf to produce a configure script.
AC_INIT(ise-engine-default, 1.0.0, li2012.zhang@samsung.com)
AC_CONFIG_SRCDIR([src/isf_default_imengine.cpp])

# Save this value here, since automake will set cflags and cxxflags later
cflags_set=${CFLAGS+set}
cppflags_set=${CPPFLAGS+set}

ISF_DEFAULT_MAJOR_VERSION=1
ISF_DEFAULT_MINOR_VERSION=0
ISF_DEFAULT_MICRO_VERSION=0

ISF_DEFAULT_VERSION=$ISF_DEFAULT_MAJOR_VERSION.$ISF_DEFAULT_MINOR_VERSION.$ISF_DEFAULT_MICRO_VERSION

AC_SUBST(ISF_DEFAULT_MAJOR_VERSION)
AC_SUBST(ISF_DEFAULT_MINOR_VERSION)
AC_SUBST(ISF_DEFAULT_MICRO_VERSION)
AC_SUBST(ISF_DEFAULT_VERSION)

# Init automake stuff
AM_INIT_AUTOMAKE
AM_CONFIG_HEADER([config.h])

# Init platform
PLATFORM_INIT

# Init libtool
AC_DISABLE_STATIC
AC_LIBTOOL_DLOPEN
AC_DISABLE_STATIC
AC_PROG_LIBTOOL
AC_LIB_LTDL
AC_SUBST(LIBTOOL_DEPS)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_LANG(C++)

AC_C_CONST
AC_TYPE_SIZE_T

case $host_cpu in  
  *arm* ) TARGET=ARM;;
  * ) TARGET=X86;;
esac
AM_CONDITIONAL(ARM, test x$TARGET = xARM)

ISF_VERSION=1.0.0

PKG_CHECK_MODULES(ISF,[isf >= $ISF_VERSION])
AC_SUBST(ISF_VERSION)

# Checks for header files.
AC_HEADER_STDC

# Checks for library functions.
AC_SUBST(ac_aux_dir)

# libtool option to control which symbols are exported
# right now, symbols starting with _ are not exported
LIBTOOL_EXPORT_OPTIONS='-export-symbols-regex "^[[^_]].*"'
AC_SUBST(LIBTOOL_EXPORT_OPTIONS)

# Extra args.
AC_ARG_ENABLE(debug,
	      [  --enable-debug          Turn on debugging],
	      enable_debug=yes,
	      enable_debug=no)
if test "$enable_debug" = "yes"; then
    AC_DEFINE(ENABLE_DEBUG, 1 ,[Define this to enable the debug facility in libscim])
    CFLAGS="$CFLAGS -g"
    CXXFLAGS="$CXXFLAGS -g"
fi

ISF_ICONDIR=`$PKG_CONFIG --variable=icondir scim`
ISF_PKGDIR=`$PKG_CONFIG --variable=pkgdir scim`
ISF_MODULEDIR=`$PKG_CONFIG --variable=moduledir scim`
ISF_DATADIR=`$PKG_CONFIG --variable=scimdatadir scim`
ISF_LIBDIR=`$PKG_CONFIG --variable=libdir scim`

if test "x$ISF_ICONDIR" = "x"; then
  ISF_ICONDIR=${datadir}/scim/icons
fi

if test "x$ISF_PKGDIR" = "x"; then
  ISF_PKGDIR=${datadir}/packages
fi

if test "x$ISF_MODULEDIR" = "x"; then
  ISF_MODULEDIR=${libdir}/scim-1.0
fi

if test "x$ISF_DATADIR" = "x"; then
  ISF_DATADIR=${datadir}/scim
fi

if test "x$ISF_LIBDIR" = "x"; then
  ISF_LIBDIR=${libdir}
fi

AC_SUBST(ISF_ICONDIR)
AC_SUBST(ISF_PKGDIR)
AC_SUBST(ISF_MODULEDIR)
AC_SUBST(ISF_DATADIR)
AC_SUBST(ISF_LIBDIR)

ISF_DEFAULT_DATADIR=${ISF_DATADIR}/ise-engine-default
AC_SUBST(ISF_DEFAULT_DATADIR)

AC_CONFIG_FILES([Makefile
		 src/Makefile
		 data/Makefile])

AC_OUTPUT
