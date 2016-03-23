#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
}

//--------------------------------------------------------------
void ofApp::update(){
    float t = ofGetElapsedTimef();
    ofPoint pt;
    pt.x = ofSignedNoise(t * 2) * 100;
    pt.y = ofSignedNoise(t * 3.1) * 100;
    pt.z = 0;
    
    pts.push_back(pt);
    
    for (int i = 0; i < pts.size(); i++){
        pts[i].z+=4;
    }
    
    mesh.clear();
    mesh.addVertices(pts);
}

//--------------------------------------------------------------
void ofApp::draw(){

    cam.begin();
    mesh.draw();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
