
//VIDEOPASILLOTUPPER

#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage14 : public ofxStage {
public: 

	ofxStage14();

	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);

	int chStage;
   
};

