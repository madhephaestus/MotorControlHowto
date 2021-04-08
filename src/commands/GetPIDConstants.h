/*
 * PIDConfigureSimplePacketComsServer.h
 *
 *  Created on: Oct 19, 2018
 *      Author: hephaestus
 */

#ifndef SRC_COMSGet_PIDCONFIGURESIMPLEPACKETCOMSSERVER_H_
#define SRC_COMGetS_PIDCONFIGURESIMPLEPACKETCOMSSERVER_H_
#include <SimplePacketComs.h>
#include "../Configurations.h"

class GetPIDConstants: public PacketEventAbstract {
	Configurations * mydata;
public:
	GetPIDConstants(int num, Configurations * list);
	virtual ~GetPIDConstants(){}
	void event(float * buffer);

};

#endif /* SRC_COMS_PIDCONFIGURESIMPLEPACKETCOMSSERVER_H_ */
