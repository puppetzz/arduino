#include <IRremote.h>

#define IN1  2
#define IN2  3
#define IN3  4
#define IN4  5

const int RECV_Pin = 6;
const int LED_Pin = 13;

int val = 0;
int piezo = 12;
float sinVal;
int toneVal;

IRrecv irrecv(RECV_Pin);
decode_results results;

int paso [4][4] =
{
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  //irrecv.blink13(true);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode(piezo, OUTPUT);
}



void loop() {
  if (irrecv.decode(&results)) {
    if (results.bits > 0) {
      Serial.println(results.value, HEX);
      switch(results.value){
        case 0xFF38C7:
          run();
          break;
        case 0xFFA25D:{
          led(7);
          break;
        }
        case 0xFF629D:{
          led(8);
          break;
        }
        case 0xFFE21D:{
          led(9);
          break;
        }
        case 0xFF22DD:{
          led(10);
          break;
        }
        case 0xFF02FD:{
          led(11);
          break;
        }
        case 0xFF18E7:{
          piezoSound();
          break;
        }
        case 0xFF4AB5:{
          noTone(piezo);
          break;
        }
      }
    irrecv.resume();
    }
  }
}

void run() {
  for (int k = 0; k < 128; k++) {
      for (int i = 0; i < 4; i++)
      {
        digitalWrite(IN1, paso[i][0]);
        digitalWrite(IN2, paso[i][1]);
        digitalWrite(IN3, paso[i][2]);
        digitalWrite(IN4, paso[i][3]);
        delay(2);
      }  
    }
    delay(1000);
}

void led(int led_pin) {
  digitalWrite(led_pin, HIGH);
  delay(200);
  digitalWrite(led_pin, LOW);
}

void piezoSound() {
  for (int i = 0; i < 180; i++){
      sinVal = (sin(i*(3.1412/180)));
      toneVal = 2000+(int(sinVal*1000));
      tone(piezo, toneVal);
      delay(2);
    }
}
