 /************************************************************************************************************
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
//Build by HT32init V1.09.20.506Beta
//-----------------------------------------------------------------------------
#ifndef __UART0_H
#define __UART0_H


//-----------------------------------------------------------------------------
#include "ht32.h"

//-----------------------------------------------------------------------------
#define UART0_BUF_SIZE 256
#define UART0_FIFO_LEN 1

//-----------------------------------------------------------------------------
typedef struct
{
  u8 buffer[UART0_BUF_SIZE];
  u16 write_pt;
  u16 read_pt;
  u16 cnt;
}_UART0_STRUCT;

//-----------------------------------------------------------------------------
void UART0_Configuration(void);
void UART0_init_buffer (void);
void UART0_analyze_data(void);
void UART0_tx_data(u8 *pt, u8 len);
void UART0_test(void);

//-----------------------------------------------------------------------------
#endif

