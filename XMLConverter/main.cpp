//
//  main.cpp
//  XMLConverter
//
//  Created by Chu Yimin on 2014/04/02.
//
//

#include "main.h"
#include <iostream>
#include "DrDocument.h"
#include "DrXMLInterpreter.h"
#include "DrTexGrouper.h"
#include "tinyxml2.h"
#include <cstring>

int main(int argc, const char * argv[])
{
	DrFontCache * fc = new DrFontCache;
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			tinyxml2::XMLDocument xmldoc;
			DrDocument doc;
			DrXMLInterpreter::SetFontCache(fc);
			DrXMLInterpreter::XMLConvertSource_Takasu(doc, argv[i]);
		}

	}
	delete fc;
    return 0;
}
