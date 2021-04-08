/*
 * GetPIDVelocity.h
 *
 *  Created on: Mar 3, 2019
 *      Author: hephaestus
 */

#ifndef SRC_COMMANDS_GETPIDVELOCITY_H_
#define SRC_COMMANDS_GETPIDVELOCITY_H_

#include <SimplePacketComs.h>
#include "../Configurations.h"
class GetPIDVelocity : public PacketEventAbstract {
private:
	Configurations * mydata;
public:
	GetPIDVelocity(int num, Configurations * data);
	virtual ~GetPIDVelocity();
	void event(float * buffer);
};
#endif /* SRC_COMMANDS_GETPIDVELOCITY_H_ */
