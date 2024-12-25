constexpr int LED_PIN = 2;
constexpr int BUTTON_PIN = 3;

bool ledState = LOW;
bool lastButtonState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool buttonState = !digitalRead(BUTTON_PIN);

  if (buttonState && !lastButtonState)
  {
    // Debounce. Компенсация дребезга контактов кнопки.
    delay(10);

    buttonState = !digitalRead(BUTTON_PIN);

    if (buttonState)
    {
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
    }
  }

  lastButtonState = buttonState;
}
