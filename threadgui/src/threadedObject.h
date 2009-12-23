#ifndef _THREADED_OBJECT
#define _THREADED_OBJECT

#include "ofMain.h"
#include "ofxThread.h"

// this is not a very exciting example yet
// but ofThread provides the basis for ofNetwork and other
// operations that require threading.
//
// please be careful - threading problems are notoriously hard
// to debug and working with threads can be quite difficult


class threadedObject : public ofxThread{

	public:


                    // threaded fucntions that share data need to use lock (mutex)
	                // and unlock in order to write to that data
	                // otherwise it's possible to get crashes.
	                //
	                // also no opengl specific stuff will work in a thread...
	                // threads can't create textures, or draw stuff on the screen
	                // since opengl is single thread safe

		//--------------------------
		bool roundbuttons[1024];
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

			/*while( isThreadRunning() != 0 ){
				if( lock() ){

				}
			}*/
		}

		//--------------------------
		void roundButton(int x, int y, int h, char srt[15], int color){
            //printf("got:\n x: %i \n y: %i \n h: %i \n text: %s \n if-then: %s \n", x, y, h, srt, color);
            roundbuttons[color] = false;
            if (roundbuttons[color]){
                ofSetColor(0x456456);
            } else {
                ofSetColor(0x092345);
            }
            ofFill();
            ofCircle(x,y,h);
            ofSetColor(0xffffff);
            x = x-h+30;
            ofDrawBitmapString(srt,x,y);

			if( lock() ){
				unlock();
			}else{
//				str = "can't lock!\neither an error\nor the thread has stopped";
			}
		}

};

#endif
