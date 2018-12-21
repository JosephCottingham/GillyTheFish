#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *Mouth = AFMS.getMotor(1);

int SoundInPin = A0;
int LedPin = 12;

void setup() {
  Serial.begin(9600);
  AFMS.begin();  //1.6KHz
    
  pinMode(SoundInPin, INPUT);
  pinMode(LedPin, OUTPUT);
  
  Mouth->setSpeed(0);
}
void loop() {
  uint8_t i;
  int sensorValue = analogRead(SoundInPin);
  Serial.print(sensorValue);
  int LEDValue = map(sensorValue,0,512,0,255);
  sensorValue = map(sensorValue,0,512,0,180);
  int MoveDelayValue = map(sensorValue,0,255,0,sensorValue);

if (sensorValue > 20) { // set ceiling noise
   delay(1); 
   Mouth->setSpeed(150);
   Mouth->run(FORWARD);
   Serial.print('\n');
  for (i=140; i<255; i++) {
    Mouth->setSpeed(i);
  
  }
  analogWrite(LedPin, sensorValue); 
  Mouth->run(RELEASE);
  delay(1);
} 
      analogWrite(LedPin, 0); 
}
