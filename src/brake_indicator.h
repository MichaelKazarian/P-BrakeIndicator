#ifndef BRAKE_INDICATOR_H
#define BRAKE_INDICATOR_H

#include <Arduino.h>

// --- НАЛАШТУВАННЯ ПІНІВ ДЛЯ ATtiny202 ---
// Фізична ніжка 4 (PA1) -> Цифровий вхід для датчика ручника
#define SENSOR_DIGITAL PIN_PA1  

// Фізична ніжка 5 (PA2) -> Аналоговий вхід датчика (залишено на майбутнє)
#define SENSOR_ANALOG  PIN_PA2  

// Фізична ніжка 7 (PA3) -> Вихід на транзистор/динамік (Таймер TCA0 WO3)
#define SPEAKER_PIN    PIN_PA3  

// Фізична ніжка 2 (PA6) -> Тестовий світлодіод індикації
#define LED_PIN        PIN_PA6  

// --- ТАЙМІНГИ ТА НАЛАШТУВАННЯ АЛГОРИТМУ ---
// Пауза перед початком сигналу (0.7 сек)
#define DELAY_BEFORE_START 700 

// Пауза між циклами відтворення (1.2 сек), щоб звук не дратував
#define DELAY_BETWEEN_ALER_CYCLES 1200

// Тривалість звучання кожної ноти (мс)
#define NOTE_DURATION 150

// Пауза між нотами всередині мелодії (мс)
#define NOTE_PAUSE 50

// --- ЧАСТОТИ НОТ (Герци) ---
#define NOTE_E6 1318  // Мі6
#define NOTE_G6 1567  // Соль6
#define NOTE_B6 1975  // Сі6

#endif // BRAKE_INDICATOR_H
