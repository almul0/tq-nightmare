
//TUPPERMICROABIERTOCONPAPEL

#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage8 : public ofxStage {
public: 

	ofxStage8();

	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);
	
	ofVec2f obj1;
	ofVec2f obj2;

	int chStage;
};

