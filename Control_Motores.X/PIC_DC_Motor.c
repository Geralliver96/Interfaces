

#include <math.h>
#include <stdio.h>
#include <pic18f4550.h>
#include "ADC_Header_File.h"
#include "Configuration_header_file.h"
#include"libuart4550.h"

#define MINTHR              8000
#define RESOLUTION          488

#define InternalOsc_8MHz    8000000
#define InternalOsc_4MHz    4000000
#define InternalOsc_2MHz    2000000
#define InternalOsc_1MHz    1000000
#define InternalOsc_500KHz  500000
#define InternalOsc_250KHz  250000
#define InternalOsc_125KHz  125000
#define InternalOsc_31KHz   31000

#define Timer2Prescale_1    1
#define Timer2Prescale_4    4
#define Timer2Prescale_16   16

#define _XTAL_FREQ 20000000

#define ENC_A PORTBbits.RB0 
#define ENC_B PORTBbits.RB1

 int contador_pulsos = 0;
 char current_A = 0;  
 char last_A = 0;
 int pulsos_vuelta = 374;
 int rpm = 0;


void MSdelay(unsigned int val)
{
 unsigned int i,j;
 for (i=0; i<=val; i++)
     for (j=0; j<165; j++); /* Delay count for 1ms for 8MHz freq. */
}

void PWM_Init()             /* Initialize PWM */
{
    TRISCbits.TRISC2 = 0;   /* Set CCP2 pin as output for PWM out */
    CCP1CON = 0x0C;         /* Set PWM mode */
}

int setPeriodTo(unsigned long FPWM)/* Set period */
{
    int clockSelectBits, TimerPrescaleBits;
    int TimerPrescaleValue;
    float period;
    unsigned long FOSC, _resolution = RESOLUTION;

    if (FPWM < MINTHR)    {TimerPrescaleBits = 2; TimerPrescaleValue = Timer2Prescale_16;}
    else                  {TimerPrescaleBits = 0; TimerPrescaleValue = Timer2Prescale_1;}

    if (FPWM > _resolution)               {clockSelectBits = 7; FOSC = InternalOsc_8MHz;}
    else if (FPWM > (_resolution >>= 1))  {clockSelectBits = 6; FOSC = InternalOsc_4MHz;}
    else if (FPWM > (_resolution >>= 1))  {clockSelectBits = 5; FOSC = InternalOsc_2MHz;}
    else if (FPWM > (_resolution >>= 1))  {clockSelectBits = 4; FOSC = InternalOsc_1MHz;}
    else if (FPWM > (_resolution >>= 1))  {clockSelectBits = 3; FOSC = InternalOsc_500KHz;}
    else if (FPWM > (_resolution >>= 1))  {clockSelectBits = 2; FOSC = InternalOsc_250KHz;}
    else if (FPWM > (_resolution >>= 1))  {clockSelectBits = 1; FOSC = InternalOsc_125KHz;}
    else                                  {clockSelectBits = 0; FOSC = InternalOsc_31KHz;}

    period = ((float)FOSC / (4.0 * (float)TimerPrescaleValue * (float)FPWM)) - 1.0;
    period = round(period);

    OSCCON = ((clockSelectBits & 0x07) << 4) | 0x02;
    PR2 = (int)period;
    T2CON = TimerPrescaleBits;
    TMR2 = 0;
    T2CONbits.TMR2ON = 1;  /* Turn ON Timer2 */
    return (int)period;
}


void SetDutyCycleTo(float Duty_Scale, int Period)/* Set Duty cycle for given period */
{
    int PWM10BitValue;
    
    PWM10BitValue = 4.0 * ((float)Period + 1.0) * (Duty_Scale/100.0);
    CCPR1L = (PWM10BitValue >> 2);
    CCP1CON = ((PWM10BitValue & 0x03) << 4) | 0x0C;
}

void configTimer0(void){

  TMR0IF = 0; // Limpiar bandera de interrupción 
  T0CONbits.TMR0ON = 1;
  T0CON = 0x00; // Timer0 apagado, modo temporizador 
  TMR0H = 0; // Clear registers  
  TMR0L = 0;
  // Configuración interrupción  
  INTCONbits.TMR0IE = 1; // Habilitar interrupción TMR0  
  INTCONbits.TMR0IF = 0; // Limpiar bandera
}

void configurar(void){
        
  INTCONbits.INT0IE = 1; // Habilitar int. RB0
  INTCONbits.INT0IF = 0;  // Limpiar bandera 
  TRISBbits.TRISB0 = 1; // RB0 como entrada
  INTCONbits.GIE = 1; // Habilitar int. globales
  INTCONbits.PEIE = 1;   
  INTCON2bits.INTEDG0 = 0; //External interrupt 0 edge, falling edge
}

void __interrupt() isr(void){
  if(INTCONbits.INT0IF){  
      contador_pulsos++;
    INTCONbits.INT0IF = 0; // Limpiar bandera         
  }
}

void main(void)
{
    float Duty_Scale;
    int Period;
    configTimer0(); 
    configurar();
    uartInit();
    char mensaje[] = "Verificacion comunicacion \n";
    
    TRISD = 0x00;           	/* PORTD as output */
    LATD0 = 0;              	/* Initial Direction */
    LATD1 = 1;
    ADC_Init();
    PWM_Init();             	/* Initialize PWM */
    
    Period = setPeriodTo(400000);/* 400KHz PWM frequency */
    /* Note that period step size will gradually increase with PWM frequency */
    
    float Kp=.02; //constante proporcional
    float Ki=0.7;//constante integrativa
    float Kd=0.00006; //constante derivativo
    int input=0; //intrada del PID-salida del ADC
    int offset=1023; //Referencia del ADC O valor esperado
    float Error =0;        //declaracion del error
    float Proporcional =0; 
    float Integral=0;
    float Derivativo=0;
    float T=0.054; //periodo de muestreo
    float Error_0=0;//error anterior
    float Error_1=0;//error anterior anterior
    float Control=0; //entrada al PWM salida del PID
    float Control_0; // Salida anterior
    float MaxIntegralError=120;
    float pwm_duty;
    float tiempo = 0.0000068;
    float rad;
    float RPM;

    while(1)
    {
        if(INTCONbits.T0IF){
            rad = contador_pulsos/pulsos_vuelta;
            RPM = rad/tiempo;
            contador_pulsos = 0;
            INTCONbits.T0IF = 0;      
        }
        //Duty_Scale = (((float)(ADC_Read(0)/4.0))/2.55); /* Scale Duty Cycle */
        Duty_Scale = (((float)(ADC_Read(2)))*340/1023); 
        input = Duty_Scale;
        Error = Duty_Scale - RPM;                 // Variable que guarda el error 
        Control = Control_0 + (Kp + Kd/tiempo)*Error + (-Kp + Ki*tiempo - 2*Kd/tiempo)*Error_0 + (Kd/tiempo)*Error_1;
        Control_0 = Control;
        Error_1 = Error_0;
        Error_0 = Error;    

        if(Control>500){   
            Control=500;
        }if(Control<30){   
            Control=30;
        }
        pwm_duty = ((int)Control*255.0/500.0);
        SetDutyCycleTo(Duty_Scale, Period);
        //printUARTfloatln(RPM);
        uartPrint(mensaje);
        
        sendUART("\n");
        __delay_ms(500);

   // T1CONbits.TMR0ON = 1;  
    //__delay_ms(1000);
    // Fórmula velocidad (pul/seg)
    //rpm = (contador_pulsos * 60) / pulsos_vuelta; 
   // contador_pulsos = 0;
    //T0CONbits.TMR0ON = 0;   
    }
}