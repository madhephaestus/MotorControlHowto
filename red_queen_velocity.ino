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
	float currentPositon = motor.getCurrentDegrees();
	float velocity_setpoint = data.velocity_target_degrees_per_sercond;

	float deltaPosition = velocity_setpoint*0.001;// change in position expected in 1ms
	// Only run away the setpoint if effort is not pegged and the velocity is non zero
	if(motor.getEffort()<0.95 && fabs(velocity_setpoint)>1)
		data.position_setpoint+=deltaPosition;

	float error = data.position_setpoint-currentPositon;

	float effort = error * kp;

	//Serial. println("Current "+String(currentPositon)+" target "+String(position_setpoint)+" error "+String(error)+" effort "+String(effort));

	motor.setEffort(effort);
	delay(1);
}
