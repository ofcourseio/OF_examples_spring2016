//
//  particle.h
//  
//
//  Created by Jason Levine on 2015-10-29.
//
//

#pragma once
#include "ofMain.h"

class particle {
public:
    void setup();
    void update();
    void draw();

    ofPoint pos;
    ofPoint vel;
    float radius;
    ofColor col;
    
    bool isMoving;
};