#
# Simple checks for qt4 libs and binaries
#
#

AC_DEFUN([QT_CHECKS],
[
	AC_MSG_NOTICE([Searching for qt libs and programs])
	
    AC_ARG_ENABLE([qtgui],
            [AS_HELP_STRING([--enable-qtgui], [enable experimental support for qt])]
            [],
			[qtgui=true])
	AM_CONDITIONAL([QTGUI_ENABLED], [test x$qtgui = xtrue])

	AS_IF([test "x$qtgui" = xtrue],
		[AC_ARG_WITH(qt,
        	[  --with-qt[=DIR]        use qt4 in DIR (default=/usr)],
        		[
            		if test -d "$withval"; then
                		QT_ROOT="$withval"
                		CPPFLAGS="$CPPFLAGS -I$QT_ROOT/include -I$QT_ROOT/include/QtCore -I$QT_ROOT/include/QtGui"
                		LDFLAGS="$LDFLAGS -Wl,--rpath -Wl,$QT_ROOT/lib -L$QT_ROOT/lib"
                		QT_MOC="$QT_ROOT/bin/moc"
                		QT_UIC="QT_ROOT/bin/uic"
            		fi
        		],
        	[
            CPPFLAGS="$CPPFLAGS -I$QT_ROOT/include -I$QT_ROOT/include/QtCore -I$QT_ROOT/include/QtGui"
            LDFLAGS="$LDFLAGS -Wl,--rpath -Wl,$QT_ROOT/lib -L$QT_ROOT/lib"
            QT_MOC="$QT_ROOT/bin/moc"
            QT_UIC="QT_ROOT/bin/uic"
        ])
    	AC_CHECK_LIB([QtCore], [main], [], 
        	[
            	AC_MSG_NOTICE([Error linking with libQtCore.])
            	AC_MSG_NOTICE([Make sure Qt4 is installed and can be found by the linker.])
            	AC_MSG_NOTICE([Try using --with-qt=/path/to/your/qt4/installation])
            	AC_MSG_NOTICE([or let the environment variable QT_ROOT point to your qt4 installation.])
            	AC_MSG_ERROR([abort])
        	])
        
    	AC_CHECK_LIB([QtGui], [main], [], 
        	[
            	AC_MSG_NOTICE([Error linking with libQtGui.])
            	AC_MSG_NOTICE([Make sure Qt4 is installed and can be found by the linker.])
            	AC_MSG_NOTICE([Try using --with-qt=/path/to/your/qt4/installation])
            	AC_MSG_NOTICE([or let the environment variable QT_ROOT point to your qt4 installation.])
            	AC_MSG_ERROR([abort])
        	])
        
    	# Find qt related tools which are needed to build qt apps 
    	AC_CHECK_PROG(QMAKE, qmake, [$QT_ROOT/bin/qmake],
        	[qmake not found],[$QT_ROOT/bin])        
		if test "$QMAKE" = "qmake not found"; then
			AC_MSG_ERROR([qmake not found in $QT_ROOT/bin])
    	fi
        
    	AC_CHECK_PROG(QMOC, moc, [$QT_ROOT/bin/moc],
        	[moc_not_found],[$QT_ROOT/bin])
    	if test "$QMOC" = "moc not found"; then
			AC_MSG_ERROR([moc not found in $QT_ROOT/bin])
    	fi
        
    	AC_CHECK_PROG(QUIC, uic, [$QT_ROOT/bin/uic],
        	[uic not found],[$QT_ROOT/bin])
    	if test "$QUIC" = "uic not found"; then
			AC_MSG_ERROR([uic not found in $QT_ROOT/bin])
    	fi
    	],
    	[AC_MSG_NOTICE([ignoring qt]) # this section is called if with_qtgui=no is set! 
    ]) # end AS_IF 
])dnl

