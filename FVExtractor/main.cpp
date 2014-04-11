//
//  main.cpp
//  FVExtractor
//
//  Created by Chu Yimin on 2014/04/11.
//
//

#include "main.h"

#include "DrDocument.h"
#include "DrAnalyzer.h"
#include "DrXMLInterpreter.h"
#include <iostream>
#include <cstring>
#include <list>

int main(int argc, char * argv[])
{
	DrFontCache * fc = new DrFontCache;
	DrXMLInterpreter::SetFontCache(fc);
	if (argc >= 2) {
		
		for (int i = 1; i < argc; i++) {
			DrAnalyzer analyist;
			DrDocument doc;
			DrXMLInterpreter::ReadFrom(doc, argv[i]);
			std::list<DrPage *> &pages = doc.GetPageList();
			for (std::list<DrPage *>::iterator it = pages.begin(); it != pages.end(); it++) {
				analyist.CalculateAttributes(**it, "features.dat");
			}
		}
	}
	delete fc;
	return 0;
}