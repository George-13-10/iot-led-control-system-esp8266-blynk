#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "YourTemplateName"
#define BLYNK_AUTH_TOKEN "YourAuthToken"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";
#define RELAY_PIN D1
BLYNK_WRITE(V0) { // Virtual Pin 0 from Blynk app button
int value = param.asInt();
digitalWrite(RELAY_PIN, value);
Serial.println(value ? "Relay ON" : "Relay OFF");
}
void setup() {
Serial.begin(115200);
pinMode(RELAY_PIN, OUTPUT);
digitalWrite(RELAY_PIN, LOW);
Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}
void loop() {
Blynk.run();
}
