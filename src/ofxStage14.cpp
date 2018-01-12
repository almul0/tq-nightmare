
//FINJUEGO

#include "ofxStage14.h"

ofxStage14::ofxStage14() {

	chStage = FINJUEGO;
}

int ofxStage14::mousePressed(int x, int y) {

	chStage = FINJUEGO;

	return chStage;
}

int ofxStage14::keyPressed(int key, int currentStage) {

	chStage = currentStage; //Guardamos en que escena estamos

	return chStage;
}

