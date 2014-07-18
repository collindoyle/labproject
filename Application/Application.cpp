//
//  Application.cpp
//  Application
//
//  Created by Chu Yimin on 2014/06/18.
//  Copyright (c) 2014年 東京大学. All rights reserved.
//

#include "Application.h"

Application::Application()
{
	kc = NULL;
	outputfilename = NULL;
	modelfilename = NULL;
}

Application::~Application()
{
	if (kc) {
		kernel_cache_cleanup(kc);
	}
	sourcelist.clear();
}

int Application::getparameters(int argc, char **argv)
{
	if (argc < 2) {
		return -1;
	}
	
	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '-' && i < argc) {
			switch (argv[i][1]) {
				case 'o':
					i++;
					outputfilename = argv[i];
					break;
				case 'm':
					i++;
					modelfilename = argv[i];
				default:
					break;
			}
		}
		else
			sourcelist.push_back(argv[i]);
	}
	return 1;
}

void Application::appsvmtrain()
{
	
}

void Application::appsvmmultitrain()
{
	
}

void Application::appcrftrain()
{
	
}
