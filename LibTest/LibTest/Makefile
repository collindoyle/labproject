#GNU Makefile


LDFLAGS := -L../../../thirdparty/mupdf/build/debug -L../../DataElements/ -L../../Extractor
CFLAGS := -I../../../thirdparty/mupdf/include -I../../DataElements -I../../Extractor
LIBRARIES:=  -lextractor -ldataelement -lmupdf -lmupdf-js-none -lopenjpeg -ljpeg -lfreetype -ljbig2dec -lz

all: LibTest
LibTest: DrTest.o
	g++ $(LDFLAGS)  DrTest.o $(LIBRARIES) -o LibTest
	rm -rf *.o
DrTest.o: DrTest.h DrTest.cpp
	g++ $(CFLAGS) -c DrTest.cpp -o DrTest.o

clean:
	rm -rf *.o LibTest