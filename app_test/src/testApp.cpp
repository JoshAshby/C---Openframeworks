#include "testApp.h"
char forwardcolor;
char backcolor;
char leftcolor;
char rightcolor;
//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255,255,255);
	ofSetWindowTitle("Navigation");
	ofSetFrameRate(60);
	forwardcolor = false;
	backcolor = false;
	leftcolor = false;
	rightcolor = false;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    if (forwardcolor){
        ofSetColor(0x456456);
    } else {
        ofSetColor(0x092345);
    }
	ofFill();
	ofCircle(200,75,50);
	ofSetColor(0x000000);
	ofDrawBitmapString("Forward",175,75);


	if (leftcolor){
        ofSetColor(0x456456);
    } else {
        ofSetColor(0x092345);
    }
	ofFill();
	ofCircle(100,125,50);
	ofSetColor(0x000000);
	ofDrawBitmapString("Left",75,125);


	if (backcolor){
        ofSetColor(0x456456);
    } else {
        ofSetColor(0x092345);
    }
	ofFill();
	ofCircle(200,175,50);
	ofSetColor(0x000000);
	ofDrawBitmapString("Back",175,175);


	if (rightcolor){
        ofSetColor(0x456456);
    } else {
        ofSetColor(0x092345);
    }
	ofFill();
	ofCircle(300,125,50);
	ofSetColor(0x000000);
	ofDrawBitmapString("Right",275,125);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == 'w'){
        forwardcolor = !forwardcolor;
	}
	if (key == 's'){
        backcolor = !backcolor;
	}
	if (key == 'a'){
        leftcolor = !leftcolor;
	}
	if (key == 'd'){
        rightcolor = !rightcolor;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	if (key == 'w'){
        forwardcolor = !forwardcolor;
	}
	if (key == 's'){
        backcolor = !backcolor;
	}
	if (key == 'a'){
        leftcolor = !leftcolor;
	}
	if (key == 'd'){
        rightcolor = !rightcolor;
	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

