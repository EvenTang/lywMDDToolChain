
#include "BCMCtrl_EventDef.h"

// State definition
enum BCMCtrl_State { 
    ST_STATE_MAX
};

// Event definition
enum BCMCtrl_Event { 
    EV_EVENT_MAX
};

void BCMCtrl_SetStatus(BCMCtrl_State state);

BCMCtrl_State BCMCtrl_GetStatus();



// State-Event Callback Matrix
typedef STM_Status (FP_BCMCtrl_ECB)(BCMCtrlEvent & _msg); 
FP_BCMCtrl_ECB const BCMCtrl_state_ecb_map[][] = { 
}; 


