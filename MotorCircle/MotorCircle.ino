int motor1Pin1 = 7;
int motor1Pin2 = 8;

int motor2Pin1 = 12;
int motor2Pin2 = 13;

int entrada = 0;
 
void setup() {
  Serial.begin(9600);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
}
 
void loop() {
  // testa se a porta serial está disponível
  if (Serial.available() > 0) {
      // le os dados da porta serial armazena na variavel 'entrada'
      entrada = Serial.read();
    if (entrada == 'f'){
      frente();
    } else if (entrada == 'r'){
      re();
    } else if (entrada == 'd') {
      lado1();
    } else if (entrada == 'e') {
      lado2();
    } else if (entrada == 's') {
      roda1();
    } else if (entrada == 'a') {
      roda2();
    } else {
      parar();
    }
  }
}

void roda1() {
  digitalWrite(motor1Pin1, 0);
  digitalWrite(motor1Pin2, 1);
  
  digitalWrite(motor2Pin1, 0);
  digitalWrite(motor2Pin2, 0);
}

void roda2() {
  digitalWrite(motor1Pin1, 0);
  digitalWrite(motor1Pin2, 0);
  
  digitalWrite(motor2Pin1, 0);
  digitalWrite(motor2Pin2, 1);
}

void lado1() {
  digitalWrite(motor1Pin1, 0);
  digitalWrite(motor1Pin2, 1);
  
  digitalWrite(motor2Pin1, 1);
  digitalWrite(motor2Pin2, 0);
}

void lado2() {
  digitalWrite(motor1Pin1, 1);
  digitalWrite(motor1Pin2, 0);
  
  digitalWrite(motor2Pin1, 0);
  digitalWrite(motor2Pin2, 1);
}

void frente(){
  digitalWrite(motor1Pin1, 1);
  digitalWrite(motor1Pin2, 0);
  
  digitalWrite(motor2Pin1, 1);
  digitalWrite(motor2Pin2, 0);
}
 
void re(){
  digitalWrite(motor1Pin1, 0);
  digitalWrite(motor1Pin2, 1);
  
  digitalWrite(motor2Pin1, 0);
  digitalWrite(motor2Pin2, 1);
}
 
void parar(){
  digitalWrite(motor1Pin1, 0);
  digitalWrite(motor1Pin2, 0);
  
  digitalWrite(motor2Pin1, 0);
  digitalWrite(motor2Pin2, 0);
}

