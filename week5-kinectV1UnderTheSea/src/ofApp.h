#pragma once

#include "ofMain.h"
#include "ofxKinectV2.h"
#include "ofxGui.h"

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
		
    
    ofxPanel panel;
    ofParameter<float> minDistance, maxDistance;
    
    
    ofxKinectV2 kinectv1;
    
    ofRectangle kinectv1DepthRect, kinectv1RgbRect;

    
    ofImage foreground;
    ofImage background;
    
    ofPixels thresh_pix;
    
    ofTexture drawTexture, rgbTexture;
  
    bool bDrawForeground;
};
