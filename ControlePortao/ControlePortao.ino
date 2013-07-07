void setup() {   
  Serial.begin(9600);  
  pinMode(12, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(9, OUTPUT); 
  pinMode(8, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int entrada = Serial.read();
    if (entrada == 'q') {
      Serial.println("ok");
    } else if (entrada == 'p') {
      Serial.println(digitalRead(2));
    } else {
      entrada = 61 - entrada;
      Serial.println(entrada);
      digitalWrite(entrada, HIGH);
      delay(1000);
      digitalWrite(entrada, LOW);
    }
  }
}
