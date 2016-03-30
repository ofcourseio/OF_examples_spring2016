#include "ofApp.h"

//----------------------------------------------------
void ofApp::setup(){
    player.load("ow.mp3");
    player.setMultiPlay(true);
}

//---------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        player.play();
    }else if(key == 'o'){
        ofFileDialogResult result = ofSystemLoadDialog();
        if (result.bSuccess) {
            player.load(result.getPath());
            player.setMultiPlay(true);
        }
        
    }
}
