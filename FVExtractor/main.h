//
//  main.h
//  FVExtractor
//
//  Created by Chu Yimin on 2014/04/11.
//
//

#ifndef __FVExtractor__main__
#define __FVExtractor__main__

#include "DrDocument.h"
#include "DrAnalyzer.h"
#include "DrXMLInterpreter.h"
#include <iostream>
#include <cstring>
#include <list>

int main(int argc, char * argv[])
{
	
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
	
	return 0;
}

#endif /* defined(__FVExtractor__main__) */
