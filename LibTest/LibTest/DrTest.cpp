//
//  DrTest.cpp
//  DrTest
//
//  Created by Chu Yimin on 2013/10/24.
//  Copyright (c) 2013年 東京大学. All rights reserved.
//

#include "DrTest.h"
extern "C"
{
#include "mupdf/fitz.h"
}
#include "DrDocument.h"
#include "DrPDFExtractor.h"
#include "DrXMLInterpreter.h"
int main(int argc, char **argv)
{
	DrDocument doc;
	DrPDFExtracor extractor;
	DrXMLInterpreter interpreter;
	std::cout<<"it works."<<std::endl;
	return 0;
}