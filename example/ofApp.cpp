#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetColor(0);
    ofNoFill();
    
    for (auto i = 0; i < 7; i++) {
        ofPath path;
        path.setFilled(false);
        path.setStrokeColor(ofColor(ofRandomf() * 64, ofRandomf() * 64, ofRandomf() * 64));
        path.setStrokeWidth(2);
        paths.push_back(path);
    }
    
    paths[0].moveTo(ofPoint(100, 500));
    paths[0].bezierTo(ofPoint(150, 100), ofPoint(500, 150), ofPoint(350, 350));
    
    paths[1].moveTo(ofPoint(150, 550));
    paths[1].bezierTo(ofPoint(300, 400), ofPoint(500, 400), ofPoint(550, 550));
    
    paths[2].moveTo(ofPoint(200, 600));
    paths[2].bezierTo(ofPoint(200, 200), ofPoint(600, 450), ofPoint(450, 250));
    
    paths[3].moveTo(ofPoint(300, 700));
    paths[3].bezierTo(ofPoint(550, 300), ofPoint(300, 400), ofPoint(700, 600));
    
    paths[4].moveTo(ofPoint(233.89831f, 285.0169000000001f));
    paths[4].bezierTo(ofPoint(233.89831f, 293.0169000000001f), ofPoint(230.5649766666668f, 301.0169000000001f), ofPoint(223.89831f, 309.0169000000001f));
    
    paths[5].moveTo(ofPoint(204.89831f, 328.0169f));
    paths[5].bezierTo(ofPoint(198.89831f ,334.0169f), ofPoint(191.2316433333334f, 337.0169f), ofPoint(181.89831f, 337.0169f));

    paths[6].moveTo(ofPoint(199, 135));
    paths[6].bezierTo(ofPoint(199, 134), ofPoint(210, 134), ofPoint(211, 134));
}


//--------------------------------------------------------------
void ofApp::update(){
    arcs.clear();
    for (auto iter = paths.begin(); iter != paths.end(); ++iter) {
        vector<tuple<ofPath, ofPath>> biarc = converter.ApproxCubicBezier((*iter), 5, 1);
        for (auto arcIter = biarc.begin(); arcIter != biarc.end(); ++arcIter) {
            arcs.push_back((*arcIter));
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    std::stringstream ss;
    ss << "         FPS: " << ofGetFrameRate() << std::endl;
    ofDrawBitmapString(ss.str(), ofVec2f(20, 20));
    
    // Draw original paths;
    for (auto i = paths.begin(); i != paths.end(); ++i) {
        (*i).draw();
    }
    
    // Draw converted curves.
    for (auto iter = arcs.begin(); iter != arcs.end(); ++iter) {
        tuple<ofPath, ofPath> biarc = (*iter);
        ofPath path1 = get<0>(biarc);
        path1.setFilled(false);
        path1.translate(ofPoint(2,2));
        path1.setStrokeColor(ofColor(250,0,0,255));
        path1.setStrokeWidth(1);
        path1.setCircleResolution(96);
        path1.draw();
        
        ofPath path2 = get<1>(biarc);
        path2.setFilled(false);
        path2.translate(ofPoint(2,2));
        path2.setStrokeColor(ofColor(0,255,0,255));
        path2.setStrokeWidth(1);
        path2.setCircleResolution(96);
        path2.draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
