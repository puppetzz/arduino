// #define IN1  2
// #define IN2  3
// #define IN3  4
// #define IN4  5
// #define LINE 2

// int val = 0;
 
// // Secuencia de pasos a par máximo del motor. Realmente es una matriz que representa la tabla del unipolar que he mostrado antes
// int paso [4][4] =
// {
//   {1, 1, 0, 0},
//   {0, 1, 1, 0},
//   {0, 0, 1, 1},
//   {1, 0, 0, 1}
// };
 
// void setup()
// {
//   // Todos los pines se configuran como salida, ya que el motor no enviará señal a Arduino
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
//   pinMode(IN3, OUTPUT);
//   pinMode(IN4, OUTPUT);
//   Serial.begin(9600);
// }
 
// // Bucle para hacerlo girar
// void loop()
// { 
//   val = digitalRead(LINE);
//   Serial.println(val);
//   delay(100);
//   run();
// }

// void run() {
//   for (int k = 0; k < 128*2; k++) { // 128 -> 90 do
//       for (int i = 0; i < 4; i++)
//       {
//         digitalWrite(IN1, paso[i][0]);
//         digitalWrite(IN2, paso[i][1]);
//         digitalWrite(IN3, paso[i][2]);
//         digitalWrite(IN4, paso[i][3]);
//         delay(2);
//       }  
//     }
//     delay(1000);
// }

#include <Stepper.h>

const int stepsPerRevolution = 1024*2; // 180 do la 1024
Stepper myStepper = Stepper(stepsPerRevolution, 2, 4, 3, 5);

void setup() {
  myStepper.setSpeed(15);
  
}
void loop() {
  myStepper.step(stepsPerRevolution);
  delay(1000);
  myStepper.step(-1*stepsPerRevolution);
  delay(1000);
}