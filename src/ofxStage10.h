
//TUPPERMICROABIERTOSINPAPEL

#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage10 : public ofxStage {
public: 

	ofxStage10();

	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);
	
	ofVec2f obj1;
	ofVec2f obj2;

	int chStage;
   
};

