//
//  Line.cpp
//  ofxCubicBezierToBiarc
//
//  Created by Carsten Høyer on 31/01/2019.
//

#include "Line.h"

Line::Line(ofPoint _P1, ofPoint _P2) : Line(_P1, Slope(_P1, _P2))
{
    
}

Line::Line(ofPoint _P, float _m)
{
    P = _P;
    m = _m;
}

Line Line::CreatePerpendicularAt(ofPoint P, ofPoint P1)
{
    float m = Slope(P, P1);
    
    if (m == 0)
    {
        return Line(P, nanf("0"));
    }
    else if(isnan(m))
    {
        return Line(P, 0);
    }
    else
    {
        return Line(P, -1.0f / m);
    }
}

ofPoint Line::Intersection(Line l)
{
    if(isnan(m))
    {
        return Line::VerticalIntersection((*this), l);
    }
    else if(isnan(l.m))
    {
        return Line::VerticalIntersection(l, (*this));
    }
    else
    {
        float x = (m * P.x - l.m * l.P.x - P.y + l.P.y) / (m - l.m);
        float y = m * x - m * P.x + P.y;
        return ofPoint(x, y);
    }
}

ofPoint Line::VerticalIntersection(Line vl, Line l)
{
    float x = vl.P.x;
    float y = l.m * (x - l.P.x) + l.P.y;
    return ofPoint(x, y);
}

float Line::Slope(ofPoint P1, ofPoint P2)
{
    if(P2.x == P1.x)
    {
        return nanf("0");
    }
    else
    {
        return (P2.y - P1.y) / (P2.x - P1.x);
    }
}
