const int chave = 2;
const int led = 13;

void setup() {
  pinMode(chave, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(chave) == HIGH) {
    Serial.println("Ligado");
  } else {
    Serial.println("Desligado");
  }
  digitalWrite(led, digitalRead(chave));
  delay(1000);
}
