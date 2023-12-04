/*
 * File:   libUSART18f4550.c
 * Author: gustavomendoza
 *
 * Created on July 13, 2023, 10:22 PM
 */

#include"USART18f4550.h"


unsigned char *endl = "\n";

void setupUART(unsigned char freq, unsigned char BaudRate){
    TRISCbits.RC7 = 1; //RX entrada
    TRISCbits.RC6 = 0; // TX Salida
    // registro de control para trasmicion
    TXSTAbits.TX9 = 0; // configuramos a trasmitir a 8 bits
    TXSTAbits.TXEN = 1; // habilitamos la trasmicion
    TXSTAbits.SENDB = 0; // limpiamos bit de trasmicion
    TXSTAbits.TRMT = 1; // limpiamos bit de estatus
    
     // configuracion de registro RCSTA
    RCSTAbits.SPEN = 1;
    RCSTAbits.RX9 = 0;
    RCSTAbits.CREN = 1;
    RCSTAbits.ADDEN = 0;
    RCSTAbits.FERR = 0;
    RCSTAbits.OERR = 0;
    
    switch(freq){
        case XTAL_4MHz:
            switch(BaudRate){
                case BAUD_RATE_2400:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 0;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 0;
                    SPBRGH = 0;
                    SPBRG = 25;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_9600:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 0;
                    SPBRGH = 0;
                    SPBRG = 25;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_19200:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 0;
                    SPBRGH = 0;
                    SPBRG = 12;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_57600:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0;
                    SPBRG = 16;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_115200:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0;
                    SPBRG = 8;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                default:
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 0;
                    SPBRGH = 0;
                    SPBRG = 25;             // valor en decimal para trasmicion de 115200 baudios
                    break;      
            }
            break;
        case XTAL_8MHz:
            switch(BaudRate){
                case BAUD_RATE_2400:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0x03;
                    SPBRG = 0x40;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_9600:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 0;
                    SPBRGH = 0;
                    SPBRG = 51;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_19200:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 0;
                    SPBRGH = 0;
                    SPBRG = 25;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_57600:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configuramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0;
                    SPBRG = 34;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_115200:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0;
                    SPBRG = 34;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                default:
                   // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 0;
                    SPBRGH = 0;
                    SPBRG = 51;             // valor en decimal para trasmicion de 115200 baudios
                    break;      
            }
            break;
        case XTAL_20MHz:
            switch(BaudRate){
                case BAUD_RATE_2400:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 0;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0x01;
                    SPBRG = 0x03;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_9600:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0x02;
                    SPBRG = 0x08;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_19200:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 0;
                    SPBRGH = 0;
                    SPBRG = 64;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_57600:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configuramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0;
                    SPBRG = 86;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_115200:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0;
                    SPBRG = 42;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                default:
                   // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 0;
                    SPBRGH = 0;
                    SPBRG = 51;             // valor en decimal para trasmicion de 115200 baudios
                    break;      
            }
            break;
        case XTAL_40MHz:
            switch(BaudRate){
                case BAUD_RATE_2400:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 0;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0x04;
                    SPBRG = 0x10;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_9600:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0x04;
                    SPBRG = 0x10;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_19200:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0x02;
                    SPBRG = 0x08;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_57600:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configuramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0;
                    SPBRG = 172;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_115200:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0;
                    SPBRG = 42;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                default:
                   // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0;
                    SPBRG = 86;             // valor en decimal para trasmicion de 115200 baudios
                    break;      
            }
            break;
        default:
            switch(BaudRate){
                case BAUD_RATE_2400:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 0;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 0;
                    SPBRGH = 0;
                    SPBRG = 25;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_9600:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 0;
                    SPBRGH = 0;
                    SPBRG = 25;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_19200:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 0;
                    SPBRGH = 0;
                    SPBRG = 12;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_57600:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0;
                    SPBRG = 16;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                case BAUD_RATE_115200:     
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 1;
                    SPBRGH = 0;
                    SPBRG = 8;             // valor en decimal para trasmicion de 115200 baudios
                    break;
                default:
                    // Configuracion de BaudRate
                    TXSTAbits.SYNC=0; // lo configugramos como asincrono
                    TXSTAbits.BRGH = 1;
                    BAUDCONbits.ABDOVF = 0;
                    BAUDCONbits.BRG16 = 0;
                    SPBRGH = 0;
                    SPBRG = 25;             // valor en decimal para trasmicion de 115200 baudios
                    break;      
            }
            break;
    }
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
    RCSTAbits.SPEN = 1;
    RCSTAbits.RX9 = 0;
    RCSTAbits.CREN = 1;
    RCSTAbits.ADDEN = 0;
    RCSTAbits.FERR = 0;
    RCSTAbits.OERR = 0;
    // Configuracion de BaudRate
    BAUDCONbits.ABDOVF = 0;
    BAUDCONbits.BRG16 = 1;
    SPBRG = 10;             // valor en decimal para trasmicion de 115200 baudios
    
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

void printUART(char *string){
    unsigned int index = 0;
    while(string[index] != 0x00){
        sendUART(string[index]);
        ++index;
    }
}
void printUARTln(char *string){
    unsigned int index = 0;
    while(string[index] != 0x00){
        sendUART(string[index]);
        ++index;
    }
    sendUART(endl[0]);
}
void printUARTInt(int data){
    char string[15];
    sprintf(string, "%d", data);
    unsigned int index = 0;
    while(string[index] != 0x00){
        sendUART(string[index]);
        ++index;
    }
}
void printUARTIntln(int data){
    char string[15];
    sprintf(string, "%d", data);
    unsigned int index = 0;
    while(string[index] != 0x00){
        sendUART(string[index]);
        ++index;
    }
    
    sendUART(endl[0]);
}

void printUARTfloat(float data){
    char string[20];
    sprintf(string, "%f", data);
    unsigned int index = 0;
    while(string[index] != 0x00){
        sendUART(string[index]);
        ++index;
    }
}
void printUARTfloatln(float data){
    char string[20];
    sprintf(string, "%f", data);
    unsigned int index = 0;
    while(string[index] != 0x00){
        sendUART(string[index]);
        ++index;
    }
    
    sendUART(endl[0]);
}

unsigned char receiverUART(){
    unsigned char receiverData;
    TXSTAbits.SYNC=0; // 
    RCSTAbits.SPEN = 1;
    RCSTAbits.CREN = 1;
    while(!PIR1bits.RCIF); // 
    receiverData = RCREG;
    return receiverData;  
}

