#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    img.load("tdf_1972_poster.jpg");
    fbo.allocate(img.getWidth(), img.getHeight());//create and set size
    fbo.begin();
    ofClear(255, 0);
    fbo.end();
}
void ofApp::update(){}
//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    img.draw(0,0);
    
    if(mouseX >=0 && mouseY >= 0 && mouseX < img.getWidth() && mouseY < img.getHeight()){
        ofColor color = img.getColor(mouseX , mouseY);
        ofSetColor(color);
       if(ofGetMousePressed(2)){
            w = ofMap(mouseY, 0, ofGetWidth(), 1, 200);
        }
        else if(ofGetMousePressed(0)){
            fbo.begin();  // new line
            ofSetColor(img.getColor(mouseX, mouseY));  // new line
            ofSetLineWidth(w);
            ofDrawLine(mouseX, mouseY, ofGetPreviousMouseX(), ofGetPreviousMouseY());
            //ofDrawCircle(mouseX, mouseY, w); // new line
            
            fbo.end(); // new line

        }
    }
    ofSetColor(255); // new line
    fbo.draw(0,0);  // new line

}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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
