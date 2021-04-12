/*
 * Configurations.h
 *
 *  Created on: Apr 8, 2021
 *      Author: hephaestus
 */

#ifndef CONFIGURATIONS_H_
#define CONFIGURATIONS_H_
#include <Motor.h>
#include <Preferences.h>
#include <WiFi.h>
#include <SimplePacketComs.h>
#include <Esp32SimplePacketComs.h>


class Configurations {

	// SImple packet coms implementation useing WiFi
	UDPSimplePacket coms;
	// WIfi stack managment state machine
	WifiManager manager;
public:
	Configurations(Motor * motor);
	// Start the coms to display data
	void attach();
	// loop the coms to display data
	void loop();

	Motor * mymotor;
	float v_kp=0.01;
	float v_ki=0;
	float v_kd=0;
	float kp=0.005;
	float ki=0;
	float kd=0;
	float position_setpoint=0;
	float velocity_target_degrees_per_sercond=0;
};

#endif /* CONFIGURATIONS_H_ */
