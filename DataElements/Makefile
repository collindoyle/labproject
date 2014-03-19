# GNU Makefile

build ?= debug

CFLAGS := $(CFLAGS) -Wall -Wvla -static -g -I../../thirdparty/mupdf/include/

LDFLAGS := -L../../thirdparty/mupdf/build/debug/

LIBRARIES:= -lmupdf -lopenjpeg -ljpeg -ljbig2dec -lfreetype -lz

SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp, %.o, $(SRC))
TARGET := libdataelement.a


all: $(OBJ) $(TARGET)


$(TARGET): $(OBJ)
	ar csrv $(TARGET) $(OBJ) $(LDFLAGS) $(LIBRARIES)

$(OBJ): $(SRC)

.cpp.o:
	g++ $(CFLAGS) -c $<

	
clean:
	rm -rf *.o $(TARGET)
	
