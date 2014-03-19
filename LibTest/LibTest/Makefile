#GNU Makefile


LDFLAGS := -L../../../thirdparty/mupdf/build/debug -L../../DataElements/ -L../../Extractor
CFLAGS := -I../../../thirdparty/mupdf/include/ -I../../DataElements/ -I../../Extractor/
LIBRARIES:= -lextractor -lmupdf-js-none -ldataelement -lmupdf-js-none -lopenjpeg -ljpeg -ljbig2dec -lfreetype -lz

all: LibTest
LibTest: DrTest.o
	gcc $(LDFLAGS) -o LibTest DrTest.o $(LIBRARIES)
	rm -rf *.o
DrTest.o: DrTest.h DrTest.cpp
	gcc $(CFLAGS) -c DrTest.cpp -o DrTest.o

clean:
	rm -rf *.o LibTest