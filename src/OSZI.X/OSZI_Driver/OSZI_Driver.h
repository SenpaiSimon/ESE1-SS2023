/* 
 * File:   OSZI_Driver.h
 * Author: cosmo
 *
 * Created on 7. Juni 2023, 16:11
 */

#ifndef OSZI_DRIVER_H
#define	OSZI_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif



#include <xc.h>
#include "../UART_Driver/UART_Driver.h"
#include "../ADC_Driver/ADC_Driver.h"


typedef union pga_instruction {
    struct bits {
        int indirect_addr : 1;
        int :4;
        int command_bytes : 3;
        int data : 8;
    } bits_t;
    unsigned int data;
}pga_instruction_t;

typedef enum od {
    HIZ,
    OD
} od_t;

void spiWrite(unsigned int *data, uint8_t dataCount);
void spiControlCS(od_t od);
void initSpi();
void initOszi();
void sendInstruction(pga_instruction_t *instruction);



#ifdef	__cplusplus
}
#endif

#endif	/* OSZI_DRIVER_H */

