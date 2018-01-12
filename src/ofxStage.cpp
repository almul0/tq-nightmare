
#include "ofxStage.h"

//int chStage;
int prevStage;
bool menuOn = false;
bool objectsCatched[numObjects];
int key;
bool microOpen = false;
bool win = false;
bool visited = false;

int ofxStage::keyPressed(int key, int currentStage) {
	//Por si acaso, aunque si redefinimos la función en todos los escenarios no hace falta
		
	return 0;
}

int ofxStage::mousePressed(int x, int y) {

	return 0;
}

int ofxStage::nextStage() {//Nunca se va a ejecutar si no estas en un escenario que sea un video, y en esos se sobreescribe el método

	return 0;
}