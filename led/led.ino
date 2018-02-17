int ledPin = 13;
int status;
void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop(){
  digitalWrite(ledPin, HIGH);
  status = digitalRead(ledPin);
  Serial.println(status);
  delay(1000);
  digitalWrite(ledPin, LOW);
  status = digitalRead(ledPin);
  Serial.println(status);
  delay(1000);
}
