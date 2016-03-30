#include "ofApp.h"

void ofApp::setup(){
    sender.setup("192.168.6.116", 12345);
    gui.setup();
    gui.add(color.set("color", ofColor::black,ofColor::black, ofColor::white));
}
void ofApp::update(){}
void ofApp::draw(){
    gui.draw();
}
void ofApp::keyPressed(int key){}
void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y ){}
//----------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    ofxOscMessage m;
    m.setAddress("/mouse/dragged");
    m.addIntArg(x);//0
    m.addIntArg(y);//1
    m.addIntArg(color.get().r);//2
    m.addIntArg(color.get().g);//3
    m.addIntArg(color.get().b);//4
    sender.sendMessage(m);
}

//----------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ofxOscMessage m;
    m.setAddress("/mouse/pressed");
    m.addIntArg(x);
    m.addIntArg(y);
    sender.sendMessage(m);
}
//---------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    ofxOscMessage m;
    m.setAddress("/mouse/released");
    m.addIntArg(x);
    m.addIntArg(y);
    sender.sendMessage(m);
}
//----------------------------------------------------
void ofApp::mouseEntered(int x, int y){}
//----------------------------------------------------
void ofApp::mouseExited(int x, int y){}
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
