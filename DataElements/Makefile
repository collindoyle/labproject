# GNU Makefile

build ?= debug

CFLAGS := $(CFLAGS) 

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
TARGET = libdataelement.lib


all: $(SRC) $(TARGET)

	
$(TARGET): $(OBJS)


.cpp.o:
	g++ $(CFLAGS) -c $<
	
