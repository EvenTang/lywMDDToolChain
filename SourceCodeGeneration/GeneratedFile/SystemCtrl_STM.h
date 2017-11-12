
#include "SystemCtrl_EventDef.h"

// State definition
enum SystemCtrl_State { 
    ST_Idle,
    ST_New,
    ST_Working,
    ST_Unitialized,
    ST_STATE_MAX
};

// Event definition
enum SystemCtrl_Event { 
    EV_SetTemperature,
    EV_SetTemperatureResult,
    EV_ShowTemperatureResult,
    EV_PowerOff,
    EV_PowerOffResult,
    EV_TurnOffDisplayResult,
    EV_PowerOn,
    EV_PowerOnResult,
    EV_EVENT_MAX
};


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
 * All state response for State :New 
 */
STM_Status SystemCtrl_ECB_New_SetTemperature(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_New_SetTemperatureResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_New_ShowTemperatureResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_New_PowerOff(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_New_PowerOffResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_New_TurnOffDisplayResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_New_PowerOn(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_New_PowerOnResult(SystemCtrlEvent const & _msg);

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
 * All state response for State :Unitialized 
 */
STM_Status SystemCtrl_ECB_Unitialized_SetTemperature(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Unitialized_SetTemperatureResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Unitialized_ShowTemperatureResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Unitialized_PowerOff(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Unitialized_PowerOffResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Unitialized_TurnOffDisplayResult(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Unitialized_PowerOn(SystemCtrlEvent const & _msg);
STM_Status SystemCtrl_ECB_Unitialized_PowerOnResult(SystemCtrlEvent const & _msg);


// State-Event Callback Matrix
typedef STM_Status (FP_SystemCtrl_ECB)(SystemCtrlEvent & _msg); 
FP_SystemCtrl_ECB const SystemCtrl_state_ecb_map[][] = { 
	{ 
		SystemCtrl_Idle_SetTemperature, 
		SystemCtrl_Idle_SetTemperatureResult, 
		SystemCtrl_Idle_ShowTemperatureResult, 
		SystemCtrl_Idle_PowerOff, 
		SystemCtrl_Idle_PowerOffResult, 
		SystemCtrl_Idle_TurnOffDisplayResult, 
		SystemCtrl_Idle_PowerOn, 
		SystemCtrl_Idle_PowerOnResult, 
	}, 
	{ 
		SystemCtrl_New_SetTemperature, 
		SystemCtrl_New_SetTemperatureResult, 
		SystemCtrl_New_ShowTemperatureResult, 
		SystemCtrl_New_PowerOff, 
		SystemCtrl_New_PowerOffResult, 
		SystemCtrl_New_TurnOffDisplayResult, 
		SystemCtrl_New_PowerOn, 
		SystemCtrl_New_PowerOnResult, 
	}, 
	{ 
		SystemCtrl_Working_SetTemperature, 
		SystemCtrl_Working_SetTemperatureResult, 
		SystemCtrl_Working_ShowTemperatureResult, 
		SystemCtrl_Working_PowerOff, 
		SystemCtrl_Working_PowerOffResult, 
		SystemCtrl_Working_TurnOffDisplayResult, 
		SystemCtrl_Working_PowerOn, 
		SystemCtrl_Working_PowerOnResult, 
	}, 
	{ 
		SystemCtrl_Unitialized_SetTemperature, 
		SystemCtrl_Unitialized_SetTemperatureResult, 
		SystemCtrl_Unitialized_ShowTemperatureResult, 
		SystemCtrl_Unitialized_PowerOff, 
		SystemCtrl_Unitialized_PowerOffResult, 
		SystemCtrl_Unitialized_TurnOffDisplayResult, 
		SystemCtrl_Unitialized_PowerOn, 
		SystemCtrl_Unitialized_PowerOnResult, 
	}, 
}; 


