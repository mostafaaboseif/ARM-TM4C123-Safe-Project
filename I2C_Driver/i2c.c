#include "i2c.h"

void I2C_initMaster(I2C i2cAddress){
	switch(i2cAddress){
		case I2C0:
			(*SYSCTL_RCGCI2C) |= 0x01;
			while(!((*SYSCTL_PRI2C)|= 0x01));
			GPIO_initPin(PORTB,PIN2,DIGITAL,PERIPHERAL);
			GPIO_initPin(PORTB,PIN3,DIGITAL,PERIPHERAL);
			GPIO_setPullup(PORTB,PIN2);
			GPIO_setPullup(PORTB,PIN3);
			GPIO_setOpenDrain(PORTB,PIN3);
//		GPIO_setPCTL(PORTB,PIN2,I2C_F);
//		GPIO_setPCTL(PORTB,PIN3,I2C_F);
			GPIO_PORTB_PCTL_R &= ~(0x0000FF00);
			GPIO_PORTB_PCTL_R = (3<<12)|(3<<8);
			break;
		
		
		case I2C1:
			(*SYSCTL_RCGCI2C) |= 0x02;
			while(!((*SYSCTL_PRI2C)|= 0x02));			
			GPIO_initPin(PORTA,PIN6,DIGITAL,PERIPHERAL); //SCL
			GPIO_initPin(PORTA,PIN7,DIGITAL,PERIPHERAL); //SDA
			GPIO_setPullup(PORTA,PIN6);
			GPIO_setPullup(PORTA,PIN7);
			GPIO_setOpenDrain(PORTA,PIN7);
//		GPIO_setPCTL(PORTA,PIN6,I2C_F);
//		GPIO_setPCTL(PORTA,PIN7,I2C_F);
			GPIO_PORTA_PCTL_R &= ~(0xFF000000);
			GPIO_PORTA_PCTL_R = (3<<28)|(3<<24);
			break;
		
		case I2C2:
			(*SYSCTL_RCGCI2C) |= 0x04;
			while(!((*SYSCTL_PRI2C)|= 0x04));
			GPIO_initPin(PORTE,PIN4,DIGITAL,PERIPHERAL);
			GPIO_initPin(PORTE,PIN5,DIGITAL,PERIPHERAL);
			GPIO_setPullup(PORTE,PIN4);
			GPIO_setPullup(PORTE,PIN5);
			GPIO_setOpenDrain(PORTE,PIN5);
//		GPIO_setPCTL(PORTE,PIN4,I2C_F);
//		GPIO_setPCTL(PORTE,PIN5,I2C_F);
			GPIO_PORTE_PCTL_R &= ~(0x00FF0000);
			GPIO_PORTE_PCTL_R = (3<<20)|(3<<16);
			break;
		
		
		case I2C3:
			(*SYSCTL_RCGCI2C) |= 0x08;
			while(!((*SYSCTL_PRI2C)|= 0x08));
			GPIO_initPin(PORTD,PIN0,DIGITAL,PERIPHERAL);
			GPIO_initPin(PORTD,PIN1,DIGITAL,PERIPHERAL);
			GPIO_setPullup(PORTD,PIN0);
			GPIO_setPullup(PORTD,PIN1);
			GPIO_setOpenDrain(PORTD,PIN1);
//		GPIO_setPCTL(PORTD,PIN0,I2C_F);
//		GPIO_setPCTL(PORTD,PIN1,I2C_F);
			GPIO_PORTD_PCTL_R &= ~(0xFF000000);
			GPIO_PORTD_PCTL_R = (3<<4)|(3<<0);	
			break;
		}
	
	Memory(i2cAddress, I2C_MCR) = (1<<4);
	Memory(i2cAddress, I2C_MTPR) = 7; //100KHz
}


void I2C_setSlaveAddress(I2C i2c, uint8_t address){
	Memory(i2c,I2C_MSA) &= ~(0xFE);
	Memory(i2c,I2C_MSA) |= (address<<1);
}


void I2C_writeByte(volatile I2C i2c, uint8_t data , I2C_CONFIG conditions){
		Memory(i2c, I2C_MSA) &= ~(1<<0);
		Memory(i2c, I2C_MDR) = data;
		Memory(i2c, I2C_MCS) = conditions;
		while((Memory(i2c, I2C_MCS) & (1<<0)) != 0 );
}

void I2C_writeTransaction(volatile I2C i2c, char* data){
	Memory(i2c, I2C_MSA) &= ~(1<<0);
	int i=0;
	I2C_writeByte(i2c, data[i++],I2C_START_BIT | I2C_RUN);  //send start bit
	do{
		I2C_writeByte(i2c, data[i],I2C_RUN);  
		i++;
	}while(data[i]!=0);
	
	I2C_writeByte(i2c, data[i],I2C_RUN | I2C_STOP_BIT);  //send stop bit
	for(int j =0 ; j<100 ; j++);
}

char I2C_readByte(volatile I2C i2c, I2C_CONFIG conditions){
	Memory(i2c,I2C_MSA) |= (1<<0);
	Memory(i2c, I2C_MCS) = conditions;
	while((Memory(i2c, I2C_MCS) & (1<<0)) != 0 );
	return Memory(i2c, I2C_MDR);
}

void I2C_receiveString(volatile I2C i2c, int nb ,char* data){
		Memory(i2c,I2C_MSA) |= (1<<0);
		int i =0;
		Memory(i2c, I2C_MCS) = I2C_START_BIT | I2C_RUN;
		while((Memory(i2c, I2C_MCS) & (1<<0)) != 0 );
		data[i++] = Memory(i2c, I2C_MDR);
		
	while(i<(nb-1)){
		Memory(i2c, I2C_MCS) = I2C_RUN; 	//run
		while((Memory(i2c, I2C_MCS) & (1<<0)) != 0 );
		data[i++]=Memory(i2c, I2C_MDR);
	}
		Memory(i2c, I2C_MCS) = I2C_STOP_BIT | I2C_RUN;		//stop bit and run
		while((Memory(i2c, I2C_MCS) & (1<<0)) != 0 );
		data[i++]=Memory(i2c, I2C_MDR);
		data[i]=0; //add NULL to the end of the string
}


void I2C_initSlave(int address)
{
		(*SYSCTL_RCGCI2C) |= 0x02;
		while(!((*SYSCTL_PRI2C)|= 0x02));			
		GPIO_initPin(PORTA,PIN6,DIGITAL,PERIPHERAL); //SCL
		GPIO_initPin(PORTA,PIN7,DIGITAL,PERIPHERAL); //SDA
		GPIO_setPullup(PORTA,PIN6);
		GPIO_setPullup(PORTA,PIN7);
		GPIO_setOpenDrain(PORTA,PIN7);
		GPIO_PORTA_PCTL_R &= ~(0xFF000000);
		GPIO_PORTA_PCTL_R = (3<<28)|(3<<24);
		
		I2C1_MCR_R = (1<<5);
		I2C1_SCSR_R = 0x01; 
		I2C1_SOAR_R = address;
		
		I2C1_SICR_R |= 0x01;
		I2C1_SIMR_R |= 0x01;
		NVIC_EN1_R |= (1<<5);
}
void (*callBackFn)(char);
void I2C_setCallBackFn(void (*function)(char))
{
	callBackFn = function;
}
char data;
void I2C1_Handler()
{
	I2C1_SMIS_R &= ~(1<<0);
	if(I2C1_SCSR_R & (1<<0))
	{
		data = I2C1_SDR_R;
    callBackFn(data);
	}
}




