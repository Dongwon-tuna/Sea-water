void setup()

{
  Serial.begin(9600); 
  pinMode(8, INPUT_PULLUP);                                  

}



void loop()

{

  

  Serial.print(analogRead(A1)); // X축 값이 표기됩니다.

  Serial.print("  ");           

  Serial.print(analogRead(A0)); //  Y축 값이표기 됩니다.

  Serial.print("  ");           //숫자가 헷깔리지않토록 중간에 공백칸을 두었습니다.

  Serial.println(digitalRead(8)); // Z축(스위치) 값이 표기됩니다.



  delay(100);             



                       

}
