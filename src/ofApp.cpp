#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // OSC
    sender.setup(SEND_TO_IP, SEND_TO_PORT);
    
    // GUI
    gui.setup("audioSimulator");
    gui.setShape(30, 30, 200, 100);
    gui.add(sendBlobAudioMessage.setup("Send audioBlob", false));
    gui.add(sendBackgroundMessage.setup("Send audioBack", false));
    gui.add(desiredFramerate.setup("FrameRate",20,1,60));
    
    // Frame rate
    ofSetFrameRate(desiredFramerate);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (sendBlobAudioMessage){
        this->sendBlobAudio();
    }
    
    if (sendBackgroundMessage){
        this->sendBackgroundAudio();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::white, ofColor::gray);
    ofSetHexColor(0xffffff);
    this->gui.draw();
}

//--------------------------------------------------------------
void ofApp::sendBlobAudio(){
    // sending blobAudio
    ofxOscMessage m;
    m.setAddress("/blobAudio");
    m.addInt32Arg(0);
    float y = (float) ofGetMouseY() / (float) ofGetHeight();
    m.addFloatArg(y);
    sender.sendMessage(m);
    ofLog(OF_LOG_NOTICE, "Sent /blobAudio " + ofToString(y));
}

//--------------------------------------------------------------
void ofApp::sendBackgroundAudio(){
    // sending backgroundAudio
    ofxOscMessage m;
    m.setAddress("/backgroundAudio");
    float y = (float) ofGetMouseY() / (float) ofGetHeight();
    m.addFloatArg(y);
    sender.sendMessage(m);
    ofLog(OF_LOG_NOTICE, "Sent /backgroundAudio " + ofToString(y));
}
