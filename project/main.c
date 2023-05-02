#include "ht32.h"
#include "GPIO.h"
#include "BFTM0.h"
#include "ADC.h"
#include "UART0.h"
#include "UART1.h"
#include "GPTM0.h"
#include "LED.h"
#include "I2C.h"

//macro definition

//---variable---
u8 datad[] = {0x00, 0x00, 00, 0x00};  //Standard data format
unsigned char temperature_10; 
//extern_variable
extern vu32 gptm0_ct;
//---function----
void Init(void);
static void delay_us(u32 count); //__nop == 1/48us?
void click_button(void);
void battery_indicator(void);
//---main---
int main(void)
{

	Init();
	while (1)
	{
		if( 30 < gptm0_ct && gptm0_ct < 90)
		{
			//check if a key is pressed
			if(GPIO_ReadInBit(OUT_PC13_GPIO_PORT, OUT_PC13_GPIO_PIN))
				click_button();
		}
		else if(gptm0_ct > 89)
			battery_indicator();
	}
}

void click_button(void)
{
	temperature_10 = temperature_measurement();  //actual temperature = temperature_10 / 10 - 20
}

void battery_indicator(void)
{
	//3.0->0%;3.3->25%;3.5->50%;3.8->75%;4.05->100%
	float voltage; //Battery level
	voltage = Get_Voltage();  //get the voltag
	if(voltage > 3.8)bttery_level(1);
	else if(voltage >3.5 && voltage <3.8)bttery_level(2);
	else if(voltage >3.3 && voltage <3.5)bttery_level(3);
	else bttery_level(4);
}

void Init(void)
{
	//Init all
	GPIO_Configuration();
	BFTM0_Configuration();
	ADC_Configuration();
	led_init();
	bttery_level(1);
	ADC_Cmd(HTCFG_ADC_PORT, ENABLE);
	/* Software trigger to start ADC conversion                                                               */
	ADC_SoftwareStartConvCmd(HTCFG_ADC_PORT, ENABLE);
	UART0_Configuration();
	UART1_Configuration();
	GPTM0_Configuration();
	
	//the led show
	delay_us(100000);
	bttery_level(4);
	delay_us(100000);
	bttery_level(3);
	delay_us(100000);
	bttery_level(2);
	delay_us(100000);
	bttery_level(1);
}

static void delay_us(u32 count) //__nop == 1/48us?
{
	unsigned int i;
  while (count--)
  {
	  for(i = 0;i<9;i++){
    __NOP(); // Prevent delay loop be optimized
	  }
  }
}
