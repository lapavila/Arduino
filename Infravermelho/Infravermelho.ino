/*
Programa desenvolvido por: 
Gamesh_
Leandro Mota
Dia: 08/07/2011
http://brasilrobotics.blogspot.com/

Descição: 
Faz um led piscar com a proximidade de um objeto.
OBS: É permitido o uso e modificação deste código se refenrenciado. 
*/
void setup() {
  pinMode(0,INPUT); 
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ir = analogRead(0); 
  digitalWrite(13,HIGH);
  delay(ir);
  digitalWrite(13,LOW);
  delay(ir);
  Serial.print("Distancia: ");
  Serial.println(ir);
}
