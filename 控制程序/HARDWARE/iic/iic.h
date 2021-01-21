#ifndef __IIC_H
#define __IIC_H
#include "sys.h"
//#include "sys.h"

#define I2C_SCL GPIO_Pin_5
#define I2C_SDA GPIO_Pin_6

#define aI2C_SCL GPIO_Pin_3
#define aI2C_SDA GPIO_Pin_4

#define bI2C_SCL GPIO_Pin_1
#define bI2C_SDA GPIO_Pin_2

#define cI2C_SCL GPIO_Pin_9
#define cI2C_SDA GPIO_Pin_7

#define dI2C_SCL GPIO_Pin_8
#define dI2C_SDA GPIO_Pin_13

#define GPIO_I2C GPIOC


#define I2C_SCL_H GPIO_SetBits(GPIO_I2C,I2C_SCL)
#define I2C_SCL_L GPIO_ResetBits(GPIO_I2C,I2C_SCL)
#define I2C_SDA_H GPIO_SetBits(GPIO_I2C,I2C_SDA)
#define I2C_SDA_L GPIO_ResetBits(GPIO_I2C,I2C_SDA)

#define aI2C_SCL_H GPIO_SetBits(GPIO_I2C,aI2C_SCL)
#define aI2C_SCL_L GPIO_ResetBits(GPIO_I2C,aI2C_SCL)
#define aI2C_SDA_H GPIO_SetBits(GPIO_I2C,aI2C_SDA)
#define aI2C_SDA_L GPIO_ResetBits(GPIO_I2C,aI2C_SDA)

#define bI2C_SCL_H GPIO_SetBits(GPIO_I2C,bI2C_SCL)
#define bI2C_SCL_L GPIO_ResetBits(GPIO_I2C,bI2C_SCL)
#define bI2C_SDA_H GPIO_SetBits(GPIO_I2C,bI2C_SDA)
#define bI2C_SDA_L GPIO_ResetBits(GPIO_I2C,bI2C_SDA)

#define cI2C_SCL_H GPIO_SetBits(GPIO_I2C,cI2C_SCL)
#define cI2C_SCL_L GPIO_ResetBits(GPIO_I2C,cI2C_SCL)
#define cI2C_SDA_H GPIO_SetBits(GPIO_I2C,cI2C_SDA)
#define cI2C_SDA_L GPIO_ResetBits(GPIO_I2C,cI2C_SDA)

#define dI2C_SCL_H GPIO_SetBits(GPIO_I2C,dI2C_SCL)
#define dI2C_SCL_L GPIO_ResetBits(GPIO_I2C,dI2C_SCL)
#define dI2C_SDA_H GPIO_SetBits(GPIO_I2C,dI2C_SDA)
#define dI2C_SDA_L GPIO_ResetBits(GPIO_I2C,dI2C_SDA)
void I2CInit(void);
void I2C_SDA_OUT(void);
void I2C_SDA_IN(void);
void I2C_Start(void);
void I2C_Stop(void);



void I2C_Ack(void);
void I2C_NAck(void);
u8 I2C_Wait_Ack(void);
void I2C_Send_Byte(u8 txd);
u8 I2C_Read_Byte(u8 ack);



void aI2CInit(void);
void aI2C_SDA_OUT(void);
void aI2C_SDA_IN(void);
void aI2C_Start(void);
void aI2C_Stop(void);


void bI2CInit(void);
void bI2C_SDA_OUT(void);
void bI2C_SDA_IN(void);
void bI2C_Start(void);
void bI2C_Stop(void);

void aI2C_Ack(void);
void aI2C_NAck(void);
u8 aI2C_Wait_Ack(void);
void aI2C_Send_Byte(u8 txd);
u8 aI2C_Read_Byte(u8 ack);


u8 bI2C_Wait_Ack(void);
void bI2C_Send_Byte(u8 txd);
u8 bI2C_Read_Byte(u8 ack);

////////////
void cI2CInit(void);
void cI2C_SDA_OUT(void);
void cI2C_SDA_IN(void);
void cI2C_Start(void);
void cI2C_Stop(void);


void dI2CInit(void);
void dI2C_SDA_OUT(void);
void dI2C_SDA_IN(void);
void dI2C_Start(void);
void dI2C_Stop(void);

void cI2C_Ack(void);
void cI2C_NAck(void);
u8 cI2C_Wait_Ack(void);
void cI2C_Send_Byte(u8 txd);
u8 cI2C_Read_Byte(u8 ack);


u8 dI2C_Wait_Ack(void);
void dI2C_Send_Byte(u8 txd);
u8 dI2C_Read_Byte(u8 ack);

#endif



