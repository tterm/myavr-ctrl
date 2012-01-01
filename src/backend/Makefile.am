#we build a dummy static lib here to add code separation
noinst_LIBRARIES = libbackend.a

AM_LDFLAGS = -L/opt/libserial-0.5.2/lib/ -lserial

AM_CPPFLAGS = -Wall -ansi -Wextra \
              -I /opt/libserial-0.5.2/include


libbackend_a_SOURCES = BaudUtils.cpp \
                       CharSizeUtils.cpp \
                       Command.cpp \
                       ConfigModel.cpp \
                       ConfigNotFoundException.cpp \
                       DeviceNotFoundException.cpp\
                       FlowControlUtils.cpp \
                       ModeUtils.cpp \
                       ParityUtils.cpp \
                       PortConfig.cpp
