#include "UART_Driver.h"

uint8_t tempBuf[10];

void initUART(uint32_t baudrate, uint32_t chipFreq) {
    // peripheral pin mapping -----------------------------------------------
	__builtin_write_OSCCONL(OSCCON&~0x0040);	// unlock registers


	// RX should be RP17
    ANSFbits.ANSF5 = 0;
    RPINR18bits.U1RXR = 17;
    // TX should be RP14
    RPOR7bits.RP14R = 3; // 3 is mode UART 1 TX

	__builtin_write_OSCCONL(OSCCON|0x0040);		// lock registers

    // config
    _U1RXIE = 1; // enable the interrupt
    _U1TXIE = 1; //
    U1MODEbits.UARTEN = 0b1; // enable
    U1MODEbits.BRGH = 0b1; // high speed
    U1MODEbits.STSEL = 0b0; // one stop bit
    U1MODEbits.PDSEL = 0b00; // no parity
    U1STAbits.UTXEN = 0b1; // enable transmits
    U1STAbits.URXISEL = 0b0; // trigger isr when data is here
    
    // set the baudrate
    float brgVal = (((chipFreq / 1.0) / (4 * (baudrate / 1.0))) - 1);
    U1BRG = round(brgVal);
}

void sendUART1(uint8_t data) {
    if(U1STAbits.UTXBF != 1) { // transmit buffer is not full
        U1TXREG = data;
    }
}

uint8_t receiveUART() {
    if(U1STAbits.URXDA == 0b1) {
        return U1RXREG;
    } else {
        return 0x0;
    }
}

void receiveBytesBlocking(uint8_t *buf, uint32_t byteCount) {
    for(int i = 0; i < byteCount; i++) {
        // first wait till we have data
        while(U1STAbits.URXDA != 0b1);

        buf[i] = U1RXREG;
    }
}

void sendBytesBlocking(uint8_t *buf, uint32_t byteCount) {
    for(int i = 0; i < byteCount; i++) {
        while(U1STAbits.UTXBF == 1); // wait till there is space in buffer

        U1TXREG = buf[i];
    }
}

void transmitDataToPcTool(unsigned int *channels, uint8_t channel_count) {
    // start the transmission
    tempBuf[0] = 0xFF;
    tempBuf[1] = 0xFF;
    sendBytesBlocking(tempBuf, 2);

    // send over channel information
    uint8_t j = 0;
    for(int i = 0; i < channel_count*2; i+=2) {
        tempBuf[i] = channels[j] & 0xFF; // low byte
        tempBuf[i+1] = (channels[j] >> 8) & 0xFF; // high byte
        j++;
    }

    sendBytesBlocking(buf, 2*channel_count);
}