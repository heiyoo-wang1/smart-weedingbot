#ifndef __LED_H
#define __LED_H
#include "sys.h"

//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	


//LED�˿ڶ���
#define LED0 PFout(9)	// DS0    
#define LED1 PFout(10)	// DS1	 PUL
#define LED2 PFout(8)	// DS1			DIR
#define PUL1 PFout(7)	// DS1
#define DIR1 PFout(6)	// DS1
#define PUL2 PFout(5)	// DS1
#define DIR2 PFout(4)	// DS1

#define PUL3 PFout(11)	// DS1
#define DIR3 PFout(12)	// DS1
#define PUL4 PFout(13)	// DS1
#define DIR4 PFout(14)	// DS1

#define DCF11 PBout(1)	// DS1
#define DCF12 PBout(2)	// DS1
#define DCF21 PBout(3)	// DS1
#define DCF22 PBout(4)	// DS1
#define DCF31 PBout(5)	// DS1
#define DCF32 PBout(7)	// DS1
void LED_Init(void);//��ʼ��		 				    
#endif
