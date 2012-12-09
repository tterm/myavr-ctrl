#
# Simple checks for qt4 libs and binaries
#
#

AC_DEFUN([QT_CHECKS],
[
	AC_MSG_NOTICE([Searching for qt libs and programs])
	
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

        AC_CHECK_HEADER([QtCore/QObject],, [AC_MSG_ERROR([abort])])
        
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

