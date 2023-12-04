

#ifndef ADC_HEADER_FILE_H
#define	ADC_HEADER_FILE_H

#include <pic18f4550.h>         /* Include PIC18F4550 header file */
#include "Configuration_header_file.h"  /* Include Configuration header file */

void ADC_Init();                /* ADC Initialize function */
int ADC_Read(char);             /* ADC Read function */


#endif	/* ADC_HEADER_FILE_H */

