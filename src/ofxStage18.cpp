
//VIDEOVICTORIA

#include "ofxStage18.h"

ofxStage18::ofxStage18() {

	chStage = VIDEOVICTORIA;
}

int ofxStage18::nextStage() {

	chStage = FINJUEGO;

	return chStage;
}

int ofxStage18::mousePressed(int x, int y) {

	chStage = VIDEOVICTORIA;

	return chStage;
}

int ofxStage18::keyPressed(int key, int currentStage) {

	chStage = currentStage; //Guardamos en que escena estamos

	return chStage;
}
