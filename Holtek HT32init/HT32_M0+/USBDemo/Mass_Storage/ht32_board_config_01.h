/*********************************************************************************************************//**
 * @file    USBD/Mass_Storage/ht32_board_config_01.h
 * @version $Rev:: 2113         $
 * @date    $Date:: 2017-11-13 #$
 * @brief   The header file of board configuration.
 *************************************************************************************************************
 * @attention
 *
 * Firmware Disclaimer Information
 *
 * 1. The customer hereby acknowledges and agrees that the program technical documentation, including the
 *    code, which is supplied by Holtek Semiconductor Inc., (hereinafter referred to as "HOLTEK") is the
 *    proprietary and confidential intellectual property of HOLTEK, and is protected by copyright law and
 *    other intellectual property laws.
 *
 * 2. The customer hereby acknowledges and agrees that the program technical documentation, including the
 *    code, is confidential information belonging to HOLTEK, and must not be disclosed to any third parties
 *    other than HOLTEK and the customer.
 *
 * 3. The program technical documentation, including the code, is provided "as is" and for customer reference
 *    only. After delivery by HOLTEK, the customer shall use the program technical documentation, including
 *    the code, at their own risk. HOLTEK disclaims any expressed, implied or statutory warranties, including
 *    the warranties of merchantability, satisfactory quality and fitness for a particular purpose.
 *
 * <h2><center>Copyright (C) Holtek Semiconductor Inc. All rights reserved</center></h2>
 ************************************************************************************************************/
/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __HT32_BOARD_CONFIG_01_H
#define __HT32_BOARD_CONFIG_01_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Settings ------------------------------------------------------------------------------------------------*/
#if defined(USE_HT32F52341_SK)
#if ((BOT_LUN_NUM<1)| (BOT_RAM_DISK0>0)| (BOT_RAM_DISK1>0)| (BOT_SD_DISK0<1))
  #if (BOT_LUN_NUM!=1)
    #undef BOT_LUN_NUM
    #define BOT_LUN_NUM 1
  #endif
  #if (BOT_RAM_DISK0>0)
      #undef BOT_RAM_DISK0
      #define BOT_RAM_DISK0 0
  #endif
  #if (BOT_RAM_DISK1>0)
      #undef BOT_RAM_DISK1
      #define BOT_RAM_DISK1 0
  #endif
  #if (BOT_SD_DISK0!=1)
      #undef BOT_SD_DISK0
      #define BOT_SD_DISK0 1
  #endif
  #warning "This example code only support BOT_SD_DISK0. "
#endif
#endif

#if defined(USE_HT32F52352_SK)

#endif

#ifdef __cplusplus
}
#endif

#endif
