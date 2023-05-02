/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2016        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "ff.h"			/* Obtains integer types */
#include "diskio.h"		/* Declarations of disk functions */
#include "ht32.h"
#include "sdio_sd.h"

/* Definitions of physical drive number for each drive */
#define DEV_RAM		0	/* Example: Map Ramdisk to physical drive 0 */
#define DEV_MMC		1	/* Example: Map MMC/SD card to physical drive 1 */
#define DEV_USB		2	/* Example: Map USB MSD to physical drive 2 */

static volatile DSTATUS DiskState = STA_NOINIT;  /* Disk status                                             */
u32 last_disk_read_address;

/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/
DSTATUS disk_status (
	BYTE pdrv		/* Physical drive nmuber to identify the drive */
)
{
  if (pdrv != 0)
    return STA_NOINIT;

  return DiskState;
}

/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/
DSTATUS disk_initialize (
	BYTE pdrv				/* Physical drive nmuber to identify the drive */
)
{
  if (pdrv != 0)
    return STA_NOINIT;

  DiskState &= ~STA_NOINIT;
  return DiskState;
}

/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/
DRESULT disk_read (
	BYTE pdrv,		/* Physical drive nmuber to identify the drive */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Start sector in LBA */
	UINT count		/* Number of sectors to read */
)
{
  DWORD addr = 0;

  if (pdrv != 0)
    return RES_PARERR;
  if (count == 0)
    return RES_PARERR;
  if (DiskState & STA_NOINIT)
    return RES_NOTRDY;

  addr = sector * 512;

  last_disk_read_address = addr;
//  SPI_FLASH_BufferRead(buff, addr, count * 512); //spi flash
//  memcpy(buff, (u8 *)addr, count * 512);         //rom flash
  SD_ReadBlock(buff, addr, count * 512);           //sd card
  count = 0;

  return (count ? RES_ERROR : RES_OK);
}


/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if FF_FS_READONLY == 0

DRESULT disk_write (
	BYTE pdrv,			/* Physical drive nmuber to identify the drive */
	const BYTE *buff,	/* Data to be written */
	DWORD sector,		/* Start sector in LBA */
	UINT count			/* Number of sectors to write */
)
{
  DWORD addr = 0;

  if (pdrv != 0)
    return RES_PARERR;
  if (count == 0)
    return RES_PARERR;
  if (DiskState & STA_NOINIT)
    return RES_NOTRDY;
  if (DiskState & STA_PROTECT)
    return RES_WRPRT;

  addr = sector * 512;

//  SPI_FLASH_BufferWrite((u8 *)buff,addr,count*512);  //spi flash
//  for(i = 0; i < count*512; i += 4)
//  {
//    if((addr & 0x1FF) == 0x00)
//      FLASH_ErasePage(addr);
//    FLASH_ProgramWordData(addr, *buff++);       //rom flash
//    addr += 4;
//  }    
  
  SD_WriteBlock((u8 *)buff,addr,count*512);            //sd card

  count = 0;

  return (count ? RES_ERROR : RES_OK);
}

#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

DRESULT disk_ioctl (
	BYTE pdrv,		/* Physical drive nmuber (0..) */
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{
  DRESULT result = RES_ERROR;
  
  if (pdrv != 0)
    return RES_PARERR;
  if (DiskState & STA_NOINIT)
    return RES_NOTRDY;

  switch (cmd)
  {
    case CTRL_SYNC:
    {        
      result = RES_OK;
      break;
    }
    case GET_SECTOR_SIZE:
    {
      *(WORD*) buff = 512;
      result = RES_OK;
      break;
    }
    case GET_SECTOR_COUNT:
    {
      
     *(WORD*) buff = 32768;          
      result = RES_OK;        
      break;
    }
    case GET_BLOCK_SIZE: 
    {
      
      *(WORD*) buff = 512;
      result = RES_OK;
      
      break;
    }
    default:
    {
      result = RES_PARERR;
    }
  }
	return result;
}

/*********************************************************************************************************//**
  * @brief  Get FAT time.
  * @retval Always 0 (Not implement)
  ***********************************************************************************************************/
DWORD get_fattime(void)
{
  return 0;
}
