#include "ofApp.h"

//--------------------------------------------------
void ofApp::setup(){
    seed = 100;
}
//--------------------------------------------------
void ofApp::update(){}
// examples https://github.com/ofcourseio/OF_examples_spring2016
//--------------------------------------------------
void ofApp::draw(){

    ofDrawRectangle(100,100,100,100);
    
    ofSetColor(100);
    //ofSeedRandom(seed);

    ofPoint p1(ofRandomWidth(), ofRandomHeight());
    ofPoint p2(ofRandomWidth(), ofRandomHeight());
    ofPoint p3(ofRandomWidth(), ofRandomHeight());

    ofSetColor(ofColor::yellow);
    
    ofDrawTriangle(p1, p2, p3);
    
    ofSetColor(ofColor::sienna);
    ofSetColor(200,0,0);//red
    cam.begin();
    
   
    ofEnableDepthTest();
    

    ofSetCylinderResolution(ofMap(ofGetMouseX(), 0,ofGetWidth(), 1, 100),ofMap(ofGetMouseY(), 0,ofGetHeight(), 1, 100));

    ofFill();
    ofSetColor(200,0,120);
    ofDrawCylinder(200, 200, 0, 100, 300);
    
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(2);
    ofDrawCylinder(200, 200, 0, 100, 300);
    ofDrawRectRounded(5675, 789, 789, 789, 789);
    ofSetConeResolution(4,0);
    
    ofDrawCone(0, 0, 0, 100, 200);
    ofDrawCone(0, 200, 0, 100, -200);
    
    cam.end();
    

}
//--------------------------------------------------
void ofApp::keyPressed(int key){
    seed ++;
}
//--------------------------------------------------
void ofApp::keyReleased(int key){}
//--------------------------------------------------
void ofApp::mouseMoved(int x, int y ){}
//--------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){}
//--------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){}
//--------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){}

//--------------------------------------------------
void ofApp::mouseEntered(int x, int y){}

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
