# 2. System Architecture and Components

## 2.1 System Architecture

The system architecture consists of the following major components:

1. Smartphone with Blynk Application
2. Blynk Cloud Server
3. ESP8266 NodeMCU
4. LED Output Circuit

The smartphone communicates with the Blynk cloud platform through the internet. The Blynk server forwards user commands to the ESP8266 NodeMCU over WiFi. The microcontroller processes the received commands and controls the LEDs using GPIO pins.

## 2.2 Hardware Components

### ESP8266 NodeMCU
The ESP8266 NodeMCU is a low-cost WiFi-enabled microcontroller widely used for IoT applications.

Features:
- Built-in WiFi module
- Multiple GPIO pins
- USB programming support
- Low power consumption

### LEDs
LEDs are used as output indicators for demonstrating remote switching functionality.

### Resistors
220Ω resistors are connected in series with LEDs to limit current and protect GPIO pins.

## 2.3 Software Components

### Blynk Platform
Blynk provides:
- Mobile app interface
- Cloud communication
- Real-time device control
- Virtual pin management

### Arduino IDE
The firmware for the ESP8266 is developed and uploaded using the Arduino IDE.

## 2.4 Communication Flow

```
Smartphone App
      ↓
Blynk Cloud Server
      ↓
ESP8266 NodeMCU
      ↓
   LED Control
```
