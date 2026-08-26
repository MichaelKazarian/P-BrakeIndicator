#include <Arduino.h>

// Для ATtiny202 в PlatformIO піни позначаються через PIN_PA6, PIN_PA7 тощо.
// Фізична ніжка 7 чіпа — це порт PA3.
const uint8_t LED_PIN = PIN_PA3; 

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}

