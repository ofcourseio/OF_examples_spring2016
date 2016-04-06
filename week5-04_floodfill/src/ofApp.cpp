#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    img.load("tdf_1972_poster.jpg");
    bSampleFillColor = true;
}

//--------------------------------------------------------------
void ofApp::update(){

}
//--------------------------------------------------------------
void ofApp::floodFill(ofPixels& pix, ofColor fill, ofColor target,int x , int y, bool bUse8Dirs){

        if(target == fill){
            return;
        }
        if(x >= 0 && x < pix.getWidth() && y >=0 && y < pix.getHeight()){
            if (pix.getColor(x, y) == target) {
                pix.setColor(x, y, fill);
                floodFill(pix, fill, target, x+1, y, bUse8Dirs);
                floodFill(pix, fill, target, x-1, y, bUse8Dirs);
                floodFill(pix, fill, target, x, y+1, bUse8Dirs);
                floodFill(pix, fill, target, x, y-1, bUse8Dirs);
                if(bUse8Dirs){
                    floodFill(pix, fill, target, x+1, y+1, bUse8Dirs);
                    floodFill(pix, fill, target, x-1, y+1, bUse8Dirs);
                    floodFill(pix, fill, target, x+1, y-1, bUse8Dirs);
                    floodFill(pix, fill, target, x-1, y-1, bUse8Dirs);
                }
            }
        }
    
}
//--------------------------------------------------------------
void ofApp::draw(){
    img.draw(0,0);
    
    //the following is just for drawing text with colors.
    string msg = "clic to flood fill";
    if (bSampleFillColor) {
        msg = "Clic to sample FILL Color";
    }
    
    ofColor textColor0 = ofColor::black;
    ofColor colorUnderMouse = img.getPixels().getColor(mouseX, mouseY);
    if (colorUnderMouse.getBrightness() < 127) {
        textColor0 = ofColor::white;
    }
    ofDrawBitmapStringHighlight(msg,  mouseX + 10, mouseY + 20, colorUnderMouse, textColor0);

    msg = "Press \'f\' key: sample FILL color mode.\n";
    msg += "Press \'o\' key: load image.";
    ofColor textColor = ofColor::black;
    if (fillColor.getBrightness() < 127) {
        textColor = ofColor::white;
    }
    
    ofDrawBitmapStringHighlight(msg, 20,20, fillColor, textColor);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'f') {
        bSampleFillColor = true;
    }else if (key == 'o'){
        ofFileDialogResult result = ofSystemLoadDialog();
        if (result.bSuccess) {
            img.load(result.getPath());
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
    if (bSampleFillColor && x < img.getWidth() && y < img.getHeight()) {
        fillColor = img.getPixels().getColor(x, y);
        bSampleFillColor = false;
    }else {
        floodFill(img.getPixels(), fillColor, img.getPixels().getColor(x, y), x, y, false);
        img.update();
    }
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
