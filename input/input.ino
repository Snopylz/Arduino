int key = A0;
int ledPin = 13;
int keyValue = 0;
int status = 0;
void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(key, INPUT);
}

void loop(){
  keyValue = analogRead(key);
  if(keyValue > 500){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
  status = digitalRead(ledPin);
  Serial.println(status);
  
}
