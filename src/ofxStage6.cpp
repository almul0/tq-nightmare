
//TUPPERMICROCERRADO

#include "ofxStage6.h"

ofxStage6::ofxStage6() {
	obj1.set(291, 266); //Puerta
	obj2.set(1095, 242); //Micro

	chStage = TUPPERMICROCERRADO;
}

int ofxStage6::mousePressed(int x, int y) {
	if (((x > obj1.x - 60) && (x < obj1.x + 60)) && ((y < obj1.y + 186) && (y > obj1.y - 186))) { //Puerta

		if (visited) {
			chStage = PASILLO2;
		}
		else {
			chStage = VIDEOTUPPERPASILLO;
		}
		
	} else if (((x > obj2.x - 41) && (x < obj2.x + 41)) && ((y < obj2.y + 16) && (y > obj2.y - 16))) { //Micro

		chStage = MICROCERRADO;
	} else {

		chStage = TUPPERMICROCERRADO;
	}

	return chStage;
}

int ofxStage6::keyPressed(int key, int currentStage) {

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

