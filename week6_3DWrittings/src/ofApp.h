#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class vertVects{
public:
    ofPoint direction, perpendicular, point;
    vector<ofPoint> normals;
    
    void draw(){
        ofPushStyle();
        ofSetLineWidth(4);
        ofSetColor(ofColor::red);
        ofDrawLine(point, point + direction *100);
        ofSetColor(ofColor::black);
        ofDrawLine(point, perpendicular*100+point);
        ofSetColor(ofColor::white);
        for(auto &n:normals){
            ofDrawLine(point, n);
        }
        ofPopStyle();
    }
    

};

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
    
    
    void addPointToMesh(ofPoint newPoint);
		
    
    
    ofMesh mesh;
    ofEasyCam cam;
    
    ofPoint lastPoint;
    vector<vertVects> verts;
    
    bool bDrawMode;
    
    ofxPanel gui;
    ofParameter<float> maxWidth, minWidth, moveZ;
    ofParameter<ofFloatColor> color;
    
};
