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
#include <math.h>

/*!
 * @brief init the uart1 interface
 * @param baudrate baudrate for the uart
 * @param chipFreq the frequency of Fcyc
 */
void initUART(uint32_t baudrate, uint32_t chipFreq);

/*!
 * @brief send data over uart1
 * @param data data to send over uart 
 */
void sendUART1(uint8_t data);

/*!
 * @brief Get data from the uart1 buffer
 * @return the contents of buffer
 */
uint8_t receiveUART();

/*!
 * @brief send data over uart1 blocking
 * @param buf buffer with data to send
 * @param byteCount how many bytes to send from buf
 */
void receiveBytesBlocking(uint8_t *buf, uint32_t byteCount);

/*!
 * @brief init the uart1 interface
 * @param buf buffer which will be filled
 * @param byteCount how many bytes should be read into buf
 */
void sendBytesBlocking(uint8_t *buf, uint32_t byteCount);

#ifdef	__cplusplus
}
#endif

#endif	/* UART_DRIVER_H */

