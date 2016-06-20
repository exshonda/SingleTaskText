#include <Wire.h>
#include <Digital_Light_TSL2561.h>
#include <SeeedOLED.h>

void setup() {
  Wire.begin();
  TSL2561.init();
  SeeedOled.init();
  SeeedOled.deactivateScroll();
  SeeedOled.setNormalDisplay();
  SeeedOled.clearDisplay();
}

int OLEDCount = 0;

void loop() {
  int lux;

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
