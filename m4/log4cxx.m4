#
# Simple checks for qt4 libs and binaries
#
#

AC_DEFUN([LOG4CXX_CHECKS],
[
	AC_MSG_NOTICE([Searching for log4cxx libs])
	AC_CHECK_LIB([log4cxx], [main], [],
		[
			AC_MSG_NOTICE([Error linking with liblog4cxx.])
			AC_MSG_NOTICE([Make sure log4cxx is installed and can be found by the linker.])
			AC_MSG_ERROR([abort])
		])

])dnl

