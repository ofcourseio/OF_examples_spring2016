#include "ofApp.h"

//-------------------------------------------------------------
void ofApp::setup(){
    ofBackground(30, 30, 30);
    
    kinectv1.setRegistration(true);
    kinectv1.init();// initialize. load
    kinectv1.open();// play
    
    kinectv1.setCameraTiltAngle(0);
}
//-------------------------------------------------------------
void ofApp::update(){
    kinectv1.update();
}
//-------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    kinectv1.draw(0,0);// rgb
    ofSetColor(255, ofMap(mouseX, 0, ofGetWidth(), 0, 255));
    kinectv1.drawDepth(0, 0);

}

//-------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
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
