//Programa: Conectando Sensor Ultrassonico HC-SR04 ao Arduino

//Carrega a biblioteca do sensor ultrassonico
#include "Ultrasonic.h"
#include "obstaculo.h"

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonicF(6, 7);
Ultrasonic ultrasonicD(8, 9);
Ultrasonic ultrasonicE(10, 11);
Ultrasonic ultrasonicT(12, 13);
// Inicializa os Leds
  int led1 = 3;
  int led2 = 4;
  int led3 = 5;
  int led4 = 6;
  
int distFrontal;
int distDireito;
int distEsquerdo;
int distTraseiro;
int mediaFrontal;
int mediaT;

void setup(){
  Serial.begin(9600);
  Serial.println("Lendo sensor...");
  // inicializa o pino digital 13 como Saída.
 // pinMode(13, OUTPUT);
 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop(){
  //Le as informacoes do sensor, em cm 
  distFrontal = ultrasonicF.Ranging(CM);// ultrassom.Ranging(CM) retorna a distancia em cm
  distTraseiro= ultrasonicT.Ranging(CM);
  distDireito= ultrasonicD.Ranging(CM);
  distEsquerdo= ultrasonicE.Ranging(CM);
 //Serial.println(distFrontal);
 //Serial.println(distTraseiro);
 //Serial.println(distDireito);
 //Serial.println(distEsquerdo);
   
 
 // distDireito = ultrasonicD.Ranging(CM);
 // distEsquerdo = ultrasonicE.Ranging(CM);
 // distTraseiro = ultrasonicT.Ranging(CM);

    mediaFrontal = getMediaMovelF(distFrontal);
    mediaT = getMediaMovelT(distTraseiro);

  controleObstaculo(mediaFrontal, distDireito, distEsquerdo, mediaT);
  //Serial.println(getMediaMovel(distFrontal));
  delay(500);
}
