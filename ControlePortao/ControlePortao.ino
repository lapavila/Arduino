int portao = 12;
int entrada = 0;

void setup() {   
  Serial.begin(9600);  
  pinMode(portao, OUTPUT);     
}

void loop() {
  if (Serial.available() > 0) {
    entrada = Serial.read();
    if (entrada == 'p') {
      digitalWrite(portao, HIGH);
      delay(400);
      digitalWrite(portao, LOW);
    }
  }
}

