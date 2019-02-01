//
//  Arc.h
//  ofxCubicBezierToBiarc
//
//  Created by Carsten Høyer on 31/01/2019.
//

#pragma once

#include "ofMain.h"

class Arc {
    
public:
    Arc();
    Arc(ofPoint _C, float _r, float _startAngle, float _sweepAngle, ofPoint _P1, ofPoint _P2, bool _cw);
    ofPoint C;
    float r;
    float startAngle;
    float sweepAngle;
    bool cw;
    ofPoint P1;
    ofPoint P2;
    float Length();
    ofPoint PointAt(float t);
    ofPath toPath();
};
