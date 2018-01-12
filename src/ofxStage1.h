//PASILLO1

#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage1 : public ofxStage {
public: 

	ofxStage1();

	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);
	
	ofVec2f obj1;
	ofVec2f obj2;
	ofVec2f obj3;	

	ofSoundPlayer laught;

	bool laughtPlayed;

	int chStage;
   
};

