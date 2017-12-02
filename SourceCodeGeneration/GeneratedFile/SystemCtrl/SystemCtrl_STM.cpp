#include "SystemCtrl_STM.h"

static SystemCtrl_State;


/* @brief Event callback of SystemCtrl Module
 *        status : IDLE
 *        event  : SetTemperature
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_IDLE_SetTemperature(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_set_temperature());
    SetTemperature * p_msg_body = _msg.get_msg_set_temperature();
    assert(p_msg_body != nullptr);

    //> implementation of IDLE SetTemperature
    //> Motor_API_SendMessage_SetTemperature(param)
    Motor_API_SendMessage_SetTemperature(param);

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : IDLE
 *        event  : SetTemperatureResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_IDLE_SetTemperatureResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_set_temperature_result());
    SetTemperatureResult * p_msg_body = _msg.get_msg_set_temperature_result();
    assert(p_msg_body != nullptr);

    //> implementation of IDLE SetTemperatureResult

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : IDLE
 *        event  : ShowTemperatureResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_IDLE_ShowTemperatureResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_show_temperature_result());
    ShowTemperatureResult * p_msg_body = _msg.get_msg_show_temperature_result();
    assert(p_msg_body != nullptr);

    //> implementation of IDLE ShowTemperatureResult

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : IDLE
 *        event  : PowerOff
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_IDLE_PowerOff(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_off());
    PowerOff * p_msg_body = _msg.get_msg_power_off();
    assert(p_msg_body != nullptr);

    //> implementation of IDLE PowerOff

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : IDLE
 *        event  : PowerOffResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_IDLE_PowerOffResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_off_result());
    PowerOffResult * p_msg_body = _msg.get_msg_power_off_result();
    assert(p_msg_body != nullptr);

    //> implementation of IDLE PowerOffResult
    //> Display_API_SendMessage_TurnOffDisplay()
    Display_API_SendMessage_TurnOffDisplay();

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : IDLE
 *        event  : TurnOffDisplayResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_IDLE_TurnOffDisplayResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_turn_off_display_result());
    TurnOffDisplayResult * p_msg_body = _msg.get_msg_turn_off_display_result();
    assert(p_msg_body != nullptr);

    //> implementation of IDLE TurnOffDisplayResult
    //> RFComm_API_SendMessage_PowerOffResult(OK)
    RFComm_API_SendMessage_PowerOffResult(OK);

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : IDLE
 *        event  : PowerOn
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_IDLE_PowerOn(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_on());
    PowerOn * p_msg_body = _msg.get_msg_power_on();
    assert(p_msg_body != nullptr);

    //> implementation of IDLE PowerOn

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : IDLE
 *        event  : PowerOnResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_IDLE_PowerOnResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_on_result());
    PowerOnResult * p_msg_body = _msg.get_msg_power_on_result();
    assert(p_msg_body != nullptr);

    //> implementation of IDLE PowerOnResult

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : WORKING
 *        event  : SetTemperature
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_WORKING_SetTemperature(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_set_temperature());
    SetTemperature * p_msg_body = _msg.get_msg_set_temperature();
    assert(p_msg_body != nullptr);

    //> implementation of WORKING SetTemperature

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : WORKING
 *        event  : SetTemperatureResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_WORKING_SetTemperatureResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_set_temperature_result());
    SetTemperatureResult * p_msg_body = _msg.get_msg_set_temperature_result();
    assert(p_msg_body != nullptr);

    //> implementation of WORKING SetTemperatureResult
    //> alt: ?????
    //> opt: SystemCtrl_apiSucceed()
    if (SystemCtrl_apiSucceed()) {
        //> A_API_SendMessage_Test1()
        A_API_SendMessage_Test1();
        //> alt: ?????
        //> opt: SystemCtrl_apiOk()
        if (SystemCtrl_apiOk()) {
            //> loop: SystemCtrl_api100times()
            while (SystemCtrl_api100times()) {
                //> Motor_API_SendMessage_Test2()
                Motor_API_SendMessage_Test2();
            }
            //> :end
        }
        //> opt: SystemCtrl_apiNg()
        else if (SystemCtrl_apiNg()) {
            //> loop: SystemCtrl_api100times()
            while (SystemCtrl_api100times()) {
                //> alt: ?????
                //> opt: SystemCtrl_apiOk()
                if (SystemCtrl_apiOk()) {
                    //> Motor_API_SendMessage_Test3()
                    Motor_API_SendMessage_Test3();
                }
                //> opt: 
                else {
                    //> Motor_API_SendMessage_Test4()
                    Motor_API_SendMessage_Test4();
                }
                //> :end
            }
            //> :end
        }
        //> :end
    }
    //> opt: SystemCtrl_apiFailed()
    else if (SystemCtrl_apiFailed()) {
        //> A_API_SendMessage_Test11()
        A_API_SendMessage_Test11();
    }
    //> :end
    //> Display_API_SendMessage_ShowTemperature(param)
    Display_API_SendMessage_ShowTemperature(param);

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : WORKING
 *        event  : ShowTemperatureResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_WORKING_ShowTemperatureResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_show_temperature_result());
    ShowTemperatureResult * p_msg_body = _msg.get_msg_show_temperature_result();
    assert(p_msg_body != nullptr);

    //> implementation of WORKING ShowTemperatureResult
    //> ShareOBJ_API_SetTemperature(param)
    ShareOBJ_API_SetTemperature(param);
    //> RFComm_API_SendMessage_SetTemperatureResult(OK)
    RFComm_API_SendMessage_SetTemperatureResult(OK);

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : WORKING
 *        event  : PowerOff
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_WORKING_PowerOff(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_off());
    PowerOff * p_msg_body = _msg.get_msg_power_off();
    assert(p_msg_body != nullptr);

    //> implementation of WORKING PowerOff

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : WORKING
 *        event  : PowerOffResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_WORKING_PowerOffResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_off_result());
    PowerOffResult * p_msg_body = _msg.get_msg_power_off_result();
    assert(p_msg_body != nullptr);

    //> implementation of WORKING PowerOffResult

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : WORKING
 *        event  : TurnOffDisplayResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_WORKING_TurnOffDisplayResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_turn_off_display_result());
    TurnOffDisplayResult * p_msg_body = _msg.get_msg_turn_off_display_result();
    assert(p_msg_body != nullptr);

    //> implementation of WORKING TurnOffDisplayResult

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : WORKING
 *        event  : PowerOn
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_WORKING_PowerOn(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_on());
    PowerOn * p_msg_body = _msg.get_msg_power_on();
    assert(p_msg_body != nullptr);

    //> implementation of WORKING PowerOn

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : WORKING
 *        event  : PowerOnResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_WORKING_PowerOnResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_on_result());
    PowerOnResult * p_msg_body = _msg.get_msg_power_on_result();
    assert(p_msg_body != nullptr);

    //> implementation of WORKING PowerOnResult

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : SC_UNINITIALIZED
 *        event  : SetTemperature
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_SC_UNINITIALIZED_SetTemperature(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_set_temperature());
    SetTemperature * p_msg_body = _msg.get_msg_set_temperature();
    assert(p_msg_body != nullptr);

    //> implementation of SC_UNINITIALIZED SetTemperature

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : SC_UNINITIALIZED
 *        event  : SetTemperatureResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_SC_UNINITIALIZED_SetTemperatureResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_set_temperature_result());
    SetTemperatureResult * p_msg_body = _msg.get_msg_set_temperature_result();
    assert(p_msg_body != nullptr);

    //> implementation of SC_UNINITIALIZED SetTemperatureResult

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : SC_UNINITIALIZED
 *        event  : ShowTemperatureResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_SC_UNINITIALIZED_ShowTemperatureResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_show_temperature_result());
    ShowTemperatureResult * p_msg_body = _msg.get_msg_show_temperature_result();
    assert(p_msg_body != nullptr);

    //> implementation of SC_UNINITIALIZED ShowTemperatureResult
    //> RFComm_API_SendMessage_PowerOn(OK)
    RFComm_API_SendMessage_PowerOn(OK);

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : SC_UNINITIALIZED
 *        event  : PowerOff
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_SC_UNINITIALIZED_PowerOff(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_off());
    PowerOff * p_msg_body = _msg.get_msg_power_off();
    assert(p_msg_body != nullptr);

    //> implementation of SC_UNINITIALIZED PowerOff

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : SC_UNINITIALIZED
 *        event  : PowerOffResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_SC_UNINITIALIZED_PowerOffResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_off_result());
    PowerOffResult * p_msg_body = _msg.get_msg_power_off_result();
    assert(p_msg_body != nullptr);

    //> implementation of SC_UNINITIALIZED PowerOffResult

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : SC_UNINITIALIZED
 *        event  : TurnOffDisplayResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_SC_UNINITIALIZED_TurnOffDisplayResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_turn_off_display_result());
    TurnOffDisplayResult * p_msg_body = _msg.get_msg_turn_off_display_result();
    assert(p_msg_body != nullptr);

    //> implementation of SC_UNINITIALIZED TurnOffDisplayResult

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : SC_UNINITIALIZED
 *        event  : PowerOn
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_SC_UNINITIALIZED_PowerOn(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_on());
    PowerOn * p_msg_body = _msg.get_msg_power_on();
    assert(p_msg_body != nullptr);

    //> implementation of SC_UNINITIALIZED PowerOn
    //> SystemCtrl_api_Initilize()
    SystemCtrl_api_Initilize();
    //> ShareOBJ_API_ReadLastTemeprature()
    ShareOBJ_API_ReadLastTemeprature();
    //> ShareOBJ_API_ReadLastMode()
    ShareOBJ_API_ReadLastMode();
    //> Motor_API_SendMessage_PowerOn(lv_last_temprature, lv_last_mode)
    Motor_API_SendMessage_PowerOn(lv_last_temprature, lv_last_mode);

    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : SC_UNINITIALIZED
 *        event  : PowerOnResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_SC_UNINITIALIZED_PowerOnResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_on_result());
    PowerOnResult * p_msg_body = _msg.get_msg_power_on_result();
    assert(p_msg_body != nullptr);

    //> implementation of SC_UNINITIALIZED PowerOnResult
    //> Display_API_SendMessage_ShowTemperature(lv_last_temprature)
    Display_API_SendMessage_ShowTemperature(lv_last_temprature);

    return STM_STATS_OK;
}


void SystemCtrl_SetStatus(SystemCtrl_State state){
    SystemCtrl_State = state;
}

SystemCtrl_State SystemCtrl_GetStatus(){
    return SystemCtrl_State;
}