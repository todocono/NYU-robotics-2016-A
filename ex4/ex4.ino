
int URPWM = 3; // PWM Output 0－25000US，Every 50US represent 1cm
int URTRIG= 10; // PWM trigger pin
  


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
  pinMode(URTRIG,OUTPUT);                     // A low pull on pin COMP/TRIG
  digitalWrite(URTRIG,HIGH);                  // Set to HIGH 
  pinMode(URPWM, INPUT);                      // Sending Enable PWM mode command
  
}
 
int MeasureDistance(){        // a low pull on pin COMP/TRIG  triggering a sensor reading
    digitalWrite(URTRIG, LOW);
    digitalWrite(URTRIG, HIGH);               // reading Pin PWM will output pulses    
    unsigned long distance=pulseIn(URPWM,LOW);    
    if(distance==50000){              // the reading is invalid.
      Serial.print("Invalid");    
    }else{
      distance=distance/50;           // every 50us low level stands for 1cm
    }
    return distance;
}
