/*
 * GetPIDData.h
 *
 *  Created on: Nov 9, 2018
 *      Author: hephaestus
 */

#ifndef SRC_COMS_GETPIDDATA_H_
#define SRC_COMS_GETPIDDATA_H_
#include <SimplePacketComs.h>
#include "../Configurations.h"
class GetPIDData: public PacketEventAbstract {
private:
	Configurations * mydata;
public:
	GetPIDData(int num, Configurations * list);
	virtual ~GetPIDData();
	void event(float * buffer);
};

#endif /* SRC_COMS_GETPIDDATA_H_ */
