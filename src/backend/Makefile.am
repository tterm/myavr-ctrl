#we build a dummy static lib here to add code separation
noinst_LIBRARIES = libbackend.a

AM_CPPFLAGS = -I$(top_srcdir)/src/backend -I$(top_builddir)/src/backend

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

include_HEADERS = BaudUtils.h \
                  ConfigModel.h \
                  FlowControlUtils.h \
                  PortConfig.h \
                  CharSizeUtils.h \
                  ConfigNotFoundException.h \
                  ModeUtils.h \
                  Command.h \
                  DeviceNotFoundException.h \
                  ParityUtils.h
