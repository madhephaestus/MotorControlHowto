/*
 * Configurations.cpp
 *
 *  Created on: Apr 8, 2021
 *      Author: hephaestus
 */

#include "Configurations.h"
#include <server/NameCheckerServer.h>
#include "commands/GetPIDConstants.h"
#include "commands/GetPIDData.h"
#include "commands/SetPIDConstants.h"
#include "commands/SetPIDSetpoint.h"

#include "commands/SetPDVelocityConstants.h"
#include "commands/SetPIDVelocity.h"
#include "commands/GetPDVelocityConstants.h"
#include "commands/GetPIDVelocity.h"
Configurations *self;

static TaskHandle_t complexHandlerTask2;
static boolean isCongigurationsAttached=false;
String * name=new String("MotorDemoBot") ;
void onConfigurationsTimer(void *param) {
	ESP_LOGI(TAG, "Starting the PID loop thread");

	while (1) {
		vTaskDelay(10);
		self->loop();
	}
	ESP_LOGE(TAG, "ERROR Pid thread died!");
}
Configurations::Configurations(Motor *motor) {
	mymotor = motor;
	self = this;
}
// Start the coms to display data
void Configurations::attach() {
	if(isCongigurationsAttached)
		return;
	isCongigurationsAttached=true;
	// disable the built in PID and stop the motor
	mymotor->setEffort(0);
	mymotor->DELTA_EFFORT=1;
	manager.setup();
	int numberOfPID=1;
	Configurations * pidList=this;
	coms.attach(new NameCheckerServer(name));
	coms.attach(new SetPIDSetpoint(numberOfPID, pidList));
	coms.attach(new SetPIDConstants(numberOfPID, pidList));
	coms.attach(new GetPIDData(numberOfPID, pidList));
	coms.attach(
			new GetPIDConstants(numberOfPID, pidList));
	coms.attach(new GetPIDVelocity(numberOfPID, pidList));
	coms.attach(new GetPDVelocityConstants(numberOfPID, pidList));
	coms.attach(new SetPIDVelocity(numberOfPID, pidList));
	coms.attach(new SetPDVelocityConstants(numberOfPID, pidList));

	xTaskCreatePinnedToCore(onConfigurationsTimer, "Configurations server",
			8192, NULL, 1, &complexHandlerTask2, 1);

	while(manager.getState() !=Connected){
		delay(1);
	}

}

// loop the coms to display data
void Configurations::loop() {
	manager.loop();
	if (manager.getState() == Connected)
		coms.server();
	else {
		return;
	}
}
