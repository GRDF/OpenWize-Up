/**********************************************************************************************************
  * @file: atci.h
  * @brief: This file contains low level functions (command responses) of the AT command interpreter for WizeUp
  * module
  *
  *****************************************************************************
  * @Copyright 2019, GRDF, Inc.  All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted (subject to the limitations in the disclaimer
  * below) provided that the following conditions are met:
  *    - Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *    - Redistributions in binary form must reproduce the above copyright
  *      notice, this list of conditions and the following disclaimer in the
  *      documentation and/or other materials provided with the distribution.
  *    - Neither the name of GRDF, Inc. nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  *****************************************************************************
  *
  * Revision history
  * ----------------
  * 0.0.1 : 2021/01/11
  * Dev. version
  *
  *
 *********************************************************************************************************/

#ifndef INC_ATCI_RESP_H_
#define INC_ATCI_RESP_H_


/*=========================================================================================================
 * INCLUDES
 *=======================================================================================================*/

#include <stdint.h>
#include <string.h>
#include <stdarg.h>

#include "console.h"
#include "atci.h"

/*=========================================================================================================
 * DEFINES
 *=======================================================================================================*/

/*=========================================================================================================
 * TYPEDEF
 *=======================================================================================================*/

/*=========================================================================================================
 * FUNCTIONS PROTOTYPES - AT responses
 *=======================================================================================================*/

/*!--------------------------------------------------------------------------------------------------------
 * @brief		Send wakeup message
 *
 * @param[in]	None
 * @param[Out]	None
 *
 * @return		None
 *-------------------------------------------------------------------------------------------------------*/
void Atci_Send_Wakeup_Msg(void);

/*!--------------------------------------------------------------------------------------------------------
 * @brief		Send sleep message
 *
 * @param[in]	None
 * @param[Out]	None
 *
 * @return		None
 *-------------------------------------------------------------------------------------------------------*/
void Atci_Send_Sleep_Msg(void);


/*!--------------------------------------------------------------------------------------------------------
 * @brief		Send AT response status (OK or error)
 *
 * @param[in]	errCode: 0 for succeess, else error code
 * @param[Out]	None
 *
 * @return		None
 *-------------------------------------------------------------------------------------------------------*/
void Atci_Resp_Ack(atci_status_t errCode);


/*!--------------------------------------------------------------------------------------------------------
 * @brief		Send AT response data
 *
 * @param[IN]	cmdCodeStr: command code as string
 * @param[IN]	atciCmdData ("atci_cmd_t" structure):
 * 					nbParams: number of parameters in command response
 * 					params: parameters list (with size and data)
 *
 * @return		None
 *-------------------------------------------------------------------------------------------------------*/
void Atci_Resp_Data(char *cmdCodeStr, atci_cmd_t *atciCmdData);


/*=========================================================================================================
 * FUNCTIONS PROTOTYPES - AT debug messages
 *=======================================================================================================*/

// Do not use: see Atci_Debug_Param_Data macro
void _Atci_Debug_Param_Data(char *dbgMsd, atci_cmd_t *atciCmdData);


/*=========================================================================================================
 * MACRO - AT info messages
 *=======================================================================================================*/

/*!--------------------------------------------------------------------------------------------------------
 * @brief		Send debug string
 *
 * @param[IN]	dbgMsd: debug message
 *
 * @return		None
 *-------------------------------------------------------------------------------------------------------*/
#define Atci_Info_Str(infoMsd)						do{Console_Send_Str("\r\n+INF: "); Console_Send_Str(infoMsd); Console_Send_Str("\r\n");}while(0)

/*!--------------------------------------------------------------------------------------------------------
 * @brief		Send debug formated string like a printf
 *
 * @param[IN]	formated string and parameters
 *
 * @return		None
 *-------------------------------------------------------------------------------------------------------*/
#define Atci_Info_Printf(...)						do{Console_Send_Str("\r\n+INF: "); Console_Printf(__VA_ARGS__); Console_Send_Str("\r\n");}while(0)


/*=========================================================================================================
 * MACRO - AT debug messages
 *=======================================================================================================*/

/*!--------------------------------------------------------------------------------------------------------
 * @brief		Send debug data: command/response parameters (with Atci_Resp_Data format)
 *
 * @param[IN]	dbgMsd: debug message
 * @param[IN]	atciCmdData ("atci_cmd_t" structure):
 * 					nbParams: number of parameters in command response
 * 					params: parameters list (with size and data)
 *
 * @return		None
 *-------------------------------------------------------------------------------------------------------*/
#define Atci_Debug_Param_Data(dbgMsd, atciCmdData)	_Atci_Debug_Param_Data(dbgMsd, atciCmdData)
//#define Atci_Debug_Param_Data(dbgMsd, atciCmdData)

/*!--------------------------------------------------------------------------------------------------------
 * @brief		Send debug string
 *
 * @param[IN]	dbgMsd: debug message
 *
 * @return		None
 *-------------------------------------------------------------------------------------------------------*/
#define Atci_Debug_Str(dbgMsd)						do{Console_Send_Str("\r\n+DBG: "); Console_Send_Str(dbgMsd); Console_Send_Str("\r\n");}while(0)
//#define Atci_Debug_Str(dbgMsd)

/*!--------------------------------------------------------------------------------------------------------
 * @brief		Send debug formated string like a printf
 *
 * @param[IN]	formated string and parameters
 *
 * @return		None
 *-------------------------------------------------------------------------------------------------------*/
#define Atci_Debug_Printf(...)						do{Console_Send_Str("\r\n+DBG: "); Console_Printf(__VA_ARGS__); Console_Send_Str("\r\n");}while(0)
//#define Atci_Debug_Printf(...)



#endif /* INC_ATCI_RESP_H_ */
/************************************************** EOF **************************************************/
