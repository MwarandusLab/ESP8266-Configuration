#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  delay(1000);
}

void loop() {
  sendRequest();
  delay(5000);
}

void sendRequest() {
  WiFiClientSecure client;
  client.setInsecure(); // Bypass SSL certificate verification

  if (client.connect("domain.com", 443)) { // Use the correct port (usually 443 for HTTPS)
    client.print("GET /upload.php HTTP/1.1\r\nHost: domain.com\r\nConnection: close\r\n\r\n");
    while (client.connected()) {
      String line = client.readStringUntil('\n');
      if (line == "\r") {
        break;
      }
    }
    String response = client.readString();
    Serial.println("Response:");
    Serial.println(response);
    client.stop();
  } else {
    Serial.println("Connection failed");
  }
}
