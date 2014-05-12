#pragma once

#include "ANN.h"
#include "ofMain.h"

class ofxANNNeighbor{
public:
    ofxANNNeighbor( ofVec3f p, double d ){
        point = p;
        distance = d;
    }
    ~ofxANNNeighbor(){}
    ofVec3f point;
    double distance;
};

class ofxANN {
public:
	ofxANN();
    ~ofxANN();
    
    void setEps(double anEps);
    void loadPoints(vector<ofVec3f>& vertices);
    vector<ofxANNNeighbor> getNeighbors(int k, ofVec3f p);
    
private:
    int nDim;
    double eps;
    ANNkd_tree* kdTree;
    ANNpointArray dataPoints;
};


