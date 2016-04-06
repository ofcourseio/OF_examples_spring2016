#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    img.load("tdf_1972_poster.jpg");
}
void ofApp::update(){}
//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    img.draw(0,0);
    
    if(mouseX >=0 && mouseY >= 0 && mouseX < img.getWidth() && mouseY < img.getHeight()){
    ofColor color = img.getColor(mouseX , mouseY);
    
    ofSetColor(color);
    
    ofDrawRectangle(0, 0, 100, 100);
        string msg ="R: " + ofToString((int)color.r)+"\n";
        msg +="G: " + ofToString((int)color.g)+"\n";
        msg +="B: " + ofToString((int)color.b)+"\n";
        msg +="X: " + ofToString(mouseX)+"\n";
        msg +="Y: " + ofToString(mouseY)+"\n";
        ofSetColor(255);
        ofDrawBitmapStringHighlight(msg , 10,120, clicColor,ofColor::blue);
    }
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if(mouseX < img.getWidth() && mouseY < img.getHeight()){
        clicColor = img.getColor(mouseX , mouseY);
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
