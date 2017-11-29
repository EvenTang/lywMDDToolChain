
#include "SystemCtrl_EventDef.h"

// State definition
enum SystemCtrl_State { 
    ST_IDLE,
    ST_WORKING,
    ST_SC_UNINITIALIZED,
    ST_STATE_MAX
};

// Event definition
enum SystemCtrl_Event { 
    EV_PowerOff,
    EV_PowerOffResult,
    EV_PowerOn,
    EV_PowerOnResult,
    EV_SetTemperature,
    EV_SetTemperatureResult,
    EV_ShowTemperatureResult,
    EV_TurnOffDisplayResult,
    EV_EVENT_MAX
};

void SystemCtrl_SetStatus(SystemCtrl_State state);

SystemCtrl_State SystemCtrl_GetStatus();


/* Event callback of SystemCtrl Module,
 * All state response for State :IDLE 
 */
STM_Status SystemCtrl_ECB_IDLE_SetTemperature(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_IDLE_SetTemperatureResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_IDLE_ShowTemperatureResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_IDLE_PowerOff(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_IDLE_PowerOffResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_IDLE_TurnOffDisplayResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_IDLE_PowerOn(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_IDLE_PowerOnResult(SystemCtrlEvent const & _msg);

/* Event callback of SystemCtrl Module,
 * All state response for State :WORKING 
 */
STM_Status SystemCtrl_ECB_WORKING_SetTemperature(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_WORKING_SetTemperatureResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_WORKING_ShowTemperatureResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_WORKING_PowerOff(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_WORKING_PowerOffResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_WORKING_TurnOffDisplayResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_WORKING_PowerOn(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_WORKING_PowerOnResult(SystemCtrlEvent const & _msg);

/* Event callback of SystemCtrl Module,
 * All state response for State :SC_UNINITIALIZED 
 */
STM_Status SystemCtrl_ECB_SC_UNINITIALIZED_SetTemperature(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_SC_UNINITIALIZED_SetTemperatureResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_SC_UNINITIALIZED_ShowTemperatureResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_SC_UNINITIALIZED_PowerOff(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_SC_UNINITIALIZED_PowerOffResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_SC_UNINITIALIZED_TurnOffDisplayResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_SC_UNINITIALIZED_PowerOn(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_SC_UNINITIALIZED_PowerOnResult(SystemCtrlEvent const & _msg);


// State-Event Callback Matrix
typedef STM_Status (FP_SystemCtrl_ECB)(SystemCtrlEvent & _msg); 
FP_SystemCtrl_ECB const SystemCtrl_state_ecb_map[][] = { 
	{ 
		SystemCtrl_ECB_IDLE_SetTemperature, 
		SystemCtrl_ECB_IDLE_SetTemperatureResult, 
		SystemCtrl_ECB_IDLE_ShowTemperatureResult, 
		SystemCtrl_ECB_IDLE_PowerOff, 
		SystemCtrl_ECB_IDLE_PowerOffResult, 
		SystemCtrl_ECB_IDLE_TurnOffDisplayResult, 
		SystemCtrl_ECB_IDLE_PowerOn, 
		SystemCtrl_ECB_IDLE_PowerOnResult, 
	}, 
	{ 
		SystemCtrl_ECB_WORKING_SetTemperature, 
		SystemCtrl_ECB_WORKING_SetTemperatureResult, 
		SystemCtrl_ECB_WORKING_ShowTemperatureResult, 
		SystemCtrl_ECB_WORKING_PowerOff, 
		SystemCtrl_ECB_WORKING_PowerOffResult, 
		SystemCtrl_ECB_WORKING_TurnOffDisplayResult, 
		SystemCtrl_ECB_WORKING_PowerOn, 
		SystemCtrl_ECB_WORKING_PowerOnResult, 
	}, 
	{ 
		SystemCtrl_ECB_SC_UNINITIALIZED_SetTemperature, 
		SystemCtrl_ECB_SC_UNINITIALIZED_SetTemperatureResult, 
		SystemCtrl_ECB_SC_UNINITIALIZED_ShowTemperatureResult, 
		SystemCtrl_ECB_SC_UNINITIALIZED_PowerOff, 
		SystemCtrl_ECB_SC_UNINITIALIZED_PowerOffResult, 
		SystemCtrl_ECB_SC_UNINITIALIZED_TurnOffDisplayResult, 
		SystemCtrl_ECB_SC_UNINITIALIZED_PowerOn, 
		SystemCtrl_ECB_SC_UNINITIALIZED_PowerOnResult, 
	}, 
}; 


