#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    depthImage.loadImage("depth.png");
    unsigned char * pixels = depthImage.getPixels();

    ofVec3f p;
    
    for(int row = 0; row < depthImage.getHeight(); row++){
        for(int col = 0; col < depthImage.getWidth(); col++){
            int i = row * depthImage.getWidth() + col;
            mesh.addVertex(ofPoint(col, row, pixels[i]));
            
            if(row == 125 && col == 123){
                p = ofPoint(col, row, pixels[i]);
            }
        }
    }
    
    ann.loadPoints(mesh.getVertices());
    
    cout << "p: " << p.x << "," << p.y << "," << p.z << endl;
    
    vector<ofxANNNeighbor> neighbors =  ann.getNeighbors(5, p);
    for(int i = 0; i < neighbors.size(); i++){
        cout << neighbors[i].point.x << ","<< neighbors[i].point.y << "," << neighbors[i].point.z << " d: " << neighbors[i].distance << endl;
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    mesh.drawVertices();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}