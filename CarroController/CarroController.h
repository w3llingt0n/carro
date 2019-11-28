#ifndef CarroController_h
#define CarroController_h

#include <Arduino.h>

class CarroController {
  public:
    CarroController(uint8_t pinMotorA1, uint8_t pinMotorA2, uint8_t pinMotorAvel, uint8_t pinMotorB1, uint8_t poinMotorB2, uint8_t pinMotorBvel, uint8_t pinCorrenteA, uint8_t pinCorrenteB, uint8_t pinBateria);
    void ligaMotor(int motor, bool sentido, int velocidade);
    void desligaMotor(int motor);
    bool isBateriaNivelCritico();
    bool isSobrecarga();
    int getSentidoCarro();
    float getNivelBateria();
    float getLeituraCorrente(int motor);
    void resetSobrecarga();

  private:
    const float CORRENTE_MAX = 5.0f;
    const float LIMITE_SOBRECARGA = 2.0f;
    const float NIVEL_MIN_BATERIA = 0.0f; //65.0f;
    uint8_t ctrlM_pin1[2];
    uint8_t ctrlM_pin2[2];
    uint8_t ctrlVel[2];
    uint8_t entradaCorrente[2];
    uint8_t entradaBateria;
    uint8_t sentidoMotor[2];
    bool sobrecarga;
};

#endif
