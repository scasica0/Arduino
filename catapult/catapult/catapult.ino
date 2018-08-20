#include <Servo.h>

#define reload 4
#define fire 5
#define readyLED 6
#define waitLED 7
Servo myservo;
int pos = 60;

void setup() {
  myservo.attach(8);
  pinMode(readyLED, OUTPUT);  
  pinMode(waitLED, OUTPUT); 
  pinMode(fire, INPUT);
  pinMode(reload, INPUT);
}

void loop() {
  if (digitalRead(fire) == LOW) {  
    pos = 60;
  }
  if (digitalRead(reload) == LOW) { 
    pos = 0;
  }
  myservo.write(pos); 
  
  if (pos < 60) {
    digitalWrite(waitLED, HIGH);
    digitalWrite(readyLED, LOW);    
  }
  else{
    digitalWrite(readyLED, HIGH);  
    digitalWrite(waitLED, LOW);  
  }
}

