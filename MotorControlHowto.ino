#include <RBE1001Lib.h>
#include "src/Configurations.h"

LeftMotor left;
Configurations data(&left);

void setup(){
	// Start up the encoder and PWM
	left.attach();
	// disable the built in PID and stop the motor
	left.setEffort(0);
	// Start the data interface
	data.attach();
}

void loop(){
	Serial.println("Main loop "+String((int)millis()));
	delay(100);
}
