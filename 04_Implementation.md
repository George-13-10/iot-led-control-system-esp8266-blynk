# 3. Working Principle and Implementation

## 3.1 Working Principle

The working process begins when the user interacts with the Blynk mobile application. The command is transmitted through the Blynk cloud server to the ESP8266 NodeMCU over a WiFi network.

The microcontroller interprets the command and changes the corresponding GPIO output state, thereby turning the LED ON or OFF.

## 3.2 Communication Process

The complete communication process is described below:

1. User presses a button in the Blynk application
2. Blynk server receives the command
3. Server identifies the target device
4. ESP8266 receives the command
5. GPIO output state is updated
6. LED status is synchronized back to the app

## 3.3 Firmware Logic

Example implementation:

```c
BLYNK_WRITE(V1)
{
    int ledState = param.asInt();

    if(ledState)
    {
        digitalWrite(LED_PIN_1, HIGH);
    }
    else
    {
        digitalWrite(LED_PIN_1, LOW);
    }
}
```

## 3.4 LED Circuit Operation

Each LED is connected:
- Through a 220Ω resistor
- Between GPIO output and ground

This arrangement:
- Limits current
- Prevents GPIO damage
- Ensures stable operation

## 3.5 Real-Time Synchronization

The system supports real-time synchronization between multiple mobile devices connected to the same Blynk project.

The firmware uses:
```c
Blynk.virtualWrite()
```

to update application widgets instantly.
