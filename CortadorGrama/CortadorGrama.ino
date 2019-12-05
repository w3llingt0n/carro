#include <Arduino.h>
#include "DirectionOfCar.h"
#include "CarroController.h"
#include "obstaculo.h"
#include "Ultrasonic.h"

char sentido;
int velocidade;
char direcao;
bool on;

CarroController carro(3, 9, 5, 10, 11, 6, 2, 4, 7);
Ultrasonic ultrasonicF(2, 3);
Ultrasonic ultrasonicD(8, 9);
Ultrasonic ultrasonicE(10, 11);
Ultrasonic ultrasonicT(12, 13);
int distFrontal;
int distTraseiro;
int distDireito;
int distEsquerdo;

void setup() {

  Serial.begin(9600);
  //    carro.ligaMotor(1, true, i);
  //    carro.ligaMotor(0, true, i);
velocidade=5;
}

void loop() {


  String a = "Valor de i: ";

  if (Serial.available() > 0) {
    String protocol = readSerial();
    protocol.trim();
    
     if (protocol.length() == 3) {
      if ((protocol.charAt(0) == 'f' || protocol.charAt(0) == 'r' || protocol.charAt(0) == 't') && (isDigit(protocol.charAt(1))) && (protocol.charAt(2) == 'e' || protocol.charAt(2) == 'd')) {

        Serial.println("Protocolo válido!");
        sentido = protocol.charAt(0);//((protocol.charAt(0) == 'f') ? true : false);
        velocidade = protocol.charAt(1);
        direcao = protocol.charAt(2);
        on=true;
      }
        changeDirection(carro, sentido, velocidade, direcao);
     /* if (protocol[1] == '0') {
        Serial.println("Parado");
        Serial.println(protocol);
        carro.desligaMotor(0);
        carro.desligaMotor(1);
      }
    } else {
      Serial.println("Protocolo inválido");
    }*/
  }
}
  /*distFrontal = ultrasonicF.Ranging(CM);
  distTraseiro = ultrasonicT.Ranging(CM);
  distDireito = ultrasonicD.Ranging(CM);
  distEsquerdo = ultrasonicE.Ranging(CM);
  controleObstaculo(distFrontal, distDireito, distEsquerdo, distTraseiro);
 */
    // carro.ligaMotor(1, sentido, getVelo());
   // carro.ligaMotor(0, sentido, getVelo());

    //carro.ligaMotor(0, false, 9);
  //changeDirection(carro, 'f', '9', 'e');
}
