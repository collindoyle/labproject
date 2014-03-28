#GNU Makefile

SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp, %.o, $(SRC))
TARGET := libanalyst.a


all: $(OBJ) $(TARGET)





all:

$(TARGET) : $(OBJ)
	ar rv $(TARGET) $(OBJ)
	ranlib $@

.cpp.o : 

	g++ $(CFLAGS) -c $<




clean:
	rm *.o $(TARGET)