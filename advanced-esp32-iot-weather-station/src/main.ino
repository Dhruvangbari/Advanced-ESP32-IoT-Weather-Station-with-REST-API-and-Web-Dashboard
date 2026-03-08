
#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>
#include "sensor_manager.h"
#include "../config/config.h"

WebServer server(80);

void handleWeather(){
  float temp = readTemperature();
  float hum = readHumidity();

  StaticJsonDocument<200> doc;
  doc["temperature"] = temp;
  doc["humidity"] = hum;

  String json;
  serializeJson(doc, json);

  server.send(200, "application/json", json);
}

void setup(){
  Serial.begin(115200);
  initSensor();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println(WiFi.localIP());

  server.on("/api/weather", handleWeather);
  server.begin();
}

void loop(){
  server.handleClient();
}
