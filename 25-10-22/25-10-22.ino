const int rledPin = 9;
const int gledPin = 10;
const int bledPin = 11;

const int buttonPin = 2;

int buttonState = 0;
bool buttonPressed = false;
unsigned long pressingTime = 0;
const int longPressInterval = 1000;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(rledPin, OUTPUT);
  pinMode(gledPin, OUTPUT);
  pinMode(bledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && !buttonPressed) {
    pressingTime = millis();
    buttonPressed = true;
    Serial.println("Button Pressed Down.");
    SetRGBLEDColor(10, 10, 0);
  }

  if (buttonState == HIGH && buttonPressed) {
    unsigned long releaseTime = millis();
    unsigned long pressDuration = releaseTime - pressingTime;

    if (pressDuration < longPressInterval) {
      Serial.print("ShortClick! Duration: ");
      Serial.print(pressDuration);
      Serial.println("ms");
      SetRGBLEDColor(0, 255, 0);
      delay(300);
    } else {
      Serial.print("LongClick! Duration: ");
      Serial.print(pressDuration);
      Serial.println("ms");
      SetRGBLEDColor(255, 0, 0);
      delay(300);
    }

    buttonPressed = false;
    SetRGBLEDColor(0, 0, 0);
  }
}

void SetRGBLEDColor(int r, int g, int b) {
  analogWrite(rledPin, r);
  analogWrite(gledPin, g);
  analogWrite(bledPin, b);
}