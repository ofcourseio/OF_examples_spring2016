#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSoundStreamSetup(2, 0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

void ofApp::audioOut(ofSoundBuffer& out){
    out.fillWithTone(ofMap(ofGetMouseY(), 0, ofGetWidth(), 20, 20000));
    float m = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0,1);
    out.stereoPan(1-m, m);
}