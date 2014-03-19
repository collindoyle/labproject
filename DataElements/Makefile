# GNU Makefile

build ?= debug

CFLAGS := $(CFLAGS) -Wall -Wvla -g

SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp, %.o, $(SRC))
TARGET := libdataelement.a


all: $(OBJ) $(TARGET)


$(TARGET): $(OBJ)
	ar $(TARGET) $(OBJ)

$(OBJ): $(SRC)

.cpp.o:
	g++ $(CFLAGS) -c $<

	
clean:
	rm -rf *.o $(TARGET)
	
