
//FINAL

#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage12 : public ofxStage {
public: 

	ofxStage12();

	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);
	
	ofVec2f obj1;

	int chStage;
   
};

