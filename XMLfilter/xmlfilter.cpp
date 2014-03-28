//
//  xmlfilter.cpp
//  xmlfilter
//
//  Created by Chu Yimin on 2014/03/28.
//
//

#include "xmlfilter.h"

#include "tinyxml2.h"
#include "DrXMLInterpreter.h"
#include "DrTexGrouper.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <memory.h>
#include <string>

int main (int argc, char ** argv) {
	for (int i = 1; i < argc; i++) {
		
		unsigned long namelength = strlen(argv[i]);
		char * newname = new char[namelength+1+4];
		memset(newname, 0, namelength+1+4);
		strcpy(newname, argv[i]);
		char *loc = strcasestr(newname, ".xml");
		unsigned long suffixlen = strlen(loc+1);
		char *suf = new char[suffixlen];
		strcpy(suf, loc);
		strcpy(loc, ".new");
		strcat(loc, suf);
		std::cout<<newname<<std::endl;
		
		
		std::ifstream src;
		std::ofstream dist;
		
		src.open(argv[i]);
		dist.open(newname);
		std::string buf;
		while (!src.eof()) {
			char content;
			src.get(content);
			bool tagstart = false;
			bool tagflag = false;
			bool filtertag = false;
			bool endtag = false;
			switch (content) {
				case '<':
					tagflag = true;
					tagstart = true;
					buf+=content;
					break;
					
				case '>':

					buf.push_back(content);
					if (!filtertag) {
						dist<<buf;
					}
					buf.clear();
					tagflag = false;
					tagstart = false;
					filtertag = false;
					endtag = false;
					break;
				case '/':
					if (tagstart) {
						endtag = true;
						buf+=content;
					}
					else
					{
						if (tagflag) {
							buf+=content;
						}
						else
							dist<<content;
					}
					break;
				case 'b':
					if (tagstart || endtag) {
						buf+=content;
						filtertag = true;
						
					}
					else {
						if (tagflag) {
							buf+=content;
						}
					}
					tagstart = false;
					break;
				default:
					tagstart = false;
					if (tagflag) {
						buf+=content;
					}
					else
						dist<<content;
					break;
			}
		}
		delete suf;
		delete newname;
		dist.close();
		src.close();
		
	}
	return 0;
}