#ifndef __STMFLASH_H__
#define __STMFLASH_H__
#include "stm32f10x.h"  


//////////////////////////////////////////////////////////////////////////////////////////////////////
//用户根据自己的需要设置
#define STM32_FLASH_SIZE 128 	 		//所选STM32的FLASH容量大小(单位为K)
#define STM32_FLASH_WREN 1              //使能FLASH写入(0，不是能;1，使能)
//////////////////////////////////////////////////////////////////////////////////////////////////////

//FLASH起始地址
#define STM32_FLASH_BASE 0x08000000 	//STM32 FLASH的起始地址
//FLASH解锁键值

#define FLASH_NEW_APP_ADDR		0x08012000  	//NEW APP ADDR

#define APP_UPDATE_FW_VER_ADDR_OFFSET  4     //文件头文件版本偏移
#define APP_UPDATE_FW_SIZE_ADDR_OFFSET  8    //文件头文件大小偏移
#define APP_UPDATE_FLAG_ADDR_OFFSET  12    //文件头标志位偏移
#define APP_UPDATE_SUM_ADDR_OFFSET  14    //文件头SUM偏移

#define APP_UPDATE_FLAG_SET    0x1111
#define APP_UPDATE_FLAG_CLEAER 0x0000

#define UPDATE_PKG_MAX_SIZE  1024
//u16 iapbuf[1024];
 

u16 STMFLASH_ReadHalfWord(u32 faddr);		  //读出半字  
void STMFLASH_WriteLenByte(u32 WriteAddr,u32 DataToWrite,u16 Len);	//指定地址开始写入指定长度的数据
u32 STMFLASH_ReadLenByte(u32 ReadAddr,u16 Len);						//指定地址开始读取指定长度数据
void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite);		//从指定地址开始写入指定长度的数据
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead);   		//从指定地址开始读出指定长度的数据

void write_app(u32 appxaddr,u8 *appbuf,u32 appsize);
void SoftReset(void);
							   
#endif

















