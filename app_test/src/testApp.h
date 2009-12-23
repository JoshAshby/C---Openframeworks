#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void serialData(char x);
		void roundButton(int x, int y, int h, char str[15], char color[15]);
		void button();

        //all of the variables used
        char forwardcolor;
        char backcolor;
        char leftcolor;
        char rightcolor;
        float devices; //will be used for serial
        float counter;
        char height[4];


        bool		bSendSerialMessage;			// a flag for sending serial
		char		bytesRead[3];				// data from serial, we will be trying to read 3
		char		bytesReadString[4];			// a string needs a null terminator, so we need 3 + 1 bytes
		int			nBytesRead;					// how much did we read?
		int			nTimesRead;					// how many times did we read?
		float		readTime;


		ofSerial	serial;
		ofTrueTypeFont		font;

};

#endif
