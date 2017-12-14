
#include "BTCtrl_EventDef.h"

// State definition
enum BTCtrl_State { 
    ST_STATE_MAX
};

// Event definition
enum BTCtrl_Event { 
    EV_MusicCtrl,
    EV_StartBT,
    EV_StartBtReq,
    EV_StopBT,
    EV_StopBtReq,
    EV_TxCmmDataReq,
    EV_EVENT_MAX
};

void BTCtrl_SetStatus(BTCtrl_State state);

BTCtrl_State BTCtrl_GetStatus();



// State-Event Callback Matrix
typedef STM_Status (FP_BTCtrl_ECB)(BTCtrlEvent & _msg); 
FP_BTCtrl_ECB const BTCtrl_state_ecb_map[][] = { 
}; 


