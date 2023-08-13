#include <ESP8266WiFi.h>

const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";
const char* hostname = "my-esp8266";  // Set your desired hostname
IPAddress staticIP(192, 168, 1, 100);  // Define your desired static IP address
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

void setup() {
  // Set hostname and connect to Wi-Fi with static IP settings
  WiFi.hostname(hostname);
  WiFi.config(staticIP, gateway, subnet);
  WiFi.begin(ssid, password);
  
  // Your setup code here
}

void loop() {
  // Your loop code here
}
