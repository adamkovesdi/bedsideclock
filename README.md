# Simple bedside clock

![bedsideclock](images/bedsideclock.jpg)

## Features
- 24 hour time display
- NTP sync
- DST support (automatic change)
- Configurable over WiFiManager automatic config mode AP
- OTA upgradable firmware

## Prerequisites
- ESP8266 board (recommended: NodeMCU/compatible see BOM)
- TM1637 4 digit 7 segment display 
- Platformio

## Build & Installation HOWTO

### Hardware BOM

- [NodeMCU v3 board](http://www.banggood.com/Geekcreit-Doit-NodeMcu-Lua-ESP8266-ESP-12E-WIFI-Development-Board-p-985891.html)
- TM1637 4 digit 7 segment display with colon
- Female-female dupont cable 4pcs (usually comes with the display)

### Wiring between NodeMCU and TM1637 display board

```
NodeMCU 3.3V -> Display Vcc
NodeMCU GND  -> Display GND
NodeMCU D3   -> Display CLK
NodeMCU D4   -> Display DATA
```

### Software installation

*OBSOLETE* will be replaced by Platformio HOWTO

- Download & Install Arduino IDE (1.8.8 at the time of writing)
[https://www.arduino.cc/en/main/software](https://www.arduino.cc/en/main/software) 

### Uploading

*OBSOLETE* will be replaced by Platformio HOWTO

- Tools, Board: select NodeMCU 1.0 (ESP 12-E Module)
- Tools, Port: select COM port
- Click upload (arrow button below menu bar on the upper left)

Upload parameters (tested with Arduino IDE 1.8.8):
```
Board: "NodeMCU 1.0 (ESP-12E Module)"
Upload Speed: "115200"
CPU Frequency: "80MHz"
Flash Size: "4M (1M SPIFFS)"
Debug: Disabled, None
IwIP Variant: "v2 Lower Memory"
VTables: "Flash"
Erase Flash: "Only Sketch"
```

### Wifi Configuration

If unable to connect to a known WiFi AP found, the unit will come up in configuration mode. Connect your PC/smartphone to clockAP SSID and follow captive portal UI to configure your WiFi credentials.

## Future plans

- Force configuration mode (button/jumper, etc)
- Openweathermap data (?)

## Special thanks

- [William Moeur](https://github.com/moeur) for NTP code improvements and credentials config

