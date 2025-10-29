const int rledPin = 9;
const int gledPin = 10;
const int bledPin = 11;

int maxBrightness = 0;

int currentBrightness = 0;
int fadingDirection = 1;
unsigned long previousMillis = 0;
int interval = 1000;

void setup(){
  pinMode(rledPin,OUTPUT);
  pinMode(gledPin,OUTPUT);
  pinMode(bledPin,OUTPUT);
}
void loop(){
  int sensorValue = analogRead(A0);
  maxBrightness = map(sensorValue , 0 , 1023 , 0, 255);
  unsigned long currentMillis = millis();
  int fadingAmount = fadingDirection * map(currentMillis - previousMillis, 0, interval , 0, maxBrightness);
  currentBrightness = currentBrightness + fadingAmount;
  if(currentBrightness >= 255){
    currentBrightness =255;
    fadingDirection = -fadingDirection ;
  }
  if(currentBrightness <= 0){
    currentBrightness = 0;
    fadingDirection = -fadingDirection;
  }
  analogWrite(rledPin , currentBrightness);
  analogWrite(gledPin , currentBrightness);
  analogWrite(bledPin , currentBrightness);
  previousMillis =currentMillis;
  delay(1);
}