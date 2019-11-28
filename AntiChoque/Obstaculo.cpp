/*
  obstaculo.cpp - Library for car IFNMG
  Created by Top Team 2019
  feras.com*/

#include "Arduino.h"
#include "DirectionOfCar.h"


#include "Obstaculo.h"
//#include "Ultrasonic.h"

const int janela = 10;
int medida[janela];
int pos;

int getMediaMovel(int distFrontal) {
  int total;
  total = 0;
  medida[pos] = distFrontal;
  pos++;
  if (pos > janela) {
    pos = 0;
  }
  for (int i = 0; i < janela; i++) {
    total += medida[i];
  }
  return total / janela;
}

/* Manter velocidade indicada pelo usuário se o campo estiver livre, e
    não seja detectado nenhum obstáculo a uma distância menor que 3 metros,
    mantendo o led verde aceso;*/
int controleObstaculo(int distFrontal, int distDireito, int distEsquerdo) {
  
  if (distFrontal >= 300) {
    //comandoLed(3, true);
    setVelocidade(7);
    Serial.println("Sem Obstáculos!");
    return 10;
  }

  /* Se detectado algum obstáculo à 3 metros de distância,
     reduzir velocidade em 50% e acender o led amarelo;*/
  else if ((distFrontal >= 150) && (distFrontal < 300)) {
    //comandoLed(4, true);
    setVelocidade(4);
    Serial.println("Obstaculo detectado, reduzindo velocidade em 50%!");
    return 10;
  }

  /* Avançando no terreno, ao detectar um obstáculo a 1,5 metros de distância,
     reduzir a velocidade em 80% e piscar o led amarelo;*/
  else if ((distFrontal >= 50) && (distFrontal < 150)) {
    //comandoLed(4, true);
    setVelocidade(2);
    Serial.println("Obstaculo detectado, reduzindo velocidade em 80%!");
    return 10;
  }

  /*Ao detectar um obstáculo a 0,5 metros de distância,
    parar o veículo e acender o led vermelho;*/
  else if (distFrontal < 50) {
    //comandoLed(4, true);
    setVelocidade(0);
    Serial.println("Obstaculo detectado, parando o veículo!");
    Serial.println("Veículo parado, calculando rota...!");

    /*Após parar, calcular se há obstáculos nas direções Direita e Esquerda,
      e fazer a conversão para a maior área livre. Se ambos os lados tiverem
      área livre maior que 3 metros(...), a conversão será feita de forma
      aleatória por uma função de sorteio.*/
    //sensoresLaterais(distDireito, distEsquerdo);
    return sensoresLaterais(distDireito, distEsquerdo);
  }
  else {
    return 9;
  }
}

int sensoresLaterais(int distDireita, int distEsquerda) {

  for(int i = 0; i < 4; i++){
    String contador = String(i, DEC);
    contador.concat("..");
    Serial.print(contador);
    delay(1000);
  }

  //se distDireita for maior distEsquerda retorna 0
  if (distDireita > distEsquerda) {
    //Serial.println(distDireita + "a Direita");
    //Serial.println(distEsquerda + "a Esquerda!");
    //Serial.println("Virar a Direita!");
//*************
    //changeDirection(carro, f, 4, d);
//*************    
    return 0;
  }

  //se distDireita for menor distEsquerda retorna 1
  else if (distEsquerda > distDireita) {
    //Serial.println(distDireita + "a Direita");
    //Serial.println(distEsquerda + "a Esquerda!");
    //Serial.println("Virar a Esquerda!");
//*************
    //changeDirection(carro, f, 4, e);
//*************   
    return 1;
  }
  //se distDireita e distEsquerda for menor que 100 retorna 0
  else if ((distDireita < 100) && (distEsquerda < 100)) {
    Serial.println("Chamar Funcao de sorteio");
    int numero = sorteio();
    if (numero == 0) {
      //Serial.println(distDireita + "a Direita");
      //Serial.println(distEsquerda + "a Esquerda!");
      //Serial.println(numero + "Virar a Direita!");
//*************
      //changeDirection(carro, f, 4, d);
//*************
      return 0;
    }
    else {
      //Serial.println(distDireita + "a Direita");
      //Serial.println(distEsquerda + "a Esquerda!");
      //Serial.println(numero + "Virar a Esquerda!");
//*************
      //changeDirection(carro, f, 4, d);
//*************   
      return 1;
    }
  }
  else if ((distDireita < 20) && (distEsquerda < 20)) {
    Serial.println("Obstaculo detectado a direita e a esquerda!");
    Serial.println("Retornar o veículo em marcha a re");
    return 3;
  }
}

bool sensorTraseiro(int distTraseira) {
  if (distTraseira > 50) {
    return true;
  }
  else {
    return false;
  }
}

int sorteio() {
  int sorteio = random(0, 2);
  return sorteio;
}
/*
void comandoLed(int led, bool liga) {
  for (int i = 3; i < 6; i++) {
    digitalWrite(i, LOW);
    digitalWrite(led, liga);
  }
}
*/
void setVelocidade(int velo) {
  PORTD = velo << 5;
}
