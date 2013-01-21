String pino;
String tempo;
char c;

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
}

void loop() {
  int pos = 0; // position in read buffer
  int servoNumber = 0; // your first field of message
  int corner = 0; // second field of message
  int cornerStartPos = 0; // starting offset of corner in string
  char buffer[32];
  
  // send data only when you receive data:
  while (Serial.available() > 0) {
    // read the incoming byte:
    char inByte = Serial.read();
    
    // add to our read buffer
    buffer[pos++] = inByte;
    
    // check for delimiter
    if (inByte == ';') {
      cornerStartPos = pos;
      buffer[pos-1] = 0;
      servoNumber = atoi(buffer);
      
      Serial.print("Servo num: ");
      Serial.println(servoNumber);
    } else {
      buffer[pos++] = 0; // delimit
      corner = atoi((char*)(buffer+cornerStartPos));
      Serial.print("Corner: ");
      Serial.println(corner);
    }
  }
 }
