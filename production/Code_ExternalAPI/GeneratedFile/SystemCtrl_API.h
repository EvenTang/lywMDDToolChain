
#include "SystemCtrlMessageDef.pb.h"





/* @brief Send message SetTemperature to module : SystemCtrl
 * 
 * @param int32 new_temp : 
 * @param int32 last_temp : 
 *
 * @return none
 */
void SystemCtrl_API_SendMsgSetTemperatureToSystemCtrl(int32 _new_temp, int32 _last_temp);

/* @brief Send message SetTemperatureResult to module : SystemCtrl
 * 
 * @param Result result : 
 *
 * @return none
 */
void SystemCtrl_API_SendMsgSetTemperatureResultToSystemCtrl(Result _result);

/* @brief Send message ShowTemperatureResult to module : SystemCtrl
 * 
 * @param Result result : 
 *
 * @return none
 */
void SystemCtrl_API_SendMsgShowTemperatureResultToSystemCtrl(Result _result);

/* @brief Send message PowerOffResult to module : SystemCtrl
 * 
 * @param Result result : 
 *
 * @return none
 */
void SystemCtrl_API_SendMsgPowerOffResultToSystemCtrl(Result _result);

/* @brief Send message TurnOffDisplayResult to module : SystemCtrl
 * 
 * @param Result result : 
 *
 * @return none
 */
void SystemCtrl_API_SendMsgTurnOffDisplayResultToSystemCtrl(Result _result);

/* @brief Send message PowerOnResult to module : SystemCtrl
 * 
 * @param Result result : 
 *
 * @return none
 */
void SystemCtrl_API_SendMsgPowerOnResultToSystemCtrl(Result _result);


