//PASILLO1

#include "ofxStage1.h"

ofxStage1::ofxStage1() {
	obj1.set(390, 240); //Lector tarjetas
	obj2.set(500, 270); //Manguera
	obj3.set(1598, 257); //Final pasillo

	laught.load("risamujer.ogg");

	laughtPlayed = false;

	chStage = PASILLO1;
}

int ofxStage1::mousePressed(int x, int y) {
	if (((x > obj1.x - 17) && (x < obj1.x + 17)) && ((y < obj1.y + 9) && (y > obj1.y - 9))) { //Lector
		
		chStage = LECTOR;
		
	} else if (((x > obj2.x - 45) && (x < obj2.x + 45)) && ((y < obj2.y + 60) && (y > obj2.y - 60))) { //Manguera

		if (objectsCatched[TARJETA]) {
			chStage = MANGUERASINTARJETA;
		} else {
			chStage = MANGUERA;
		}
		
	} else if (((x > obj3.x - 11) && (x < obj3.x + 11)) && ((y < obj3.y + 27) && (y > obj3.y - 27))) { //Final pasillo
		if (!laughtPlayed) {
			laught.play();
			laughtPlayed = true;
		}

		chStage = PASILLO2;
	} else {
		chStage = PASILLO1;
	}

	return chStage;
}

int ofxStage1::keyPressed(int key, int currentStage) {

	chStage = currentStage; //Guardamos en que escena estamos

	if (key == 'm') {

		if (menuOn) {
			chStage = prevStage; //Si salimos del menu, volvemos al escenario previo
			ofLog() << "(m)Actual stage: " << chStage;
			menuOn = false;
		}
		else {
			prevStage = currentStage; //Si entramos al menu, guardamos el escenario actual para poder volver a �l
			ofLog() << "(m)Previous stage: " << prevStage;

			chStage = MENU;
			menuOn = true;
		}
	}

	return chStage;
}
