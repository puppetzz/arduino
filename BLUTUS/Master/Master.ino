#include<SoftwareSerial.h>
  SoftwareSerial BTSerial(3,2);
  int Button =4;
  int led=5;
void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(Button,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  
}

void loop() {
 int button= digitalRead(Button);
 if(button== LOW)
 {
  BTSerial.println("a");
 }
 if(BTSerial.available()>0)
 {
       Serial.write(BTSerial.read());
 }
 if(BTSerial.read()=='b')
 {
  digitalWrite(led,HIGH);

 }
 else
 {
  digitalWrite(led,LOW);
 }
}