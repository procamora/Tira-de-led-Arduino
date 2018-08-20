/**
   @file Tira-de-led-Arduino.ino
   @brief Gestion de una tira de led
   @author Pablo Rocamora pablojoserocamora@gmail.com
   @date 14/12/2016
*/
#include "Tira-de-led-Arduino.h"

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
    Serial.begin(9600);
    Serial.println("inicio");
  }
}

String checkBoolean(bool valor) {
  if (String(valor) == "1")
    return "True";
  return "False";
}

void processPin(int pin, int led, String info) {
  if (digitalRead(pin)) {
    bool estado = digitalRead(led);
    if (DEBUG)
      Serial.println(info + ": " + checkBoolean(!estado));
    digitalWrite(led, !estado);
  }
}

void loop() {
  if (millis() > TIEMPO_ACTUAL + TIEMPO_ESPERA) {
    TIEMPO_ACTUAL = millis();

    bool current_rx[4];
    if (remote_controller.getCurrentValue(current_rx)) {   // Si hay dato valido
      if (DEBUG)
        Serial.println("currentButton: " + checkBoolean(currentButton));

      processPin(INPUT_A, LED_R, "rojo");
      processPin(INPUT_B, LED_G, "verde");
      processPin(INPUT_C, LED_B, "azul");

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
    }
    delay(500);
  }
}


