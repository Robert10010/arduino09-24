int rledPin = 3;
int gledPin = 4;
int bledPin = 5;
int pushButton = 2;
int buttonState = 0;
bool ButtonPressed = false;
unsigned long previousMillis;
unsigned long interval = 1000;
int ledcolor = 0;
bool ledcolorOrder = true;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(rledPin,OUTPUT);
  pinMode(gledPin,OUTPUT);
  pinMode(bledPin,OUTPUT);
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  if(buttonState == HIGH && !ButtonPressed){
    ledcolorOrder = !ledcolorOrder;
    ButtonPressed = true;
  }
  if(buttonState == LOW && ButtonPressed){
    ButtonPressed = false;
  }
  unsigned long  currentMillis = millis();
  if (currentMillis - previousMillis >= interval){
    previousMillis = curren tMillis ; 
    if (ledcolorOrder == true){
      ledcolor = ledcolor + 1;
      if (ledcolor > 3)
        ledcolor = 0;
    }
      else{
        ledcolor = ledcolor - 1;
          if(ledcolor < 0 )
            ledcolor =3;
      }
  }
  if(ledcolor == 0){
    digitalWrite(rledPin,LOW);
    digitalWrite(gledPin,HIGH);
    digitalWrite(bledPin,HIGH);
  }
  else if(ledcolor == 1){
      digitalWrite(rledPin,HIGH);
      digitalWrite(gledPin,LOW);
      digitalWrite(bledPin,HIGH);
  }
  else if(ledcolor == 2){
      digitalWrite(rledPin,HIGH);
      digitalWrite(gledPin,HIGH);
      digitalWrite(bledPin,LOW);
  }
  else if(ledcolor == 3){
      digitalWrite(rledPin,LOW);
      digitalWrite(gledPin,LOW);
      digitalWrite(bledPin,LOW);
  }
}
