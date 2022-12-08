#include "DHT.h" 
#include<SoftwareSerial.h>           
const int DHTPIN = 4;      
const int DHTTYPE = DHT11;  
DHT dht(DHTPIN, DHTTYPE);

  SoftwareSerial BTSerial(3,2);
 // int Button =4;
  int led=5;
    String text = "";
void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
 // pinMode(Button,INPUT_PULLUP);
  pinMode(led,OUTPUT); 
    dht.begin();       

}

void loop() {
 //int button= digitalRead(Button);
  if(BTSerial.available()>0)
 {
    
       //Serial.write(BTSerial.read());
       text = BTSerial.readString();
       Serial.print(text);
       text.trim();
 }
 if(text=="a")  
 {
  digitalWrite(led,HIGH);
 }
 else if (text=="b")
 {
  digitalWrite(led,LOW);
 }
 else {
   float h = dht.readHumidity();    
  float t = dht.readTemperature(); 

  BTSerial.print("Nhiet do: ");
  BTSerial.println(t);               
  BTSerial.print("Do am: ");
  BTSerial.println(h); 
 }
}
