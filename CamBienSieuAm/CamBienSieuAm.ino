const int trigPin = 3;     
const int echoPin = 5;     
int piezo = 13;
float sinVal;
int toneVal;

void setup()
{
  pinMode(piezo, OUTPUT);
  pinMode(trigPin,OUTPUT);  
  pinMode(echoPin,INPUT);    
}

void loop()
{
    unsigned long duration; 
    int distance;           
    
    digitalWrite(trigPin, LOW);   
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);   
    delayMicroseconds(5);   
    digitalWrite(trigPin, LOW);   
  
    duration = pulseIn(echoPin,HIGH);  
    distance = int(duration/2/29.412);
    
    if(distance <= 50)
      piezoSound();
    else {
      noTone(piezo);
    }
    delay(200);
}

void piezoSound() {
  for (int i = 0; i < 180; i++){
      sinVal = (sin(i*(3.1412/180)));
      toneVal = 2000+(int(sinVal*1000));
      tone(piezo, toneVal);
      delay(2);
    }
}
