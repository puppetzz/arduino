#define LINE 2
int val = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(LINE);
  Serial.print(val);
  delay(500);
}
