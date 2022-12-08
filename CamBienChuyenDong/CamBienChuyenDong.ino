const int InfraredPin = 2;
const int piezo = 13;
int sinVal = 0;
int toneVal = 0;

void setup() {
  pinMode(InfraredPin, INPUT);
  pinMode(piezo, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if (digitalRead(InfraredPin) == HIGH) {
    piezoSound();
    Serial.println("anything move in!");
  } else {
    noTone(piezo);
    Serial.println("this is nothing");
  }
  delay(1000);
}

void piezoSound() {
  for (int i = 0; i < 180; i++){
      sinVal = (sin(i*(3.1412/180)));
      toneVal = 2000+(int(sinVal*1000));
      tone(piezo, toneVal);
      delay(2);
    }
}
