#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    hihatClosed.load("hihatClosed.wav");
    hihatFoot.load("hihatFoot.wav");
    kick.load("kick.wav");
    ride.load("ride.wav");
    snare.load("snare.wav");

    hihatClosed.setMultiPlay(true);
    hihatFoot.setMultiPlay(true);
    kick.setMultiPlay(true);
    ride.setMultiPlay(true);
    snare.setMultiPlay(true);
    currentColor = ofColor::black;
}

//----------------------------------------------------
void ofApp::update(){}
//---------------------------------------------------
void ofApp::draw(){
    ofBackground(currentColor);
}
//----------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        kick.play();
        currentColor = ofColor::red;
    }
    if (key == 'p') {
        ride.play();
        currentColor = ofColor::yellow;
    }
    if (key == 'u') {
        snare.play();
        currentColor = ofColor::violet;
    }
    if (key == 'w') {
        hihatClosed.play();
        currentColor = ofColor::blue;
    }
    if (key == 'q') {
        hihatFoot.play();
        currentColor = ofColor::cyan;
    }
}

//---------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
