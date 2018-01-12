
//VIDEOVICTORIA

#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage17 : public ofxStage {
public: 

	ofxStage17();

	int nextStage();

	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);

	int chStage;
   
};

