# GNU Makefile

build ?= debug

CFLAGS := $(CFLAGS) 

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
TARGET = libdataelement.lib


all:

lib: libdocelements.a
	
libdocelements.a: $(OBJS)

.cpp.o:
	g++ $(CFLAGS) -c $<
	
