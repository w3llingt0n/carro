/*
  Ultrasonic.h - Library for HR-SC04 Ultrasonic Ranging Module.
  Created by ITead studio. Alex, Apr 20, 2010.
  iteadstudio.com
*/
#include "Ultrasonic.h"
#include "Arduino.h"
#include "DirectionOfCar.h"

  
int getMediaMovel(int distFrontal);
int controleObstaculo(int distFrontal, int distDireito, int distEsquerdo);
void comandoLed(int led,bool liga);
void setVelocidade(int velo);
int sensorFrontal(int distFrontal);
int sensoresLaterais(int distDireita, int distEsquerda);
bool sensorTraseiro(int distTraseira);
int sorteio();
