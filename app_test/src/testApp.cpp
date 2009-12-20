#include "testApp.h"
//--------------------------------------------------------------
void testApp::setup(){

    //color of the background
    ofBackground(200,200,200);

    //window title
	ofSetWindowTitle("Navigation");

	ofSetFrameRate(60);

	//these are for whether the circles are dark blue or light blue
	forwardcolor = false;
	backcolor = false;
	leftcolor = false;
	rightcolor = false;

	ofSetCircleResolution(500);

	//the counter used to test the colored bars
	counter = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    //everytime update is called counter will increase by .05
    counter = counter + 0.05;
}

//--------------------------------------------------------------
void testApp::draw(){

    //these if (color) then sets are for the circles
    //basically they say "if the color is set to true,
    //the circle will be light blue/grey
    //if it's anything else besides true, it is dark blue
    if (forwardcolor){
        ofSetColor(0x456456);
    } else {
        ofSetColor(0x092345);
    }
	ofFill();
	ofCircle(200,75,50);
	ofSetColor(0x000000);
	//drew the circle, and now to draw the text
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


    //these two rectangles are the colored bars background
	ofSetColor(0x092345);
	ofFill();
	ofRect(50, 200, 50, 100);

	ofSetColor(0x092345);
	ofFill();
	ofRect(300, 200, 50, 100);

    //give the height float a value
    //in this case, 100 times the sin of counter (see update)
	height = 100 * sin(counter);

    //if height is within the proper range, then draw the colored bars
    //if not, draw them, but do not change their height
	if (ofInRange(height,10,100)){
	ofSetColor(0x456456);
	ofFill();
	ofRect(50, 200, 50, height);

	ofSetColor(0x456456);
	ofFill();
	ofRect(300, 200, 50, height);
	} else {
	ofSetColor(0x456456);
	ofFill();
	ofRect(50, 200, 50, 10);

	ofSetColor(0x456456);
	ofFill();
	ofRect(300, 200, 50, 10);
	}
}

//--------------------------------------------------------------
//All of the code down here is to process the keyboard events,
//and the mouse events, and tell the above code what to do
//when those events happen, such as change the circle color
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
    //printf("x = %i \n", x);
    //printf("y = %i \n", y);
    //printf("button = %i \n", button);
    if (ofInRange(x,150,250) && ofInRange(y,25,125)){
        forwardcolor = !forwardcolor;
    }
    if (ofInRange(x,50,150) && ofInRange(y,75,170)){
        leftcolor = !leftcolor;
    }
    if (ofInRange(x,250,350) && ofInRange(y,75,170)){
        rightcolor = !rightcolor;
    }
    if (ofInRange(x,150,250) && ofInRange(y,125,225)){
        backcolor = !backcolor;
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    //printf("x = %i \n", x);
    //printf("y = %i \n", y);
    //printf("button = %i \n", button);
    if (ofInRange(x,150,250) && ofInRange(y,25,125)){
        forwardcolor = !forwardcolor;
    }
    if (ofInRange(x,50,150) && ofInRange(y,75,170)){
        leftcolor = !leftcolor;
    }
    if (ofInRange(x,250,350) && ofInRange(y,75,170)){
        rightcolor = !rightcolor;
    }
    if (ofInRange(x,150,250) && ofInRange(y,125,225)){
        backcolor = !backcolor;
    }

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
