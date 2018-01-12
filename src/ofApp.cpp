#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetLogLevel(LOGLEVEL);
	ofLogToConsole();

    grabber.initGrabber( WIDTH, HEIGHT);
    streamingSender.setup();
    streamingSender.setVideoEncoder("libx264", "ultrafast", AV_PIX_FMT_RGB24, AV_PIX_FMT_YUV420P, WIDTH, HEIGHT, STREAM_FRAMERATE, STREAM_BITRATE);
    //streamingSender.start("udp://127.0.0.1:1234");
    streamingSender.start("udp://239.0.1.23:1234");

    psMoveReceiver.setup();
    ofxAddPSMoveListeners(this);

	//Musica ambiente
	ambient.load("musicaAmbiente.ogg");
	ambient.setLoop(true);
	ambient.play();

	//Cargar las imagenes
	lantern.load("reveal.png");

	arrayImageStage[MENU].load("menu.jpg");
	arrayImageStage[PASILLO1].load("pasillo1.jpg");
	arrayImageStage[LECTOR].load("lector.jpg");
	arrayImageStage[MANGUERA].load("mangueraConTarjeta.jpg");
	arrayImageStage[MANGUERASINTARJETA].load("mangueraSinTarjeta.jpg");
	arrayImageStage[PASILLO2].load("pasillo2.jpg");
	arrayImageStage[TUPPERMICROCERRADO].load("tupperCerrado.jpg");
	arrayImageStage[MICROCERRADO].load("microCerrado.jpg");
	arrayImageStage[TUPPERMICROABIERTOCONPAPEL].load("tupperAbiertoConPapel.jpg");
	arrayImageStage[MICROABIERTOCONPAPEL].load("microAbiertoConPapel.jpg");
	arrayImageStage[TUPPERMICROABIERTOSINPAPEL].load("tupperAbiertoSinPapel.jpg");
	arrayImageStage[MICROABIERTOSINPAPEL].load("microAbiertoSinPapel.jpg");
	arrayImageStage[FINAL].load("puertaFinal.jpg");
	arrayImageStage[LECTORFINAL].load("lectorFinal.jpg");
	arrayImageStage[FINJUEGO].load("fin.jpg");

	arrayImageObjects[TARJETA].load("tarjeta.jpg");
	arrayImageObjects[PAPEL].load("papel.jpg");

	arrayVideo[0].load("videoPasilloTupper.mp4");
	arrayVideo[1].load("videoTupperPasillo.mp4");
	arrayVideo[2].load("videoEscaleras.mp4");
	arrayVideo[3].load("victoria.mp4");
	arrayVideo[4].load("susto.mp4");

	arrayVideo[0].setLoopState(OF_LOOP_NONE);
	arrayVideo[1].setLoopState(OF_LOOP_NONE);
	arrayVideo[2].setLoopState(OF_LOOP_NONE);
	arrayVideo[3].setLoopState(OF_LOOP_NORMAL);
	arrayVideo[4].setLoopState(OF_LOOP_NONE);

	currentStage = PASILLO1;

	arrayStage.push_back(shared_ptr<ofxStage>(new ofxMenu));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage1));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage2));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage3));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage4));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage5));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage6));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage7));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage8));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage9));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage10));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage11));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage12));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage13));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage14));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage15));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage16));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage17));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage18));
	arrayStage.push_back(shared_ptr<ofxStage>(new ofxStage19));
}

void ofApp::update() {
	if (currentStage > 14) {
		arrayVideo[currentStage-15].update();
	}
    grabber.update();
    if(grabber.isFrameNew()){
        streamingSender.sendVideoFrame(grabber.getPixels().getData());
    }
}

void ofApp::update(ofEventArgs & args) {
    psMoveReceiver.update(args);
    update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	int w1 = ofGetWidth(); //Anchura de la ventana de la aplicacion
	int h1 = ofGetHeight(); //Altura de la ventana de la aplicacion

	if (currentStage < 15) {
		int w0 = arrayImageStage[currentStage].getWidth();
		int h0 = arrayImageStage[currentStage].getHeight();

		//Evitamos pintar sombra en el menu
		if (currentStage != MENU) {
			ofEnableAlphaBlending();
			ofSetColor(255);

			arrayImageStage[currentStage].draw(max(0, (w1 - w0) / 2), max(0, (h1 - h0) / 2), w0, h0);

			lantern.draw(cursor.x - (lantern.getWidth() / 2), cursor.y - (lantern.getHeight() / 2));

			ofDisableAlphaBlending();
		}
		else {
			arrayImageStage[currentStage].draw(max(0, (w1 - w0) / 2), max(0, (h1 - h0) / 2), w0, h0);
		}

		//Pintamos los objetos en el menu
		int width;
		int height;

		if (currentStage == MENU) {
			for (int i = 0; i < numObjects; i++) {
				if (objectsCatched[i]) {
					width = arrayImageObjects[i].getWidth();
					height = arrayImageObjects[i].getHeight();
					arrayImageObjects[i].draw(705, (i+1)*106, width, height);
				}
			}
		}
	}
	else {		
		int w0 = arrayVideo[currentStage - 15].getWidth();
		int h0 = arrayVideo[currentStage - 15].getHeight();

		float videoLength = arrayVideo[currentStage - 15].getDuration();
		float videoElapsedTime = arrayVideo[currentStage - 15].getPosition()*arrayVideo[currentStage - 15].getDuration();
		float videoTimeRemaining = videoLength - videoElapsedTime;
		bool started = false;

		if (!started) {
			arrayVideo[currentStage - 15].play();
			started = true;
		}
		if (videoTimeRemaining > 0.1) { //Nos comemos un poquitin de video, pero poquisimo

			ofEnableAlphaBlending();
			ofSetColor(255);

			if (currentStage == VIDEOPASILLOTUPPER) {
				arrayVideo[currentStage - 15].draw(1280, 0, w0, h0);
			} else if ((currentStage == VIDEOESCALERAS) || (currentStage == VIDEOTUPPERPASILLO)) {
				arrayVideo[currentStage - 15].draw(0, 0, w0, h0);
			}
			else {
				arrayVideo[currentStage - 15].draw(max(0, (w1 - w0) / 2), max(0, (h1 - h0) / 2), w0, h0);
			}

			lantern.draw(cursor.x - (lantern.getWidth() / 2), cursor.y - (lantern.getHeight() / 2));
			ofDisableAlphaBlending();

		} else {
			currentStage = arrayStage[currentStage].get()->nextStage();
			started = false;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	currentStage = arrayStage[currentStage].get()->keyPressed(key, currentStage);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	ofLog(OF_LOG_VERBOSE, "mouseMoved x: %d, y: %d", x, y);
	cursor.x = x;
	cursor.y = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	currentStage = arrayStage[currentStage].get()->mousePressed(x, y);
	ofLog() << "(Mouse)Actual stage: " << currentStage;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::onAccelerometerUpdated( ofxPSMove::EventArgs & psmoveEvent )
{
}
void ofApp::onGyroscopeUpdated ( ofxPSMove::EventArgs & psmoveEvent )
{

}
void ofApp::onMagnetometerUpdated( ofxPSMove::EventArgs & psmoveEvent )
{

}
void ofApp::onTrianglePressed( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Triangle pressed");
}
void ofApp::onCirclePressed( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Circle pressed");
}
void ofApp::onCrossPressed( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Cross pressed");
}
void ofApp::onSquarePressed( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Square pressed");
}
void ofApp::onSelectPressed( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Select pressed");
}
void ofApp::onStartPressed( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Start pressed");
}
void ofApp::onMovePressed( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Move pressed");
}
void ofApp::onTPressed( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("T pressed");
}
void ofApp::onPSPressed( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("PS pressed");
}

void ofApp::onTriangleReleased( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Triangle released");
}
void ofApp::onCircleReleased( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Circle released");
}
void ofApp::onCrossReleased( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Cross released");
}
void ofApp::onSquareReleased( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Square released");
}
void ofApp::onSelectReleased( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Select released");
}
void ofApp::onStartReleased( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Trigger released");
}
void ofApp::onMoveReleased( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Move released");

}
void ofApp::onTReleased( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Trigger Released");

}
void ofApp::onPSReleased( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("PS Released");
}

void ofApp::onTriggerUpdated( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Trigger updated: %d", psmoveEvent.data->TRIGGER);
}
void ofApp::onBatteryUpdated( ofxPSMove::EventArgs & psmoveEvent )
{
    ofLogNotice() << printf("Battery updated: %d\n", psmoveEvent.data->battery);
}
void ofApp::onTemperatureUpdated( ofxPSMove::EventArgs & psmoveEvent )
{
    //ofLogNotice() << printf("Temperature updated: %d", psmoveEvent.data->temperature) ;
}

void ofApp::onPSMoved( ofxPSMove::EventArgs & psmoveEvent )
{
    /*ofLogNotice() << printf("PS Moved: (%.2f,%.2f,%.2f)",psmoveEvent.data->position.x,
                            psmoveEvent.data->position.y,
                            psmoveEvent.data->position.z);*/

    cursor.x = psmoveEvent.data->position.x;
    cursor.y = psmoveEvent.data->position.y;
}