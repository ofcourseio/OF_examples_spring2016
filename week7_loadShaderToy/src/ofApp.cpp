#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    toy.allocate(1000, 600, GL_RGB);//set sizes
    snail.allocate(1000, 600, GL_RGB);
    toy.load("ocean");
    snail.load("shader");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    toy.update();
    snail.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(0, toy.getHeight());
    ofScale(1, -1);
    ofSetColor(255);
    toy.draw();
    ofSetColor(255, ofMap(mouseX, 0, ofGetWidth(), 0, 255));
    snail.draw();
    ofPopMatrix();
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
