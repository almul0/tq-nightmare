
//FINAL

#include "ofxStage12.h"

ofxStage12::ofxStage12() {
	obj1.set(810, 195); //Lector tarjeta final

	chStage = FINAL;
}

int ofxStage12::mousePressed(int x, int y) { //Lector tarjeta final
	if (((x > obj1.x - 10) && (x < obj1.x + 10)) && ((y < obj1.y + 12) && (y > obj1.y - 12))) {
		chStage = LECTORFINAL;
		
	} else {
		chStage = FINAL;
	}

	return chStage;
}

int ofxStage12::keyPressed(int key, int currentStage) {

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
	}

	return chStage;
}
