#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage3 : public ofxStage {
public:

	ofxStage3();

	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);
	
	ofVec2f obj1;
	ofVec2f obj2;

	int chStage;
};

