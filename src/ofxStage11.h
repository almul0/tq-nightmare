
//MICROABIERTOSINPAPEL

#pragma once

#include "ofMain.h"
#include "ofxStage.h"

class ofxStage11 : public ofxStage {
public: 

	ofxStage11();

	int mousePressed(int x, int y);
	int keyPressed(int key, int currentStage);

	int chStage;
   
};

