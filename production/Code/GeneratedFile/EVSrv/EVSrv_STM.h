
#include "EVSrv_EventDef.h"

// State definition
enum EVSrv_State { 
    ST_STATE_MAX
};

// Event definition
enum EVSrv_Event { 
    EV_EVENT_MAX
};

void EVSrv_SetStatus(EVSrv_State state);

EVSrv_State EVSrv_GetStatus();



// State-Event Callback Matrix
typedef STM_Status (FP_EVSrv_ECB)(EVSrvEvent & _msg); 
FP_EVSrv_ECB const EVSrv_state_ecb_map[][] = { 
}; 


