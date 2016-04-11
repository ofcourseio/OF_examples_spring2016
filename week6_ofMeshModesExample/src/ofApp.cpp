#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofMesh mesh;
    ofPoint initialOffset(100,100);
    float distance = 100;
    for (int i = 0; i < 7; i++) {
        mesh.addVertex(ofPoint(i*distance,0)+initialOffset);
        mesh.addVertex(ofPoint(i*distance,distance)+initialOffset);
    }
    meshes.push_back(mesh);
    meshes.back().setMode(OF_PRIMITIVE_POINTS);
    meshes.push_back(mesh);
    meshes.back().setMode(OF_PRIMITIVE_LINES);
    meshes.push_back(mesh);
    meshes.back().setMode(OF_PRIMITIVE_LINE_STRIP);
    meshes.push_back(mesh);
    meshes.back().setMode(OF_PRIMITIVE_LINE_LOOP);
    meshes.push_back(mesh);
    meshes.back().setMode(OF_PRIMITIVE_TRIANGLES);
    meshes.push_back(mesh);
    meshes.back().setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    meshes.push_back(mesh);
    meshes.back().setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    index = 0;
    bDrawWireframe = true;

    
    
    circleMesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    
    
    ofVec3f center(ofGetWidth()/2, ofGetHeight()/2);
    circleMesh.addVertex(center);
    
    for (int i =0; i < 20; i++) {
        float angle = ofMap(i, 0, 19, 0, TWO_PI);
        cout << angle << endl;
        circleMesh.addVertex(ofVec3f(cos(angle)*200, sin(angle)*200) + center);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    glPointSize(10);

    ofSetColor(255);
    
    if (bDrawWireframe) {
        meshes[index].drawWireframe();
    }else{
        meshes[index].draw();
    }
    ofSetColor(0);
    
    for (int i =0; i < meshes[index].getNumVertices();i++ ) {
        ofDrawBitmapString(ofToString(i), meshes[index].getVertex(i) + ofPoint(5, 0) );
    }
    
    
    
    circleMesh.drawWireframe();
    
    string message = "Mesh mode: ";
    switch (meshes[index].getMode()) {
        case OF_PRIMITIVE_LINE_LOOP:
            message += "OF_PRIMITIVE_LINE_LOOP";
            break;
        case OF_PRIMITIVE_LINE_STRIP:
            message += "OF_PRIMITIVE_LINE_STRIP";
            break;
        case OF_PRIMITIVE_LINES:
            message += "OF_PRIMITIVE_LINES";
            break;
        case OF_PRIMITIVE_POINTS:
            message += "OF_PRIMITIVE_POINTS";
            break;
        case OF_PRIMITIVE_TRIANGLE_STRIP:
            message += "OF_PRIMITIVE_TRIANGLE_STRIP";
            break;
        case OF_PRIMITIVE_TRIANGLE_FAN:
            message += "OF_PRIMITIVE_TRIANGLE_FAN";
            break;
        case OF_PRIMITIVE_TRIANGLES:
            message += "OF_PRIMITIVE_TRIANGLES";
            break;
        default:
            break;
    }
    message += "\nDraw Wireframe: " + (string)(bDrawWireframe?"TRUE":"FALSE");
    ofDrawBitmapStringHighlight(message, 50, 50);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == OF_KEY_UP) {
        index ++;
        index %= meshes.size();
    }else if(key == OF_KEY_DOWN){
        index --;
        if (index < 0) {
            index = 0;
        }
    }else if(key == ' '){
        bDrawWireframe = !bDrawWireframe;
    }
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
