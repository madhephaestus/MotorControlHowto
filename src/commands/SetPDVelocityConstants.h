/*
 * SetPDVelocityConstants.h
 *
 *  Created on: Mar 3, 2019
 *      Author: hephaestus
 */

#ifndef SRC_COMMANDS_SETPDVELOCITYCONSTANTS_H_
#define SRC_COMMANDS_SETPDVELOCITYCONSTANTS_H_
#include <SimplePacketComs.h>
#include "../Configurations.h"
class SetPDVelocityConstants : public PacketEventAbstract {
private:
	Configurations * mydata;
public:
	SetPDVelocityConstants(int num, Configurations * list);
	virtual ~SetPDVelocityConstants();
	void event(float * buffer);
};
#endif /* SRC_COMMANDS_SETPDVELOCITYCONSTANTS_H_ */
