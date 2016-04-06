#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofFileDialogResult res = ofSystemLoadDialog();
    if(res.bSuccess){
        img.load(res.getPath());
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    img.draw(0, 0);
    
    
    
    if(mouseX >= 0 && mouseY >= 0){
        if (mouseX < img.getWidth() && mouseY < img.getHeight()) {
            ofColor pixColor = img.getColor(mouseX, mouseY);
            
            ofSetColor(pixColor);
            ofDrawRectangle(0, 0, 100, 100);
            
        }
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
