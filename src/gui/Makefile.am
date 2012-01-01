AM_CPPFLAGS = -Wall -ansi -Wextra \
			  -I /usr/include/qt4/ \
              -I /opt/libserial-0.5.2/include \
              -I$(top_srcdir)/src


AM_LDFLAGS = -lQtCore -lQtGui -L/opt/libserial-0.5.2/lib/ -lserial

bin_PROGRAMS = myavr-ctrl
myavr_ctrl_SOURCES = myavr-ctrl.cpp \ 
				     moc_MainWindow.cpp MainWindow.cpp \
					 moc_ConfigDialog.cpp ConfigDialog.cpp \
                     moc_MainWindowPresenter.cpp MainWindowPresenter.cpp \
                     moc_DialogPresenter.cpp DialogPresenter.cpp

myavr_ctrl_LDADD = ../backend/libbackend.a
                     
CLEANFILES = $(filter moc_%.cpp,$(myavr_ctrl_SOURCES))

moc_%.cpp: %.h
	moc $< -I/usr/include/qt4 -I. -o $@

