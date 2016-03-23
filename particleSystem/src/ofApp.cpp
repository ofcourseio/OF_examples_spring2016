#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    lastMouseX = mouseX;
    lastMouseY = mouseY;
}


//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < particleSystem.size(); i++){
        particleSystem[i].update();
    }
    
    //erase particles that have stopped moving
    for (int i = particleSystem.size()-1; i >= 0; i--){
        if (particleSystem[i].vel.length() < 1) {
            particleSystem.erase(particleSystem.begin()+i);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < particleSystem.size(); i++){
        particleSystem[i].draw();
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
    //add a new particle at the position of the mouse. Calculate the velocity based on the the last postion of the mouse.
    particle newParticle;
    newParticle.pos.set(x, y);
    newParticle.vel.set(x - lastMouseX, y - lastMouseY);
    newParticle.radius = ofRandom(3, 7);
    newParticle.col.set(ofRandom(200,255), ofRandom(200,255), ofRandom(200,255));
    
    particleSystem.push_back(newParticle);
    
    lastMouseX = x;
    lastMouseY = y;
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
