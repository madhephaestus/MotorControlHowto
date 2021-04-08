/*
 * PIDConfigureSimplePacketComsServer.cpp
 *
 *  Created on: Oct 19, 2018
 *      Author: hephaestus
 */

#include "GetPIDConstants.h"
#include <Arduino.h>

GetPIDConstants::GetPIDConstants(int num, Configurations * list) :
		PacketEventAbstract(1857) {
	mydata=list;

}

void GetPIDConstants::event(float * buffer) {
	buffer[0]=mydata->kp;
	buffer[1]=mydata->ki;
	buffer[2]=mydata->kd;
}

