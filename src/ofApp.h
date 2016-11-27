#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxGui.h"

#define SEND_TO_IP "127.0.0.1"
#define SEND_TO_PORT 12347

class ofApp : public ofBaseApp{

    ofxOscSender sender;
    
    void sendBlobAudio();
    void sendBackgroundAudio();
    
    //Interface
    ofxPanel gui;
    ofxToggle sendBlobAudioMessage;
    ofxToggle sendBackgroundMessage;
    ofxIntSlider desiredFramerate;
    ofxLabel text;
    
	public:
		void setup();
		void update();
		void draw();
};
