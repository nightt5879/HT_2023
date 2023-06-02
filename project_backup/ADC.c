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
#include "ADC.h"

//-----------------------------------------------------------------------------
vu8 adc_result_update;
vu16 adc_result[14];

//-----------------------------------------------------------------------------
void ADC_Configuration(void)
{
  { /* Enable peripheral clock                                                                              */
	CKCU_PeripClockConfig_TypeDef LEDClock = {{ 0 }};
	CKCU_PeripClockConfig_TypeDef CKCUClock = {{ 0 }};
	
	
	LEDClock.Bit.PC = 1; 
	CKCU_PeripClockConfig(LEDClock, ENABLE); //????
	GPIO_DirectionConfig(HT_GPIOC, GPIO_PIN_9, GPIO_DIR_IN); 
	  

    CKCUClock.Bit.AFIO = 1;
    CKCUClock.Bit.HTCFG_ADC_IPN = 1;
    CKCU_PeripClockConfig(CKCUClock, ENABLE);
  }
	AFIO_GPxConfig(GPIO_PC, AFIO_PIN_9, AFIO_FUN_ADC);  //AFIO_FUN_ADC

  { /* ADC related settings                                                                                 */
    /* CK_ADC frequency is set to (CK_AHB / 64)                                                             */
    CKCU_SetADCnPrescaler(HTCFG_ADC_CKCU_ADCPRE, CKCU_ADCPRE_DIV64);

    /* One Shot mode, sequence length = 1                                                                   */
    ADC_RegularGroupConfig(HTCFG_ADC_PORT, ONE_SHOT_MODE, 1, 0);  //CONTINUOUS_MODE  ONE_SHOT_MODE

    /* ADC conversion time = (Sampling time + Latency) / CK_ADC = (1.5 + ADST + 12.5) / CK_ADC              */
    /* Set ADST = 0, sampling time = 1.5 + ADST                                                             */
    #if (LIBCFG_ADC_SAMPLE_TIME_BY_CH)
      // The sampling time is set by the last parameter of the function "ADC_RegularChannelConfig()".
    #else
    ADC_SamplingTimeConfig(HTCFG_ADC_PORT, 0);
    #endif

    /* Set ADC conversion sequence as channel n                                                             */
    ADC_RegularChannelConfig(HTCFG_ADC_PORT, 11, 0);

    /* Set ADC trigger source                                                                               */
    ADC_RegularTrigConfig(HTCFG_ADC_PORT, ADC_TRIG_SOFTWARE);
  }

  /* Enable ADC end of conversion interrupt                                                                 */
  ADC_IntConfig(HTCFG_ADC_PORT, ADC_INT_SINGLE_EOC, ENABLE);

  /* Enable the ADC interrupts                                                                              */
  NVIC_EnableIRQ(HTCFG_ADC_IRQn);
}


//-----------------------------------------------------------------------------
void ADC_IRQHandler(void)
{

  extern vu32 gPotentiometerLevel;

  extern volatile bool gADC_SingleEndOfConversion;

  ADC_ClearIntPendingBit(HTCFG_ADC_PORT, ADC_FLAG_SINGLE_EOC);
//	bttery_level(4);
}


//-----------------------------------------------------------------------------
float Get_Voltage(void)
{
 uint32_t ADC_Value=0;
 uint8_t i;
 for(i=0;i<10;i++)
 {
  ADC_SoftwareStartConvCmd(HT_ADC, ENABLE);
  while(ADC_GetFlagStatus(HT_ADC,ADC_FLAG_SINGLE_EOC));
  ADC_Value += ADC_GetConversionData(HT_ADC0,0);
 }
 return (float)2*3.3*ADC_Value/4096/10;
}

