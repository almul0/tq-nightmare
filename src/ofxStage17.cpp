
//VIDEOESCALERAS

#include "ofxStage17.h"

ofxStage17::ofxStage17() {

	chStage = VIDEOESCALERAS;
}

int ofxStage17::nextStage() {

	chStage = FINAL;

	return chStage;
}

int ofxStage17::mousePressed(int x, int y) {

	chStage = VIDEOESCALERAS;

	return chStage;
}

int ofxStage17::keyPressed(int key, int currentStage) {

	chStage = currentStage; //Guardamos en que escena estamos

	if (key == 'm') {

		if (menuOn) {
			chStage = prevStage; //Si salimos del menu, volvemos al escenario previo
			ofLog() << "(m)Actual stage: " << chStage;
			menuOn = false;
		}
		else {
			prevStage = currentStage; //Si entramos al menu, guardamos el escenario actual para poder volver a él
			ofLog() << "(m)Previous stage: " << prevStage;

			chStage = MENU;
			menuOn = true;
		}
	}

	return chStage;
}
