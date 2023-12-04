/*
 * File:   libuart4550.c
 * Author: gustavomendoza
 *
 * Created on December 14, 2021, 4:04 PM
 */


#include <xc.h>
#include"libuart4550.h"

void uartInit(){
    RCSTAbits.SPEN = 1;
    TRISCbits.RC7 = 1; //RX entrada
    TRISCbits.RC6 = 0; // TX Salida
    
    // registro de control para trasmicion
    TXSTAbits.TX9 = 0; // configuramos a trasmitir a 8 bits
    TXSTAbits.TXEN = 1; // habilitamos la trasmicion
    TXSTAbits.SYNC=0; // lo configugramos como asincrono
    TXSTAbits.SENDB = 0; // limpiamos bit de trasmicion
    TXSTAbits.BRGH = 0;
    TXSTAbits.TRMT = 1; // limpiamos bit de estatus
    // configuracion de registro RCSTA
    RCSTAbits.RX9 = 0;
    RCSTAbits.CREN = 1;
    RCSTAbits.ADDEN = 0;
    RCSTAbits.FERR = 0;
    RCSTAbits.OERR = 0;
    // Configuracion de BaudRate
    BAUDCONbits.ABDOVF = 0;
    BAUDCONbits.BRG16 = 1;
    SPBRG = 129;             // valor en decimal para trasmicion de 115200 baudios 9600
}

void uartTransmitter(unsigned char dataTrasmit){
    
    TXSTAbits.SYNC=0; // lo configugramos como asincrono
    RCSTAbits.SPEN = 1;
    TXSTAbits.TXEN = 1; // habilitamos la trasmicion
    //PIR1bits.TXIF = 1;
    TXSTAbits.TXEN = 1;
    while(!TXSTAbits.TRMT); //esperamos a que se pueda enviar la informacion
    TXREG = dataTrasmit;
    
}

unsigned char uartReceiver(){
    unsigned char receiverData;
    TXSTAbits.SYNC=0; // lo configugramos como asincrono
    RCSTAbits.SPEN = 1;
    RCSTAbits.CREN = 1;
    
    
    while(!PIR1bits.RCIF); // esperamos a recivir un dato
    receiverData = RCREG;
    return receiverData;
    
}
void uartPrint(unsigned char *string){
    int index =0;
    while(string != 0x00){
        uartTransmitter(string[index]);
        ++index;
    }
} 

void sendUART(unsigned char data){
    TXSTAbits.SYNC=0; // lo configugramos como asincrono
    RCSTAbits.SPEN = 1;
    TXSTAbits.TXEN = 1; // habilitamos la trasmicion
    //PIR1bits.TXIF = 1;
    TXSTAbits.TXEN = 1;
    while(!TXSTAbits.TRMT); //esperamos a que se pueda enviar la informacion
    TXREG = data;
}
void printUARTfloatln(float data){
    char string[20];
    sprintf(string, "%f", data);
    unsigned int index = 0;
    while(string[index] != 0x00){
        sendUART(string[index]);
        ++index;
    }
    sendUART('\n');
}


