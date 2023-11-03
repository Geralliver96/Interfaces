
#include <pic18f4550.h>

#include"main.h"
int lectura;

void setup(){
    //Configurando registro D
    LATD = 0;
    PORTD = 0;
    TRISD = 0;
    
    LATC = 0;
    PORTC = 0;
    TRISC &= 0b11111100;
    
    setupADC(0);
}

void loop(){
    lectura = readADC(0);
    LATD = ADRESL;
    LATC = ADRESH;
   
}



