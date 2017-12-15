#include "BTCtrl_STM.h"

static BTCtrl_State;



void BTCtrl_SetStatus(BTCtrl_State state){
    BTCtrl_State = state;
}

BTCtrl_State BTCtrl_GetStatus(){
    return BTCtrl_State;
}