const int rLEDPin = 9;
const int gLEDPin = 10;
const int bLEDPin = 11;
void setup() {
  pinMode(6,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(rLEDPin,OUTPUT);
  pinMode(gLEDPin,OUTPUT);
  pinMode(bLEDPin,OUTPUT);

}

void loop() {
  digitalWrite(6,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(gLEDPin,HIGH);
  delay(500);
  digitalWrite(6,LOW);
  digitalWrite(8,LOW);
  digitalWrite(gLEDPin,LOW)
  delay(500);
}
