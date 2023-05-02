#ifndef __I2C_H
#define __I2C_H


//-----------------------------------------------------------------------------
#include "ht32.h"
#include "GPIO.h"
void delayy(u32 count); //__nop == 1/48us?
#define SDA_LOW() OUT_PA1_LOW//GPIO_ClearOutBits(HT_GPIOA,GPIO_PIN_1)
#define SDA_HIGH() OUT_PA1_HIGH//GPIO_SetOutBits(HT_GPIOA,GPIO_PIN_1)
#define SCL_LOW() OUT_PA0_LOW//GPIO_ClearOutBits(HT_GPIOA,GPIO_PIN_0)
#define SCL_HIGH() OUT_PA0_HIGH//GPIO_SetOutBits(HT_GPIOA,GPIO_PIN_0)
#define _nop_() delayy(1)

//-----------------------------------------------------------------------------
void   start_bit(void);                 //MLX90614 ????'?????? 
void   stop_bit(void);                 //MLX90614???????????? 
unsigned char  rx_byte(void);              //MLX90614 ???????????? 
void   send_bit(void);             //MLX90614?????????? 
void   tx_byte(unsigned char dat_byte);     //MLX90614 ???????????? 
void   receive_bit(void);           //MLX90614?????????? 
unsigned int   memread(void);    
unsigned char temperature_measurement(void);
//-----------------------------------------------------------------------------
#endif
