#include "WProgram.h"
void setup();
void loop();
//--------------------------------------
//include other libraries here:


//--------------------------------------
//Declare your variables here:
#define ultra1 0
#define ultra2 1
#define led 13
char x;
char y;
char z;
//--------------------------------------
//setup the pins
void setup() {
pinMode(led, OUTPUT);
Serial.begin(9600);
}
//--------------------------------------
//main loop
void loop() {
//digitalWrite(led, HIGH);
while (Serial.available() > 0){
x = Serial.read();
z = analogRead(ultra1);
y = analogRead(ultra2);
if (x){
    //Serial.write(z);
    //Serial.write(y);
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
}
}
}
//--------------------------------------
//Pandoras Box
//if you delete this, the world will end
int main(void)
{
	init();

	setup();

	for (;;)
		loop();

	return 0;
}
//--------------------------------------
//Another Pandoras Box
//delete this and the sky will fall on your head
extern "C" void __cxa_pure_virtual() {
cli();
for (;;);
}
