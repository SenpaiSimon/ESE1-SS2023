/* 
 * File:   UART_Driver.h
 * Author: cosmo
 *
 * Created on 3. Mai 2023, 16:01
 */

#ifndef UART_DRIVER_H
#define	UART_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <stdbool.h>
#include <stdio.h>

void initUART(uint32_t baudrate, uint32_t chipFreq);
void sendUART1(uint8_t data);
uint8_t receiveUART();

#ifdef	__cplusplus
}
#endif

#endif	/* UART_DRIVER_H */

