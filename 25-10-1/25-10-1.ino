int rledPin = 3;
int gledPin = 4;
int bledPin = 5;
int pushButton = 2;
int buttonState = 0;
bool ButtonPressed = false;
int ledcolor = 0;

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
    ledcolor = ledcolor + 1;
    ButtonPressed = true;
  }
  if(buttonState == LOW && ButtonPressed){
    ButtonPressed = false;
  }
  if(ledcolor = 0){
    digitalWrite(rledPin,HIGH);
    digitalWrite(gledPin,HIGH);
    digitalWrite(bledPin,HIGH);
  }
  if(ledcolor = 1){
    digitalWrite(rledPin,LOW);
    digitalWrite(gledPin,HIGH);
    digitalWrite(bledPin,HIGH);
  }
  if(ledcolor = 2){
    digitalWrite(rledPin,HIGH);
    digitalWrite(gledPin,LOW);
    digitalWrite(bledPin,HIGH);
  }
  if(ledcolor = 3){
    digitalWrite(rledPin,HIGH);
    digitalWrite(gledPin,HIGH);
    digitalWrite(bledPin,LOW);
  }
  if(ledcolor = 4){
    digitalWrite(rledPin,LOW);
    digitalWrite(gledPin,LOW);
    digitalWrite(bledPin,HIGH);
  }
  if(ledcolor = 5){
    digitalWrite(rledPin,LOW);
    digitalWrite(gledPin,HIGH);
    digitalWrite(bledPin,LOW);
  }
  else if(ledcolor = 6){
    digitalWrite(rledPin,HIGH);
    digitalWrite(gledPin,LOW);
    digitalWrite(bledPin,LOW);
  }
  else if(ledcolor = 7){
    digitalWrite(rledPin,LOW);
    digitalWrite(gledPin,LOW);
    digitalWrite(bledPin,LOW);
  }
  if(ledcolor = 8){
    ledcolor = 0;
  }
}
