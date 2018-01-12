
//LECTORFINAL

#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage13 : public ofxStage {
public: 

	ofxStage13();

	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);
	
	ofVec2f obj1;

	int chStage;
   
};

