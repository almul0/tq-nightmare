#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage15 : public ofxStage {
public: 

	ofxStage15();

	int nextStage();
	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);
	
	int chStage;
   
};

