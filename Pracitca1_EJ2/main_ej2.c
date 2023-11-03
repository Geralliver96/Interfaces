
#include<stdio.h>
#include"main.h"
#include <pic18f4550.h>

char seleccion;

unsigned int valor_ch[6];

void ADC_Init()
{
    ADCON0 =  0x00;
  ADCON1 =  0x0A; 
  ADCON2 = 0b00010111;  
  
  ADCON0bits.ADON = 1; 
}

unsigned int ADC_Read(unsigned char ch){
    if(ch>13){
        return 0;
    }else{
       ADCON0bits.GO_DONE = 1; 
  
  while(ADCON0bits.GO_DONE); 
  
  return ADRESH;
    }
}

void loop(){
    
     TRISC = 0b00000011;
    
      seleccion = PORTC & 0x03;
      
    switch (seleccion){
        case 0:
        PORTD = (unsigned char)valor_ch[0];
        break;
    case 1:
        PORTD = (unsigned char)valor_ch[1];
        break;
    case 2:
        PORTD = (unsigned char)valor_ch[2];
        break;
    case 3:
          PORTD = (unsigned char)valor_ch[3];
        break;
 
}
}