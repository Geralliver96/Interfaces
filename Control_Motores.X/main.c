/*
 * File:   arduinoFuntions.c
 * Author: gustavomendoza
 *
 * Created on June 12, 2023, 10:04 PM
 */


#include <xc.h>
#include"../include/main.h"

int i =0;
float Temperatura;
void setup(void){
    setupUART(XTAL_20MHz,BAUD_RATE_115200);
    initADC(ADC_XTAL_20MHz,14);
    LATD = 0x00;
    PORTD = 0x00;
    TRISD = 0x00;
}

void loop(void){
    
    i = readADC(AN0);
    Temperatura = (100.0*i*5.0)/1023;
    printUART("Valor de lectura: ");
    printUARTInt(i);
    printUART(" Temperatura: ");
    printUARTfloatln(Temperatura);
    LATD = ADRESL;
}