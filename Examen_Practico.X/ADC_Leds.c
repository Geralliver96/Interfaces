
#include "adc.h"

void ADC_Init()
{
    ADCON0 =  0x00;
  ADCON1 =  0x0A; 
  ADCON2 = 0b10010111; 
  
  ADCON0bits.ADON = 1; 
}

unsigned int ADC_Read(unsigned char ch){
    if(ch>13){
        return 0;
    }else{
       ADCON0bits.GO_DONE = 1; 
  
  while(ADCON0bits.GO_DONE); 
  
  return ADRES;
    }
}
   


   