#include <Ultrasonic.h>

#define echoPin 13
#define trigPin 12

const int botaoEsquerda = 8;
const int botaoDireita = 4;

int motorDireitoPin1 = 5;
int motorDireitoPin2 = 6;

int motorEsquerdoPin1 = 9;
int motorEsquerdoPin2 = 10;

int ldr = 0;

Ultrasonic distancia(12,13);

void setup() {
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
 
  if (digitalRead(botaoDireita) == HIGH) {
    Serial.println("Colisao laterial Direita");
    roboReDireita();
    delay(125);
    roboFrente();
  }
  
  if (digitalRead(botaoEsquerda) == HIGH) {
    Serial.println("Colisao laterial Esquerda");
    roboReEsquerda();
    delay(125);
    roboFrente();
  } 

  if (leLuminosidade() < 200) {
    Serial.println("Luninosidade baixa detectada");
    Serial.println("Afastando do escuro...");
      roboRe();
      delay(1000);
    while(leLuminosidade() < 200) {
      roboReDireita();
    }
    roboReDireita();
    delay(100);
    roboFrente();
  }

  int dist = leDistancia();
  if (dist < 15 && dist != 0) {
    Serial.println("Obstaculo detectado");
    while(leDistancia() < 20) {
      Serial.println("afastando do Obstaculo pela esquerda...");
      roboRe();
    }
    roboReEsquerda();
    delay(100);
    roboFrente();
  } else {
    roboFrente();
  }
}

int leLuminosidade() {
  int lum = analogRead(ldr);
//  Serial.print("Luminosidade: ");
//  Serial.println(lum);
  return lum;
}
  
int leDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  int cm = (distancia.Ranging(CM));
//  Serial.print("Distancia em CM: ");
//  Serial.println(cm);
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
