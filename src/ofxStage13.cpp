
//LECTORFINAL

#include "ofxStage13.h"

ofxStage13::ofxStage13() {
	obj1.set(918, 215); //Poner tarjeta

	chStage = LECTORFINAL;
}

int ofxStage13::mousePressed(int x, int y) {
	if (((x > obj1.x - 92) && (x < obj1.x + 92)) && ((y < obj1.y + 113) && (y > obj1.y - 113))) { //Poner tarjeta

		if (objectsCatched[TARJETA]) {
			win = true;
			chStage = MENU;
		} else {
			chStage = VIDEOMUERTE;
		}
		
	} else {
		chStage = LECTORFINAL;
	}

	return chStage;
}

int ofxStage13::keyPressed(int key, int currentStage) {

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
		chStage = FINAL;
	}

	return chStage;
}
