#pragma once

#include "ofMain.h"
#include "stages.h"
#include "objects.h"

#define numObjects 2

extern int prevStage;
extern bool menuOn;
extern int key;
extern bool microOpen;
extern bool win;
extern bool visited;

extern bool objectsCatched[numObjects]; //Vector de booleanos que guarda los objetos que se han cogido ya

class ofxStage {
public:

	virtual int keyPressed(int key, int currentStage);
	virtual int mousePressed(int x, int y);
	virtual int nextStage();

};