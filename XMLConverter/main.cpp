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

int main(int argc, const char * argv[])
{
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			tinyxml2::XMLDocument doc;
			DrXMLInterpreter::ConvertSource_Takasu(doc, argv[i]);
		}

	}
	
    return 0;
}
