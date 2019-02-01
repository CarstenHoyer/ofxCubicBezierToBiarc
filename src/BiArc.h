//
//  BiArc.hpp
//  ofxCubicBezierToBiarc
//
//  Created by Carsten Høyer on 31/01/2019.
//

#pragma once

#include "ofMain.h"
#include "Line.h"
#include "Arc.h"
#include <tuple>

class BiArc {
public:
    BiArc(ofPoint P1, ofPoint T1, ofPoint P2, ofPoint T2, ofPoint T);
    Arc A1;
    Arc A2;
    float Length();
    ofPoint PointAt(float t);
    static vector<tuple<ofPath, ofPath>> toPaths(vector<BiArc> biarcs);
};
