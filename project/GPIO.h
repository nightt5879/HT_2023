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
#ifndef __GPIO_H
#define __GPIO_H

#include "ht32.h"

//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
#define OUT_PA0_PORT           A
#define OUT_PA0_PIN            0
#define OUT_PA0_GPIO_CLK      STRCAT2(P,          OUT_PA0_PORT)
#define OUT_PA0_GPIO_ID       STRCAT2(GPIO_P,     OUT_PA0_PORT)
#define OUT_PA0_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PA0_PORT)
#define OUT_PA0_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PA0_PIN)
#define OUT_PA0_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PA0_HIGH          OUT_PA0_GPIO_PORT->SRR    = OUT_PA0_GPIO_PIN
#define OUT_PA0_LOW           OUT_PA0_GPIO_PORT->RR     = OUT_PA0_GPIO_PIN
#define OUT_PA0_XOR           OUT_PA0_GPIO_PORT->DOUTR ^= OUT_PA0_GPIO_PIN

#define OUT_PA1_PORT           A
#define OUT_PA1_PIN            1
#define OUT_PA1_GPIO_CLK      STRCAT2(P,          OUT_PA1_PORT)
#define OUT_PA1_GPIO_ID       STRCAT2(GPIO_P,     OUT_PA1_PORT)
#define OUT_PA1_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PA1_PORT)
#define OUT_PA1_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PA1_PIN)
#define OUT_PA1_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PA1_HIGH          OUT_PA1_GPIO_PORT->SRR    = OUT_PA1_GPIO_PIN
#define OUT_PA1_LOW           OUT_PA1_GPIO_PORT->RR     = OUT_PA1_GPIO_PIN
#define OUT_PA1_XOR           OUT_PA1_GPIO_PORT->DOUTR ^= OUT_PA1_GPIO_PIN

#define OUT_PA2_PORT           A
#define OUT_PA2_PIN            2
#define OUT_PA2_GPIO_CLK      STRCAT2(P,          OUT_PA2_PORT)
#define OUT_PA2_GPIO_ID       STRCAT2(GPIO_P,     OUT_PA2_PORT)
#define OUT_PA2_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PA2_PORT)
#define OUT_PA2_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PA2_PIN)
#define OUT_PA2_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PA2_HIGH          OUT_PA2_GPIO_PORT->SRR    = OUT_PA2_GPIO_PIN
#define OUT_PA2_LOW           OUT_PA2_GPIO_PORT->RR     = OUT_PA2_GPIO_PIN
#define OUT_PA2_XOR           OUT_PA2_GPIO_PORT->DOUTR ^= OUT_PA2_GPIO_PIN

#define OUT_PA3_PORT           A
#define OUT_PA3_PIN            3
#define OUT_PA3_GPIO_CLK      STRCAT2(P,          OUT_PA3_PORT)
#define OUT_PA3_GPIO_ID       STRCAT2(GPIO_P,     OUT_PA3_PORT)
#define OUT_PA3_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PA3_PORT)
#define OUT_PA3_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PA3_PIN)
#define OUT_PA3_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PA3_HIGH          OUT_PA3_GPIO_PORT->SRR    = OUT_PA3_GPIO_PIN
#define OUT_PA3_LOW           OUT_PA3_GPIO_PORT->RR     = OUT_PA3_GPIO_PIN
#define OUT_PA3_XOR           OUT_PA3_GPIO_PORT->DOUTR ^= OUT_PA3_GPIO_PIN

#define OUT_PA4_PORT           A
#define OUT_PA4_PIN            4
#define OUT_PA4_GPIO_CLK      STRCAT2(P,          OUT_PA4_PORT)
#define OUT_PA4_GPIO_ID       STRCAT2(GPIO_P,     OUT_PA4_PORT)
#define OUT_PA4_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PA4_PORT)
#define OUT_PA4_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PA4_PIN)
#define OUT_PA4_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PA4_HIGH          OUT_PA4_GPIO_PORT->SRR    = OUT_PA4_GPIO_PIN
#define OUT_PA4_LOW           OUT_PA4_GPIO_PORT->RR     = OUT_PA4_GPIO_PIN
#define OUT_PA4_XOR           OUT_PA4_GPIO_PORT->DOUTR ^= OUT_PA4_GPIO_PIN

#define OUT_PA5_PORT           A
#define OUT_PA5_PIN            5
#define OUT_PA5_GPIO_CLK      STRCAT2(P,          OUT_PA5_PORT)
#define OUT_PA5_GPIO_ID       STRCAT2(GPIO_P,     OUT_PA5_PORT)
#define OUT_PA5_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PA5_PORT)
#define OUT_PA5_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PA5_PIN)
#define OUT_PA5_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PA5_HIGH          OUT_PA5_GPIO_PORT->SRR    = OUT_PA5_GPIO_PIN
#define OUT_PA5_LOW           OUT_PA5_GPIO_PORT->RR     = OUT_PA5_GPIO_PIN
#define OUT_PA5_XOR           OUT_PA5_GPIO_PORT->DOUTR ^= OUT_PA5_GPIO_PIN

#define OUT_PA6_PORT           A
#define OUT_PA6_PIN            6
#define OUT_PA6_GPIO_CLK      STRCAT2(P,          OUT_PA6_PORT)
#define OUT_PA6_GPIO_ID       STRCAT2(GPIO_P,     OUT_PA6_PORT)
#define OUT_PA6_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PA6_PORT)
#define OUT_PA6_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PA6_PIN)
#define OUT_PA6_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PA6_HIGH          OUT_PA6_GPIO_PORT->SRR    = OUT_PA6_GPIO_PIN
#define OUT_PA6_LOW           OUT_PA6_GPIO_PORT->RR     = OUT_PA6_GPIO_PIN
#define OUT_PA6_XOR           OUT_PA6_GPIO_PORT->DOUTR ^= OUT_PA6_GPIO_PIN

#define OUT_PA7_PORT           A
#define OUT_PA7_PIN            7
#define OUT_PA7_GPIO_CLK      STRCAT2(P,          OUT_PA7_PORT)
#define OUT_PA7_GPIO_ID       STRCAT2(GPIO_P,     OUT_PA7_PORT)
#define OUT_PA7_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PA7_PORT)
#define OUT_PA7_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PA7_PIN)
#define OUT_PA7_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PA7_HIGH          OUT_PA7_GPIO_PORT->SRR    = OUT_PA7_GPIO_PIN
#define OUT_PA7_LOW           OUT_PA7_GPIO_PORT->RR     = OUT_PA7_GPIO_PIN
#define OUT_PA7_XOR           OUT_PA7_GPIO_PORT->DOUTR ^= OUT_PA7_GPIO_PIN

#define OUT_PC8_PORT           C
#define OUT_PC8_PIN            8
#define OUT_PC8_GPIO_CLK      STRCAT2(P,          OUT_PC8_PORT)
#define OUT_PC8_GPIO_ID       STRCAT2(GPIO_P,     OUT_PC8_PORT)
#define OUT_PC8_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PC8_PORT)
#define OUT_PC8_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PC8_PIN)
#define OUT_PC8_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PC8_HIGH          OUT_PC8_GPIO_PORT->SRR    = OUT_PC8_GPIO_PIN
#define OUT_PC8_LOW           OUT_PC8_GPIO_PORT->RR     = OUT_PC8_GPIO_PIN
#define OUT_PC8_XOR           OUT_PC8_GPIO_PORT->DOUTR ^= OUT_PC8_GPIO_PIN

#define OUT_PB0_PORT           B
#define OUT_PB0_PIN            0
#define OUT_PB0_GPIO_CLK      STRCAT2(P,          OUT_PB0_PORT)
#define OUT_PB0_GPIO_ID       STRCAT2(GPIO_P,     OUT_PB0_PORT)
#define OUT_PB0_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PB0_PORT)
#define OUT_PB0_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PB0_PIN)
#define OUT_PB0_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PB0_HIGH          OUT_PB0_GPIO_PORT->SRR    = OUT_PB0_GPIO_PIN
#define OUT_PB0_LOW           OUT_PB0_GPIO_PORT->RR     = OUT_PB0_GPIO_PIN
#define OUT_PB0_XOR           OUT_PB0_GPIO_PORT->DOUTR ^= OUT_PB0_GPIO_PIN

#define OUT_PB1_PORT           B
#define OUT_PB1_PIN            1
#define OUT_PB1_GPIO_CLK      STRCAT2(P,          OUT_PB1_PORT)
#define OUT_PB1_GPIO_ID       STRCAT2(GPIO_P,     OUT_PB1_PORT)
#define OUT_PB1_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PB1_PORT)
#define OUT_PB1_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PB1_PIN)
#define OUT_PB1_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PB1_HIGH          OUT_PB1_GPIO_PORT->SRR    = OUT_PB1_GPIO_PIN
#define OUT_PB1_LOW           OUT_PB1_GPIO_PORT->RR     = OUT_PB1_GPIO_PIN
#define OUT_PB1_XOR           OUT_PB1_GPIO_PORT->DOUTR ^= OUT_PB1_GPIO_PIN

#define OUT_PB2_PORT           B
#define OUT_PB2_PIN            2
#define OUT_PB2_GPIO_CLK      STRCAT2(P,          OUT_PB2_PORT)
#define OUT_PB2_GPIO_ID       STRCAT2(GPIO_P,     OUT_PB2_PORT)
#define OUT_PB2_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PB2_PORT)
#define OUT_PB2_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PB2_PIN)
#define OUT_PB2_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PB2_HIGH          OUT_PB2_GPIO_PORT->SRR    = OUT_PB2_GPIO_PIN
#define OUT_PB2_LOW           OUT_PB2_GPIO_PORT->RR     = OUT_PB2_GPIO_PIN
#define OUT_PB2_XOR           OUT_PB2_GPIO_PORT->DOUTR ^= OUT_PB2_GPIO_PIN

#define OUT_PB3_PORT           B
#define OUT_PB3_PIN            3
#define OUT_PB3_GPIO_CLK      STRCAT2(P,          OUT_PB3_PORT)
#define OUT_PB3_GPIO_ID       STRCAT2(GPIO_P,     OUT_PB3_PORT)
#define OUT_PB3_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PB3_PORT)
#define OUT_PB3_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PB3_PIN)
#define OUT_PB3_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PB3_HIGH          OUT_PB3_GPIO_PORT->SRR    = OUT_PB3_GPIO_PIN
#define OUT_PB3_LOW           OUT_PB3_GPIO_PORT->RR     = OUT_PB3_GPIO_PIN
#define OUT_PB3_XOR           OUT_PB3_GPIO_PORT->DOUTR ^= OUT_PB3_GPIO_PIN

#define OUT_PB4_PORT           B
#define OUT_PB4_PIN            4
#define OUT_PB4_GPIO_CLK      STRCAT2(P,          OUT_PB4_PORT)
#define OUT_PB4_GPIO_ID       STRCAT2(GPIO_P,     OUT_PB4_PORT)
#define OUT_PB4_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PB4_PORT)
#define OUT_PB4_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PB4_PIN)
#define OUT_PB4_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PB4_HIGH          OUT_PB4_GPIO_PORT->SRR    = OUT_PB4_GPIO_PIN
#define OUT_PB4_LOW           OUT_PB4_GPIO_PORT->RR     = OUT_PB4_GPIO_PIN
#define OUT_PB4_XOR           OUT_PB4_GPIO_PORT->DOUTR ^= OUT_PB4_GPIO_PIN

#define OUT_PB5_PORT           B
#define OUT_PB5_PIN            5
#define OUT_PB5_GPIO_CLK      STRCAT2(P,          OUT_PB5_PORT)
#define OUT_PB5_GPIO_ID       STRCAT2(GPIO_P,     OUT_PB5_PORT)
#define OUT_PB5_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PB5_PORT)
#define OUT_PB5_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PB5_PIN)
#define OUT_PB5_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PB5_HIGH          OUT_PB5_GPIO_PORT->SRR    = OUT_PB5_GPIO_PIN
#define OUT_PB5_LOW           OUT_PB5_GPIO_PORT->RR     = OUT_PB5_GPIO_PIN
#define OUT_PB5_XOR           OUT_PB5_GPIO_PORT->DOUTR ^= OUT_PB5_GPIO_PIN

#define OUT_PB6_PORT           B
#define OUT_PB6_PIN            6
#define OUT_PB6_GPIO_CLK      STRCAT2(P,          OUT_PB6_PORT)
#define OUT_PB6_GPIO_ID       STRCAT2(GPIO_P,     OUT_PB6_PORT)
#define OUT_PB6_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PB6_PORT)
#define OUT_PB6_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PB6_PIN)
#define OUT_PB6_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PB6_HIGH          OUT_PB6_GPIO_PORT->SRR    = OUT_PB6_GPIO_PIN
#define OUT_PB6_LOW           OUT_PB6_GPIO_PORT->RR     = OUT_PB6_GPIO_PIN
#define OUT_PB6_XOR           OUT_PB6_GPIO_PORT->DOUTR ^= OUT_PB6_GPIO_PIN

#define OUT_PB7_PORT           B
#define OUT_PB7_PIN            7
#define OUT_PB7_GPIO_CLK      STRCAT2(P,          OUT_PB7_PORT)
#define OUT_PB7_GPIO_ID       STRCAT2(GPIO_P,     OUT_PB7_PORT)
#define OUT_PB7_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PB7_PORT)
#define OUT_PB7_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PB7_PIN)
#define OUT_PB7_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PB7_HIGH          OUT_PB7_GPIO_PORT->SRR    = OUT_PB7_GPIO_PIN
#define OUT_PB7_LOW           OUT_PB7_GPIO_PORT->RR     = OUT_PB7_GPIO_PIN
#define OUT_PB7_XOR           OUT_PB7_GPIO_PORT->DOUTR ^= OUT_PB7_GPIO_PIN

#define OUT_PB8_PORT           B
#define OUT_PB8_PIN            8
#define OUT_PB8_GPIO_CLK      STRCAT2(P,          OUT_PB8_PORT)
#define OUT_PB8_GPIO_ID       STRCAT2(GPIO_P,     OUT_PB8_PORT)
#define OUT_PB8_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PB8_PORT)
#define OUT_PB8_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PB8_PIN)
#define OUT_PB8_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PB8_HIGH          OUT_PB8_GPIO_PORT->SRR    = OUT_PB8_GPIO_PIN
#define OUT_PB8_LOW           OUT_PB8_GPIO_PORT->RR     = OUT_PB8_GPIO_PIN
#define OUT_PB8_XOR           OUT_PB8_GPIO_PORT->DOUTR ^= OUT_PB8_GPIO_PIN

#define OUT_PC13_PORT           C
#define OUT_PC13_PIN            13
#define OUT_PC13_GPIO_CLK      STRCAT2(P,          OUT_PC13_PORT)
#define OUT_PC13_GPIO_ID       STRCAT2(GPIO_P,     OUT_PC13_PORT)
#define OUT_PC13_GPIO_PORT     STRCAT2(HT_GPIO,    OUT_PC13_PORT)
#define OUT_PC13_GPIO_PIN      STRCAT2(GPIO_PIN_,  OUT_PC13_PIN)
#define OUT_PC13_AFIO_MODE     (AFIO_MODE_GPIO)
#define OUT_PC13_HIGH          OUT_PC13_GPIO_PORT->SRR    = OUT_PC13_GPIO_PIN
#define OUT_PC13_LOW           OUT_PC13_GPIO_PORT->RR     = OUT_PC13_GPIO_PIN
#define OUT_PC13_XOR           OUT_PC13_GPIO_PORT->DOUTR ^= OUT_PC13_GPIO_PIN

//-----------------------------------------------------------------------------
void GPIO_Configuration(void);

#endif

