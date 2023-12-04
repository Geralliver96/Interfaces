/* 
 * File:   ADC4550.h
 * Author: gustavomendoza
 *
 * Created on August 2, 2023, 1:55 PM
 */

#ifndef ADC4550_H
#define	ADC4550_H


#include <stdio.h>
#include"configurationBits.h"

#define ADC_XTAL_4MHz 0
#define ADC_XTAL_8MHz 1
#define ADC_XTAL_20MHz 2
#define ADC_XTAL_40MHz 3

#define AN0 0
#define AN1 1
#define AN2 2
#define AN3 3
#define AN4 4
#define AN5 5
#define AN6 6
#define AN7 7
#define AN8 8
#define AN9 9
#define AN10 10
#define AN11 11
#define AN12 12

void initADC(unsigned char XTAL_Freq, unsigned char channels);

unsigned int readADC(unsigned char channel);

#endif	/* ADC4550_H */

