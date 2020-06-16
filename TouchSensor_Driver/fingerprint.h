/******************************************************************************
 *
 * Module: Fingerprint
 *
 * File Name: fingerprint.h
 *
 * Description: Header file for the Fingerprint module
 *
 * Author: Mohamed Adel
 *
 *******************************************************************************/

#ifndef FINGERPRINT_H_
#define FINGERPRINT_H_

/*******************************************************************************
 *                                Includes                                     *
 *******************************************************************************/
#include "../UART_Driver/uart.h"

/*******************************************************************************
 *                     Definitions and configurations                          *
 *******************************************************************************/

///////////////////////////////////////////////////////////////////
/*
void FP_SA();
void FP_PWVC();
void FP_PWSC();
void FP_SSP();
void FP_SetControl();
void FP_ResetControl();
void FP_RSP();
void FP_ReadValideTemplateNumber();
void FP_AutoSearch();
void FP_GR_Identify();
void FP_genImg();
void FP_UpImage();
void FP_DownImage();
void FP_Img2Tz1();
void FP_Img2Tz2();
void FP_RegModel();
void FP_UpChar();
void FP_DownChar();
void FP_Store();
void FP_LoadChar();
void FP_DeleteChar();
void FP_Empty();
void FP_Match();
void FP_Search();
void FP_GetRandomCode();
void FP_WriteNotePad();
void FP_ReadNotePad();
void enroll();
void fingerPrint();
void FP_TC();


*/
/////////////////////////////////////////////////////////////////////////////

// Fingerprint configurations
/*
#define FINGERPRINT_UART_CHANNEL UART1
#define FINGERPRINT_UART_BAUDRATE 57600


#define HEADER 0xEF01
#define ADDRESS 0xFFFFFFFF
#define COMMAND_PACKET_ID 0x01
#define BAUD 57600



// Packet head
#define FINGERPRINT_PACKET_HEAD_H 0xEF
#define FINGERPRINT_PACKET_HEAD_L 0x01

// Packet flag
#define FINGERPRINT_COMMAND_PACKET 0x10
#define FINGERPRINT_DATA_PACKET 0x20
#define FINGERPRINT_LAST_PACKET 0x21
#define FINGERPRINT_RESPONSE_PACKET 0x30

// Commands
#define FINGERPRINT_ADD_FINGERPRINT 0x40
#define FINGERPRINT_DELETE_FINGERPRINT 0x42
#define FINGERPRINT_SEARCH_FINGERPRINT 0x44
#define FINGERPRINT_EMPTY_FINGERPRINT_DATABASE 0x46
#define FINGERPRINT_SEARCH_INFO_FINGERPRINT 0x4B
#define FINGERPRINT_DOWNLOAD_FINGERPRINT_TEMPLATE 0x50
#define FINGERPRINT_UPLOAD_FINGERPRINT_TEMPLATE 0x52
#define FINGERPRINT_READ_ID_NUMBER 0x60
#define FINGERPRINT_READ_USER_FLASH 0x62
#define FINGERPRINT_WRITE_USER_FLASH 0x64
#define FINGERPRINT_READ_PRODUCT_LOGO 0x80

// Response codes
#define FINGERPRINT_RECEIVE_CORRECT 0x01
#define FINGERPRINT_RECEIVE_ERROR 0x02
#define FINGERPRINT_OPERATION_SUCCESSFUL 0x31
#define FINGERPRINT_FINGERPRINT_DETECTED 0x32
#define FINGERPRINT_TIME_OUT 0x33
#define FINGERPRINT_FINGERPRINT_PROCEESS_FAILURE 0x34
#define FINGERPRINT_PARAMETER_ERROR 0x35
#define FINGERPRINT_FINGERPRINT_MATCH_ID 0x37
#define FINGERPRINT_FINGERPRINT_DOESNT_MATCH_ID 0x38
#define FINGERPRINT_FINGERPRINT_FOUND 0x39
#define FINGERPRINT_FINGERPRINT_UNFOUND 0x3A

// Boolean values
#define FALSE 0
#define TRUE 1

/*******************************************************************************
 *                     Functions Declarations                                  *
 *******************************************************************************/
/*void FINGERPRINT_init();
uint8_t FINGERPRINT_addFingerprint(uint16_t a_id);
uint8_t FINGERPRINT_deleteFingerprint(uint16_t a_id);
uint8_t FINGERPRINT_searchFingerprint(uint16_t a_startId, uint16_t a_numOfFingerprintsSearched);
uint8_t FINGERPRINT_emptyFingerprintDatabase();
uint8_t FINGERPRINT_searchFingerprintDatabase(uint16_t a_id);
uint8_t FINGERPRINT_downloadFingerprintTemplate(uint16_t a_id);
uint16_t FINGERPRINT_uploadFingerprintTemplate(uint16_t a_id);
uint8_t FINGERPRINT_readIdNumber();
uint8_t FINGERPRINT_readUserFlash(uint8_t a_numOfData, uint16_t a_address);
uint8_t FINGERPRINT_writeUserFlash(
    uint8_t a_numOfData, uint16_t a_address,
    uint8_t *a_data, uint8_t a_arraySize);
uint8_t FINGERPRINT_readProductFlag();*/

#endif /* fingerprint.h */