#include <Arduino.h>
#include "DirectionOfCar.h"

DirectionCar carro(3, 9, 10, 11);
char sentido;
int velocidade;
char direcao;

void setup(){

  Serial.begin(9600);
}

void loop(){

  if(Serial.available()>0){
    String protocol = carro.readSerial();
    protocol.trim();
    
    //Serial.print("Bytes no protocolo: ");
    //Serial.println(protocol.length());
    
    if(protocol.length() == 3){
      if((protocol.charAt(0) == 'f' || protocol.charAt(0) == 'r' || protocol.charAt(0) == 't')&&(isDigit(protocol.charAt(1)))&&(protocol.charAt(2) == 'e' || protocol.charAt(2) == 'd')){
        Serial.println("Protocolo válido!");
        sentido = protocol.charAt(0);
        velocidade = protocol.charAt(1); 
        direcao = protocol.charAt(2);

        carro.changeDirection(sentido, velocidade, direcao);
        
      }else{
        carro.protocolInvalid();
      }
    }else{
       carro.protocolInvalid();
    }
  }  

  
}
