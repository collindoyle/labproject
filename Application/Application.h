//
//  Application.h
//  Application
//
//  Created by Chu Yimin on 2014/06/18.
//  Copyright (c) 2014年 東京大学. All rights reserved.
//

#ifndef __Application__Application__
#define __Application__Application__

#include <iostream>
#include <vector>
extern "C" {
#include "svm_common.h"
#include "svm_learn.h"
}

class Application {
public:
	std::vector<char *> sourcelist;
	char * 			outputfilename;
	char *			modelfilename;
	KERNEL_CACHE * kc;
	LEARN_PARM learnparm;
	KERNEL_PARM kernelparm;
	
	Application();
	~Application();
	int getparameters(int argc, char **argv);
	void appsvmtrain();
	void appsvmmultitrain();
	void appcrftrain();
};

#endif /* defined(__Application__Application__) */
