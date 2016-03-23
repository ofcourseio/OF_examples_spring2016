#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetConeResolution(4,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofPoint c (sin(ofGetElapsedTimef()*0.001)*1000,0,0);
    cam.rotateAround( 0.05, ofPoint(0,1,0), c);
    cam.lookAt(c);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(ofColor(50), ofColor(0));
    
    cam.begin();
    
    ofSeedRandom(100);
    ofEnableDepthTest();
    ofNoFill();
    
    for (int i = 0; i < 1000; i++) {
        ofSetLineWidth(5);
        ofPoint p (ofRandom(-ofGetWidth()*2,ofGetWidth()*2),ofGetHeight(),ofRandom(-10000, 10000));
        
        ofSetColor(ofRandom(100,255),ofRandom(100,255),ofRandom(100,255), (sin(ofGetElapsedTimef()*ofRandom(4) + ofRandom(PI)) +1)*127 );
    
        ofDrawBox(p, ofRandom(100,300), ofRandom(100,2000), ofRandom(100,200));
    }
    cam.end();
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
