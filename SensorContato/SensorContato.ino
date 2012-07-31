const int botaoEsquerda = 2;
const int botaoDireita = 4;

const int ledEsquerda = 12;
const int ledDireita = 13;

void setup() {
  pinMode(botaoEsquerda, INPUT);
  pinMode(botaoDireita, INPUT);
  
  pinMode(ledEsquerda, OUTPUT);
  pinMode(ledDireita, OUTPUT);
}

void loop() {
  if (digitalRead(botaoEsquerda) == LOW && digitalRead(botaoDireita) == LOW) {
    digitalWrite(ledDireita, LOW);
    digitalWrite(ledEsquerda, LOW);
  } else if (digitalRead(botaoEsquerda) == HIGH && digitalRead(botaoDireita) == HIGH) {
    digitalWrite(ledDireita, HIGH);
    digitalWrite(ledEsquerda, HIGH);
  } else if (digitalRead(botaoEsquerda) == HIGH && digitalRead(botaoDireita) == LOW) {
    digitalWrite(ledDireita, LOW);
    digitalWrite(ledEsquerda, HIGH);
  } else if (digitalRead(botaoEsquerda) == LOW && digitalRead(botaoDireita) == HIGH) {
    digitalWrite(ledDireita, HIGH);
    digitalWrite(ledEsquerda, LOW);
  }
}
