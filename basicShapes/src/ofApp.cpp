#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::limeGreen, ofColor::yellow);
    ofFill();
    ofSetColor(ofColor::salmon);
    //x of topleft corner, y of topleft corner, width, height
    ofDrawRectangle(200, 234, 150, 100);
    ofSetColor(ofColor::pink);
    //x and y of the center, radius
    ofDrawCircle(512, 284, 50);
    
    ofSetColor(ofColor::tomato);
    //x1,y1,x2,y2,x3,y3
    ofDrawTriangle(700, 234, 750, 314, 650, 314);
    
    //x1,y1,x2,y2
    
    ofSetColor(220);
    
    ofDrawLine(200, 384, 750, 384);
    
    ofSetLineWidth(2);
    //stroke only
    ofNoFill();
    ofDrawRectangle(200, 434, 150, 100);
    ofSetLineWidth(5);
    ofDrawCircle(512, 484, 50);
    ofSetLineWidth(8);
    ofDrawTriangle(700, 434, 750, 514, 650, 514);
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
