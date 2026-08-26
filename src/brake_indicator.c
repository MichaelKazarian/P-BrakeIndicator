#include <Arduino.h>
#include "brake_indicator.h"

unsigned long handbrakeTimer = 0;
bool isBraking = false;

// Прототипи функцій
void playWarningMelody(void);
void playToneManually(uint16_t half_period_us, uint16_t duration_ms);

void setup(void) {
  pinMode(SENSOR_DIGITAL, INPUT_PULLUP);
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

// Кастомна заміна функції tone()
void playToneManually(uint16_t half_period_us, uint16_t duration_ms) {
  // Розраховуємо кількість циклів коливання для заданої тривалості
  // Сумарний час одного циклу = half_period_us * 2 мкс
  uint32_t total_cycles = ((uint32_t)duration_ms * 500) / half_period_us;
  
  //digitalWrite(LED_PIN, HIGH);
  for (uint32_t i = 0; i < total_cycles; i++) {
    digitalWrite(SPEAKER_PIN, HIGH);
    delayMicroseconds(half_period_us);
    digitalWrite(SPEAKER_PIN, LOW);
    delayMicroseconds(half_period_us);
  }
  //digitalWrite(LED_PIN, LOW);
}

void playWarningMelody(void) {
  // 1. Мі6
  playToneManually(NOTE_E6_HALF_PERIOD, NOTE_DURATION);
  delay(NOTE_PAUSE);
  
  // 2. Соль6
  playToneManually(NOTE_G6_HALF_PERIOD, NOTE_DURATION);
  delay(NOTE_PAUSE);
  
  // 3. Сі6
  playToneManually(NOTE_B6_HALF_PERIOD, NOTE_DURATION);
}

void loop(void) {
  // Читаємо стан ручника (HIGH означає активний ручник)
  bool handbrakeActive = (digitalRead(SENSOR_DIGITAL) == LOW);

  if (handbrakeActive) {
    digitalWrite(LED_PIN, HIGH);
    if (!isBraking) {
      handbrakeTimer = millis(); 
      isBraking = true;
    }

    if (millis() - handbrakeTimer > DELAY_BEFORE_START) {
      playWarningMelody();
      delay(DELAY_BETWEEN_ALER_CYCLES); 
    }
  } else {
    isBraking = false;
    digitalWrite(SPEAKER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
  }
}
