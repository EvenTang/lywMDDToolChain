#include "Motor_STM.h"

static Motor_State;



void Motor_SetStatus(Motor_State state){
    Motor_State = state;
}

Motor_State Motor_GetStatus(){
    return Motor_State;
}