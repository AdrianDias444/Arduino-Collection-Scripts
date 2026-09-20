#include <Arduino.h>
#include <Stepper.h>

#include "motor_toolkit.hpp"
#include "sonar_toolkit.hpp"
#include "led_toolkit.hpp"

#define R_PIN 10
#define Y_PIN 11
#define G_PIN 12


uint8_t state = 2;
float dist = 0.0f;

int processInfo(float dist);

void setup() {
    Serial.begin(9600);

    sonarInit();
    motorInit(12);
    ledInit(R_PIN, Y_PIN, G_PIN);

    delay(2000);
}

void loop() {
    dist = sonarRead();

    state = processInfo(dist);

    switch (state) {
		case 1:
			motorSweep();
			ledWrite(G_PIN);
			break;
		case 2:
			ledWrite(R_PIN);
			break;
    }
}

int processInfo(float dist) {
    if (dist >= 18.0 && dist <= 22.0) {
        return 1;
    }
	return 2;
}