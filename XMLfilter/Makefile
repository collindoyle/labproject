#GNU Makefile


LDFLAGS := -L../../thirdparty/mupdf/build/debug -L../DataElements/ -L../Extractor
CFLAGS := -I../../thirdparty/mupdf/include -I../DataElements -I../Extractor
LIBRARIES:=  -lextractor -ldataelement -lmupdf -lmupdf-js-none -lopenjpeg -ljpeg -lfreetype -ljbig2dec -lz

all: xmlfilter
xmlfilter: xmlfilter.o
	g++ $(LDFLAGS)  xmlfilter.o $(LIBRARIES) -o xmlfilter
	rm -rf *.o
xmlfilter.o: xmlfilter.h xmlfilter.cpp
	g++ $(CFLAGS) -c xmlfilter.cpp -o xmlfilter.o

clean:
	rm -rf *.o xmlfilter