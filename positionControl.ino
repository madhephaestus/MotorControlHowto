#include <RBE1001Lib.h>
#include "src/Configurations.h"

LeftMotor motor;
Configurations data(&motor);

void setup(){
	// Start the data interface
	data.attach();
}

void loop(){
	float kp=data.kp;
	float position_setpoint=data.position_setpoint;
	float currentPositon = motor.getCurrentDegrees();

	float error = position_setpoint-currentPositon;

	float effort = error * kp;

	//Serial. println("Current "+String(currentPositon)+" target "+String(position_setpoint)+" error "+String(error)+" effort "+String(effort));

	motor.setEffort(effort);
	delay(1);
}