# GNU Makefile

build ?= debug

CFLAGS := $(CFLAGS) -Wall -Wvla -g

SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp, %.o, $(SRC))
TARGET := libdataelement.a


all: $(SRC) $(TARGET)

.cpp.o:
	g++ $(CFLAGS) -c $<
	
$(TARGET): $(OBJS)
	ar $(TARGET) $(OBJ)


	
clean:
	rm -rf *.o $(TARGET)
	
