//Include header file for display hardware
#include <LiquidCrystal.h>

//Define Pins
#define tempPin 4
#define lightPin 5

LiquidCrystal lcd(12,11,5,4,3,2);

void setup(){
  lcd.begin(16,2);
}

void loop(){
  int tempReading = analogRead(tempPin);
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );     
  float tempC = tempK - 273.15;            
  float tempF = (tempC * 9.0)/ 5.0 + 32.0; 
  
  // Display weather
  lcd.setCursor(0, 1);
  int light  = analogRead(lightPin);
  if (light > 1000) 
    lcd.print("Weather: Sunny");
  else
    lcd.print("Weather: Cloudy");
  
  lcd.setCursor(0, 0);
  // Display Temperature in F
  lcd.print("Temp:         F  ");
  lcd.setCursor(6, 0);
  lcd.print(tempF);
  
  delay(500);
  lcd.clear();
}

