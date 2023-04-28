#include "DAC_Driver.h"

uint32_t fsample = 22050;

double sawToothIncrement;
double sineIncrement;

unsigned int sawBufferSize = 0;
unsigned int *sawBuffer;

unsigned int sineBufferSize = 0;
unsigned int *sineBuffer;

void initDacDriver(void) {
    // shutdown pin
    ANSBbits.ANSB12 = 0; // digital
    TRISBbits.TRISB12 = 0; // output
    ODCBbits.ODB12 = 1; // open drain
    PORTBbits.RB12 = 1; // first toggle off

    // dac setup
    DAC1CONbits.DACEN = 1; // enable 
    DAC1CONbits.DACREF = 0b10; // AVDD ref

    // dma setup channel 0
    DMACONbits.DMAEN = 1; // enable DMA

    // setup dma channel 0
    DMACH0bits.CHEN = 0; // disable it first
    DMACH0bits.TRMODE = 0b01; // repeated one-shot
    DMACH0bits.SIZE = 0; // 16 bits data
    DMACH0bits.DAMODE = 0b00; // destination needs to be untouched
    DMACH0bits.SAMODE = 0b01; // source will be incremented
    DMACH0bits.RELOAD = 0b1;

    // interrupt triggers
    DMAINT0bits.CHSEL = 0b110101; // timer 2 as trigger source

    // look up table
}

void speakerOn(bool on) {
    PORTBbits.RB12 = (on ? 0 : 1);
} 

void setupDMA0(unsigned int *destination, unsigned int *source, uint32_t elementCount) {
    DMASRC0 = (unsigned int)source;
    DMADST0 = (unsigned int)destination;
    DMAL = (unsigned int)source;
    DMAH = (unsigned int)source + elementCount * sizeof(unsigned int);
    DMACNT0 = elementCount; // how much data our buffer will have --> buffer entry count
}

void generateSawToothBufferAndStart(uint32_t sampleFreq, uint32_t desiredFreq, uint32_t peak) {
    // stop it
    DMACH0bits.CHEN = 0;
    
    free(sawBuffer);
    
    startStopTimer2(false);
    initTimer2(16000000, sampleFreq, true);
    startStopTimer2(true);

    // protect adc module
    if(peak > 1024) { peak = 1024; }
    
    sawToothIncrement = (peak * desiredFreq) / (sampleFreq / 1.0);
    sawBufferSize = (unsigned int)(peak / sawToothIncrement);
    sawBuffer = (unsigned int*)calloc(sizeof(unsigned int), sawBufferSize);

    setupDMA0((unsigned int*)&DAC1DAT, sawBuffer, sawBufferSize);

    // generate the wave
    sawBuffer[0] = 0; 
    for(int i = 1; i < sawBufferSize; i++) {
        sawBuffer[i] = sawBuffer[i-1] + sawToothIncrement;
    }

    // start it
    DMACH0bits.CHEN = 1;
}

void generateSineBufferAndStart(uint32_t sampleFreq, uint32_t desiredFreq, uint32_t peak) {
    // stop it
    DMACH0bits.CHEN = 0;

    free(sineBuffer);

    startStopTimer2(false);
    initTimer2(16000000, sampleFreq, true);
    startStopTimer2(true);

    // protect adc module
    if(peak > 1024) { peak = 1024; }

    sineIncrement = (peak * 2.0 * desiredFreq) / (sampleFreq / 1.0);
    sineBufferSize = (unsigned int)(peak / sineIncrement);
    sineBuffer = (unsigned int*)calloc(sizeof(unsigned int), sineBufferSize);

    setupDMA0((unsigned int*)&DAC1DAT, sineBuffer, sineBufferSize);

    for(int i = 0; i < sineBufferSize; i++) {
        sineBuffer[i] = peak * sin(i * ((2*3.1415)/sineBufferSize)) + peak;
    }

    DMACH0bits.CHEN = 1;
}
