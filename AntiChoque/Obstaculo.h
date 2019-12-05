/*
  Ultrasonic.h - Library for HR-SC04 Ultrasonic Ranging Module.
  Created by ITead studio. Alex, Apr 20, 2010.
  iteadstudio.com
*/

int getMediaMovelF(int distFrontal);
bool controleObstaculo(int distFrontal, int distDireito, int distEsquerdo, int mediaT);

void comandoLed(int led,bool liga);
int getMediaMovelT(int distTraseiro);
void setVelocidade(int velo);
int sensorFrontal(int distFrontal);
int sensoresLaterais(int distDireita, int distEsquerda, int mediaT);
int sensorTraseiro(int mediaT, int distDireita, int distEsquerda);
int sorteio();
int getVelo();
