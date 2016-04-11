#include "ofApp.h"
using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
    gui.setup();
    gui.add(minArea.set("Min area", 10, 1, 100));
    gui.add(maxArea.set("Max area", 200, 1, 500));
    gui.add(threshold.set("Threshold", 128, 0, 255));
    gui.add(letterSpacing.set("letterSpacing", 20, 1, 50));
    
    gui.add(bDrawCountours.set("bDrawCountours", false));
    
    font.load("helvetica", 20);
    
}
void ofApp::update(){
    kinect.update();
    

    if(kinect.isFrameNew()) {
        contourFinder.setMinAreaRadius(minArea);
        contourFinder.setMaxAreaRadius(maxArea);
        contourFinder.setThreshold(threshold);
        contourFinder.findContours(kinect.getDepthPixels());
        contourFinder.setSimplify(true);
    }
}
void ofApp::draw(){
    kinect.draw(0, 0);
    if (bDrawCountours) {
   contourFinder.draw();
    }

    for (int i = 0; i < contourFinder.getPolylines().size(); i++) {
        ofPolyline p = contourFinder.getPolylines()[i];
        p.simplify();
        
        for (int i = 0; i < text.length(); i++) {
//            ofPushMatrix();
    //        ofTranslate(p.getPointAtLength(i*letterSpacing));
            ofPoint point = p.getPointAtLength(i*letterSpacing);
                font.drawString(text.substr(i,1), point.x, point.y);
            
  //          ofPopMatrix();
        }
        
    }
    gui.draw();
    
    font.drawString(text, 100, 500);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == OF_KEY_BACKSPACE){
        text.pop_back();
    }else if(key == OF_KEY_RETURN){
        text+= "\n";
    }else{
        text += (unsigned char)key;
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
