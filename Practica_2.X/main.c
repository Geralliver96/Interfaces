
#include <xc.h>
#include "configurationBits.h"
#include "libuart4550.h"

void main(void) {
    
    
    uartInit();// inicializamos modulo uart
    char mensaje[] = "Hola Mundo\n";
    while(1){//Ciclo Principal
        uartPrint(mensaje);
        __delay_ms(1000);
    }
    
    return;
}
