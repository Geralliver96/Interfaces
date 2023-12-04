/*
 * File:   UART XC8 Library for Pic 18f4550
 * Author:  Ing. Gustavo David Mendoza Pinto
 * Comments: 
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef LIBUART4550
#define	LIBUART4550

#include <xc.h> // include processor files - each processor file is guarded.
#include<stdio.h>
#include"configurationBits.h"

void uartInit();

void uartTransmitter(unsigned char dataTrasmit);

unsigned char uartReceiver();

void uartPrint(unsigned char *string);

#endif	/* XC_HEADER_TEMPLATE_H */
