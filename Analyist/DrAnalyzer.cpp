//
//  DrAnalyzer.cpp
//  DrAnalyzer
//
//  Created by Chu Yimin on 2013/06/28.
//  Copyright (c) 2013年 東京大学. All rights reserved.
//

#include "DrAnalyzer.h"
#include <fstream>
#include <iostream>
#include <map>

extern "C" {
#include "svm_common.h"
#include "svm_learn.h"
}



DrAnalyzer::DrAnalyzer()
{
    m_doc = NULL;
}

DrAnalyzer::~DrAnalyzer()
{
    
}

void DrAnalyzer::SetDocument(DrDocument *pdoc)
{
    m_doc = pdoc;
}

void DrAnalyzer::CalculateAttributes(DrPage & page)
{
	std::map<float, int> pagefontmap;
    
    
    for (std::list<DrZone *>::iterator itzone = page.m_zonelist.begin(); itzone != page.m_zonelist.end(); itzone++) {
        std::map<float, int> zonefontmap;
        DrZone * pzone = *itzone;
        pzone->m_attr = new DrAttributeList;
        float leftalign, rightalign, centeralign;
        leftalign = rightalign = centeralign = 0.0;
        float centerzone;
        float inzonedistance = 0.0;
        int linecount = 0;
        int charcount = 0;
        if (pzone->m_label != NONE) {
            pzone->m_attr->m_label = pzone->m_label;
        }
        if ((*itzone)->m_direction == HORIZONAL) {
            centerzone = ((*itzone)->m_bbox.m_x1 + (*itzone)->m_bbox.m_x0)/2;
        }
        else
        {
            centerzone = ((*itzone)->m_bbox.m_y1 + (*itzone)->m_bbox.m_y0)/2;
        }
        
        
        // Compare with every zone on this page and get the closest zone, calculate the offset
        DrPoint prev, next;
        for (std::list<DrZone *>::iterator itcomp = page.m_zonelist.begin(); itcomp != page.m_zonelist.end(); itcomp++) {
            if (itcomp == itzone) {
                continue;
            }
            DrPoint offset = (*itzone)->m_bbox.Offset((*itcomp)->m_bbox);
            if ((*itzone)->m_direction == VERTICAL) {
                if (offset.x < 0) {
                    if (prev.Size() == 0) {
                        prev = offset;
                    }
                    else
                    {
                        if (prev.Size() > offset.Size()) {
                            prev = offset;
                        }
                    }
                }
                else if (offset.x > 0)
                {
                    if (next.Size() == 0) {
                        next = offset;
                    }
                    else
                    {
                        if (next.Size() > offset.Size()) {
                            next = offset;
                        }
                    }
                }
            }
			
            else  {
                if (offset.y > 0) {
                    if (prev.Size() == 0) {
                        prev = offset;
                    }
                    else
                    {
                        if (prev.Size() > offset.Size()) {
                            prev = offset;
                        }
                    }
                }
                else if (offset.y < 0)
                {
                    if (next.Size() == 0) {
                        next = offset;
                    }
                    else
                    {
                        if (next.Size() > offset.Size()) {
                            next = offset;
                        }
                    }
                }
            }
        }
        
        if ((*itzone)->m_direction == VERTICAL)
        {
            (*itzone)->m_attr->m_attributevector[2] = prev.x;
            (*itzone)->m_attr->m_attributevector[4] = next.x;
        }
        else {
            (*itzone)->m_attr->m_attributevector[2] = prev.y;
            (*itzone)->m_attr->m_attributevector[4] = next.y;
        }
        
        
        for (std::list<DrLine *>::iterator itline = pzone->m_linelist.begin(); itline != pzone->m_linelist.end(); itline++) {
            DrLine *pline = *itline;
			
            for (std::list<DrPhrase *>::iterator itphrase = pline->m_phraselist.begin(); itphrase != pline->m_phraselist.end(); itphrase++) {
                
                // count Most used font size
                DrFontDescriptor * pfont = (*itphrase)->m_font;
                if (pfont->m_fontstyle != DrFontDescriptor::FS_NONE) {
					if (pfont->m_fontstyle == DrFontDescriptor::FS_BOLD || pfont->m_fontstyle == DrFontDescriptor::FS_BOLD_ITALIC) {
						pzone->m_attr->m_attributevector[8] = 1;
					}
					else
						pzone->m_attr->m_attributevector[8] = 0;
					if (pfont->m_fontstyle == DrFontDescriptor::FS_ITALIC || pfont->m_fontstyle == DrFontDescriptor::FS_BOLD_ITALIC) {
						pzone->m_attr->m_attributevector[9] = 1;
					}
					else
						pzone->m_attr->m_attributevector[9] = 0;
                }
                charcount += (*itphrase)->m_charlist.size();
                std::map<float,int>::iterator itlocalmap = zonefontmap.find(pfont->m_fontsize);
                if (itlocalmap == zonefontmap.end()) {
                    zonefontmap.insert(std::pair<float,int>(pfont->m_fontsize, (*itphrase)->m_charlist.size()));
                }
                else
                {
                    itlocalmap->second += (*itphrase)->m_charlist.size();
                }
                
                std::map<float, int>::iterator itpagemap = pagefontmap.find(pfont->m_fontsize);
                if (itpagemap == pagefontmap.end()) {
                    pagefontmap.insert(std::pair<float,int>(pfont->m_fontsize, (*itphrase)->m_charlist.size()));
                }
                else
                {
                    itpagemap->second += (*itphrase)->m_charlist.size();
                }
            }
            
            // calculate spacing between lines
            std::list<DrLine *>::iterator itnext = (++itline)--;
            if (itnext != pzone->m_linelist.end()) {
                float x, y;
                (*itline)->m_bbox.Distance((*itnext)->m_bbox,x,y);
                if (pzone->m_direction == HORIZONAL) {
                    inzonedistance += y;
                }
                else
                {
                    inzonedistance += x;
                }
                linecount ++;
            }
            // calculate the alignment
            if ((*itzone)->m_direction == HORIZONAL) {
                leftalign+= fabs(((*itline)->m_bbox).m_x0-(*itzone)->m_bbox.m_x0);
                rightalign += fabs(((*itline)->m_bbox.m_x1)-(*itzone)->m_bbox.m_x1);
                float centerline = ((*itline)->m_bbox.m_x0 + (*itline)->m_bbox.m_x1)/2;
                centeralign += fabs(centerline - centerzone);
            }
            else
            {
                leftalign+= fabs(((*itline)->m_bbox).m_y0 - (*itzone)->m_bbox.m_y0);
                rightalign += fabs(((*itline)->m_bbox).m_y1 - (*itzone)->m_bbox.m_y1);
                float centerline = ((*itline)->m_bbox.m_y0 + (*itline)->m_bbox.m_y1)/2;
                centeralign += fabs(centerline - centerzone);
            }
			
        }
        if (linecount != 0) {
            pzone->m_attr->m_attributevector[3] = inzonedistance/linecount;
        }
		
        float minalignaccum = centeralign < rightalign ? centeralign : rightalign;
        minalignaccum = minalignaccum < leftalign ? minalignaccum : leftalign;
        
        if (minalignaccum == leftalign) {
            (*itzone)->m_attr->m_attributevector[5] = LEFT;
			(*itzone)->m_attr->m_attributevector[6] = 0;
			(*itzone)->m_attr->m_attributevector[7] = 0;
        }
        else if (minalignaccum == centeralign)
        {
			(*itzone)->m_attr->m_attributevector[5] = 0;
			(*itzone)->m_attr->m_attributevector[6] = 1;
			(*itzone)->m_attr->m_attributevector[7] = 1;
        }
        else
        {
			(*itzone)->m_attr->m_attributevector[5] = 0;
			(*itzone)->m_attr->m_attributevector[6] = 0;
			(*itzone)->m_attr->m_attributevector[7] = 1;
        }
        int maxcount = 0; float fontsize = 0.0;
        for(std::map<float, int>::iterator itmap = zonefontmap.begin(); itmap != zonefontmap.end(); itmap++)
        {
            if (itmap->second > maxcount) {
                maxcount = itmap->second;
                fontsize = itmap->first;
            }
        }
        pzone->m_attr->m_attributevector[0] = fontsize;
        pzone->m_attr->m_attributevector[1] = charcount;
    }
    
    int pagefontcount = 0;
    float mostfontsize = 0.0;
    for (std::map<float, int>::iterator itpagefontmap = pagefontmap.begin(); itpagefontmap != pagefontmap.end(); itpagefontmap++) {
        if (itpagefontmap->second > pagefontcount) {
            pagefontcount = itpagefontmap->second;
            mostfontsize = itpagefontmap->first;
        }
    }
    
    // Normalization
    for (std::list<DrZone *>::iterator itzone = page.m_zonelist.begin(); itzone != page.m_zonelist.end(); itzone++) {
        (*itzone)->m_attr->m_attributevector[0] = (*itzone)->m_attr->m_attributevector[0]/mostfontsize;
    }
}

void DrAnalyzer::CalculateAttributes(DrPage &page, const char * outputfilename)
{
	CalculateAttributes(page);
    std::ofstream outf;
    outf.open(outputfilename,std::ios_base::app);
    for (std::list<DrZone *>::iterator itzone = page.m_zonelist.begin(); itzone != page.m_zonelist.end(); itzone++) {
        DrAttributeList * attr = (*itzone)->m_attr;
        outf<<attr->m_label;
		for (int i = 0; i < ATTRSIZE; i++) {
			outf<<" "<<i<<":"<<attr->m_attributevector[i];
		}
		outf<<std::endl;
    }
    outf.close();
    
}

void DrAnalyzer::ExtractAttributeList(std::list<DrAttributeList> &attrlist, DrPage &page)
{
	CalculateAttributes(page);
	for (std::list<DrZone *>::iterator itzone = page.m_zonelist.begin(); itzone != page.m_zonelist.end(); itzone++) {
		attrlist.push_back(*(*itzone)->m_attr);
	}
}

void DrAnalyzer::TrainSVMModel(std::list<DrAttributeList> &attrlist, int featurelength)
{
	// Train for the title model
	DOC **docs;  /* training examples */
	long totwords,totdoc,i;
	double *target;
	double *alpha_in=NULL;
	KERNEL_CACHE *kernel_cache;
	LEARN_PARM learn_parm;
	KERNEL_PARM kernel_parm;
	MODEL *model=(MODEL *)my_malloc(sizeof(MODEL));
	
	long verbosity=1;
	learn_parm.biased_hyperplane=1;
	learn_parm.sharedslack=0;
	learn_parm.remove_inconsistent=0;
	learn_parm.skip_final_opt_check=0;
	learn_parm.svm_maxqpsize=10;
	learn_parm.svm_newvarsinqp=0;
	learn_parm.svm_iter_to_shrink=-9999;
	learn_parm.maxiter=100000;
	learn_parm.kernel_cache_size=40;
	learn_parm.svm_c=0.0;
	learn_parm.eps=0.1;
	learn_parm.transduction_posratio=-1.0;
	learn_parm.svm_costratio=1.0;
	learn_parm.svm_costratio_unlab=1.0;
	learn_parm.svm_unlabbound=1E-5;
	learn_parm.epsilon_crit=0.001;
	learn_parm.epsilon_a=1E-15;
	//	learn_parm.epsilon_shrink=0.1;
	learn_parm.compute_loo=0;
	learn_parm.rho=1.0;
	learn_parm.xa_depth=0;
	kernel_parm.kernel_type=0;
	kernel_parm.poly_degree=3;
	kernel_parm.rbf_gamma=1.0;
	kernel_parm.coef_lin=1;
	kernel_parm.coef_const=1;
	kernel_parm.kernel_type = LINEAR;
	learn_parm.type = CLASSIFICATION;
	strcpy(learn_parm.alphafile,"");
	kernel_cache = NULL;
	strcpy(kernel_parm.custom,"empty");
	long counter = 0;
	docs = new DOC*[attrlist.size()];
	target = new double[attrlist.size()];
	for (std::list<DrAttributeList>::iterator itattr = attrlist.begin(); itattr != attrlist.end(); itattr++) {
		DOC *docvector = new DOC;
		docs[counter] = docvector;
		eZoneLabel label = (*itattr).m_label;
		if (label == TEXTBODY) {
			target[counter] = 1;
		}
		else
			target[counter] = -1;
		SVECTOR * vector = new SVECTOR;
		vector->next = NULL;
		docvector->docnum = counter++;
		vector->words = new WORD[featurelength];
		for (int i = 0; i < ATTRSIZE; i++) {
			vector->words[i].wnum = i;
			vector->words[i].weight = (*itattr).m_attributevector[i];
		}
		docvector->fvec = vector;
	}
	totwords = ATTRSIZE;
	totdoc = attrlist.size();
	svm_learn_classification(docs, target, totdoc, totwords, &learn_parm, &kernel_parm, kernel_cache, model, alpha_in);
	write_model("model.dat", model);
	delete model;
	for (int i = 0; i <totdoc; i++) {
		delete [] docs[i]->fvec->words;
		delete [] docs[i]->fvec;
	}
	delete [] docs;
	delete target;
	
}