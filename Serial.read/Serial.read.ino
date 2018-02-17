char comchar;
int status;
int ledPin = 13;
void setup(){
  Serial.begin(9600);
  while(Serial.read() >= 0){}
  pinMode(ledPin, OUTPUT);
  
}

void loop(){
  comchar = Serial.read();
  Serial.print("Serial.read:");
  Serial.println(comchar);
  if(comchar == '1'){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
  
   //digitalWrite(ledPin, HIGH);
  status = digitalRead(ledPin);
  Serial.print("The key value:");
  Serial.println(status);
  delay(1000);
}
//Serial.read()每次读取一个字符为char型,不是int型.

