/**
  * @file: bsp.h
  * @brief: This file defines functions to initialize the BSP.
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
  * 1.0.0 : 2020/04/23[GBI]
  * Initial version
  *
  *
  */
#ifndef _BSP_H_
#define _BSP_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <bsp_boot.h>
#include <bsp_flash.h>
#include <bsp_rtc.h>
#include <bsp_gpio.h>
#include <bsp_gpio_it.h>
#include <bsp_lptimer.h>
#include <bsp_spi.h>
#include <bsp_i2c.h>
#include <bsp_uart.h>
#ifdef HAS_BSP_PWRLINE
#include <bsp_pwrlines.h>
#endif

extern void msleep(uint32_t milisecond);
extern void Error_Handler(void);
extern void BSP_Init(void);

#ifdef  USE_FULL_ASSERT
extern void assert_failed(char *file, uint32_t line);
#endif /* USE_FULL_ASSERT */

#ifdef __cplusplus
}
#endif
#endif /* _BSP_H_ */
