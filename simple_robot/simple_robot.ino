#define touchpin 9 // sets the capactitive touch sensor @pin 4
int ledPin = 4; // sets the LED @pin 2
#define echoPin 2
#define trigPin 3

#include <Servo.h>
Servo servo;

long duration; 
int direction = 0;
int angle = 0;
int distance = 0;
unsigned long lastTime;
unsigned long lastPrintTime = 0;


void setup() {
  pinMode(touchpin, INPUT); //sets the touch sensor as input
  pinMode(ledPin, OUTPUT);  //sets the led as output
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  servo.attach(7);
  Serial.begin(115200);
  
}
void loop() {
  int touchValue = digitalRead(touchpin); //reads the touch sensor signal
  if (touchValue == HIGH){      //if sensor is HIGH
    digitalWrite(ledPin, HIGH);   //LED will turn ON
  }
  else{       //otherwise
    digitalWrite(ledPin,LOW); //LED is turned OFF
  } 
  delay(100);   //delay of 300milliseconds
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 2500);

 if(duration != 0 && duration > 500) { 
    for(angle = 0; angle < 120; angle++)  
  {                                  
    servo.write(angle);               
    delay(5);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 120; angle > 0; angle--)    
  {                                
    servo.write(angle);           
    delay(5);       
  } 
 }

}
