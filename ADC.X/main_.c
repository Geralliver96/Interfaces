/*
 * File:   main_.c
 * Author: gerar
 *
 * Created on 5 de octubre de 2023, 09:52 PM
 */


#include <xc.h>
#include"configuracionBits.h"
#include"main.h"

void main(void) {
    setup();
    while(1){
        loop();
    }
    return;
}
