// -*- mode: c++ -*-

#ifndef MEDIDOR_H_INCLUIDO
#define MEDIDOR_H_INCLUIDO
#include "libraries.h"
/*!
* \brief Clase en desuso. Se dara uso mas adelante 
* \author Pepe Gascó Bule
* \version 0
* \date 2023
 */
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
