#include "testApp.h"
#include "stdio.h"

bool locked = false;

//--------------------------------------------------------------
void testApp::setup(){
	TO.start();
}

//--------------------------------------------------------------
void testApp::update(){
	ofBackground(0,0,0);   // black because threads are EVIL ;)
}

//--------------------------------------------------------------
void testApp::draw(){
	TO.roundButton(100,100,50,"hello",0);
	TO.roundButton(200,100,60,"bye",1);
	TO.roundButton(400,100,80,"rawr",2);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    if (key == 's'){
        TO.stop();
    }
    if  (key == 'd'){
        TO.start();
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

