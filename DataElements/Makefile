# GNU Makefile

build ?= debug

CFLAGS := $(CFLAGS) 

default: all

all: lib

lib: *.o

.cpp.o:
	g++ $(CFLAGS) -c $< -o $@
	
