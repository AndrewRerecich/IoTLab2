// I, Andrew Rerecich, 000845049, state that no other code has been used other than my own for the following application
#include <Arduino.h>
#include "Freenove_WS2812_Lib_for_ESP32.h"
#define RGB_COUNT 1
#define PIN_RGB_LED 16
#define CHANNEL 0
Freenove_ESP32_WS2812 rgb_led = Freenove_ESP32_WS2812(RGB_COUNT, PIN_RGB_LED, CHANNEL,
TYPE_GRB);
#define PIN_ANALOG 36
int iVal;
int r = 0;
int g = 0;
int b = 0;
float iValConverted;
void setup() {
  Serial.begin(115200);
  rgb_led.begin();
  rgb_led.setBrightness(20);
}
void loop() {
  iVal = analogRead(PIN_ANALOG);
  if (iVal >= 0 && iVal < 2047){
    r = 0;
    g = 0 + (iVal / (2047/255));
    b = 255 - (iVal / (2047/255));
  }
  else if (iVal == 2047){
    r = 0;
    g = 255;
    b = 0;
  }
  else if (iVal > 2047 && iVal <= 4095){
    r = 0 + (iVal / (2047/255));
    g = 255 - (iVal / (2047/255));
    b = 0;
  }
  rgb_led.setLedColorData(0, r, g, b);
  rgb_led.show();
  delay(1);
}
