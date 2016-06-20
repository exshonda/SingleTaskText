#include <ChainableLED.h>
#include <Wire.h>

#define NUM_LEDS 1
ChainableLED leds(8, 9, NUM_LEDS);

void setup() {
  leds.init();
}

void loop() {
  int i;
  for(i = 0; i < 25; i++){
    leds.setColorRGB(0, i*10, 0, 0);
    delay(10);
  }
  for(i = 0; i < 25; i++){
    leds.setColorRGB(0, 0, i*10, 0);
    delay(10);
  }
  for(i = 0; i < 25; i++){
    leds.setColorRGB(0, 0, 0, i*10);
    delay(10);
  }
}
