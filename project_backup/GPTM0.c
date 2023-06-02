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
#include "GPTM0.h"

//-----------------------------------------------------------------------------
#define GPTM0_TIMER_BASE            ((long long)SystemCoreClock * 1/1000)

//-----------------------------------------------------------------------------
vu32 gptm0_ct;

//-----------------------------------------------------------------------------
void GPTM0_Configuration(void)
{
  u32 wCRR = 0, wPSCR = 0;
  TM_TimeBaseInitTypeDef TM_TimeBaseInitStruct;
  CKCU_PeripClockConfig_TypeDef CKCUClock = {{ 0 }};
  CKCUClock.Bit.GPTM0      = 1;
  CKCU_PeripClockConfig(CKCUClock, ENABLE);

  wCRR = GPTM0_TIMER_BASE - 1;
  while ((wCRR / (wPSCR + 1)) > 0xFFFF)
  {
    wPSCR++;
  }
  wCRR = wCRR / (wPSCR + 1);

  TM_TimeBaseInitStruct.CounterReload = wCRR;
  TM_TimeBaseInitStruct.Prescaler = wPSCR;
  TM_TimeBaseInitStruct.RepetitionCounter = 0;
  TM_TimeBaseInitStruct.CounterMode = TM_CNT_MODE_UP;
  TM_TimeBaseInitStruct.PSCReloadTime = TM_PSC_RLD_IMMEDIATE;
  TM_TimeBaseInit(HT_GPTM0, &TM_TimeBaseInitStruct);

  TM_ClearFlag(HT_GPTM0, TM_INT_UEV);
  TM_IntConfig(HT_GPTM0, TM_INT_UEV, ENABLE);
  NVIC_EnableIRQ(GPTM0_IRQn);   // interrupt enable

  TM_Cmd(HT_GPTM0, ENABLE);
}


//-----------------------------------------------------------------------------
void GPTM0_IRQHandler(void)
{
  TM_ClearFlag(HT_GPTM0, TM_INT_UEV);
  gptm0_ct++;
  if (gptm0_ct >100) gptm0_ct = 0;
}

//-----------------------------------------------------------------------------


