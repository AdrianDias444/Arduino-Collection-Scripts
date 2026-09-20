#include <Arduino.h>
#include <Stepper.h>
#include "motor_toolkit.hpp"
#define OUTPUT1 7
#define OUTPUT2 6
#define OUTPUT3 5
#define OUTPUT4 4
#define STP_PER_ROTATION 2048
#define LIM_STP 512


Stepper motor(STP_PER_ROTATION , OUTPUT1 , OUTPUT3 , OUTPUT2 , OUTPUT4);


int cur_stp = 0;
int direct = 1;
void motorInit(int speed_rpm)
{
	motor.setSpeed(speed_rpm);
}

void motorSweep()
{
	motor.step(direct * 5); // 5 steps at a time
	cur_stp += (direct * 5);

	if (cur_stp >= LIM_STP || cur_stp <= -LIM_STP) {
		direct *= -1;
}
}