
//MICROABIERTOCONPAPEL

#include "ofxStage9.h"

ofxStage9::ofxStage9() {
	obj1.set(969, 279); //Coger papel

	chStage = MICROABIERTOCONPAPEL;
}

int ofxStage9::mousePressed(int x, int y) { //Coger papel
	if (((x > obj1.x - 34) && (x < obj1.x + 34)) && ((y < obj1.y + 9) && (y > obj1.y - 9))) { //Abrir micro

		objectsCatched[PAPEL] = true;
		chStage = MICROABIERTOSINPAPEL;

	}
	else {
		chStage = MICROABIERTOCONPAPEL;
	}

	return chStage;
}

int ofxStage9::keyPressed(int key, int currentStage) {

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
		chStage = TUPPERMICROABIERTOCONPAPEL;
	}

	return chStage;
}

