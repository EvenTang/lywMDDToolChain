#include "SystemCtrl_STM.h"


/* @brief Event callback of SystemCtrl Module
 *        status : Idle
 *        event  : SetTemperature
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Idle_SetTemperature(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_set_temperature());
    SetTemperature * p_msg_body = _msg.get_msg_set_temperature();
    assert(p_msg_body != nullptr);
    //> implementation of Idle SetTemperature

    
    SetTemperature(new_temp=param)
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Idle
 *        event  : SetTemperatureResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Idle_SetTemperatureResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_set_temperature_result());
    SetTemperatureResult * p_msg_body = _msg.get_msg_set_temperature_result();
    assert(p_msg_body != nullptr);
    //> implementation of Idle SetTemperatureResult

    
    if (Succeed()) {
        Test1
        if (Ok()) {
            while (100times/'addByShiweizBegin'/()) {
                Test2
            }
        }
        else if (Ng()) {
            while (100times()) {
                if (Ok()) {
                    Test3
                }
                else {
                    Test4
                }
            }
        }
    }
    else if (Failed()) {
        Test11
    }
    ShowTemperature(new_temp=param)
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Idle
 *        event  : ShowTemperatureResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Idle_ShowTemperatureResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_show_temperature_result());
    ShowTemperatureResult * p_msg_body = _msg.get_msg_show_temperature_result();
    assert(p_msg_body != nullptr);
    //> implementation of Idle ShowTemperatureResult

    
    
    SetTemperatureResult(result=OK)
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Idle
 *        event  : PowerOff
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Idle_PowerOff(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_off());
    PowerOff * p_msg_body = _msg.get_msg_power_off();
    assert(p_msg_body != nullptr);
    //> implementation of Idle PowerOff

    
    PowerOff
    TurnOffDisplay
    PowerOffResult(result=OK)
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Idle
 *        event  : PowerOffResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Idle_PowerOffResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_off_result());
    PowerOffResult * p_msg_body = _msg.get_msg_power_off_result();
    assert(p_msg_body != nullptr);
    //> implementation of Idle PowerOffResult

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Idle
 *        event  : TurnOffDisplayResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Idle_TurnOffDisplayResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_turn_off_display_result());
    TurnOffDisplayResult * p_msg_body = _msg.get_msg_turn_off_display_result();
    assert(p_msg_body != nullptr);
    //> implementation of Idle TurnOffDisplayResult

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Idle
 *        event  : PowerOn
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Idle_PowerOn(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_on());
    PowerOn * p_msg_body = _msg.get_msg_power_on();
    assert(p_msg_body != nullptr);
    //> implementation of Idle PowerOn

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Idle
 *        event  : PowerOnResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Idle_PowerOnResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_on_result());
    PowerOnResult * p_msg_body = _msg.get_msg_power_on_result();
    assert(p_msg_body != nullptr);
    //> implementation of Idle PowerOnResult

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : New
 *        event  : SetTemperature
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_New_SetTemperature(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_set_temperature());
    SetTemperature * p_msg_body = _msg.get_msg_set_temperature();
    assert(p_msg_body != nullptr);
    //> implementation of New SetTemperature

    
    SetTemperature(new_temp=param)
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : New
 *        event  : SetTemperatureResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_New_SetTemperatureResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_set_temperature_result());
    SetTemperatureResult * p_msg_body = _msg.get_msg_set_temperature_result();
    assert(p_msg_body != nullptr);
    //> implementation of New SetTemperatureResult

    
    if (Succeed()) {
        Test1
        if (Ok()) {
            while (100times/'addByShiweizBegin'/()) {
                Test2
            }
        }
        else if (Ng()) {
            while (100times()) {
                if (Ok()) {
                    Test3
                }
                else {
                    Test4
                }
            }
        }
    }
    else if (Failed()) {
        Test11
    }
    ShowTemperature(new_temp=param)
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : New
 *        event  : ShowTemperatureResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_New_ShowTemperatureResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_show_temperature_result());
    ShowTemperatureResult * p_msg_body = _msg.get_msg_show_temperature_result();
    assert(p_msg_body != nullptr);
    //> implementation of New ShowTemperatureResult

    
    
    SetTemperatureResult(result=OK)
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : New
 *        event  : PowerOff
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_New_PowerOff(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_off());
    PowerOff * p_msg_body = _msg.get_msg_power_off();
    assert(p_msg_body != nullptr);
    //> implementation of New PowerOff

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : New
 *        event  : PowerOffResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_New_PowerOffResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_off_result());
    PowerOffResult * p_msg_body = _msg.get_msg_power_off_result();
    assert(p_msg_body != nullptr);
    //> implementation of New PowerOffResult

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : New
 *        event  : TurnOffDisplayResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_New_TurnOffDisplayResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_turn_off_display_result());
    TurnOffDisplayResult * p_msg_body = _msg.get_msg_turn_off_display_result();
    assert(p_msg_body != nullptr);
    //> implementation of New TurnOffDisplayResult

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : New
 *        event  : PowerOn
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_New_PowerOn(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_on());
    PowerOn * p_msg_body = _msg.get_msg_power_on();
    assert(p_msg_body != nullptr);
    //> implementation of New PowerOn

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : New
 *        event  : PowerOnResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_New_PowerOnResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_on_result());
    PowerOnResult * p_msg_body = _msg.get_msg_power_on_result();
    assert(p_msg_body != nullptr);
    //> implementation of New PowerOnResult

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Working
 *        event  : SetTemperature
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Working_SetTemperature(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_set_temperature());
    SetTemperature * p_msg_body = _msg.get_msg_set_temperature();
    assert(p_msg_body != nullptr);
    //> implementation of Working SetTemperature

    
    if (Succeed()) {
        Test1
        if (Ok()) {
            while (100times/'addByShiweizBegin'/()) {
                Test2
            }
        }
        else if (Ng()) {
            while (100times()) {
                if (Ok()) {
                    Test3
                }
                else {
                    Test4
                }
            }
        }
    }
    else if (Failed()) {
        Test11
    }
    ShowTemperature(new_temp=param)
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Working
 *        event  : SetTemperatureResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Working_SetTemperatureResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_set_temperature_result());
    SetTemperatureResult * p_msg_body = _msg.get_msg_set_temperature_result();
    assert(p_msg_body != nullptr);
    //> implementation of Working SetTemperatureResult

    
    if (Succeed()) {
        Test1
        if (Ok()) {
            while (100times/'addByShiweizBegin'/()) {
                Test2
            }
        }
        else if (Ng()) {
            while (100times()) {
                if (Ok()) {
                    Test3
                }
                else {
                    Test4
                }
            }
        }
    }
    else if (Failed()) {
        Test11
    }
    ShowTemperature(new_temp=param)
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Working
 *        event  : ShowTemperatureResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Working_ShowTemperatureResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_show_temperature_result());
    ShowTemperatureResult * p_msg_body = _msg.get_msg_show_temperature_result();
    assert(p_msg_body != nullptr);
    //> implementation of Working ShowTemperatureResult

    
    
    SetTemperatureResult(result=OK)
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Working
 *        event  : PowerOff
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Working_PowerOff(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_off());
    PowerOff * p_msg_body = _msg.get_msg_power_off();
    assert(p_msg_body != nullptr);
    //> implementation of Working PowerOff

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Working
 *        event  : PowerOffResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Working_PowerOffResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_off_result());
    PowerOffResult * p_msg_body = _msg.get_msg_power_off_result();
    assert(p_msg_body != nullptr);
    //> implementation of Working PowerOffResult

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Working
 *        event  : TurnOffDisplayResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Working_TurnOffDisplayResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_turn_off_display_result());
    TurnOffDisplayResult * p_msg_body = _msg.get_msg_turn_off_display_result();
    assert(p_msg_body != nullptr);
    //> implementation of Working TurnOffDisplayResult

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Working
 *        event  : PowerOn
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Working_PowerOn(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_on());
    PowerOn * p_msg_body = _msg.get_msg_power_on();
    assert(p_msg_body != nullptr);
    //> implementation of Working PowerOn

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Working
 *        event  : PowerOnResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Working_PowerOnResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_on_result());
    PowerOnResult * p_msg_body = _msg.get_msg_power_on_result();
    assert(p_msg_body != nullptr);
    //> implementation of Working PowerOnResult

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Unitialized
 *        event  : SetTemperature
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Unitialized_SetTemperature(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_set_temperature());
    SetTemperature * p_msg_body = _msg.get_msg_set_temperature();
    assert(p_msg_body != nullptr);
    //> implementation of Unitialized SetTemperature

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Unitialized
 *        event  : SetTemperatureResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Unitialized_SetTemperatureResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_set_temperature_result());
    SetTemperatureResult * p_msg_body = _msg.get_msg_set_temperature_result();
    assert(p_msg_body != nullptr);
    //> implementation of Unitialized SetTemperatureResult

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Unitialized
 *        event  : ShowTemperatureResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Unitialized_ShowTemperatureResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_show_temperature_result());
    ShowTemperatureResult * p_msg_body = _msg.get_msg_show_temperature_result();
    assert(p_msg_body != nullptr);
    //> implementation of Unitialized ShowTemperatureResult

    
    PowerOn(result=OK)
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Unitialized
 *        event  : PowerOff
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Unitialized_PowerOff(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_off());
    PowerOff * p_msg_body = _msg.get_msg_power_off();
    assert(p_msg_body != nullptr);
    //> implementation of Unitialized PowerOff

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Unitialized
 *        event  : PowerOffResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Unitialized_PowerOffResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_off_result());
    PowerOffResult * p_msg_body = _msg.get_msg_power_off_result();
    assert(p_msg_body != nullptr);
    //> implementation of Unitialized PowerOffResult

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Unitialized
 *        event  : TurnOffDisplayResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Unitialized_TurnOffDisplayResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_turn_off_display_result());
    TurnOffDisplayResult * p_msg_body = _msg.get_msg_turn_off_display_result();
    assert(p_msg_body != nullptr);
    //> implementation of Unitialized TurnOffDisplayResult

    
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Unitialized
 *        event  : PowerOn
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Unitialized_PowerOn(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_on());
    PowerOn * p_msg_body = _msg.get_msg_power_on();
    assert(p_msg_body != nullptr);
    //> implementation of Unitialized PowerOn

    
    
    
    PowerOn(last_temperature=lv_last_temprature, last_mode=lv_last_mode)
    return STM_STATS_OK;
}

/* @brief Event callback of SystemCtrl Module
 *        status : Unitialized
 *        event  : PowerOnResult
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : SystemCtrlEvent
 * @return STM_Status
 */
STM_Status SystemCtrl_ECB_Unitialized_PowerOnResult(SystemCtrlEvent const & _msg) {
    assert(_msg.has_msg_power_on_result());
    PowerOnResult * p_msg_body = _msg.get_msg_power_on_result();
    assert(p_msg_body != nullptr);
    //> implementation of Unitialized PowerOnResult

    
    ShowTemperature(last_temprature=lv_last_temprature)
    return STM_STATS_OK;
}
