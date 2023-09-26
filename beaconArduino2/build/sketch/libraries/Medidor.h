#line 1 "D:\\Personal\\ProyectosUni\\3Anyo\\ProyectoBiometria\\Codigo\\git\\BiometriaYMedioAmbiente-Arduino\\beaconArduino2\\libraries\\Medidor.h"
// -*- mode: c++ -*-

#ifndef MEDIDOR_H_INCLUIDO
#define MEDIDOR_H_INCLUIDO
#include "libraries.h"
// ------------------------------------------------------
// ------------------------------------------------------
class Medidor {

  // .....................................................
  // .....................................................
private:

public:

  // .....................................................
  // constructor
  // .....................................................
  Medidor(  ) {
  } // ()

  // .....................................................
  // .....................................................
  void iniciarMedidor() {
	// las cosas que no se puedan hacer en el constructor, if any
  } // ()

  // .....................................................
  // .....................................................
  int medirCO2() {
	return 235; //Cambiar este valor para cambair el resultado del co2
  } // ()

  // .....................................................
  // .....................................................
  int medirTemperatura() {
	return -12; // Cambiar este valor para cambiar el resultado de la temperatura
  } // ()
	
}; // class

// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------
#endif
