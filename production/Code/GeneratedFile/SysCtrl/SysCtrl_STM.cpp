#include "SysCtrl_STM.h"

static SysCtrl_State;



void SysCtrl_SetStatus(SysCtrl_State state){
    SysCtrl_State = state;
}

SysCtrl_State SysCtrl_GetStatus(){
    return SysCtrl_State;
}