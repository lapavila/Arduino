#include <Ultrasonic.h>

#define trigPin 11
#define echoPin 12
#define lightPin 8

Ultrasonic ultrassonic(trigPin, echoPin);

void setup() {
  Serial.begin(9600);
  pinMode(lightPin, OUTPUT);
}

void loop() {
  int cm = ultrassonic.Ranging(CM);
  Serial.print("Distance: ");
  Serial.println(cm);
  Serial.print("Distancia: ");
  Serial.println(cm);
  if (cm < 4) {
    digitalWrite(lightPin, LOW);
  } else {
    digitalWrite(lightPin, HIGH);
  }
  delay(250);
}
