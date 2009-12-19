#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	counter = 0;
	ofSetCircleResolution(50);
	ofBackground(255,255,255);
	bSmooth = false;
	ofSetWindowTitle("Button");

	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
}

//--------------------------------------------------------------
void testApp::update(){
	counter = counter + 0.5;
}

//--------------------------------------------------------------
void testApp::draw(){

	//--------------------------- circles
	//let's draw a circle:
	if (bSmooth){
		ofSetColor(0x092345);
	} else {
        ofSetColor(0x456456);
	}
	float radius = 100 + 10 * sin(counter);
	ofFill();		// draw "filled shapes"
	ofCircle(400,400,radius);
	// now just an outline
	ofNoFill();
	ofSetColor(0xCCCCCC);
	ofCircle(400,400,100);

	// use the bitMap type
	// note, this can be slow on some graphics cards
	// because it is using glDrawPixels which varies in
	// speed from system to system.  try using ofTrueTypeFont
	// if this bitMap type slows you down.
	ofSetColor(0x000000);
	ofDrawBitmapString("Josh Ashby", 360,400);

/*
	//--------------------------- rectangles
	ofFill();
	for (int i = 0; i < 50; i++){
		ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255));
		ofRect(ofRandom(250,350),ofRandom(350,450),ofRandom(10,20),ofRandom(10,20));
	}
	ofSetColor(0x000000);
	ofDrawBitmapString("rectangles", 275,500);

	//---------------------------  transparency
	ofSetColor(0x00FF33);
	ofRect(400,350,100,100);
	// alpha is usually turned off - for speed puposes.  let's turn it on!
	ofEnableAlphaBlending();
	ofSetColor(255,0,0,127);   // red, 50% transparent
	ofRect(450,430,100,33);
	ofSetColor(255,0,0,(int)(counter * 10.0f) % 255);   // red, variable transparent
	ofRect(450,370,100,33);
	ofDisableAlphaBlending();

	ofSetColor(0x000000);
	ofDrawBitmapString("transparency", 410,500);

	//---------------------------  lines
	// a bunch of red lines, make them smooth if the flag is set

	if (bSmooth){
		ofEnableSmoothing();
	}

	ofSetColor(0xFF0000);
	for (int i = 0; i < 20; i++){
		ofLine(600,300 + (i*5),800, 250 + (i*10));
	}

	if (bSmooth){
		ofDisableSmoothing();
	}

	ofSetColor(0x000000);
	ofDrawBitmapString("lines\npress 's' to toggle smoothness", 600,500);
*/
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	if (key == 's'){
		bSmooth = !bSmooth;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
	if (key == 's'){
		bSmooth = !bSmooth;
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
