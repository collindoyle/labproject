#GNU Makefile


LDFLAGS := -L../../thirdparty/mupdf/build/debug -L../DataElements/ -L../Extractor
CFLAGS := -I../../thirdparty/mupdf/include -I../DataElements -I../Extractor
LIBRARIES:=  -lextractor -ldataelement -lmupdf -lmupdf-js-none -lopenjpeg -ljpeg -lfreetype -ljbig2dec -lz

SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp, %.o, $(SRC))

TARGET := XMLConverter

all: $(TARGET)
$(TARGET): $(OBJ)
	g++ $(LDFLAGS)  $(OBJ) $(LIBRARIES) -o $(TARGET)
	rm -rf *.o
.cpp.o:
	g++ $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGET)