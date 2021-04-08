/*
 * GetPDVelocityConstants.h
 *
 *  Created on: Mar 3, 2019
 *      Author: hephaestus
 */

#ifndef SRC_COMMANDS_GETPDVELOCITYCONSTANTS_H_
#define SRC_COMMANDS_GETPDVELOCITYCONSTANTS_H_
#include <SimplePacketComs.h>
#include "../Configurations.h"
class  GetPDVelocityConstants: public PacketEventAbstract {
private:
	Configurations * mydata;
public:
	GetPDVelocityConstants(int num,Configurations * list);
	virtual ~GetPDVelocityConstants();
	void event(float * buffer);
};
#endif /* SRC_COMMANDS_GETPDVELOCITYCONSTANTS_H_ */
