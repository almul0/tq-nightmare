//LECTOR

#include "ofxStage2.h"

ofxStage2::ofxStage2() {
	obj1.set(224, 277); //Selecci�n
	obj2.set(310, 261); //5
	obj3.set(258, 259); //2
	obj4.set(293, 259); //4
	obj5.set(286, 269); //botones

	button.load("boton.ogg");
	buttonCorrect.load("correcto.ogg");
	buttonIncorrect.load("incorrecto.ogg");
	
	chStage = LECTOR;
}

int ofxStage2::mousePressed(int x, int y) {
	if (((x > obj1.x - 11) && (x < obj1.x + 11)) && ((y < obj1.y + 11) && (y > obj1.y - 11))) { //Selecci�n
		if (objectsCatched[PAPEL] && key == 3) {
			buttonCorrect.play();

			chStage = VIDEOESCALERAS;
		} else {
			buttonIncorrect.play();

			chStage = LECTOR;
			key = 0;
		}

	}
	else if (((x > obj2.x - 7) && (x < obj2.x + 7)) && ((y < obj2.y + 7) && (y > obj2.y - 7))) { //5
		if (key == 0) {
			key++;
		}
		else {
			key = 0;
		}
		chStage = LECTOR;

		button.play();
	}
	else if (((x > obj3.x - 7) && (x < obj3.x + 7)) && ((y < obj3.y + 7) && (y > obj3.y - 7))) { //2
		if (key == 1) {
			key++;
		}
		else {
			key = 0;
		}
		chStage = LECTOR;

		button.play();
	}
	else if (((x > obj4.x - 7) && (x < obj4.x + 7)) && ((y < obj4.y + 7) && (y > obj4.y - 7))) { //4
		if (key == 2) {
			key++;
		}
		else {
			key = 0;
		}
		chStage = LECTOR;

		button.play();
	} else if (((x > obj5.x - 71) && (x < obj5.x + 71)) && ((y < obj5.y + 21) && (y > obj5.y - 21))) {
		button.play();
	}
	else {
		chStage = LECTOR;
		key = 0;
	}

	return chStage;

}

int ofxStage2::keyPressed(int key, int currentStage) {

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
	else if (key == 'p'){
		chStage = PASILLO1;
	}

	return chStage;
}
