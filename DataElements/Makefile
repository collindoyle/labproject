# GNU Makefile

build ?= debug

CFLAGS := $(CFLAGS) 

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
TARGET = libdataelement.lib


all: $(SRC) $(TARGET)

	
$(TARGET): $(OBJS)


.cpp.o:
	g++ $(CFLAGS) -c $<
	
