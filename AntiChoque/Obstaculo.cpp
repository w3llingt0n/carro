/*
  obstaculo.cpp - Library for car IFNMG
  Created by Top Team 2019
  feras.com*/


#include "obstaculo.h"
#include "Ultrasonic.h"

const int janela = 2;
int medida[janela];
int pos;
int veloS;

int getMediaMovelF(int distFrontal) {
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

int getMediaMovelT(int distTraseiro) {
  int total;
  total = 0;
  medida[pos] = distTraseiro;
  pos++;
  if (pos > janela) {
    pos = 0;
  }
  for (int i = 0; i < janela; i++) {
    total += medida[i];
  }
  return total / janela;
}


bool controleObstaculo(int mediaFrontal, int distDireito, int distEsquerdo, int mediaT) {
  /* Manter velocidade indicada pelo usuário se o campo estiver livre, e
    não seja detectado nenhum obstáculo a uma distância menor que 3 metros,
    mantendo o led verde aceso;*/
  if (mediaFrontal >= 100) {
    //comandoLed(3, true);
    setVelocidade(9);
    Serial.println("Sem Obstáculos!");
    Serial.println(mediaFrontal);
    return true;
  }

  /* Se detectado algum obstáculo à 3 metros de distância,
     reduzir velocidade em 50% e acender o led amarelo;*/
  else if ((mediaFrontal >= 70) && (mediaFrontal < 100)) {
    //comandoLed(4, true);
    setVelocidade(7);
    Serial.println("Obstaculo detectado, reduzindo velocidade em 50%!");
    Serial.println(mediaFrontal);
    return true;
  }

  /* Avançando no terreno, ao detectar um obstáculo a 1,5 metros de distância,
     reduzir a velocidade em 80% e piscar o led amarelo;*/
  else if ((mediaFrontal >= 30) && (mediaFrontal < 70)) {
    //comandoLed(4, true);
    setVelocidade(5);
    Serial.println("Obstaculo detectado, reduzindo velocidade em 80%!");
    Serial.println(mediaFrontal);
    return true;
  }

  /*Ao detectar um obstáculo a 0,5 metros de distância,
    parar o veículo e acender o led vermelho;*/
  else if (mediaFrontal < 30) {
    //comandoLed(4, true);
    setVelocidade(0);
    Serial.println(mediaFrontal);
    Serial.println("Obstaculo detectado, parando o veículo!");
    Serial.println("Veículo parado, calculando rota...!");

    /*Após parar, calcular se há obstáculos nas direções Direita e Esquerda,
      e fazer a conversão para a maior área livre. Se ambos os lados tiverem
      área livre maior que 3 metros(...), a conversão será feita de forma
      aleatória por uma função de sorteio.*/
      //sensoresLaterais(distDireito, distEsquerdo, mediaT);

    return true;
  }
  else {
    return false;
  }
}

int sensoresLaterais(int distDireita, int distEsquerda, int mediaT) {

  if (distDireita > distEsquerda) {
    //Serial.println(distDireita + "a Direita");
    //Serial.println(distEsquerda + "a Esquerda!");
    Serial.println("Virar a Direita!");
    return 0;
  }
  else if (distEsquerda > distDireita) {
    //Serial.println(distDireita + "a Direita");
    //Serial.println(distEsquerda + "a Esquerda!");
    Serial.println("Virar a Esquerda!");
    return 1;
  }
  else if ((distDireita > 100) && (distEsquerda > 100)) {
    Serial.println("Chamar Funcao de sorteio");
    int numero = sorteio();
    if (numero == 0) {
      //Serial.println(distDireita + "a Direita");
      //Serial.println(distEsquerda + "a Esquerda!");
      Serial.println(numero + "Virar a Direita!");
      return numero;
    }
    else {
      //Serial.println(distDireita + "a Direita");
      //Serial.println(distEsquerda + "a Esquerda!");
      Serial.println(numero + "Virar a Esquerda!");
      return numero;
    }
  }
  else if ((distDireita < 20) && (distEsquerda < 20)) {
    //Serial.println(getMediaMovelF(mediaFrontal));
    Serial.println("Obstaculo detectado a direita e a esquerda!");
    Serial.println("Retornar o veículo em marcha a re");
    return 3;
  }
  else if ((distDireita < 20) && (distEsquerda < 20)) {
    sensorTraseiro(mediaT, distDireita, distEsquerda);
  }
}

int sensorTraseiro(int mediaT, int distDireita, int distEsquerda) {
  if (mediaT >= 50) {
    if (distDireita > distEsquerda) {
      Serial.println(distDireita + "a Direita");
      Serial.println(distEsquerda + "a Esquerda!");
      Serial.println("Virar a Direita!");
      Serial.println(getMediaMovelT(mediaT));
      return 0;
    }
    else if (distEsquerda > distDireita) {
      Serial.println(distDireita + "a Direita");
      Serial.println(distEsquerda + "a Esquerda!");
      Serial.println(getMediaMovelT(mediaT));
      Serial.println("Virar a Esquerda!");
      return 1;
    }
  }
  else {
    //Serial.println(getMediaMovelF(mediaFrontal));
    Serial.println(getMediaMovelT(mediaT));
    Serial.println("Veículo Parado. Sem Saídas!");
    return 4;
  }
}

int sorteio() {
  int sorteio = random(0, 2);
  return sorteio;
}/*

  void comandoLed(int led, bool liga) {
  for (int i = 3; i < 6; i++) {
    digitalWrite(i, LOW);
    digitalWrite(led, liga);
  }
  }
*/
void setVelocidade(int velo) {
  //PORTD = velo << 5;
veloS= velo;
}
int getVelo()
{
  return veloS;
}