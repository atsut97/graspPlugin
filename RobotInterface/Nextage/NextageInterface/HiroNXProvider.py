#!/usr/bin/env python
# -*- Python -*-

"""
 \file HiroNXProvider.py
 \brief Interface for HiroNx
 \date $Date$


"""
import sys
import time
sys.path.append(".")

import HiroNXManipulator

# Import RTM module
import RTC
import OpenRTM_aist

# Import Service implementation class
# <rtc-template block="service_impl">
from HiroNX_idl_example import *
from HIROController_idl_example import *

# </rtc-template>

# Import Service stub modules
# <rtc-template block="consumer_import">
# </rtc-template>


# This module's spesification
# <rtc-template block="module_spec">
hironxprovider_spec = ["implementation_id", "HiroNXProvider", 
		 "type_name",         "HiroNXProvider", 
		 "description",       "Interface for HiroNx", 
		 "version",           "1.0.0", 
		 "vendor",            "AIST", 
		 "category",          "Category", 
		 "activity_type",     "STATIC", 
		 "max_instance",      "0", 
		 "language",          "Python", 
		 "lang_type",         "SCRIPT",
		 ""]
# </rtc-template>

#robot = None

class HiroNXProvider(OpenRTM_aist.DataFlowComponentBase):
	
	"""
	\class HiroNXProvider
	\brief Interface for HiroNx
	
	"""
	def __init__(self, manager):
		"""
		\brief constructor
		\param manager Maneger Object
		"""
		OpenRTM_aist.DataFlowComponentBase.__init__(self, manager)
		
		#global robot

		
		"""
		"""
		self._HiroNXPort = OpenRTM_aist.CorbaPort("HiroNX")
		"""
		"""
		self._HIROPort = OpenRTM_aist.CorbaPort("HIRO")

		"""
		"""
		self._manipulator = HiroNX_i()
		"""
		"""
		self._common = CommonCommands_i()
		"""
		"""
		self._motion = MotionCommands_i()
		


		# initialize of configuration-data.
		# <rtc-template block="init_conf_param">
		
		# </rtc-template>


		 
	def onInitialize(self):
		"""
		
		The initialize action (on CREATED->ALIVE transition)
		formaer rtc_init_entry() 
		
		\return RTC::ReturnCode_t
		
		"""
		# Bind variables and configuration variable
		
		# Set InPort buffers
		
		# Set OutPort buffers
		
		# Set service provider to Ports
		self._HiroNXPort.registerProvider("manipulator", "HiroNX", self._manipulator)
		self._HIROPort.registerProvider("common", "CommonCommands", self._common)
		self._HIROPort.registerProvider("motion", "MotionCommands", self._motion)
		
		# Set service consumers to Ports
		
		# Set CORBA Service Ports
		self.addPort(self._HiroNXPort)
		self.addPort(self._HIROPort)
		
		return RTC.RTC_OK
	
	#def onFinalize(self, ec_id):
	#	"""
	#
	#	The finalize action (on ALIVE->END transition)
	#	formaer rtc_exiting_entry()
	#
	#	\return RTC::ReturnCode_t
	#
	#	"""
	#
	#	return RTC.RTC_OK
	
	#def onStartup(self, ec_id):
	#	"""
	#
	#	The startup action when ExecutionContext startup
	#	former rtc_starting_entry()
	#
	#	\param ec_id target ExecutionContext Id
	#
	#	\return RTC::ReturnCode_t
	#
	#	"""
	#
	#	return RTC.RTC_OK
	
	#def onShutdown(self, ec_id):
	#	"""
	#
	#	The shutdown action when ExecutionContext stop
	#	former rtc_stopping_entry()
	#
	#	\param ec_id target ExecutionContext Id
	#
	#	\return RTC::ReturnCode_t
	#
	#	"""
	#
	#	return RTC.RTC_OK
	
	#def onActivated(self, ec_id):
	#	"""
	#
	#	The activated action (Active state entry action)
	#	former rtc_active_entry()
	#
	#	\param ec_id target ExecutionContext Id
	#
	#	\return RTC::ReturnCode_t
	#
	#	"""
	#
	#	return RTC.RTC_OK
	
	#def onDeactivated(self, ec_id):
	#	"""
	#
	#	The deactivated action (Active state exit action)
	#	former rtc_active_exit()
	#
	#	\param ec_id target ExecutionContext Id
	#
	#	\return RTC::ReturnCode_t
	#
	#	"""
	#
	#	return RTC.RTC_OK
	
	#def onExecute(self, ec_id):
	#	"""
	#
	#	The execution action that is invoked periodically
	#	former rtc_active_do()
	#
	#	\param ec_id target ExecutionContext Id
	#
	#	\return RTC::ReturnCode_t
	#
	#	"""
	#
	#	return RTC.RTC_OK
	
	#def onAborting(self, ec_id):
	#	"""
	#
	#	The aborting action when main logic error occurred.
	#	former rtc_aborting_entry()
	#
	#	\param ec_id target ExecutionContext Id
	#
	#	\return RTC::ReturnCode_t
	#
	#	"""
	#
	#	return RTC.RTC_OK
	
	#def onError(self, ec_id):
	#	"""
	#
	#	The error action in ERROR state
	#	former rtc_error_do()
	#
	#	\param ec_id target ExecutionContext Id
	#
	#	\return RTC::ReturnCode_t
	#
	#	"""
	#
	#	return RTC.RTC_OK
	
	#def onReset(self, ec_id):
	#	"""
	#
	#	The reset action that is invoked resetting
	#	This is same but different the former rtc_init_entry()
	#
	#	\param ec_id target ExecutionContext Id
	#
	#	\return RTC::ReturnCode_t
	#
	#	"""
	#
	#	return RTC.RTC_OK
	
	#def onStateUpdate(self, ec_id):
	#	"""
	#
	#	The state update action that is invoked after onExecute() action
	#	no corresponding operation exists in OpenRTm-aist-0.2.0
	#
	#	\param ec_id target ExecutionContext Id
	#
	#	\return RTC::ReturnCode_t
	#
	#	"""
	#
	#	return RTC.RTC_OK
	
	#def onRateChanged(self, ec_id):
	#	"""
	#
	#	The action that is invoked when execution context's rate is changed
	#	no corresponding operation exists in OpenRTm-aist-0.2.0
	#
	#	\param ec_id target ExecutionContext Id
	#
	#	\return RTC::ReturnCode_t
	#
	#	"""
	#
	#	return RTC.RTC_OK
	



def HiroNXProviderInit(manager):
    profile = OpenRTM_aist.Properties(defaults_str=hironxprovider_spec)
    manager.registerFactory(profile,
                            HiroNXProvider,
                            OpenRTM_aist.Delete)

def MyModuleInit(manager):
    HiroNXProviderInit(manager)

    # Create a component
    comp = manager.createComponent("HiroNXProvider")

def main():
	HiroNXManipulator.init()
	mgr = OpenRTM_aist.Manager.init(sys.argv)
	mgr.setModuleInitProc(MyModuleInit)
	mgr.activateManager()
	mgr.runManager()

if __name__ == "__main__":
	main()

