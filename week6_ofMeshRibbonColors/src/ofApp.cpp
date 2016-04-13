#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    bDrawing = true;
    cam.disableMouseInput();
    gui.setup();
    gui.add(meshColor.set("Mesh Color 1",ofFloatColor(1,1,1,1),
                          ofFloatColor(0,0,0,0),ofFloatColor(1,1,1,1)));
    gui.add(meshColor2.set("Mesh Color 2",ofFloatColor(1,1,1,1),
                           ofFloatColor(0,0,0,0),ofFloatColor(1,1,1,1)));
    gui.add(speed.set("speed", 40, 0, 200));
    
}
void ofApp::draw(){
    ofEnableDepthTest();
    
    cam.begin();
    ofSetColor(255);
    mesh.enableColors();
    mesh.draw();
    ofSetColor(0);
    mesh.disableColors();
    mesh.drawWireframe();
    
    ofDisableDepthTest();
    
    for (int i = 0; i < mesh.getNumVertices(); i++) {
        ofDrawBitmapString(ofToString(mesh.getNumVertices() - i -1), mesh.getVertex(i));
    }
    
    
    
    cam.end();
    ofDrawBitmapString("Draw mode: " +
                       (string)(bDrawing?" ON":" OFF"), 100, 100);
    
    gui.draw();
}
void ofApp::mouseDragged(int x, int y, int button){
    if (bDrawing) {
        for (int i =0 ; i < mesh.getNumVertices(); i++) {
            mesh.getVertices()[i].z -= speed;
        }
        //ofVec3f is exactly the same as ofPoint
//        for (int i =0 ; i < 4; i++) {
//            mesh.addVertex(mesh.getVertex(mesh.getNumVertices() -1 -i));
//        }
        ofVec3f mousePoint(x-ofGetWidth()/2,-(y-ofGetHeight()/2));
        mesh.addVertex(mousePoint + ofPoint(50, 50));
        mesh.addVertex(mousePoint + ofPoint(-50, 50));
        mesh.addVertex(mousePoint + ofPoint(-50, -50));
        mesh.addVertex(mousePoint + ofPoint(50, -50));
//        mesh.addVertex(mousePoint + ofPoint(-50, -50));
        
        
        int lastIndex = mesh.getNumVertices() -1;
        if(lastIndex > 7){
            for (int i = 0; i < 4; i++) {
                mesh.addTriangle(lastIndex - 0-i, lastIndex -1-i, lastIndex-i -5);
                mesh.addTriangle(lastIndex - 0-i, lastIndex -5-i, lastIndex-i -4);
            }
            
//            mesh.addTriangle(lastIndex -0, lastIndex -1, lastIndex -4);
//            mesh.addTriangle(lastIndex -1, lastIndex -4, lastIndex -5);
//            
//            mesh.addTriangle(lastIndex -1, lastIndex -5, lastIndex -7);
//            mesh.addTriangle(lastIndex -1, lastIndex -3, lastIndex -7);
//            
//            mesh.addTriangle(lastIndex -3, lastIndex -7, lastIndex -6);
//            mesh.addTriangle(lastIndex -3, lastIndex -2, lastIndex -6);
//            
        }
        
//        ofFloatColor c(ofRandom(1),ofRandom(1),ofRandom(1));
//        int colsToAdd = (mesh.getNumVertices()<8)?4:8;
//        for (int i =0; i < 8; i ++) {
//            mesh.addColor(c);
//        }
        
        mesh.addColor(meshColor);
        mesh.addColor(meshColor2);
        mesh.addColor(meshColor);
        mesh.addColor(meshColor2);
        
        
    }
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