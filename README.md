# ADC_excercise

## Ziel
Einlesen eines analogen Wertes über den ADC des ATmega328P und Ausgabe über die serielle Schnittstelle. Die Konvertierung wird manuell über Register gesteuert.

## Verwendete Register und Bits

### ADMUX – ADC Multiplexer Selection Register
- REFS1:0 – Auswahl der Referenzspannung  
  Einstellung: 01 → AVcc mit externem Kondensator an AREF-Pin
- MUX3:0 – Auswahl des ADC-Kanals  
  Einstellung: 0000 → ADC0 (Pin A0, Potentiometer)

### ADCSRA – ADC Control and Status Register A
- ADEN – ADC Enable  
  Aktiviert den ADC
- ADSC – ADC Start Conversion  
  Startet eine Konvertierung, wenn gesetzt
- ADIE – ADC Interrupt Enable  
  Aktiviert ADC Interrupt nach Abschluss der Wandlung
- ADIF – ADC Interrupt Flag  
  Wird vom ADC gesetzt, wenn Konvertierung abgeschlossen ist
- ADPS2:0 – ADC Prescaler Select Bits  
  Setzt den Teilerfaktor für den ADC-Takt

## Prescaler-Einstellung

Der ADC benötigt eine Taktfrequenz zwischen 50 kHz und 200 kHz für präzise Messungen.  
Bei einem Systemtakt von 16 MHz:

| Prescaler | ADC-Frequenz | Geeignet |
|-----------|---------------|----------|
| 128       | 125 kHz       | Ja       |

Einstellung: ADPS2 = 1, ADPS1 = 1, ADPS0 = 1
