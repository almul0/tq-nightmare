
//PASILLO2

#include "ofxStage5.h"

ofxStage5::ofxStage5() {
	obj1.set(307, 234); //Final del pasillo
	obj2.set(1589, 249); //Puerta de ir hacia el tupper
	
	chStage = PASILLO2;
}

int ofxStage5::mousePressed(int x, int y) { 
	if (((x > obj1.x - 10) && (x < obj1.x + 10)) && ((y < obj1.y + 25) && (y > obj1.y - 25))) { //Final del pasillo
		chStage = PASILLO1;

	} else if (((x > obj2.x - 44) && (x < obj2.x + 44)) && ((y < obj2.y + 136) && (y > obj2.y - 136))){ //Puerta de ir hacia el tupper
		if (visited) {
			if (objectsCatched[PAPEL]) { //Hemos cogido el papel
				chStage = TUPPERMICROABIERTOSINPAPEL;
			} else if (microOpen) { //Si abrimos y no cogemos papel
				chStage = TUPPERMICROABIERTOCONPAPEL;
			}
			else {
				chStage = TUPPERMICROCERRADO;
			}
		} else {
			chStage = VIDEOPASILLOTUPPER;
		}
	} else {
		chStage = PASILLO2;
	}

	return chStage;
}

int ofxStage5::keyPressed(int key, int currentStage) {

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

