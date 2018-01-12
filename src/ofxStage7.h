
//MICROCERRADO

#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage7 : public ofxStage {
public: 

	ofxStage7();

	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);
	
	ofVec2f obj1;

	int chStage;
};

