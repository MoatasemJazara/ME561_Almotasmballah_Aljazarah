const int trigPin = 7;
const int echoPin = 6;
#include <Servo.h>
Servo testservo;
int pos = 0;

void setup() {
  Serial.begin (9600);
  testservo.attach(5);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance <= 10) 
  {
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
   testservo.write(pos);
  
    delay(15);
    
    }
    }
  else {
    
     testservo.write(pos);
    delay(15);
  }
  }
