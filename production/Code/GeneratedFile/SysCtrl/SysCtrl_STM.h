
#include "SysCtrl_EventDef.h"

// State definition
enum SysCtrl_State { 
    ST_STATE_MAX
};

// Event definition
enum SysCtrl_Event { 
    EV_DisableBTRsp,
    EV_EnableBTRsp,
    EV_EVENT_MAX
};

void SysCtrl_SetStatus(SysCtrl_State state);

SysCtrl_State SysCtrl_GetStatus();



// State-Event Callback Matrix
typedef STM_Status (FP_SysCtrl_ECB)(SysCtrlEvent & _msg); 
FP_SysCtrl_ECB const SysCtrl_state_ecb_map[][] = { 
}; 


