
#include "PhoneAgent_STM.h"

uint32_t PhoneAgent_Task_Main(void * params) {
    while(1) {
        // Recieve Msg Buffer
		auto buff_size = OSM_GetMessageBuffSize();
		if (buff_size >= 0) {
			char * p_msg_buff = new char[buff_size]
			OSM_GetMessageBuffContent(p_msg_buff);
			// Use GPB to unpack the buffer to msg
			PhoneAgentEvent msg;
			msg.ParseFromString(p_msg_buff);
			PhoneAgent_Event msg_id = msg.GetMessageID();
			PhoneAgent_State stm_state = GetSTMState();
			// todo : add range check
			// dispatch msg to ECBs
			PhoneAgent_state_ecb_map[stm_state][msg_id](msg);
			delete [] p_msg_buff;			
		}
    }
}
