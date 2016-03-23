#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    for (int i = 0; i < 100; i++){
        ofPoint randomPos;
        randomPos.set(ofGetWidth()/2, ofGetHeight()/2);
        pos.push_back(randomPos);
        
        ofPoint randomVel;
        randomVel.set(cos(i*0.01)*4.0, sin(i*0.2)*4.0);
        vel.push_back(randomVel);
        
        radius.push_back(ofRandom(10,11));
    }
    
    ofSetColor(255,0,100);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < pos.size(); i++){
        pos[i] += vel[i];
        
        if (pos[i].x + radius[i] > ofGetWidth() || pos[i].x - radius[i] < 0) {
            vel[i].x *= -1;
        }
        
        if (pos[i].y + radius[i] > ofGetHeight() || pos[i].y - radius[i] < 0) {
            vel[i].y *= -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < pos.size(); i++){
        ofColor col;
        col.setHsb(ofMap(i, 0, pos.size(), 0, 255), 200, 200);
        ofSetColor(col);
        ofCircle(pos[i], radius[i]);
    }
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
