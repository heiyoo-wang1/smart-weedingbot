#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "led.h" 
#include "AT24Cxx.h"
#include "iic.h"
#include "usart.h"	
#include "timer.h"
#define uchar unsigned char
const unsigned char at_9[10]={'0','1','2','3','4','5','6','7','8','9'};

//ALIENTEK 探索者STM32F407开发板 实验0
//STM32F4工程模板-库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK

//void MY_USART1_Init(void)
//{
//	GPIO_InitTypeDef  GPIO_InitStructure;
//	USART_InitTypeDef  USART_InitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);//使能USART1时钟
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
//	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1);
//	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1);
//	
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 ;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//  GPIO_Init(GPIOA, &GPIO_InitStructure);
//	
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 ;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//  GPIO_Init(GPIOA, &GPIO_InitStructure);
//	
//	USART_InitStructure.USART_BaudRate=115200;//波特率
//	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;//硬件流控制（不使用）
//	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;//使能发送和接收
//	USART_InitStructure.USART_Parity=USART_Parity_No;//奇偶校验（不使用）
//	USART_InitStructure.USART_StopBits=USART_StopBits_1;//停止位(一个)
//	USART_InitStructure.USART_WordLength=USART_WordLength_8b;//字长(8位)
//	USART_Init(USART1,&USART_InitStructure);
//	USART_Cmd(USART1,ENABLE);//串口使能
//	
//	USART_ITConfig(USART1,USART_IT_RXNE/*使能接收非空*/,ENABLE); 
//	//中断优先级
//	NVIC_InitStructure.NVIC_IRQChannel=USART1_IRQn;//通道
//	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
//	NVIC_Init(&NVIC_InitStructure);
//}
u8 BZ2,CF1,CF2,CF3;
float BZ6,BZ7,BZ3,BZ9,D2CF4,D2CF3;
u32 BZ1,BZ8,C1F,C2F,C3F;
u8 BZ4,BZ5,ZF,BZ10;
u8 DCF2,D1CF1,D2CF2;
u8 D3CF1,D3CF3;
u8 CC;
u8 BL,BL1,BL2,BL3,BL4;
float D1CF2,D3CF2,D3CF4,D3CF5;


extern u8  TIM10CH1_CAPTURE_STA;		//输入捕获状态		    				
extern u32	TIM10CH1_CAPTURE_VAL;	//输入捕获值  
 
 
 u8 BBZ4,BBZ6;


void USART3_IRQHandler(void)
{
	u8 RES1;	    
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)//接收到数据
	{	 
		RES1 =USART_ReceiveData(USART3);//(UART4->DR);	//读取接收到的数据
	//	USART_SendData(USART1,RES1);
   			//////******delay****///////////
		if(BBZ4==1)
		{
		if(RES1!=0x0A&&BBZ6==3)
			BBZ6=0;
		if(RES1==0x0A&&BBZ6==3)
			BBZ6++;
		if(RES1!=0x0D&&BBZ6==2)
			BBZ6=0;
		if(RES1==0x0D&&BBZ6==2)
			BBZ6++;
		if(RES1!='K'&&BBZ6==1)
			BBZ6=0;
		if(RES1=='K'&&BBZ6==1)
			BBZ6++;
		if(RES1=='O'&&BBZ6==0)
			BBZ6++;
	}
	}										 
}  
u32 AAA;
void delay(void)
{
			BBZ4=1;
			while(1)
			{
				//LED1=!LED1;
				if(BBZ6==4)
				{
					delay_ms(10);
					if(BBZ6==4)
						
				{
					BBZ6=0;
					BBZ4=0;
					break;
				}
				}
				AAA++;
				delay_ms(100);
				if(AAA>600)
				{
						//AAA=0;
					break;
				}
			}
}
 u8 wwww;

void USART1_IRQHandler(void)//中断服务函数
{
	
	if(USART_GetITStatus(USART1,USART_IT_RXNE))//判断串口1是否发生中断,判断是否为USART_IT_RXNE中断类型
	{
		//BZ2=1;
//			CC=USART_ReceiveData(USART1);
//			USART_SendData(UART4,CC);
		wwww=USART_ReceiveData(USART1);
		USART_SendData(USART1,wwww);
		 
		if(ZF!=1&&ZF!=2)
		{
		BZ10=USART_ReceiveData(USART1);
			
			if(BL==1)
			{
				if(BZ10=='0')	{TIM_SetCompare1(TIM14,240);		delay_ms(50);		TIM_SetCompare1(TIM14,2400);}	//修改比较值，修改占空比
				if(BZ10=='1')	{TIM_SetCompare1(TIM14,480);		delay_ms(50);		TIM_SetCompare1(TIM14,2400);}	//修改比较值，修改占空比
				if(BZ10=='2')	{TIM_SetCompare1(TIM14,720);		delay_ms(50);		TIM_SetCompare1(TIM14,2400);}	//修改比较值，修改占空比
				if(BZ10=='3')	{TIM_SetCompare1(TIM14,960);		delay_ms(50);		TIM_SetCompare1(TIM14,2400);}	//修改比较值，修改占空比
				if(BZ10=='4')	{TIM_SetCompare1(TIM14,1200);		delay_ms(50);		TIM_SetCompare1(TIM14,2400);}	//修改比较值，修改占空比
				if(BZ10=='5')	{TIM_SetCompare1(TIM14,1440);		delay_ms(50);		TIM_SetCompare1(TIM14,2400);}	//修改比较值，修改占空比
				if(BZ10=='6')	{TIM_SetCompare1(TIM14,1920);		delay_ms(50);		TIM_SetCompare1(TIM14,2400);}	//修改比较值，修改占空比
				if(BZ10=='7')	{TIM_SetCompare1(TIM14,2040);		delay_ms(50);		TIM_SetCompare1(TIM14,2400);}	//修改比较值，修改占空比
				if(BZ10=='8')	{TIM_SetCompare1(TIM14,2160);		delay_ms(50);		TIM_SetCompare1(TIM14,2400);}	//修改比较值，修改占空比
				if(BZ10=='9')	{TIM_SetCompare1(TIM14,0); 	delay_ms(100);		TIM_SetCompare1(TIM14,2400);}	//修改比较值，修改占空比
				BL=0;
			}
			if(BZ10=='*'&&BL==0)
			{
				BL++;
			}
			
			
			
			if(BL1==1)
			{
				if(BZ10=='0')	{TIM_SetCompare1(TIM9,240);		delay_ms(50);		TIM_SetCompare1(TIM9,2400);}	//修改比较值，修改占空比
				if(BZ10=='1')	{TIM_SetCompare1(TIM9,480);		delay_ms(50);		TIM_SetCompare1(TIM9,2400);}	//修改比较值，修改占空比
				if(BZ10=='2')	{TIM_SetCompare1(TIM9,720);		delay_ms(50);		TIM_SetCompare1(TIM9,2400);}	//修改比较值，修改占空比
				if(BZ10=='3')	{TIM_SetCompare1(TIM9,960);		delay_ms(50);		TIM_SetCompare1(TIM9,2400);}	//修改比较值，修改占空比
				if(BZ10=='4')	{TIM_SetCompare1(TIM9,1200);	delay_ms(50);		TIM_SetCompare1(TIM9,2400);}	//修改比较值，修改占空比
				if(BZ10=='5')	{TIM_SetCompare1(TIM9,1440);	delay_ms(50);		TIM_SetCompare1(TIM9,2400);}	//修改比较值，修改占空比
				if(BZ10=='6')	{TIM_SetCompare1(TIM9,1920);	delay_ms(50);		TIM_SetCompare1(TIM9,2400);}	//修改比较值，修改占空比
				if(BZ10=='7')	{TIM_SetCompare1(TIM9,2040);	delay_ms(50);		TIM_SetCompare1(TIM9,2400);}	//修改比较值，修改占空比
				if(BZ10=='8')	{TIM_SetCompare1(TIM9,2160);	delay_ms(50);		TIM_SetCompare1(TIM9,2400);}	//修改比较值，修改占空比
				if(BZ10=='9')	{TIM_SetCompare1(TIM9,0); 	delay_ms(50);		TIM_SetCompare1(TIM9,2400);}	//修改比较值，修改占空比
				BL1=0;
			}
			if(BZ10=='P'&&BL1==0)
			{
				BL1++;
			}
			
			
			if(BL2==1)
			{
				if(BZ10=='0')	{TIM_Cmd(TIM3,ENABLE); BL3=1;}	//修改比较值，修改占空比
				if(BZ10=='1')	{TIM_Cmd(TIM3,ENABLE); BL3=2;}	//修改比较值，修改占空比
				if(BZ10=='2')	{TIM_Cmd(TIM3,ENABLE); BL3=3;}	//修改比较值，修改占空比
				if(BZ10=='3')	{TIM_Cmd(TIM3,ENABLE); BL3=4;}	//修改比较值，修改占空比
				if(BZ10=='4')	{TIM_Cmd(TIM3,ENABLE); BL3=5;}	//修改比较值，修改占空比
				BL2=0;
			}
			if(BZ10=='S'&&BL2==0)
			{
				BL2++;
			}
//			USART_SendData(USART1,BZ10);
		}
		if(ZF==1)
		{
			BZ7=USART_ReceiveData(USART1);
			//USART_Cmd(USART1, DISABLE);  //使能串口1 
			//USART_SendData(USART1,BZ7);
			ZF=3;
			if(BZ2==1)
			{
//			u3_printf("%s","t1.txt=");
//			u3_printf("%c",'"');
//			//printf("%s","-");
//			u3_printf("角度A:+%.1f",BZ7);
//			//printf("%s","ug/m3");
//			u3_printf("%c",'"');
//			delay_ms(5);
//			USART_SendData(UART4,255);
//			delay_ms(5);
//			USART_SendData(UART4,255);
//			delay_ms(5);
//			USART_SendData(UART4,255);
			}
			
			
						if(BZ2==2)
			{
//			u3_printf("%s","t2.txt=");
//			u3_printf("%c",'"');
//			//printf("%s","-");
//			u3_printf("角度B:+%.1f",BZ7);
//			//printf("%s","ug/m3");
//			u3_printf("%c",'"');
//			delay_ms(5);
//			USART_SendData(UART4,255);
//			delay_ms(5);
//			USART_SendData(UART4,255);
//			delay_ms(5);
//			USART_SendData(UART4,255);
			}
			
			
									if(BZ2==3)
			{
//			u3_printf("%s","t3.txt=");
//			u3_printf("%c",'"');
//			//printf("%s","-");
//			u3_printf("角度C:+%.1f",BZ7);
//			//printf("%s","ug/m3");
//			u3_printf("%c",'"');
//			delay_ms(5);
//			USART_SendData(UART4,255);
//			delay_ms(5);
//			USART_SendData(UART4,255);
//			delay_ms(5);
//			USART_SendData(UART4,255);
			}
			
//			printf("%s","t1.txt=");
//			printf("%c",'"');
//			//printf("%s","-");
//			printf("角度:+%.1f",BZ7);
//			//printf("%s","ug/m3");
//			printf("%c",'"');
//			delay_ms(5);
//			USART_SendData(USART1,255);
//			delay_ms(5);
//			USART_SendData(USART1,255);
//			delay_ms(5);
//			USART_SendData(USART1,255);
			delay_ms(105);
						BZ7=BZ7*1600/360;
//			printf("%.1f\r\n",BZ7);
		}
		if(ZF==2)
		{
			BZ7=USART_ReceiveData(USART1);
			//USART_Cmd(USART1, DISABLE);  //使能串口1 
			//USART_SendData(USART1,BZ7);
			ZF=3;
			
									if(BZ2==1)
			{
//			u3_printf("%s","t1.txt=");
//			u3_printf("%c",'"');
//			//printf("%s","-");
//			u3_printf("角度A:-%.1f",BZ7);
//			//printf("%s","ug/m3");
//			u3_printf("%c",'"');
//			delay_ms(5);
//			USART_SendData(UART4,255);
//			delay_ms(5);
//			USART_SendData(UART4,255);
//			delay_ms(5);
//			USART_SendData(UART4,255);
			}
										if(BZ2==2)
			{
//			u3_printf("%s","t2.txt=");
//			u3_printf("%c",'"');
//			//printf("%s","-");
//			u3_printf("角度B:-%.1f",BZ7);
//			//printf("%s","ug/m3");
//			u3_printf("%c",'"');
//			delay_ms(5);
//			USART_SendData(UART4,255);
//			delay_ms(5);
//			USART_SendData(UART4,255);
//			delay_ms(5);
//			USART_SendData(UART4,255);
			}
			
			
			
												if(BZ2==3)
			{
//			u3_printf("%s","t3.txt=");
//			u3_printf("%c",'"');
//			//printf("%s","-");
//			u3_printf("角度C:-%.1f",BZ7);
//			//printf("%s","ug/m3");
//			u3_printf("%c",'"');
//			delay_ms(5);
//			USART_SendData(UART4,255);
//			delay_ms(5);
//			USART_SendData(UART4,255);
//			delay_ms(5);
//			USART_SendData(UART4,255);
			}
			
			
//			printf("%s","t1.txt=");
//			printf("%c",'"');
//			//printf("%s","-");
//			printf("角度:-%.1f",BZ7);
//			//printf("%s","ug/m3");
//			printf("%c",'"');
//			delay_ms(5);
//			USART_SendData(USART1,255);
//			delay_ms(5);
//			USART_SendData(USART1,255);
//			delay_ms(5);
//			USART_SendData(USART1,255);
			
			delay_ms(105);
			BZ7=-BZ7*1600/360;
//			printf("%.1f\r\n",BZ7);
		}
		if(BZ2==1||BZ2==2||BZ2==3)
		{
			if(ZF!=3)
			{
			if(BZ10=='+')
			ZF=1;
			if(BZ10=='-')
			ZF=2;
			}
		}
		
		
		/***********电磁阀1步进电机***************/
		if(BZ2==1&&ZF==3)
		{
			BZ2=0;
			ZF=0;
			                      //                                          BZ5=1;
		if(BZ5==1)
		{
			BZ6=BZ7-BZ3-BZ9;
//			printf("BZ6=%.1f\r\n",BZ6);
			if(BZ6>0)
				LED2=1;
			if(BZ6<0)
			{
				BZ6=-BZ6;
				LED2=0;
			}
			BZ9=BZ7-BZ3;
			
//			printf("BZ7=%.1f\r\n",BZ7);
//			printf("BZ9=%.1f\r\n",BZ9);
				for(BZ8=BZ6;BZ8>0;BZ8--)
			{
				LED1=!LED1;
				delay_ms(1);
			}
			CF1=1;
			USART_Cmd(USART1, ENABLE);  //使能串口1 
		}
		}
		/***********电磁阀1步进电机***************/
		
		/***********电磁阀2步进电机***************/
		if(BZ2==2&&ZF==3)
		{
			BZ2=0;
			ZF=0;
						     //                                                           BZ5=1;
		if(BZ5==1)
		{
			D2CF4=BZ7-D1CF2-D2CF3;
//			printf("BZ6=%.1f\r\n",D2CF4);
			if(D2CF4>0)
				DIR1=1;
			if(D2CF4<0)
			{
				D2CF4=-D2CF4;
				DIR1=0;
			}
			D2CF3=BZ7-D1CF2;
			
//			printf("BZ7=%.1f\r\n",BZ7);
//			printf("BZ9=%.1f\r\n",D2CF3);
				for(BZ8=D2CF4;BZ8>0;BZ8--)
			{
				PUL1=!PUL1;
				delay_ms(1);
			}
			CF2=1;
			USART_Cmd(USART1, ENABLE);  //使能串口1 
		}
		}
		/***********电磁阀2步进电机***************/
		
		/***********电磁阀3步进电机***************/
		if(BZ2==3&&ZF==3)
		{
			BZ2=0;
			ZF=0;
						                //                                                BZ5=1;
		if(BZ5==1)
		{
			D3CF4=BZ7-D3CF2-D3CF5;
//			printf("BZ6=%.1f\r\n",D3CF4);
			if(D3CF4>0)
				DIR2=1;
			if(D3CF4<0)
			{
				D3CF4=-D3CF4;
				DIR2=0;
			}
			D3CF5=BZ7-D3CF2;
			
//			printf("BZ7=%.1f\r\n",BZ7);
//			printf("BZ9=%.1f\r\n",D3CF5);
				for(BZ8=D3CF4;BZ8>0;BZ8--)
			{
				PUL2=!PUL2;
				delay_ms(1);
			}
			CF3=1;
			USART_Cmd(USART1, ENABLE);  //使能串口1 
		}
		}
		/***********电磁阀3步进电机***************/
		if(BZ10=='A')
		{
			BZ2=1;
		}
		if(BZ10=='B')
		{
			BZ2=2;
		}
		if(BZ10=='C')
		{
			BZ2=3;
		}


	}
}

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //溢出中断
	{

		if(BZ5==0)
		{
			/***********电磁阀1步进电机***************/
			adWrite(0x90,0x40);
			BZ1=adRead(0x90);
	//		printf("%d\r\n",BZ1);
	//		printf("           %.1f\r\n",BZ3);
			if(BZ3>BZ1)
			{
				//BZ1++;
				LED2=1;
				LED1=!LED1;
			}
			if(BZ3<BZ1)
			{
				//BZ1--;
				LED2=0;
				LED1=!LED1;
			}
			if(BZ3==BZ1)
			{
				//BZ2=0;
				D1CF1=1;
				BZ5=1;
				//TIM_Cmd(TIM3,DISABLE); //使能定时器3
			}
			/***********电磁阀1步进电机***************/

			/***********电磁阀2步进电机***************/
			addWrite(0x90,0x40);
			DCF2=ad1Read(0x90);
			printf("%d\r\n",DCF2);
			printf("           %.1f\r\n",D1CF2);
			if(D1CF2>DCF2)
			{
				//BZ1++;
				DIR1=1;
				PUL1=!PUL1;
			}
			if(D1CF2<DCF2)
			{
				//BZ1--;
				DIR1=0;
				PUL1=!PUL1;
			}
			if(D1CF2==DCF2)
			{
				//BZ2=0;
				D2CF2=1;
				BZ5=1;
				//TIM_Cmd(TIM3,DISABLE); //使能定时器3
			}
			/***********电磁阀2步进电机***************/
			
			/***********电磁阀3步进电机***************/
			adddWrite(0x90,0x40);
			D3CF1=ad2Read(0x90);
//			printf("%d\r\n",D3CF1);
//			printf("           %.1f\r\n",D3CF2);
			if(D3CF2>D3CF1)
			{
				//BZ1++;
				DIR2=1;
				PUL2=!PUL2;
			}
			if(D3CF2<D3CF1)
			{
				//BZ1--;
				DIR2=0;
				PUL2=!PUL2; 
			}
			if(D3CF2==D3CF1)
			{
				//BZ2=0;
				D3CF3=1;
				BZ5=1;
				//TIM_Cmd(TIM3,DISABLE); //使能定时器3
			}
			/***********电磁阀3步进电机***************/
	}
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除中断标志位
}
//void TIM5_IRQHandler(void)
//{
//	if(TIM_GetITStatus(TIM5,TIM_IT_Update)==SET) //溢出中断
//	{
//			BZ4=0;
//			adWrite(0x90,0x40);
//			BZ1=adRead(0x90);
//		printf("%d\r\n",BZ1);
//		printf("           %d\r\n",BZ3);
//	}
//	TIM_ClearITPendingBit(TIM5,TIM_IT_Update);  //清除中断标志位
//}
u8 BZZ;
u8 zong;
long long temp=0;
long long ceshi=0;
int main(void)
{
	
	//u16 dt=0,dt1=0,dt2=0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	delay_init(168);
	I2CInit(); 
	
	LED_Init();
	//TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除中断标志位
	//TIM3_Int_Init(50-1,8400-1);	//定时器时钟84M，分频系数8400，所以84M/8400=10Khz的计数频率，计数5000次为500ms  
	//TIM5_Int_Init(40-1,8400-1);	//定时器时钟84M，分频系数8400，所以84M/8400=10Khz的计数频率，计数5000次为500ms  
	TIM14_PWM_Init(2400-1,8400-1);	//84M/84=1Mhz的计数频率,重装载值500，所以PWM频率为 1M/500=2Khz.    
//	TIM_SetCompare1(TIM14,1200);	//修改比较值，修改占空比
	TIM5_PWM_Init(2400-1,8400-1);	//84M/84=1Mhz的计数频率,重装载值500，所以PWM频率为 1M/500=2Khz.   
	TIM9_PWM_Init(2400-1,8400-1);	//84M/84=1Mhz的计数频率,重装载值500，所以PWM频率为 1M/500=2Khz.  
//	TIM3_PWM_Init(2400-1,84-1);	//84M/84=1Mhz的计数频率,重装载值500，所以PWM频率为 1M/500=2Khz.  
//	TIM_SetCompare1(TIM3,2300);	//修改比较值，修改占空比
//	TIM10_CH1_Cap_Init(0XFFFFFFFF,84-1); //以1Mhz的频率计数   
//	TIM_Cmd(TIM10,DISABLE ); 	//关闭定时器5
//	TIM_Cmd(TIM14, DISABLE);  //使能TIM14
//	TIM_Cmd(TIM5, DISABLE);  //使能TIM14
//	TIM_Cmd(TIM9, DISABLE);  //使能TIM14
	//LED0=0;
	uart_init(115200);
	usart3_init(115200);	
	//USART_SendData(USART1,10);
	
	BZ3=0;
	D1CF2=0;
	D3CF2=0;
	DCF11=1;DCF12=0;
	DCF21=1;DCF22=0;
	DCF31=1;DCF32=0; 
	TIM_SetCompare1(TIM5,2400);	//修改比较值，修改占空比
	TIM_SetCompare1(TIM9,2400);	//修改比较值，修改占空比
	TIM_SetCompare1(TIM14,2400);	//修改比较值，修改占空比
//	TIM_SetCompare1(TIM5,1200);	//修改比较值，修改占空比
//TIM_SetCompare1(TIM9,1200);	//修改比较值，修改占空比
//TIM_SetCompare1(TIM14,1200);	//修改比较值，修改占空比
	//BZ2=1;
//	/*********读写1个*//////////////
//		/*AT24Cxx_WriteOneByte(50,0);
//		dt=AT24Cxx_ReadOneByte(50);
//		USART_SendData(USART1,dt);*/
//	/**********读写两个**************/
//	//AT24Cxx_WriteTwoByte(32,0x6541);
//	dt=AT24Cxx_ReadTwoByte(31);
//	dt1=dt/256;
//	dt2=dt%256;
//	/*dt1=dt/100;
//	dt2=dt%100/10;
//	dt3=dt%10;*/
//	USART_SendData(USART1,dt1);
//	USART_SendData(USART1,dt2);
//	//USART_SendData(USART1,dt3);

//					while(1)
//		{
////			DIR1=0;
////			DIR2=0;
//			DIR3=0;
//			DIR4=0;
////			PUL2=!PUL2;
//			PUL3=!PUL3;
//			PUL4=!PUL4;
//			delay_ms(1);
////			PUL1=!PUL1;
//		}
//	u3_printf("%s","AT+RST\r\n");
//	delay_ms(1000);
//	u3_printf("%s","AT+CWMODE=1\r\n");
//	delay();
//	u3_printf("%s","AT+CWLAP\r\n");
//	delay();
//	u3_printf("%s","AT+CWJAP=");
//	u3_printf("%c",'"');
//	u3_printf("%s","shi");
//	u3_printf("%c",'"');
//	u3_printf("%c",',');
//	u3_printf("%c",'"');
//	u3_printf("%s","123666666");
//	u3_printf("%c",'"');
//	u3_printf("%s","\r\n");
//	delay();
//	u3_printf("AT+CIPMUX=1\r\n");
//	delay();
//	u3_printf("AT+CIPSTART=2,");
//	u3_printf("%c",'"');
//	u3_printf("%s","TCP");
//	u3_printf("%c",'"');
//	u3_printf("%c",',');
//	u3_printf("%c",'"');
//	u3_printf("%s","192.168.4.1");
//	u3_printf("%c",'"');
//	u3_printf("%c",',');
//	u3_printf("%s","8686\r\n");
//	delay();
//	while(1){
//	ceshi=ad2Read(0x90);
//	printf("HIGH:%lld us\r\n",ceshi);}
//	while(1)
//	{
//		//printf("1111:%lld us\r\n",2222); //打印总的高点平时间
//					 		if(TIM10CH1_CAPTURE_STA&0X80)        //成功捕获到了一次高电平
//		{
//			temp=TIM10CH1_CAPTURE_STA&0X3F; 
//			temp*=0XFFFFFFFF;		 		         //溢出时间总和
//			temp+=TIM10CH1_CAPTURE_VAL;		   //得到总的高电平时间
//			printf("HIGH:%lld us\r\n",temp); //打印总的高点平时间
//			TIM10CH1_CAPTURE_STA=0;			     //开启下一次捕获
//		}
//	}
	while(1)
	{
		
		delay_ms(10);
		if(BZZ==0)
		{
			BZZ=1;
		while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2))
		{
		//	printf("qqqqqq\r\n");
//			DIR1=0;
//			DIR2=0;
			LED2=0;
//			PUL2=!PUL2;
			LED1=!LED1;
			delay_ms(1);
//			PUL1=!PUL1;
		}
				while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1))
		{
//			DIR1=0;
			DIR2=0;
			PUL2=!PUL2;
			delay_ms(1);
//			PUL1=!PUL1;
		}
		while(GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3))
		{
			DIR1=0;
			PUL1=!PUL1;
			delay_ms(1);
		}


				for(BZ8=440;BZ8>0;BZ8--)
			{
				LED2=1;
				LED1=!LED1;
				delay_ms(1);
			}

				for(BZ8=400;BZ8>0;BZ8--)
			{
				DIR2=1;
				PUL2=!PUL2;
				delay_ms(1);
			}

				for(BZ8=460;BZ8>0;BZ8--)
			{
				DIR1=1;
				PUL1=!PUL1;
				delay_ms(1);
			}
		BZ5=1;
					while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1))
		{
//			DIR1=0;
//			DIR2=0;
			DIR3=1;
//			PUL2=!PUL2;
			PUL3=!PUL3;
			delay_ms(1);
//			PUL1=!PUL1;
		}
		

		while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2))
		{
//			DIR1=0;
//			DIR2=0;
			DIR4=0;
//			PUL2=!PUL2;
			PUL4=!PUL4;
			delay_ms(1);
//			PUL1=!PUL1;
		}

						for(BZ8=500;BZ8>0;BZ8--)
			{
				DIR3=0;
				PUL3=!PUL3;
				delay_ms(1);
			}


				for(BZ8=500;BZ8>0;BZ8--)
			{
				DIR4=1;
				PUL4=!PUL4;
				delay_ms(1);
			}
		}
		if(CF3==1)
		{
			TIM_Cmd(TIM9, ENABLE);  //使能TIM14
			TIM_SetCompare1(TIM9,1200);	//修改比较值，修改占空比
			delay_ms(300);
			TIM_SetCompare1(TIM9,2400);	//修改比较值，修改占空比
			CF3=0;
//			C3F++;
//			if(C3F==100)
//			{
//				TIM_SetCompare1(TIM9,2400);	//修改比较值，修改占空比
//				//TIM_Cmd(TIM9, DISABLE);  //使能TIM14
//				C3F=0;
//				CF3=0;
//			}
		}
		if(CF2==1)
		{
			TIM_Cmd(TIM14, ENABLE);  //使能TIM14
			TIM_SetCompare1(TIM14,1200);	//修改比较值，修改占空比
			delay_ms(300);
			TIM_SetCompare1(TIM14,2400);	//修改比较值，修改占空比
			CF2=0;
//			C2F++;
//			if(C2F==100)
//			{
//				TIM_SetCompare1(TIM5,2400);	//修改比较值，修改占空比
//				//TIM_Cmd(TIM5, DISABLE);  //使能TIM14
//				C2F=0;
//				CF2=0;
//			}
		}
		if(CF1==1)
		{
			TIM_Cmd(TIM5, ENABLE);  //使能TIM14
			TIM_SetCompare1(TIM5,1200);	//修改比较值，修改占空比
			delay_ms(300);
			TIM_SetCompare1(TIM5,2400);	//修改比较值，修改占空比
			CF1=0;
//			C1F++;
//			if(C1F==100)
//			{
//				TIM_SetCompare1(TIM14,2400);	//修改比较值，修改占空比
//				//TIM_Cmd(TIM14, DISABLE);  //使能TIM14
//				C1F=0;
//				CF1=0;
//			}
		}
//////////////////		while(BL3==1||BL3==2||BL3==3)
//////////////////		{
//////////////////			if(BL4!=0)
//////////////////			{
//////////////////			if(BL4==1)	DIR4=0;
//////////////////			if(BL4==2)	DIR4=1;
//////////////////			PUL4=!PUL4;
//////////////////			delay_ms(1);
//////////////////			}
//////////////////		}
//////////////////		BL4=0;
//		if(BZ2==1)
//			TIM_Cmd(TIM3,ENABLE); //使能定时器3
//		else
//			TIM_Cmd(TIM3,DISABLE); //使能定时器3
//			 		if(TIM10CH1_CAPTURE_STA&0X80)        //成功捕获到了一次高电平
//		{
//			temp=TIM10CH1_CAPTURE_STA&0X3F; 
//			temp*=0XFFFFFFFF;		 		         //溢出时间总和
//			temp+=TIM10CH1_CAPTURE_VAL;		   //得到总的高电平时间
//			printf("HIGH:%lld us\r\n",temp); //打印总的高点平时间
//			TIM10CH1_CAPTURE_STA=0;			     //开启下一次捕获
////			if(BL3==1)
////			{
////				if(temp<500&&BL4==0) BL4=1; if(temp >= 500&&BL4==0) BL4=2;
////				if(temp >= 500&&BL4==1)	{TIM_Cmd(TIM10,DISABLE ); 	BL3=0;}
////				if(temp < 500&&BL4==2)	{TIM_Cmd(TIM10,DISABLE ); 	BL3=0;}
////			}
////			if(BL3==2)
////			{
////				if(temp<1000) BL4=1; else BL4=2;if(temp >= 1000&&BL4==0) BL4=2;
////				if(temp >= 1000&&BL4==1)	{TIM_Cmd(TIM10,DISABLE ); 	BL3=0;}
////				if(temp < 1000&&BL4==2)	{TIM_Cmd(TIM10,DISABLE ); 	BL3=0;}
////			}
////			if(BL3==3)
////			{
////				if(temp<1500) BL4=1; else BL4=2;if(temp >= 1500&&BL4==0) BL4=2;
////				if(temp >= 1500&&BL4==1)	{TIM_Cmd(TIM10,DISABLE ); 	BL3=0;}
////				if(temp < 1500&&BL4==2)	{TIM_Cmd(TIM10,DISABLE ); 	BL3=0;}
////			}
//			//zong=(temp*10)/100000;
//			u3_printf("%s","AT+CIPSEND=2,12\r\n");
//			delay();
//			u3_printf("%s","JULIG");
//			u3_printf("%c",at_9[temp/100000]);u3_printf("%c",at_9[temp%100000/10000]);u3_printf("%c",at_9[temp%10000/1000]);u3_printf("%c",at_9[temp%1000/100]);
//			u3_printf("%c",at_9[temp%100/10]);u3_printf("%c",at_9[temp%10]);u3_printf("%c",'#');

//			
//			
//		}

	}
}


