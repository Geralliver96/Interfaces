#include <xc.h>
#include <pic18f4550.h>
#include"main.h"

char seleccion;

void setup(){
    
 ADCON1 = 0b00001111;
    //configuracion puerto A
    LATA = 0x00;
    PORTA = 0x00;
    TRISA = 0b00111111;
    
    //configuracion puerto B
    LATB = 0x00;
    PORTB = 0x00;
    TRISB = 0b11111111;
    
    //configuracion puerto C
    LATC = 0x00;
    PORTC = 0x00;
    TRISC = 0b0001111;
    
    //configuracion puerto D
    LATD = 0x00;
    PORTD = 0x00;
    TRISD = 0x00;

}

void loop(){
    
   // LATA = 0b11111001;
  
        LATD = 0x00;
        seleccion = PORTC & 0x0F;
      //seleccion = 0;
        switch(seleccion){
            case 0:
                LATD = PORTA;
                __delay_us(100);
               // LATD = 0b11111001;
                break;
            case 1:
                LATD = PORTB;
                __delay_us(100);
                //LATD = 0b11111001;
            break;
        case 2:
            LATD = PORTA + PORTB;
            break;
        case 3:
            LATD = PORTB - PORTA;
            break;
        case 4:
            LATD = PORTB & PORTA;
            break;
        case 8:
            LATD = PORTB | PORTA;
            break;
            
    }

}



