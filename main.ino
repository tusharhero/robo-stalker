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
  
  //Serial.println(duration);
  
  cm = 0.0173*duration;
  Serial.println("duration");
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
  //getDistance();
  int sensorValue = analogRead(A0);
uint16_t min_dist = 65535;
uint8_t min_angle = 0;
for (uint8_t i = 0; i < 180; i+=9) { // do 20 sectors
  myservo.write(i);
  delay(500);
  uint16_t dist = getDistance();
  if (dist < min_dist) {
    min_dist = dist;
    min_angle = i;
  }
}
  // float min = getMin(measurements,180);

  
  myservo.write(min_angle);
  delay(500);
  while (getDistance() <= min_dist){
    delay(25);
  }
  
  //for refined in range(min-20, min-20, 5):
  //servo.setPos(refined)
  //improved_measurement[refined] = sensor.getDistance()
  
  
  //myservo.write(angle);              // tell servo to go to position in variable 'pos'
  delay(15);                       // waits 15ms for the servo to reach the position                   
}