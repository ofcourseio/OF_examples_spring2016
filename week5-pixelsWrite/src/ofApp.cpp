#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    img.load("tdf_1972_poster.jpg");
}
void ofApp::update(){}
//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    img.draw(0,0);
    
    if(mouseX >=0 && mouseY >= 0 && mouseX < img.getWidth() && mouseY < img.getHeight()){
        ofColor color = img.getColor(mouseX , mouseY);
        
        ofSetColor(color);
        

        if(ofGetMousePressed(2)){//right button clic
            w = ofMap(mouseY, 0, ofGetWidth(), 1, 200);
        }
        else if(ofGetMousePressed(0)){// left button clic
            for (int y =-w; y < w; y++) {
                for(int x = -w; x < w; x++){
                    if(mouseX+x >=0 && mouseY+y >= 0 && mouseX+x < img.getWidth() && mouseY+y < img.getHeight()){
                        if(ofDist(mouseX+x, mouseY+y, mouseX, mouseY) <=w){//make the brush a circle
                            img.setColor(mouseX+x, mouseY+y, clicColor);
                        }
                    }
                }
            }
            img.update();
        }
        
        ofDrawRectangle(0, 0, 100, 100);
        string msg ="R: " + ofToString((int)color.r)+"\n";
        msg +="G: " + ofToString((int)color.g)+"\n";
        msg +="B: " + ofToString((int)color.b)+"\n";
        msg +="X: " + ofToString(mouseX)+"\n";
        msg +="Y: " + ofToString(mouseY)+"\n";
        msg +="brush width: "+ ofToString(w);
        ofSetColor(255);
        ofDrawBitmapStringHighlight(msg , 10,120, clicColor,ofColor::blue);
    }
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(mouseX < img.getWidth() && mouseY < img.getHeight()){
        clicColor = img.getColor(mouseX , mouseY);
    }
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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
