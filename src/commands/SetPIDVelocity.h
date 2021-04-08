/*
 * SetPIDVelocity.h
 *
 *  Created on: Mar 3, 2019
 *      Author: hephaestus
 */

#ifndef SRC_COMMANDS_SETPIDVELOCITY_H_
#define SRC_COMMANDS_SETPIDVELOCITY_H_
#include <SimplePacketComs.h>
#include "../Configurations.h"
class SetPIDVelocity : public PacketEventAbstract {
private:
	Configurations * mydata;
public:
	SetPIDVelocity(int num, Configurations * list);
	virtual ~SetPIDVelocity();
	void event(float * buffer);
};

#endif /* SRC_COMMANDS_SETPIDVELOCITY_H_ */
