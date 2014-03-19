#GNU Makefile


LDFLAGS := -L../../../thirdparty/mupdf/build/debug/ -L../../DataElements/
CFLAGS := -I../../../thirdparty/mupdf/include/ -I../../DataElements/
LIBRARIES:= -lmupdf -lopenjpeg -ljpeg -ljbig2dec -lfreetype -lz -ldataelement

all: LibTest
LibTest: DrTest.o
	g++ $(LDFLAGS) -o LibTest DrTest.o $(LIBRARIES)
	rm -rf *.o
DrTest.o: DrTest.h DrTest.cpp
	g++ $(CFLAGS) -c DrTest.cpp -o DrTest.o

clean:
	rm -rf *.o LibTest