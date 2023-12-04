/* 
 * File:   libUSART18f4550.h
 * Author: gustavomendoza
 *
 * Created on July 13, 2023, 10:21 PM
 */

#ifndef USART18F4550_H
#define	USART18F4550_H

#include <stdio.h>
#include"configurationBits.h"

// Baud Rate
#define BAUD_RATE_2400 0
#define BAUD_RATE_9600 1
#define BAUD_RATE_19200 2
#define BAUD_RATE_57600 3
#define BAUD_RATE_115200 4

#define XTAL_4MHz 0
#define XTAL_8MHz 1
#define XTAL_20MHz 2
#define XTAL_40MHz 3

// Funasiones de Trasmicion y recepsion asincrona

void setupUART(unsigned char freq, unsigned char BaudRate);
// Funciones de envio de datos por serial asincrono
void sendUART(unsigned char data);
void printUART(char *string);
void printUARTln(char *string);
void printUARTInt(int data);
void printUARTIntln(int data);
void printUARTfloat(float data);
void printUARTfloatln(float data);
//FUnciones de recepcion serial asincrono
unsigned char receiverUART();


#endif	/* LIBUSART18F4550_H */

