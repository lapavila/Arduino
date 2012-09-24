unsigned int timeout=0;
unsigned char state=0;

ISR(TIMER2_OVF_vect) {
  TCNT2 = 0;
  timeout++;
  if (timeout > 61) {
    state = 1;
    timeout = 0;
  }
}

void init_timer2(void) {
  TCCR2A |= (1 << WGM21) | (1 << WGM20);
  TCCR2B |= 0x07;   // by clk/1024
  ASSR |= (0<<AS2);    // Use internal clock - external clock not used in Arduino
  TIMSK2 |= 0x01;   //Timer2 Overflow Interrupt Enable
  TCNT2 = 0;
  sei();
}

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  attachInterrupt(0, cleantime, FALLING);
  init_timer2();
}

void loop() {
  switch(state) {
    case 0:
      digitalWrite(13,LOW);
      break;
    case 1:
      digitalWrite(13,HIGH);
      Serial.println("Hellow BT");
      break;
  }
  delay(200);
}

void cleantime() {
  timeout=0;
  state=0;
}
