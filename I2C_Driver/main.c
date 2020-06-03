//#include "stdint.h"
//#include "gpio.h"
//#include "tm4c123gh6pm.h"
//#include "C:\Users\mosta\Desktop\TivaWare_C_Series-2.1.4.178\examples\new prj\i2c.h"
//#include "C:\Users\mosta\Desktop\TivaWare_C_Series-2.1.4.178\examples\new prj\uart.h"

//char data;
//void test(char data)
//{
//	UART_sendChar(UART1,data);
//}
//int main()
//{	
//	UART_Init(UART1,9600);
//	GPIO_initPin(PORTF,PIN1,DIGITAL,OUTPUT);
//	GPIO_writePin(PORTF,PIN1,HIGH);
//	
//	I2C_initSlave(0x50);
//	I2C_setCallBackFn(test);
//	
//	while(1)
//	{
//		
//	}
//}




//#include "stdint.h"
//#include "gpio.h"
//#include "tm4c123gh6pm.h"
//#include "C:\Users\mosta\Desktop\TivaWare_C_Series-2.1.4.178\examples\new prj\i2c.h"
//#include "C:\Users\mosta\Desktop\TivaWare_C_Series-2.1.4.178\examples\new prj\uart.h"

//int main()
//{	
//	(*SYSCTL_RCGCI2C) |= 0x02;
//		while(!((*SYSCTL_PRI2C)|= 0x02));			
//		GPIO_initPin(PORTA,PIN6,DIGITAL,PERIPHERAL); //SCL
//		GPIO_initPin(PORTA,PIN7,DIGITAL,PERIPHERAL); //SDA
//		GPIO_setPullup(PORTA,PIN6);
//		GPIO_setPullup(PORTA,PIN7);
//		GPIO_setOpenDrain(PORTA,PIN7);
//		GPIO_PORTA_PCTL_R &= ~(0xFF000000);
//		GPIO_PORTA_PCTL_R = (3<<28)|(3<<24);
//		I2C1_MCR_R = (1<<4);
//		I2C1_MTPR_R = 7; //100KHz		
//		I2C1_MSA_R = (0x50<<1);
//		I2C1_MSA_R &= ~(1<<0);
//	while(1)
//	{
//		I2C_writeByte('a',0x07);
//	}
//}













#include "stdint.h"
#include "gpio.h"
#include "tm4c123gh6pm.h"
#include "C:\Users\mosta\Desktop\TivaWare_C_Series-2.1.4.178\examples\new prj\i2c.h"
#include "C:\Users\mosta\Desktop\TivaWare_C_Series-2.1.4.178\examples\new prj\uart.h"


int main()
{	
	I2C_initMaster(I2C1, READ);
	char str[4]= "abcd" ;
	unsigned char x = 10;
//			
	
	//////////////eeprom read
	I2C_switchToWrite();
	I2C_setSlaveAddress(0x50);
	I2C_writeByte(0x00,0x03);
	I2C_writeByte(0x06,0x01);
	I2C_switchToRead();
	I2C_setSlaveAddress(0x50);
	str[0]=I2C_readByte(0b1011);
	str[1]=I2C_readByte(0b1001);
	str[2]=I2C_readByte(0b1001);
	str[3]=I2C_readByte(0b1101);
	UART_Init(UART1,9600);		
	UART_sendChar(UART1,str[0]);
	UART_sendChar(UART1,str[1]);
	UART_sendChar(UART1,str[2]);
	UART_sendChar(UART1,str[3]);	
	
	//////////////eeprom write
//	I2C_setSlaveAddress(0x50);
//	I2C_switchToWrite();
//	I2C_writeByte(0x00,0x03);
//	I2C_writeByte(0x0F,0x01);
//	I2C_writeByte(32,0x01);
//	I2C_writeByte(str[1],0x01);
//	I2C_writeByte(str[2],0x01);
//	I2C_writeByte(str[3],0x05);


//////////////eeprom write 2
//	I2C_setSlaveAddress(0x50);
//	I2C_writeByte(0x00,0x03);
//	I2C_writeByte(0x00,0x01);
//	x=1;
//	for(int j =0 ; j<5 ; j++)
//		I2C_writeByte(x,0x01);
//	I2C_writeByte(x,0x05);


	////////////////readByte
//		I2C_setSlaveAddress(0x50);
//		str[0]=I2C_readByte(0b1011);
//		str[1]=I2C_readByte(0b1001);
//		str[2]=I2C_readByte(0b1101);
//		str[3]=0;
//		I2C_writeTransaction(str);
//	
	while(1)
{	

	


///////////////////2 arduinos addressing in the same transaction
//	I2C_setSlaveAddress(0x55);
//	I2C_writeByte('a',0x03);  //send start bit	
//	I2C_writeByte('b',0x01);
//	
//	I2C_setSlaveAddress(0x53);
//	I2C_writeByte('c',0x03);
//	I2C_writeByte('d',0x05);
//	for(int j =0 ; j<100 ; j++);
	
	
	
}


}