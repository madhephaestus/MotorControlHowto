/*
 * GetPIDVelocity.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: hephaestus
 */

#include "GetPIDVelocity.h"
#include <Arduino.h>
GetPIDVelocity::GetPIDVelocity(int num, Configurations * list) :
PacketEventAbstract(1822) {//Brazil's independence from Portugal,

	mydata=list;
}

GetPIDVelocity::~GetPIDVelocity() {
	// TODO Auto-generated destructor stub
}

void GetPIDVelocity::event(float * buffer) {
	buffer[0] = 1;
	buffer[1]=mydata->velocity_target_degrees_per_sercond;
	buffer[2]=mydata->mymotor->getDegreesPerSecond();
	buffer[3]=mydata->mymotor->getEffort();

}
