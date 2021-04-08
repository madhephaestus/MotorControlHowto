/*
 * PIDConfigureSimplePacketComsServer.cpp
 *
 *  Created on: Oct 19, 2018
 *      Author: hephaestus
 */

#include "SetPIDConstants.h"
#include <Arduino.h>
SetPIDConstants::SetPIDConstants(int num, Configurations * list) :
		PacketEventAbstract(1900) {
	mydata=list;

}

void SetPIDConstants::event(float * buffer) {
	mydata->kp=buffer[0];
	mydata->ki=buffer[1];
	mydata->kd=buffer[2];

}

