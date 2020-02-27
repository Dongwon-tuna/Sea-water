#include <IRremote.h>

IRrecv irrecv(11);
decode_results results;
int Relaypin = 7;
void setup() {
  // put your setup code here, to run once:
  irrecv.enableIRIn();
  pinMode(Relaypin,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    
    if(results.value == 0xFF30CF){
      digitalWrite(Relaypin,HIGH);
      }
    if(results.value == 0xFF18E7){
      digitalWrite(Relaypin,LOW);
      }     

       delay(30);
       irrecv.resume();
      
    }
}
