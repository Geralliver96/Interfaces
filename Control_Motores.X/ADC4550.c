/*
 * File:   ADC4550.c
 * Author: gustavomendoza
 *
 * Created on August 2, 2023, 1:55 PM
 */


#include <xc.h>
#include"ADC4550.h"

void initADC(unsigned char XTAL_Freq, unsigned char channels){
    ADCON1bits.PCFG = channels;
    ADCON1bits.VCFG = 0;
    ADCON2bits.ADFM = 1; // justificado a la derecha
    switch(XTAL_Freq){
        case ADC_XTAL_4MHz:
            ADCON2bits.ADCS = 4;
            ADCON2bits.ACQT = 2; // Tiempo de adquisición 4 us
            
            break;
        case ADC_XTAL_8MHz:
            ADCON2bits.ADCS = 1;
            ADCON2bits.ACQT = 2; // Tiempo de adquisición 3 us
            break;
        case ADC_XTAL_20MHz:
            //configuramos el TAD
            ADCON2bits.ADCS = 6;
            ADCON2bits.ACQT = 2; // Tiempo de adquisición 3.2 us
            break;
        case ADC_XTAL_40MHz:
            ADCON2bits.ADCS = 2;
            ADCON2bits.ACQT = 2; //// Tiempo de adquisición 4 us
            break;
    }
    
    
}

unsigned int readADC(unsigned char channel){
    if(channel > 13){
        return 0;
    }
    ADCON0bits.CHS = channel;
    ADCON0bits.ADON = 1;
    ADCON0bits.GO_DONE = 1;
    while(ADCON0bits.GO_DONE);
    ADCON0bits.ADON = 0;
    return ADRES;  
}
