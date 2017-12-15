#include "VehicleAgent_STM.h"

static VehicleAgent_State;



void VehicleAgent_SetStatus(VehicleAgent_State state){
    VehicleAgent_State = state;
}

VehicleAgent_State VehicleAgent_GetStatus(){
    return VehicleAgent_State;
}