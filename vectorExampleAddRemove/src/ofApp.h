#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    
    //Declare here new vector that will hold elements of type ofRectangle, which just holds the position and size of a rectangle but it has several very handy functions related to it.
    vector<ofRectangle> rects;
    
    
    ofPoint clickPoint;// we will use this to store the point where we clic
    
    bool bIsDragging;// to know if we are dragging the mouse or not
    
    
};
