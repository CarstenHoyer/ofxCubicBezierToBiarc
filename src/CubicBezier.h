//
//  CubicBezier.h
//  ofxCubicBezierToBiarc
//
//  Created by Carsten Høyer on 31/01/2019.
//

#pragma once

#include "ofMain.h"
#include <complex>
#include <tuple>

class CubicBezier {
public:
    CubicBezier();
    CubicBezier(ofPath path);
    CubicBezier(ofPoint _P1, ofPoint _C1, ofPoint _C2, ofPoint _P2);
    ofPoint P1;
    ofPoint P2;
    ofPoint C1;
    ofPoint C2;
    tuple<complex<float>, complex<float>> InflexionPoints();
    tuple<CubicBezier, CubicBezier> Split(float t);
    ofPoint PointAt(float t);
    
private:
    void init(ofPoint _P1, ofPoint _C1, ofPoint _C2, ofPoint _P2);
};

