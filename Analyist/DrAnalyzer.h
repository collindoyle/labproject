//
//  DrAnalyzer.h
//  DrAnalyzer
//
//  Created by Chu Yimin on 2013/06/28.
//  Copyright (c) 2013年 東京大学. All rights reserved.
//

#ifndef __DrAnalyzer__DrAnalyzer__
#define __DrAnalyzer__DrAnalyzer__

#include <iostream>
#include <list>
#include "DrDocument.h"

class DrAnalyzer {
public:
    DrDocument* m_doc;
    
    
public:
    DrAnalyzer();
    ~DrAnalyzer();
    void SetDocument(DrDocument* pdoc);
	void CalculateAttributes(DrPage & page);
    void CalculateAttributes(DrPage & page, const char * outputfilename);
	void ExtractAttributeList(std::list<DrAttributeList> & attrlist, DrPage & page);
	void TrainSVMModel(std::list<DrAttributeList> & attrlist);
};

#endif /* defined(__DrAnalyzer__DrAnalyzer__) */
