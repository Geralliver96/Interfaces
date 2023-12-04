/*
 * File:   main.c
 * Author: gustavomendoza
 *
 * Created on June 12, 2023, 9:35 PM
 */


#include <xc.h>
#include"../include/USART18f4550.h"
#include"../include/main.h"


void main(void)
{
	setup();
	
	while(TRUE){
		loop();
	}
	
	return;
}
