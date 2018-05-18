
//VIDEOPASILLOTUPPER

#include "ofxStage15.h"

ofxStage15::ofxStage15() {

	chStage = VIDEOPASILLOTUPPER;
}

int ofxStage15::nextStage() {
	chStage = TUPPERMICROCERRADO;

	return chStage;
}

int ofxStage15::mousePressed(int x, int y) {
	return chStage;
}

int ofxStage15::keyPressed(int key, int currentStage) {

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
