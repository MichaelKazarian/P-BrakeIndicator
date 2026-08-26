#include <Arduino.h>
#include "brake_indicator.h"

unsigned long handbrakeTimer = 0;
bool isBraking = false;

// Прототип функції
void playWarningNotes(void);

void setup(void) {
  // Якщо кінцевик автомобіля замикає на масу, змініть на INPUT_PULLUP
  pinMode(SENSOR_DIGITAL, INPUT); 
  
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void playWarningNotes(void) {
  // 1. Мі6
  tone(SPEAKER_PIN, NOTE_E6);
  digitalWrite(LED_PIN, HIGH);
  delay(NOTE_DURATION);
  
  noTone(SPEAKER_PIN);
  digitalWrite(LED_PIN, LOW);
  delay(NOTE_PAUSE);
  
  // 2. Соль6
  tone(SPEAKER_PIN, NOTE_G6);
  digitalWrite(LED_PIN, HIGH);
  delay(NOTE_DURATION);
  
  noTone(SPEAKER_PIN);
  digitalWrite(LED_PIN, LOW);
  delay(NOTE_PAUSE);
  
  // 3. Сі6
  tone(SPEAKER_PIN, NOTE_B6);
  digitalWrite(LED_PIN, HIGH);
  delay(NOTE_DURATION);

  noTone(SPEAKER_PIN);
  digitalWrite(LED_PIN, LOW);
}

void loop(void) {
  // Читаємо стан ручника (HIGH означає активний ручник)
  bool handbrakeActive = (digitalRead(SENSOR_DIGITAL) == HIGH);

  if (handbrakeActive) {
    if (!isBraking) {
      handbrakeTimer = millis(); 
      isBraking = true;
    }

    if (millis() - handbrakeTimer > DELAY_BEFORE_START) {
      playWarningNotes();
      delay(DELAY_BETWEEN_ALER_CYCLES); 
    }
  } else {
    isBraking = false;
    noTone(SPEAKER_PIN);
    digitalWrite(LED_PIN, LOW);
  }
}
