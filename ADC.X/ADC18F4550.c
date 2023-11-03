#include <pic18f4550.h>

#include"ADC18F4550.h"

void setupADC(unsigned char channels){
    
    //ADCON0
    if(channels>12){
        ADCON0bits.CHS = 0;
    }else{
        ADCON0bits.CHS = channels;
    }
    switch(channels){
        case 0:
            ADCON0bits.CHS0 = 0;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS3 = 0;
            break;
        case 1:
            ADCON0bits.CHS0 = 1;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS3 = 0;
            break;
        case 2:
            ADCON0bits.CHS0 = 0;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS3 = 0;
            break;   
    }
    ADCON0bits.GODONE = 0;
    ADCON0bits.ADON = 1;
    
    //ADCON1
    ADCON1bits.VCFG0 = 0;
    ADCON1bits.VCFG01 = 0;
    if(channels>12){
        ADCON1bits.PCFG = 0;
    }else{
        ADCON1bits.PCFG = channels;
    }
    //Configurcion ADCON2
    ADCON2bits.ADFM = 1;
    ADCON2bits.ACQT = 0b010;
    ADCON2bits.ADCS = 0b101; 
}

unsigned int readADC(unsigned char channel){
    //Seleccion de canal
     if(channel>12){
        ADCON0bits.CHS = 0;
    }else{
        ADCON0bits.CHS = channel;
    }
     ADCON0bits.GODONE = 1;
     while(ADCON0bits.GODONE);
     return ADRES;
     
}
