#we build a dummy static lib here to add code separation
noinst_LIBRARIES = libbackend.a

#AM_LDFLAGS = -lboost_system

AM_CPPFLAGS = -Wall -ansi -Wextra \
              -I /opt/apache-log4cxx-0.10.0/include


libbackend_a_SOURCES = BaudUtils.cpp \
                       CharSizeUtils.cpp \
                       ConfigModel.cpp \
                       ConfigNotFoundException.cpp \
                       DeviceNotFoundException.cpp\
                       FlowControlUtils.cpp \
                       ModeUtils.cpp \
                       ParityUtils.cpp \
                       PortConfig.cpp \
                       Command.cpp
                       
libbackend_a_LIBDADD = /opt/apache-log4cxx-0.10.0/lib/liblog4cxx.a
