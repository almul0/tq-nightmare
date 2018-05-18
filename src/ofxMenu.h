
//MENU

#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxMenu : public ofxStage {
public: 

	ofxMenu();

	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);
	int chStage;

	ofVec2f obj1;
};

