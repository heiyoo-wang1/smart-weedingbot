#include "AT24Cxx.h"
#include "iic.h"
#include "delay.h"
u8 AT24Cxx_ReadOneByte(u16 addr)
{
	u8 temp=0;
	I2C_Start();
	
	if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);//д
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);//�������ݵ�ַ��λ
		
	}
	else
	{
		I2C_Send_Byte(0xa0);//������ַ+���ݵ�ַ
	}
	I2C_Wait_Ack();
	I2C_Send_Byte(addr);//˫�ֽ������ݵ�ַ��λ
													//���ֽ������ݵ�ַ��λ
	I2C_Wait_Ack();
	
	I2C_Start();
	I2C_Send_Byte(0xa1);//��
	I2C_Wait_Ack();
	temp=I2C_Read_Byte(0);  //0  ����NACK
	I2C_Stop();
	return temp;
}

void AT24Cxx_WriteOneByte(u16 addr,u8 dt)
{
	I2C_Start();
	if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);//д
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);//�������ݵ�ַ��λ
		
	}
	else
	{
		I2C_Send_Byte(0xa0);//������ַ+���ݵ�ַ
	}
	I2C_Wait_Ack();
	I2C_Send_Byte(addr);//˫�ֽ������ݵ�ַ��λ
													//���ֽ������ݵ�ַ��λ
	I2C_Wait_Ack();
	I2C_Send_Byte(dt);
	I2C_Wait_Ack();
	I2C_Stop();
	delay_ms(10);
}


u8 adRead(u16 addr)
{
	u8 temp=0;
	aI2C_Start();
	
	/*if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);//д
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);//�������ݵ�ַ��λ
		
	}
	else
	{
		I2C_Send_Byte(0xa0);//������ַ+���ݵ�ַ
	}
	I2C_Wait_Ack();*/
	aI2C_Send_Byte(addr+1);//˫�ֽ������ݵ�ַ��λ
													//���ֽ������ݵ�ַ��λ
	aI2C_Wait_Ack();
	
	//I2C_Start();
	//I2C_Send_Byte(0xa1);//��
	//I2C_Wait_Ack();
	temp=aI2C_Read_Byte(0);  //0  ����NACK
	aI2C_Stop();
	return temp;
}

u8 ad1Read(u16 addr)
{
	u8 temp=0;
	bI2C_Start();
	
	/*if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);//д
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);//�������ݵ�ַ��λ
		
	}
	else
	{
		I2C_Send_Byte(0xa0);//������ַ+���ݵ�ַ
	}
	I2C_Wait_Ack();*/
	bI2C_Send_Byte(addr+1);//˫�ֽ������ݵ�ַ��λ
													//���ֽ������ݵ�ַ��λ
	bI2C_Wait_Ack();
	
	//I2C_Start();
	//I2C_Send_Byte(0xa1);//��
	//I2C_Wait_Ack();
	temp=bI2C_Read_Byte(0);  //0  ����NACK
	bI2C_Stop();
	return temp;
}


u8 ad2Read(u16 addr)
{
	u8 temp=0;
	cI2C_Start();
	
	/*if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);//д
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);//�������ݵ�ַ��λ
		
	}
	else
	{
		I2C_Send_Byte(0xa0);//������ַ+���ݵ�ַ
	}
	I2C_Wait_Ack();*/
	cI2C_Send_Byte(addr+1);//˫�ֽ������ݵ�ַ��λ
													//���ֽ������ݵ�ַ��λ
	cI2C_Wait_Ack();
	
	//I2C_Start();
	//I2C_Send_Byte(0xa1);//��
	//I2C_Wait_Ack();
	temp=cI2C_Read_Byte(0);  //0  ����NACK
	cI2C_Stop();
	return temp;
}

u8 ad3Read(u16 addr)
{
	u8 temp=0;
	dI2C_Start();
	
	/*if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);//д
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);//�������ݵ�ַ��λ
		
	}
	else
	{
		I2C_Send_Byte(0xa0);//������ַ+���ݵ�ַ
	}
	I2C_Wait_Ack();*/
	dI2C_Send_Byte(addr+1);//˫�ֽ������ݵ�ַ��λ
													//���ֽ������ݵ�ַ��λ
	dI2C_Wait_Ack();
	
	//I2C_Start();
	//I2C_Send_Byte(0xa1);//��
	//I2C_Wait_Ack();
	temp=dI2C_Read_Byte(0);  //0  ����NACK
	dI2C_Stop();
	return temp;
}


u8 adWrite(u16 addr,u8 dt)
{
	aI2C_Start();
	/*if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);//д
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);//�������ݵ�ַ��λ
		
	}
	else
	{
		I2C_Send_Byte(0xa0);//������ַ+���ݵ�ַ
	}*/
	//I2C_Wait_Ack();
	aI2C_Send_Byte(addr);//˫�ֽ������ݵ�ַ��λ
													//���ֽ������ݵ�ַ��λ
	aI2C_Wait_Ack();
	aI2C_Send_Byte(dt);
	aI2C_Wait_Ack();
	aI2C_Stop();
	delay_ms(10);
	return(1);
}

u8 addWrite(u16 addr,u8 dt)
{
	bI2C_Start();
	/*if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);//д
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);//�������ݵ�ַ��λ
		
	}
	else
	{
		I2C_Send_Byte(0xa0);//������ַ+���ݵ�ַ
	}*/
	//I2C_Wait_Ack();
	bI2C_Send_Byte(addr);//˫�ֽ������ݵ�ַ��λ
													//���ֽ������ݵ�ַ��λ
	bI2C_Wait_Ack();
	bI2C_Send_Byte(dt);
	bI2C_Wait_Ack();
	bI2C_Stop();
	delay_ms(10);
	return(1);
}

u8 adddWrite(u16 addr,u8 dt)
{
	cI2C_Start();
	/*if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);//д
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);//�������ݵ�ַ��λ
		
	}
	else
	{
		I2C_Send_Byte(0xa0);//������ַ+���ݵ�ַ
	}*/
	//I2C_Wait_Ack();
	cI2C_Send_Byte(addr);//˫�ֽ������ݵ�ַ��λ
													//���ֽ������ݵ�ַ��λ
	cI2C_Wait_Ack();
	cI2C_Send_Byte(dt);
	cI2C_Wait_Ack();
	cI2C_Stop();
	delay_ms(10);
	return(1);
}

u8 addddWrite(u16 addr,u8 dt)
{
	dI2C_Start();
	/*if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);//д
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);//�������ݵ�ַ��λ
		
	}
	else
	{
		I2C_Send_Byte(0xa0);//������ַ+���ݵ�ַ
	}*/
	//I2C_Wait_Ack();
	dI2C_Send_Byte(addr);//˫�ֽ������ݵ�ַ��λ
													//���ֽ������ݵ�ַ��λ
	dI2C_Wait_Ack();
	dI2C_Send_Byte(dt);
	dI2C_Wait_Ack();
	dI2C_Stop();
	delay_ms(10);
	return(1);
}


void ad1Write(u16 addr,u8 dt,u8 c)
{
	aI2C_Start();
	/*if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);//д
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);//�������ݵ�ַ��λ
		
	}
	else
	{
		I2C_Send_Byte(0xa0);//������ַ+���ݵ�ַ
	}
	I2C_Wait_Ack();*/
	aI2C_Send_Byte(addr);//˫�ֽ������ݵ�ַ��λ
													//���ֽ������ݵ�ַ��λ
	aI2C_Wait_Ack();
	aI2C_Send_Byte(dt);
	aI2C_Wait_Ack();
	aI2C_Send_Byte(c);
	aI2C_Wait_Ack();
	aI2C_Stop();
	delay_ms(10);
}
void ad2Write(u16 addr,u8 dt,u8 c)
{
	
	
	bI2C_Start();
	/*if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);//д
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);//�������ݵ�ַ��λ
		
	}
	else
	{
		I2C_Send_Byte(0xa0);//������ַ+���ݵ�ַ
	}
	I2C_Wait_Ack();*/
	bI2C_Send_Byte(addr);//˫�ֽ������ݵ�ַ��λ
													//���ֽ������ݵ�ַ��λ
	bI2C_Wait_Ack();
	bI2C_Send_Byte(dt);
	bI2C_Wait_Ack();
	bI2C_Send_Byte(c);
	bI2C_Wait_Ack();
	bI2C_Stop();
	delay_ms(10);
}


u16 AT24Cxx_ReadTwoByte(u16 addr)
{
	u16 temp=0;
	I2C_Start();
	
	if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);//д
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);//�������ݵ�ַ��λ
		
	}
	else
	{
		I2C_Send_Byte(0xa0);//������ַ+���ݵ�ַ
	}
	I2C_Wait_Ack();
	I2C_Send_Byte(addr);//˫�ֽ������ݵ�ַ��λ
													//���ֽ������ݵ�ַ��λ
	I2C_Wait_Ack();
	
	I2C_Start();
	I2C_Send_Byte(0xa1);//��
	I2C_Wait_Ack();
	temp=I2C_Read_Byte(1);  //1  ����ACK
	temp<<=8;
	temp|=I2C_Read_Byte(0);  //0  ����NACK
	
	I2C_Stop();
	return temp;
}
void AT24Cxx_WriteTwoByte(u16 addr,u16 dt)
{
	I2C_Start();
	if(EE_TYPE>AT24C16)
	{
		I2C_Send_Byte(0xa0);//д
		I2C_Wait_Ack();
		I2C_Send_Byte(addr>>8);//�������ݵ�ַ��λ
		
	}
	else
	{
		I2C_Send_Byte(0xa0);//������ַ+���ݵ�ַ
	}
	I2C_Wait_Ack();
	I2C_Send_Byte(addr);//˫�ֽ������ݵ�ַ��λ
													//���ֽ������ݵ�ַ��λ
	I2C_Wait_Ack();
	I2C_Send_Byte(dt>>8);
	I2C_Wait_Ack();
	I2C_Send_Byte(dt&0xff);
	I2C_Wait_Ack();
	I2C_Stop();
	delay_ms(10);
}


