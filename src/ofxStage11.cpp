//MICROABIERTOSINPAPEL

#include "ofxStage11.h"

ofxStage11::ofxStage11() {

	chStage = MICROABIERTOSINPAPEL;
}

int ofxStage11::mousePressed(int x, int y) { 

	chStage = MICROABIERTOSINPAPEL;

	return chStage;
}

int ofxStage11::keyPressed(int key, int currentStage) {

	chStage = currentStage; //Guardamos en que escena estamos

	if (key == 'm') {

		if (menuOn) {
			chStage = prevStage; //Si salimos del menu, volvemos al escenario previo
			ofLog() << "(m)Actual stage: " << chStage;
			menuOn = false;
		} else {
			prevStage = currentStage; //Si entramos al menu, guardamos el escenario actual para poder volver a él
			ofLog() << "(m)Previous stage: " << prevStage;

			chStage = MENU;
			menuOn = true;
		}
	} else if (key == 'p') {
		chStage = TUPPERMICROABIERTOSINPAPEL;
	}

	return chStage;
}

