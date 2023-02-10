#define touchpin 9 // sets the capactitive touch sensor @pin 4
#define echoPin 2
#define trigPin 3
int ledPin = 4; // sets the LED @pin 2


#include <Servo.h>
Servo myServo;

long duration; 
int position = 0;
int direction = 0;
unsigned long lastTime;
unsigned long lastPrintTime = 0;



void setup() {
  pinMode(touchpin, INPUT); //sets the touch sensor as input
  pinMode(ledPin, OUTPUT);  //sets the led as output
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  myServo.attach(7);
  Serial.begin(9600);
}
void loop() {
  int touchValue = digitalRead(touchpin); //reads the touch sensor signal
  if (touchValue == HIGH) {     //if sensor is HIGH
    digitalWrite(ledPin, HIGH);   //LED will turn ON
  }
  else {      //otherwise
    digitalWrite(ledPin, LOW); //LED is turned OFF
  }
  delay(300);   //delay of 300milliseconds

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 2500);

  Serial.println(duration);
  
  if(duration != 0 && duration > 500) { 
      lastTime = millis(); 
    }


    if(millis() - lastTime < 400) {
        if (position != 120 && direction == 0) {
        myServo.write(position);
        position ++;
      }
      if (position == 120) {
        direction = 1;
      }
      if (position != 0 && direction == 1) {
        myServo.write(position);
        position--;
      }
      if (position == 0) {
        direction = 0;
      }
    }
}
