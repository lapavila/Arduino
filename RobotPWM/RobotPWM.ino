#include <Ultrasonic.h>

#define trigPin 12
#define echoPin 13

#define motorDireitoPin1 5
#define motorDireitoPin2 6

#define motorEsquerdoPin1 9
#define motorEsquerdoPin2 10

#define ledPin 8

#define ldrPin 0

#define rightButton 2
#define leftButton 4

int theBegin = true;
const int velocityFactorLeft = 160;
const int velocityFactorRight = 190;

Ultrasonic ultrassonic(trigPin, echoPin);

void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  
  pinMode(motorDireitoPin1, OUTPUT);
  pinMode(motorDireitoPin2, OUTPUT);
  
  pinMode(motorEsquerdoPin1, OUTPUT);
  pinMode(motorEsquerdoPin2, OUTPUT);
  
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (theBegin) {
    blinkLed(10);
    robotForward();
    theBegin = false;
    digitalWrite(ledPin, HIGH);
  }
  
  if (isRightColision()) {
    Serial.println("Colisao laterial Direita");
    robotBackward();
    blinkLed(5);
    roboReEsquerda();
    delay(250);
    robotForward();
  }
  
  if (isLeftColision()) {
    Serial.println("Colisao laterial Direita");
    robotBackward();
    blinkLed(5);
    roboReDireita();
    delay(250);
    robotForward();
  }
  
  int distance = readDistance();
  if (distance < 10 && distance != 0) {
    robotBackward();
    while(readDistance() < 20) {
      //do nothing
    }
    roboReEsquerda();
    delay(250);
    robotForward();
  }
  
  if (readLuminosity() < 200) {
    robotBackward();
    blinkLed(10);
    digitalWrite(ledPin, HIGH);
    while(readLuminosity() < 200) {
      roboReDireita();
    }
    roboReDireita();
    delay(250);
    robotForward();
  }
  digitalWrite(ledPin, HIGH);
}
  
int readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  int cm = (ultrassonic.Ranging(CM));
  return cm;
}

int readLuminosity() {
  int lum = analogRead(ldrPin);
  return lum;
}

boolean isRightColision() {
  return digitalRead(rightButton) == HIGH;
}

boolean isLeftColision() {
  return digitalRead(leftButton) == HIGH;
}

void blinkLed(int cicles) {
  for (int i = 0; i < cicles; i++) {
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW);
    delay(50);
  }
}

void robotForward() {
  robotStop();
  delay(10);
  motorDireitoFrente();
  motorEsquerdoFrente();
}

void robotBackward() {
  robotStop();
  delay(10);
  motorDireitoRe();
  motorEsquerdoRe();
}

void robotStop() {
  motorDireitoParado();
  motorEsquerdoParado();
}

void roboReEsquerda() {
  motorDireitoFrente();
  motorEsquerdoRe();
}

void roboReDireita() {
  motorEsquerdoFrente();
  motorDireitoRe();
}

void motorDireitoFrente() {
  digitalWrite(motorDireitoPin1, 0);
  analogWrite(motorDireitoPin2, velocityFactorRight);
}

void motorEsquerdoFrente() {
  digitalWrite(motorEsquerdoPin1, 0);
  analogWrite(motorEsquerdoPin2, velocityFactorLeft);
}

void motorDireitoRe() {
  analogWrite(motorDireitoPin1, velocityFactorRight);
  digitalWrite(motorDireitoPin2, 0);
}

void motorEsquerdoRe() {
  analogWrite(motorEsquerdoPin1, velocityFactorLeft);
  digitalWrite(motorEsquerdoPin2, 0);
}

void motorDireitoParado() {
  digitalWrite(motorDireitoPin1, 0);
  digitalWrite(motorDireitoPin2, 0);
}

void motorEsquerdoParado() {
  digitalWrite(motorEsquerdoPin1, 0);
  digitalWrite(motorEsquerdoPin2, 0);
}
