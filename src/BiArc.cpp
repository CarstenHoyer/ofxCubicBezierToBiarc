//
//  BiArc.cpp
//  ofxCubicBezierToBiarc
//
//  Created by Carsten Høyer on 31/01/2019.
//

#include "BiArc.h"
#include "Arc.h"
#include <math.h>

BiArc::BiArc(ofPoint P1, ofPoint T1, ofPoint P2, ofPoint T2, ofPoint T)
{
    // Calculate the orientation
    // https://en.wikipedia.org/wiki/Curve_orientation
    
    double sum = 0.0;
    sum += (T.x - P1.x) * (T.y + P1.y);
    sum += (P2.x - T.x) * (P2.y + T.y);
    sum += (P1.x - P2.x) * (P1.y + P2.y);
    bool cw = sum < 0;
    
    // Calculate perpendicular lines to the tangent at P1 and P2
    Line tl1 = Line::CreatePerpendicularAt(P1, P1 + T1);
    Line tl2 = Line::CreatePerpendicularAt(P2, P2 + T2);
    
    // Calculate the perpendicular bisector of P1T and P2T
    ofPoint P1T2 = (P1 + T) / 2;
    Line pbP1T = Line::CreatePerpendicularAt(P1T2, T);
    
    ofPoint P2T2 = (P2 + T) / 2;
    Line pbP2T = Line::CreatePerpendicularAt(P2T2, T);
    
    // The origo of the circles are at the intersection points
    ofPoint C1 = tl1.Intersection(pbP1T);
    ofPoint C2 = tl2.Intersection(pbP2T);
    
    // Calculate the radii
    float r1 = (C1 - P1).length();
    float r2 = (C2 - P2).length();
    
    // Calculate start and sweep angles
    ofPoint startVector1 = P1 - C1;
    ofPoint endVector1 = T - C1;
    float startAngle1 = atan2(startVector1.y, startVector1.x);
    float sweepAngle1 = atan2(endVector1.y, endVector1.x) - startAngle1;
    
    ofPoint startVector2 = T - C2;
    ofPoint endVector2 = P2 - C2;
    float startAngle2 = atan2(startVector2.y, startVector2.x);
    float sweepAngle2 = atan2(endVector2.y, endVector2.x) - startAngle2;
    
    // Adjust angles according to the orientation of the curve
    if (cw && sweepAngle1 < 0) sweepAngle1 = 2 * M_PI + sweepAngle1;
    if (!cw && sweepAngle1 > 0) sweepAngle1 = sweepAngle1 - 2 * M_PI;
    if (cw && sweepAngle2 < 0) sweepAngle2 = 2 * M_PI + sweepAngle2;
    if (!cw && sweepAngle2 > 0) sweepAngle2 = sweepAngle2 - 2 * M_PI;
    
    A1 = Arc(C1, r1, (float)startAngle1, (float)sweepAngle1, P1, T, cw);
    A2 = Arc(C2, r2, (float)startAngle2, (float)sweepAngle2, T, P2, cw);
}

float BiArc::Length()
{
    return A1.Length() + A2.Length();
}

ofPoint BiArc::PointAt(float t)
{
    float s = A1.Length() / (A1.Length() + A2.Length());
    
    if (t <= s)
    {
        return A1.PointAt(t / s);
    }
    else
    {
        return A2.PointAt((t - s) / (1 - s));
    }
}

vector<tuple<ofPath, ofPath>> BiArc::toPaths(vector<BiArc> biarcs)
{
    vector<tuple<ofPath, ofPath>> paths;
    for (auto biarc = biarcs.begin(); biarc != biarcs.end(); ++biarc) {
        tuple<ofPath, ofPath> arcs = tuple<ofPath, ofPath>((*biarc).A1.toPath(), (*biarc).A2.toPath());
        paths.push_back(arcs);
    }
    return paths;
}
