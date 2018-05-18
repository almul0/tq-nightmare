
//MICROCERRADO

#include "ofxStage7.h"

ofxStage7::ofxStage7() {
	obj1.set(1000, 240); //Abrir micro

	chStage = MICROCERRADO;
}

int ofxStage7::mousePressed(int x, int y) {
	if (((x > obj1.x - 133) && (x < obj1.x + 133)) && ((y < obj1.y + 108) && (y > obj1.y - 108))) { //Abrir micro

		chStage = MICROABIERTOCONPAPEL;

	} else {
		chStage = MICROCERRADO;
	}

	return chStage;
}

int ofxStage7::keyPressed(int key, int currentStage) {

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
		chStage = TUPPERMICROCERRADO;
	}

	return chStage;
}

