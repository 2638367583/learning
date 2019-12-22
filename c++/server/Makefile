TOP := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))/../../

TARGET := server

ifeq ($(findstring .so, $(TARGET)),)
TYPE ?= app
INSTALL_DIR ?= $(BINDIR)
else
TYPE ?= so
INSTALL_DIR ?= $(LIBDIR)
endif

INCLUDES += -I. 
CPPFLAGS += -g -Wall -std=c++0x -Werror -fstack-protector-all -Wsign-compare
CFLAGS += -g -Wall -Werror -Wshadow -fstack-protector-all -Wsign-compare

LIBS += 

ifeq ($(TYPE),so)
# so TARGET: libbase.so.1.2.345
SO_BASE_NAME := $(shell echo $(TARGET) | sed 's/\(.*\)\.so\(\.[0-9]\+\)\?\(\.[0-9]\+\)\?\(\.[0-9]\+\)\?/\1.so/')

SO_NAME := $(SO_BASE_NAME)
TARGET = $(SO_BASE_NAME)

LINKFLAGS += -shared -fPIC -DPIC -Wl,-soname,$(SO_NAME)
CPPFLAGS += -fPIC -DPIC 
CFLAGS += -fPIC -DPIC
ASMFLAGS += -fPIC -DPIC
endif


CC = ${CROSS_COMPILE}gcc
CXX = ${CROSS_COMPILE}g++

.c.o:
	$(CC) -c -o $*.o $(CFLAGS) $(INCLUDES) $*.c
.cpp.o:
	$(CXX) -c -o $*.o $(CPPFLAGS) $(INCLUDES) $*.cpp

.s.o:
	$(CXX) -c -o $*.o $(ASMFLAGS) $(INCLUDES) $*.s


CFILE ?= $(wildcard *.c)
CXXFILE ?= $(wildcard *.cpp)
ASMFILE ?= $(wildcard *.s)
ALLOBJS = $(CXXFILE:.cpp=.o) $(CFILE:.c=.o) $(ASMFILE:.s=.o)

all: compile

compile: $(ALLOBJS)
	$(CXX)  -o $(TARGET) $^ $(LIBS) $(LINKFLAGS)

$(TARGET):compile

clean: $(myclean)
	-rm -f $(CFILE:.c=.o) 
	-rm -f $(CXXFILE:.cpp=.o)
	-rm -f $(ASMFILE:.s=.o)
	-rm -f $(TARGET) $(TARGET).gcovinfo
	-rm -f $(CFILE:.c=.gcno) $(CFILE:.c=.gcda) $(CFILE:.c=.c.gcov)
	if [ -f $(TARGET).rc ];then rm -rf $(TARGET).rc;fi

install: $(myinstall)
	if [ ! -d $(INSTALL_TARGET_DIR) ];then mkdir -p $(INSTALL_TARGET_DIR);fi
	cp -f $(TARGET) $(INSTALL_TARGET_DIR)

ifneq ($(HEADERS),)
	if [ ! -d $(INSTALL_INC_DIR) ];then mkdir -p $(INSTALL_INC_DIR);fi 
	cp -rf $(HEADERS) $(INSTALL_INC_DIR)
endif

.PHONY: all clean target install





