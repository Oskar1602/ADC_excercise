#include <Arduino.h>

const int potPin = A0; // Pin, an dem das Potentiometer angeschlossen ist
const unsigned long interval = 500; // Intervall in Millisekunden (0.5 Sekunden)

unsigned long previousMillis = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

        int analogValue = analogRead(potPin);
        float voltage = analogValue * (5.0 / 1023.0);

        Serial.print("Potentiometer analog value = ");
        Serial.print(voltage, 2); // 2 Nachkommastellen
        Serial.println(" V");
    }
}
