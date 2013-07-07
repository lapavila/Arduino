#include <MeetAndroid.h>

#define motorDireitoPin1 7
#define motorDireitoPin2 8

#define motorEsquerdoPin1 12
#define motorEsquerdoPin2 13

MeetAndroid meetAndroid;

const float DIFF = 2;
const int X = 0;
const int Y = 1;
const int Z = 2;

float eixos[3];

void setup() {
  Serial.begin(9600);
  meetAndroid.registerFunction(acelerometro, 'B'); 
  pinMode(motorDireitoPin1, OUTPUT);
  pinMode(motorDireitoPin2, OUTPUT);
  
  pinMode(motorEsquerdoPin1, OUTPUT);
  pinMode(motorEsquerdoPin2, OUTPUT);
}

void loop() {
  meetAndroid.receive();
  andar();
  delay(20);
}

void acelerometro(byte flag, byte numOfValues) {
  int length = meetAndroid.stringLength();
  char data[length];
  meetAndroid.getString(data);
  String leitura = data;

  //Separa a string recebida do Amarino em 3 strings
  //Ex: 1.42342;-3.43242;-1.34232  
  int offset = 0;
  int count = 0;
  for(int i = 0; i < length; i++) {
    //Toda vez que encontrar um ';', le de 'offset' até 'i'
    if(data[i] == ';') {
      eixos[count] = stringToFloat(leitura.substring(offset, i));
      offset = i + 1;
      count++;
      
      //Se o último ';' na string tiver o mesmo índice de 'i', então pega 
      //o restante da string no próximo elemento do array.
      if(leitura.lastIndexOf(';') == i) {
        eixos[count] = stringToFloat(leitura.substring(offset, length));
      }
    }
  }
  
//  meetAndroid.send("x");
//  meetAndroid.send(eixos[X]);
//  meetAndroid.send("y");
//  meetAndroid.send(eixos[Y]);
//  meetAndroid.send("z");
//  meetAndroid.send(eixos[Z]);
}

void andar() {
  if(eixos[Y] < -DIFF) {
    meetAndroid.send("frente");
    robotForward();
  } else if(eixos[Y] > DIFF) {
    meetAndroid.send("recuar");
    robotBackward();
  } else if (eixos[X] > DIFF) {
    meetAndroid.send("esquerda");
    roboReEsquerda();
  } else if(eixos[X] < -DIFF) {
    meetAndroid.send("direita");
    roboReDireita();
  } else {
    robotStop();
  }
}

void robotForward() {
  robotStop();
  delay(10);
  motorDireitoFrente();
  motorEsquerdoFrente();
}

void robotBackward() {
  robotStop();
  delay(10);
  motorDireitoRe();
  motorEsquerdoRe();
}

void robotStop() {
  motorDireitoParado();
  motorEsquerdoParado();
}

void roboReEsquerda() {
  motorDireitoFrente();
  motorEsquerdoRe();
}

void roboReDireita() {
  motorEsquerdoFrente();
  motorDireitoRe();
}

void motorDireitoFrente() {
  digitalWrite(motorDireitoPin1, 0);
  analogWrite(motorDireitoPin2, 1);
}

void motorEsquerdoFrente() {
  digitalWrite(motorEsquerdoPin1, 0);
  analogWrite(motorEsquerdoPin2, 1);
}

void motorDireitoRe() {
  analogWrite(motorDireitoPin1, 1);
  digitalWrite(motorDireitoPin2, 0);
}

void motorEsquerdoRe() {
  analogWrite(motorEsquerdoPin1, 1);
  digitalWrite(motorEsquerdoPin2, 0);
}

void motorDireitoParado() {
  digitalWrite(motorDireitoPin1, 0);
  digitalWrite(motorDireitoPin2, 0);
}

void motorEsquerdoParado() {
  digitalWrite(motorEsquerdoPin1, 0);
  digitalWrite(motorEsquerdoPin2, 0);
}

float stringToFloat(String str) {
  char arr[str.length()];
  str.toCharArray(arr, sizeof(arr));
  return atof(arr);
}
