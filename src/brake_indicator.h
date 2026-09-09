#ifndef BRAKE_INDICATOR_H
#define BRAKE_INDICATOR_H

#include <Arduino.h>

// --- Pin configuration for ATtiny202 ---
#define SENSOR_DIGITAL PIN_PA7
#define SENSOR_ANALOG  PIN_PA3
#define SPEAKER_PIN    PIN_PA1
#define LED_PIN        PIN_PA6

// --- Timing and algorithm settings ---
#define DELAY_BEFORE_START 700 
#define DELAY_BETWEEN_ALER_CYCLES 1200
#define NOTE_DURATION 150
#define NOTE_PAUSE 50

// --- Note periods in microseconds (1000000 / Hz) ---
#define NOTE_E6_HALF_PERIOD 379  // 1318 Hz -> full period 758 us
#define NOTE_G6_HALF_PERIOD 319  // 1567 Hz -> full period 638 us
#define NOTE_B6_HALF_PERIOD 253  // 1975 Hz -> full period 506 us

void playWarningMelody(void);
void playTone(uint16_t halfPeriodUs, uint16_t durationMs);

#endif // BRAKE_INDICATOR_H
