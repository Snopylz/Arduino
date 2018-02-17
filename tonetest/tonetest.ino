float sinVal;
int toneVal;
void setup(){
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int sensorValue = analogRead(0);
  delay(1);
  Serial.println (sensorValue);
  if (sensorValue < 500 ){
    for( int x = 0;x < 180; x++){
      sinVal = (sin(x*(3.1412/180)));
      toneVal = 2000 + (int (sinVal * 1000));
      tone (8, toneVal);
      delay(2);
    }
  }else{
    noTone(8);
  }
}
//蜂鸣器插pin 8 扭动 A0, 小于500 鸣叫.
