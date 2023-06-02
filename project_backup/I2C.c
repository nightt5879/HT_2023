#include "I2C.h"
#include "GPIO.h"




u8 bit_in,bit_out;
unsigned char DataH,DataL,Pecreg; 
//************************************

void delayy(u32 count) //__nop == 1/48us?
{
	unsigned int i;
  while (count--)
  {
	  for(i = 0;i<3;i++){
    __NOP(); // Prevent delay loop be optimized
	  }
  }
}

void   start_bit(void) 
{ 
	SDA_HIGH();
//   SDA=1; 
   _nop_();_nop_();_nop_();_nop_();_nop_(); 
	SCL_HIGH();
//   SCL=1; 
   _nop_();_nop_();_nop_();_nop_();_nop_();
SDA_LOW();	
//   SDA=0; 
   _nop_();_nop_();_nop_();_nop_();_nop_(); 
	SCL_LOW();
//   SCL=0; 
   _nop_();_nop_();_nop_();_nop_();_nop_(); 
 
} 
//------------------------------ 
void   stop_bit(void) 
{ 
	SCL_LOW();
//   SCL=0; 
   _nop_();_nop_();_nop_();_nop_();_nop_();
SDA_LOW();	
//   SDA=0; 
   _nop_();_nop_();_nop_();_nop_();_nop_(); 
	SCL_HIGH();
//   SCL=1; 
   _nop_();_nop_();_nop_();_nop_();_nop_(); 
	SDA_HIGH();
//   SDA=1; 
} 
//--------- ????h?????--------- 
void  tx_byte(unsigned char dat_byte) 
{ 
   unsigned char i,n,dat; 
   n=10; 
TX_again: 
   dat=dat_byte; 
   for(i=0;i<8;i++) 
   { 
     if(dat&0x80) 
      bit_out=1; 
     else 
      bit_out=0; 
     send_bit(); 
     dat=dat<<1; 
   } 
   
      receive_bit(); 
   if(bit_in==1) 
   { 
    stop_bit(); 
    if(n!=0) 
    {n--;goto Repeat;} 
    else 
//		printf(" no answer ");
     goto exit; 
   } 
   else 
//	   printf(" answering ");
    goto exit; 
Repeat: 
    start_bit(); 
    goto TX_again; 
exit: ; 
} 
//-----------????h???--------- 
void  send_bit(void) 
{ 
  if(bit_out==0) 
	  SDA_LOW();
//       SDA=0; 
  else 
	  SDA_HIGH();
//     SDA=1; 
  _nop_(); 
  SCL_HIGH();
//  SCL=1; 
  _nop_();_nop_();_nop_();_nop_(); 
  _nop_();_nop_();_nop_();_nop_(); 
  SCL_LOW();
//  SCL=0; 
  _nop_();_nop_();_nop_();_nop_(); 
  _nop_();_nop_();_nop_();_nop_(); 
} 
//---------- ????h?????-------- 
unsigned char rx_byte(void) 
{ 
  unsigned char i,dat; 
  dat=0; 
  for(i=0;i<8;i++) 
  { 
    dat=dat<<1; 
    receive_bit(); 
    if(bit_in==1) 
     dat=dat+1; 
  } 
  send_bit(); 
  return dat; 
} 

//---------- ????h???---------- 
void receive_bit(void) 
{ 
	SDA_HIGH();
	
		GPIO_InputConfig(OUT_PA1_GPIO_PORT,OUT_PA1_GPIO_PIN, ENABLE);
GPIO_DirectionConfig(OUT_PA1_GPIO_PORT, OUT_PA1_GPIO_PIN, GPIO_DIR_IN);
//  SDA=1;
	bit_in=1;
SCL_HIGH();	
//  SCL=1; 
  _nop_();_nop_();_nop_();_nop_(); 
  _nop_();_nop_();_nop_();_nop_(); 
	 if(GPIO_ReadInBit(OUT_PA1_GPIO_PORT, OUT_PA1_GPIO_PIN))
	 {
		 bit_in =1;
//	printf("in");
	 }
	else bit_in = 0;
//  bit_in=SDA;
GPIO_InputConfig(OUT_PA1_GPIO_PORT,OUT_PA1_GPIO_PIN, DISABLE);	
GPIO_DirectionConfig(OUT_PA1_GPIO_PORT, OUT_PA1_GPIO_PIN, GPIO_DIR_OUT);	
  _nop_(); 
	SCL_LOW();
//  SCL=0; 
  _nop_();_nop_();_nop_();_nop_(); 
  _nop_();_nop_();_nop_();_nop_(); 
} 
//------------ ???-------------- 
void   delay(int N) 
{ 
  unsigned int i; 
  for(i=0;i<N;i++) 
  
     _nop_(); 
} 
//------------------------------ 
unsigned int memread(void) 
{ 
  start_bit(); 
  tx_byte(0x00);  //Send SlaveAddress ==============================
	
//  //tx_byte(0x00); 
  tx_byte(0x07);  //Send Command 
//  //------------ 
  start_bit(); 
  tx_byte(0x01); 
	
  bit_out=0; 
  DataL=rx_byte(); 
  bit_out=0; 
  DataH=rx_byte(); 
  bit_out=1; 
  Pecreg=rx_byte(); 
  stop_bit(); 
  return(DataH*256+DataL); 
} 

unsigned char temperature_measurement(void)
{
	u32 tem;
	unsigned char t;
	tem =  memread();
	t = (tem/5) - 2930;  // 20 a starting point with 20 degrees as 0
//		temm += 15;  //correcting 1.5 degrees
//	tem_low = tem & 0x00FF;
//	tem_high = (tem & 0xFF00) >> 8;
	return t;
}
