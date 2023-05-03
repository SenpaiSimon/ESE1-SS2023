#include "UART_Driver.h"

void initUART(uint32_t baudrate, uint32_t chipFreq) {
    // peripheral pin mapping -----------------------------------------------
	__builtin_write_OSCCONL(OSCCON&~0x0040);	// unlock registers

	// RX should be RP17
    RPINR18bits.U1RXR = 17;
    // TX should be RP14
    RPOR7bits.RP14R = 3; // 3 is mode UART 1 TX

	__builtin_write_OSCCONL(OSCCON|0x0040);		// lock registers

    // config
    U1MODEbits.UARTEN = 0b1; // enable
    U1MODEbits.BRGH = 0b1; // high speed
    U1MODEbits.STSEL = 0b0; // one stop bit
    U1MODEbits.PDSEL = 0b00; // no parity
    U1STAbits.UTXEN = 0b1; // enable transmits
    U1STAbits.URXISEL = 0b0; // trigger isr when data is here

    
    // set the baudrate
    U1BRG = (((chipFreq / 1.0) / (4 * (baudrate / 1.0))) - 1);
}

void sendUART1(uint8_t data) {
    if(U1STAbits.UTXBF != 1) { // transmit buffer is not full
        U1TXREG = data;
    }
}

uint8_t receiveUART() {
    if(U1STAbits.URXDA == 0b1) {
        return U1RXREG;
    }
}