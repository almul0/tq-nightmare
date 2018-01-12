#pragma once

#define LOGLEVEL OF_LOG_NOTICE

#define WIDTH 1920
#define HEIGHT 480
#define STREAM_FRAMERATE 60
//#define STREAM_BITRATE 400000
#define STREAM_BITRATE 4000000

#include "ofMain.h"
#include "ofxPSMove.h"
#include "ofxStreamingSender.h"

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

    void update(ofEventArgs & args);

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

    ofxPSMove::Receiver psMoveReceiver;

    void onTrianglePressed( ofxPSMove::EventArgs & psmoveEvent );
    void onCirclePressed( ofxPSMove::EventArgs & psmoveEvent );
    void onCrossPressed( ofxPSMove::EventArgs & psmoveEvent );
    void onSquarePressed( ofxPSMove::EventArgs & psmoveEvent );
    void onSelectPressed( ofxPSMove::EventArgs & psmoveEvent );
    void onStartPressed( ofxPSMove::EventArgs & psmoveEvent );
    void onMovePressed( ofxPSMove::EventArgs & psmoveEvent );
    void onTPressed( ofxPSMove::EventArgs & psmoveEvent );
    void onPSPressed( ofxPSMove::EventArgs & psmoveEvent );

    void onTriangleReleased( ofxPSMove::EventArgs & psmoveEvent );
    void onCircleReleased( ofxPSMove::EventArgs & psmoveEvent );
    void onCrossReleased( ofxPSMove::EventArgs & psmoveEvent );
    void onSquareReleased( ofxPSMove::EventArgs & psmoveEvent );
    void onSelectReleased( ofxPSMove::EventArgs & psmoveEvent );
    void onStartReleased( ofxPSMove::EventArgs & psmoveEvent );
    void onMoveReleased( ofxPSMove::EventArgs & psmoveEvent );
    void onTReleased( ofxPSMove::EventArgs & psmoveEvent );
    void onPSReleased( ofxPSMove::EventArgs & psmoveEvent );

    void onTriggerUpdated( ofxPSMove::EventArgs & psmoveEvent );
    void onBatteryUpdated( ofxPSMove::EventArgs & psmoveEvent );
    void onTemperatureUpdated( ofxPSMove::EventArgs & psmoveEvent );

    void onAccelerometerUpdated( ofxPSMove::EventArgs & psmoveEvent );
    void onGyroscopeUpdated ( ofxPSMove::EventArgs & psmoveEvent );
    void onMagnetometerUpdated( ofxPSMove::EventArgs & psmoveEvent );
    void onPSMoved( ofxPSMove::EventArgs & psmoveEvent );


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

    ofxStreamingSender streamingSender;
    ofVideoGrabber grabber;
};