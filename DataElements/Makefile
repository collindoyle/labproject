# GNU Makefile

build ?= debug

CFLAGS := $(CFLAGS) 

default: all

all: lib

objects := $(patsubst %.c, %.o, $(wildcard *.c))

lib: $(objects)
.cpp.o:
	g++ $(CFLAGS) -c $< -o $@
	
