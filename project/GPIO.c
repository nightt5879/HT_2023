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
#include "GPIO.h"

//-----------------------------------------------------------------------------
void GPIO_Configuration(void)
{
  CKCU_PeripClockConfig_TypeDef CKCUClock = {{ 0 }};
  CKCUClock.Bit.PA    = 1;
  CKCUClock.Bit.PB    = 1;
  CKCUClock.Bit.PC    = 1;
  CKCUClock.Bit.AFIO  = 1;
  CKCU_PeripClockConfig(CKCUClock, ENABLE);



  GPIO_ClearOutBits       (OUT_PA0_GPIO_PORT, OUT_PA0_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PA0_GPIO_PORT, OUT_PA0_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PA1_GPIO_PORT, OUT_PA1_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PA1_GPIO_PORT, OUT_PA1_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PA2_GPIO_PORT, OUT_PA2_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PA2_GPIO_PORT, OUT_PA2_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PA3_GPIO_PORT, OUT_PA3_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PA3_GPIO_PORT, OUT_PA3_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PA4_GPIO_PORT, OUT_PA4_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PA4_GPIO_PORT, OUT_PA4_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PA5_GPIO_PORT, OUT_PA5_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PA5_GPIO_PORT, OUT_PA5_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PA6_GPIO_PORT, OUT_PA6_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PA6_GPIO_PORT, OUT_PA6_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PA7_GPIO_PORT, OUT_PA7_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PA7_GPIO_PORT, OUT_PA7_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PC8_GPIO_PORT, OUT_PC8_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PC8_GPIO_PORT, OUT_PC8_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PB0_GPIO_PORT, OUT_PB0_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PB0_GPIO_PORT, OUT_PB0_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PB1_GPIO_PORT, OUT_PB1_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PB1_GPIO_PORT, OUT_PB1_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PB2_GPIO_PORT, OUT_PB2_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PB2_GPIO_PORT, OUT_PB2_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PB3_GPIO_PORT, OUT_PB3_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PB3_GPIO_PORT, OUT_PB3_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PB4_GPIO_PORT, OUT_PB4_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PB4_GPIO_PORT, OUT_PB4_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PB5_GPIO_PORT, OUT_PB5_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PB5_GPIO_PORT, OUT_PB5_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PB6_GPIO_PORT, OUT_PB6_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PB6_GPIO_PORT, OUT_PB6_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PB7_GPIO_PORT, OUT_PB7_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PB7_GPIO_PORT, OUT_PB7_GPIO_PIN, GPIO_DIR_OUT);

  GPIO_ClearOutBits       (OUT_PB8_GPIO_PORT, OUT_PB8_GPIO_PIN);
  GPIO_DirectionConfig    (OUT_PB8_GPIO_PORT, OUT_PB8_GPIO_PIN, GPIO_DIR_OUT);
  
  GPIO_ClearOutBits       (OUT_PC13_GPIO_PORT, OUT_PC13_GPIO_PIN);
  GPIO_InputConfig		  (OUT_PC13_GPIO_PORT,OUT_PC13_GPIO_PIN, ENABLE);
  GPIO_DirectionConfig    (OUT_PC13_GPIO_PORT, OUT_PC13_GPIO_PIN, GPIO_DIR_IN);
  
}

//-----------------------------------------------------------------------------


