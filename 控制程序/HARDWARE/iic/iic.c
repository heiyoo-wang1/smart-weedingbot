
#include "iic.h"
#include "delay.h"


void I2CInit(void)
{    	 
	
  GPIO_InitTypeDef  GPIO_InitStructure;
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);//使能GPIOF时钟
  //GPIOF9,F10初始化设置
  GPIO_InitStructure.GPIO_Pin = I2C_SCL | I2C_SDA | aI2C_SCL | aI2C_SDA| bI2C_SCL | bI2C_SDA| cI2C_SCL | cI2C_SDA| dI2C_SCL | dI2C_SDA;//LED0和LED1对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//100MHz
  //GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIO
	aI2C_SCL_H;
	aI2C_SDA_H;
	bI2C_SCL_H;
	bI2C_SDA_H;
	cI2C_SCL_H;
	cI2C_SDA_H;
	dI2C_SCL_H;
	dI2C_SDA_H;
}

void I2C_SDA_OUT(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  //GPIOF9,F10初始化设置
  GPIO_InitStructure.GPIO_Pin = I2C_SDA;//LED0和LED1对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//100MHz
  //GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIO
}
void aI2C_SDA_OUT(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  //GPIOF9,F10初始化设置
  GPIO_InitStructure.GPIO_Pin = aI2C_SDA;//LED0和LED1对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//100MHz
  //GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIO
}
void bI2C_SDA_OUT(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  //GPIOF9,F10初始化设置
  GPIO_InitStructure.GPIO_Pin = bI2C_SDA;//LED0和LED1对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//100MHz
  //GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIO
}

void cI2C_SDA_OUT(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  //GPIOF9,F10初始化设置
  GPIO_InitStructure.GPIO_Pin = cI2C_SDA;//LED0和LED1对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//100MHz
  //GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIO
}
void dI2C_SDA_OUT(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  //GPIOF9,F10初始化设置
  GPIO_InitStructure.GPIO_Pin = dI2C_SDA;//LED0和LED1对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//100MHz
  //GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIO
}
void I2C_SDA_IN(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  //GPIOF9,F10初始化设置
  GPIO_InitStructure.GPIO_Pin = I2C_SDA;//LED0和LED1对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输出模式
  //GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIO
}
void aI2C_SDA_IN(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  //GPIOF9,F10初始化设置
  GPIO_InitStructure.GPIO_Pin = aI2C_SDA;//LED0和LED1对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输出模式
  //GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIO
}

void bI2C_SDA_IN(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  //GPIOF9,F10初始化设置
  GPIO_InitStructure.GPIO_Pin = bI2C_SDA;//LED0和LED1对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输出模式
  //GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIO
}

void cI2C_SDA_IN(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  //GPIOF9,F10初始化设置
  GPIO_InitStructure.GPIO_Pin = cI2C_SDA;//LED0和LED1对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输出模式
  //GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIO
}

void dI2C_SDA_IN(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  //GPIOF9,F10初始化设置
  GPIO_InitStructure.GPIO_Pin = dI2C_SDA;//LED0和LED1对应IO口
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输出模式
  //GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIO
}

///起始信号
void I2C_Start(void)
{
	I2C_SDA_OUT();
	I2C_SDA_H;
	I2C_SCL_H;
	delay_us(5);
	I2C_SDA_L;
	delay_us(6);
	I2C_SCL_L;
}
void aI2C_Start(void)
{
	aI2C_SDA_OUT();
	aI2C_SDA_H;
	aI2C_SCL_H;
	delay_us(5);
	aI2C_SDA_L;
	delay_us(6);
	aI2C_SCL_L;
}
void bI2C_Start(void)
{
	bI2C_SDA_OUT();
	bI2C_SDA_H;
	bI2C_SCL_H;
	delay_us(5);
	bI2C_SDA_L;
	delay_us(6);
	bI2C_SCL_L;
}
void cI2C_Start(void)
{
	cI2C_SDA_OUT();
	cI2C_SDA_H;
	cI2C_SCL_H;
	delay_us(5);
	cI2C_SDA_L;
	delay_us(6);
	cI2C_SCL_L;
}
void dI2C_Start(void)
{
	dI2C_SDA_OUT();
	dI2C_SDA_H;
	dI2C_SCL_H;
	delay_us(5);
	dI2C_SDA_L;
	delay_us(6);
	dI2C_SCL_L;
}
////停止信号
void I2C_Stop(void)
{
	I2C_SDA_OUT();
	I2C_SCL_L;
	I2C_SDA_L;
	I2C_SCL_H;
	delay_us(6);
	I2C_SDA_H;
	delay_us(6);
}
void aI2C_Stop(void)
{
	aI2C_SDA_OUT();
	aI2C_SCL_L;
	aI2C_SDA_L;
	aI2C_SCL_H;
	delay_us(6);
	aI2C_SDA_H;
	delay_us(6);
}

void bI2C_Stop(void)
{
	bI2C_SDA_OUT();
	bI2C_SCL_L;
	bI2C_SDA_L;
	bI2C_SCL_H;
	delay_us(6);
	bI2C_SDA_H;
	delay_us(6);
}

void cI2C_Stop(void)
{
	cI2C_SDA_OUT();
	cI2C_SCL_L;
	I2C_SDA_L;
	cI2C_SCL_H;
	delay_us(6);
	cI2C_SDA_H;
	delay_us(6);
}

void dI2C_Stop(void)
{
	dI2C_SDA_OUT();
	dI2C_SCL_L;
	dI2C_SDA_L;
	dI2C_SCL_H;
	delay_us(6);
	dI2C_SDA_H;
	delay_us(6);
}
//主机产生应答信号
void I2C_Ack(void)
{
	I2C_SCL_L;
	I2C_SDA_OUT();
	I2C_SDA_L;
	delay_us(2);
	I2C_SCL_H;
	delay_us(5);
	I2C_SCL_L;
}
void aI2C_Ack(void)
{
	aI2C_SCL_L;
	aI2C_SDA_OUT();
	aI2C_SDA_L;
	delay_us(2);
	aI2C_SCL_H;
	delay_us(5);
	aI2C_SCL_L;
}
void bI2C_Ack(void)
{
	bI2C_SCL_L;
	bI2C_SDA_OUT();
	bI2C_SDA_L;
	delay_us(2);
	bI2C_SCL_H;
	delay_us(5);
	bI2C_SCL_L;
}

void cI2C_Ack(void)
{
	cI2C_SCL_L;
	cI2C_SDA_OUT();
	cI2C_SDA_L;
	delay_us(2);
	cI2C_SCL_H;
	delay_us(5);
	cI2C_SCL_L;
}
void dI2C_Ack(void)
{
	dI2C_SCL_L;
	dI2C_SDA_OUT();
	dI2C_SDA_L;
	delay_us(2);
	dI2C_SCL_H;
	delay_us(5);
	dI2C_SCL_L;
}
//主机不产生应答信号
void I2C_NAck(void)
{
	I2C_SCL_L;
	I2C_SDA_OUT();
	I2C_SDA_H;
	delay_us(2);
	I2C_SCL_H;
	delay_us(5);
	I2C_SCL_L;
}
void aI2C_NAck(void)
{
	aI2C_SCL_L;
	aI2C_SDA_OUT();
	aI2C_SDA_H;
	delay_us(2);
	aI2C_SCL_H;
	delay_us(5);
	aI2C_SCL_L;
}
void bI2C_NAck(void)
{
	bI2C_SCL_L;
	bI2C_SDA_OUT();
	bI2C_SDA_H;
	delay_us(2);
	bI2C_SCL_H;
	delay_us(5);
	bI2C_SCL_L;
}

void cI2C_NAck(void)
{
	cI2C_SCL_L;
	cI2C_SDA_OUT();
	cI2C_SDA_H;
	delay_us(2);
	cI2C_SCL_H;
	delay_us(5);
	cI2C_SCL_L;
}
void dI2C_NAck(void)
{
	dI2C_SCL_L;
	dI2C_SDA_OUT();
	dI2C_SDA_H;
	delay_us(2);
	dI2C_SCL_H;
	delay_us(5);
	dI2C_SCL_L;
}
//等待丛从机应答信号
//返回值 1 接收应答失败
//       0 接收应答成功
u8 I2C_Wait_Ack(void)
{
	u8 TempTime=0;
	I2C_SDA_IN();
	I2C_SDA_H;
	delay_us(1);
	I2C_SCL_H;
	delay_us(1);
	while(GPIO_ReadInputDataBit(GPIO_I2C,I2C_SDA))//读取管脚状态
	{
	TempTime++;
		if(TempTime>250)
		{
			I2C_Stop();
			return 1;
		}
	}
	I2C_SCL_L;
	return 0;
}
u8 aI2C_Wait_Ack(void)
{
	u8 TempTime=0;
	aI2C_SDA_IN();
	aI2C_SDA_H;
	delay_us(1);
	aI2C_SCL_H;
	delay_us(1);
	while(GPIO_ReadInputDataBit(GPIO_I2C,aI2C_SDA))//读取管脚状态
	{
	TempTime++;
		if(TempTime>250)
		{
			aI2C_Stop();
			return 1;
		}
	}
	aI2C_SCL_L;
	return 0;
}

u8 bI2C_Wait_Ack(void)
{
	u8 TempTime=0;
	bI2C_SDA_IN();
	bI2C_SDA_H;
	delay_us(1);
	bI2C_SCL_H;
	delay_us(1);
	while(GPIO_ReadInputDataBit(GPIO_I2C,bI2C_SDA))//读取管脚状态
	{
	TempTime++;
		if(TempTime>250)
		{
			bI2C_Stop();
			return 1;
		}
	}
	bI2C_SCL_L;
	return 0;
}

u8 cI2C_Wait_Ack(void)
{
	u8 TempTime=0;
	cI2C_SDA_IN();
	cI2C_SDA_H;
	delay_us(1);
	cI2C_SCL_H;
	delay_us(1);
	while(GPIO_ReadInputDataBit(GPIO_I2C,cI2C_SDA))//读取管脚状态
	{
	TempTime++;
		if(TempTime>250)
		{
			cI2C_Stop();
			return 1;
		}
	}
	cI2C_SCL_L;
	return 0;
}

u8 dI2C_Wait_Ack(void)
{
	u8 TempTime=0;
	dI2C_SDA_IN();
	dI2C_SDA_H;
	delay_us(1);
	dI2C_SCL_H;
	delay_us(1);
	while(GPIO_ReadInputDataBit(GPIO_I2C,dI2C_SDA))//读取管脚状态
	{
	TempTime++;
		if(TempTime>250)
		{
			dI2C_Stop();
			return 1;
		}
	}
	dI2C_SCL_L;
	return 0;
}
//iic发送一个字节
void I2C_Send_Byte(u8 txd)
{
	u8 i=0;
	I2C_SDA_OUT();
	I2C_SCL_L;//拉低时钟，开始数据传输
	for(i=0;i<8;i++)
{
	if((txd&0x80)>0)
	{
		I2C_SDA_H;
	}
	else
	{
		I2C_SDA_L;
	}
	txd<<=1;
	I2C_SCL_H;
	delay_us(2);//发送数据
	I2C_SCL_L;
	delay_us(2);
}	
}
void aI2C_Send_Byte(u8 txd)
{
	u8 i=0;
	aI2C_SDA_OUT();
	aI2C_SCL_L;//拉低时钟，开始数据传输
	for(i=0;i<8;i++)
{
	if((txd&0x80)>0)
	{
		aI2C_SDA_H;
	}
	else
	{
		aI2C_SDA_L;
	}
	txd<<=1;
	aI2C_SCL_H;
	delay_us(2);//发送数据
	aI2C_SCL_L;
	delay_us(2);
}	
}

void bI2C_Send_Byte(u8 txd)
{
	u8 i=0;
	bI2C_SDA_OUT();
	bI2C_SCL_L;//拉低时钟，开始数据传输
	for(i=0;i<8;i++)
{
	if((txd&0x80)>0)
	{
		bI2C_SDA_H;
	}
	else
	{
		bI2C_SDA_L;
	}
	txd<<=1;
	bI2C_SCL_H;
	delay_us(2);//发送数据
	bI2C_SCL_L;
	delay_us(2);
}	
}

void cI2C_Send_Byte(u8 txd)
{
	u8 i=0;
	cI2C_SDA_OUT();
	cI2C_SCL_L;//拉低时钟，开始数据传输
	for(i=0;i<8;i++)
{
	if((txd&0x80)>0)
	{
		cI2C_SDA_H;
	}
	else
	{
		cI2C_SDA_L;
	}
	txd<<=1;
	cI2C_SCL_H;
	delay_us(2);//发送数据
	cI2C_SCL_L;
	delay_us(2);
}	
}

void dI2C_Send_Byte(u8 txd)
{
	u8 i=0;
	dI2C_SDA_OUT();
	dI2C_SCL_L;//拉低时钟，开始数据传输
	for(i=0;i<8;i++)
{
	if((txd&0x80)>0)
	{
		dI2C_SDA_H;
	}
	else
	{
		dI2C_SDA_L;
	}
	txd<<=1;
	dI2C_SCL_H;
	delay_us(2);//发送数据
	dI2C_SCL_L;
	delay_us(2);
}	
}
//iic读取一个字节
u8 I2C_Read_Byte(u8 ack)
{
	u8 i=0,receive=0;
	I2C_SDA_IN();
	for(i=0;i<8;i++)
	{
		I2C_SCL_L;
		delay_us(2);
		I2C_SCL_H;
		receive<<=1;
		if(GPIO_ReadInputDataBit(GPIO_I2C,I2C_SDA))
		{
			receive++;
		}
		delay_us(1);
	}
	if(ack==0)
	{
		I2C_NAck();
	}
	else
	{
		I2C_Ack();
	}
	return receive;
}

u8 aI2C_Read_Byte(u8 ack)
{
	u8 i=0,receive=0;
	aI2C_SDA_IN();
	for(i=0;i<8;i++)
	{
		aI2C_SCL_L;
		delay_us(2);
		aI2C_SCL_H;
		receive<<=1;
		if(GPIO_ReadInputDataBit(GPIO_I2C,aI2C_SDA))
		{
			receive++;
		}
		delay_us(1);
	}
	if(ack==0)
	{
		aI2C_NAck();
	}
	else
	{
		aI2C_Ack();
	}
	return receive;
}


u8 bI2C_Read_Byte(u8 ack)
{
	u8 i=0,receive=0;
	bI2C_SDA_IN();
	for(i=0;i<8;i++)
	{
		bI2C_SCL_L;
		delay_us(2);
		bI2C_SCL_H;
		receive<<=1;
		if(GPIO_ReadInputDataBit(GPIO_I2C,bI2C_SDA))
		{
			receive++;
		}
		delay_us(1);
	}
	if(ack==0)
	{
		bI2C_NAck();
	}
	else
	{
		bI2C_Ack();
	}
	return receive;
}


u8 cI2C_Read_Byte(u8 ack)
{
	u8 i=0,receive=0;
	cI2C_SDA_IN();
	for(i=0;i<8;i++)
	{
		cI2C_SCL_L;
		delay_us(2);
		cI2C_SCL_H;
		receive<<=1;
		if(GPIO_ReadInputDataBit(GPIO_I2C,cI2C_SDA))
		{
			receive++;
		}
		delay_us(1);
	}
	if(ack==0)
	{
		cI2C_NAck();
	}
	else
	{
		cI2C_Ack();
	}
	return receive;
}


u8 dI2C_Read_Byte(u8 ack)
{
	u8 i=0,receive=0;
	dI2C_SDA_IN();
	for(i=0;i<8;i++)
	{
		dI2C_SCL_L;
		delay_us(2);
		dI2C_SCL_H;
		receive<<=1;
		if(GPIO_ReadInputDataBit(GPIO_I2C,dI2C_SDA))
		{
			receive++;
		}
		delay_us(1);
	}
	if(ack==0)
	{
		dI2C_NAck();
	}
	else
	{
		dI2C_Ack();
	}
	return receive;
}


