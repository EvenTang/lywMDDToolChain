
#include "SystemCtrl_EventDef.h"

// State definition
enum SystemCtrl_State { 
    ST_Idle,
    ST_Working,
    ST_SC_uninitialized,
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
 * All state response for State :Idle 
 */
STM_Status SystemCtrl_ECB_Idle_SetTemperature(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Idle_SetTemperatureResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Idle_ShowTemperatureResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Idle_PowerOff(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Idle_PowerOffResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Idle_TurnOffDisplayResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Idle_PowerOn(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Idle_PowerOnResult(SystemCtrlEvent const & _msg);

/* Event callback of SystemCtrl Module,
 * All state response for State :Working 
 */
STM_Status SystemCtrl_ECB_Working_SetTemperature(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Working_SetTemperatureResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Working_ShowTemperatureResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Working_PowerOff(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Working_PowerOffResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Working_TurnOffDisplayResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Working_PowerOn(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Working_PowerOnResult(SystemCtrlEvent const & _msg);

/* Event callback of SystemCtrl Module,
 * All state response for State :SC_uninitialized 
 */
STM_Status SystemCtrl_ECB_SC_uninitialized_SetTemperature(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_SC_uninitialized_SetTemperatureResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_SC_uninitialized_ShowTemperatureResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_SC_uninitialized_PowerOff(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_SC_uninitialized_PowerOffResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_SC_uninitialized_TurnOffDisplayResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_SC_uninitialized_PowerOn(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_SC_uninitialized_PowerOnResult(SystemCtrlEvent const & _msg);


// State-Event Callback Matrix
typedef STM_Status (FP_SystemCtrl_ECB)(SystemCtrlEvent & _msg); 
FP_SystemCtrl_ECB const SystemCtrl_state_ecb_map[][] = { 
	{ 
		SystemCtrl_ECB_Idle_SetTemperature, 
		SystemCtrl_ECB_Idle_SetTemperatureResult, 
		SystemCtrl_ECB_Idle_ShowTemperatureResult, 
		SystemCtrl_ECB_Idle_PowerOff, 
		SystemCtrl_ECB_Idle_PowerOffResult, 
		SystemCtrl_ECB_Idle_TurnOffDisplayResult, 
		SystemCtrl_ECB_Idle_PowerOn, 
		SystemCtrl_ECB_Idle_PowerOnResult, 
	}, 
	{ 
		SystemCtrl_ECB_Working_SetTemperature, 
		SystemCtrl_ECB_Working_SetTemperatureResult, 
		SystemCtrl_ECB_Working_ShowTemperatureResult, 
		SystemCtrl_ECB_Working_PowerOff, 
		SystemCtrl_ECB_Working_PowerOffResult, 
		SystemCtrl_ECB_Working_TurnOffDisplayResult, 
		SystemCtrl_ECB_Working_PowerOn, 
		SystemCtrl_ECB_Working_PowerOnResult, 
	}, 
	{ 
		SystemCtrl_ECB_SC_uninitialized_SetTemperature, 
		SystemCtrl_ECB_SC_uninitialized_SetTemperatureResult, 
		SystemCtrl_ECB_SC_uninitialized_ShowTemperatureResult, 
		SystemCtrl_ECB_SC_uninitialized_PowerOff, 
		SystemCtrl_ECB_SC_uninitialized_PowerOffResult, 
		SystemCtrl_ECB_SC_uninitialized_TurnOffDisplayResult, 
		SystemCtrl_ECB_SC_uninitialized_PowerOn, 
		SystemCtrl_ECB_SC_uninitialized_PowerOnResult, 
	}, 
}; 


