#include "LED.h"

void led_init(void)
{
	//Enable peripheral clock  
	CKCU_PeripClockConfig_TypeDef LEDClock = {{ 0 }};
	//A group GPIO
	LEDClock.Bit.PA = 1; 
	CKCU_PeripClockConfig(LEDClock, ENABLE);
	GPIO_DirectionConfig(HT_GPIOA, GPIO_PIN_6|GPIO_PIN_7, GPIO_DIR_OUT); //output mode
	/* Configure AFIO mode as GPIO                                                                          */
//    AFIO_GPxConfig(GPIO_PA, GPIO_PIN_6|GPIO_PIN_7, AFIO_FUN_GPIO);
	/* Configure GPIO pull resistor                                                                         */
    GPIO_PullResistorConfig(HT_GPIOA, GPIO_PIN_6|GPIO_PIN_7, GPIO_PR_DOWN);  //pull-down resisitor
	

	LEDClock.Bit.PB = 1; 
	CKCU_PeripClockConfig(LEDClock, ENABLE);
	GPIO_DirectionConfig(HT_GPIOB, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_DIR_OUT); //output mode
	/* Configure AFIO mode as GPIO                                                                          */
//    AFIO_GPxConfig(GPIO_PB, AFIO_PIN_4|AFIO_PIN_5|AFIO_PIN_6, AFIO_FUN_GPIO);
	/* Configure GPIO pull resistor                                                                         */
    GPIO_PullResistorConfig(HT_GPIOB, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PR_DOWN);  //pull-down resisitor

	LEDClock.Bit.PC = 1; 
	CKCU_PeripClockConfig(LEDClock, ENABLE);
	GPIO_DirectionConfig(HT_GPIOC, GPIO_PIN_8, GPIO_DIR_OUT); //output mode
	/* Configure AFIO mode as GPIO                                                                          */
//    AFIO_GPxConfig(GPIO_PB, AFIO_PIN_4|AFIO_PIN_5|AFIO_PIN_6, AFIO_FUN_GPIO);
	/* Configure GPIO pull resistor                                                                         */
    GPIO_PullResistorConfig(HT_GPIOC, GPIO_PIN_8, GPIO_PR_DOWN);  //pull-down resisitor
}

void bttery_level(uint8_t led_num)
{
	switch(led_num)
	{
		case 1: //power 100%
		{
			//three LED
			GPIO_SetOutBits(HT_GPIOB, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6);
			//GPIO_ClearOutBits();
			//RGB A6:Red A7:Green C8:Blue
			GPIO_SetOutBits(HT_GPIOA, GPIO_PIN_7);
			GPIO_ClearOutBits(HT_GPIOA, GPIO_PIN_6);
			GPIO_ClearOutBits(HT_GPIOC, GPIO_PIN_8);	
			break;
		}
		case 2: //power 75%
		{
			GPIO_SetOutBits(HT_GPIOB, GPIO_PIN_4|GPIO_PIN_5); 
			GPIO_SetOutBits(HT_GPIOA, GPIO_PIN_7);
			
			GPIO_SetOutBits(HT_GPIOA, GPIO_PIN_7);
			GPIO_ClearOutBits(HT_GPIOA, GPIO_PIN_6);
			GPIO_ClearOutBits(HT_GPIOC, GPIO_PIN_8);	
			break;
		}
		case 3: //power 50%
		{
			GPIO_SetOutBits(HT_GPIOB, GPIO_PIN_4); 
			GPIO_ClearOutBits(HT_GPIOB, GPIO_PIN_5|GPIO_PIN_6);
			
			GPIO_SetOutBits(HT_GPIOA, GPIO_PIN_7);
			GPIO_ClearOutBits(HT_GPIOA, GPIO_PIN_6);
			GPIO_ClearOutBits(HT_GPIOC, GPIO_PIN_8);
			break;
		}
		case 4: //power 25%
		{

			GPIO_ClearOutBits(HT_GPIOB, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6);
			
			GPIO_SetOutBits(HT_GPIOA, GPIO_PIN_6);
			GPIO_ClearOutBits(HT_GPIOA, GPIO_PIN_7);
			GPIO_ClearOutBits(HT_GPIOC, GPIO_PIN_8);
			break;
		}
	}
}
