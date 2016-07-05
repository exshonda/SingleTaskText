#include <ChainableLED.h>
#include <Wire.h>

#define LED_PIN 4
#define NUM_LEDS 1

ChainableLED leds(8, 9, NUM_LEDS);

int led_count;
int led_state;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  leds.init();
  led_count = 0;
  led_state = 0;
}

void led_check(){
  led_count++;
  if(led_count == 4) {
    led_count = 0;
    if(led_state == 0) {
      digitalWrite(LED_PIN, HIGH);
      led_state = 1;
    }
    else {
      digitalWrite(LED_PIN, LOW);
      led_state = 0;
    }
  }
}

void loop() {
  leds.setColorRGB(0, 250, 0, 0);
  delay(250);
  led_check();

  leds.setColorRGB(0, 0, 250, 0);
  delay(250);
  led_check();

  leds.setColorRGB(0, 0, 0, 250);
  delay(250);
  led_check();
}
