
#include "PhoneAgent_EventDef.h"

// State definition
enum PhoneAgent_State { 
    ST_CONNECTED,
    ST_DISCONNECTED,
    ST_INIT,
    ST_STOPPING,
    ST_STARTING,
    ST_STATE_MAX
};

// Event definition
enum PhoneAgent_Event { 
    EV_BTConnectedNtf,
    EV_BTDisconnectedNtf,
    EV_CancelChargePlanRsp,
    EV_ConfigDriveModeRsp,
    EV_DisableBtReq,
    EV_EnableBtReq,
    EV_EngineStsNtf,
    EV_LockStsChgNtf,
    EV_MainStandCtrlRsp,
    EV_MusicCtrlCmdReq,
    EV_OperationA2dpRst,
    EV_RKLearingRsp,
    EV_RcvSppDataNtf,
    EV_SeatCtrlRsp,
    EV_SendDataRsltNtf,
    EV_SetChargePlanRsp,
    EV_SetPreferenceRsp,
    EV_StartBTRsltNtf,
    EV_StartSrvReq,
    EV_StopBTRsltNtf,
    EV_StopSrvReq,
    EV_UpdateRsltNtf,
    EV_VehicleLockCtrlRsp,
    EV_EVENT_MAX
};

void PhoneAgent_SetStatus(PhoneAgent_State state);

PhoneAgent_State PhoneAgent_GetStatus();


/* Event callback of PhoneAgent Module,
 * All state response for State :CONNECTED 
 */
STM_Status PhoneAgent_ECB_CONNECTED_CancelChargePlanRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_ConfigDriveModeRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_BTConnectedNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_BTDisconnectedNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_EngineStsNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_RcvSppDataNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_VehicleLockCtrlRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_MainStandCtrlRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_LockStsChgNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_OperationA2dpRst(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_MusicCtrlCmdReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_SendDataRsltNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_EnableBtReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_StartBTRsltNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_DisableBtReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_StopBTRsltNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_RKLearingRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_SetChargePlanRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_SetPreferenceRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_StartSrvReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_StopSrvReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_SeatCtrlRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_CONNECTED_UpdateRsltNtf(PhoneAgentEvent const & _msg);

/* Event callback of PhoneAgent Module,
 * All state response for State :DISCONNECTED 
 */
STM_Status PhoneAgent_ECB_DISCONNECTED_CancelChargePlanRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_ConfigDriveModeRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_BTConnectedNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_BTDisconnectedNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_EngineStsNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_RcvSppDataNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_VehicleLockCtrlRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_MainStandCtrlRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_LockStsChgNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_OperationA2dpRst(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_MusicCtrlCmdReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_SendDataRsltNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_EnableBtReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_StartBTRsltNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_DisableBtReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_StopBTRsltNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_RKLearingRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_SetChargePlanRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_SetPreferenceRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_StartSrvReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_StopSrvReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_SeatCtrlRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_DISCONNECTED_UpdateRsltNtf(PhoneAgentEvent const & _msg);

/* Event callback of PhoneAgent Module,
 * All state response for State :INIT 
 */
STM_Status PhoneAgent_ECB_INIT_CancelChargePlanRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_ConfigDriveModeRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_BTConnectedNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_BTDisconnectedNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_EngineStsNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_RcvSppDataNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_VehicleLockCtrlRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_MainStandCtrlRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_LockStsChgNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_OperationA2dpRst(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_MusicCtrlCmdReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_SendDataRsltNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_EnableBtReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_StartBTRsltNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_DisableBtReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_StopBTRsltNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_RKLearingRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_SetChargePlanRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_SetPreferenceRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_StartSrvReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_StopSrvReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_SeatCtrlRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_INIT_UpdateRsltNtf(PhoneAgentEvent const & _msg);

/* Event callback of PhoneAgent Module,
 * All state response for State :STOPPING 
 */
STM_Status PhoneAgent_ECB_STOPPING_CancelChargePlanRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_ConfigDriveModeRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_BTConnectedNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_BTDisconnectedNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_EngineStsNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_RcvSppDataNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_VehicleLockCtrlRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_MainStandCtrlRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_LockStsChgNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_OperationA2dpRst(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_MusicCtrlCmdReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_SendDataRsltNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_EnableBtReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_StartBTRsltNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_DisableBtReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_StopBTRsltNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_RKLearingRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_SetChargePlanRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_SetPreferenceRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_StartSrvReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_StopSrvReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_SeatCtrlRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STOPPING_UpdateRsltNtf(PhoneAgentEvent const & _msg);

/* Event callback of PhoneAgent Module,
 * All state response for State :STARTING 
 */
STM_Status PhoneAgent_ECB_STARTING_CancelChargePlanRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_ConfigDriveModeRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_BTConnectedNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_BTDisconnectedNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_EngineStsNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_RcvSppDataNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_VehicleLockCtrlRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_MainStandCtrlRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_LockStsChgNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_OperationA2dpRst(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_MusicCtrlCmdReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_SendDataRsltNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_EnableBtReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_StartBTRsltNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_DisableBtReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_StopBTRsltNtf(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_RKLearingRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_SetChargePlanRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_SetPreferenceRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_StartSrvReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_StopSrvReq(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_SeatCtrlRsp(PhoneAgentEvent const & _msg);
STM_Status PhoneAgent_ECB_STARTING_UpdateRsltNtf(PhoneAgentEvent const & _msg);


// State-Event Callback Matrix
typedef STM_Status (FP_PhoneAgent_ECB)(PhoneAgentEvent & _msg); 
FP_PhoneAgent_ECB const PhoneAgent_state_ecb_map[][] = { 
	{ 
		PhoneAgent_ECB_CONNECTED_CancelChargePlanRsp, 
		PhoneAgent_ECB_CONNECTED_ConfigDriveModeRsp, 
		PhoneAgent_ECB_CONNECTED_BTConnectedNtf, 
		PhoneAgent_ECB_CONNECTED_BTDisconnectedNtf, 
		PhoneAgent_ECB_CONNECTED_EngineStsNtf, 
		PhoneAgent_ECB_CONNECTED_RcvSppDataNtf, 
		PhoneAgent_ECB_CONNECTED_VehicleLockCtrlRsp, 
		PhoneAgent_ECB_CONNECTED_MainStandCtrlRsp, 
		PhoneAgent_ECB_CONNECTED_LockStsChgNtf, 
		PhoneAgent_ECB_CONNECTED_OperationA2dpRst, 
		PhoneAgent_ECB_CONNECTED_MusicCtrlCmdReq, 
		PhoneAgent_ECB_CONNECTED_SendDataRsltNtf, 
		PhoneAgent_ECB_CONNECTED_EnableBtReq, 
		PhoneAgent_ECB_CONNECTED_StartBTRsltNtf, 
		PhoneAgent_ECB_CONNECTED_DisableBtReq, 
		PhoneAgent_ECB_CONNECTED_StopBTRsltNtf, 
		PhoneAgent_ECB_CONNECTED_RKLearingRsp, 
		PhoneAgent_ECB_CONNECTED_SetChargePlanRsp, 
		PhoneAgent_ECB_CONNECTED_SetPreferenceRsp, 
		PhoneAgent_ECB_CONNECTED_StartSrvReq, 
		PhoneAgent_ECB_CONNECTED_StopSrvReq, 
		PhoneAgent_ECB_CONNECTED_SeatCtrlRsp, 
		PhoneAgent_ECB_CONNECTED_UpdateRsltNtf, 
	}, 
	{ 
		PhoneAgent_ECB_DISCONNECTED_CancelChargePlanRsp, 
		PhoneAgent_ECB_DISCONNECTED_ConfigDriveModeRsp, 
		PhoneAgent_ECB_DISCONNECTED_BTConnectedNtf, 
		PhoneAgent_ECB_DISCONNECTED_BTDisconnectedNtf, 
		PhoneAgent_ECB_DISCONNECTED_EngineStsNtf, 
		PhoneAgent_ECB_DISCONNECTED_RcvSppDataNtf, 
		PhoneAgent_ECB_DISCONNECTED_VehicleLockCtrlRsp, 
		PhoneAgent_ECB_DISCONNECTED_MainStandCtrlRsp, 
		PhoneAgent_ECB_DISCONNECTED_LockStsChgNtf, 
		PhoneAgent_ECB_DISCONNECTED_OperationA2dpRst, 
		PhoneAgent_ECB_DISCONNECTED_MusicCtrlCmdReq, 
		PhoneAgent_ECB_DISCONNECTED_SendDataRsltNtf, 
		PhoneAgent_ECB_DISCONNECTED_EnableBtReq, 
		PhoneAgent_ECB_DISCONNECTED_StartBTRsltNtf, 
		PhoneAgent_ECB_DISCONNECTED_DisableBtReq, 
		PhoneAgent_ECB_DISCONNECTED_StopBTRsltNtf, 
		PhoneAgent_ECB_DISCONNECTED_RKLearingRsp, 
		PhoneAgent_ECB_DISCONNECTED_SetChargePlanRsp, 
		PhoneAgent_ECB_DISCONNECTED_SetPreferenceRsp, 
		PhoneAgent_ECB_DISCONNECTED_StartSrvReq, 
		PhoneAgent_ECB_DISCONNECTED_StopSrvReq, 
		PhoneAgent_ECB_DISCONNECTED_SeatCtrlRsp, 
		PhoneAgent_ECB_DISCONNECTED_UpdateRsltNtf, 
	}, 
	{ 
		PhoneAgent_ECB_INIT_CancelChargePlanRsp, 
		PhoneAgent_ECB_INIT_ConfigDriveModeRsp, 
		PhoneAgent_ECB_INIT_BTConnectedNtf, 
		PhoneAgent_ECB_INIT_BTDisconnectedNtf, 
		PhoneAgent_ECB_INIT_EngineStsNtf, 
		PhoneAgent_ECB_INIT_RcvSppDataNtf, 
		PhoneAgent_ECB_INIT_VehicleLockCtrlRsp, 
		PhoneAgent_ECB_INIT_MainStandCtrlRsp, 
		PhoneAgent_ECB_INIT_LockStsChgNtf, 
		PhoneAgent_ECB_INIT_OperationA2dpRst, 
		PhoneAgent_ECB_INIT_MusicCtrlCmdReq, 
		PhoneAgent_ECB_INIT_SendDataRsltNtf, 
		PhoneAgent_ECB_INIT_EnableBtReq, 
		PhoneAgent_ECB_INIT_StartBTRsltNtf, 
		PhoneAgent_ECB_INIT_DisableBtReq, 
		PhoneAgent_ECB_INIT_StopBTRsltNtf, 
		PhoneAgent_ECB_INIT_RKLearingRsp, 
		PhoneAgent_ECB_INIT_SetChargePlanRsp, 
		PhoneAgent_ECB_INIT_SetPreferenceRsp, 
		PhoneAgent_ECB_INIT_StartSrvReq, 
		PhoneAgent_ECB_INIT_StopSrvReq, 
		PhoneAgent_ECB_INIT_SeatCtrlRsp, 
		PhoneAgent_ECB_INIT_UpdateRsltNtf, 
	}, 
	{ 
		PhoneAgent_ECB_STOPPING_CancelChargePlanRsp, 
		PhoneAgent_ECB_STOPPING_ConfigDriveModeRsp, 
		PhoneAgent_ECB_STOPPING_BTConnectedNtf, 
		PhoneAgent_ECB_STOPPING_BTDisconnectedNtf, 
		PhoneAgent_ECB_STOPPING_EngineStsNtf, 
		PhoneAgent_ECB_STOPPING_RcvSppDataNtf, 
		PhoneAgent_ECB_STOPPING_VehicleLockCtrlRsp, 
		PhoneAgent_ECB_STOPPING_MainStandCtrlRsp, 
		PhoneAgent_ECB_STOPPING_LockStsChgNtf, 
		PhoneAgent_ECB_STOPPING_OperationA2dpRst, 
		PhoneAgent_ECB_STOPPING_MusicCtrlCmdReq, 
		PhoneAgent_ECB_STOPPING_SendDataRsltNtf, 
		PhoneAgent_ECB_STOPPING_EnableBtReq, 
		PhoneAgent_ECB_STOPPING_StartBTRsltNtf, 
		PhoneAgent_ECB_STOPPING_DisableBtReq, 
		PhoneAgent_ECB_STOPPING_StopBTRsltNtf, 
		PhoneAgent_ECB_STOPPING_RKLearingRsp, 
		PhoneAgent_ECB_STOPPING_SetChargePlanRsp, 
		PhoneAgent_ECB_STOPPING_SetPreferenceRsp, 
		PhoneAgent_ECB_STOPPING_StartSrvReq, 
		PhoneAgent_ECB_STOPPING_StopSrvReq, 
		PhoneAgent_ECB_STOPPING_SeatCtrlRsp, 
		PhoneAgent_ECB_STOPPING_UpdateRsltNtf, 
	}, 
	{ 
		PhoneAgent_ECB_STARTING_CancelChargePlanRsp, 
		PhoneAgent_ECB_STARTING_ConfigDriveModeRsp, 
		PhoneAgent_ECB_STARTING_BTConnectedNtf, 
		PhoneAgent_ECB_STARTING_BTDisconnectedNtf, 
		PhoneAgent_ECB_STARTING_EngineStsNtf, 
		PhoneAgent_ECB_STARTING_RcvSppDataNtf, 
		PhoneAgent_ECB_STARTING_VehicleLockCtrlRsp, 
		PhoneAgent_ECB_STARTING_MainStandCtrlRsp, 
		PhoneAgent_ECB_STARTING_LockStsChgNtf, 
		PhoneAgent_ECB_STARTING_OperationA2dpRst, 
		PhoneAgent_ECB_STARTING_MusicCtrlCmdReq, 
		PhoneAgent_ECB_STARTING_SendDataRsltNtf, 
		PhoneAgent_ECB_STARTING_EnableBtReq, 
		PhoneAgent_ECB_STARTING_StartBTRsltNtf, 
		PhoneAgent_ECB_STARTING_DisableBtReq, 
		PhoneAgent_ECB_STARTING_StopBTRsltNtf, 
		PhoneAgent_ECB_STARTING_RKLearingRsp, 
		PhoneAgent_ECB_STARTING_SetChargePlanRsp, 
		PhoneAgent_ECB_STARTING_SetPreferenceRsp, 
		PhoneAgent_ECB_STARTING_StartSrvReq, 
		PhoneAgent_ECB_STARTING_StopSrvReq, 
		PhoneAgent_ECB_STARTING_SeatCtrlRsp, 
		PhoneAgent_ECB_STARTING_UpdateRsltNtf, 
	}, 
}; 


