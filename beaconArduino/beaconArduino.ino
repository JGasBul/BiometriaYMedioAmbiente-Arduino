#include <BLEAdvertising.h>
#include <BLECentral.h>
#include <BLECharacteristic.h>
#include <BLEClientCharacteristic.h>
#include <BLEClientService.h>
#include <BLEConnection.h>
#include <BLEDiscovery.h>
#include <BLEGatt.h>
#include <BLEPeriph.h>
#include <BLEScanner.h>
#include <BLESecurity.h>
#include <BLEService.h>
#include <BLEUuid.h>
#include <bluefruit_common.h>
#include <bluefruit.h>


// --------------------------------------------------------------
// --------------------------------------------------------------
//#include <bluefruit.h>

#include "./libraries/LED.h"
#include "./libraries/PuertoSerie.h"

// --------------------------------------------------------------
// --------------------------------------------------------------
namespace Globales
{

    LED elLED ( /* NUMERO DEL PIN LED = */ 7 );

    PuertoSerie elPuerto(/* velocidad = */ 115200); // 115200 o 9600 o ...

    // Serial1 en el ejemplo de Curro creo que es la conexión placa-sensor
};

// --------------------------------------------------------------
// --------------------------------------------------------------
#include "./libraries/EmisoraBLE.h"
#include "./libraries/Publicador.h"
#include "./libraries/Medidor.h"

// --------------------------------------------------------------
// --------------------------------------------------------------
namespace Globales
{

    Publicador elPublicador;

    Medidor elMedidor;

}; // namespace

// --------------------------------------------------------------
// --------------------------------------------------------------
void inicializarPlaquita()
{

    // de momento nada

} // ()

void setup()
{
    Globales::elPuerto.esperarDisponible();

    //
    //
    //
    inicializarPlaquita();

    // Suspend Loop() to save power
    // suspendLoop();

    //
    //
    //
    Globales::elPublicador.encenderEmisora();

    // Globales::elPublicador.laEmisora.pruebaEmision();

    //
    //
    //
    Globales::elMedidor.iniciarMedidor();

    //
    //
    //
    esperar(1000);

    Globales::elPuerto.escribir("---- setup(): fin ---- \n ");

} // setup ()

// --------------------------------------------------------------
// --------------------------------------------------------------
inline void lucecitas() {
  using namespace Globales;

  elLED.brillar( 100 ); // 100 encendido
  esperar ( 400 ); //  100 apagado
  elLED.brillar( 100 ); // 100 encendido
  esperar ( 400 ); //  100 apagado
  Globales::elLED.brillar( 100 ); // 100 encendido
  esperar ( 400 ); //  100 apagado
  Globales::elLED.brillar( 1000 ); // 1000 encendido
  esperar ( 1000 ); //  100 apagado
} // ()

// --------------------------------------------------------------
// loop ()
// --------------------------------------------------------------
namespace Loop {
  uint8_t cont = 0;
};

// ..............................................................
// ..............................................................
void loop () {

  using namespace Loop;
  using namespace Globales;

  cont++;

  elPuerto.escribir( "\n---- loop(): empieza " );
  elPuerto.escribir( cont );
  elPuerto.escribir( "\n" );


  lucecitas();

  // 
  // mido y publico
  // 
  int valorCO2 = elMedidor.medirCO2();
  
  elPublicador.publicarCO2( valorCO2,
							cont,
							1000 // intervalo de emisión
							);
  
  // 
  // mido y publico
  // 
  int valorTemperatura = elMedidor.medirTemperatura();
  
  elPublicador.publicarTemperatura( valorTemperatura, 
									cont,
									1000 // intervalo de emisión
									);

  // 
  // prueba para emitir un iBeacon y poner
  // en la carga (21 bytes = uuid 16 major 2 minor 2 txPower 1 )
  // lo que queramos (sin seguir dicho formato)
  // 
  // Al terminar la prueba hay que hacer Publicador::laEmisora privado
  // 
  char datos[21] = {
	'H', 'o', 'l', 'a',
	'H', 'o', 'l', 'a',
	'H', 'o', 'l', 'a',
	'H', 'o', 'l', 'a',
	'H', 'o', 'l', 'a',
	'H'
  };

  // elPublicador.laEmisora.emitirAnuncioIBeaconLibre ( &datos[0], 21 );
  elPublicador.laEmisora.emitirAnuncioIBeaconLibre ( "MolaMolaMolaMolaMolaM", 21 );

  esperar( 2000 );

  elPublicador.laEmisora.detenerAnuncio();
  
  // 
  // 
  // 
  elPuerto.escribir( "---- loop(): acaba **** " );
  elPuerto.escribir( cont );
  elPuerto.escribir( "\n" );
  
} // loop ()
// --------------------------------------------------------------
// --------------------------------------------------------------
// --------------------------------------------------------------
// --------------------------------------------------------------
