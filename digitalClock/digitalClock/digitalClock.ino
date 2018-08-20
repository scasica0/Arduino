//Include header file for display hardware
#include <LiquidCrystal.h>

//Define Pins
#define setHour 8
#define setMinute 9

LiquidCrystal lcd(12,11,5,4,3,2);
int hours = 12;
int minutes = 0;
int seconds = 0;
int militaryTime = 0;
bool morning = true;
//change “military” to true if you want a 24 hour format
bool military = false;

void setup(){
  lcd.begin(16,2);
}
void loop(){
   lcd.setCursor(0,0);
   seconds += 1;
   if (military) lcd.print(militaryTime);
   else {
     if (hours < 10)lcd.print ("0");
     lcd.print(hours);
   }
   lcd.print(":");
   if (minutes < 10)lcd.print ("0");
   lcd.print(minutes);
   lcd.print(":");
   if (seconds < 10)lcd.print ("0");
   lcd.print(seconds);
   if (morning) lcd.print("AM");
   else lcd.print("PM");
   delay(1000);
   checkTimeFormat();
   
   //Set HOUR & Minutes
   if (digitalRead(setHour) == HIGH) {  
    hours += 1;
    militaryTime += 1;
    checkTimeFormat();
   }
   if (digitalRead(setMinute) == HIGH) { 
    seconds = 0;
    minutes += 1;
    checkTimeFormat();
   }
}
void checkTimeFormat (){
   if(seconds == 60){
    seconds = 0;
    minutes += 1;
   }
   if(minutes==60){
    minutes = 0;
    hours += 1;
    militaryTime += 1;
   }
   if(hours==13){
    hours = 1;
   }
   if (militaryTime < 12){
    morning = true;
   }
   else{
    morning = false;
   }
}

