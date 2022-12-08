#include <IRremote.h>
#define IN1  2
#define IN2  3
#define IN3  4
#define IN4  5


const int RECV_Pin = 11;
const int LED_Pin = 13;
const int piezo = 12;
int sinVal = 0, toneVal = 0;

int paso [4][4] =
{
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};

IRrecv irrecv(RECV_Pin);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();

pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(LED_Pin, OUTPUT);
}

void loop() {
   if (irrecv.decode(&results)) {
     if (results.bits > 0) {
       Serial.println(results.value, HEX);
       int state;
       if (0x100 == results.value) {
         digitalWrite(LED_Pin , state);
         run();
       }
     }
     irrecv.resume();
   }
}


void piezoSound() {
  for (int i = 0; i < 180; i++) {
      sinVal = (sin(i*(3.1412/180)));
      toneVal = 2000+(int(sinVal*1000));
      tone(piezo, toneVal);
    }
}

void piezoOff() {
  noTone(piezo);
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
