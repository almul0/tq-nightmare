
//VIDEOMUERTE

#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage18 : public ofxStage {
public: 

	ofxStage18();

	int nextStage();

	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);

	int chStage;
   
};

