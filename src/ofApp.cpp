#include "ofApp.h"
#include "ofLog.h"

//--------------------------------------------------------------
void ofApp::setup(){
    left.load("./assets/left.jpg");
    front.load("./assets/front.jpg");
    right.load("./assets/right.jpg");
    lantern.load("./assets/reveal.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    ofSetColor(255);
    left.draw(0, 0);
    front.draw(1024, 0);
    right.draw(2048,0);
    lantern.draw(cursor.x-(lantern.getWidth()/2),cursor.y-(lantern.getHeight()/2));
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    cursor.x =x;
    cursor.y=y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
}
