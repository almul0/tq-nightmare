
//MANGUERASINTARJETA

#include "ofxStage4.h"

ofxStage4::ofxStage4() {

	chStage = MANGUERASINTARJETA;
}

int ofxStage4::mousePressed(int x, int y) {
	
	chStage = MANGUERASINTARJETA;

	return chStage;
}

int ofxStage4::keyPressed(int key, int currentStage) {

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
	else if (key == 'p') {
		chStage = PASILLO1;
	}

	return chStage;
}

