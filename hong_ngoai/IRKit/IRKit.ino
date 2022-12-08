//#define IR_BIT_LENGTH 32
//#define FirstLastBit 15
//#define BIT_1 1500
//#define BIT_0 450
//#define IR_PIN 3
//#define LED_PIN 13
//#define BIT_START 4000
//
//int debug = 0;
//int output_verify = 0;
//int output_key = 0;
//int remote_verify = 0;
//
//void setup() {
//  pinMode(LED_PIN, OUTPUT);
//  pinMode(IR_PIN, INPUT);
//  digitalWrite(LED_PIN, LOW);
//  Serial.begin(9600);
//}
//
//void loop() {
//  digitalWrite(LED_PIN, HIGH);
//  int key = get_ir_key();
//  digitalWrite(LED_PIN, LOW);
//  do_response(key);
//  delay(100);
//
//}
//
//int get_ir_key() {
//  int pulse[IR_BIT_LENGTH];
//  int bits[IR_BIT_LENGTH];
//  do {} while (pulseIn(IR_PIN, HIGH) < BIT_START);
//  read_pulse(pulse);
//  pulse_to_bits(pulse, bits);
//  RemoteVerify(bits);
//  return bits_to_int(bits);
//}
//
//void read_pulse(int pulse[]) {
//  for (int i = 0; i < IR_BIT_LENGTH; i++) {
//    pulse[i] = pulseIn(IR_PIN, HIGH);
//  }
//}
//void pulse_to_bits (int pulse[], int bits[]) {
//  if (debug) {
//      Serial.print("------");
//    }
//  for (int i = 0; i < IR_BIT_LENGTH; i++) {
//    if (debug) {
//      Serial.print(pulse[i]);
//    }
//    if (pulse[i] > BIT_1) {
//      bits[i] = 1;
//    } else if (pulse[i] > BIT_0) {
//      bits[i] = 0;
//    } else {
//      Serial.println("Error: pulse too short");
//    }
//  }
//}
//
//void RemoteVerify(int bits[]) {
//  int result = 0;
//  int seed = 1;
//  for (int i = 0; i < FirstLastBit; i++) {
//    result += bits[i] * seed;
//    seed *= 2;
//  }
//  if (output_verify) {
//    Serial.print("Remote: ");
//    Serial.print(result);
//    Serial.println(" verification code");
//  }
//  if (remote_verify != result) {
//    delay(60);
//    get_ir_key();
//  }
//}
//
//int bits_to_int (int bits[]) {
//  int result = 0;
//  int seed = 1;
//  for (int i = FirstLastBit; i < IR_BIT_LENGTH; i++) {
//    if (bits[i] == 1) {
//      result += seed;
//    }
//    seed *= 2;
//  }
//
//  return result;
//}
//void do_response(int key) {
//  if (output_key) {
//    Serial.print("Key: ");
//    Serial.println(key);
//  }
//  switch(key) {
//    case 32640:
//      Serial.println("Power");
//      break;
//    case 32385:
//      Serial.println("Func/Stop");
//      break;
//    case 32130:
//      Serial.println("|<<");
//      break;
//    case 32002:
//      Serial.println(">||");
//      break;
//    case 31875:
//      Serial.println(">>|");
//      break;
//    case 32512:
//      Serial.println("VOL+");
//      break;
//    case 31492:
//      Serial.println("VOL-");
//      break;
//    case 31620:
//      Serial.println("v");
//      break;
//    case 31365:
//      Serial.println("^");
//      break;
//    case 30982:
//      Serial.println("EQ");
//      break;
//    case 30855:
//      Serial.println("ST/REPT");
//      break;
//    case 31110:
//      Serial.println("0");
//      break;
//    case 30600:
//      Serial.println("1");
//      break;
//    case 30472:
//      Serial.println("2");
//      break;
//    case 30345:
//      Serial.println("3");
//      break;
//    case 30090:
//      Serial.println("4");
//      break;
//    case 29962:
//      Serial.println("5");
//      break;
//    case 29835:
//      Serial.println("6");
//      break;
//    case 29580:
//      Serial.println("7");
//      break;
//    case 29452:
//      Serial.println("8");
//      break;
//    case 29325:
//      Serial.println("9");
//      break;
//    default: {
//      Serial.print("Unknown key: ");
//      Serial.println(key);
//      break;
//    }
//  }
//}


#define IR_BIT_LENGTH 32
#define FirstLastBit 15
#define BIT_1 1500
#define BIT_0 450
#define BIT_START 4000
#define IR_Pin 8
#define LED_Pin 13

int debug = 0;
int output_verify = 0;
int output_key = 0;
int remote_verify = 16128;

void setup()
{
    pinMode(LED_Pin, OUTPUT);
    pinMode(IR_Pin, INPUT);
    digitalWrite(LED_Pin, LOW);
    Serial.begin(9600);
}

void loop()
{
    digitalWrite(LED_Pin, HIGH);
    int key = get_ir_key();
    digitalWrite(LED_Pin, LOW);
    do_response(key);
    delay(130);
}

int get_ir_key()
{
    int pulse[IR_BIT_LENGTH];
    int bits[IR_BIT_LENGTH];

    do
    {
    } while (pulseIn(IR_Pin, HIGH) < BIT_START);

    read_pulse(pulse);
    pulse_to_bits(pulse, bits);
    RemoteVerify(bits);
    return bits_to_int(bits);
}

void read_pulse(int pulse[])
{
    for (int i = 0; i < IR_BIT_LENGTH; i++)
    {
        pulse[i] = pulseIn(IR_Pin, HIGH);
    }
}

void pulse_to_bits(int pulse[], int bits[])
{
    if (debug)
    {
        Serial.println("-----");
    }

    for (int i = 0; i < IR_BIT_LENGTH; i++)
    {
        if (debug)
        {
            Serial.println(pulse[i]);
        }

        if (pulse[i] > BIT_1)
        {
            bits[i] = 1;
        }
        else if (pulse[i] > BIT_0)
        {
            bits[i] = 0;
        }
        else
        {
            Serial.println("ERROR");
        }
    }
}

void RemoteVerify(int bits[])
{
    int result = 0;
    int seed = 1;

    for (int i = 0; i < (FirstLastBit); i++)
    {
        if (bits[i] == 1)
        {
            result += seed;
        }

        seed *= 2;
    }

    if (output_verify)
    {
        Serial.print("Remote ");
        Serial.print(result);
        Serial.println(" verification code");
    }

    if (remote_verify != result)
    {
        delay(60);
        get_ir_key();
    }
}

int bits_to_int(int bits[])
{
    int result = 0;
    int seed = 1;

    for (int i = (IR_BIT_LENGTH - FirstLastBit); i < IR_BIT_LENGTH; i++)
    {
        if (bits[i] == 1)
        {
            result += seed;
        }
        seed *= 2;
    }
    return result;
}

void do_response(int key)
{
    if (output_key)
    {
        Serial.print("Key ");
        Serial.println(key);
    }

    switch (key)
    {
    case 32640:
        Serial.println("POWER");
        break;
    case 32385:
        Serial.println("FUNC/STOP");
        break;
    case 32130:
        Serial.println("|<<");
        break;
    case 32002:
        Serial.println(">||");
        break;
    case 31875:
        Serial.println(">>|");
        break;
    case 32512:
        Serial.println("VOL+");
        break;
    case 31492:
        Serial.println("VOL-");
        break;
    case 31620:
        Serial.println("v");
        break;
    case 31365:
        Serial.println("^");
        break;
    case 30982:
        Serial.println("EQ");
        break;
    case 30855:
        Serial.println("ST/REPT");
        break;
    case 31110:
        Serial.println("0");
        break;
    case 30600:
        Serial.println("1");
        break;
    case 30472:
        Serial.println("2");
        break;
    default:
        break;
    }
}
