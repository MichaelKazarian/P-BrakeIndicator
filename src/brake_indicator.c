#include <Arduino.h>
#include "brake_indicator.h"

unsigned long handbrakeTimer = 0;
bool isBraking = false;

void setup(void) {
  pinMode(SENSOR_DIGITAL, INPUT_PULLUP);
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void playTone(uint16_t halfPeriodUs, uint16_t durationMs) {
  uint32_t cyclesTotalUs = (uint32_t)durationMs * 1000UL;
  uint32_t elapsedUs = 0;

  digitalWrite(LED_PIN, HIGH);
  while (elapsedUs < cyclesTotalUs) {
    digitalWrite(SPEAKER_PIN, HIGH);
    delayMicroseconds(halfPeriodUs);
    digitalWrite(SPEAKER_PIN, LOW);
    delayMicroseconds(halfPeriodUs);
    elapsedUs += (uint32_t)halfPeriodUs * 2;
  }
  digitalWrite(LED_PIN, LOW);
}

void playWarningMelody(void) {
  playTone(NOTE_E6_HALF_PERIOD, NOTE_DURATION); delay(NOTE_PAUSE); // E6 (Мі6)
  playTone(NOTE_G6_HALF_PERIOD, NOTE_DURATION); delay(NOTE_PAUSE); // G6 (Соль6)
  playTone(NOTE_B6_HALF_PERIOD, NOTE_DURATION); // B6 (Сі6)
}

void loop(void) {
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
