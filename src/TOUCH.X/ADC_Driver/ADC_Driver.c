#include "ADC_Driver.h"

void initADC() {
    // setup adc
    ADCON1bits.PWRLVL = 1;
    ADCON1bits.FORM = 0;

    // reference voltages
    ADCON2bits.PVCFG = 0;
    ADCON2bits.NVCFG = 0;

    ADCON3bits.ADRC = 0;   // use system clock
    ADCON3bits.ADCS = 0b1; // 8 Mhz Prescaler

    ADCON2bits.BUFORG = 1; // organize buffer 

    // sample list
    ADL0CONHbits.SAMC = 1;
    ADL0CONLbits.SLTSRC = 0;
    ADL0PTR = 0;                // start the data pointer at zero

    ADL0CONHbits.CM = 0;

    ADCON1bits.ADON = 1;             // Enable A/D.
    while(ADSTATHbits.ADREADY == 0); // Wait for ready flag set.
    ADCON1bits.ADCAL = 1;            // Start calibration.
    while(ADSTATHbits.ADREADY == 0); // Wait for ready flag set.
    ADL0CONLbits.SAMP = 1;           // Close sample switch.
    ADL0CONLbits.SLEN = 1;           // enable the list
}

void initOnboardVoltADC() {
    // setup pins
    // analog
    ANSBbits.ANSB1 = 1;
    ANSBbits.ANSB6 = 1;

    // input
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB6 = 1;

    ADL0CONHbits.SLINT = 1;     // isr after auto scan complete
    ADL0CONHbits.ASEN = 1;      // auto scan
    ADL0CONLbits.SLSIZE = 2-1;  // size of list two
    ADTBL0bits.ADCH = VBAT_ADC; // set channel for vbat to list 0
    ADTBL1bits.ADCH = IN1_ADC;  // set channel for iin1 to list 1
}

void initTouchADC() {
    _AD1IE = 1;
    // setup pins
    // analog
    ANSFbits.ANSF3  = 1;
    ANSFbits.ANSF4  = 1;
    ANSBbits.ANSB13 = 1;
    ANSBbits.ANSB15 = 1;

    // input
    TRISFbits.TRISF3  = 1;
    TRISFbits.TRISF4  = 1;
    TRISBbits.TRISB13 = 1;
    TRISBbits.TRISB15 = 1;

    // setup the adc
    ADL0CONLbits.SAMP = 0; // open sample switch.
    ADL0CONHbits.ASEN = 0; // wait for a trigger
    ADL0CONHbits.SLINT = 0b10; // isr after all channels in list are complete
    ADL0CONLbits.SLTSRC = 0b00110; // CTMU as trigger source

    // setup list
    ADL0CONLbits.SLSIZE = 1-1;  // size of list four
    ADTBL0bits.UCTMU = 1;
    // ADTBL1bits.UCTMU = 1;
    // ADTBL2bits.UCTMU = 1;
    // ADTBL3bits.UCTMU = 1;
    ADTBL0bits.ADCH = PAD1_ADC;
    // ADTBL1bits.ADCH = PAD2_ADC;
    // ADTBL2bits.ADCH = PAD3_ADC;
    // ADTBL3bits.ADCH = PAD4_ADC;
}

void getPadStates(pad_storage_t *storage) {
    storage->pad1 = ADRES0;
    storage->pad2 = ADRES1;
    storage->pad3 = ADRES2;
    storage->pad4 = ADRES3;
}

unsigned int readChannel(uint8_t channel) {
    unsigned int result;
    // clear the isr flag from before
    _AD1IF = 0;
    // open sample switch
    ADL0CONLbits.SAMP = 0;
    while(!_AD1IF) {}; // wait till ready
    
    // close sample switch again
    ADL0CONLbits.SAMP = 1;

    // return the result
    if(channel == VBAT_ADC) {
        result = ADRES0;
    } else {
        result = ADRES1;
    }

    return result;
}

void readBothChannels(adc_storage_t *storage) {
    _AD1IF = 0;
    ADL0CONLbits.SAMP = 0;
    while(!_AD1IF) {};

    ADL0CONLbits.SAMP = 1;
    storage->vbat = ADRES0;
    storage->iin = ADRES1;
}

unsigned int rawToVoltage(unsigned int input) {
    return ((input / 4096.0) * 3300); 
}