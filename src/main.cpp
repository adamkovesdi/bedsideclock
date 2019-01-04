/************************************************************************* 
 * adamkov Bedside Clock
 * (c) 2018-2019
 * code based on William Moeur's Arduino_ESP8266 examples
 * https://github.com/moeur/Arduino_ESP8266
 *************************************************************************/

/* You must dedicate two GPIO pins to be used to communicate with the tm1637 module
 * Make sure to connect:
 *   tm1637_clk_pin to the CLK pin on the tm1637 clock module
 *   tm1637_data_pin to the pin on the clock module labeled DIO
 */
#define tm1637_clk_pin D3
#define tm1637_data_pin D4

#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include <WiFiUdp.h>
#include <Ticker.h>
#include <Time.h>
#include "ntp.h"
#include "TM1637.h"
#include "wifi.h"

void digitalClockDisplay();
void toggleColon(void);

NTP NTPclient;
tm1637 display(tm1637_clk_pin, tm1637_data_pin);
Ticker clockticker;
bool colon = true;
bool updateTime = true;

#define PST -8 // pacific standard time
#define CET 1 // central european time

time_t getNTPtime(void)
{
  return NTPclient.getNtpTime();
}

void setup() {
	Serial.begin(9600);
	Serial.println();
	Serial.println();

	// Until WiFi is connected display 8008
	display.setBrightness(2);
	display.writeTime(80,8,1);

	setupWiFi();

	// Once WiFi is connected display 0001
	display.writeTime(0,1,0);

	ArduinoOTA.begin(); 

	NTPclient.begin("hu.pool.ntp.org", CET);
	setSyncInterval(SECS_PER_HOUR);
	setSyncProvider(getNTPtime);
	// Once NTP sync is setup display 0002
	display.writeTime(0,2,0);
	clockticker.attach(0.5, toggleColon);
}

void loop()
{
	if (updateTime)
	{
		updateTime = false;
		if (timeStatus() != timeNotSet) 
		{
			digitalClockDisplay();  
		}
	}
	ArduinoOTA.handle();
}

void digitalClockDisplay()
{
	// digital clock display of the time
	display.writeTime(hour(), minute(), colon);
	colon = !colon;
}

void toggleColon(void)
{
	updateTime = true;  
}
