const int botaoEsquerda = 10;
const int botaoDireita = 9;

void setup() {
  pinMode(botaoEsquerda, INPUT);
  pinMode(botaoDireita, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(botaoEsquerda) == LOW && digitalRead(botaoDireita) == LOW) {
    Serial.println("10 = 0 e 7 = 0");    
  } else if (digitalRead(botaoEsquerda) == HIGH && digitalRead(botaoDireita) == HIGH) {
    Serial.println("10 = 1 e 7 = 1");
  } else if (digitalRead(botaoEsquerda) == HIGH && digitalRead(botaoDireita) == LOW) {
    Serial.println("10 = 1 e 7 = 0");
  } else if (digitalRead(botaoEsquerda) == LOW && digitalRead(botaoDireita) == HIGH) {
    Serial.println("10 = 0 e 7 = 1");
  }
  
  delay(500);
}
