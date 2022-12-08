#include <SoftwareSerial.h>
SoftwareSerial BT(3,2); // TX , RX

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    //BT.begin(9600);
    Serial.println("AT Commands");
    Serial.println("Fuction               || Command   ");
    Serial.println("Test                  || AT   ");
    Serial.println("Name                  || AT+NAME?   ");
    Serial.println("Pass                  || AT+PSWD?   ");
    Serial.println("Change Name           || AT+NAME=<Name>   ");
    Serial.println("Change Pass           || AT+PSWD?=<Pass>   ");
    Serial.println("Address               || AT+ADDR?   ");
    Serial.println("UART                  || AT+UART?   ");
    Serial.println("Connect to ADDR       || AT+BIND=<ADDR>   ");
    Serial.println("ROLE                  || AT+ROLE?   ");
    Serial.println("Change Role           || AT+ROLE=<0,1> {0 Slave , 1 Master}");
    Serial.println("Find BT               || AT+INQ   ");
    Serial.println("CMODE                 || AT+COMDE?   ");
    Serial.println("CMODE                 || AT+COMDE=<?> { 0 ALL , 1 }   ");
    Serial.println("Reset                 || AT+ORGL   ");
    Serial.println("Clear BT              || AT+RMAAD   ");
    BT.begin(38400);

}

void loop() {
  // Read from HC=05 TO Arduno
  if (BT.available())
      Serial.write(BT.read());
  //Read frm Adruno to HC 05
  if (Serial.available())
      BT.write(Serial.read());
  // put your main code here, to run repeatedly:

}
