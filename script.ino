#include <DHT.h>
#include <DHT_U.h>
///////
#include "thingProperties.h"
#define DHTpin 2 
#define DHTTYPE DHT11
DHT dht(DHTpin,DHTTYPE);

  void setup() {
  Serial.begin(9600);
  delay(1500); 
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
//////////////////////
  pinMode(DHTpin, INPUT);
}

void loop() {
  ArduinoCloud.update();
  dht.begin();
//Start//
  unsigned long startmillis = 0;
  const long interval = 1000;  //"Delay"
  unsigned long currenttime = millis();
  if (tempoatt - startmillis >= interval){
  currenttime = startmillis;  
  float humi=dht.readHumidity();  
  float temp=dht.readTemperature();
    Serial.print("Temperature [°C] = ");
    Serial.println(temp);
    Serial.print("Humidity [%] = ");
    Serial.println(humi);
    temperature=temp;
    humidity=humi;
  }
}
