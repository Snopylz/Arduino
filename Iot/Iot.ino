#include <SoftwareSerial.h>

#include "Obloq.h"
 
//MQTT连接相关参数 MQTT parameters
const String ssid = "TP-LINK_AEE0BC";
const String password = "Qaws12ed3";
const String iot_id = "HJZnQDsHPG";
const String iot_pwd = "ByGnQvirvf";
const String topic = "HJjvPsrDz";
 
 //led小灯引脚 Led pin parameter
int ledPin = 13;
bool sendPingFlag = true; 
bool subscribeFlag = true; 
unsigned long currentTime = 0;                          
 
SoftwareSerial softSerial(10, 11);         // RX, TX
	
Obloq olq(softSerial, ssid, password);
 
void handleRaw(String& data)
{
    Serial.println(data);   //串口打印返回的数据; Serial print the returned data
}
 
void subscribeMessageHandle(const String topicStr,const String message)
{
    if(topicStr == topic)
    {
        if(message == "1")
          digitalWrite(ledPin,HIGH);
        else if(message == "2")
          digitalWrite(ledPin,LOW);
    }
}
 
void setup()
{
    Serial.begin(9600);
	
		    softSerial.begin(9600);
    pinMode(ledPin,OUTPUT);
    olq.setHandleRaw(handleRaw);
    olq.setReceiveCallBak(subscribeMessageHandle);
}
void loop()
{
    olq.update();
    if(sendPingFlag && olq.getWifiState()== OBLOQWIFICONNECT)
    {
      sendPingFlag = false;
      olq.connect(iot_id,iot_pwd);
    }
    if(subscribeFlag && olq.getMqttConnectState())
    {
      subscribeFlag = false;
      //监听Topic; Subscribe Topic
      olq.subscribe(topic);
    }
}	
