
//TUPPERMICROABIERTOSINPAPEL

#include "ofxStage10.h"

ofxStage10::ofxStage10() {
	obj1.set(291, 266); //Puerta
	obj2.set(1092, 245); //Micro abierto sin papel

	chStage = TUPPERMICROABIERTOSINPAPEL;
}

int ofxStage10::mousePressed(int x, int y) {
	if (((x > obj1.x - 60) && (x < obj1.x + 60)) && ((y < obj1.y + 186) && (y > obj1.y - 186))) { //Puerta

		if (visited) {
			chStage = PASILLO2;
		}
		else {
			chStage = VIDEOTUPPERPASILLO;
		}
	}
	else if (((x > obj2.x - 40) && (x < obj2.x + 40)) && ((y < obj2.y + 20) && (y > obj2.y - 20))) { //Micro abierto sin papel

		chStage = MICROABIERTOSINPAPEL;
	}
	else {

		chStage = TUPPERMICROABIERTOSINPAPEL;
	}

	return chStage;
}

int ofxStage10::keyPressed(int key, int currentStage) {

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

