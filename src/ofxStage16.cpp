//VIDEOPASILLOTUPPER

#include "ofxStage16.h"

ofxStage16::ofxStage16() {

	chStage = VIDEOTUPPERPASILLO;
}

int ofxStage16::nextStage() {

	chStage = PASILLO2;
	visited = true;

	return chStage;
}

int ofxStage16::mousePressed(int x, int y) {

	chStage = VIDEOTUPPERPASILLO;

	return chStage;
}

int ofxStage16::keyPressed(int key, int currentStage) {

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
