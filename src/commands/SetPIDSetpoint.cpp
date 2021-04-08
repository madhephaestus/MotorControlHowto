/*
 * SetPIDSetpoint.cpp
 *
 *  Created on: Dec 28, 2018
 *      Author: hephaestus
 */

#include "SetPIDSetpoint.h"
#include <Arduino.h>
SetPIDSetpoint::SetPIDSetpoint(int num, Configurations * list) :
		PacketEventAbstract(1848) {
	mydata=list;

}

void SetPIDSetpoint::event(float * buffer) {

	mydata->position_setpoint=buffer[2];
}
