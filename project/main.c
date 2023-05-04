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
u8 data[] = {0xAA, 0x00, 00, 0x00};  //Standard data format
u8 data_tem[] = {0xAA,0x55,0x00,0x00,0x00,0x55,0xAA};  //battery 
u8 data_speech[] = {0xAA,0x55,0x00,0x55,0xAA};  //speech
unsigned char temperature_10,temperature_time,face_time; 
u8 press_flag,face_flag,temperature_flag,face_flag_complete;
u32 restart_flag;
float voltage; //Battery level
	unsigned char t = 3;
//extern_variable
extern vu32 gptm0_ct;
extern u8 face_flag_complete;
extern u8 face_flag;
extern unsigned char face_time;
//---function----
void Init(void);
static void delay_us(u32 count); //__nop == 1/48us?
void broadcast_battery(void);
void detect_complete(void);
void cheak_Rxdata(void);
void click_button(void);
void battery_indicator(void);

//---main---
int main(void)
{
	Init();
	while (1)
	{
//		UART0_tx_data(data,sizeof(data));
//		cheak_Rxdata();  
		if (gptm0_ct < 10)  //Check if the detection work of a person is completed
			detect_complete();
		else if( 9 < gptm0_ct && gptm0_ct < 30) //Read the Rxdata
			__NOP();
//			cheak_Rxdata();  
		else if( 29 < gptm0_ct && gptm0_ct < 80) //Check if the key is pressed
			click_button(); 
		else if(79 < gptm0_ct && gptm0_ct < 90) //Restart main function by long press 
		{
			if(restart_flag > 10000)  
				main();
		}
		else if(gptm0_ct > 89)  //battery level
			battery_indicator();
	}
}



void detect_complete(void)
{
	if(temperature_flag && face_flag_complete)
	{
		//two green
		GPIO_SetOutBits(HT_GPIOB, GPIO_PIN_8);  //green
		GPIO_ClearOutBits(HT_GPIOA, GPIO_PIN_2);
		GPIO_ClearOutBits(HT_GPIOB, GPIO_PIN_7); 
		
		GPIO_SetOutBits(HT_GPIOA, GPIO_PIN_4);  //green
		GPIO_ClearOutBits(HT_GPIOA, GPIO_PIN_3|GPIO_PIN_5);
		
		//send speak signal
		data_speech[2] = 0x06;
		UART1_tx_data(data_speech,sizeof(data_speech));
		//Assign initial value to the variable
		temperature_time = 0;
		face_time = 0;
		press_flag = 0;
		restart_flag = 0; //for restart the main,
		face_flag = 0;
		temperature_flag = 0;
	}
}
void cheak_Rxdata(void)
{
	t = UART0_analyze_data();
	if(t == FACE_SUCCESS)
	{
//		UART0_tx_data(data,sizeof(data));
		face_flag_complete = 1;
		//send speak signal
		data_speech[2] = 0x04;
		UART1_tx_data(data_speech,sizeof(data_speech));
		GPIO_SetOutBits(HT_GPIOB, GPIO_PIN_8);  //green
		GPIO_ClearOutBits(HT_GPIOA, GPIO_PIN_2);
		GPIO_ClearOutBits(HT_GPIOB, GPIO_PIN_7); 		
	}
	else if(t == FACE_FAILURE)
	{
		face_flag = 0;
		data_speech[2] = 0x05;
		//send speak signal
		UART1_tx_data(data_speech,sizeof(data_speech));
		GPIO_SetOutBits(HT_GPIOB, GPIO_PIN_7);  //red
		GPIO_ClearOutBits(HT_GPIOA, GPIO_PIN_2);
		GPIO_ClearOutBits(HT_GPIOB, GPIO_PIN_8); 
		face_time++;
	}
}
void temperature_RGB_UART(void)
{
	unsigned char tem_int,tem_float; 
	temperature_10 = temperature_measurement() + 22;  //actual temperature = temperature_10 / 10 - 20
	tem_int = (temperature_10 / 10) + 20;
	tem_float = temperature_10 % 10;
	if (temperature_10 > 185) //exceeding the standard temperature
	{
		GPIO_SetOutBits(HT_GPIOA, GPIO_PIN_3);  //red
		GPIO_ClearOutBits(HT_GPIOA, GPIO_PIN_4|GPIO_PIN_5);
		temperature_time++;
		//send the temperature data
		data_tem[2] = 0x02;
		data_tem[3] = tem_int;
		data_tem[4] = tem_float;
		UART1_tx_data(data_tem,sizeof(data_tem));
	}
	else if(temperature_10 < 160)  //below the standard temperature
	{
		GPIO_SetOutBits(HT_GPIOA, GPIO_PIN_5);  //blue
		GPIO_ClearOutBits(HT_GPIOA, GPIO_PIN_3|GPIO_PIN_4);
		data_speech[2] = 3;
		UART1_tx_data(data_speech,sizeof(data_speech));
		temperature_time++;
		//send the temperature data
		data_tem[2] = 0x03;
		data_tem[3] = tem_int;
		data_tem[4] = tem_float;
		UART1_tx_data(data_tem,sizeof(data_tem));
	}
	else  //The temperature is normal. UART Sends
	{
		GPIO_SetOutBits(HT_GPIOA, GPIO_PIN_4);  //green
		GPIO_ClearOutBits(HT_GPIOA, GPIO_PIN_3|GPIO_PIN_5);
		
		temperature_flag = 1;  //flag
		//send the temperature data
		data_tem[2] = 0x01;
		data_tem[3] = tem_int;
		data_tem[4] = tem_float;
		UART1_tx_data(data_tem,sizeof(data_tem));
		UART0_tx_data(data_tem,sizeof(data_tem));
	}
}
void click_button(void)
{
if(!GPIO_ReadInBit(OUT_PC13_GPIO_PORT, OUT_PC13_GPIO_PIN) || press_flag)
{
	delay_us(100);
	if(!GPIO_ReadInBit(OUT_PC13_GPIO_PORT, OUT_PC13_GPIO_PIN) || press_flag)
	{
		restart_flag++;  
		press_flag = 1;//flag indicating that the button has been pressed
		if(GPIO_ReadInBit(OUT_PC13_GPIO_PORT, OUT_PC13_GPIO_PIN))
		{
			press_flag = 0;
			if(!face_flag)
			{
				face_flag = 1;
				if(face_time >3)
				{
					//send speak signal
					data_speech[2] = 0x07;
					UART1_tx_data(data_speech,sizeof(data_speech));
					//two RGB in blue
					GPIO_SetOutBits(HT_GPIOA, GPIO_PIN_2|GPIO_PIN_5);
					GPIO_ClearOutBits(HT_GPIOB, GPIO_PIN_7|GPIO_PIN_8);
					GPIO_ClearOutBits(HT_GPIOA, GPIO_PIN_3|GPIO_PIN_4);
				}
				else
				{
					//send the image
					data[1] = 0x02;
					data[2] = 0x00;
					data[3] = 0x00;
					UART0_tx_data(data, sizeof(data));
				}
			}
			else
			{
				temperature_RGB_UART();
				if(temperature_time >3)
				{
					//send speak signal
					data_speech[2] = 0x08;
					UART1_tx_data(data_speech,sizeof(data_speech));
					//two RGB in red
					GPIO_SetOutBits(HT_GPIOA, GPIO_PIN_3);
					GPIO_SetOutBits(HT_GPIOB, GPIO_PIN_7);
					GPIO_ClearOutBits(HT_GPIOB, GPIO_PIN_8);
					GPIO_ClearOutBits(HT_GPIOA, GPIO_PIN_2|GPIO_PIN_4|GPIO_PIN_5);
				}
			}
		}
	}
}


}

void battery_indicator(void)
{
	//3.0->0%;3.3->25%;3.5->50%;3.8->75%;4.05->100%
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
	
	//Assign initial value to the variable
	voltage = 0.0;
	temperature_time = 0;
	face_time = 0;
	press_flag = 0;
	restart_flag = 0; //for restart the main,
	face_flag = 0;
	face_flag_complete = 0; //for finish
	temperature_flag = 0;
	
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
