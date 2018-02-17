void setup(){
 Serial.begin(9600);
}

void loop(){
 int status = analogRead(A0);
 Serial.println(status);
delay(1);
}
