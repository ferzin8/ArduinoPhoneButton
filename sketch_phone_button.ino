#include "HID-Project.h"

const int buttonPin = 2; 
int lastButtonState = HIGH; 
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // Задержка для подавления дребезга

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); 
  Consumer.begin();
}

void loop() {
  int reading = digitalRead(buttonPin); 

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    static int stableButtonState = HIGH;
    if (reading != stableButtonState) {
      stableButtonState = reading;

      if (stableButtonState == LOW) {
        // Consumer.write(MEDIA_PLAY_PAUSE); 
        Consumer.write(MEDIA_VOLUME_UP);
        // Consumer.write(MEDIA_VOLUME_DOWN);
        // Consumer.write(MEDIA_NEXT);
        // Consumer.write(MEDIA_PREVIOUS);
      }
    }
  }
  lastButtonState = reading;
}
