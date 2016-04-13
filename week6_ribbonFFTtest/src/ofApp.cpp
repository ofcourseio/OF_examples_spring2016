#include "ofApp.h"
double log2(double x){return log(x)/log(2);}
//--------------------------------------------------------------
void ofApp::setup(){
    numBins = 128;
    ofFileDialogResult r = ofSystemLoadDialog();
    if (r.bSuccess) {
        player.load(r.getPath());
        player.play();
    }
    meshes.resize(numBins);
    for (int i =0; i < numBins; i++) {
        meshes[i].setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    }
    lineMesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    maxVal = FLT_MIN;
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i =0; i < numBins; i++) {
        for(int j = 0; j < meshes[i].getNumVertices();j++){
            meshes[i].getVertices()[j].z -= 40;
        }
    }
    
    float * f = ofSoundGetSpectrum(numBins);
    float xInc = ofGetWidth()/numBins;
    lineMesh.clear();
    for (int i =0; i < numBins; i++) {
        if (f[i] > maxVal) {
            maxVal = f[i];
        }

        float y = ofMap(log2(f[i]+1), 0, log2(maxVal+1), 0, ofGetHeight());
        float x = ofMap(log2(i+1), 0, log2(numBins), 0, ofGetWidth());
        meshes[i].addVertex(ofPoint(i *xInc , y));
        meshes[i].addVertex(ofPoint((i-1) *xInc, y));
        

        lineMesh.addVertex(ofVec3f(x, y));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    for (int i =0; i < numBins; i++) {
        ofSetColor(ofColor::fromHsb((255.0*i)/numBins, 255, 255));
        meshes[i].draw();
        ofSetColor(0);
        meshes[i].drawWireframe();
    }
    cam.end();
    
    lineMesh.draw();
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
