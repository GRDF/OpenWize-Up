/*!
  * @file: platform.h
  * @brief: This file defines some specific platform constants..
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
  * 1.0.0 : 2019/12/15[GBI]
  * Initial version
  *
  *
  */
#ifndef _PLATFORME_H_
#define _PLATFORME_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "pin_cfg.h"

typedef enum
{
	SPI_ID_MAIN,
	//
	SPI_ID_MAX
} spi_id_e;

typedef enum
{
	I2C_ID_INT,
	I2C_ID_EXT,
	//
	I2C_ID_MAX
} i2c_id_e;

typedef enum
{
	UART_ID_CONSOLE,
	//
	UART_ID_MAX
} uart_id_e;

#define EEPROM_ADDRESS 0b10100000 // 0xA0

#define STDOUT_UART_ID UART_ID_CONSOLE

#define RTC_PREDIV_S 1023
#define RTC_PREDIV_A 31

#ifdef __cplusplus
}
#endif
#endif /* _Port_PLATFORME_H_ */
