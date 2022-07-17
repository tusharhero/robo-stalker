#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

int echoPin = 6; // analog pin for the ultrasonic sensor
int trigPin = 7;

int getDistance() {
  long duration;
  float cm;

  	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

  
  duration = pulseIn(echoPin, HIGH);
  
  Serial.println(duration);
  
  cm = 0.0173*duration;
  
  Serial.println(cm);
  
  delay(10);
  
  return cm;
  
}


void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
    
  pinMode(trigPin, OUTPUT);
  
  pinMode(echoPin, INPUT);
  
}

void loop() {
  getDistance();
  int sensorValue = analogRead(A0);
  int angle = sensorValue * 180.0/1023;
  //Serial.println(angle);
  myservo.write(angle);              // tell servo to go to position in variable 'pos'
  delay(15);                       // waits 15ms for the servo to reach the position                   
}