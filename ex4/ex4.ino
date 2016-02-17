#define trigPin 5
#define echoPin 6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                         // Sets the baud rate to 9600
  SensorSetup();
  
}

void loop() {
  // put your main code here, to run repeatedly:

   int actualDistance = MeasureDistance();
    Serial.print(actualDistance);
    Serial.println(" cm");
 
  delay(500);
   
  
}
 
void SensorSetup(){ 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
int MeasureDistance(){        // a low pull on pin COMP/TRIG  triggering a sensor reading
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
