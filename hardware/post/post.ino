#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid = "Justin";
const char* password = "123@tumba";
String serverName = "http://137.184.232.255/iot_based_three_phase_fail_monitoring_system/data.php";
void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
  delay(500);
  }
}

void loop() {
    if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;
      //String   httpRequestData = Serial.readStringUntil('\n');
      http.begin(client, serverName);
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      String httpRequestData = Serial.readStringUntil('\n');
      int      httpResponseCode = http.POST(httpRequestData);
      if (httpResponseCode>0) {
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      // Free resources
      http.end();
    }
  }
