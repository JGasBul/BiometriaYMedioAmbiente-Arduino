#ifndef PUERTO_SERIE_H_INCLUIDO
#define PUERTO_SERIE_H_INCLUIDO
#include "libraries.h"
// ----------------------------------------------------------
// Clase para controlar el puerto serie
// Pepe Gascó Bule
// 2023
// ----------------------------------------------------------

class PuertoSerie
{

public:
  // Inicializar puerto serie
  PuertoSerie(long baudios)
  {
    Serial.begin(baudios);
  }
  // Esperar a que este disponible el puerto serie
  void esperarDisponible()
  {
    while (!Serial)
    {
      delay(10);
    }
  }
  // Metodo para escribir en el puerto serie
  template <typename T>
  void escribir(T mensaje)
  {
    Serial.print(mensaje);
  }
};
#endif
