/******************************************************************************
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

const Uart UART = FINGERPRINT_UART_CHANNEL;

/*******************************************************************************
 *                       Functions Definitions                                 *
 *******************************************************************************/

void FINGERPRINT_init()
{
    UART_Init(UART, FINGERPRINT_UART_BAUDRATE);
}

uint8_t FINGERPRINT_addFingerprint(uint16_t a_id)
{
    // Sending
    // Send packet head
    UART_sendChar(UART, FINGERPRINT_PACKET_HEAD_H);
    UART_sendChar(UART, FINGERPRINT_PACKET_HEAD_L);
    // Send packet flag
    UART_sendChar(UART, FINGERPRINT_COMMAND_PACKET);
    // Send packet length
    UART_sendChar(UART, 0x03);
    // Send packet content
    UART_sendChar(UART, FINGERPRINT_ADD_FINGERPRINT);
    UART_sendChar(UART, a_id >> 8);
    UART_sendChar(UART, a_id & 0xff);
    // Send check sum
    uint8_t check_sum = FINGERPRINT_PACKET_HEAD_H + FINGERPRINT_PACKET_HEAD_L + FINGERPRINT_COMMAND_PACKET + FINGERPRINT_ADD_FINGERPRINT + 0x03 + (a_id >> 8) + (a_id & 0xff);
    UART_sendChar(UART, check_sum);

    // Receiving
    FINGERPRINT_readPacket();
    FINGERPRINT_readPacket();
    FINGERPRINT_readPacket();
}

uint8_t FINGERPRINT_deleteFingerprint(uint16_t a_id)
{
    // Send packet head
    UART_sendChar(UART, FINGERPRINT_PACKET_HEAD_H);
    UART_sendChar(UART, FINGERPRINT_PACKET_HEAD_L);
    // Send packet flag
    UART_sendChar(UART, FINGERPRINT_COMMAND_PACKET);
    // Send packet length
    UART_sendChar(UART, 0x03);
    // Send packet content
    UART_sendChar(UART, FINGERPRINT_DELETE_FINGERPRINT);
    UART_sendChar(UART, a_id >> 8);
    UART_sendChar(UART, a_id & 0xff);
    // Send check sum
    uint8_t check_sum = FINGERPRINT_PACKET_HEAD_H + FINGERPRINT_PACKET_HEAD_L + FINGERPRINT_COMMAND_PACKET + FINGERPRINT_DELETE_FINGERPRINT + 0x03 + (a_id >> 8) + (a_id & 0xff);
    UART_sendChar(UART, check_sum);

    // Receiving
    FINGERPRINT_readPacket();
    FINGERPRINT_readPacket();
}

uint8_t FINGERPRINT_searchFingerprint(uint16_t a_startId, uint16_t a_numOfFingerprintsSearched)
{
    // Send packet head
    UART_sendChar(UART, FINGERPRINT_PACKET_HEAD_H);
    UART_sendChar(UART, FINGERPRINT_PACKET_HEAD_L);
    // Send packet flag
    UART_sendChar(UART, FINGERPRINT_COMMAND_PACKET);
    // Send packet length
    UART_sendChar(UART, 0x05);
    // Send packet content
    UART_sendChar(UART, FINGERPRINT_DELETE_FINGERPRINT);
    UART_sendChar(UART, a_startId >> 8);
    UART_sendChar(UART, a_startId & 0xff);
    UART_sendChar(UART, a_numOfFingerprintsSearched >> 8);
    UART_sendChar(UART, a_numOfFingerprintsSearched & 0xff);
    // Send check sum
    uint8_t check_sum = FINGERPRINT_PACKET_HEAD_H + FINGERPRINT_PACKET_HEAD_L + FINGERPRINT_COMMAND_PACKET + FINGERPRINT_DELETE_FINGERPRINT + 0x05 + (a_startId >> 8) + (a_startId & 0xff) + (a_numOfFingerprintsSearched >> 8) + (a_numOfFingerprintsSearched & 0xff);
    UART_sendChar(UART, check_sum);

    // Receiving
    for (size_t i = 0; i < 10; i++)
    {
        UART_readChar(UART);
    }
    const uint8_t packet_length = UART_readChar(UART);
    const uint8_t result = (UART_readChar(UART) == 0x04);
    for (size_t i = 0; i < packet_length + 1; i++)
    {
        UART_readChar(UART);
    }
    return result;
}

uint8_t FINGERPRINT_emptyFingerprintDatabase()
{
    // Send packet head
    UART_sendChar(UART, FINGERPRINT_PACKET_HEAD_H);
    UART_sendChar(UART, FINGERPRINT_PACKET_HEAD_L);
    // Send packet flag
    UART_sendChar(UART, FINGERPRINT_COMMAND_PACKET);
    // Send packet length
    UART_sendChar(UART, 0x01);
    // Send packet content
    UART_sendChar(UART, FINGERPRINT_EMPTY_FINGERPRINT_DATABASE);
    // Send check sum
    uint8_t check_sum = FINGERPRINT_PACKET_HEAD_H + FINGERPRINT_PACKET_HEAD_L + FINGERPRINT_COMMAND_PACKET + FINGERPRINT_EMPTY_FINGERPRINT_DATABASE + 0x01;
    UART_sendChar(UART, check_sum);
}

uint8_t FINGERPRINT_searchFingerprintDatabase(uint16_t a_id)
{
    // Send packet head
    UART_sendChar(UART, FINGERPRINT_PACKET_HEAD_H);
    UART_sendChar(UART, FINGERPRINT_PACKET_HEAD_L);
    // Send packet flag
    UART_sendChar(UART, FINGERPRINT_COMMAND_PACKET);
    // Send packet length
    UART_sendChar(UART, 0x03);
    // Send packet content
    UART_sendChar(UART, FINGERPRINT_SEARCH_INFO_FINGERPRINT);
    UART_sendChar(UART, a_id >> 8);
    UART_sendChar(UART, a_id & 0xff);
    // Send check sum
    const uint8_t check_sum = FINGERPRINT_PACKET_HEAD_H + FINGERPRINT_PACKET_HEAD_L + FINGERPRINT_COMMAND_PACKET + 0x03 + FINGERPRINT_SEARCH_INFO_FINGERPRINT + (a_id >> 8) + (a_id & 0xff);
    UART_sendChar(UART, check_sum);

    // Receiving
    for (size_t i = 0; i < 10; i++)
    {
        UART_readChar(UART);
    }
    const uint8_t result = (UART_readChar(UART) == 0x37);
    UART_readChar(UART);
    return result;
}

uint8_t FINGERPRINT_downloadFingerprintTemplate(uint16_t a_id)
{
}

uint16_t FINGERPRINT_uploadFingerprintTemplate(uint16_t a_id)
{
}

uint8_t FINGERPRINT_readIdNumber()
{
}

uint8_t FINGERPRINT_readUserFlash(uint8_t a_numOfData, uint16_t a_address)
{
}

uint8_t FINGERPRINT_writeUserFlash(uint8_t a_numOfData, uint16_t a_address, uint8_t *a_data, uint8_t a_arraySize)
{
}

uint8_t FINGERPRINT_readProductFlag()
{
}

static void FINGERPRINT_readPacket()
{
    // Receive packet head
    UART_readChar(UART);
    UART_readChar(UART);
    // Receive packet flag
    UART_readChar(UART);
    // Receive packet length
    uint8_t packetLength = UART_readChar(UART);
    // Receive packet content
    for (size_t i = 0; i < packetLength; i++)
    {
        UART_readChar(UART);
    }
    // Receive check sum
    UART_readChar(UART);
}