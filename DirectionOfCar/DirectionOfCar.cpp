#include "Arduino.h"
#include "DirectionOfCar.h"

String readSerial(){
  String conteudo = "";
  char caractere;

  while(Serial.available() > 0){
    caractere = Serial.read();

    if(caractere != '\n'){
      conteudo.concat(caractere);
    }
    delay(15);
  }
  Serial.print("Recebi: ");
  Serial.println(conteudo);
  return conteudo;
}

void changeDirection(CarroController carro, char c, int velocity, char directionCar){

  /* exibindo os parametros recebidos */
  Serial.print(c);
  Serial.print("   ");
  Serial.write(velocity);
  Serial.print("   ");
  Serial.print(directionCar);
  Serial.println(" ;");

  /* tratando valor do pwm */
  int v = velocity - 47;
  int velocidade = (v * 25);

  /* tratando a direção da conversão */
  String direcao = "";
  if(directionCar == 'e'){ //virar para direita
    direcao = "Esquerda";
  }else if(directionCar == 'd'){ //virar para esquerda
    direcao = "Direita";
  }
 
  switch(c){
/*##################################################################################################*/
    /********  Seguir em frente  ************/
    case 'f': 
      Serial.println(velocity);
        Serial.println(velocity);
          Serial.println(velocity);
      if(direcao.equals("Direita")){
        switch(velocity){
          case 48:
            carro.ligaMotor(0, 1, 2);
            carro.ligaMotor(1, 1, 1); 
            break;
          case 49:
            carro.ligaMotor(0, 1, 3);
            carro.ligaMotor(1, 1, 2);
          break;
          case 50:
            carro.ligaMotor(0, 1, 4);
            carro.ligaMotor(1, 1, 3);
            break;
          case 51:
            carro.ligaMotor(0, 1, 5);
            carro.ligaMotor(1, 1, 4);
            break;
          case 52:
           carro.ligaMotor(0, 1, 6);
            carro.ligaMotor(1, 1, 5);
            break;
          case 53:
            carro.ligaMotor(0, 1, 7);
            carro.ligaMotor(1, 1, 6);
            break;
          case 54:
            carro.ligaMotor(0, 1, 8);
            carro.ligaMotor(1, 1, 7);
           break;
          case 55:
            carro.ligaMotor(0, 1, 9);
            carro.ligaMotor(1, 1, 8);
            break;
          case 56:
            carro.ligaMotor(0, 1, 10);
            carro.ligaMotor(1, 1, 9);
            break;
          case 57:
            carro.ligaMotor(0, 0 , 0);
            carro.ligaMotor(1, 0, 10);
         ///   Serial.println(" ops");
            break;
        }
      }else if(direcao.equals("Esquerda")){
        switch(velocity){
          case 48:
            carro.ligaMotor(0, 1, 1);
            carro.ligaMotor(1, 1, 2);
            break;
            case 49:
            carro.ligaMotor(0, 1, 2);
            carro.ligaMotor(1, 1, 3);
            break;
          case 50:
            carro.ligaMotor(0, 1, 3);
            carro.ligaMotor(1, 1, 4);
            break;
          case 51:
            carro.ligaMotor(0, 1, 4);
            carro.ligaMotor(1, 1, 5);
            break;
          case 52:
            carro.ligaMotor(0, 1, 5);
            carro.ligaMotor(1, 1, 6);
           break;
          case 53:
            carro.ligaMotor(0, 1, 6);
            carro.ligaMotor(1, 1, 7);
           break;
          case 54:
            carro.ligaMotor(0, 1, 7);
            carro.ligaMotor(1, 1, 8);
           break;
          case 55:
            carro.ligaMotor(0, 1, 8);
            carro.ligaMotor(1, 1, 9);
           break;
          case 56:
            carro.ligaMotor(0, 1, 9);
            carro.ligaMotor(1, 1, 10);
            break;
          case 57:
            carro.ligaMotor(0, 0, 10);
            carro.ligaMotor(1, 0, 0);
            // Serial.println(" Bigal");
            break;
        }
      }
    break; // fim do case 'f'
/*##################################################################################################*/
    /********  Seguir em marcha ré  ************/
    case 'r':
      if(direcao.equals("Esquerda")){
        switch(velocity){
          case 48:
            carro.ligaMotor(0, 0, 2);
            carro.ligaMotor(1, 0, 1);
           case 49:
            carro.ligaMotor(0, 0, 3);
            carro.ligaMotor(1, 0, 2);
            break;
          case 50:
            carro.ligaMotor(0, 0, 4);
            carro.ligaMotor(1, 0, 3);
            break;
          case 51:
            carro.ligaMotor(0, 0, 5);
            carro.ligaMotor(1, 0, 4);
            break;
          case 52:
            carro.ligaMotor(0, 0, 6);
            carro.ligaMotor(1, 0, 5);
            break;
          case 53:
            carro.ligaMotor(0, 0, 7);
            carro.ligaMotor(1, 0, 6);
            break;
          case 54:
            carro.ligaMotor(0, 0, 8);
            carro.ligaMotor(1, 0, 7);
           break;
          case 55:
            carro.ligaMotor(0, 0, 9);
            carro.ligaMotor(1, 0, 8);
            break;
          case 56:
            carro.ligaMotor(0, 0, 10);
            carro.ligaMotor(1, 0, 9);
            break;
          case 57:
            carro.ligaMotor(0, 0, 10);
            carro.ligaMotor(1, 0, 0);
            break;
        }

      }else if(direcao.equals("Direita")){
        switch(velocity){
          case 48:
            carro.ligaMotor(0, 0, 1);
            carro.ligaMotor(1, 0, 2);
            break;
          case 49:
            carro.ligaMotor(0, 0, 2);
            carro.ligaMotor(1, 0, 3);
           break;
          case 50:
            carro.ligaMotor(0, 0, 3);
            carro.ligaMotor(1, 0, 4);
            break;
          case 51:
            carro.ligaMotor(0, 0, 4);
            carro.ligaMotor(1, 0, 5);
           break;
          case 52:
            carro.ligaMotor(0, 0, 5);
            carro.ligaMotor(1, 0, 6);
           break;
          case 53:
            carro.ligaMotor(0, 0, 6);
            carro.ligaMotor(1, 0, 7);
            break;
          case 54:
            carro.ligaMotor(0, 0, 7);
            carro.ligaMotor(1, 0, 8);
            break;
          case 55:
            carro.ligaMotor(0, 0, 8);
            carro.ligaMotor(1, 0, 9);
            break;
          case 56:
            carro.ligaMotor(0, 0, 9);
            carro.ligaMotor(1, 0, 10);
           break;
          case 57:
            carro.ligaMotor(0, 0, 10);
            carro.ligaMotor(1, 0, 0);
           break;
        }
      }
    break;  //fim case 'r'

    /********  Conversão abrupta  ************/
    case 't':
      if(direcao.equals("Esquerda")){
          carro.ligaMotor(0, 1, 10);
          carro.ligaMotor(1, 0, 0);
      }else if(direcao.equals("Direita")){
          carro.ligaMotor(0, 0, 10);
          carro.ligaMotor(1, 1, 0);
      }

      Serial.print("Motor A: ");
      Serial.println(velocidade);
      Serial.print("Motor B: ");
      Serial.println(velocidade);
      
    break;  //fim case 't'
  }
}
  
