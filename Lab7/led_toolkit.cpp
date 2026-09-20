#include <Arduino.h>
#include "led_toolkit.hpp"
// Global variables to indicate whichever pins we want in setup().
uint8_t r_pin = 0;
uint8_t y_pin = 0;
uint8_t g_pin = 0;
void ledIgnite(const uint8_t mode)
{ 
	// Turns all three pins ON or OFF at once
	digitalWrite(r_pin , mode);
	digitalWrite(y_pin , mode);
	digitalWrite(g_pin , mode);
}
void ledInit(const uint8_t r, const uint8_t y, const uint8_t g)
{
	pinMode((r_pin = r), OUTPUT);
	pinMode((y_pin = y), OUTPUT);
	pinMode((g_pin = g), OUTPUT);

	for(int i = 0; i < 3; i++){ // Testing pins
		ledIgnite(HIGH);
		delay(200);
		ledIgnite(LOW);
		delay(200);
	}
}
void ledWrite(const uint8_t pin){ // Turns only one pin on.
if(pin <= 12 && pin >= 10){
	ledIgnite(LOW);
	delay(10);
	digitalWrite(pin, HIGH);
}
}
void ledWarning(){ // All leds blinking represents a warning
	ledIgnite(HIGH);
	delay(10);
	ledIgnite(LOW);
}