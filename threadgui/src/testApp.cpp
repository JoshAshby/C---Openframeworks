#include "testApp.h"
#include "stdio.h"

bool locked = false;
float serialdata;
float ludata;
float rudata;

//--------------------------------------------------------------
void testApp::setup(){
	TO.start();
	ofSetWindowTitle("Threadgui Example");
}

//--------------------------------------------------------------
void testApp::update(){
	ofBackground(0,0,0);
}

//--------------------------------------------------------------
void testApp::draw(){
    TO.roundButton(0,0,40,"",4);
    //draw a label
	TO.label(20,45,"Movement");
	//draw a few buttons
	TO.roundButton(75,100,20,"<",0);
	TO.roundButton(125,100,20,"V",1);
	TO.roundButton(175,100,20,">",2);
	TO.roundButton(125,50,20,"^",3);

	TO.label(500,45,"Data");
	TO.line(520,70,520,350,5);

	TO.bullet(400,90,"Serial");
	TO.text(550,90,serialdata);
	TO.line(420,105,620,105,2);
	TO.mlbullet(400,120,"Left\nUltrasound");
	TO.text(550,120,ludata);
	TO.line(420,135,620,135,2);
	TO.mlbullet(400,150,"Right\nUnltrasound");
	TO.text(550,150,rudata);

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

