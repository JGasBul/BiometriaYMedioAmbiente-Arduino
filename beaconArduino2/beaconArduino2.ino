#include "./libraries/EmisoraBLE.h"
#include "./libraries/LED.h"
#include "./libraries/libraries.h"
#include "./libraries/Medidor.h"
#include "./libraries/Publicador.h"
#include "./libraries/PuertoSerie.h"
#include "./libraries/ServicioEnEmisora.h"

/*!
* \brief App para enviar beacons desde un arduino. 
* \details Columna vertebral del proyecto. Desde aqui se controla todo
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
/**
 * Setup del programa
*/
void setup()
{
    Globales::elPuerto.esperarDisponible();
    Globales::elPublicador.encenderEmisora();

    esperar(1000);
    Globales::elPuerto.escribir("---- setup(): fin ---- \n ");
}

/**
 * Metodo para encender y apagar el LED
*/
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
/**
 * Metodo para mandar la medida de CO2
*/
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
/**
 * Metodo para medir y mandar la temperatura
*/
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
/**
 * Metodo para enviar un mensaje cualquiera como beacon
*/
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
/**
 * Loop principal del programa
*/
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
