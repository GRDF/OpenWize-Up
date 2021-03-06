/**
  * @file: adf7030-1__irq.h
  * @brief:  ...
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
  * 1.0.0 : 2020/05/18[TODO: your name]
  * Initial version
  *
  *
  */

#ifndef _ADF7030_1__IRQ_H_
#define _ADF7030_1__IRQ_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

#include "adf7030-1__common.h"

/* Enumeration of events generated by AF7030_1.
 *
 */

/* Structure describing radio PHY interrupt source
 * 
 */
typedef enum {
    /* ---------------------  ADF7030 Soft External Interrupt Numbers  --------------------- */
    PREAMBLE_IRQn            =   0UL,              /*!<   0  Preamble detected (RX) / Start preamble (TX)                     */
    PREAMBLE_GONE_IRQn       =   1UL,              /*!<   1  Preamble gone (RX) / End of preamble (TX)                        */
    SYNCWORD_IRQn            =   2UL,              /*!<   2  Syncword detected (RX) / End of Syncword (TX)                    */
    LENGTH_IRQn              =   3UL,              /*!<   3  Valid Length received (RX) / End of Length word (TX)             */
    PAYLOAD_IRQn             =   4UL,              /*!<   4  Full payload received (RX) / Full payload transmitted (TX)       */
    PAYLOAD_BLOC_IRQn        =   5UL,              /*!<   5  TRX bloc received (RX) / TRX bloc transmitted (TX)               */
    CRC_CHK_IRQn             =   6UL,              /*!<   6  Frame CRC correct (RX) / Frame CRC transmitted (TX)              */
    EOF_IRQn                 =   7UL,              /*!<   7  End of Frame (RX) / End od Frame (TX)                            */

    BUFF_HALF_IRQn           =   8UL,              /*!<   8  Rolling Buffer Half Full                                         */
    BUFF_FULL_IRQn           =   9UL,              /*!<   9  Rolling Buffer Full                                              */
    SM_READY_IRQn            =  10UL,              /*!<  10  State Machine ready for new command                              */
    SM_IDLE_IRQn             =  11UL,              /*!<  11  State Machine in idle                                            */
    SM_BODY_IRQn             =  12UL,              /*!<  12  State Machine in state body function                             */
    SM_SCRIPT_IRQn           =  13UL,              /*!<  13  State Machine end of script                                      */
    SM_ERROR_IRQn            =  13UL,              /*!<  13  State Machine error                                              */
    SNOOP_IRQn               =  14UL,              /*!<  14  MCR Snoop IRQ                                                    */
    HARDFAULT_IRQn           =  15UL,              /*!<  15  Critical firmware error                                          */

    /* ---------------------  ADF7030 Hard External Interrupt Numbers  --------------------- */
    SPI_HOST_EXT_IRQn       =  16UL,                    /*!<  16  */
    TMR0_EXT_IRQn           =  17UL,                    /*!<  17  */
    TMR1_EXT_IRQn           =  18UL,                    /*!<  18  */
    TMR2_EXT_IRQn           =  19UL,                    /*!<  19  */
    TMR3_EXT_IRQn           =  20UL,                    /*!<  20  */
    UNUSED0_IRQn            =  21UL,                    /*!<  21  */
    RTC_EXT_IRQn            =  22UL,                    /*!<  22  */
    WDT_EXT_IRQn            =  23UL,                    /*!<  23  */

    SERDES_EXT_IRQn         =  24UL,                    /*!<  24  */
    SERDES_MONITOR_EXT_IRQn =  25UL,                    /*!<  25  */
    MCR_SNOOP_EXT_IRQn      =  26UL,                    /*!<  26  */
    CAL_READY_EXT_IRQn      =  27UL,                    /*!<  27  */
    AGC_EXT_IRQn            =  28UL,                    /*!<  28  */
    UNUSED1_IRQn            =  29UL,                    /*!<  29  */
    UNUSED2_IRQn            =  30UL,                    /*!<  30  */
    UNUSED3_IRQn            =  31UL                       /*!<  31  */
} adf7030_1_ext_irq_e;

/* Structure describing radio PHY interrupt mask
 * 
 */
typedef enum {
    /* ---------------------  ADF7030 Soft External Interrupt Mask  --------------------- */
    PREAMBLE_IRQn_Msk             = (1UL << PREAMBLE_IRQn),
    PREAMBLE_GONE_IRQn_Msk        = (1UL << PREAMBLE_GONE_IRQn),
    SYNCWORD_IRQn_Msk             = (1UL << SYNCWORD_IRQn),
    LENGTH_IRQn_Msk               = (1UL << LENGTH_IRQn),
    PAYLOAD_IRQn_Msk              = (1UL << PAYLOAD_IRQn),
    PAYLOAD_BLOC_IRQn_Msk         = (1UL << PAYLOAD_BLOC_IRQn),
    CRC_CHK_IRQn_Msk              = (1UL << CRC_CHK_IRQn),
    EOF_IRQn_Msk                  = (1UL << EOF_IRQn),

    BUFF_HALF_IRQn_Msk            = (1UL << BUFF_HALF_IRQn),
    BUFF_FULL_IRQn_Msk            = (1UL << BUFF_FULL_IRQn),
    SM_READY_IRQn_Msk             = (1UL << SM_READY_IRQn),
    SM_IDLE_IRQn_Msk              = (1UL << SM_IDLE_IRQn),
    SM_BODY_IRQn_Msk              = (1UL << SM_BODY_IRQn),
    SM_SCRIPT_IRQn_Msk            = (1UL << SM_SCRIPT_IRQn),
    SM_ERROR_IRQn_Msk             = (1UL << SM_ERROR_IRQn),
    SNOOP_IRQn_Msk                = (1UL << SNOOP_IRQn),
	HARDFAULT_IRQn_Msk            = (1UL << HARDFAULT_IRQn),
    /* ---------------------  ADF7030 Hard External Interrupt Numbers  --------------------- */
    SPI_HOST_EXT_IRQn_Msk       = (1UL << SPI_HOST_EXT_IRQn),
    TMR0_EXT_IRQn_Msk           = (1UL << TMR0_EXT_IRQn),
    TMR1_EXT_IRQn_Msk           = (1UL << TMR1_EXT_IRQn),
    TMR2_EXT_IRQn_Msk           = (1UL << TMR2_EXT_IRQn),
    TMR3_EXT_IRQn_Msk           = (1UL << TMR3_EXT_IRQn),
    UNUSED0_IRQn_Msk            = (1UL << UNUSED0_IRQn),
    RTC_EXT_IRQn_Msk            = (1UL << RTC_EXT_IRQn),

	WDT_EXT_IRQn_Msk            = (1UL << WDT_EXT_IRQn),
    SERDES_EXT_IRQn_Msk         = (1UL << SERDES_EXT_IRQn),
    SERDES_MONITOR_EXT_IRQn_Msk = (1UL << SERDES_MONITOR_EXT_IRQn),
    MCR_SNOOP_EXT_IRQn_Msk      = (1UL << MCR_SNOOP_EXT_IRQn),
    CAL_READY_EXT_IRQn_Msk      = (1UL << CAL_READY_EXT_IRQn),
    AGC_EXT_IRQn_Msk            = (1UL << AGC_EXT_IRQn),
    UNUSED1_IRQn_Msk            = (1UL << UNUSED1_IRQn),
    UNUSED2_IRQn_Msk            = (1UL << UNUSED2_IRQn),

	UNUSED3_IRQn_Msk            = (1UL << UNUSED3_IRQn)
} adf7030_1_irq_msk_e;


uint8_t adf7030_1__IRQ_SetGPIOPin(
	adf7030_1_device_t* const pDevice,
    adf7030_1_intpin_e eIntPin
);

uint8_t adf7030_1__IRQ_SetMap(
	adf7030_1_device_t* const pDevice,
    adf7030_1_intpin_e eIntPin,
    uint32_t           nIntMap
);

uint8_t adf7030_1__IRQ_GetMap(
	adf7030_1_device_t* const pDevice,
    adf7030_1_intpin_e eIntPin
);

uint8_t adf7030_1__IRQ_GetStatus(
	adf7030_1_device_t* const pDevice,
    adf7030_1_intpin_e eIntPin
);

uint8_t adf7030_1__IRQ_ClrStatus(
	adf7030_1_device_t* const pDevice,
    adf7030_1_intpin_e eIntPin,
    uint32_t           nIntSource
);

#define adf7030_1__IRQ_ClrAllStatus(pDevice, eIntPin) adf7030_1__IRQ_ClrStatus( pDevice, eIntPin, 0xFFFFFFFF )

uint8_t adf7030_1__IRQ_GetClrStatus(
	adf7030_1_device_t* const pDevice,
    adf7030_1_intpin_e eIntPin
);

#ifdef __cplusplus
}
#endif

#endif /* _ADF7030_1__IRQ_H_ */

