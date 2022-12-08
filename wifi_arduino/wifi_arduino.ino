#include<SoftwareSerial.h> //Included SoftwareSerial Library
//Started SoftwareSerial at RX and TX pin of ESP8266/NodeMCU
SoftwareSerial Arduino(A1, A2);

const int DENDO = 13;

void setup() {
  //Serial S Begin at 9600 Baud
  Serial.begin(9600);
  Arduino.begin(4800);
  pinMode(DENDO, OUTPUT);
}

void loop() {
  while (Arduino.available() > 0) {
    int val = Arduino.parseInt();
    if (Arduino.read() == '\n') {
      
      Serial.println(val);
      switch(val) {
        case 1: {
          digitalWrite(DENDO, HIGH);
          break;
        }
        case 2: {
          digitalWrite(DENDO, LOW);
          break;
        }
        default: break;
      }
    }
  }
}
