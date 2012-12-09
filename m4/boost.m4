#
# Simple checks for qt4 libs and binaries
#
#

AC_DEFUN([BOOST_CHECKS],
[
	AC_CHECK_LIB([boost_system], [main], [],
		[
			AC_MSG_NOTICE([Error linking with libboost_system.])
			AC_MSG_NOTICE([Make sure boost is installed and can be found by the linker.])
			AC_MSG_ERROR([abort])
		])

])dnl

