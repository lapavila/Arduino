#define led 11
#define red 2

void setup() {
  pinMode(red,INPUT); 
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}


void loop() {
  int ir = analogRead(red); 
  int BR = map(ir,0,800,300,0);
  digitalWrite(led,HIGH);
  delay(BR);
  digitalWrite(led,LOW);
  delay(BR);
  Serial.print("==> ");
  Serial.println(BR);
}
