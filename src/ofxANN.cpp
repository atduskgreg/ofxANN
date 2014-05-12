//
//  ofxANN.cpp
//  emptyExample
//
//  Created by Greg Borenstein on 5/11/14.
//
//

#include "ofxANN.h"

ofxANN::ofxANN(){
    // defaults
    nDim = 3;
    eps = 0;
}

void ofxANN::setEps(double anEps){
    eps = anEps;
}

void ofxANN::loadPoints(vector<ofVec3f>& vertices){
    dataPoints = annAllocPts(vertices.size()*3, nDim);
    for(int i = 0; i < vertices.size(); i+=3){
        dataPoints[i] = vertices[i].getPtr();
    }
    
    kdTree = new ANNkd_tree(dataPoints, vertices.size()*3, nDim);
}

vector<ofxANNNeighbor> ofxANN::getNeighbors( int k, ofVec3f p){
    vector<ofxANNNeighbor> result = vector<ofxANNNeighbor>();
    ANNpoint queryPt = annAllocPt(nDim);
    queryPt = p.getPtr();
    
    ANNidxArray	nnIdx = new ANNidx[k];
    ANNdistArray dists = new ANNdist[k];
    kdTree->annkSearch(queryPt, k, nnIdx, dists, eps);
    
    for(int i = 0; i < k; i++){
        ANNpoint n = dataPoints[nnIdx[i]];
        double d = dists[i];
        result.push_back(ofxANNNeighbor(ofVec3f(n[0], n[1], n[2]), d));
    }
    return result;
}

ofxANN::~ofxANN(){
    // TODO: also delete idx array and dists array
    delete kdTree;
    annClose();
}