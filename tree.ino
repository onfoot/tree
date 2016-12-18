#include "FastLED.h"

#define NUM_LEDS 50
#define DATA_PIN 10
    
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5,100);
}

uint8_t thisdelay = 20;

float hue=0;
float vphase = 0.0;

void loop () {
  EVERY_N_MILLISECONDS(thisdelay) {
    fill();
  }
  FastLED.show();
}

void fill() {
  for (int k=0; k<NUM_LEDS; k++) {
    leds[k] = CHSV(floor(hue)+k, 255, max(32, sin8(vphase + k*float(255.0/NUM_LEDS))));
  }
  if (hue >= 255.0) {
    hue = 0;
  } else {
    hue += 0.2;
  }
  
  vphase -= 0.3;
}

