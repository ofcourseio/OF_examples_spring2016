#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    gui.add(amplitude.set("amplitude", 100, 10, 1000));
    gui.add(xyScale.set("xyScale", 1, 0, 100));
    gui.add(speed.set("speed", 0.5, 0, 1));
    mesh = ofMesh::plane(300, 300,300,300);

    light.setup();
    light.enable();
    light.setAreaLight(120,400);
    light.setAmbientColor(ofFloatColor(0.1,0.1,0.1));
    light.setAttenuation(1.0,0.0001,0.0001);
    light.setDiffuseColor(ofFloatColor(1,1,1));
    light.setSpecularColor(ofFloatColor(1,1,1));
    light.rotate(-110,ofVec3f(1,0,0));
    light.rotate(30,ofVec3f(0,0,1));
    light.setPosition(0,-200,100);

    ofEnableLighting();
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int y = 0; y < 300; y++) {
        for (int x =0; x < 300; x++) {
            mesh.getVertices()[y*300 + x].z = amplitude* ofNoise(x/xyScale,y/xyScale,ofGetFrameNum()*speed);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    mesh.draw();
    cam.end();
    
    gui.draw();
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
