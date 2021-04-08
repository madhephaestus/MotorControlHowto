/*
 * GetPIDData.cpp
 *
 *  Created on: Nov 9, 2018
 *      Author: hephaestus
 */

#include "GetPIDData.h"

GetPIDData::~GetPIDData() {
	// TODO Auto-generated destructor stub
}

GetPIDData::GetPIDData(int num, Configurations * list) :
		PacketEventAbstract(1910) {
	mydata=list;

}

void GetPIDData::event(float * buffer) {
	buffer[0]=1;
	buffer[1]=mydata->position_setpoint;
	buffer[2]=mydata->mymotor->getCurrentDegrees();

//	buffer[0] = (float) numPID;
//	for (int i = 0; i < numPID && i < 7; i++) {
////		Motor * current = pidlist[i];
////		buffer[i * 2 + 1 + 0] = current->getSetPointDegrees();
////		buffer[i * 2 + 1 + 1] = current->getAngleDegrees();
//	}

}

