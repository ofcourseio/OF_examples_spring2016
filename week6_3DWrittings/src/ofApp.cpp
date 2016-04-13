#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofEasyCam cam;
    
    bDrawMode = true;
    
    gui.setup();
    gui.add( minWidth.set("Min Width", 10, 0, 50));
    gui.add( maxWidth.set("Max Width", 100, 20, 150));
    gui.add(color.set("Color", ofFloatColor(1.0,1.0,1.0,1.0), ofFloatColor(0,0,0,0), ofFloatColor(1.0,1.0,1.0,1.0)));
    gui.add(moveZ.set("moveZ", 100, -100,200));
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    

    ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update(){

}
//--------------------------------------------------------------
void ofApp::addPointToMesh(ofPoint newPoint){


    int resolution = 24;
    
    for (auto & v:mesh.getVertices()) {
        v.z -= moveZ;
    }
    
    vertVects vv;
    vv.point =newPoint;
    
    
    float angleIncrement = 360.0/resolution;
    
    ofVec3f direction = newPoint - lastPoint;
    direction.normalize();
    vv.direction = direction;
    
    float width = 100;//ofMap(newPoint.distance(lastPoint), 0 , 400, minWidth, maxWidth);
    
    ofVec3f perpendicular;
    if (direction == ofVec3f(0,0,1)) {
        perpendicular = direction.getPerpendicular(ofVec3f(0,1,0));
    }else{
        perpendicular = direction.getPerpendicular(ofVec3f(0,0,1));
    }
    vv.perpendicular = perpendicular;
    bool bIsEmpty = false;
    if ( mesh.getNumVertices() <= resolution*2) {
        bIsEmpty = true;
    }
    
    for (int i = 0; i < resolution; i++) {
        ofPoint p = newPoint + perpendicular.getRotated(angleIncrement*i, direction)*width;
        mesh.addVertex(p);
        vv.normals.push_back(p*width);
        mesh.addColor(color);
        
    }
    
    verts.push_back(vv);
 
    if (!bIsEmpty) {
        for (int i = 0; i < resolution; i++) {
            //first triangle
            mesh.addIndex(mesh.getNumVertices() -1 - resolution + i);
            if (i == resolution -1) {
                mesh.addIndex(mesh.getNumVertices() -1 - resolution );
            }else{
                mesh.addIndex(mesh.getNumVertices() -1 - resolution + i + 1);
            }
            mesh.addIndex(mesh.getNumVertices() -1 - resolution*2 + i);
            //second triangle
            
            mesh.addIndex(mesh.getNumVertices() -1 - resolution*2 + i);
            if (i == resolution -1) {
                mesh.addIndex(mesh.getNumVertices() -1 - resolution*2 );
                mesh.addIndex(mesh.getNumVertices() -1 - resolution );
            }else{
                mesh.addIndex(mesh.getNumVertices() -1 - resolution*2 + i + 1);
                mesh.addIndex(mesh.getNumVertices() -1 - resolution + i+1);
            }
            //*/
        }
    }

    
    
    
    lastPoint = newPoint;
 
}
//--------------------------------------------------------------
void ofApp::draw(){


    
    ofDrawBitmapStringHighlight("mesh verts: " +ofToString(mesh.getNumVertices())+"\n"+
                                ofToString(verts.size()), 100,130  );
    cam.begin();
    if(ofGetKeyPressed('k')){
        for (auto& v:verts) {
            v.draw();
        }
    }else{
    

    mesh.enableColors();
    mesh.draw();
    mesh.disableColors();
    ofSetColor(0);
    mesh.drawWireframe();
//    glPointSize(5);
//    mesh.drawVertices();
    cam.end();
    }
    
    
    ofDrawBitmapStringHighlight("DRAW MODE: "+ (string)(bDrawMode?"ON":"OFF"), 100, 100);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        bDrawMode = !bDrawMode;
        if (bDrawMode) {
            cam.disableMouseInput();
        }else{
            cam.enableMouseInput();
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

    if(bDrawMode){
        addPointToMesh(cam.screenToWorld( ofPoint(x,y)));
    }
    
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
