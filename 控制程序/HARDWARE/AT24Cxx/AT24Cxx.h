#ifndef __AT24Cxx_H
#define __AT24Cxx_H
#include "sys.h"
//µ¥×Ö½ÚÑ°Ö·
#define AT24C01 127
#define AT24C02 255
#define AT24C04 511
#define AT24C08 1023
#define AT24C16 2047
//Ë«×Ö½ÚÑ°Ö·
#define AT24C32 4095
#define AT24C64 8191
#define AT24C128 16383
#define AT24C256 32767



#define EE_TYPE AT24C02
u8 AT24Cxx_ReadOneByte(u16 addr);
void AT24Cxx_WriteOneByte(u16 addr,u8 dt);
void AT24Cxx_WriteTwoByte(u16 addr,u16 dt);
u16 AT24Cxx_ReadTwoByte(u16 addr);
u8 adWrite(u16 addr,u8 dt);
void ad1Write(u16 addr,u8 dt,u8 c);
void ad2Write(u16 addr,u8 dt,u8 c);
u8 adRead(u16 addr);
u8 ad1Read(u16 addr);
u8 ad2Read(u16 addr);
u8 ad3Read(u16 addr);
u8 addWrite(u16 addr,u8 dt);
u8 adddWrite(u16 addr,u8 dt);
u8 addddWrite(u16 addr,u8 dt);
#endif



