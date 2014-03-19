# GNU Makefile

build ?= debug

CFLAGS := $(CFLAGS) 

default: all

all: lib

lib: $(patsubst %.c, %.o, $(wildcard *.c))

.cpp.o:
	g++ $(CFLAGS) -c $< -o $@
	
