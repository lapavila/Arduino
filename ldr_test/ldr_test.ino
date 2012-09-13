int ldr = 0;             //analog pin to which LDR is connected
int ldr_value = 0;        //variable to store LDR values

void setup()
{
  Serial.begin(9600);   //start te serial monitor
}

void loop()
{
  ldr_value = analogRead(ldr);          //reads the LDR values
  Serial.println(ldr_value);                 //prints the LDR values to serial monitor
  delay(500);                  //wait
}
