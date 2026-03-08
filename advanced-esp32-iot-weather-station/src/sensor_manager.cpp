
#include "sensor_manager.h"
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void initSensor(){
  dht.begin();
}

float readTemperature(){
  return dht.readTemperature();
}

float readHumidity(){
  return dht.readHumidity();
}
