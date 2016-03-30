#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    ofxOscReceiver receiver;
    
    map<string, ofPath> paths;
};
