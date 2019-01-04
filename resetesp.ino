/************************************************************************* 
 * adamkov RESET ESP CONFIG
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
