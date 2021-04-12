#include <RBE1001Lib.h>
#include "src/Configurations.h"

LeftMotor motor;
Configurations data(&motor);

void setup(){
	// Start the data interface
	data.attach();
}
float effort=0;

void loop(){
	float kp = data.v_kp/1000.0;
	float velocity_setpoint = data.velocity_target_degrees_per_sercond;
	float current_velocity = motor.getDegreesPerSecond();

	float error = velocity_setpoint-current_velocity;

	effort+=(error*kp);

	if(effort>1)
		effort=1;
	if( effort<-1)
		effort=-1;

	//Serial. println("Current "+String(currentPositon)+" target "+String(position_setpoint)+" error "+String(error)+" effort "+String(effort));

	motor.setEffort(effort);
	delay(1);
}
