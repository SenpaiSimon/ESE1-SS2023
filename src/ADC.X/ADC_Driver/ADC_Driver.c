#include "ADC_Driver.h"

void initADC() {
    // setup pins
    ANSBbits.ANSB1 = 1;
    ANSBbits.ANSB6 = 1;

    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB6 = 1;


    // setup adc
    ADCON1bits.PWRLVL = 1;
    ADCON1bits.FORM = 0;

    ADCON2bits.PVCFG = 0;
    ADCON2bits.NVCFG = 0;

    ADCON3bits.ADRC = 0;
    ADCON3bits.ADCS = 0b1; // 8 Mhz

    ADCON2bits.BUFORG = 1;

    // sample list
    ADL0CONLbits.SLSIZE = 2-1; // size two
    ADL0CONHbits.ASEN = 1;
    ADL0CONHbits.SLINT = 1;

    ADL0CONHbits.SAMC = 1;
    ADL0CONLbits.SLTSRC = 0;
    ADL0PTR = 0;

    ADL0CONHbits.CM = 0;
    ADTBL0bits.ADCH = VBAT_ADC;
    ADTBL1bits.ADCH = IN1_ADC;

    ADCON1bits.ADON = 1; // Enable A/D.
    while(ADSTATHbits.ADREADY == 0); // Wait for ready flag set.
    ADCON1bits.ADCAL = 1; // Start calibration.
    while(ADSTATHbits.ADREADY == 0);
    ADL0CONLbits.SAMP = 1; // Close sample switch.
    ADL0CONLbits.SLEN = 1;
}

unsigned int readChannel(uint8_t channel) {
    unsigned int result;
    _AD1IF = 0;
    ADL0CONLbits.SAMP = 0;
    while(!_AD1IF) {}; // wait while busy
    
    ADL0CONLbits.SAMP = 1;
    if(channel == VBAT_ADC) {
        result = ADRES0;
    } else {
        result = ADRES1;
    }

    return result;
}

unsigned int rawToVoltage(unsigned int input) {
    return ((input / 4096.0) * 3300); 
}