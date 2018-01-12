#pragma once

#define LOGLEVEL OF_LOG_NOTICE

#include "ofMain.h"

#include "ofxMenu.h"
#include "ofxStage1.h"
#include "ofxStage2.h"
#include "ofxStage3.h"
#include "ofxStage4.h"
#include "ofxStage5.h"
#include "ofxStage6.h"
#include "ofxStage7.h"
#include "ofxStage8.h"
#include "ofxStage9.h"
#include "ofxStage10.h"
#include "ofxStage11.h"
#include "ofxStage12.h"
#include "ofxStage13.h"
#include "ofxStage14.h"
#include "ofxStage15.h"
#include "ofxStage16.h"
#include "ofxStage17.h"
#include "ofxStage18.h"
#include "ofxStage19.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	int currentStage;
	int prevStage;

	ofxMenu menu;
	ofxStage1 stage1;
	ofxStage2 stage2;
	ofxStage3 stage3;
	ofxStage4 stage4;
	ofxStage5 stage5;
	ofxStage6 stage6;
	ofxStage7 stage7;
	ofxStage8 stage8;
	ofxStage9 stage9;
	ofxStage10 stage10;
	ofxStage11 stage11;
	ofxStage12 stage12;
	ofxStage13 stage13;
	ofxStage14 stage14;
	ofxStage15 stage15;
	ofxStage16 stage16;
	ofxStage17 stage17;
	ofxStage17 stage18;
	ofxStage17 stage19;

	vector<shared_ptr<ofxStage>> arrayStage;
	ofImage arrayImageStage[15];
	ofImage arrayImageObjects[2];
	ofVideoPlayer arrayVideo[5];

	ofSoundPlayer ambient;

	//Linterna
	ofPoint cursor;
	ofImage lantern;
};