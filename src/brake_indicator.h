#ifndef BRAKE_INDICATOR_H
#define BRAKE_INDICATOR_H

#include <Arduino.h>

// --- НАЛАШТУВАННЯ ПІНІВ ДЛЯ ATtiny202 ---
#define SENSOR_DIGITAL PIN_PA1
#define SENSOR_ANALOG  PIN_PA2
#define SPEAKER_PIN    PIN_PA3
#define LED_PIN        PIN_PA6

// --- ТАЙМІНГИ ТА НАЛАШТУВАННЯ АЛГОРИТМУ ---
#define DELAY_BEFORE_START 700 
#define DELAY_BETWEEN_ALER_CYCLES 1200
#define NOTE_DURATION 150
#define NOTE_PAUSE 50

// --- ПЕРІОДИ НОТ В МІКРОСЕКУНДАХ (1000000 / Гц) ---
#define NOTE_E6_HALF_PERIOD 379  // 1318 Гц -> повний період 758 мкс (напівперіод 379 мкс)
#define NOTE_G6_HALF_PERIOD 319  // 1567 Гц -> повний період 638 мкс (напівперіод 319 мкс)
#define NOTE_B6_HALF_PERIOD 253  // 1975 Гц -> повний період 506 мкс (напівперіод 253 мкс)

#endif // BRAKE_INDICATOR_H
