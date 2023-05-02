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
#include "UART0.h"

//-----------------------------------------------------------------------------
__ALIGN4 _UART0_STRUCT rxd_comm0;
__ALIGN4 _UART0_STRUCT txd_comm0;

//-----------------------------------------------------------------------------
void UART0_Configuration(void)
{
  USART_InitTypeDef USART_InitStruct;
  CKCU_PeripClockConfig_TypeDef CKCUClock = {{0}};
  CKCUClock.Bit.UART0   = 1;
  CKCUClock.Bit.AFIO    = 1;
  CKCU_PeripClockConfig(CKCUClock, ENABLE);

  AFIO_GPxConfig(GPIO_PC, AFIO_PIN_4, AFIO_FUN_USART_UART);  // Config AFIO mode
  AFIO_GPxConfig(GPIO_PC, AFIO_PIN_5, AFIO_FUN_USART_UART);  // Config AFIO mode

  USART_InitStruct.USART_BaudRate = 115200;
  USART_InitStruct.USART_WordLength = USART_WORDLENGTH_8B;
  USART_InitStruct.USART_StopBits = USART_STOPBITS_1;
  USART_InitStruct.USART_Parity = USART_PARITY_NO;
  USART_InitStruct.USART_Mode = USART_MODE_NORMAL;
  USART_Init(HT_UART0, &USART_InitStruct);
  USART_RxCmd(HT_UART0, ENABLE);
  USART_TxCmd(HT_UART0, ENABLE);

  USART_IntConfig(HT_UART0, USART_INT_RXDR, ENABLE);

  NVIC_EnableIRQ(UART0_IRQn);
  UART0_init_buffer();
}

//-----------------------------------------------------------------------------
void UART0_init_buffer (void)
{
  rxd_comm0.read_pt = 0;
  rxd_comm0.write_pt = 0;
  rxd_comm0.cnt = 0;

  txd_comm0.read_pt = 0;
  txd_comm0.write_pt = 0;
  txd_comm0.cnt = 0;
}

//-----------------------------------------------------------------------------
void UART0_IRQHandler(void)
{
  // Tx, move data from buffer to UART FIFO
  if ((HT_UART0->SR) & USART_FLAG_TXC)
  {
    if (!txd_comm0.cnt)
    {
      USART_IntConfig(HT_UART0, USART_INT_TXC, DISABLE);
    }
    else
    {
      u16 i;
      for (i = 0; i < UART0_FIFO_LEN; i++)   //have FIFO?
      {
        USART_SendData(HT_UART0, txd_comm0.buffer[txd_comm0.read_pt]);
        txd_comm0.read_pt = (txd_comm0.read_pt + 1) % UART0_BUF_SIZE;
        txd_comm0.cnt--;
        if (!txd_comm0.cnt)
          break;
      }
    }
  }

  // Rx, move data from UART FIFO to buffer
  if ((HT_UART0->SR) & USART_FLAG_RXDR )
  {
    rxd_comm0.buffer[rxd_comm0.write_pt] = USART_ReceiveData(HT_UART0);

    rxd_comm0.write_pt = (rxd_comm0.write_pt + 1) % UART0_BUF_SIZE;
    rxd_comm0.cnt++;
  }
}

//-----------------------------------------------------------------------------
unsigned char UART0_analyze_data(void)
{
	u8 pos = rxd_comm0.read_pt;
//	if (rxd_comm0.cnt < 4) //  If less than four bytes, it is not necessary.
//		return ERR_SERIAL;

  // 0x00, 0x00, 0x01, 0x02

  if (rxd_comm0.buffer[pos] == 0x00 && 
      rxd_comm0.buffer[(pos + 1) % UART0_BUF_SIZE] == 0x03 &&
      rxd_comm0.buffer[(pos + 2) % UART0_BUF_SIZE] == 0x01 && //face detect success
      rxd_comm0.buffer[(pos + 3) % UART0_BUF_SIZE] == 0x00)
  {

    // Update the reading position and counter of the receive buffer.
    NVIC_DisableIRQ(UART0_IRQn);
    rxd_comm0.read_pt = (rxd_comm0.read_pt + 4) % UART0_BUF_SIZE;
    rxd_comm0.cnt -= 4;
    NVIC_EnableIRQ(UART0_IRQn);
		return FACE_SUCCESS;
  }
   else if (rxd_comm0.buffer[pos] == 0x00 && 
      rxd_comm0.buffer[(pos + 1) % UART0_BUF_SIZE] == 0x03 &&
      rxd_comm0.buffer[(pos + 2) % UART0_BUF_SIZE] == 0x00 && //face detect failure
      rxd_comm0.buffer[(pos + 3) % UART0_BUF_SIZE] == 0x00)
  {
    // Update the reading position and counter of the receive buffer.
    NVIC_DisableIRQ(UART0_IRQn);
    rxd_comm0.read_pt = (rxd_comm0.read_pt + 4) % UART0_BUF_SIZE;
    rxd_comm0.cnt -= 4;
    NVIC_EnableIRQ(UART0_IRQn);
		return FACE_FAILURE;
  }
  return 0;
//  else
//  {
//    // If the received byte does not meet the requirements, increase the reading position by 1 and discard one byte
//    NVIC_DisableIRQ(UART0_IRQn);
//    rxd_comm0.read_pt = (rxd_comm0.read_pt + 1) % UART0_BUF_SIZE;
//    rxd_comm0.cnt--;
//    NVIC_EnableIRQ(UART0_IRQn);
//	return ERR_SERIAL;
//  }

}

//-----------------------------------------------------------------------------
void UART0_tx_data(u8 *pt, u8 len)
{
  while(len--)
  {
    txd_comm0.buffer[txd_comm0.write_pt] = *pt++;
    txd_comm0.write_pt = (txd_comm0.write_pt + 1) % UART0_BUF_SIZE;
    NVIC_DisableIRQ(UART0_IRQn);
    txd_comm0.cnt++;
    NVIC_EnableIRQ(UART0_IRQn);
  }

  if(txd_comm0.cnt)
    USART_IntConfig(HT_UART0,  USART_INT_TXC , ENABLE);
}

//-----------------------------------------------------------------------------
void UART0_test(void)
{
  u8 i,test_array[8];
  for(i=0; i<8; i++)
  {
    test_array[i] = i;
  }
  UART0_tx_data(test_array, 8);
}

//-----------------------------------------------------------------------------


