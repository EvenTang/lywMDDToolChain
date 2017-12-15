#include "EVSrv_STM.h"

static EVSrv_State;



void EVSrv_SetStatus(EVSrv_State state){
    EVSrv_State = state;
}

EVSrv_State EVSrv_GetStatus(){
    return EVSrv_State;
}