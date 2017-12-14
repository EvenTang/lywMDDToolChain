#include "SystemCtrl_API.h"




/* @brief Send message SetTemperature to module : SystemCtrl
 */
void SystemCtrl_API_SendMsgSetTemperatureToSystemCtrl(int32 _new_temp, int32 _last_temp) {
    SystemCtrlMessagge system_ctrl_msg;
    SetTemperature msg_set_temperature;
    
    msg_set_temperature.set_new_temp(_new_temp);
    msg_set_temperature.set_last_temp(_last_temp);
	
    system_ctrl_msg.set_set_temperature(msg_set_temperature);

    OSM_SendMsg(SystemCtrl, system_ctrl_msg);

}

/* @brief Send message SetTemperatureResult to module : SystemCtrl
 */
void SystemCtrl_API_SendMsgSetTemperatureResultToSystemCtrl(Result _result) {
    SystemCtrlMessagge system_ctrl_msg;
    SetTemperatureResult msg_set_temperature_result;
    
    msg_set_temperature_result.set_result(_result);
	
    system_ctrl_msg.set_set_temperature_result(msg_set_temperature_result);

    OSM_SendMsg(SystemCtrl, system_ctrl_msg);

}

/* @brief Send message ShowTemperatureResult to module : SystemCtrl
 */
void SystemCtrl_API_SendMsgShowTemperatureResultToSystemCtrl(Result _result) {
    SystemCtrlMessagge system_ctrl_msg;
    ShowTemperatureResult msg_show_temperature_result;
    
    msg_show_temperature_result.set_result(_result);
	
    system_ctrl_msg.set_show_temperature_result(msg_show_temperature_result);

    OSM_SendMsg(SystemCtrl, system_ctrl_msg);

}

/* @brief Send message PowerOffResult to module : SystemCtrl
 */
void SystemCtrl_API_SendMsgPowerOffResultToSystemCtrl(Result _result) {
    SystemCtrlMessagge system_ctrl_msg;
    PowerOffResult msg_power_off_result;
    
    msg_power_off_result.set_result(_result);
	
    system_ctrl_msg.set_power_off_result(msg_power_off_result);

    OSM_SendMsg(SystemCtrl, system_ctrl_msg);

}

/* @brief Send message TurnOffDisplayResult to module : SystemCtrl
 */
void SystemCtrl_API_SendMsgTurnOffDisplayResultToSystemCtrl(Result _result) {
    SystemCtrlMessagge system_ctrl_msg;
    TurnOffDisplayResult msg_turn_off_display_result;
    
    msg_turn_off_display_result.set_result(_result);
	
    system_ctrl_msg.set_turn_off_display_result(msg_turn_off_display_result);

    OSM_SendMsg(SystemCtrl, system_ctrl_msg);

}

/* @brief Send message PowerOnResult to module : SystemCtrl
 */
void SystemCtrl_API_SendMsgPowerOnResultToSystemCtrl(Result _result) {
    SystemCtrlMessagge system_ctrl_msg;
    PowerOnResult msg_power_on_result;
    
    msg_power_on_result.set_result(_result);
	
    system_ctrl_msg.set_power_on_result(msg_power_on_result);

    OSM_SendMsg(SystemCtrl, system_ctrl_msg);

}


