#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	angle		= 0; // set our angle that we will take the sin of to 0
	angleAdder	= 0.1; // set the ammount we increment our angle by each frame to 0.1

	ofSetFrameRate(30); // 30 frames per second
	ofBackground(255, 255, 255); // white background
}

//--------------------------------------------------------------
void ofApp::update(){
	angle+=angleAdder; // each update loop, increase our angle by the angleAdder
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofEnableAlphaBlending(); // turn on blending
	
	ofSetColor(0,0,255,100); // set a color
	// and then draw a sin wave with rectangles in that color
	drawSinWaveWithRects(0, /*no offset*/
						 50, /*amplitude of 50*/
						 64, /*width of 64*/
						 140); /*height of 140*/ 
	
	ofSetColor(255,0,0,100); // do this a few times
	drawSinWaveWithRects(0.5, 70, 32, 160);
	
	ofSetColor(255,255,0,100);
	drawSinWaveWithRects(2.5, 100, 10, 190);
	
	ofSetColor(0,255,255,100);
	drawSinWaveWithRects(1.2, 100, 10, 290);
	
	ofSetColor(255,0,255,100);
	drawSinWaveWithRects(1.7, 60, 22, 120);
}
//--------------------------------------------------------------
void ofApp::drawSinWaveWithRects(float angleBase, int amplitude, int rectWidth, int rectHeight){
	
	for(int i=0;i<ofGetWidth()/32;i++){ // increment across the screen by 32pixels at a time.
		//angleBase sets our offset. e.g. if one sin wave starts at 0, and one starts at 0.5, they wont be aligned with eachother
		//amplitude sets the height that the waves will go
		//rectWidth and rectHeight set the size and width of the rectangle. setting a width under 32 creates a space in the wave, over 32 creates overlap
		
		//we add angleBase to the sin is to offset the wave
		//we add angleAdder*i to the sin is so that each consecutive rectangle is using the sin of the next angle. (this is what creates the wave shape)
		ofRect(i*32, ofGetHeight()/2-amplitude + sin(angleBase + angle + angleAdder*i) * amplitude, rectWidth, rectHeight);
	}
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
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

