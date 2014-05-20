#pragma once

#include "ANN.h"
#include "ofMain.h"

class ofxANNNeighbor {
public:
    float x, y, z;
    double distance;
    int idx; // index of the neighbor in the original array

    ofxANNNeighbor(float _x, float _y, float _z);
    ~ofxANNNeighbor();
    ofxANNNeighbor();
    
    
};

class ofxANN {
public:
	ofxANN();
    ~ofxANN();
    
    void setEps(double anEps);
    void loadPoints(vector<ofVec3f>& vertices);
    // defaults to not including the original point and returning a ofVec3f subtype with the distance added
    vector<ofxANNNeighbor> getNeighbors(int k, ofVec3f p);
    vector<ofxANNNeighbor> getNeighbors(int k, ofVec3f p, bool includeOriginal);
    // this version doesn't return the distances in case you need a vector<ofVec3f>
    vector<ofVec3f> getNeighborVectors(int k, ofVec3f p, bool includeOriginal);
    
private:
    int nDim;
    double eps;
    ANNkd_tree* kdTree;
    ANNpointArray dataPoints;
};


