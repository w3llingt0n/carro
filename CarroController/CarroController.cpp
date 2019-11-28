#include "CarroController.h"

CarroController::CarroController(uint8_t pinMotorA1, uint8_t pinMotorA2, uint8_t pinMotorAvel, uint8_t pinMotorB1, 
  uint8_t pinMotorB2, uint8_t pinMotorBvel, uint8_t pinCorrenteA, uint8_t pinCorrenteB, uint8_t pinBateria) {

  pinMode(pinMotorA1, OUTPUT);
  pinMode(pinMotorA2, OUTPUT);
  pinMode(pinMotorAvel, OUTPUT);
  pinMode(pinMotorB1, OUTPUT);
  pinMode(pinMotorB2, OUTPUT);
  pinMode(pinMotorBvel, OUTPUT);

  ctrlM_pin1[0] = pinMotorA1;
  ctrlM_pin2[0] = pinMotorA2;
  ctrlVel[0] = pinMotorAvel;
  ctrlM_pin1[1] = pinMotorB1;
  ctrlM_pin2[1] = pinMotorB2;
  ctrlVel[1] = pinMotorBvel;
  entradaCorrente[0] = pinCorrenteA;
  entradaCorrente[1] = pinCorrenteB;
  entradaBateria = pinBateria;
  sobrecarga = false;
}

/*Faz o acionamento do motor.
**motor: número inteiro 0 ou 1 representando motor direito e esquerdo
**sentido: valor booleano true->(frente) ou false->(marcha ré) para avanço e reversão
**velocidade: número inteiro que representa a velocidade do motor. Valores possíveis de 0 a 10
*/
void CarroController::ligaMotor(int motor, bool sentido, int velocidade) {
  
  if (motor > 1) {
    return;
  }

  if (isSobrecarga()) {
    sobrecarga = true;
    Serial.println("Sobrecarga da bateria.");
  }

  if ((!sobrecarga) and (!isBateriaNivelCritico())) {

  	Serial.println("Motor ligado.");

    int velReal = map(velocidade, 0, 10, 0, 255);
    digitalWrite(ctrlM_pin1[motor], sentido);
    digitalWrite(ctrlM_pin2[motor], !sentido);
    analogWrite(ctrlVel[motor], velReal);

    if (sentido) {
      sentidoMotor[motor] = 1;
    } else {
      sentidoMotor[motor] = 2;
    }
  }
}

/*Desliga o motor.
**motor: número inteiro 0 ou 1 representando motor direito e esquerdo
*/
void CarroController::desligaMotor(int motor) {
  if (motor > 1) {
    return;
  }

  Serial.println("Motor desligado.");

  digitalWrite(ctrlM_pin1[motor], LOW);
  digitalWrite(ctrlM_pin2[motor], LOW);
  analogWrite(ctrlVel[motor], 0);
  sentidoMotor[motor] = 0;
}

//Retorna o nível da bateria em percentual. Valores possíveis de 0 a 100
float CarroController::getNivelBateria() {
  int leituraBateria = analogRead(entradaBateria);
  return map(leituraBateria, 0, 1023, 0, 100);
}

/*Retorna a leitura de corrente do motor.
**motor: número inteiro 0 ou 1 representando motor direito e esquerdo
*/
float CarroController::getLeituraCorrente(int motor) {
  if (motor > 1) {
    return 0.0f;
  }

  int leituraMotor = analogRead(entradaCorrente[motor]);
  float corrente = map(leituraMotor, 0, 1023, 0, CORRENTE_MAX);
  return corrente;
}

//Retorna verdadeiro se algum dos motores está em sobrecarga
bool CarroController::isSobrecarga() {
  return (getLeituraCorrente(0) > LIMITE_SOBRECARGA) or (getLeituraCorrente(1) > LIMITE_SOBRECARGA);
}

//Retorna verdadeiro se o nível da bateria está em estado crítico
bool CarroController::isBateriaNivelCritico() {
	Serial.println("");
  return (getNivelBateria() < NIVEL_MIN_BATERIA);
}

/*Retorna o sentido do carro.
**0 - Indica que o carro está parado
**1 - Indica que o carro está avançando (sentido frente)
**2 - Indica que o carro está recuando (sentido ré)
**3 - Indica que o carro está executando alguma manobra (Os dois motores estão em sentidos opostos)
*/
int CarroController::getSentidoCarro() {
  if (sentidoMotor[0] == sentidoMotor[1]) {
    return sentidoMotor[0];
  } else {
    return 3;
  }
}

//Reinicia a falha de sobrecarga
void CarroController::resetSobrecarga() {
  sobrecarga = false;
}
