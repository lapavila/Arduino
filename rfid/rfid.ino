#include <SoftwareSerial.h>

SoftwareSerial rfid = SoftwareSerial(3, 2);
String tag;

void setup()  
{
  Serial.begin(9600);
  rfid.begin(9600);
  tag = "";
}

char c;

void loop() {
  
  while(rfid.available() > 0){
    c = rfid.read(); 
    Serial.println(tag);
    tag += c;
  }
  if (tag.length() > 10) {
    Serial.println(tag);
    tag = "";
  }
  delay(500);
}
