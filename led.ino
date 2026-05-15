#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#define DHTPIN D4
#define DHTTYPE DHT11
const char* ssid = "George";
const char* password = "12345678";
const char* apiKey = "Q8GZ1A5T7XYZABCD";
unsigned long channelID = 2425981;
WiFiClient client;
DHT dht(DHTPIN, DHTTYPE);
void setup() {
Serial.begin(115200);
WiFi.begin(ssid, password);
ThingSpeak.begin(client);
dht.begin();
Serial.print("Connecting");
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("Connected!");
}
void loop() {
float h = dht.readHumidity();
float t = dht.readTemperature();
if (isnan(h) || isnan(t)) {
Serial.println("Failed to read from sensor!");
return;
}
Serial.print("Temp: ");
Serial.print(t);
Serial.print("°C, Humidity: ");
Serial.print(h);
Serial.println("%");
ThingSpeak.setField(1, t);
ThingSpeak.setField(2, h);
int result = ThingSpeak.writeFields(channelID, apiKey);
if (result == 200) {
Serial.println("Data sent to ThingSpeak.");
} else {
Serial.print("Error sending data. Code: ");
Serial.println(result);
}
delay(10000);
}