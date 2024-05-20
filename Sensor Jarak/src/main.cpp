#include <Arduino.h>

int trigPin = D1; 
int echoPin = D0;
int led = D2;

long duration;
int distance;

void setup(){
  pinMode (led, OUTPUT);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = 0.034 * duration / 2;
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance <= 10){
      digitalWrite(led, HIGH);
    }else{
      digitalWrite(led, LOW);
     }

  delay(1000);
}