
#include "Motor_EventDef.h"

// State definition
enum Motor_State { 
    ST_STATE_MAX
};

// Event definition
enum Motor_Event { 
    EV_SetTemperature,
    EV_Test2,
    EV_Test3,
    EV_Test4,
    EV_PowerOff,
    EV_PowerOn,
    EV_EVENT_MAX
};

void Motor_SetStatus(Motor_State state);

Motor_State Motor_GetStatus();



// State-Event Callback Matrix
typedef STM_Status (FP_Motor_ECB)(MotorEvent & _msg); 
FP_Motor_ECB const Motor_state_ecb_map[][] = { 
}; 


