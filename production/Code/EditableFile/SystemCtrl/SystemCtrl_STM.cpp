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
	
	//> alt: if the power is off
	//> opt: power is off
		//> haha
		//> loop: retry for 3 times
			//> do something
			//> alt: need to retry?
			//> opt: yes
				//> OK, let's retry
			//> :end
		//> :end
	//> opt: power is on
		//> hoho
	//> :end
	//> continue to do something
	//> alt: if the power is off
	//> opt: power is off
		//> haha
		//> loop: retry for 3 times
			//> do something
			//> alt: need to retry?
			//> opt: yes
				//> OK, let's retry
			//> :end
		//> :end
	//> opt: power is on
		//> hoho
	//> :end
	//> everything is end
	

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

    return STM_STATS_OK;
}
