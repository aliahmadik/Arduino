/*Load Necessary Library */
#include <IRremote.h>

/* remote control consists of several keys that each of which posses a specific hex digits. We choose three of them */
#define button_1 3877175040 // forward key
#define button_2 2907897600 // backward key
#define button_3 3860463360 // 0 key

// receiver is the pin we use to connect IR sensor to Arudino Board
const int receiver = 7;
uint32_t Previous;

//irrecv is the object of IR REMOTE
IRrecv irrecv(receiver);

//enA,in1,in2 are three pin we use to connect motor
int enA = 10;
int in1 = 9;
int in2 = 8;
int motorspeed = 100 ;

// trigpin and echopin are used to connect Ultrasonic Sensor
int trigpin = 4;
int echopin = 5;

// if the motor want to move backward the rear led is turned on.
int rear = 2; 

// if the ultrasonic detect an obstacle , the led is turned on
int obstacle = 3; 

//duration and cm are two variables used to measure the distance
unsigned long duration, cm;
bool guard = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(obstacle, OUTPUT);
  pinMode(rear, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Ultrasonic_Pulse_Producer();
  duration = pulseIn(echopin, HIGH);
  cm = Micro_to_cm(duration);
  Serial.print("cm = ");
  Serial.println(cm);
  if ( cm < 20 ) { // it means an obstacle is detected and the motor is turned off and the obstacle light turned on
    guard = true;
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(enA, 0);
    digitalWrite(obstacle, HIGH);
  }
  else {
    digitalWrite(obstacle, LOW);
    guard = false;
  }
  if (irrecv.decode()) {
    
    Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
    digitalWrite(rear, LOW);
    switch (irrecv.decodedIRData.decodedRawData) {
      case button_1: // go forward
        if (guard == false) {
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
          analogWrite(enA, motorspeed);
        }
        break;

      case button_2: // go backward
        if (guard == false) {
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          analogWrite(enA, motorspeed);
          digitalWrite(rear, HIGH);
        }
        break;
      case button_3: // motors shutdown
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(enA, 0);
        break;
    }
    Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
    irrecv.resume(); //next value
  }
  delay(1000);
}

void Ultrasonic_Pulse_Producer() { // create signal for ultrasonic sensor
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
}
unsigned long Micro_to_cm(int micro) { // scale the ultrasonic sensor value into cm
  return (micro / 58);
}
