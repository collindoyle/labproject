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

		DrAnalyzer analyist;
		std::list<DrAttributeList> attrlist;
		for (int i = 1; i < argc; i++) {
			DrDocument doc;
			std::cout<<"Start Main: "<<argv[i]<<std::endl;
			DrXMLInterpreter::ReadFrom(doc, argv[i]);
			std::cout<<"File: "<<argv[i]<<std::endl;
			std::list<DrPage *> &pages = doc.GetPageList();
			for (std::list<DrPage *>::iterator it = pages.begin(); it != pages.end(); it++) {
				analyist.ExtractAttributeList(attrlist, **it);
			}
			std::cout<<"End Main"<<std::endl;
		}
		analyist.TrainSVMModel(attrlist,ATTRSIZE);
	}
	delete fc;
	return 0;
}