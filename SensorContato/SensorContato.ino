const int botaoEsquerda = 8;
const int botaoDireita = 7;

void setup() {
  pinMode(botaoEsquerda, INPUT);
  pinMode(botaoDireita, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(botaoEsquerda) == LOW && digitalRead(botaoDireita) == LOW) {
    
  } else if (digitalRead(botaoEsquerda) == HIGH && digitalRead(botaoDireita) == HIGH) {
    Serial.println("botaoEsquerda + botaoDireita");
  } else if (digitalRead(botaoEsquerda) == HIGH && digitalRead(botaoDireita) == LOW) {
    Serial.println("botaoEsquerda");
  } else if (digitalRead(botaoEsquerda) == LOW && digitalRead(botaoDireita) == HIGH) {
    Serial.println("botaoDireita");
  }
}
