
#include <IRremote.h>

#define ENABLE 5
#define FORWARD 3
#define REVERSE 4
#define IR 8

IRrecv irrecv(IR);
decode_results results; 
bool power = false;

void setup() {
  //---set pin direction
  Serial.begin(9600);
  pinMode(ENABLE,OUTPUT);
  pinMode(FORWARD,OUTPUT);
  pinMode(REVERSE,OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if(results.value == 0xFFA25D){
      //Turn off
      if (power) { 
        power = false;
        digitalWrite(ENABLE,LOW); 
      }
      //Turn On
      else {
        power = true;
        digitalWrite(ENABLE,HIGH);
          digitalWrite(FORWARD,HIGH);
          digitalWrite(REVERSE,LOW);
        }
      }
    irrecv.resume();
    } 
}

   
