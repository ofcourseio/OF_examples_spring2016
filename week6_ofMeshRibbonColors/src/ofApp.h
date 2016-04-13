#pragma once

#include "ofMain.h"
#include "ofxGui.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();
    
		void keyReleased(int key);
		void mouseDragged(int x, int y, int button);
	
    
    ofMesh mesh;
    ofEasyCam cam;
    
    bool bDrawing;
    
    ofxPanel gui;
    ofParameter<ofFloatColor> meshColor, meshColor2;
    ofParameter<float>speed;
    
};
