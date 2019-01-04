
#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include <WiFiUdp.h>
#include "wifi.h"

void readLine(char buffer[], uint8_t size)
{
	uint8_t i = 0;
	char c;

	do {
		while (!Serial.available()){yield();} //wait for input
		c = Serial.read();
		Serial.write(c); //echo characters back to user.
		if (c == '\r') break;
		if (c != '\n')
			buffer[i++] = c;      
	} while (i < size-1);
	buffer[i] = '\0';
}

void setupWiFi(void)
{
	WiFi.setAutoConnect(true);
	WiFi.mode(WIFI_STA);
}

bool startWiFi(void)
{
	uint8_t i;
	//check for persistent wifi connection
	for (i=0;i<10;i++){
		if (WiFi.status() == WL_CONNECTED) return true;
		delay(500);
		Serial.print(".");
	}

	/*didn't work: so ask user to enter credentials over Serial Port */
#define maxSSIDlength 20
#define maxPASSlength 40
	char ssid[maxSSIDlength];
	char pass[maxPASSlength];

	//prompt the user for his ssid

	Serial.print("Enter ssid name: ");
	readLine(ssid, maxSSIDlength);
	Serial.println();
	Serial.print("Enter pass phrase: ");
	readLine(pass, maxPASSlength);
	Serial.println();

	Serial.print("Attempting to Connect");
	if (WiFi.begin(ssid, pass) != WL_CONNECTED) {
		for (i=0;i<20;i++){
			if (WiFi.status() == WL_CONNECTED) return true;
			delay(500);
			Serial.print(".");
		}
	}
	Serial.print("Failed to connect to: ");
	Serial.println(ssid);

	Serial.print("using pass phrase: ");
	Serial.println(pass);

	return false;
}
