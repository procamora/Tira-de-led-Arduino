#ifndef Tira_de_led_Arduinoh
#define Tira_de_led_Arduino_h

#include <WirelessRemoteController.h>

#define DEBUG false

#define LED_R 7      //ROJO
#define LED_G 6      //VERDE
#define LED_B 5      //AZUL

#define LECTURA 9     //

#define INPUT_D 10     //APAGAR
#define INPUT_C 11     //AZUL
#define INPUT_B 12     //VERDE
#define INPUT_A 13     //ROJO


//Info: http://www.prometec.net/tira-de-leds/


//inicio contador en 1 para que en la primera pulsacion entre en el rojo
boolean currentButton = false;  //Contiene el estado actual del boton

unsigned long TIEMPO_ACTUAL = 0; //last time messages' scan has been done
#define TIEMPO_ESPERA 100 // mean time between scan messages

// Create wireless remote controller instance with D3, D4, D5, D6 pins as data pins
WirelessRemoteController remote_controller(INPUT_A, INPUT_B, INPUT_C, INPUT_D);

#endif
