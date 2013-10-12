AM_CPPFLAGS = -I$(top_srcdir)/src


AM_LDFLAGS = -lapr-1 -laprutil-1

bin_PROGRAMS = myavr-ctrl

myavr_ctrl_SOURCES = myavr-ctrl.cpp \
				     MainWindow.cpp \
					 ConfigDialog.cpp \
                     MainWindowPresenter.cpp \
                     DialogPresenter.cpp

nodist_myavr_ctrl_SOURCES = moc_MainWindow.cpp \
                            moc_ConfigDialog.cpp \
							moc_MainWindowPresenter.cpp \
							moc_DialogPresenter.cpp


include_HEADERS = ConfigDialog.h \
                  DialogPresenter.h \
                  MainWindow.h \
                  MainWindowPresenter.h

myavr_ctrl_LDADD = ../backend/libbackend.a 
                     
CLEANFILES = moc_MainWindow.cpp \
             moc_ConfigDialog.cpp \
             moc_MainWindowPresenter.cpp \
             moc_DialogPresenter.cpp

moc_%.cpp: %.h
	moc $< -I/usr/include/qt4 -I. -o $@

