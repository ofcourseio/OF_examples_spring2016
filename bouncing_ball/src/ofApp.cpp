#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    pos.set(ofGetWidth()/2, ofGetHeight()/2);
    vel.set(2.0, 3.0);
    radius = 25;
    
    ofSetColor(255,0,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    pos += vel;
    
    if (pos.x > ofGetWidth() || pos.x < 0) {
        vel.x *= -1;
    }
    
    if (pos.y > ofGetHeight() || pos.y < 0) {
        vel.y *= -1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofCircle(pos, radius);
}

//--------------------------------------------------------------
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
