# GNU Makefile

build ?= debug

CFLAGS := $(CFLAGS) 

SRC := $(wildcard *.c)
OBJ := $(patsubst %.c, %.o, $(SRC))

default: all

all: lib

objects := $(patsubst %.c, %.o, $(wildcard *.c))

lib: libdocelements.a
	
libdocelements.a: $(OBJS)

.cpp.o:
	g++ $(CFLAGS) -c $< -o $@
	
