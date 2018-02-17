#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup(){
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop()
{
  int val;
  int val2;
  val = analogRead(0);
  val2 = analogRead(A5);
  Serial.println(val, DEC);
  Serial.println(val2, DEC);
  lcd.setCursor(0, 0);
  lcd.print(val);
  lcd.setCursor(0,1);
  lcd.print("Google");
  delay(500);
}

