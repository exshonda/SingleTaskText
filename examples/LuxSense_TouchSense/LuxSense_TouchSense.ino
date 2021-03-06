#include <Wire.h>
#include <Digital_Light_TSL2561.h>
#include <SeeedOLED.h>

#define TOUCH_PIN 3
#define LED_PIN  4

int PreTouchValue = 0;
int TouchState = 0;
int LEDState = 0;

void setup() {
  Wire.begin();
  TSL2561.init();
  SeeedOled.init();
  SeeedOled.deactivateScroll();
  SeeedOled.setNormalDisplay();
  SeeedOled.clearDisplay();
  
  pinMode(TOUCH_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);  
}

int OLEDCount = 0;

void CheckTouch(){
   int TouchValue = digitalRead(TOUCH_PIN);

  if ((PreTouchValue == 0) && (TouchValue == 1) && (TouchState == 0)) {
    TouchState = 1;
  }

  if ((PreTouchValue == 1) && (TouchValue == 0) && (TouchState == 1)) {
    TouchState = 0;
    if (LEDState == 0) {
      LEDState = 1;
      digitalWrite(LED_PIN, HIGH);
    }
    else {
      LEDState = 0;
      digitalWrite(LED_PIN, LOW);
    }
  }
  PreTouchValue = TouchValue; 
}

void loop() {
  int lux;

  CheckTouch();
 
  lux = TSL2561.readVisibleLux();
  
  SeeedOled.setTextXY(0, 0);
  SeeedOled.putString("Digital Light");
  SeeedOled.setTextXY(1, 0);
  SeeedOled.putString("Sensor Value is");
  SeeedOled.setTextXY(2, 0);
  SeeedOled.putNumber(lux);
  SeeedOled.putString(" lux      ");
  SeeedOled.setTextXY(4, 0);
  SeeedOled.putString("Count is");
  SeeedOled.setTextXY(5, 0);
  SeeedOled.putNumber(OLEDCount++);  
}
