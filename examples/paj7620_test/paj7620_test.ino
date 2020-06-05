#include <Wire.h>
#include <IOXhop_PAJ7620.h>

void setup() {
  Serial.begin(9600);

  Serial.println();
  Serial.println();

  Wire.begin();

  if (!PAJ7620.begin()) {
    Serial.println("PAJ7620 communication fail");
    while (1) delay(100);
  }

  Serial.println("PAJ7620 ready for input gestures");
}

void loop() {
  int gesture = PAJ7620.getGesture();
  if (gesture != -1) {
    if (gesture & GESTURE_WAVE) {
      Serial.println("WAVE");
    }
    if (gesture & GESTURE_COUNTER_CLOCKWISE) {
      Serial.println("Counter Clockwise");
    }
    if (gesture & GESTURE_CLOCKWISE) {
      Serial.println("Clockwise");
    }
    if (gesture & GESTURE_BACKWORD) {
      Serial.println("Backward");
    }
    if (gesture & GESTURE_FORWARD) {
      Serial.println("Forward");
    }
    if (gesture & GESTURE_RIGHT) {
      Serial.println("Right");
    }
    if (gesture & GESTURE_LEFT) {
      Serial.println("Left");
    }
    if (gesture & GESTURE_DOWN) {
      Serial.println("Down");
    }
    if (gesture & GESTURE_UP) {
      Serial.println("Up");
    }
  } else {
    Serial.println("PAJ7620 communication fail");
  }
  // delay(100);
}