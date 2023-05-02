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
#include "BFTM0.h"

//-----------------------------------------------------------------------------
#define BFTM0_TIMER_BASE            ((long long)SystemCoreClock * 1/1000)

//-----------------------------------------------------------------------------
vu32 bftm0_ct;

//-----------------------------------------------------------------------------
void BFTM0_Configuration(void)
{
  CKCU_PeripClockConfig_TypeDef CKCUClock = {{ 0 }};
  CKCUClock.Bit.BFTM0      = 1;
  CKCU_PeripClockConfig(CKCUClock, ENABLE);

  NVIC_EnableIRQ(BFTM0_IRQn);   // interrupt enable
  BFTM_IntConfig(HT_BFTM0, ENABLE);

  BFTM_SetCompare(HT_BFTM0, BFTM0_TIMER_BASE);
  BFTM_SetCounter(HT_BFTM0, 0);
  BFTM_EnaCmd(HT_BFTM0, ENABLE);
}

//-----------------------------------------------------------------------------
void BFTM0_IRQHandler(void)
{
  BFTM_ClearFlag(HT_BFTM0);
  bftm0_ct++;
}

//-----------------------------------------------------------------------------


