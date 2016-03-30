#include "ofApp.h"
void ofApp::setup(){
    	mainOutputSyphonServer.setName("Screen Output");
}
void ofApp::update(){

}
void ofApp::draw(){
    ofBackground(255);

    //HERE DRAW WHAT EVER YOU WANT TO.

    
    
    //MAKE SURE THAT THE FOLLOWING LINE IS AT THE END OF DRAW.
    // Anything you draw after this line will not go through syphon.
    mainOutputSyphonServer.publishScreen();
}

