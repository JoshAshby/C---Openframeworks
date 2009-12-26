#include "testApp.h"
#include "stdio.h"

bool locked = false;

//--------------------------------------------------------------
void testApp::setup(){
	TO.start();
	ofSetWindowTitle("Threadgui Example");
}

//--------------------------------------------------------------
void testApp::update(){
	ofBackground(0,0,0);   // black because threads are EVIL ;)
}

//--------------------------------------------------------------
void testApp::draw(){
	TO.roundButton(100,100,50,"Hello",0); //draw a few buttons
	TO.roundButton(300,100,60,"Good Bye",1);
	TO.roundButton(500,100,80,"Click Me",2);
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
    //send the (x,y) to the gui thread to see if you clicked on a button
    TO.click(x,y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    TO.click(x,y);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

