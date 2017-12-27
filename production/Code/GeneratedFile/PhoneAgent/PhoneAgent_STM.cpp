#include "PhoneAgent_STM.h"

static PhoneAgent_State;


/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : CancelChargePlanRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_CancelChargePlanRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_cancel_charge_plan_rsp());
    CancelChargePlanRsp * p_msg_body = _msg.get_msg_cancel_charge_plan_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED CancelChargePlanRsp
    //> PhoneAgent_api_TX_NtfCancelChargePlanRslt(rslt)
    PhoneAgent_api_TX_NtfCancelChargePlanRslt(rslt);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : ConfigDriveModeRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_ConfigDriveModeRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_config_drive_mode_rsp());
    ConfigDriveModeRsp * p_msg_body = _msg.get_msg_config_drive_mode_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED ConfigDriveModeRsp
    //> PhoneAgent_api_TX_NtfDriveModeSetRslt(rslt)
    PhoneAgent_api_TX_NtfDriveModeSetRslt(rslt);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : BTConnectedNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_BTConnectedNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_bt_connected_ntf());
    BTConnectedNtf * p_msg_body = _msg.get_msg_bt_connected_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED BTConnectedNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : BTDisconnectedNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_BTDisconnectedNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_bt_disconnected_ntf());
    BTDisconnectedNtf * p_msg_body = _msg.get_msg_bt_disconnected_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED BTDisconnectedNtf
    //> PhoneAgent_api_Reset()
    PhoneAgent_api_Reset();

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : EngineStsNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_EngineStsNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_engine_sts_ntf());
    EngineStsNtf * p_msg_body = _msg.get_msg_engine_sts_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED EngineStsNtf
    //> PhoneAgent_api_TX_NtfEngineSts(sts)
    PhoneAgent_api_TX_NtfEngineSts(sts);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : RcvSppDataNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_RcvSppDataNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_rcv_spp_data_ntf());
    RcvSppDataNtf * p_msg_body = _msg.get_msg_rcv_spp_data_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED RcvSppDataNtf
    //> PhoneAgent_api_Dispatch_ProcessReceiveCmd(data_buf, 123)
    PhoneAgent_api_Dispatch_ProcessReceiveCmd(data_buf, 123);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : VehicleLockCtrlRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_VehicleLockCtrlRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_vehicle_lock_ctrl_rsp());
    VehicleLockCtrlRsp * p_msg_body = _msg.get_msg_vehicle_lock_ctrl_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED VehicleLockCtrlRsp
    //> PhoneAgent_api_TX_NtfMainstandLockRslt(rslt)
    PhoneAgent_api_TX_NtfMainstandLockRslt(rslt);
    //> PhoneAgent_api_TX_NtfVehicleLockRslt(rslt)
    PhoneAgent_api_TX_NtfVehicleLockRslt(rslt);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : MainStandCtrlRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_MainStandCtrlRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_main_stand_ctrl_rsp());
    MainStandCtrlRsp * p_msg_body = _msg.get_msg_main_stand_ctrl_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED MainStandCtrlRsp
    //> PhoneAgent_api_TX_NtfMainstandLockRslt()
    PhoneAgent_api_TX_NtfMainstandLockRslt();

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : LockStsChgNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_LockStsChgNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_lock_sts_chg_ntf());
    LockStsChgNtf * p_msg_body = _msg.get_msg_lock_sts_chg_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED LockStsChgNtf
    //> PhoneAgent_api_TX_NtfLockSts(SHARE_LOCK_STATUS_LOCKED)
    PhoneAgent_api_TX_NtfLockSts(SHARE_LOCK_STATUS_LOCKED);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : OperationA2dpRst
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_OperationA2dpRst(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_operation_a2dp_rst());
    OperationA2dpRst * p_msg_body = _msg.get_msg_operation_a2dp_rst();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED OperationA2dpRst
    //> alt: ?????
    //> opt: BTCTRL_RESULT_A2DP_CONNECT_OK==rslt
    if (BTCTRL_RESULT_A2DP_CONNECT_OK==rslt) {
        //> BTCtrl_API_GetCurrentBTProtocol()
        BTCtrl_API_GetCurrentBTProtocol();
        //> alt: ?????
        //> opt: BT_DATA_PROT_BLE==DataProttype
        if (BT_DATA_PROT_BLE==DataProttype) {
            //> PhoneAgent_api_TX_NtfPhoneMacAddress()
            PhoneAgent_api_TX_NtfPhoneMacAddress();
        }
        //> :end
    }
    //> opt: 
    else {
        //> PhoneAgent_api_SetDataSendFlag(FALSE)
        PhoneAgent_api_SetDataSendFlag(FALSE);
        //> PhoneAgent_api_CancelTxDataTimer()
        PhoneAgent_api_CancelTxDataTimer();
    }
    //> :end
    //> PhoneAgent_api_IsDataQueueEmpty()
    PhoneAgent_api_IsDataQueueEmpty();
    //> alt: ?????
    //> opt: FALSE==rslt
    if (FALSE==rslt) {
        //> PhoneAgent_api_SendQueueData()
        PhoneAgent_api_SendQueueData();
    }
    //> :end

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : MusicCtrlCmdReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_MusicCtrlCmdReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_music_ctrl_cmd_req());
    MusicCtrlCmdReq * p_msg_body = _msg.get_msg_music_ctrl_cmd_req();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED MusicCtrlCmdReq
    //> PhoneAgent_api_SendBTMusicCtrlCmd(BCMCTRL_MUSIC_BUTTON_STOP)
    PhoneAgent_api_SendBTMusicCtrlCmd(BCMCTRL_MUSIC_BUTTON_STOP);
    //> PhoneAgent_api_SendBTMusicCtrlCmd(BCMCTRL_MUSIC_BUTTON_PREVIOUS)
    PhoneAgent_api_SendBTMusicCtrlCmd(BCMCTRL_MUSIC_BUTTON_PREVIOUS);
    //> PhoneAgent_api_SendBTMusicCtrlCmd(BCMCTRL_MUSIC_BUTTON_NEXT)
    PhoneAgent_api_SendBTMusicCtrlCmd(BCMCTRL_MUSIC_BUTTON_NEXT);
    //> PhoneAgent_api_SendBTMusicCtrlCmd(BCMCTRL_MUSIC_BUTTON_PLAY)
    PhoneAgent_api_SendBTMusicCtrlCmd(BCMCTRL_MUSIC_BUTTON_PLAY);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : SendDataRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_SendDataRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_send_data_rslt_ntf());
    SendDataRsltNtf * p_msg_body = _msg.get_msg_send_data_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED SendDataRsltNtf
    //> PhoneAgent_api_GetCurrentEvt()
    PhoneAgent_api_GetCurrentEvt();
    //> PhoneAgent_api_CancelTxDataTimer()
    PhoneAgent_api_CancelTxDataTimer();
    //> PhoneAgent_api_SetDataSendFlag(FALSE)
    PhoneAgent_api_SetDataSendFlag(FALSE);
    //> PhoneAgent_api_NotifySendRsltToOtherModule(current_evt, rslt)
    PhoneAgent_api_NotifySendRsltToOtherModule(current_evt, rslt);
    //> PhoneAgent_api_IsDataQueueEmpty()
    PhoneAgent_api_IsDataQueueEmpty();
    //> alt: ?????
    //> opt: FALSE==is_empty
    if (FALSE==is_empty) {
        //> PhoneAgent_api_SendQueueData()
        PhoneAgent_api_SendQueueData();
    }
    //> :end

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : EnableBtReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_EnableBtReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_enable_bt_req());
    EnableBtReq * p_msg_body = _msg.get_msg_enable_bt_req();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED EnableBtReq

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : StartBTRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_StartBTRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_start_bt_rslt_ntf());
    StartBTRsltNtf * p_msg_body = _msg.get_msg_start_bt_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED StartBTRsltNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : DisableBtReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_DisableBtReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_disable_bt_req());
    DisableBtReq * p_msg_body = _msg.get_msg_disable_bt_req();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED DisableBtReq
    //> PhoneAgent_api_CancelBTCtrlTimer()
    PhoneAgent_api_CancelBTCtrlTimer();
    //> PhoneAgent_api_StopBTModule()
    PhoneAgent_api_StopBTModule();
    //> PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_DISABLE_BT_REQ)
    PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_DISABLE_BT_REQ);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : StopBTRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_StopBTRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_stop_bt_rslt_ntf());
    StopBTRsltNtf * p_msg_body = _msg.get_msg_stop_bt_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED StopBTRsltNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : RKLearingRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_RKLearingRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_rk_learing_rsp());
    RKLearingRsp * p_msg_body = _msg.get_msg_rk_learing_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED RKLearingRsp
    //> PhoneAgent_api_TX_NtfRKLearningRslt(type, rslt)
    PhoneAgent_api_TX_NtfRKLearningRslt(type, rslt);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : SetChargePlanRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_SetChargePlanRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_set_charge_plan_rsp());
    SetChargePlanRsp * p_msg_body = _msg.get_msg_set_charge_plan_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED SetChargePlanRsp
    //> PhoneAgent_api_TX_NtfChargePlanSettingRslt(rslt)
    PhoneAgent_api_TX_NtfChargePlanSettingRslt(rslt);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : SetPreferenceRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_SetPreferenceRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_set_preference_rsp());
    SetPreferenceRsp * p_msg_body = _msg.get_msg_set_preference_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED SetPreferenceRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : StartSrvReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_StartSrvReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_start_srv_req());
    StartSrvReq * p_msg_body = _msg.get_msg_start_srv_req();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED StartSrvReq

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : StopSrvReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_StopSrvReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_stop_srv_req());
    StopSrvReq * p_msg_body = _msg.get_msg_stop_srv_req();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED StopSrvReq
    //> PhoneAgent_api_CancelBTCtrlTimer()
    PhoneAgent_api_CancelBTCtrlTimer();
    //> PhoneAgent_api_StopBTModule()
    PhoneAgent_api_StopBTModule();
    //> PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_STOP_SRV_REQ)
    PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_STOP_SRV_REQ);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : SeatCtrlRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_SeatCtrlRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_seat_ctrl_rsp());
    SeatCtrlRsp * p_msg_body = _msg.get_msg_seat_ctrl_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED SeatCtrlRsp
    //> PhoneAgent_api_TX_NtfSaddleLockRslt(rslt)
    PhoneAgent_api_TX_NtfSaddleLockRslt(rslt);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : CONNECTED
 *        event  : UpdateRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_CONNECTED_UpdateRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_update_rslt_ntf());
    UpdateRsltNtf * p_msg_body = _msg.get_msg_update_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of CONNECTED UpdateRsltNtf
    //> PhoneAgent_api_NtfOTAUpdateRslt(PHONE_RESULT_OK)
    PhoneAgent_api_NtfOTAUpdateRslt(PHONE_RESULT_OK);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : CancelChargePlanRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_CancelChargePlanRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_cancel_charge_plan_rsp());
    CancelChargePlanRsp * p_msg_body = _msg.get_msg_cancel_charge_plan_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED CancelChargePlanRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : ConfigDriveModeRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_ConfigDriveModeRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_config_drive_mode_rsp());
    ConfigDriveModeRsp * p_msg_body = _msg.get_msg_config_drive_mode_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED ConfigDriveModeRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : BTConnectedNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_BTConnectedNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_bt_connected_ntf());
    BTConnectedNtf * p_msg_body = _msg.get_msg_bt_connected_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED BTConnectedNtf
    //> PhoneAgent_api_NotifyAuthRsltToVehicle()
    PhoneAgent_api_NotifyAuthRsltToVehicle();
    //> ShareOBJ_API_SetBTIcon(TRUE)
    ShareOBJ_API_SetBTIcon(TRUE);
    //> BCMCtrl_API_GetBTPlaySwitchStatus()
    BCMCtrl_API_GetBTPlaySwitchStatus();
    //> alt: ?????
    //> opt: BCM_INPUT_STATUS_SW_ON==switch_status
    if (BCM_INPUT_STATUS_SW_ON==switch_status) {
        //> PhoneAgent_api_NtfBTMusicSource(TRUE)
        PhoneAgent_api_NtfBTMusicSource(TRUE);
    }
    //> opt: 
    else {
        //> PhoneAgent_api_NtfBTMusicSource(FALSE)
        PhoneAgent_api_NtfBTMusicSource(FALSE);
    }
    //> :end
    //> BTCtrl_API_CheckConnectA2DOCondition()
    BTCtrl_API_CheckConnectA2DOCondition();
    //> alt: ?????
    //> opt: TRUE==is_a2dp
    if (TRUE==is_a2dp) {
        //> PhoneAgent_api_Dispatch_SendPackToQueue(4, PHONE_AGENT_EVT_CONNECT_A2DP_REQ)
        PhoneAgent_api_Dispatch_SendPackToQueue(4, PHONE_AGENT_EVT_CONNECT_A2DP_REQ);
    }
    //> :end

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : BTDisconnectedNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_BTDisconnectedNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_bt_disconnected_ntf());
    BTDisconnectedNtf * p_msg_body = _msg.get_msg_bt_disconnected_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED BTDisconnectedNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : EngineStsNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_EngineStsNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_engine_sts_ntf());
    EngineStsNtf * p_msg_body = _msg.get_msg_engine_sts_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED EngineStsNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : RcvSppDataNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_RcvSppDataNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_rcv_spp_data_ntf());
    RcvSppDataNtf * p_msg_body = _msg.get_msg_rcv_spp_data_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED RcvSppDataNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : VehicleLockCtrlRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_VehicleLockCtrlRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_vehicle_lock_ctrl_rsp());
    VehicleLockCtrlRsp * p_msg_body = _msg.get_msg_vehicle_lock_ctrl_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED VehicleLockCtrlRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : MainStandCtrlRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_MainStandCtrlRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_main_stand_ctrl_rsp());
    MainStandCtrlRsp * p_msg_body = _msg.get_msg_main_stand_ctrl_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED MainStandCtrlRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : LockStsChgNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_LockStsChgNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_lock_sts_chg_ntf());
    LockStsChgNtf * p_msg_body = _msg.get_msg_lock_sts_chg_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED LockStsChgNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : OperationA2dpRst
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_OperationA2dpRst(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_operation_a2dp_rst());
    OperationA2dpRst * p_msg_body = _msg.get_msg_operation_a2dp_rst();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED OperationA2dpRst

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : MusicCtrlCmdReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_MusicCtrlCmdReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_music_ctrl_cmd_req());
    MusicCtrlCmdReq * p_msg_body = _msg.get_msg_music_ctrl_cmd_req();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED MusicCtrlCmdReq

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : SendDataRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_SendDataRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_send_data_rslt_ntf());
    SendDataRsltNtf * p_msg_body = _msg.get_msg_send_data_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED SendDataRsltNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : EnableBtReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_EnableBtReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_enable_bt_req());
    EnableBtReq * p_msg_body = _msg.get_msg_enable_bt_req();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED EnableBtReq

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : StartBTRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_StartBTRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_start_bt_rslt_ntf());
    StartBTRsltNtf * p_msg_body = _msg.get_msg_start_bt_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED StartBTRsltNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : DisableBtReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_DisableBtReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_disable_bt_req());
    DisableBtReq * p_msg_body = _msg.get_msg_disable_bt_req();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED DisableBtReq
    //> PhoneAgent_api_CancelBTCtrlTimer()
    PhoneAgent_api_CancelBTCtrlTimer();
    //> PhoneAgent_api_StopBTModule()
    PhoneAgent_api_StopBTModule();
    //> PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_DISABLE_BT_REQ)
    PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_DISABLE_BT_REQ);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : StopBTRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_StopBTRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_stop_bt_rslt_ntf());
    StopBTRsltNtf * p_msg_body = _msg.get_msg_stop_bt_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED StopBTRsltNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : RKLearingRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_RKLearingRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_rk_learing_rsp());
    RKLearingRsp * p_msg_body = _msg.get_msg_rk_learing_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED RKLearingRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : SetChargePlanRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_SetChargePlanRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_set_charge_plan_rsp());
    SetChargePlanRsp * p_msg_body = _msg.get_msg_set_charge_plan_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED SetChargePlanRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : SetPreferenceRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_SetPreferenceRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_set_preference_rsp());
    SetPreferenceRsp * p_msg_body = _msg.get_msg_set_preference_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED SetPreferenceRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : StartSrvReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_StartSrvReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_start_srv_req());
    StartSrvReq * p_msg_body = _msg.get_msg_start_srv_req();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED StartSrvReq

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : StopSrvReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_StopSrvReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_stop_srv_req());
    StopSrvReq * p_msg_body = _msg.get_msg_stop_srv_req();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED StopSrvReq
    //> PhoneAgent_api_CancelBTCtrlTimer()
    PhoneAgent_api_CancelBTCtrlTimer();
    //> PhoneAgent_api_StopBTModule()
    PhoneAgent_api_StopBTModule();
    //> PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_STOP_SRV_REQ)
    PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_STOP_SRV_REQ);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : SeatCtrlRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_SeatCtrlRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_seat_ctrl_rsp());
    SeatCtrlRsp * p_msg_body = _msg.get_msg_seat_ctrl_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED SeatCtrlRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : DISCONNECTED
 *        event  : UpdateRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_UpdateRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_update_rslt_ntf());
    UpdateRsltNtf * p_msg_body = _msg.get_msg_update_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of DISCONNECTED UpdateRsltNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : CancelChargePlanRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_CancelChargePlanRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_cancel_charge_plan_rsp());
    CancelChargePlanRsp * p_msg_body = _msg.get_msg_cancel_charge_plan_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of INIT CancelChargePlanRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : ConfigDriveModeRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_ConfigDriveModeRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_config_drive_mode_rsp());
    ConfigDriveModeRsp * p_msg_body = _msg.get_msg_config_drive_mode_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of INIT ConfigDriveModeRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : BTConnectedNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_BTConnectedNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_bt_connected_ntf());
    BTConnectedNtf * p_msg_body = _msg.get_msg_bt_connected_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of INIT BTConnectedNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : BTDisconnectedNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_BTDisconnectedNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_bt_disconnected_ntf());
    BTDisconnectedNtf * p_msg_body = _msg.get_msg_bt_disconnected_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of INIT BTDisconnectedNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : EngineStsNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_EngineStsNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_engine_sts_ntf());
    EngineStsNtf * p_msg_body = _msg.get_msg_engine_sts_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of INIT EngineStsNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : RcvSppDataNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_RcvSppDataNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_rcv_spp_data_ntf());
    RcvSppDataNtf * p_msg_body = _msg.get_msg_rcv_spp_data_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of INIT RcvSppDataNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : VehicleLockCtrlRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_VehicleLockCtrlRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_vehicle_lock_ctrl_rsp());
    VehicleLockCtrlRsp * p_msg_body = _msg.get_msg_vehicle_lock_ctrl_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of INIT VehicleLockCtrlRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : MainStandCtrlRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_MainStandCtrlRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_main_stand_ctrl_rsp());
    MainStandCtrlRsp * p_msg_body = _msg.get_msg_main_stand_ctrl_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of INIT MainStandCtrlRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : LockStsChgNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_LockStsChgNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_lock_sts_chg_ntf());
    LockStsChgNtf * p_msg_body = _msg.get_msg_lock_sts_chg_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of INIT LockStsChgNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : OperationA2dpRst
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_OperationA2dpRst(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_operation_a2dp_rst());
    OperationA2dpRst * p_msg_body = _msg.get_msg_operation_a2dp_rst();
    assert(p_msg_body != nullptr);

    //> implementation of INIT OperationA2dpRst

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : MusicCtrlCmdReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_MusicCtrlCmdReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_music_ctrl_cmd_req());
    MusicCtrlCmdReq * p_msg_body = _msg.get_msg_music_ctrl_cmd_req();
    assert(p_msg_body != nullptr);

    //> implementation of INIT MusicCtrlCmdReq

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : SendDataRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_SendDataRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_send_data_rslt_ntf());
    SendDataRsltNtf * p_msg_body = _msg.get_msg_send_data_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of INIT SendDataRsltNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : EnableBtReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_EnableBtReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_enable_bt_req());
    EnableBtReq * p_msg_body = _msg.get_msg_enable_bt_req();
    assert(p_msg_body != nullptr);

    //> implementation of INIT EnableBtReq
    //> PhoneAgent_api_CancelBTCtrlTimer()
    PhoneAgent_api_CancelBTCtrlTimer();
    //> PhoneAgent_api_OSM_TaskDelay(3000)
    PhoneAgent_api_OSM_TaskDelay(3000);
    //> PhoneAgent_api_StartBTModule()
    PhoneAgent_api_StartBTModule();
    //> PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_ENABLE_BT_REQ)
    PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_ENABLE_BT_REQ);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : StartBTRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_StartBTRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_start_bt_rslt_ntf());
    StartBTRsltNtf * p_msg_body = _msg.get_msg_start_bt_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of INIT StartBTRsltNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : DisableBtReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_DisableBtReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_disable_bt_req());
    DisableBtReq * p_msg_body = _msg.get_msg_disable_bt_req();
    assert(p_msg_body != nullptr);

    //> implementation of INIT DisableBtReq

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : StopBTRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_StopBTRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_stop_bt_rslt_ntf());
    StopBTRsltNtf * p_msg_body = _msg.get_msg_stop_bt_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of INIT StopBTRsltNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : RKLearingRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_RKLearingRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_rk_learing_rsp());
    RKLearingRsp * p_msg_body = _msg.get_msg_rk_learing_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of INIT RKLearingRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : SetChargePlanRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_SetChargePlanRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_set_charge_plan_rsp());
    SetChargePlanRsp * p_msg_body = _msg.get_msg_set_charge_plan_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of INIT SetChargePlanRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : SetPreferenceRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_SetPreferenceRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_set_preference_rsp());
    SetPreferenceRsp * p_msg_body = _msg.get_msg_set_preference_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of INIT SetPreferenceRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : StartSrvReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_StartSrvReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_start_srv_req());
    StartSrvReq * p_msg_body = _msg.get_msg_start_srv_req();
    assert(p_msg_body != nullptr);

    //> implementation of INIT StartSrvReq
    //> PhoneAgent_api_GetBTPowerSts()
    PhoneAgent_api_GetBTPowerSts();
    //> alt: ?????
    //> opt: TRUE!=BT_power
    if (TRUE!=BT_power) {
        //> PhoneAgent_api_TxStartSrvRsltToSysCtrl(PHONE_RESULT_FAILED)
        PhoneAgent_api_TxStartSrvRsltToSysCtrl(PHONE_RESULT_FAILED);
    }
    //> :end
    //> alt: ?????
    //> opt: TRUE==BT_power
    if (TRUE==BT_power) {
        //> PhoneAgent_api_OSM_TaskDelay(3000)
        PhoneAgent_api_OSM_TaskDelay(3000);
        //> PhoneAgent_api_StartBTModule()
        PhoneAgent_api_StartBTModule();
        //> PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_START_SRV_REQ)
        PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_START_SRV_REQ);
        //> PhoneAgent_SetStatus(ST_STARTING)
        PhoneAgent_SetStatus(ST_STARTING);
    }
    //> :end

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : StopSrvReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_StopSrvReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_stop_srv_req());
    StopSrvReq * p_msg_body = _msg.get_msg_stop_srv_req();
    assert(p_msg_body != nullptr);

    //> implementation of INIT StopSrvReq

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : SeatCtrlRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_SeatCtrlRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_seat_ctrl_rsp());
    SeatCtrlRsp * p_msg_body = _msg.get_msg_seat_ctrl_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of INIT SeatCtrlRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : INIT
 *        event  : UpdateRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_INIT_UpdateRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_update_rslt_ntf());
    UpdateRsltNtf * p_msg_body = _msg.get_msg_update_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of INIT UpdateRsltNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : CancelChargePlanRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_CancelChargePlanRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_cancel_charge_plan_rsp());
    CancelChargePlanRsp * p_msg_body = _msg.get_msg_cancel_charge_plan_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING CancelChargePlanRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : ConfigDriveModeRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_ConfigDriveModeRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_config_drive_mode_rsp());
    ConfigDriveModeRsp * p_msg_body = _msg.get_msg_config_drive_mode_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING ConfigDriveModeRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : BTConnectedNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_BTConnectedNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_bt_connected_ntf());
    BTConnectedNtf * p_msg_body = _msg.get_msg_bt_connected_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING BTConnectedNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : BTDisconnectedNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_BTDisconnectedNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_bt_disconnected_ntf());
    BTDisconnectedNtf * p_msg_body = _msg.get_msg_bt_disconnected_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING BTDisconnectedNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : EngineStsNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_EngineStsNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_engine_sts_ntf());
    EngineStsNtf * p_msg_body = _msg.get_msg_engine_sts_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING EngineStsNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : RcvSppDataNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_RcvSppDataNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_rcv_spp_data_ntf());
    RcvSppDataNtf * p_msg_body = _msg.get_msg_rcv_spp_data_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING RcvSppDataNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : VehicleLockCtrlRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_VehicleLockCtrlRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_vehicle_lock_ctrl_rsp());
    VehicleLockCtrlRsp * p_msg_body = _msg.get_msg_vehicle_lock_ctrl_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING VehicleLockCtrlRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : MainStandCtrlRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_MainStandCtrlRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_main_stand_ctrl_rsp());
    MainStandCtrlRsp * p_msg_body = _msg.get_msg_main_stand_ctrl_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING MainStandCtrlRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : LockStsChgNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_LockStsChgNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_lock_sts_chg_ntf());
    LockStsChgNtf * p_msg_body = _msg.get_msg_lock_sts_chg_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING LockStsChgNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : OperationA2dpRst
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_OperationA2dpRst(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_operation_a2dp_rst());
    OperationA2dpRst * p_msg_body = _msg.get_msg_operation_a2dp_rst();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING OperationA2dpRst

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : MusicCtrlCmdReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_MusicCtrlCmdReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_music_ctrl_cmd_req());
    MusicCtrlCmdReq * p_msg_body = _msg.get_msg_music_ctrl_cmd_req();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING MusicCtrlCmdReq

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : SendDataRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_SendDataRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_send_data_rslt_ntf());
    SendDataRsltNtf * p_msg_body = _msg.get_msg_send_data_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING SendDataRsltNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : EnableBtReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_EnableBtReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_enable_bt_req());
    EnableBtReq * p_msg_body = _msg.get_msg_enable_bt_req();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING EnableBtReq
    //> PhoneAgent_api_CancelBTCtrlTimer()
    PhoneAgent_api_CancelBTCtrlTimer();
    //> PhoneAgent_api_OSM_TaskDelay(3000)
    PhoneAgent_api_OSM_TaskDelay(3000);
    //> PhoneAgent_api_StartBTModule()
    PhoneAgent_api_StartBTModule();
    //> PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_ENABLE_BT_REQ)
    PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_ENABLE_BT_REQ);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : StartBTRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_StartBTRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_start_bt_rslt_ntf());
    StartBTRsltNtf * p_msg_body = _msg.get_msg_start_bt_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING StartBTRsltNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : DisableBtReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_DisableBtReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_disable_bt_req());
    DisableBtReq * p_msg_body = _msg.get_msg_disable_bt_req();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING DisableBtReq

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : StopBTRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_StopBTRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_stop_bt_rslt_ntf());
    StopBTRsltNtf * p_msg_body = _msg.get_msg_stop_bt_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING StopBTRsltNtf
    //> PhoneAgent_api_CancelBTCtrlTimer()
    PhoneAgent_api_CancelBTCtrlTimer();
    //> PhoneAgent_api_Reset()
    PhoneAgent_api_Reset();
    //> PhoneAgent_api_TxDisableBTRsltToSysCtrl(PHONE_RESULT_OK)
    PhoneAgent_api_TxDisableBTRsltToSysCtrl(PHONE_RESULT_OK);
    //> PhoneAgent_SetStatus(ST_INIT)
    PhoneAgent_SetStatus(ST_INIT);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : RKLearingRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_RKLearingRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_rk_learing_rsp());
    RKLearingRsp * p_msg_body = _msg.get_msg_rk_learing_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING RKLearingRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : SetChargePlanRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_SetChargePlanRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_set_charge_plan_rsp());
    SetChargePlanRsp * p_msg_body = _msg.get_msg_set_charge_plan_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING SetChargePlanRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : SetPreferenceRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_SetPreferenceRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_set_preference_rsp());
    SetPreferenceRsp * p_msg_body = _msg.get_msg_set_preference_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING SetPreferenceRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : StartSrvReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_StartSrvReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_start_srv_req());
    StartSrvReq * p_msg_body = _msg.get_msg_start_srv_req();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING StartSrvReq

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : StopSrvReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_StopSrvReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_stop_srv_req());
    StopSrvReq * p_msg_body = _msg.get_msg_stop_srv_req();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING StopSrvReq

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : SeatCtrlRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_SeatCtrlRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_seat_ctrl_rsp());
    SeatCtrlRsp * p_msg_body = _msg.get_msg_seat_ctrl_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING SeatCtrlRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STOPPING
 *        event  : UpdateRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STOPPING_UpdateRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_update_rslt_ntf());
    UpdateRsltNtf * p_msg_body = _msg.get_msg_update_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STOPPING UpdateRsltNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : CancelChargePlanRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_CancelChargePlanRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_cancel_charge_plan_rsp());
    CancelChargePlanRsp * p_msg_body = _msg.get_msg_cancel_charge_plan_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING CancelChargePlanRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : ConfigDriveModeRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_ConfigDriveModeRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_config_drive_mode_rsp());
    ConfigDriveModeRsp * p_msg_body = _msg.get_msg_config_drive_mode_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING ConfigDriveModeRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : BTConnectedNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_BTConnectedNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_bt_connected_ntf());
    BTConnectedNtf * p_msg_body = _msg.get_msg_bt_connected_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING BTConnectedNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : BTDisconnectedNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_BTDisconnectedNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_bt_disconnected_ntf());
    BTDisconnectedNtf * p_msg_body = _msg.get_msg_bt_disconnected_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING BTDisconnectedNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : EngineStsNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_EngineStsNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_engine_sts_ntf());
    EngineStsNtf * p_msg_body = _msg.get_msg_engine_sts_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING EngineStsNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : RcvSppDataNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_RcvSppDataNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_rcv_spp_data_ntf());
    RcvSppDataNtf * p_msg_body = _msg.get_msg_rcv_spp_data_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING RcvSppDataNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : VehicleLockCtrlRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_VehicleLockCtrlRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_vehicle_lock_ctrl_rsp());
    VehicleLockCtrlRsp * p_msg_body = _msg.get_msg_vehicle_lock_ctrl_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING VehicleLockCtrlRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : MainStandCtrlRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_MainStandCtrlRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_main_stand_ctrl_rsp());
    MainStandCtrlRsp * p_msg_body = _msg.get_msg_main_stand_ctrl_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING MainStandCtrlRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : LockStsChgNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_LockStsChgNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_lock_sts_chg_ntf());
    LockStsChgNtf * p_msg_body = _msg.get_msg_lock_sts_chg_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING LockStsChgNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : OperationA2dpRst
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_OperationA2dpRst(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_operation_a2dp_rst());
    OperationA2dpRst * p_msg_body = _msg.get_msg_operation_a2dp_rst();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING OperationA2dpRst

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : MusicCtrlCmdReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_MusicCtrlCmdReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_music_ctrl_cmd_req());
    MusicCtrlCmdReq * p_msg_body = _msg.get_msg_music_ctrl_cmd_req();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING MusicCtrlCmdReq

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : SendDataRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_SendDataRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_send_data_rslt_ntf());
    SendDataRsltNtf * p_msg_body = _msg.get_msg_send_data_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING SendDataRsltNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : EnableBtReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_EnableBtReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_enable_bt_req());
    EnableBtReq * p_msg_body = _msg.get_msg_enable_bt_req();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING EnableBtReq

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : StartBTRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_StartBTRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_start_bt_rslt_ntf());
    StartBTRsltNtf * p_msg_body = _msg.get_msg_start_bt_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING StartBTRsltNtf
    //> PhoneAgent_api_CancelBTCtrlTimer()
    PhoneAgent_api_CancelBTCtrlTimer();
    //> alt: ?????
    //> opt: BTCTRL_RESULT_OK==rslt
    if (BTCTRL_RESULT_OK==rslt) {
        //> PhoneAgent_api_TxEnableBTRsltToSysCtrl(PHONE_RESULT_OK)
        PhoneAgent_api_TxEnableBTRsltToSysCtrl(PHONE_RESULT_OK);
        //> PhoneAgent_SetStatus(ST_DISCONNECTED)
        PhoneAgent_SetStatus(ST_DISCONNECTED);
    }
    //> opt: 
    else {
        //> PhoneAgent_api_OSM_TaskDelay(3000)
        PhoneAgent_api_OSM_TaskDelay(3000);
        //> PhoneAgent_api_StartBTModule()
        PhoneAgent_api_StartBTModule();
        //> PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_ENABLE_BT_REQ)
        PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_ENABLE_BT_REQ);
        //> PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_ENABLE_BT_RSLT)
        PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_ENABLE_BT_RSLT);
    }
    //> :end

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : DisableBtReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_DisableBtReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_disable_bt_req());
    DisableBtReq * p_msg_body = _msg.get_msg_disable_bt_req();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING DisableBtReq
    //> PhoneAgent_api_CancelBTCtrlTimer()
    PhoneAgent_api_CancelBTCtrlTimer();
    //> PhoneAgent_api_StopBTModule()
    PhoneAgent_api_StopBTModule();
    //> PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_DISABLE_BT_REQ)
    PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_DISABLE_BT_REQ);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : StopBTRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_StopBTRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_stop_bt_rslt_ntf());
    StopBTRsltNtf * p_msg_body = _msg.get_msg_stop_bt_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING StopBTRsltNtf

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : RKLearingRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_RKLearingRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_rk_learing_rsp());
    RKLearingRsp * p_msg_body = _msg.get_msg_rk_learing_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING RKLearingRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : SetChargePlanRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_SetChargePlanRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_set_charge_plan_rsp());
    SetChargePlanRsp * p_msg_body = _msg.get_msg_set_charge_plan_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING SetChargePlanRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : SetPreferenceRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_SetPreferenceRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_set_preference_rsp());
    SetPreferenceRsp * p_msg_body = _msg.get_msg_set_preference_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING SetPreferenceRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : StartSrvReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_StartSrvReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_start_srv_req());
    StartSrvReq * p_msg_body = _msg.get_msg_start_srv_req();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING StartSrvReq

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : StopSrvReq
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_StopSrvReq(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_stop_srv_req());
    StopSrvReq * p_msg_body = _msg.get_msg_stop_srv_req();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING StopSrvReq
    //> PhoneAgent_api_CancelBTCtrlTimer()
    PhoneAgent_api_CancelBTCtrlTimer();
    //> PhoneAgent_api_StopBTModule()
    PhoneAgent_api_StopBTModule();
    //> PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_STOP_SRV_REQ)
    PhoneAgent_api_SetBTCtrlTimer(PHONE_AGENT_EVT_STOP_SRV_REQ);

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : SeatCtrlRsp
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_SeatCtrlRsp(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_seat_ctrl_rsp());
    SeatCtrlRsp * p_msg_body = _msg.get_msg_seat_ctrl_rsp();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING SeatCtrlRsp

    return STM_STATS_OK;
}

/* @brief Event callback of PhoneAgent Module
 *        status : STARTING
 *        event  : UpdateRsltNtf
 *        reference sequence id list:
 *               xxxx
 *               yyyy
 * 
 * @param _msg : PhoneAgentEvent
 * @return STM_Status
 */
STM_Status PhoneAgent_ECB_STARTING_UpdateRsltNtf(PhoneAgentEvent const & _msg) {
    assert(_msg.has_msg_update_rslt_ntf());
    UpdateRsltNtf * p_msg_body = _msg.get_msg_update_rslt_ntf();
    assert(p_msg_body != nullptr);

    //> implementation of STARTING UpdateRsltNtf

    return STM_STATS_OK;
}


void PhoneAgent_SetStatus(PhoneAgent_State state){
    PhoneAgent_State = state;
}

PhoneAgent_State PhoneAgent_GetStatus(){
    return PhoneAgent_State;
}