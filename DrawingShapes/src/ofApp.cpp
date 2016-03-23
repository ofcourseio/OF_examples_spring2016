#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    seed = 100;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofDrawRectangle(100,100,100,100);
    ofSeedRandom(seed);
    ofPoint p1(ofRandomWidth(), ofRandomHeight());
    ofPoint p2(ofRandomWidth(), ofRandomHeight());
    ofPoint p3(ofRandomWidth(), ofRandomHeight());

    ofSetColor(ofColor::pink);
    ofDrawTriangle(p1, p2, p3);
    ofSetColor(ofColor::sienna);
    cam.begin();
    
    ofDrawCylinder(200, 200, 0, 100, 300);
    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    seed ++;
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
