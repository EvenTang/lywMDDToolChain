
#include "EVSrv_STM.h"

uint32_t EVSrv_Task_Main(void * params) {
    while(1) {
        // Recieve Msg Buffer
		auto buff_size = OSM_GetMessageBuffSize();
		if (buff_size >= 0) {
			char * p_msg_buff = new char[buff_size]
			OSM_GetMessageBuffContent(p_msg_buff);
			// Use GPB to unpack the buffer to msg
			EVSrvEvent msg;
			msg.ParseFromString(p_msg_buff);
			EVSrv_Event msg_id = msg.GetMessageID();
			EVSrv_State stm_state = GetSTMState();
			// todo : add range check
			// dispatch msg to ECBs
			EVSrv_state_ecb_map[stm_state][msg_id](msg);
			delete [] p_msg_buff;			
		}
    }
}
