AM_CPPFLAGS = -Wall -ansi -Wextra \
			  -I /usr/include/qt4/ \
              -I /opt/libserial-0.5.2/include


AM_LDFLAGS = -lQtCore -lQtGui -L/opt/libserial-0.5.2/lib/ -lserial

bin_PROGRAMS = myavr-ctrl
myavr_ctrl_SOURCES = myavr-ctrl.cpp moc_MainWindow.cpp MainWindow.cpp \
                     BaudUtils.cpp \
                     CharSizeUtils.cpp \
                     FlowControlUtils.cpp \
                     ParityUtils.cpp
                     
#nodist_myavr_ctrl_SOURCES = moc_MainWindow.cpp

CLEANFILES = $(filter moc_%.cpp,$(myavr_ctrl_SOURCES))

moc_%.cpp: %.h
	moc $< -I/usr/include/qt4 -I. -o $@

