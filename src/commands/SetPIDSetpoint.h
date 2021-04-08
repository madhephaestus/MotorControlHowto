/*
 * SetPIDSetpoint.h
 *
 *  Created on: Dec 28, 2018
 *      Author: hephaestus
 */

#ifndef SRC_COMMANDS_SETPIDSETPOINT_H_
#define SRC_COMMANDS_SETPIDSETPOINT_H_
#include <SimplePacketComs.h>
#include "../Configurations.h"
class SetPIDSetpoint: public PacketEventAbstract {
	Configurations * mydata;
public:
	SetPIDSetpoint(int num, Configurations * list);
	virtual ~SetPIDSetpoint(){}
	void event(float * buffer);
};

#endif /* SRC_COMMANDS_SETPIDSETPOINT_H_ */
