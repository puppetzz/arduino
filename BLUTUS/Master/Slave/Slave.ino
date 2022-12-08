#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  Serial.println("Enter your comands");
  mySerial.begin(38400);;
}
void loop() { 
  // Đọc dữ liệu từ HC-O5 và gửi tới Arduiono
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  // Đọc dữ liệu từ Arduiono và gửi tới HC - 05
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}