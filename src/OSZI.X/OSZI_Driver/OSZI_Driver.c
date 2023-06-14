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

    _SPI1IE = 1;
    _SPI1IF = 0;

    SPI1STATbits.SISEL = 0b101;
    SPI1CON1bits.MSTEN = 1; // master mode
    SPI1CON1bits.MODE16 = 1; // 16 bit mode
    SPI1CON1bits.PPRE = 0b11;
    SPI1CON1bits.SPRE = 0b000;
    SPI1CON1bits.CKP = 0; // clock idle at low
    SPI1CON1bits.CKE = 1; // sample when toggling from idle clock to active clock
    SPI1STATbits.SPIROV = 0;
    SPI1CON2bits.SPIBEN = 1; // enhanced buffer mode
    SPI1STATbits.SPIEN = 1; // enable
}

void initOsziADC() {
    initADC();
    
    // setup pins
    // analog
    ANSBbits.ANSB0 = 1;

    // input
    TRISBbits.TRISB0 = 1;

    ADL0CONHbits.SLINT = 1;     // isr after auto scan complete
    ADL0CONHbits.ASEN = 1;      // auto scan
    ADL0CONLbits.SLSIZE = 1-1;  // size of list two
    ADTBL0bits.ADCH = ANALOG_FRONT_ADC; // set channel for vbat to list 0
}

unsigned int getAnalogFrontADC() {
    unsigned int result;
    _AD1IF = 0;
    ADL0CONLbits.SAMP = 0;
    while(!_AD1IF) {}; // wait till ready
    // close sample switch again
    ADL0CONLbits.SAMP = 1;

    result = ADRES0;
    return result;
}

void initOszi() {
    initSpi();
    initOsziADC();
}

void sendInstruction(pga_instruction_t *instruction) {
    spiBuffer[0] = instruction->data;
    // spiBuffer[0] = 0b0100000000000111;

    spiWrite(spiBuffer, 1);
}

void spiControlCS(od_t od) {
    LATEbits.LATE5 = (od == HIZ ? 1 : 0);
}

void spiWrite(unsigned int *data, uint8_t dataCount) {
    spiControlCS(OD);
    unsigned int dump;

    for(int i = 0; i < dataCount; i++) {
        // while(!(SPI1STATbits.SRMPT)); // wait when buffer is full

        SPI1BUF = data[i]; // send da data
        dump = SPI1BUF;
    }
}
