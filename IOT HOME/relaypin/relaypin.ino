int relaypin = 8;
int led = 13;
int but = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(relaypin,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(but,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 

  if(digitalRead(but)==HIGH){
     digitalWrite(led,HIGH);
     digitalWrite(relaypin,HIGH);
     delay(500);
     digitalWrite(relaypin,LOW);
    }
  

 
  
  
}
