#line 1 "D:\\Personal\\ProyectosUni\\3Anyo\\ProyectoBiometria\\Codigo\\git\\BiometriaYMedioAmbiente-Arduino\\beaconArduino2\\libraries\\LED.h"
#ifndef LED_H_INCLUIDO
#define LED_H_INCLUIDO
#include "libraries.h"
// ----------------------------------------------------------
// Librearia para usar los leds
// Pepe Gascó Bule
// 2023
// ----------------------------------------------------------

// Metodo para esperar x tiempo.
void esperar(long tiempo)
{
  delay(tiempo);
}

// ----------------------------------------------------------
class LED
{
private:
  int numeroLED;
  bool encendido;

public:
  LED(int numero)
      : numeroLED(numero), encendido(false)
  {
    pinMode(numeroLED, OUTPUT);
    apagar();
  }

  // .........................................................
  // Metodo para encender LED
  void encender()
  {
    digitalWrite(numeroLED, HIGH);
    encendido = true;
  }

  // .........................................................
  // Metodo para encender LED
  void apagar()
  {
    digitalWrite(numeroLED, LOW);
    encendido = false;
  }

  // .........................................................
  // Metodo para parpadear LED
  void alternar()
  {
    if (encendido)
    {
      apagar();
    }
    else
    {
      encender();
    }
  } // ()

  // .........................................................
  // Metodo para encender x segundos LED
  void brillar(long tiempo)
  {
    encender();
    esperar(tiempo);
    apagar();
  }
};
#endif
