#ifndef __STMFLASH_H__
#define __STMFLASH_H__
#include "stm32f10x.h"  


//////////////////////////////////////////////////////////////////////////////////////////////////////
//�û������Լ�����Ҫ����
#define STM32_FLASH_SIZE 128 	 		//��ѡSTM32��FLASH������С(��λΪK)
#define STM32_FLASH_WREN 1              //ʹ��FLASHд��(0��������;1��ʹ��)
//////////////////////////////////////////////////////////////////////////////////////////////////////

//FLASH��ʼ��ַ
#define STM32_FLASH_BASE 0x08000000 	//STM32 FLASH����ʼ��ַ
//FLASH������ֵ

#define FLASH_NEW_APP_ADDR		0x08012000  	//NEW APP ADDR

#define APP_UPDATE_FW_VER_ADDR_OFFSET  4     //�ļ�ͷ�ļ��汾ƫ��
#define APP_UPDATE_FW_SIZE_ADDR_OFFSET  8    //�ļ�ͷ�ļ���Сƫ��
#define APP_UPDATE_FLAG_ADDR_OFFSET  12    //�ļ�ͷ��־λƫ��
#define APP_UPDATE_SUM_ADDR_OFFSET  14    //�ļ�ͷSUMƫ��

#define APP_UPDATE_FLAG_SET    0x1111
#define APP_UPDATE_FLAG_CLEAER 0x0000

#define UPDATE_PKG_MAX_SIZE  1024
//u16 iapbuf[1024];
 

u16 STMFLASH_ReadHalfWord(u32 faddr);		  //��������  
void STMFLASH_WriteLenByte(u32 WriteAddr,u32 DataToWrite,u16 Len);	//ָ����ַ��ʼд��ָ�����ȵ�����
u32 STMFLASH_ReadLenByte(u32 ReadAddr,u16 Len);						//ָ����ַ��ʼ��ȡָ����������
void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite);		//��ָ����ַ��ʼд��ָ�����ȵ�����
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead);   		//��ָ����ַ��ʼ����ָ�����ȵ�����

void write_app(u32 appxaddr,u8 *appbuf,u32 appsize);
void SoftReset(void);
							   
#endif

















