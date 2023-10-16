#include <Arduino.h>
#line 1 "D:\\Personal\\ProyectosUni\\3Anyo\\ProyectoBiometria\\Codigo\\git\\BiometriaYMedioAmbiente-Arduino\\beaconArduino2\\beaconArduino2.ino"
#include "./libraries/EmisoraBLE.h"
#include "./libraries/LED.h"
#include "./libraries/libraries.h"
#include "./libraries/Medidor.h"
#include "./libraries/Publicador.h"
#include "./libraries/PuertoSerie.h"
#include "./libraries/ServicioEnEmisora.h"

/*!
* \brief Columna vertebral del proyecto. Desde aqui se controla todo
* \details Tenemos todos los metodos necesarios para que la app funcione
* \author Pepe Gascó Bule
* \version 1.0
* \date 2023
 */

namespace Globales
{
    LED elLED(7);                 // Para inicializar el led. En este caso el numero del pin led es el 7
    PuertoSerie elPuerto(115200); // Baudios
    Publicador elPublicador;
    Medidor elMedidor;
};
namespace Loop
{
    uint8_t cont = 0;
};

#line 29 "D:\\Personal\\ProyectosUni\\3Anyo\\ProyectoBiometria\\Codigo\\git\\BiometriaYMedioAmbiente-Arduino\\beaconArduino2\\beaconArduino2.ino"
void setup();
#line 39 "D:\\Personal\\ProyectosUni\\3Anyo\\ProyectoBiometria\\Codigo\\git\\BiometriaYMedioAmbiente-Arduino\\beaconArduino2\\beaconArduino2.ino"
void lucecitas();
#line 69 "D:\\Personal\\ProyectosUni\\3Anyo\\ProyectoBiometria\\Codigo\\git\\BiometriaYMedioAmbiente-Arduino\\beaconArduino2\\beaconArduino2.ino"
void medicionesco2();
#line 81 "D:\\Personal\\ProyectosUni\\3Anyo\\ProyectoBiometria\\Codigo\\git\\BiometriaYMedioAmbiente-Arduino\\beaconArduino2\\beaconArduino2.ino"
void medicionesTemperatura();
#line 92 "D:\\Personal\\ProyectosUni\\3Anyo\\ProyectoBiometria\\Codigo\\git\\BiometriaYMedioAmbiente-Arduino\\beaconArduino2\\beaconArduino2.ino"
void envioLibreBLE();
#line 111 "D:\\Personal\\ProyectosUni\\3Anyo\\ProyectoBiometria\\Codigo\\git\\BiometriaYMedioAmbiente-Arduino\\beaconArduino2\\beaconArduino2.ino"
void loop();
#line 29 "D:\\Personal\\ProyectosUni\\3Anyo\\ProyectoBiometria\\Codigo\\git\\BiometriaYMedioAmbiente-Arduino\\beaconArduino2\\beaconArduino2.ino"
void setup()
{
    Globales::elPuerto.esperarDisponible();
    Globales::elPublicador.encenderEmisora();

    esperar(1000);
    Globales::elPuerto.escribir("---- setup(): fin ---- \n ");
}

// --------------------------------------------------------------
inline void lucecitas()
{
    using namespace Globales;

    Globales::elLED.brillar(100); // 100 encendido
    esperar(400); //  100 apagado
    Globales::elLED.brillar(1000); // 1000 encendido
    esperar(1000);                 //  100 apagado
    Globales::elLED.brillar(1000); // 1000 encendido
    esperar(1000);                 //  100 apagado             
    Globales::elLED.brillar(100);  // 100 encendido
    esperar(400);                  //  100 apagado
    Globales::elLED.brillar(100);  // 100 encendido
    esperar(400);                  //  100 apagado
    Globales::elLED.brillar(100);  // 100 encendido
    esperar(400);                  //  100 apagado
    Globales::elLED.brillar(100);  // 100 encendido
    esperar(400);                  //  100 apagado
    Globales::elLED.brillar(1000); // 1000 encendido
    esperar(1000);                 //  100 apagado
    Globales::elLED.brillar(1000); // 1000 encendido
    esperar(1000);                 //  100 apagado
    Globales::elLED.brillar(1000); // 1000 encendido
    esperar(1000);                 //  100 apagado
    Globales::elLED.brillar(1000); // 1000 encendido
    esperar(1000);                 //  100 apagado
    Globales::elLED.brillar(1000); // 1000 encendido
    esperar(1000);                 //  100 apagado
}
// --------------------------------------------------------------
void medicionesco2()
{
    using namespace Loop;
    using namespace Globales;
    int valorCO2 = elMedidor.medirCO2();
    // Llamada para publicar variable
    elPublicador.publicarCO2(valorCO2,
                             cont,
                             1000 // intervalo de emisión
    );
}
// --------------------------------------------------------------
void medicionesTemperatura()
{
    using namespace Loop;
    using namespace Globales;
    int valorTemperatura = elMedidor.medirTemperatura();
    elPublicador.publicarTemperatura(valorTemperatura,
                                     cont,
                                     1000 // intervalo de emisión
    );
}
//---------------------------------------------------------------
void envioLibreBLE()
{
    using namespace Loop;
    using namespace Globales;
    // Prueba para emitir un iBeacon libre
    // Al terminar la prueba hay que hacer Publicador::laEmisora privado

    char datos[21] = {
        'H', 'o', 'l', 'a',
        ' ', 'e', 's', 't',
        'o', ' ', 'e', 's',
        ' ', 'u', 'n', ' ',
        'e', 'j', 'e', 'm',
        'p'};

    elPublicador.laEmisora.emitirAnuncioIBeaconLibre(&datos[0], 21);
    // elPublicador.laEmisora.emitirAnuncioIBeaconLibre("MolaMolaMolaMolaMolaM", 21);
}

void loop()
{
    using namespace Loop;
    using namespace Globales;

    cont++;

    elPuerto.escribir("\n---- loop(): empieza ");
    elPuerto.escribir(cont);
    elPuerto.escribir("\n");

    lucecitas();
    medicionesco2();
    /*
    medicionesTemperatura();
    envioLibreBLE();
    */
    esperar(2000);
    elPublicador.laEmisora.detenerAnuncio();

    elPuerto.escribir("---- loop(): acaba ");
    elPuerto.escribir(cont);
    elPuerto.escribir("\n");
}

