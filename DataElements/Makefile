# GNU Makefile

build ?= debug

CFLAGS := $(CFLAGS) -Wall -Wvla -g

SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp, %.o, $(SRC))
TARGET := libdataelement.a


all: $(SRC) $(TARGET)


$(TARGET): $(OBJS)
	ar $(TARGET) $(OBJ)

.cpp.o:
	g++ $(CFLAGS) -c $<

	
clean:
	rm -rf *.o $(TARGET)
	
