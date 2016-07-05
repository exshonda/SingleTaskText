#include <ChainableLED.h>
#include <Wire.h>

#define NUM_LEDS 1
ChainableLED leds(8, 9, NUM_LEDS);

void setup() {
  leds.init();
}

void loop() {
  leds.setColorRGB(0, 250, 0, 0);
  delay(250);

  leds.setColorRGB(0, 0, 250, 0);
  delay(250);

  leds.setColorRGB(0, 0, 0, 250);
  delay(250);
}
