void setup()
{
  char temp;
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  
  while(1)
  {
    if (Serial.available() > 0 )
    {
      temp = Serial.read();
      if(temp == '1')
        digitalWrite(13,HIGH);
      if(temp == '0')
        digitalWrite(13,LOW);
      Serial.print(temp);
    }
  }
}

void loop()
{

}
