#pragma once

#include "ofMain.h"
#include "ofxWiiMouse.h"

#define LOGLEVEL OF_LOG_VERBOSE


class ofApp : public ofxWiiMouseApp {

	public:
		void setup();
		void update();
		void draw();
        void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void wiiMouseConnect();
        void wiiMouseConnected(int connected, int found);
        void wiiMouseMoved(int x, int y);
        void wiiMouseDragged(int x, int y, int button);
        void wiiMousePressed(int x, int y, int button);
        void wiiMouseReleased(int x, int y, int button);
        void wiiMouseButtonHeld(int x, int y, int button);

        ofImage left;
        ofImage front;
        ofImage right;
        ofImage lantern;
        ofImage shadow;
        ofPoint cursor;

    private:
        ofxWiiMouse WiiMouse;
};
