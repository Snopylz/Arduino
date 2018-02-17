#include <dht11.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2);
int senorValue = 0;
dht11 DHT;
#define DHT11_PIN 4
void setup(){
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  Serial.println("Type,\tstatus,Humidity,Temperature");
  lcd.print("Humidity:");
  lcd.setCursor(0,1);
  lcd.print("Temp:");
}
  void loop(){
    int chk;
    Serial.print("DHT11,\t");
    chk = DHT.read(DHT11_PIN);
    switch(chk){
      case DHTLIB_OK:
        Serial.print ("OK!\t");
        break;
      case DHTLIB_ERROR_CHECKSUM:
        Serial.print ("Checksum error,\t");
        break;
      case DHTLIB_ERROR_TIMEOUT:
        Serial.print("Time out error,\t");
        break;
      default:
        Serial.print("Unknown error,\t");
        break;
    }
    
    Serial.print(DHT.humidity, 1);
    Serial.print("\t");
    Serial.println(DHT.temperature, 1);
    lcd.setCursor(10, 0);
    lcd.print(DHT.temperature, 2);
    lcd.setCursor(6,1);
    lcd.print(DHT.humidity, 2);
    lcd.setCursor(0,2);
    lcd.print("Google");

    delay(1000);
  }

