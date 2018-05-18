
//FINJUEGO

#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage19 : public ofxStage {
public: 

	ofxStage19();

	int nextStage();

	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);
	
	int chStage;
   
};

