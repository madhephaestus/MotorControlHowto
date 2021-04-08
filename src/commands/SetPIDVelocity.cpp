/*
 * SetPIDVelocity.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: hephaestus
 */

#include "SetPIDVelocity.h"
#include <Arduino.h>
SetPIDVelocity::SetPIDVelocity(int num, Configurations * list) :
PacketEventAbstract(1811)  {//Venezuela's independence
	// TODO Auto-generated constructor stub
	mydata=list;
}

SetPIDVelocity::~SetPIDVelocity() {
	// TODO Auto-generated destructor stub
}

void SetPIDVelocity::event(float * buffer) {
	mydata->velocity_target_degrees_per_sercond=buffer[0];
}
