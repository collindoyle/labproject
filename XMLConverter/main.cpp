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
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			tinyxml2::XMLDocument doc;
			DrXMLInterpreter::ConvertSource_Takasu(doc, argv[i]);
            int len = strlen(argv[i]+1);
            char * poutname = new char[len+9];
            strcpy(poutname, argv[i]);
            strcat(poutname, ".conv.xml");
			doc.SaveFile(poutname);
            delete [] poutname;
		}

	}
	
    return 0;
}
