/*/******************************************************************************
 *
 * Module: Fingerprint
 *
 * File Name: fingerprint.c
 *
 * Description: Source file for the Fingerprint module
 *
 * Author: Mohamed Adel
 *
 *******************************************************************************/

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "../UART_Driver/uart.h"
#include "fingerprint.h"

/*******************************************************************************
 *                         Global Variables                                    *
 *******************************************************************************/



//const Uart UART = FINGERPRINT_UART_CHANNEL;

/*******************************************************************************

 *                       Functions Definitions                                 *
 ****************************************************************************

void FP_SA(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x07);
	//inst
	UART_sendChar(UART1,0x15);
	//password
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x1D);
}




void FP_PWVC(){
	//header
	UART_sendChar(UART1,0xEF);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF); 
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x07);
	//inst
	UART_sendChar(UART1,0x13);
	//password
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x1B);
}


void FP_PWSC(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x07);
	//inst
	UART_sendChar(UART1,0x12);
	//password
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x1A);
}
void FP_SSP(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x05);
	//inst
	UART_sendChar(UART1,0x0E);
	//para
	UART_sendChar(UART1,0x00);
	//content
	UART_sendChar(UART1,0x06);
	
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x1A);
}

void FP_SetControl(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x04);
	//inst
	UART_sendChar(UART1,0x17);
	//control
	UART_sendChar(UART1,0x01);
	
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x1D);
}
void FP_ResetControl(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x04);
	//inst
	UART_sendChar(UART1,0x17);
	//control
	UART_sendChar(UART1,0x00);
	
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x1C);
}
void FP_RSP(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x03);
	//inst
	UART_sendChar(UART1,0x1f);
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x23);
}

void FP_ReadValideTemplateNumber(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x03);
	//inst
	UART_sendChar(UART1,0x1D);

	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x21);
}
void FP_AutoSearch(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x08);
	//inst
	UART_sendChar(UART1,0x32);
	//capture
	UART_sendChar(UART1,0x20);
	//number
	UART_sendChar(UART1,0x00);
  UART_sendChar(UART1,0x00);
	//quantity
	UART_sendChar(UART1,0x05);
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x65);
}

void FP_GR_Identify(){
	//header
	UART_sendChar(UART1,0xEF);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x03);
	//inst
	UART_sendChar(UART1,0x34);

	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x38);
}
void FP_genImg(){
	//header
	UART_sendChar(UART1,0xEF);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x03);
	//inst
	UART_sendChar(UART1,0x01);

	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x05);
}


void FP_UpImage(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x03);
	//inst
	UART_sendChar(UART1,0x0A);

	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x0E);
}
void FP_DownImage(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x03);
	//inst
	UART_sendChar(UART1,0x0B);

	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x0F);
}

void FP_Img2Tz1(){
	//header
	UART_sendChar(UART1,0xEF);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x04);
	//inst
	UART_sendChar(UART1,0x02);
  //char
	UART_sendChar(UART1,0x01);
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x08);
}
void FP_Img2Tz2(){
	//header
	UART_sendChar(UART1,0xEF);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x04);
	//inst
	UART_sendChar(UART1,0x02);
  //char
	UART_sendChar(UART1,0x01);
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x09);
}
void FP_RegModel(){
	//header
	UART_sendChar(UART1,0xEF);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x03);
	//inst
	UART_sendChar(UART1,0x05);

	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x09);
}

void FP_UpChar(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x04);
	//inst
	UART_sendChar(UART1,0x08);
  //buffer
	UART_sendChar(UART1,0x01);
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x0E);
}
void FP_DownChar(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x04);
	//inst
	UART_sendChar(UART1,0x09);
  //buffer
	UART_sendChar(UART1,0x01);
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x0F);
}
void FP_Store(){
	//header
	UART_sendChar(UART1,0xEF);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x06);
	//inst
	UART_sendChar(UART1,0x06);
  //buffer
	UART_sendChar(UART1,0x00);
	//pge id
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x0D);
}

void FP_LoadChar(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x06);
	//inst
	UART_sendChar(UART1,0x07);
  //buffer
	UART_sendChar(UART1,0x01);
	//pge id
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x0F);
}
void FP_DeleteChar(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x07);
	//inst
	UART_sendChar(UART1,0x0C);
	//pge id
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	//n of templates to be deleted
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x01);
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x0F);
}

void FP_Empty(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x03);
	//inst
	UART_sendChar(UART1,0x0d);

	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x11);
}
void FP_Match(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x03);
	//inst
	UART_sendChar(UART1,0x03);

	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x07);
}

void FP_Search(){
	//header
	UART_sendChar(UART1,0xEF);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x08);
	//inst
	UART_sendChar(UART1,0x04);
	//buffer
	UART_sendChar(UART1,0x01);
	//page start
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	//page num
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x0E);
}
void FP_GetRandomCode(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x03);
	//inst
	UART_sendChar(UART1,0x14);

	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x18);
}

void FP_WriteNotePad(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x24);
	//inst
	UART_sendChar(UART1,0x18);
  //page number
	UART_sendChar(UART1,0x00);
	//data
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x00);
	
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x3C);
}
void FP_ReadNotePad(){
	//header
	UART_sendChar(UART1,0xEE);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x04);
	//inst
	UART_sendChar(UART1,0x19);
//page no
	UART_sendChar(UART1,0x00);

	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x1E);
}
void FP_TC(){
	//header
	UART_sendChar(UART1,0xEF);
	UART_sendChar(UART1,0x01);
	//adder
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	UART_sendChar(UART1,0xFF);
	//id
	UART_sendChar(UART1,0x01);
	//length
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x03);
	//inst
	UART_sendChar(UART1,0x1D);
	//sum
	UART_sendChar(UART1,0x00);
	UART_sendChar(UART1,0x21);
}
	
void enroll1(){
	FP_PWVC();
	FP_genImg();
	FP_Img2Tz1();
	FP_genImg();
	FP_Img2Tz2();
	FP_RegModel();
	FP_Store();
}
void fingerPrint(){ 
	FP_PWVC();
	FP_TC();
	FP_genImg();
	FP_Img2Tz1();
	FP_GR_Identify();
}
	                                                                                  */