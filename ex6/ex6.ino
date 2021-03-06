#include <Servo.h>

/*
  Example g
   Introduction to Robotics
   by Rodolfo Cossovich at New York University
   Description: This software uses HC-SR04 on pins 13 and 12

   Original code improvements to the Ping sketch sourced from Trollmaker.com . More info at: http://goo.gl/kJ8Gl
   Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
*/

Servo myservo1;
Servo myservo2;

#define trigPin 5
#define echoPin 6

int speedPin_M1 = 5;     //M1 Speed Control
int speedPin_M2 = 6;     //M2 Speed Control
int directionPin_M1 = 4;     //M1 Direction Control
int directionPin_M2 = 7;     //M1 Direction Control



void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {

  int distance = ultraSound();
  if (distance < 10) {  // This is where the LED On/Off happens
    Serial.print("I'm going!");
    digitalWrite (speedPin_M2, HIGH);             //PWM Speed Control
    digitalWrite(directionPin_M1, HIGH);
    digitalWrite (speedPin_M1, HIGH);
    digitalWrite(directionPin_M2, HIGH);

    //sweepServo();
  }
  else {
    Serial.print("measured: ");
    Serial.println(distance);

    digitalWrite (speedPin_M2, LOW);             //PWM Speed Control
    digitalWrite (speedPin_M1, LOW);
  }
  if (distance >= 200 || distance <= 0) {
    Serial.println("Out of range");

  }

  delay(500);
}

void sweepServo( void ) {
  myservo1.attach(10);  // attaches the servo on pin 10 to the servo object
  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  myservo1.detach(); //note that every time I exit the function I also detach the servo
  //so there are no intereferences with the ultrasound sensor
}

void neck( int pos ) {
  myservo2.attach(9);  // attaches the servo on pin 10 to the servo object
  myservo2.write(40 * pos);            // tell servo to go to position in variable 'pos'
  delay(1000);                       // waits 15ms for the servo to reach the position
  myservo2.detach(); //note that every time I exit the function I also detach the servo
  //so there are no intereferences with the ultrasound sensor
}


int ultraSound( void ) {
  long duration;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  long distance = (duration / 2) / 29.1;
  return (int)distance;
}
