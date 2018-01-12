
//MICROABIERTOCONPAPEL

#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage9 : public ofxStage {
public: 

	ofxStage9();

	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);
	
	ofVec2f obj1;

	int chStage;
};

