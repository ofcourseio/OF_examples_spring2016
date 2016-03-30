#include "ofApp.h"
void ofApp::setup(){
    receiver.setup(12345);
}
void ofApp::update(){
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        if (m.getRemoteIp() == "192.168.6.233") {
            //then do something
        }
        if(m.getAddress() == "/mouse/dragged"){
            ofColor col(m.getArgAsInt32(2),m.getArgAsInt32(3),m.getArgAsInt32(4));
            paths[m.getRemoteIp()].setStrokeColor(col);
            paths[m.getRemoteIp()].lineTo(m.getArgAsInt32(0), m.getArgAsInt32(1));
        }else if(m.getAddress() == "/mouse/pressed"){
            paths[m.getRemoteIp()].moveTo(m.getArgAsInt32(0), m.getArgAsInt32(1));
            paths[m.getRemoteIp()].setStrokeWidth(4);
            paths[m.getRemoteIp()].setFilled(false);
        }else if(m.getAddress() == "/mouse/released"){
            paths[m.getRemoteIp()].newSubPath();
        }
    }
}
void ofApp::draw(){
    ofBackground(255);
    
//    for (map<string,ofPath>::iterator it= paths.begin(); it!=paths.end(); ++it){
//        it->second.draw();
//    }

    for(auto& p:paths){
        p.second.draw();
    }
}

