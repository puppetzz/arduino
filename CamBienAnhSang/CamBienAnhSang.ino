int LED = 13;
int LIGHT = 0;
int val = 0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(LIGHT);
  Serial.println(val);
  if (val < 700) {
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
  }
  delay(10);
}
