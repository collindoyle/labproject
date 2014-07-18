//
//  DrAttributeList.h
//  DrEntity
//
//  Created by Chu Yimin on 2013/06/28.
//  Copyright (c) 2013年 東京大学. All rights reserved.
//

#ifndef __DrEntity__DrAttributeList__
#define __DrEntity__DrAttributeList__

#include <iostream>
#include "DrFontDescriptor.h"

enum eZoneLabel {
    NONE = 0,
    TITLE,
    TEXTBODY,
    ABSTRACT,
    AUTHOR,
    KEYWORD,
    ALLIFICATION,
    CAPTION,
    PAGENUM,
    SUBTITLE,
    REFERENCE,
    START,
    END
};

enum ealign {
    LEFT = 0,
    CENTER = 1,
    RIGHT = 2
    };

const int ATTRSIZE = 10;
class DrAttributeList {
public:
    eZoneLabel  m_label;
/*    float               m_aversize;
    int                 m_charcount;
    float               m_spacebefore;
    float               m_spacein;
    float               m_spaceafter;
    int                 m_align;
	int					m_left;
	int					m_center;
	int					m_right;
    DrFontDescriptor::style m_style;
	int 				m_bold;
	int					m_italic;
*/
	/*
	 0		average font size
	 1		character count
	 2		space from previous paragraph
	 3		line space within the paragraph
	 4		space to next paragraph
	 5		is left aligned
	 6		is center aligned
	 7		is right aligned
	 8		is bold
	 9		is italic
	 */
	float 				m_attributevector[ATTRSIZE];
public:
    DrAttributeList();
};

#endif /* defined(__DrEntity__DrAttributeList__) */
