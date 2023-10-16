#line 1 "D:\\Personal\\ProyectosUni\\3Anyo\\ProyectoBiometria\\Codigo\\git\\BiometriaYMedioAmbiente-Arduino\\beaconArduino2\\libraries\\Publicador.h"
#ifndef PUBLICADOR_H_INCLUIDO
#define PUBLICADOR_H_INCLUIDO
#include "libraries.h"
#include "EmisoraBLE.h"
// --------------------------------------------------------------
// Pepe Gascó Bule
// 2023
// --------------------------------------------------------------
class Publicador
{
private:
	uint8_t beaconUUID[16] = {
		'E', 'P', 'S', 'G', '-', 'G', 'T', 'I',
		'-', 'P', 'R', 'O', 'Y', '-', '3', 'A'}; // aaaa

public:
	EmisoraBLE laEmisora{
		"GTI-PepeGascóBule", //  nombre emisora
		0x004c,				 // fabricanteID (Apple)
		4					 // txPower
	};

	const int RSSI = -53; // por poner algo, de momento no lo uso
public:
	enum MedicionesID
	{
		CO2 = 11,
		TEMPERATURA = 12,
		RUIDO = 13
	};

	Publicador()
	{
	}

	// ............................................................
	// ............................................................
	void encenderEmisora()
	{
		(*this).laEmisora.encenderEmisora();
	}

	// ............................................................
	// ............................................................
	void publicarCO2(int16_t valorCO2, uint8_t contador,
					 long tiempoEspera)
	{

		//
		// 1. empezamos anuncio
		//
		uint16_t major = (MedicionesID::CO2 << 8) + contador;
		(*this).laEmisora.emitirAnuncioIBeacon((*this).beaconUUID,
											   major,
											   valorCO2,	// minor
											   (*this).RSSI // rssi
		);

		//
		// 2. esperamos el tiempo que nos digan
		//
		esperar(tiempoEspera);

		//
		// 3. paramos anuncio
		//
		(*this).laEmisora.detenerAnuncio();
	} // ()

	// ............................................................
	// ............................................................
	void publicarTemperatura(int16_t valorTemperatura,
							 uint8_t contador, long tiempoEspera)
	{
		uint16_t major = (MedicionesID::TEMPERATURA << 8) + contador;
		(*this).laEmisora.emitirAnuncioIBeacon((*this).beaconUUID,
											   major,
											   valorTemperatura, // minor
											   (*this).RSSI		 // rssi
		);
		esperar(tiempoEspera);

		(*this).laEmisora.detenerAnuncio();
	} // ()

}; // class
#endif
