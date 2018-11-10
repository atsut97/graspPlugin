/*
 * HIROControllerRtc.h
 *
 *  Created on: 2011-10-05
 *  Auto Generated by: gp.rb
 */

#ifndef HIROCONTROLLERRTC_H
#define HIROCONTROLLERRTC_H

#include "../Grasp/GraspController.h"
#ifdef OPENRTM112
#include "ArmControllerRtc1_1_2/HIROController.hh"
#include "ArmControllerRtc1_1_2/ArmController.h"
#else
#include "ArmControllerRtc/HIROController.hh"
#include "ArmControllerRtc/ArmController.h"
#endif

namespace grasp {

class ArmControllerRtc {
	public:
		ArmControllerRtc() {}
		~ArmControllerRtc() {}
		static ArmControllerRtc* instance();
		int RtcStart();
		static void MyModuleInit(RTC::Manager* manager);

		::ArmController * comp_;



};

}

#endif /* HIROCONTROLLER_H */
