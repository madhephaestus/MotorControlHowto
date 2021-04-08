/*
 * SetPDVelocityConstants.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: hephaestus
 */

#include "SetPDVelocityConstants.h"
#include <Arduino.h>
SetPDVelocityConstants::SetPDVelocityConstants(int num, Configurations * list) :
PacketEventAbstract(1810)  {//The Colombian Declaration of Independence
	// TODO Auto-generated constructor stub
	mydata=list;
}

SetPDVelocityConstants::~SetPDVelocityConstants() {
	// TODO Auto-generated destructor stub
}

void SetPDVelocityConstants::event(float * buffer) {
	mydata->v_kp=buffer[0];
	mydata->v_ki=buffer[1];
	mydata->v_kd=buffer[2];

}
