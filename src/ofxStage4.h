//
//  ofxQuadWarp.h
//  Created by lukasz karluk on 19/06/11.
//
//  nay added hack to invert on 2011/06/21
//
#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage4 : public ofxStage {
public: 

	ofxStage4();

	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);
	
	int chStage;
   
};

