#include "testApp.h"
#include "stdio.h"

bool locked = false;

//--------------------------------------------------------------
void testApp::setup(){
	TO.start();
	ofSetWindowTitle("Threadgui ");
}

//--------------------------------------------------------------
void testApp::update(){
	ofBackground(0,0,0);   // black because threads are EVIL ;)
}

//--------------------------------------------------------------
void testApp::draw(){
	TO.roundButton(75,100,20,"<",0); //draw a few buttons
	TO.roundButton(125,100,20,"V",1);
	TO.roundButton(175,100,20,">",2);
	TO.roundButton(125,50,20,"^",3);
	//draw a label
	TO.label(20,45,"Movement");
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'a'){
        TO.click(0);
    }
    if  (key == 's'){
        TO.click(1);
    }
    if (key == 'd'){
        TO.click(2);
    }
    if  (key == 'w'){
        TO.click(3);
    }
}
//---------------------------------------------------------------
void testApp::keyReleased(int key){
    if (key == 'a'){
        TO.click(0);
    }
    if  (key == 's'){
        TO.click(1);
    }
    if (key == 'd'){
        TO.click(2);
    }
    if  (key == 'w'){
        TO.click(3);
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

