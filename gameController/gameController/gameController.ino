
const int switchPin = 2;
const int xPin = 0;
const int yPin = 1; 

void setup() {
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(switchPin) == 0) {
    Serial.println("button");
  }
  if (analogRead(xPin) < 300){ //LEFT
    Serial.println("left");
  }
  if (analogRead(xPin) > 700){ //RIGHT
    Serial.println("right");
  }
  if (analogRead(yPin) < 300){ //UP
    Serial.println("1");
  }
  if (analogRead(yPin) > 700){ //DOWN
    Serial.println("2");
  }
  delay(400);
}
