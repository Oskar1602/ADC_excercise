#include <Arduino.h>

#define ADC_CHANNEL 0

volatile uint16_t poti_value = 0;
unsigned long lastPrintTime = 0;
const unsigned long interval = 500; // 500 ms interval

void setup() {
  Serial.begin(115200);

  // Select ADC channel (ADC0)
  ADMUX = (ADMUX & 0b11110000) | ADC_CHANNEL;

  // Use AVcc as reference voltage
  ADMUX |= (1 << REFS0);

  // Enable ADC, set prescaler to 128, enable ADC interrupt
  ADCSRA = (1 << ADEN)     // Enable ADC
         | (1 << ADIE)     // Enable ADC interrupt
         | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Prescaler 128

  sei();                   // Enable global interrupts

  ADCSRA |= (1 << ADSC);   // Start first conversion
}

// Called whenever an ADC conversion is complete
ISR(ADC_vect) {
  poti_value = ADC;         // Read ADC value
  ADCSRA |= (1 << ADSC);    // Start next conversion
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastPrintTime >= interval) {
    lastPrintTime = currentTime;

    float voltage = (poti_value * 5.0) / 1023.0;

    Serial.print("Potentiometer analog value = ");
    Serial.print(voltage, 2);
    Serial.println(" V");
  }

}
