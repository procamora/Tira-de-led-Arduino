/**
   @file Tira-de-led-Arduino.ino
   @brief Gestion de una tira de led
   @author Pablo Rocamora pablojoserocamora@gmail.com
   @date 14/12/2016
*/

//Info: http://www.prometec.net/tira-de-leds/

#define DEBUG true

#define LED_R 2      //ROJO
#define LED_G 3      //VERDE
#define LED_B 4      //AZUL

#define INPUT_D 6     //APAGAR
#define INPUT_A 7     //ROJO
#define INPUT_B 8     //VERDE
#define INPUT_C 9     //AZUL

#define LECTURA 5     //

//inicio contador en 1 para que en la primera pulsacion entre en el rojo
boolean currentButton = false;  //Contiene el estado actual del boton

unsigned long TIEMPO_ACTUAL = 0; //last time messages' scan has been done
#define TIEMPO_ESPERA 100 // mean time between scan messages

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(INPUT_A, INPUT);
  pinMode(INPUT_B, INPUT);   // Para leel el boton
  pinMode(INPUT_C, INPUT);
  pinMode(INPUT_D, INPUT);
  pinMode(LECTURA, INPUT);

  if (DEBUG) {
    Serial.begin(115200);
    Serial.println("inicio");
  }
}

String checkBoolean(bool valor) {
  if (String(valor) == "1")
    return "True";
  return "False";
}

void loop() {
  if (millis() > TIEMPO_ACTUAL + TIEMPO_ESPERA) {
    TIEMPO_ACTUAL = millis();

    if (digitalRead(LECTURA)) {    // Si hay dato valido
      //if (DEBUG)
      // Serial.println("currentButton: " + checkBoolean(currentButton));

      if (digitalRead(INPUT_A)) {
        bool estado = digitalRead(LED_R);
        if (DEBUG)
          Serial.println("rojo: " + checkBoolean(!estado));
        digitalWrite(LED_R, !estado);
      }

      if (digitalRead(INPUT_B)) {
        bool estado = digitalRead(LED_G);
        if (DEBUG)
          Serial.println("verde: " + checkBoolean(!estado));
        digitalWrite(LED_G,  !estado);
      }

      if (digitalRead(INPUT_C)) {
        bool estado = digitalRead(LED_B);
        if (DEBUG)
          Serial.println("azul: " + checkBoolean(!estado));
        digitalWrite(LED_B,  !estado);
      }

      if (digitalRead(INPUT_D)) {
        if (DEBUG)
          Serial.println("APAGAR");
        digitalWrite(LED_R,  LOW);
        digitalWrite(LED_G,  LOW);
        digitalWrite(LED_B,  LOW);
      }

      if (DEBUG) {
        Serial.println();
        Serial.println("rojo: " + checkBoolean(digitalRead(LED_R)));
        Serial.println("verde: " + checkBoolean(digitalRead(LED_G)));
        Serial.println("azul: " + checkBoolean(digitalRead(LED_B)));
        Serial.println();
        Serial.println();
        Serial.println();
      }
      delay(300);
    }
  }
}


