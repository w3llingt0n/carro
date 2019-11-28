#include <Arduino.h>
#include "DirectionOfCar.h"
#include "CarroController.h"
#include "Obstaculo.h"

char sentido;
int velocidade;
char direcao;

CarroController carro(3, 9, 5, 10, 11, 6, 2, 4, 7);

void setup(){

  Serial.begin(9600);
//    carro.ligaMotor(1, true, i);
//    carro.ligaMotor(0, true, i);
  
}

void loop(){

  String a = "Valor de i: ";

  if(Serial.available()>0){
     String protocol = readSerial();
     protocol.trim();

    if(protocol.length() == 3){
      if((protocol.charAt(0) == 'f' || protocol.charAt(0) == 'r' || protocol.charAt(0) == 't')&&
          (isDigit(protocol.charAt(1)))&&
          (protocol.charAt(2) == 'e' || protocol.charAt(2) == 'd')){
            
        Serial.println("Protocolo válido!");
        sentido = ((protocol.charAt(0) == 'f') ? true : false);
        velocidade = protocol.charAt(1); 
        direcao = protocol.charAt(2);

        carro.ligaMotor(1, sentido, protocol[1]);
        carro.ligaMotor(0, sentido, protocol[1]);
      
      }
       
      if(protocol[1] == '0'){
        Serial.println(protocol);
        carro.desligaMotor(0);
        carro.desligaMotor(1);    
      }
    }else{
      Serial.println("Protocolo inválido");
    }
  }
}
