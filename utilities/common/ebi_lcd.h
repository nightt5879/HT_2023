/*********************************************************************************************************//**
 * @file    ebi_lcd.h
 * @version $Rev:: 4216         $
 * @date    $Date:: 2019-09-12 #$
 * @brief   The header file of ebi_lcd.c module.
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
#ifndef __EBI_LCD_H
#define __EBI_LCD_H

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

/** @addtogroup EBI_LCD EBI_LCD
  * @{
  */

/* Settings ------------------------------------------------------------------------------------------------*/
#define LCD_08_BIT_MODE               (8)
#define LCD_16_BIT_MODE               (16)

#define SPIDUALOUT_WITH_EBI_8BIT_MODE (0)
// Note: Connect RS to EBI_An if you want to use SPI dual output with EBI 8-bit mode (For default RS is EBI_A0)

#ifndef LCD_BIT_MODE
#define LCD_BIT_MODE                  (LCD_16_BIT_MODE)
#endif

/* Exported types ------------------------------------------------------------------------------------------*/
/** @defgroup EBI_LCD_Exported_Types EBI LCD exported types
  * @{
  */
#if (LCD_BIT_MODE == LCD_16_BIT_MODE)
  typedef struct
  {
    vu16 EBI_LCD_REG;
    #if (LCD_EBI_RS_ADDR_PIN)
    vu16 _RESERVED[(0x1ul << LCD_EBI_RS_ADDR_PIN) - 1];
    #endif
    vu16 EBI_LCD_RAM;
  } EBI_LCD_TypeDef;
#elif ((LCD_BIT_MODE == LCD_08_BIT_MODE) && (SPIDUALOUT_WITH_EBI_8BIT_MODE == 1))
  typedef struct
  {
    vu8 EBI_LCD_REG;
    #if (LCD_EBI_RS1_ADDR_PIN)
    vu8 _RESERVED[(0x1ul << LCD_EBI_RS1_ADDR_PIN) - 1];
    #endif
    vu8 EBI_LCD_RAM;
  } EBI_LCD_TypeDef;
#else
  typedef struct
  {
    vu8 EBI_LCD_REG;
    #if (LCD_EBI_RS_ADDR_PIN)
    vu8 _RESERVED[(0x1ul << LCD_EBI_RS_ADDR_PIN) - 1];
    #endif
    vu8 EBI_LCD_RAM;
  } EBI_LCD_TypeDef;
#endif
/**
  * @}
  */

/* Exported constants --------------------------------------------------------------------------------------*/
/** @defgroup EBI_LCD_Exported_Constants EBI LCD exported constants
  * @{
  */
#define LCD_Bank_ADDR             0x60000000
#define EBI_LCD                  ((EBI_LCD_TypeDef *) LCD_Bank_ADDR)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------------------------------------*/
/** @defgroup EBI_LCD_Exported_Functions EBI LCD exported functions
  * @{
  */
void LCD_Init(void);
void LCD_Config(void);
void LCD_WriteReg(u32 LCD_Reg_Index, u32 LCD_Reg_Value);
u16 LCD_ReadReg(u32 LCD_Reg_Index);
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
