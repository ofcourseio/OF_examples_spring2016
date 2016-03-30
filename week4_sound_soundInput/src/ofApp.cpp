#include "ofApp.h"

//-----------------------------------------------------------
void ofApp::setup(){
    bSampling = true;
    ofSoundStreamSetup(0, 2);
    smoothVolume = 0;
}
//------------------------------------------------------------
void ofApp::update(){}
//------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetLineWidth(3);
    ofSetColor(255);
    float volume = 0;
    
    if(buffer.getNumFrames() > 0){
        float xIncrement = ofGetWidth()/buffer.getNumFrames();
        for(int i = 0; i < buffer.getNumFrames(); i++){
            float sample0 = buffer.getSample(i-1, 0);
            float sample1 = buffer.getSample(i, 0);
            ofDrawLine(i*xIncrement, sample0 *400 + ofGetWidth()/2, i *xIncrement, sample1 *400 + ofGetWidth()/2);
            volume += sample0 * sample0;
        }
        volume/= buffer.getNumFrames();//values go from 0 to 1
    }
   
    ofDrawRectangle(0, 0, volume * ofGetWidth(), 100);
    
    smoothVolume = (smoothVolume * 0.97 + volume)/2;
    ofDrawRectangle(0, 100, smoothVolume * ofGetWidth(), 100);
    
    
    
}
//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer & input){
    if(bSampling){
        buffer = input;
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        bSampling = !bSampling;
    }
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
