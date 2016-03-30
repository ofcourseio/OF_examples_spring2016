#include "ofApp.h"

//-------------------------------------------------------------
void ofApp::setup(){

    ofFileDialogResult  result = ofSystemLoadDialog();
    if (result.bSuccess) {
        player.load(result.getPath());
        player.play();
    }
}

//-------------------------------------------------------------
void ofApp::draw(){

    int numBands = 5;
    float * spectrum = ofSoundGetSpectrum(numBands);
    
    float xInc = ofGetWidth()/numBands;
    ofColor color;
    for(int i = 0; i < numBands; i++){
        color.setHsb(ofMap(i, 0, numBands-1, 0, 255), 255, 255);
        ofSetColor(color);
        ofDrawRectangle(i*xInc, ofGetHeight(), xInc, - spectrum[i]* ofGetHeight());
    }
    
    
}
