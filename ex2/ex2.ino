
int speedPin_M1 = 5;     //M1 Speed Control
int speedPin_M2 = 6;     //M2 Speed Control
int directionPin_M1 = 4;     //M1 Direction Control
int directionPin_M2 = 7;     //M1 Direction Control

void setup() {                               // Serial initialization

}

void loop() {
  digitalWrite (speedPin_M2, HIGH);             //PWM Speed Control
  digitalWrite(directionPin_M1, HIGH);
  digitalWrite (speedPin_M1, HIGH);
  digitalWrite(directionPin_M2, HIGH);

  delay(1000); //WAITS FOR 1 SECOND

  digitalWrite (speedPin_M2, LOW);             //PWM Speed Control
  digitalWrite(directionPin_M1, HIGH);
  digitalWrite (speedPin_M1, LOW);
  digitalWrite(directionPin_M2, HIGH);

  delay(1000);

}

