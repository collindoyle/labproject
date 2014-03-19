# GNU Makefile

build ?= debug

CFLAGS := $(CFLAGS) 

SRC := $(wildcard *.c)
OBJ := $(patsubst %.c, %.o, $(SRC))

default: all

all: lib

objects := $(patsubst %.cpp, %.o, $(wildcard *.cpp))

lib: libdocelements.a
	
libdocelements.a: $(OBJS)

.cpp.o:
	g++ $(CFLAGS) -c $< -o $@
	
