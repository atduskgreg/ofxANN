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

ofxANNNeighbor::ofxANNNeighbor(float _x, float _y, float _z){
    x = _x;
    y = _y;
    z = _z;
}
ofxANNNeighbor::ofxANNNeighbor(){
    x = 0;
    y = 0;
    z = 0;
}


ofxANNNeighbor::~ofxANNNeighbor(){
}

vector<ofxANNNeighbor> ofxANN::getNeighbors( int k, ofVec3f p){
    getNeighbors(k, p, false);
}

vector<ofxANNNeighbor> ofxANN::getNeighbors( int k, ofVec3f p, bool includeOriginal){
    vector<ofxANNNeighbor> result = vector<ofxANNNeighbor>();
    ANNpoint queryPt = annAllocPt(nDim);
    queryPt = p.getPtr();
    
    ANNidxArray	nnIdx = new ANNidx[k];
    ANNdistArray dists = new ANNdist[k];
    kdTree->annkSearch(queryPt, k, nnIdx, dists, eps);
    
    for(int i = 0; i < k; i++){
        ANNpoint n = dataPoints[nnIdx[i]];
        ofxANNNeighbor neighbor(n[0], n[1], n[2]);
        neighbor.distance = dists[i];
        neighbor.idx = nnIdx[i];
        result.push_back(neighbor);
    }
    
    if(includeOriginal){
        ofxANNNeighbor orig(p.x,p.y, p.z);
        orig.distance = 0;
        result.push_back(orig);
    }
    
    return result;
}

vector<ofVec3f> ofxANN::getNeighborVectors(int k, ofVec3f p, bool includeOriginal){
    vector<ofVec3f> result = vector<ofVec3f>();
    ANNpoint queryPt = annAllocPt(nDim);
    queryPt = p.getPtr();
    
    ANNidxArray	nnIdx = new ANNidx[k];
    ANNdistArray dists = new ANNdist[k];
    kdTree->annkSearch(queryPt, k, nnIdx, dists, eps);
    
    for(int i = 0; i < k; i++){
        ANNpoint n = dataPoints[nnIdx[i]];
        ofVec3f neighbor(n[0], n[1], n[2]);
        result.push_back(neighbor);
    }
    
    if(includeOriginal){
        ofVec3f orig(p.x,p.y, p.z);
        result.push_back(orig);
    }
    
    return result;
}

ofxANN::~ofxANN(){
    // TODO: also delete idx array and dists array
    delete kdTree;
    annClose();
}