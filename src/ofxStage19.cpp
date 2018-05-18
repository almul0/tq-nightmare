
//VIDEOMUERTE

#include "ofxStage19.h"

ofxStage19::ofxStage19() {

	chStage = VIDEOMUERTE;
}

int ofxStage19::nextStage() {

	chStage = FINJUEGO;

	return chStage;
}

int ofxStage19::mousePressed(int x, int y) {

	chStage = VIDEOMUERTE;

	return chStage;
}

int ofxStage19::keyPressed(int key, int currentStage) {

	chStage = currentStage; //Guardamos en que escena estamos

	return chStage;
}
