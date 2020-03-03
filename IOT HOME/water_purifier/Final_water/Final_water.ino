//servo
#include <Servo.h> 
//servo 
int servoPin = 9;
Servo servo; 
int angle = 0; // servo position in degrees 

//ultrasonic wave
int echoPin = 12;
int trigPin = 13;

//lcd

#include <Wire.h>                        // i2C 통신을 위한 라이브러리

#include <LiquidCrystal_I2C.h>        // LCD 2004 I2C용 라이브러리

LiquidCrystal_I2C lcd(0x27,20,4);     // 접근주소: 0x3F or 0x27


void setup()
{
  // put your setup code here, to run once:
  servo.attach(servoPin); 

  Serial.begin(9600);
  // trig를 출력모드로 설정, echo를 입력모드로 설정
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //lcd setups
    lcd.init();                      // LCD 초기화

    // Print a message to the LCD.

    lcd.backlight();                // 백라이트 켜기
    lcd.setCursor(0,0);             // 1번째, 1라인

    lcd.print("Are You Thirsty?");

    lcd.setCursor(0,1);             // 1번째, 2라인

    lcd.print("Just Put The Cup On");

    lcd.setCursor(6,2);             // 4번째, 3라인

    lcd.print("^w^");

    lcd.setCursor(0,3);             // 9번째, 4라인

    lcd.print("Have A Good Day");


    pinMode(7,INPUT);

        
  
}

void loop() {
  // put your main code here, to run repeatedly:
  float duration, distance;
  
  // 초음파를 보낸다. 다 보내면 echo가 HIGH 상태로 대기하게 된다.
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  
  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  duration = pulseIn(echoPin, HIGH); 
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  distance = ((float)(340 * duration) / 10000) / 2;  
  
//초음파 loop 속 distance 이용한 서보 제어.
  delay(10);
  if(distance>5.5){
     
        servo.write(95); 
        delay(15); 
        
        lcd.setCursor(0,0);             // 1번째, 1라인

        lcd.print("Are You Thirsty?");

        lcd.setCursor(0,1);             // 1번째, 2라인

        lcd.print("Just Put The Cup On");

        lcd.setCursor(6,2);             // 4번째, 3라인

        lcd.print("^w^");

        lcd.setCursor(0,3);             // 9번째, 4라인

        lcd.print("Have A Good Day");

        

        
   
     
  }

  
  if(distance<5.5){
   
        servo.write(180); 
        delay(15);
        lcd.clear();

        lcd.setCursor(0,1);             // 1번째, 2라인

        lcd.print("Preparing...");
        delay(500);
         
        
        
  }


}
