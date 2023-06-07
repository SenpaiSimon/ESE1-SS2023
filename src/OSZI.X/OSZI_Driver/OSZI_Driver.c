#include "OSZI_Driver.h"

void spiControlCS(od_t od);
unsigned int spiBuffer[2];

void initSpi() {
    // max 10MHz(we use 8MHz -- which is FCY) -- clock idle high -- sample on rising edge
    // CS at RE5

    // cs pin
    ANSEbits.ANSE5 = 0; // digital
    TRISEbits.TRISE5 = 0; // output
    ODCEbits.ODE5 = 1; // open-drain
    spiControlCS(HIZ);

    // spi itself
    __builtin_write_OSCCONL(OSCCON&~0x0040);	// unlock registers
    ANSBbits.ANSB5 = 0; // digital
    ANSBbits.ANSB4 = 0; // digital
    RPOR9bits.RP18R = 8; // RB5 should be spi 1 clock
    RPOR14bits.RP28R = 7; // RB4 should be spi 1 mosi
	__builtin_write_OSCCONL(OSCCON|0x0040);		// lock registers

    SPI1STATbits.SPIEN = 1; // enable
    SPI1CON1bits.MODE16 = 1; // 16 bit mode
    SPI1CON1bits.CKE = 0; // sample when toggling from idle clock to active clock
    SPI1CON1bits.CKP = 0; // clock idle at low
    SPI1CON1bits.MSTEN = 1; // master mode
    SPI1CON2bits.SPIBEN = 1; // enhanced buffer mode
}

void initOszi() {
    initSpi();
}

void sendInstruction(pga_instruction_t *instruction) {
    spiBuffer[0] = instruction->data;
    spiWrite(spiBuffer, 1);
}

void spiControlCS(od_t od) {
    LATEbits.LATE5 = (od == HIZ ? 0 : 1);
}

void spiWrite(unsigned int *data, uint8_t dataCount) {
    for(int i = 0; i < dataCount; i++) {
        while(SPI1STATbits.SPITBF); // wait when buffer is full

        SPI1BUF = data[i]; // send da data
    }
}
