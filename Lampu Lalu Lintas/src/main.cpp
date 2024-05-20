#include <Arduino.h>

int redLED = D2;
int yellowLED = D1;
int greenLED = D0;

void setup() {
  pinMode(redLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
}

void loop() {
  digitalWrite(redLED,HIGH);
  digitalWrite(yellowLED,LOW);
  digitalWrite(greenLED,LOW);
  delay(5000);

  digitalWrite(redLED,LOW);
  digitalWrite(yellowLED,LOW);
  digitalWrite(greenLED,HIGH);
  delay(1000);

  digitalWrite(redLED,LOW);
  digitalWrite(yellowLED,LOW);
  digitalWrite(greenLED,HIGH);
  delay(3000);
}

