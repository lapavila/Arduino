void setup() {   
  Serial.begin(9600);  
  pinMode(12, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(9, OUTPUT); 
  pinMode(8, OUTPUT); 
}

void loop() {
  if (Serial.available() > 0) {
    int entrada = 61 - Serial.read();
    Serial.println(entrada);
    digitalWrite(entrada, HIGH);
    delay(400);
    digitalWrite(entrada, LOW);
  }
}
