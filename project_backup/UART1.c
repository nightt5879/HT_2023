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
#include "UART1.h"

//-----------------------------------------------------------------------------
__ALIGN4 _UART1_STRUCT rxd_comm1;
__ALIGN4 _UART1_STRUCT txd_comm1;

//-----------------------------------------------------------------------------
void UART1_Configuration(void)
{
  USART_InitTypeDef USART_InitStruct;
  CKCU_PeripClockConfig_TypeDef CKCUClock = {{0}};
  CKCUClock.Bit.UART1   = 1;
  CKCUClock.Bit.AFIO    = 1;
  CKCU_PeripClockConfig(CKCUClock, ENABLE);

  AFIO_GPxConfig(GPIO_PC, AFIO_PIN_12, AFIO_FUN_USART_UART);  // Config AFIO mode

  USART_InitStruct.USART_BaudRate = 115200;
  USART_InitStruct.USART_WordLength = USART_WORDLENGTH_8B;
  USART_InitStruct.USART_StopBits = USART_STOPBITS_1;
  USART_InitStruct.USART_Parity = USART_PARITY_NO;
  USART_InitStruct.USART_Mode = USART_MODE_NORMAL;
  USART_Init(HT_UART1, &USART_InitStruct);
  USART_RxCmd(HT_UART1, ENABLE);
  USART_TxCmd(HT_UART1, ENABLE);

  USART_IntConfig(HT_UART1, USART_INT_RXDR, ENABLE);

  NVIC_EnableIRQ(UART1_IRQn);
  UART1_init_buffer();
}

//-----------------------------------------------------------------------------
void UART1_init_buffer (void)
{
  rxd_comm1.read_pt = 0;
  rxd_comm1.write_pt = 0;
  rxd_comm1.cnt = 0;

  txd_comm1.read_pt = 0;
  txd_comm1.write_pt = 0;
  txd_comm1.cnt = 0;
}

//-----------------------------------------------------------------------------
void UART1_IRQHandler(void)
{
  // Tx, move data from buffer to UART FIFO
  if ((HT_UART1->SR) & USART_FLAG_TXC)
  {
    if (!txd_comm1.cnt)
    {
      USART_IntConfig(HT_UART1, USART_INT_TXC, DISABLE);
    }
    else
    {
      u16 i;
      for (i = 0; i < UART1_FIFO_LEN; i++)   //have FIFO?
      {
        USART_SendData(HT_UART1, txd_comm1.buffer[txd_comm1.read_pt]);
        txd_comm1.read_pt = (txd_comm1.read_pt + 1) % UART1_BUF_SIZE;
        txd_comm1.cnt--;
        if (!txd_comm1.cnt)
          break;
      }
    }
  }

  // Rx, move data from UART FIFO to buffer
  if ((HT_UART1->SR) & USART_FLAG_RXDR )
  {
    rxd_comm1.buffer[rxd_comm1.write_pt] = USART_ReceiveData(HT_UART1);

    rxd_comm1.write_pt = (rxd_comm1.write_pt + 1) % UART1_BUF_SIZE;
    rxd_comm1.cnt++;
  }
}

//-----------------------------------------------------------------------------
void UART1_analyze_data(void)
{
  u8 tmp;
  if(!rxd_comm1.cnt)
    return;

  //...to be add
  tmp = rxd_comm1.buffer[rxd_comm1.read_pt];
  if( (tmp != 0xAA) )            //for example
  {
    NVIC_DisableIRQ(UART1_IRQn);
    rxd_comm1.cnt--;  //throw invalid data
    NVIC_EnableIRQ(UART1_IRQn);
    rxd_comm1.read_pt = (rxd_comm1.read_pt + 1) % UART1_BUF_SIZE;
    return;
  }
  else if(rxd_comm1.cnt >= 8)    //for example
  {
    //add your code here

  }
}

//-----------------------------------------------------------------------------
void UART1_tx_data(u8 *pt, u8 len)
{
  while(len--)
  {
    txd_comm1.buffer[txd_comm1.write_pt] = *pt++;
    txd_comm1.write_pt = (txd_comm1.write_pt + 1) % UART1_BUF_SIZE;
    NVIC_DisableIRQ(UART1_IRQn);
    txd_comm1.cnt++;
    NVIC_EnableIRQ(UART1_IRQn);
  }

  if(txd_comm1.cnt)
    USART_IntConfig(HT_UART1,  USART_INT_TXC , ENABLE);
}

//-----------------------------------------------------------------------------
void UART1_test(void)
{
  u8 i,test_array[8];
  for(i=0; i<8; i++)
  {
    test_array[i] = i;
  }
  UART1_tx_data(test_array, 8);
}

//-----------------------------------------------------------------------------


