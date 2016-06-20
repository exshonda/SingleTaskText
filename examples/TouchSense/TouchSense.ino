#define TOUCH_PIN 3
#define LED_PIN  4

int PreTouchValue = 0;
int TouchState = 0;
int LEDState = 0;

void setup() {
  pinMode(TOUCH_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  int TouchValue = digitalRead(TOUCH_PIN);

  if ((PreTouchValue == 0) && (TouchValue == 1) && (TouchState = 0)) {
    TouchState = 1;
  }

  if ((PreTouchValue == 1) && (TouchValue == 0) && (TouchState = 1)) {
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
