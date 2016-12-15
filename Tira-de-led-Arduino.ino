/**
   @file Tira-de-led-Arduino.ino
   @brief Gestion de una tira de led
   @author Pablo Rocamora pablojoserocamora@gmail.com
   @date 14/12/2016
*/

//Info: http://www.prometec.net/tira-de-leds/

//inicio contador en 1 para que en la primera pulsacion entre en el rojo
int contador = 1;

const int LED_B = D3;      //AZUL
const int LED_R = D6;      //ROJO
const int LED_G = D9;      //VERDE
const int BUTTON = D2;     //Conexion del boton
boolean lastButton = LOW;   //contiene el estado anterioR del boton
boolean currentButton = LOW;  //Contiene el estado actual del boton

void setup() {
  pinMode (LED_B, OUTPUT);
  pinMode (LED_R, OUTPUT);
  pinMode (LED_G, OUTPUT);
  pinMode (BUTTON, INPUT);
  Serial.begin(115200);
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
    switch (contador) {
      case 0:
        Serial.println("APAGAR");
        contador++;
        digitalWrite(LED_B, LOW);
        digitalWrite(LED_R, LOW);
        digitalWrite(LED_G, LOW);
        break;

      case 1: //ROJO
        Serial.println("rojo 0");
        contador++;
        digitalWrite(LED_B, LOW);
        digitalWrite(LED_R, HIGH);
        digitalWrite(LED_G, LOW);
        break;

      case 2: //VERDE
        Serial.println("azul 1");
        contador++;
        digitalWrite(LED_B, LOW);
        digitalWrite(LED_R, LOW);
        digitalWrite(LED_G, HIGH);
        break;

      case 3: //AZUL
        Serial.println("verde 2");
        contador = 0;
        digitalWrite(LED_B, HIGH);
        digitalWrite(LED_R, LOW);
        digitalWrite(LED_G, LOW);
        break;

      default:  //nunca debria llegar aqui
        contador = 0;
        Serial.println("HAY ALGUN FALLO CON EL CONTADOR");
        Serial.println(contador);
        break;
    }
    Serial.println(contador);
    //delay(500);
  }

  lastButton = currentButton;
}

