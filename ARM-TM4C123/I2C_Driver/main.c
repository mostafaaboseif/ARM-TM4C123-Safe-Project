#include "stdint.h"
#include "gpio.h"
#include "tm4c123gh6pm.h"
#include "C:\Users\mosta\Desktop\TivaWare_C_Series-2.1.4.178\examples\new prj\i2c.h"

int main()
{

	I2C_initMaster(I2C1,READ);
	I2C_setSlaveAddress(0x55);
	char data1,data2,data3;
	while(1)
{
		I2C_switchToRead();
		I2C1_MCS_R = 0b1011;  //start bit and run
		while((I2C1_MCS_R & (1<<0)) != 0 );
		data1=I2C1_MDR_R;
		
		I2C1_MCS_R = 0b01001; 	//run
		while((I2C1_MCS_R & (1<<0)) != 0 );
		data2=I2C1_MDR_R;
			
		I2C1_MCS_R = 0b01101;		//stop bit and run
		while((I2C1_MCS_R & (1<<0)) != 0 );
		data3=I2C1_MDR_R;
		
		I2C_switchToWrite();
		I2C_sendChar(data1);
		I2C_sendChar(data2);	
		I2C_sendChar(data3);
//	I2C_sendChar(data2);
//		if (data=='A')
//		{
//			GPIO_initPin(PORTF,PIN1,DIGITAL,OUTPUT);
//			GPIO_writePin(PORTF,PIN1,HIGH);
//		}
		

		
}
}



















