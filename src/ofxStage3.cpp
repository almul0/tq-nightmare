
#include "ofxStage3.h"

//MANGUERA

ofxStage3::ofxStage3() {
	obj1.set(294, 325); //Tarjeta

	chStage = MANGUERA;
}

int ofxStage3::mousePressed(int x, int y)
{
	if (((x > obj1.x - 12) && (x < obj1.x + 12)) && ((y < obj1.y + 8) && (y > obj1.y - 8))) { //Tarjeta
		chStage = MANGUERASINTARJETA;

		objectsCatched[TARJETA] = true;
		
	} else {
		chStage = MANGUERA;
	}

	return chStage;
}

int ofxStage3::keyPressed(int key, int currentStage) {

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
