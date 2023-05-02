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
#ifndef __ADC_H
#define __ADC_H

#define HTCFG_ADC_IPN                           ADC0
#define HTCFG_ADC_CKCU_ADCPRE                     STRCAT2(CKCU_ADCPRE_,   HTCFG_ADC_IPN)
#define HTCFG_ADC_PORT                            STRCAT2(HT_,            HTCFG_ADC_IPN)
#define HTCFG_ADC_IRQn                            STRCAT2(HTCFG_ADC_IPN, _IRQn)
//-----------------------------------------------------------------------------
#include "ht32.h"

//-----------------------------------------------------------------------------
extern vu8 adc_result_update;
extern vu16 adc_result[14];

//-----------------------------------------------------------------------------
void ADC_Configuration(void);
float Get_Voltage(void);

//-----------------------------------------------------------------------------
#endif

