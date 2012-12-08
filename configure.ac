AC_PREREQ([2.67])
AC_INIT([myavr-ctrl C++], [0.5], [tterm@strace.org],
             [myavr_cc], [https://github.com/tterm/myavr-ctrl])
AC_CONFIG_SRCDIR([src/gui/MainWindow.cpp])
AM_INIT_AUTOMAKE([foreign -Wall tar-pax])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
AC_CONFIG_HEADERS([config.h])

AC_CANONICAL_HOST

# Checks for programs.
AC_PROG_CXX
AC_LANG(C++)
AC_PROG_INSTALL
AC_PROG_RANLIB

# Checks for libraries.
QT_CHECKS
AC_CHECK_LIB([boost_system], [main],, [AC_MSG_ERROR([libboost_system not found.])])
AC_CHECK_LIB([log4cxx], [main],, [AC_MSG_ERROR([liblog4cxx not found.])])

# Checks for headers
AC_CHECK_HEADERS([ctype.h \
                  stdbool.h],,
                  [AC_MSG_ERROR([Some header wasn't found.])], 
                  [AC_INCLUDES_DEFAULT])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_TYPE_SIZE_T

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/backend/Makefile
                 src/gui/Makefile])
AC_OUTPUT
