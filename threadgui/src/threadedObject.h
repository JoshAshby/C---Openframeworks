 #ifndef _THREADED_OBJECT
#define _THREADED_OBJECT

#include "ofMain.h"
#include "ofxThread.h"
#include <cstring>

/*
Threadgui
2009 - Joshua Ashby
joshuaashby@joshashby.com
http://joshashby.com
*/

class threadedObject : public ofxThread{

	public:

                    //yucky thread stuff:
                    // threaded fucntions that share data need to use lock (mutex)
	                // and unlock in order to write to that data
	                // otherwise it's possible to get crashes.
	                //
	                //This file sets up the thread in charge of all of the buttons,
	                //and the click functions for them.
	                //The roundButtons function is called to draw a circular button,
	                //simply give it the (x,y) of the center of the circle, the radius
	                //the text, and the number (soon to be removed).
	                //the function will then draw the button, set up the color change for
	                //click, and place the text in the center of the button.

		//--------variables---------
		bool roundbuttons[1024];
		//this is the max # of buttons, if you change this, change the 1024
		//in the click statment to the same number you change this to.
		int xcoord[1024];//and change these three
		int ycoord[1024];// <--
		int hvalue[1024];// <--
		int width;
		int button;
		int i;
		//--------------------------
		threadedObject(){
		}

		void start(){
            startThread(true, false);   // blocking, verbose
        }

        void stop(){
            stopThread();
        }

		//--------------------------
		void threadedFunction(){

			while( isThreadRunning() != 0 ){
				if( lock() ){
					unlock();
					ofSleepMillis(1 * 1000);
				}
			}
		}
        //--------------------------
        void label(int x, int y, char str[20]){
            //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
			int width;
            ofSetRectMode(OF_RECTMODE_CORNER);

			width = strlen(str)*8 + 10;

			ofSetColor(0x029807);
			ofFill();
			ofRect(x,y,width,20);

			ofSetColor(0xffffff);
            ofDrawBitmapString(str,x+5,y+15);
        }
		//--------------------------
		void roundButton(int x, int y, int h, char srt[15], int color){
            //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
//debug            printf("got:\n x: %i \n y: %i \n h: %i \n text: %s \n if-then: %s \n", x, y, h, srt, color);
            //draw the circle with radius h at cord. (x,y)
            xcoord[color] = x-h;
            ycoord[color] = y-h;
            hvalue[color] = h;
//debug            printf("x:%i\ny:%i\n",xcoord[color],ycoord[color]);
            if (roundbuttons[color]) {
                ofSetColor(0x029807);
            } else {
                ofSetColor(0x456456);
            }
            ofFill();
            ofCircle(x,y,h);

            ofNoFill();
            ofSetColor(0xffffff);
            ofCircle(x,y,h);

            //calculate how far over the text needs to be to be in the center of the circle
            width = strlen(srt);
            width = (width*8)/2;//8 is the average width of a letter for this

            //draw the text in the center of the circle
            ofSetColor(0x000000);
            x = x-width;
            ofDrawBitmapString(srt,x,y);
		}
        //-----------------------------
		void click(int x, int y){
		    //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
			//setup two variables
            int xc;
            int yc;
            //here we go (cycling through the buttons
            for (i = 0; i < 1024; i++){
                //get the lower corner coordinates
                xc = xcoord[i] + hvalue[i]*2;
                yc = ycoord[i] + hvalue[i]*2;
//debug                printf("x: %i\ny: %i\nxcoord: %i\nycoord: %i\nxc: %i\nyc: %i\nh: %i\n",x,y,xcoord[i],ycoord[i],xc,yc,hvalue[i]);
                //if the x is with in range of a button
                if (x > xcoord[i] && x < xc){
                    //then see if y is in range
                    if (y > ycoord[i] && y < yc){
//debug                        printf("y: %i\n",y);
                        //if it is, change the that buttons color
                        button = i;
                        roundbuttons[button] = !roundbuttons[button];
                        //place case statement here for button functions.
                        switch (button) {
                            case 0:
                                printf("Hello\n");
                                break;
                            case 1:
                                printf("Good Bye\n");
                                break;
                            case 2:
                                printf("Click Me\n");
                                break;
                        }
                    }
                }
            }
		}
		//---------------------------
		//Second click that does it by button number so you can use this in the testApp::keyPressed for example
		//or generating a sequence to change them
		void click(int color){
		    //thread stuff
		    if( lock() ){
		        unlock();
		    }else{
				printf("can't lock!\neither an error\nor the thread has stopped");
			}
            roundbuttons[color] = !roundbuttons[color];
            //place case statement here for button functions.
            switch (button) {
                case 0:
                    printf("Hello\n");
                    break;
                case 1:
                    printf("Good Bye\n");
                    break;
                case 2:
                    printf("Click Me\n");
                    break;
            }
		}
};

#endif
