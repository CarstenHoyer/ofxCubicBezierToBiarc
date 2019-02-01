//
//  CubicBezier.cpp
//  ofxCubicBezierToBiarc
//
//  Created by Carsten Høyer on 31/01/2019.
//

#include "CubicBezier.h"
#include <math.h>

CubicBezier::CubicBezier()
{
    
}

CubicBezier::CubicBezier(ofPath path)
{
    auto commands = path.getCommands();
    ofPoint P1 = (ofPoint) commands[0].to;
    ofPoint C1 = (ofPoint) commands[1].cp1;
    ofPoint C2 = (ofPoint) commands[1].cp2;
    ofPoint P2 = (ofPoint) commands[1].to;
    
    init(P1, C1, C2, P2);
}

CubicBezier::CubicBezier(ofPoint _P1, ofPoint _C1, ofPoint _C2, ofPoint _P2)
{
    init(_P1, _C1, _C2, _P2);
}

void CubicBezier::init(ofPoint _P1, ofPoint _C1, ofPoint _C2, ofPoint _P2)
{
    P1 = _P1;
    C1 = _C1;
    C2 = _C2;
    P2 = _P2;
}

tuple<complex<float>, complex<float>> CubicBezier::InflexionPoints() {
    ofPoint A = C1 - P1;
    ofPoint B = C2 - C1 - A;
    ofPoint C = P2 - C2 - A - 2 * B;
    
    complex<float> a(B.x * C.y - B.y * C.x, 0);
    complex<float> b(A.x * C.y - A.y * C.x, 0);
    complex<float> c(A.x * B.y - A.y * B.x, 0);
    
    auto t1 = (-b + sqrt(b * b - 4.0f * a * c)) / (2.0f * a);
    auto t2 = (-b - sqrt(b * b - 4.0f * a * c)) / (2.0f * a);
    
    return tuple<complex<float>, complex<float>>(t1, t2);
}

tuple<CubicBezier, CubicBezier> CubicBezier::Split(float t)
{
    auto p0 = P1 + t * (C1 - P1);
    auto p1 = C1 + t * (C2 - C1);
    auto p2 = C2 + t * (P2 - C2);
    
    auto p01 = p0 + t * (p1 - p0);
    auto p12 = p1 + t * (p2 - p1);
    
    auto dp = p01 + t * (p12 - p01);
    
    return tuple<CubicBezier, CubicBezier>(CubicBezier(P1, p0, p01, dp), CubicBezier(dp, p12, p2, P2));
}

ofPoint CubicBezier::PointAt(float t)
{
    return (float) pow(1 - t, 3) * P1 +
        (float)(3 * pow(1 - t, 2) * t) * C1 +
        (float)(3 * (1 - t) * pow(t, 2)) * C2 +
        (float) pow(t, 3) * P2;
}
