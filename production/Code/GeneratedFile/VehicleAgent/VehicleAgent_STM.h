
#include "VehicleAgent_EventDef.h"

// State definition
enum VehicleAgent_State { 
    ST_STATE_MAX
};

// Event definition
enum VehicleAgent_Event { 
    EV_AuthcompleteNtf,
    EV_LockMainstandReq,
    EV_LockVehilceReq,
    EV_UnlockSeatReq,
    EV_EVENT_MAX
};

void VehicleAgent_SetStatus(VehicleAgent_State state);

VehicleAgent_State VehicleAgent_GetStatus();



// State-Event Callback Matrix
typedef STM_Status (FP_VehicleAgent_ECB)(VehicleAgentEvent & _msg); 
FP_VehicleAgent_ECB const VehicleAgent_state_ecb_map[][] = { 
}; 


