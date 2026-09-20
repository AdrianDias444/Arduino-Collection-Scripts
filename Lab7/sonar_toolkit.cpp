#include <Arduino.h>
#include "sonar_toolkit.hpp"
// Pin definition
#define PINO_TRIG 9
#define PINO_ECHO 8
#define OUT_OF_RANGE 999.0


void sonarInit() {
	pinMode(PINO_TRIG , OUTPUT);
	pinMode(PINO_ECHO , INPUT);
}

float sonarRead()
{
	digitalWrite(PINO_TRIG , LOW);
	delayMicroseconds(2);
	digitalWrite(PINO_TRIG , HIGH);
	delayMicroseconds(10);
	digitalWrite(PINO_TRIG , LOW);

	long tof = pulseIn( PINO_ECHO ,HIGH, 30000);
	if (tof == 0){
		return OUT_OF_RANGE;
	}
	return (tof * 0.0343) / 2.0;
}