/*
 * PIDConfigureSimplePacketComsServer.h
 *
 *  Created on: Oct 19, 2018
 *      Author: hephaestus
 */

#ifndef SRC_COMS_PIDCONFIGURESIMPLEPACKETCOMSSERVER_H_
#define SRC_COMS_PIDCONFIGURESIMPLEPACKETCOMSSERVER_H_
#include <SimplePacketComs.h>
#include "../Configurations.h"

class SetPIDConstants: public PacketEventAbstract {
	Configurations * mydata;
public:
	SetPIDConstants(int num, Configurations * list);
	virtual ~SetPIDConstants(){}
	void event(float * buffer);

};

#endif /* SRC_COMS_PIDCONFIGURESIMPLEPACKETCOMSSERVER_H_ */
