/*
 * GetPDVelocityConstants.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: hephaestus
 */

#include "GetPDVelocityConstants.h"
#include <Arduino.h>
GetPDVelocityConstants::GetPDVelocityConstants(int num, Configurations * list) :
PacketEventAbstract(1825)  {//Uruguay Independence from the Empire of Brazil
	// TODO Auto-generated constructor stub
	mydata=list;
}

GetPDVelocityConstants::~GetPDVelocityConstants() {
	// TODO Auto-generated destructor stub
}

void GetPDVelocityConstants::event(float * buffer) {
	buffer[0]=mydata->v_kp;
	buffer[1]=mydata->v_ki;
	buffer[2]=mydata->v_kd;

}
