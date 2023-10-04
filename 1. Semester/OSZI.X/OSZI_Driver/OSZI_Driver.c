#include "OSZI_Driver.h"

void spiControlCS(od_t od);
unsigned int spiBuffer[2];

oszi_config_t config;
uint8_t config_counter = 0;
uint8_t configBuffer[12];
pga_instruction_t instruction;

uint8_t adc_buffer[2 * 2048];
unsigned int osziSampleCount = 2048;

LCD_STATE_t *localLCD;

// --------------------------------------------------------------------------------------
// -------------------------------------------- CONF ------------------------------------
// --------------------------------------------------------------------------------------

oszi_config_t* getOsziConfig() {
    return &config;
}

void receiveOsziConfig() {
    // Mimic protocoll --> 0xFF - 0xFF - 'V' - data - 'H' - dataLow - dataHigh - 'T' - trigLow - trigHigh - trigMode - trigEdge
    receiveBytesBlocking(configBuffer, 12);

    // select the correct bytes ignoring control bytes
    config.vertical = configBuffer[3];
    config.tad_fak_low = configBuffer[5];
    config.tad_fak_high = configBuffer[6];
    config.trigger_low = configBuffer[8];
    config.trigger_high = configBuffer[9];
    config.trigger_mode = configBuffer[10];
    config.trigger_edge = configBuffer[11];

    setDigits(config.vertical, config.tad_fak_high, config.tad_fak_low, 0);
}

void sendOsziConfig() {
    sendBytesBlocking(configBuffer, 12);
}

// --------------------------------------------------------------------------------------
// -------------------------------------------- UART ------------------------------------
// --------------------------------------------------------------------------------------
void sendOsziDataToPC() {
    sendBytesBlocking(configBuffer, 12); // this already includes the two 0xFF sync bytes
    sendBytesBlocking(adc_buffer, 2 * osziSampleCount);
    // start dma for the rest

}


// --------------------------------------------------------------------------------------
// -------------------------------------------- SPI -------------------------------------
// --------------------------------------------------------------------------------------
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

// --------------------------------------------------------------------------------------
// -------------------------------------------- ADC -------------------------------------
// --------------------------------------------------------------------------------------
void initOsziADC() {
    initADC();
    
    // setup pins
    // analog
    ANSBbits.ANSB0 = 1;

    // input
    TRISBbits.TRISB0 = 1;

    // re-configure pre scaler for desired horizonal freq
    ADCON3bits.ADCS = (config.tad_fak_high << 8) | config.tad_fak_low;

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

void fill_adc_buffer() { // this makes the sending easier if we split it instantly
    unsigned int tempAnalogADC;
    for(int i = 0; i < osziSampleCount * 2; i+=2) {
        tempAnalogADC = getAnalogFrontADC();
        adc_buffer[i]   = tempAnalogADC & 0xFF; // low byte
        adc_buffer[i+1] = (tempAnalogADC >> 8) & 0xFF; // high byte
    }
}


// --------------------------------------------------------------------------------------
// -------------------------------------------- PGA -------------------------------------
// --------------------------------------------------------------------------------------
void sendInstruction(pga_instruction_t *instruction) {
    spiBuffer[0] = instruction->data;

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

void configurePGA() {
    instruction.bits_t.command_bytes = 0b010;
    instruction.bits_t.indirect_addr = 0;
    switch(config.vertical) {
        case 1:
            instruction.bits_t.data = 0b000;
        break;
        case 2:
            instruction.bits_t.data = 0b010;
        break;
        case 3:
            instruction.bits_t.data = 0b101;
        break;
        case 4:
            instruction.bits_t.data = 0b111;
        break;
        default:
            instruction.bits_t.data = 0b000;
    }

    sendInstruction(&instruction);
}


// --------------------------------------------------------------------------------------
// -------------------------------------------- INI -------------------------------------
// --------------------------------------------------------------------------------------

void initOszi() {
    localLCD = getLCDStorage();
    initSpi();
    receiveOsziConfig();

    configurePGA();
    initOsziADC();

    // initDMA0(0b110000); // uart 1 transmit isr as trigger
    // DMACH0bits.SIZE = 1; // for 8 bit operation
    // DMACH0bits.TRMODE = 0b10; // continuous mode --> do whole buffer

    // setupDMA0((unsigned int*)&U1TXREG, adc_buffer, 2 * osziSampleCount);
}