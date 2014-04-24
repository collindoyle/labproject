# GNU Makefile

build ?= debug

CFLAGS := $(CFLAGS) -Wall -Wvla -g -I../../thirdparty/mupdf/include/ -I../DataElements/

LDFLAGS := ../../thirdparty/mupdf/build/debug/

LIBRARIES:= ../../thirdparty/svm_light/svm_learn.o ../../thirdparty/svm_light/svm_common.o ../../thirdparty/svm_light/svm_hideo.o ../DataElements/libdataelement.a $(LDFLAGS)/libmupdf.a $(LDFLAGS)/libopenjpeg.a $(LDFLAGS)/libjpeg.a $(LDFLAGS)/libjbig2dec.a $(LDFLAGS)/libfreetype.a $(LDFLAGS)/libz.a

SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp, %.o, $(SRC))
TARGET := libanalyist.a


all: $(OBJ) $(TARGET)


$(TARGET): $(OBJ)
	ar rv $(TARGET) $(OBJ)
	ranlib $@
$(OBJ): $(SRC)

.cpp.o:
	g++ $(CFLAGS) -c $<

	
clean:
	rm -rf *.o $(TARGET)
