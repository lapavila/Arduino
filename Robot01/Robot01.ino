#include <Ultrasonic.h>

#define echoPin 13
#define trigPin 12

const int botaoEsquerda = 2;
const int botaoDireita = 4;

int estado = 0;

int motorDireitoPin1 = 5;
int motorDireitoPin2 = 6;

int motorEsquerdoPin1 = 9;
int motorEsquerdoPin2 = 10;

Ultrasonic distancia(12,13);

void setup() {
  //iniciar_Motor();
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  
  pinMode(motorDireitoPin1, OUTPUT);
  pinMode(motorDireitoPin2, OUTPUT);
  
  pinMode(motorEsquerdoPin1, OUTPUT);
  pinMode(motorEsquerdoPin2, OUTPUT);
  
  pinMode(botaoEsquerda, INPUT);
  pinMode(botaoDireita, INPUT);
}

void loop() {
  int dist = ultrasonico();
  
  if (digitalRead(botaoDireita) == HIGH) {
    roboRe();
    delay(600);
    roboReDireita();
    delay(200);
    roboFrente();
  }
  
  if (digitalRead(botaoEsquerda) == HIGH) {
    roboRe();
    delay(600);
    roboReEsquerda();
    delay(200);
    roboFrente();
  } 
  
  if (dist < 15 && dist != 0) {
    roboRe();
    delay(600);
    roboReEsquerda();
    delay(250);
    roboFrente();
  } else {
    roboFrente();
  }
  
}
  
int ultrasonico() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  int cm = (distancia.Ranging(CM));
  Serial.print("Distancia em CM: ");
  Serial.println(cm);
  return cm;
}

void roboFrente() {
  motorDireitoFrente();
  motorEsquerdoFrente();
  delay(50);
}

void roboRe() {
  motorDireitoRe();
  motorEsquerdoRe();
  delay(50);
}

void roboReEsquerda() {
  motorDireitoFrente();
  motorEsquerdoRe();
  delay(50);
}

void roboReDireita() {
  motorEsquerdoFrente();
  motorDireitoRe();
  delay(50);
}

void roboParado() {
  motorDireitoParado();
  motorEsquerdoParado();
  delay(50);
}

void motorDireitoFrente() {
  digitalWrite(motorDireitoPin1, 0);
  digitalWrite(motorDireitoPin2, 1);
}

void motorEsquerdoFrente() {
  digitalWrite(motorEsquerdoPin1, 0);
  digitalWrite(motorEsquerdoPin2, 1);
}

void motorDireitoRe() {
  digitalWrite(motorDireitoPin1, 1);
  digitalWrite(motorDireitoPin2, 0);
}

void motorEsquerdoRe() {
  digitalWrite(motorEsquerdoPin1, 1);
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
