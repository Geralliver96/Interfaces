/* 
 * File:   ADC18F4550.h
 * Author: gerar
 *
 * Created on 19 de octubre de 2023, 09:31 PM
 */

#ifndef ADC18F4550_H
#define	ADC18F4550_H

#include"configuracionBits.h"

void setupADC(unsigned char channels);

unsigned int readADC(unsigned char channel);

#endif	/* ADC18F4550_H */

