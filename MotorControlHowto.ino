#include <RBE1001Lib.h>
#include "src/Configurations.h"

LeftMotor motor;
Configurations data(&motor);

void setup(){
	// Start the data interface
	data.attach();
}
float scalar = 1000000.0;
float effort=600.0/scalar;

void loop(){
	float kp = data.v_kp/scalar;
	float velocity_setpoint = data.velocity_target_degrees_per_sercond;
	float current_velocity = motor.getDegreesPerSecond();

	float error = (velocity_setpoint-current_velocity)*kp;

	if(velocity_setpoint<0)
		error=-(error);

	effort+=(error);
	Serial.println("Effort "+String(effort*scalar));
	motor.setEffort(effort*velocity_setpoint);
	delay(1);
}
