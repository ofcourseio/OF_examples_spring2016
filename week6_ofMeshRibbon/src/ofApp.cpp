#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    bDrawing = true;
    cam.disableMouseInput();
}
//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofSetColor(255);
    mesh.draw();
    ofSetColor(0);
    mesh.drawWireframe();
    cam.end();
    ofDrawBitmapString("Draw mode: " +
                       (string)(bDrawing?" ON":" OFF"), 100, 100);
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == ' ') {
        bDrawing = ! bDrawing;
        if (bDrawing) {
            cam.disableMouseInput();
        }else{
            cam.enableMouseInput();
        }
    }
}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if (bDrawing) {
        for (int i =0 ; i < mesh.getNumVertices(); i++) {
            mesh.getVertices()[i].z -= 40;
        }
        //ofVec3f is exactly the same as ofPoint
        ofPoint mousePoint(x-ofGetWidth()/2,-(y-ofGetHeight()/2));
        ofVec3f offsetPoint(50,0);
        mesh.addVertex(mousePoint + offsetPoint);
        mesh.addVertex(mousePoint - offsetPoint);
    }
}