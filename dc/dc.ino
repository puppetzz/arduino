const int low = 7;
const int high = 8;
const int en = 9;

void setup() {
  pinMode(low, OUTPUT);
  pinMode(high, OUTPUT);
  pinMode(en, OUTPUT);
}

void loop() {
  backward();
}

void forward() {
  digitalWrite(low, LOW);
  digitalWrite(high, HIGH);
  analogWrite(en, 255);
}

void backward() {
  digitalWrite(low, HIGH);
  digitalWrite(high, LOW);
  analogWrite(en, 255);
}