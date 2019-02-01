//
//  Algorithm.h
//  ofxCubicBezierToBiarc
//
//  Created by Carsten Høyer on 31/01/2019.
//

#pragma once

#include "ofMain.h"
#include <complex>
#include <tuple>

class ofxCubicBezierToBiarc {
public:
    ofxCubicBezierToBiarc();
    vector<tuple<ofPath, ofPath>> ApproxCubicBezier(ofPath bezier, float samplingStep, float tolerance);
    
private:
    static bool IsRealInflexionPoint(complex<float> t);
};
