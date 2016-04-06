#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofFileDialogResult res = ofSystemLoadDialog();
    if(res.bSuccess){
        img.load(res.getPath());
    }
    bCircularSample =true;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    img.draw(0, 0);
    
    
    
    int avgR = 0;
    int avgG = 0;
    int avgB = 0;
    
    int numAvereaged = 0;
    
    for (int x = -averageRadius; x < averageRadius; x++) {
        for (int y = -averageRadius; y < averageRadius; y++) {
            if(mouseX + x >= 0 && mouseY + y >= 0){
                if (mouseX +x < img.getWidth() && mouseY + y < img.getHeight()) {
                    if ((bCircularSample && sqrt(x*x + y*y) <= averageRadius) || !bCircularSample) {
                        
                        ofColor pxCol = img.getColor(mouseX + x, mouseY+y);
                        avgR += pxCol.r;
                        avgG += pxCol.g;
                        avgB += pxCol.b;
                        
                        numAvereaged ++;
                    }
                }
            }
        }
    }
    
    ofSetColor(0);
    ofNoFill();
    if (bCircularSample) {
        ofDrawEllipse(mouseX , mouseY, averageRadius * 2, averageRadius * 2);
    }else{
        ofDrawRectangle(mouseX - averageRadius, mouseY - averageRadius, averageRadius * 2, averageRadius * 2);
    }
    
    ofFill();
    ofSetColor(avgR/(float)numAvereaged,avgG/(float)numAvereaged,avgB/(float)numAvereaged );
    ofDrawRectangle(0, 0, 100, 100);
    
    ofDrawBitmapStringHighlight(bCircularSample?"CIRCULAR SAMPLING":"SQUARE SAMPLING\nAverage Radius: "+ ofToString(averageRadius), 30, 30);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == ' '){
        bCircularSample = !bCircularSample;
    }else if(key == OF_KEY_UP){
        averageRadius ++;
    }else if(key == OF_KEY_DOWN){
        averageRadius --;
        if (averageRadius <= 0) {
            averageRadius = 1;
        }
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
