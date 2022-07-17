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

int findIndex(float arr[], int n, float target)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

float getMin(float arr[], int n)
{
    int res = arr[0];
  	int i;
    for (i = 1; i < n; i++)
        res = min(res, arr[i]);
  	int m = sizeof(arr) / sizeof(*arr);
    int index = findIndex(arr, m, res);
    return index;
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
  float measurements[180];
  float imeasurements[180];
  //int angle = sensorValue * 180.0/1023;
  for (int i = 0; i <= 180; i++) {
  // statement(s);
    myservo.write(i);
    measurements[i] = getDistance();
    
}
  float min = getMin(measurements,180);
  Serial.println(min);
  
  for (int ci = min-20; ci <= min-20; ci++){
    myservo.write(ci);
    imeasurements[ci] = getDistance();
    
  }
  //for refined in range(min-20, min-20, 5):
  //servo.setPos(refined)
  //improved_measurement[refined] = sensor.getDistance()
  
  
  //myservo.write(angle);              // tell servo to go to position in variable 'pos'
  delay(15);                       // waits 15ms for the servo to reach the position                   
}