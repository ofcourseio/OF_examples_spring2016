#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(200),ofColor(100));// just a fancier background. :D

    ofFill();// tell OF to draw filled shapes.
    for(int i = 0; i < rects.size(); i++){
        if (rects[i].inside(ofGetMouseX(), ofGetMouseY())) {// The .inside(float x, float y) checks if the cordinates x, y are inside the rectangle.
            ofSetColor(255, 0,0); //if our mouse is over the rectangle the color will be set to red;
        }else{
            ofSetColor(0, 127, 255);// if it is not it will be set to a kind of cyan.
        }
        ofDrawRectangle(rects[i]);// then draw a rectangle using the cordinates stored in the rect collection's element with index i
    }
    if (bIsDragging) {
        ofNoFill();// tell OF to draw shapes with no fill, hence just outline stroke.
        // just draw an outline rectangle so we know how the rectangle we are going to create looks like.
        ofSetColor(0);// black
        ofDrawRectangle(clickPoint.x, clickPoint.y, ofGetMouseX() - clickPoint.x, ofGetMouseY() - clickPoint.y);
    }

    
    //The following will just show a message on screen, using a very simple and basic typo
    ofDrawBitmapStringHighlight("Clic anywhere over the background and drag to create a new rectangle\nClick over a rectangle to delete it", 20, 20);
    
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
    bIsDragging = true;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    clickPoint.set(x,y);// when we press the mouse we set the values of clicpoi
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    bool bDeletedRect = false;
    for(int i = 0; i < rects.size(); i++){
        if (rects[i].inside(x, y)){
            rects.erase(rects.begin() + i); //this way you remove the element at index i
            //all the elements that come after this element will get their indices reduced by 1.
            i--; // as we deleted an element we need to reduce i by one so we dont skip the next element.
            bDeletedRect = true;
        }
    }
    if(!bDeletedRect && bIsDragging){
        // if we didn't delete any rectangle, which means that our mouse is not a rectangle.
        // Only create a new rectangle when dragging, otherwise it will create a rectangle with
        // width and height equal to zero, as the mousePressed and mouseReleased points will be the same.
        rects.push_back(ofRectangle(clickPoint.x, clickPoint.y, x - clickPoint.x, y - clickPoint.y));
    }
    bIsDragging = false;
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
