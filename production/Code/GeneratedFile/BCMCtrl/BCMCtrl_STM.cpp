#include "BCMCtrl_STM.h"

static BCMCtrl_State;



void BCMCtrl_SetStatus(BCMCtrl_State state){
    BCMCtrl_State = state;
}

BCMCtrl_State BCMCtrl_GetStatus(){
    return BCMCtrl_State;
}