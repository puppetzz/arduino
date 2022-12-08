#include <Servo.h> 
Servo myservo;

int potpin = 0;
int val;

void setup() { 
  myservo.attach(9); 
  Serial.begin(9600);
} 

void loop() { 
//  val = analogRead(potpin);
//  
//  val = map(val, 0, 1023, 0, 179);
//  Serial.println(val);
//  myservo.write(val);
//  delay(15);

    myservo.write(0);
    delay(1000);
  
    myservo.write(90);
    delay(1000);
  
    myservo.write(180);
    delay(1000);
}
