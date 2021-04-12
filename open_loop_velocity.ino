#include <RBE1001Lib.h>
#include "src/Configurations.h"

LeftMotor motor;
Configurations data(&motor);

void setup(){
	// Start the data interface
	data.attach();
}


void loop(){
	float kp=data.v_kp/1000.0;
	float velocity_setpoint = data.velocity_target_degrees_per_sercond;

	float effort = velocity_setpoint * kp;

	motor.setEffort(effort);
	delay(1);
}
