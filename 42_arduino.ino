
#include <Servo.h>
#define FORCE_SENSOR_PIN A0
Servo myservo;

int pos = 82;
float maxSSpeed = 32;//32;
float minSSpeed = 82;
float incomingByte = 0;
float diff = minSSpeed - maxSSpeed;
int starterPin = 6;
float sub;
float calSpeed;

void setup() {
  pinMode(starterPin, OUTPUT);
  myservo.attach(9);  
  Serial.begin(115200);
  myservo.write(pos);
  delay(500);
  (starterPin, HIGH);
}

void loop()
{
  int analogReading = analogRead(FORCE_SENSOR_PIN);
  if (analogReading > 90) {
    digitalWrite(starterPin, HIGH);

  } else {
    digitalWrite(starterPin, LOW);
  }
  if (Serial.available() > 0) {

    incomingByte = Serial.parseInt();
    if (incomingByte == 1 && pos >= maxSSpeed) { // accelerating
      pos -= 1;
    } else if (incomingByte == 2 && pos <= minSSpeed) { // not accelerating
      pos += 1;
    }

  }
   myservo.write(pos);
   delay(3);
}
