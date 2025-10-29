const int rledPin = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(rledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A8);
  Serial.println(sensorValue);
  if(sensorValue > 500 ){
    digitalWrite(rledPin, LOW);
  }
  else{
    digitalWrite(rledPin, HIGH);
  }
  delay(1);
}
