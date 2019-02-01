//
//  Line.h
//  ofxCubicBezierToBiarc
//
//  Created by Carsten Høyer on 31/01/2019.
//

#pragma once

#include "ofMain.h"

class Line {
public:
    Line(ofPoint _P, float _m);
    Line(ofPoint P1, ofPoint P2);
    ofPoint P;
    float m;
    static Line CreatePerpendicularAt(ofPoint P, ofPoint P1);
    ofPoint Intersection(Line l);

private:
    static float Slope(ofPoint P1, ofPoint P2);
    static ofPoint VerticalIntersection(Line vl, Line l);
};
