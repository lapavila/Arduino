int led = 12;
int entrada = 0;
boolean initiated = false;
void setup() {   
  Serial.begin(9600);  
  pinMode(led, OUTPUT);     
}

void loop() {
  if (!initiated) {
    digitalWrite(led, HIGH);
    initiated = true;
  }
  if (Serial.available() > 0) {
    entrada = Serial.read();
    if (entrada == 'l') {
      Serial.println("Liga Lampada");
      digitalWrite(led, LOW);
    } else {
      Serial.println("Desliga Lampada");
      digitalWrite(led, HIGH);
    }
  }
}


