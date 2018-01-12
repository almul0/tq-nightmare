#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage2 : public ofxStage {
public:

	ofxStage2();

	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);
	
	ofVec2f obj1;
	ofVec2f obj2;
	ofVec2f obj3;
	ofVec2f obj4;
	ofVec2f obj5;

	ofSoundPlayer button;
	ofSoundPlayer buttonCorrect;
	ofSoundPlayer buttonIncorrect;

	int chStage;
};

