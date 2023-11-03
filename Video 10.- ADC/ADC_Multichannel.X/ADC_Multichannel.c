#pragma config PLLDIV = 2, CPUDIV = OSC1_PLL2, USBDIV = 2
#pragma config FOSC = HSPLL_HS, FCMEN = OFF, IESO = OFF
#pragma config PWRT = OFF, BOR = OFF, BORV = 3, VREGEN = OFF
#pragma config WDT = OFF
#pragma config WDTPS = 32768
#pragma config CCP2MX = ON, PBADEN = OFF, LPT1OSC = OFF, MCLRE = ON
#pragma config STVREN = ON, LVP = OFF, ICPRT = OFF, XINST = OFF
#pragma config CP0 = OFF, CP1 = OFF, CP2 = OFF, CP3 = OFF
#pragma config CPB = OFF, CPD = OFF
#pragma config WRT0 = OFF, WRT1 = OFF, WRT2 = OFF, WRT3 = OFF
#pragma config WRTC = OFF, WRTB = OFF, WRTD = OFF
#pragma config EBTR0 = OFF, EBTR1 = OFF, EBTR2 = OFF, EBTR3 = OFF
#pragma config EBTRB = OFF

#define _XTAL_FREQ 48000000
#include <xc.h>
#include <stdio.h>

#include "adc.h"                        // Libreria para el manejo del ADC
#include "lcd.h"                        // Libreria para el control de la pantalla LCD

char buffer[20];

void main()
{
    ADC_Init(AN0_TO_AN2_ANALOG);        // Inicializa el ADC
    Lcd_Init();                         // Inicializa la pantalla LCD
    
    while(1)
    {
        int valor_ch0 = ADC_Read(0);    // Lectura del canal 0
        int valor_ch1 = ADC_Read(1);    // Lectura del canal 1
        int valor_ch2 = ADC_Read(2);    // Lectura del canal 2
        
        Lcd_Set_Cursor(1,1);
        sprintf(buffer, "ADC Canal 0: %u   ", valor_ch0);
        Lcd_Write_String(buffer);
        
        Lcd_Set_Cursor(2,1);
        sprintf(buffer, "ADC Canal 1: %u   ", valor_ch1);
        Lcd_Write_String(buffer);
        
        Lcd_Set_Cursor(3,1);
        sprintf(buffer, "ADC Canal 2: %u   ", valor_ch2);
        Lcd_Write_String(buffer);
        __delay_ms(150);
    }
}