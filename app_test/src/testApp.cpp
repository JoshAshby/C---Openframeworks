#include "testApp.h"
#include <string.h>
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

    //load the font for debuging in app
	font.loadFont("DIN.otf",12);

	//set the serial port
	serial.setup("/dev/ttyUSB0", 9600);
}

//--------------------------------------------------------------
void testApp::update(){
    //everytime update is called counter will increase by .05
    counter = counter + 0.05;


    if (bSendSerialMessage){

		// (1) write the letter "a" to serial:
		serial.writeByte('a');

		// (2) read
		// now we try to read 3 bytes
		// since we might not get them all the time 3 - but sometimes 0, 6, or something else,
		// we will try to read three bytes, as much as we can
		// otherwise, we may have a "lag" if we don't read fast enough
		// or just read three every time. now, we will be sure to
		// read as much as we can in groups of three...

		nTimesRead = 0;
		nBytesRead = 0;
		int nRead  = 0;  // a temp variable to keep count per read

		unsigned char bytesReturned[3];

		memset(bytesReadString, 0, 4);
		memset(bytesReturned, 0, 3);

		while( (nRead = serial.readBytes( bytesReturned, 3)) > 0){
			nTimesRead++;
			nBytesRead = nRead;
		};

		memcpy(bytesReadString, bytesReturned, 3);

		bSendSerialMessage = false;
		readTime = ofGetElapsedTimef();
	}
	//button();
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
	ofRect(50, 200, 50, 255);

	ofSetColor(0x092345);
	ofFill();
	ofRect(300, 200, 50, 255);

    //give the height float a value
    //in this case, 100 times the sin of counter (see update)

    //if height is within the proper range, then draw the colored bars
    //if not, draw them, but do not change their height
    //printf("got: %i \n", bytesReadString[1]);
	if (ofInRange(bytesReadString[1],0,255)){
	ofSetColor(0x456456);
	ofFill();
	ofRect(50, 200, 50, bytesReadString[1]);
	} else {
	ofSetColor(0x456456);
	ofFill();
	ofRect(50, 200, 50, 10);
	}
	if (ofInRange(bytesReadString[2],0,255)){
	ofSetColor(0x456456);
	ofFill();
	ofRect(300, 200, 50, bytesReadString[2]);
	} else {
	ofSetColor(0x456456);
	ofFill();
	ofRect(300, 200, 50, 10);
	}
	char tempStr[1024];
	sprintf(tempStr, "Left: %i", bytesReadString[1]);
	font.drawString(tempStr,50,190);

	sprintf(tempStr, "Right: %i", bytesReadString[2]);
	font.drawString(tempStr,300,190);
}

//--------------------------------------------------------------
//All of the code down here is to process the keyboard events,
//and the mouse events, and tell the above code what to do
//when those events happen, such as change the circle color
//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == 'w'){
        forwardcolor = !forwardcolor;
        serial.writeByte('w');
        bSendSerialMessage = true;
	}
	if (key == 's'){
        backcolor = !backcolor;
        serial.writeByte('s');
        bSendSerialMessage = true;
	}
	if (key == 'a'){
        leftcolor = !leftcolor;
        serial.writeByte('a');
        bSendSerialMessage = true;
	}
	if (key == 'd'){
        rightcolor = !rightcolor;
        serial.writeByte('d');
        bSendSerialMessage = true;
	}
	if (key == 'r'){
        bSendSerialMessage = true;
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
        button();
	}
	if (key == 'd'){
        rightcolor = !rightcolor;
        roundButton(100,100,50,"test","red");
	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

void testApp::serialData(char x){
    serial.writeByte(x);
    /*
	nBytesRead = 0;
	int nRead  = 0;  // a temp variable to keep count per read
	unsigned char bytesReturned[3];
	memset(bytesReadString, 0, 4);
    memset(bytesReturned, 0, 3);
	while( (nRead = serial.readBytes( bytesReturned, 3)) > 0){
		nBytesRead = nRead;
	};
	memcpy(bytesReadString, bytesReturned, 3);
	*/
}

void testApp::roundButton(int x, int y, int h, char srt[15], char color[15]){
    //printf("got:\n x: %i \n y: %i \n h: %i \n text: %s \n if-then: %s \n", x, y, h, srt, color);
    /*if (color){
        ofSetColor(0x456456);
    } else {
        ofSetColor(0x092345);
    }
	ofFill();
	ofCircle(x,y,h);*/
	ofSetColor(0x000000);
	ofDrawBitmapString("hello",100,100);
}

void testApp::button(){
    printf("hello\n");
	ofSetColor(0x000000);
	ofDrawBitmapString("hello",100,100);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    //printf("x = %i \n", x);
    //printf("y = %i \n", y);
    //printf("button = %i \n", button);
    if (ofInRange(x,150,250) && ofInRange(y,25,125)){
        forwardcolor = !forwardcolor;
        serial.writeByte('w');
        bSendSerialMessage = true;
    }
    if (ofInRange(x,50,150) && ofInRange(y,75,170)){
        leftcolor = !leftcolor;
        serial.writeByte('a');
        bSendSerialMessage = true;
    }
    if (ofInRange(x,250,350) && ofInRange(y,75,170)){
        rightcolor = !rightcolor;
        serial.writeByte('d');
        bSendSerialMessage = true;
    }
    if (ofInRange(x,150,250) && ofInRange(y,125,225)){
        backcolor = !backcolor;
        serial.writeByte('s');
        bSendSerialMessage = true;
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
