int GasPin = 0;
int val;
int sinVal = 0;
int toneVal = 0;
int piezo = 13;

void setup() {
  pinMode(piezo, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(GasPin);
  Serial.println(val);
  if ( val > 800) {
    piezoSound();
  } else {
    noTone(piezo);
  }
  delay(100);

}

void piezoSound() {
  for (int i = 0; i < 180; i++){
      sinVal = (sin(i*(3.1412/180)));
      toneVal = 2000+(int(sinVal*1000));
      tone(piezo, toneVal);
      delay(2);
    }
}
