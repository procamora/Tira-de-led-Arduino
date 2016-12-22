/**
   @file Tira-de-led-Arduino.ino
   @brief Gestion de una tira de led
   @author Pablo Rocamora pablojoserocamora@gmail.com
   @date 14/12/2016
*/

//Info: http://www.prometec.net/tira-de-leds/

#define DEBUG true

#define LED_R 3      //ROJO
#define LED_G 4      //VERDE
#define LED_B 5      //AZUL
#define BUTTON 6     //Conexion del boton

//inicio contador en 1 para que en la primera pulsacion entre en el rojo
int contador = 1;
boolean lastButton = LOW;   //contiene el estado anterioR del boton
boolean currentButton = LOW;  //Contiene el estado actual del boton

void setup() {
  pinMode (LED_R, OUTPUT);
  pinMode (LED_G, OUTPUT);
  pinMode (LED_B, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);   // Para leel el boton
  pinMode(13, OUTPUT);         // Para usar un LED de encendido
  if (DEBUG) {
    Serial.begin(115200);
    Serial.println("inicio");
  }
}


/*
  Debouncing Function
  Pass it the previous button state,
  and get back the current debounced button state.
*/
boolean debounce(boolean last) {
  boolean current = digitalRead(BUTTON);    //Read the button state
  if (last != current) {            //if it's different?
    delay(5);               //wait 5ms
    current = digitalRead(BUTTON);      //read it again
  }
  return current;               //return the current value
}


void loop() {
  currentButton = debounce(lastButton);       //read debounced state
  if (lastButton == LOW && currentButton == HIGH) {  //if it was pressed?
    if (DEBUG)
      Serial.println("CONTADOR: " + String(contador));
    //delay(500);

    switch (contador) {
      case 0:
        if (DEBUG)
          Serial.println("APAGAR");
        contador++;
        digitalWrite(LED_R, LOW);
        digitalWrite(LED_G, LOW);
        digitalWrite(LED_B, LOW);
        break;

      case 1: //ROJO
        if (DEBUG)
          Serial.println("rojo");
        contador++;
        digitalWrite(LED_R, HIGH);
        digitalWrite(LED_G, LOW);
        digitalWrite(LED_B, LOW);
        break;

      case 2: //VERDE
        if (DEBUG)
          Serial.println("verde");
        contador++;
        digitalWrite(LED_R, LOW);
        digitalWrite(LED_G, HIGH);
        digitalWrite(LED_B, LOW);
        break;

      case 3: //AZUL
        if (DEBUG)
          Serial.println("azul");
        contador = 0;
        digitalWrite(LED_R, LOW);
        digitalWrite(LED_G, LOW);
        digitalWrite(LED_B, HIGH);
        break;

      default:  //nunca debria llegar aqui
        contador = 0;
        if (DEBUG) {
          Serial.println("HAY ALGUN FALLO CON EL CONTADOR");
          Serial.println(contador);
        }
        break;
    }
  }

  lastButton = currentButton;
}

