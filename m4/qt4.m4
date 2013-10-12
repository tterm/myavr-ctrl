#
# Simple checks for qt4 libs and binaries
#
#

AC_DEFUN([QT_CHECKS],
[
    # Header hack
    AC_ARG_WITH([qt-includes],
      [AS_HELP_STRING([--with-qt-includes],
        [location of the QT4 headers, defaults to /usr/include/qt4])],
      [QT4_CFLAGS="-I$withval"],
      [QT4_CFLAGS='-I/usr/include/qt4'])
    AC_SUBST([QT4_CFLAGS])
    CXXFLAGS="$CXXFLAGS $QT4_CFLAGS"
    CXXCPP="$CXXCPP $QT4_CFLAGS"
	
    AC_CHECK_LIB([QtCore], [main], [], 
       	[
           	AC_MSG_NOTICE([Error linking with libQtCore.])
           	AC_MSG_NOTICE([Make sure Qt4 is installed and can be found by the linker.])
           	AC_MSG_ERROR([abort])
       	])
       
   	AC_CHECK_LIB([QtGui], [main], [], 
       	[
           	AC_MSG_NOTICE([Error linking with libQtGui.])
           	AC_MSG_NOTICE([Make sure Qt4 is installed and can be found by the linker.])
           	AC_MSG_ERROR([abort])
       	])

    AC_CHECK_HEADER([QtCore/QObject],,[AC_MSG_ERROR([Couldn't find QT headers. Try using --with-qt-header=/some/dir])])
       
  	# Find qt related tools which are needed to build qt apps 
   	AC_CHECK_PROG(QMAKE, qmake, [qmake],
       	[qmake not found],[$PATH])        
	if test "$QMAKE" = "qmake not found"; then
		AC_MSG_ERROR([qmake not found in $PATH])
   	fi
        
   	AC_CHECK_PROG(QMOC, moc, [moc],
       	[moc_not_found],[$PATH])
   	if test "$QMOC" = "moc not found"; then
		AC_MSG_ERROR([moc not found in $PATH])
   	fi
        
   	AC_CHECK_PROG(QUIC, uic, [uic],
       	[uic not found],[$PATH])
   	if test "$QUIC" = "uic not found"; then
		AC_MSG_ERROR([uic not found in $PATH])
   	fi
])dnl

