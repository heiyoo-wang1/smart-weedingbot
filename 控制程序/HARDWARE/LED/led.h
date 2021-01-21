#ifndef __LED_H
#define __LED_H
#include "sys.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//LED驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	


//LED端口定义
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
void LED_Init(void);//初始化		 				    
#endif
