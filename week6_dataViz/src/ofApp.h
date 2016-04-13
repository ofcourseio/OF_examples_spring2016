#pragma once

#include "ofMain.h"


class creditCard{
public:
    string cardType, city, date,product, price,name,state,country;
    ofVec2f geoPos;
    float time;
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

    vector<creditCard> cards;
    
//    vector<string> cardType;
//    vector<string> city;
//    vector<ofVec2f> geoPos;
    
    ofImage map;
    
    std::map <string, int> cardBrand;
		
};
