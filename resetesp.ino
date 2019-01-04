/************************************************************************* 
 * adamkov RESET ESP CONFIG
 * in case WiFi crashes (exception 29 on mine)
 * reference: https://github.com/esp8266/Arduino/issues/1648
 * (c) 2018-2019
 *************************************************************************/

#include <ESP8266WiFi.h>

void setup()
{
	WiFi.softAPdisconnect(true);
	WiFi.disconnect(true); 
	delay(3000);
	ESP.eraseConfig();
	ESP.reset(); 
	delay(3000);
}

void loop()
{
}
