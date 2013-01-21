#include <Ultrasonic.h>

#define trigPin 12
#define echoPin 13

#define motorDireitoPin1 5
#define motorDireitoPin2 6

#define motorEsquerdoPin1 9
#define motorEsquerdoPin2 10

#define ledPin 11

#define ldrPin 0

//#define rightButton 7
//#define leftButton 8

//#define rightIr 2
//#define leftIr 3

int theBegin = true;
const int velocityFactorLeft = 160;
const int velocityFactorRight = 190;

const int backwardTime = 700;

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
  
//  pinMode(rightIr, INPUT); 
//  pinMode(leftIr, INPUT);
}

void loop() {
  if (theBegin) {
    blinkLed(10);
    robotForward();
    theBegin = false;
    digitalWrite(ledPin, HIGH);
  }
  
  verifyDistance();
  
  //verifyColision();
  
  //verifyLuminosity();
  
  digitalWrite(ledPin, HIGH);
}

////////////////////////
////////////////////////
void verifyDistance() {
  int distance = readDistance();
  Serial.print("Distancia: ");
  Serial.println(distance);
  if (distance < 20 && distance != 0) {
    robotBackward(backwardTime);
    robotLeft();
    blinkLed(10);
    robotForward();
  }
}

////////////////////////
////////////////////////
void verifyColision() {
  if (isRightColision()) {
    Serial.println("Colisao laterial Direita");
    robotBackward(backwardTime);
    robotLeft();
    blinkLed(10);
    robotForward();
  }
  
  if (isLeftColision()) {
    Serial.println("Colisao laterial Esquerda");
    robotBackward(backwardTime);
    robotRight();
    blinkLed(10);
    robotForward();
  }
}

////////////////////////
////////////////////////
void verifyLuminosity() {
  if (readLuminosity() < 200) {
    robotBackward(backwardTime);
    blinkLed(10);
    digitalWrite(ledPin, HIGH);
    while(readLuminosity() < 200) {
      roboReDireita();
    }
    roboReDireita();
    delay(250);
    robotForward();
  }
}
  
int readDistance() {
  int cm = ultrassonic.Ranging(CM);
  Serial.print("Distance: ");
  Serial.println(cm);
  return cm;
}

int readIr(int theIr) {
  int ir = analogRead(theIr); 
  int BR = map(ir, 0, 1023, 300, 0);
  return BR;
}

boolean isButtonClicked(int theButton) {
  return digitalRead(theButton) == LOW;
}

int readLuminosity() {
  int lum = analogRead(ldrPin);
  return lum;
}

boolean isRightColision() {
  return (isButtonClicked(rightButton));
}

boolean isLeftColision() {
  return (isButtonClicked(leftButton));
}

void blinkLed(int cicles) {
  for (int i = 0; i < cicles; i++) {
    digitalWrite(ledPin, HIGH);
    delay(25);
    digitalWrite(ledPin, LOW);
    delay(25);
  }
}

void robotForward() {
  motorDireitoFrente();
  motorEsquerdoFrente();
}

void robotBackward(int time) {
  robotStop(500);
  motorDireitoRe();
  motorEsquerdoRe();
  delay(time);
}

void robotStop(int timeToStop) {
  motorDireitoParado();
  motorEsquerdoParado();
  if (timeToStop > 0) {
    delay(timeToStop);
  }
}

void robotLeft() {
  motorDireitoFrente();
  motorEsquerdoParado();
}

void robotRight() {
  motorEsquerdoFrente();
  motorDireitoParado();
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
  analogWrite(motorDireitoPin1, 0);
  analogWrite(motorDireitoPin2, velocityFactorRight);
}

void motorEsquerdoFrente() {
  analogWrite(motorEsquerdoPin1, 0);
  analogWrite(motorEsquerdoPin2, velocityFactorLeft);
}

void motorDireitoRe() {
  analogWrite(motorDireitoPin1, velocityFactorRight);
  analogWrite(motorDireitoPin2, 0);
}

void motorEsquerdoRe() {
  analogWrite(motorEsquerdoPin1, velocityFactorLeft);
  analogWrite(motorEsquerdoPin2, 0);
}

void motorDireitoParado() {
  analogWrite(motorDireitoPin1, 0);
  analogWrite(motorDireitoPin2, 0);
}

void motorEsquerdoParado() {
  analogWrite(motorEsquerdoPin1, 0);
  analogWrite(motorEsquerdoPin2, 0);
}
