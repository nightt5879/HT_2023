/*********************************************************************************************************//**
 * @file    spi_lcd.h
 * @version $Rev:: 4216         $
 * @date    $Date:: 2019-09-12 #$
 * @brief   The header file of spi_lcd.c module.
 *************************************************************************************************************
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

/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __SPI_LCD_H
#define __SPI_LCD_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32_board.h"
#include "lcd.h"

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup Common
  * @{
  */

/** @addtogroup SPI_LCD SPI_LCD
  * @{
  */


/* Exported constants --------------------------------------------------------------------------------------*/
/** @defgroup SPI_LCD_Exported_Constants SPI LCD exported constants
  * @{
  */

#define START_BYTE      0x70
#define SET_INDEX       0x00
#define READ_STATUS     0x01
#define LCD_WRITE_REG   0x02
#define LCD_READ_REG    0x03

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------------------------------------*/
/** @defgroup SPI_Exported_Macros SPI LCD exported macro
  * @{
  */
#if defined(USE_HT32F52230_SK) || defined(USE_HT32F0008_SK) || defined(USE_HT32F57341_SK) || defined(USE_HT32F57352_SK)
  #define LCD_SEL_CMD_INACTIVE()    GPIO_SetOutBits(GPIO_PORT[LCD_SPI_SEL_GPIO_ID], LCD_SPI_SEL_AFIO_PIN)
  #define LCD_SEL_CMD_ACTIVE()      GPIO_ClearOutBits(GPIO_PORT[LCD_SPI_SEL_GPIO_ID], LCD_SPI_SEL_AFIO_PIN)
#else
  #define LCD_SEL_CMD_INACTIVE()    SPI_SoftwareSELCmd(LCD_SPI, SPI_SEL_INACTIVE)
  #define LCD_SEL_CMD_ACTIVE()      SPI_SoftwareSELCmd(LCD_SPI, SPI_SEL_ACTIVE)
#endif

/**
  * @}
  */

/* Exported functions --------------------------------------------------------------------------------------*/
/** @defgroup SPI_LCD_Exported_Functions SPI LCD exported functions
  * @{
  */
void LCD_Init(void);
void LCD_Config(void);
void LCD_WriteReg(u32 LCD_Reg_Index, u32 LCD_Reg_Value);
void LCD_StarterSet(u32 X_Location, u32 Y_Location);
void LCD_WriteRAMPrior(void);
void LCD_WriteRAM(u32 RGB_Set);
void LCD_Clear(u16 Color);
void LCD_BackColorSet(u16 Color);
void LCD_TextColorSet(u16 Color);
void LCD_CharDisplay(u32 Line_Num, u32 Column, u32 Ascii);
void LCD_DisplayOff(void);
void LCD_DisplayOn(void);
void LCD_StringLineDisplay(u32 Line_Num, char *Sptr);
void LCD_CharDraw(u32 X_Location, u32 Y_Location, u16 *Cptr);
void LCD_LineDraw(u32 X_Location, u32 Y_Location, u32 Length, u32 Direction);
void LCD_CircleDraw(u32 X_Location, u32 Y_Location, u32 Radius);
void LCD_RectDraw(u32 X_Location, u32 Y_Location, u32 Height, u32 Width);
void LCD_PicDraw(u8 X_Location, u16 Y_Location, u8 Height, u16 Width, uc8 *Pptr);
void LCD_WriteRAMWord(u32 RGB_Set);
void LCD_SetDisplayArea(u16 Column, u16 Page, u16 Height, u16 Width);
void LCD_WriteRegIndex(u32 LCD_Reg_Index);
u16  LCD_ReadReg(u32 LCD_Reg_Index);
/**
  * @}
  */


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif
