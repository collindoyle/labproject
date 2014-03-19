# GNU Makefile

build ?= debug

CFLAGS := $(CFLAGS) -Wall -Wvla -g -I../../thirdparty/mupdf/include/

LDFLAGS := ../../thirdparty/mupdf/build/debug/

LIBRARIES:= $(LDFLAGS)/libmupdf.a $(LDFLAGS)/libopenjpeg.a $(LDFLAGS)/libjpeg.a $(LDFLAGS)/libjbig2dec.a $(LDFLAGS)/libfreetype.a $(LDFLAGS)/libz.a

SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp, %.o, $(SRC))
TARGET := libdataelement.a


all: $(OBJ) $(TARGET)


$(TARGET): $(OBJ)
	ar csrv $(TARGET) $(OBJ) $(LIBRARIES)

$(OBJ): $(SRC)

.cpp.o:
	g++ $(CFLAGS) -c $<

	
clean:
	rm -rf *.o $(TARGET)
	
