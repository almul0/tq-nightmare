
//VIDEOESCALERAS

#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage16 : public ofxStage {
public: 

	ofxStage16();

	int nextStage();
	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);
	
	int chStage;
   
};

