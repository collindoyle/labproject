#GNU Makefile


LDFLAGS := -L../../thirdparty/mupdf/build/debug -L../DataElements/ -L../Extractor -L../Analyist -L../../thirdparty/svm_light
CFLAGS := -I../../thirdparty/mupdf/include -I../DataElements -I../Extractor -I../Analyist -I../thirdparty/svm_light
LIBRARIES:=  -lanalyist -lextractor -ldataelement -lmupdf -lmupdf-js-none -lopenjpeg -ljpeg -lfreetype -ljbig2dec -lz

SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp, %.o, $(SRC))

TARGET := FVExtractor

all: $(TARGET)
$(TARGET): $(OBJ)
	g++ $(LDFLAGS)  $(OBJ) ../../thirdparty/svm_light/svm_learn.o ../../thirdparty/svm_light/svm_common.o ../../thirdparty/svm_light/svm_hideo.o $(LIBRARIES) -o $(TARGET)
	rm -rf *.o
.cpp.o:
	g++ $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGET)