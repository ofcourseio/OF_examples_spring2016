#include "ofApp.h"

//-------------------------------------------------------------
void ofApp::setup(){
    ofBackground(30, 30, 30);
    //---KINECT SETUP
    kinectv1.setRegistration(true);
    kinectv1.init();
    kinectv1.open();
    kinectv1.setCameraTiltAngle(0);
    
    //---GUI SETUP
    panel.setup();
    panel.add(minDistance.set("minDistance", 0, 0, 12000));
    panel.add(maxDistance.set("maxDistance", 12000, 0, 12000));
    
    //---- ofRectangles setup
    float margin = 10;
    float w = (ofGetWidth()/2) - (margin*2);
    float h = (ofGetHeight()/2) - (margin*2);
    kinectv1DepthRect.set(margin, ofGetHeight()/2 + margin, w,h) ;
    kinectv1RgbRect.set(ofGetWidth()/2 + margin, ofGetHeight()/2 + margin, w,h);
    
}
//-------------------------------------------------------------
void ofApp::update(){
    kinectv1.update();

    if( kinectv1.isFrameNew()){
        //ofPixels --> 8 bit 0 - 255 // data type char
        //ofShortPixels -> 16bit 0 - 65550 // dataType short int
        //ofFloatPixels -> 32bit // floats
       
        ofShortPixels depth =kinectv1.getRawDepthPixels();//unprocessed pixels// each pixel is the distance from the camera to the object in milimeters.
        
        thresh_pix.allocate(depth.getWidth(), depth.getHeight(), 1);//set size of memory to use.
        for (int i =0; i < thresh_pix.size(); i++) {
            if (depth.getData()[i] > minDistance &&
                depth.getData()[i] < maxDistance) {
                thresh_pix.getData()[i] = 255;
            }else{
                thresh_pix.getData()[i] = 0;
            }
        }
            drawTexture.loadData(thresh_pix);
    }
}
//-------------------------------------------------------------
void ofApp::draw(){
    drawTexture.draw(kinectv1DepthRect);
    
    kinectv1.draw(kinectv1RgbRect);//rgb
    
    panel.draw();// put this at the end of the draw function
}

//-------------------------------------------------------------
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
