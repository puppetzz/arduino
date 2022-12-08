#include<SoftwareSerial.h> //Included SoftwareSerial Library
#include<ESP8266WiFi.h>
//Started SoftwareSerial at RX and TX pin of ESP8266/NodeMCU
SoftwareSerial NodeMCU(D2, D3);
WiFiClient client;
WiFiServer server(80);

/* WIFI settings */
const char* ssid = "Hii";
const char* password = "17122002";

/* data received from application */
String  data =""; 
/* define L298N or L293D motor control pins */

void setup() {
  //Serial S Begin at 9600 Baud
  Serial.begin(9600);
  NodeMCU.begin(4800);
  connectWiFi();
  server.begin();

  pinMode(D2, INPUT);
  pinMode(D3, OUTPUT);
}

void loop() {
  client = server.available();
  if (!client) return; 
  data = checkClient ();
  

  if (data == "batdendo") guiData("1");
    
    else if (data == "tatdendo") guiData("2");
}

void guiData(String message) {
  NodeMCU.print(message);
  NodeMCU.println("\n");
}

String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  Serial.println(request);
  request.remove(0, 5);
  Serial.println(request);
  request.remove(request.length()-9,9);
  Serial.println(request);
  return request;
}
void connectWiFi()
{
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.print("..");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("NodeMCU Local IP is : ");
  Serial.print((WiFi.localIP()));
}
