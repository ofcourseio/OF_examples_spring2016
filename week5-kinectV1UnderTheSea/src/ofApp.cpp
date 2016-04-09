#include "ofApp.h"

//-------------------------------------------------------------
void ofApp::setup(){
    
//    ofFileDialogResult r = ofSystemLoadDialog();
//    if (r.bSuccess) {
//        background.load(r.getPath());
//    }
    background.load("underthesea.jpg");
    ofBackground(30, 30, 30);
    //---KINECT SETUP
    kinectv1.setRegistration(true);
    kinectv1.init();
    
//    if(kinectv1.getNumDevices()==0){
//        cout << "NO KINECTS" << endl;
//    }else{
//        cout << "KINECT FOUND: " << kinectv1.getDeviceList()[0].serial << endl;
//    }
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
    
    bDrawForeground = false;
    
    
    
    
}
//-------------------------------------------------------------
void ofApp::update(){
    kinectv1.update();

    if( kinectv1.isFrameNew()){
        //ofPixels --> 8 bit 0 - 255 // data type char
        //ofShortPixels -> 16bit 0 - 65550 // dataType short int
        //ofFloatPixels -> 32bit // floats
  //      foreground.setFromPixels(kinectv1.getRgbPixels());

        
       
       // ofFloatPixels depth =kinectv1.getRawDepthPixels();
        ofShortPixels depth =kinectv1.getRawDepthPixels();//unprocessed pixels// each pixel is the distance from the camera to the object in milimeters.
        
        thresh_pix.allocate(depth.getWidth(), depth.getHeight(), 1);//set size of memory to use.
        foreground.allocate(depth.getWidth(), depth.getHeight(), OF_IMAGE_COLOR_ALPHA);
//        foreground.resize(depth.getWidth(), depth.getHeight());
        foreground.setImageType(OF_IMAGE_COLOR_ALPHA);
        for (int i =0; i < thresh_pix.getHeight(); i++) {
        for (int j  =0; j < thresh_pix.getWidth(); j++) {
            int index = i*thresh_pix.getWidth() + j;
            if (depth.getData()[index] > minDistance &&
                depth.getData()[index] < maxDistance) {
                thresh_pix.getData()[index] = 255;
                foreground.setColor(j, i, kinectv1.getColorAt(j, i));
            }else{
                foreground.getPixels()[index*4+3] = 0;
            //    foreground.setColor(j, i,ofColor(0,0));
                thresh_pix.getData()[index] = 0;
            }
        }
        }
        if(bDrawForeground){
        foreground.update();
        }else{
        drawTexture.loadData(thresh_pix);//*/
        rgbTexture.loadData(kinectv1.getPixels());
        }
    }
}
//-------------------------------------------------------------
void ofApp::draw(){
    if(bDrawForeground){
        background.draw(0, 0, ofGetWidth(), ofGetHeight());
        foreground.draw(0, 0, ofGetWidth(), ofGetHeight());
    }else{
        if(drawTexture.isAllocated()){
            drawTexture.draw(kinectv1DepthRect);
        }
        if (rgbTexture.isAllocated()) {
            rgbTexture.draw(kinectv1RgbRect);
        }
//      kinectv1. // (kinectv1RgbRect);//rgb
    }
    panel.draw();// put this at the end of the draw function
}

//-------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == ' ') {
        bDrawForeground = !bDrawForeground;
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
