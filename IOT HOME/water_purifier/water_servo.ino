#include <Servo.h> 
 
int servoPin = 9;

Servo servo; 

int angle = 0; // servo position in degrees 

void setup() 
{ 
    servo.attach(servoPin); 
} 


void loop() 
{ 


    
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 95; angle--) 
  { 
    servo.write(angle); 
    delay(15); 
  } 

  // scan from 0 to 180 degrees
  for(angle = 95; angle < 180; angle++) 
  { 
    servo.write(angle); 
    delay(15);
  }

} 
