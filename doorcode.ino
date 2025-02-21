// defines pins numbers
#include <Servo.h>

Servo servoBase;
const int buzzer = 8;
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;
int 

// defines variables
long duration;
int distance;
int safetyDistance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
servoBase.attach(A1);//Pin a utilizar para servo
servoBase.write(0);
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 8){
  for(int i=0; i<=180; i=i+10)
  {
   servoBase.write(i);
   delay(200);
  }
  tone(buzzer, 1000);
  digitalWrite(ledPin, HIGH);
}
else if (safetyDistance <= 20 & safetyDistance > 8){ 
	for(int i=0; i<=180; i=i+10)
  {
   servoBase.write(i);
   delay(200);
  }
}
else{
  noTone(buzzer);
  digitalWrite(ledPin, LOW);
  
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}