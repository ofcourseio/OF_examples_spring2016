#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofFileDialogResult r = ofSystemLoadDialog();
    if(r.bSuccess){
        if(img.load(r.getPath())){
            img.resize(img.getWidth() /10, img.getHeight() / 10);
            
            mesh = ofMesh::plane(img.getWidth(), img.getHeight(),img.getWidth(), img.getHeight());
            
            for (int i =0; i < img.getHeight(); i++) {
                for (int j = 0; j < img.getWidth(); j++) {
                    int meshIndex = i*img.getWidth()+j;
                    ofPoint v = mesh.getVertex(meshIndex);

                  
                    v.z = img.getColor(j, i).getLightness();
                    
                    mesh.setVertex(meshIndex, v);
                    mesh.addColor(img.getColor(j, i));
                }
            }
        }
    }
    ofEnableDepthTest();

}

//--------------------------------------------------------------
void ofApp::update(){

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
