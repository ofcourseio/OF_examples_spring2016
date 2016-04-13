#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();
    
		void keyReleased(int key);
		void mouseDragged(int x, int y, int button);
	
    
    ofMesh mesh;
    ofEasyCam cam;
    
    bool bDrawing;
    
};
