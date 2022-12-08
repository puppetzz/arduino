#include <IRremote.h> 
 
 IRsend irsend(3); 
 
 void setup() { 
  Serial.begin(9600);
 } 
 
 void loop() { 
//  int val = analogRead(0);
//  Serial.println(val);
//  if (val > 0){
//   irsend.sendRC5(0x100, 8);
//   delay(100); 
//  }

  irsend.sendRC5(0x100, 8);
  delay(2000);
  // irsend.sendRC5(0x101, 8);
  // delay(200);
}
