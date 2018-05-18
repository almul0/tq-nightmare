
//MENU

#include "ofxMenu.h"

ofxMenu::ofxMenu() {
	chStage = MENU;

	obj1.set(764, 136); //Tarjeta
}

int ofxMenu::mousePressed(int x, int y) {

	if (((x > obj1.x - 60) && (x < obj1.x + 60)) && ((y < obj1.y + 40) && (y > obj1.y - 40))) { //Tarjeta
		if (win) {
			chStage = VIDEOVICTORIA;
		}
	}
	else {
		chStage = MENU;
	}

	return chStage;
}

int ofxMenu::keyPressed(int key, int currentStage) {

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
