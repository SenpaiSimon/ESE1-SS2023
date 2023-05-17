#include "ADC_Driver.h"

void initADC() {
    // setup pins
    // analog
    ANSBbits.ANSB1 = 1;
    ANSBbits.ANSB6 = 1;

    // input
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB6 = 1;


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
    ADL0CONLbits.SLSIZE = 2-1; // size of list two
    ADL0CONHbits.ASEN = 1;     // auto scan
    ADL0CONHbits.SLINT = 1;

    ADL0CONHbits.SAMC = 1;
    ADL0CONLbits.SLTSRC = 0;
    ADL0PTR = 0;                // start the data pointer at zero

    ADL0CONHbits.CM = 0;
    ADTBL0bits.ADCH = VBAT_ADC; // set channel for vbat to list 0
    ADTBL1bits.ADCH = IN1_ADC;  // set channel for iin1 to list 1

    ADCON1bits.ADON = 1;             // Enable A/D.
    while(ADSTATHbits.ADREADY == 0); // Wait for ready flag set.
    ADCON1bits.ADCAL = 1;            // Start calibration.
    while(ADSTATHbits.ADREADY == 0); // Wait for ready flag set.
    ADL0CONLbits.SAMP = 1;           // Close sample switch.
    ADL0CONLbits.SLEN = 1;           // enable the list
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

adc_storage_t readBothChannels() {
    adc_storage_t temp;

    _AD1IF = 0;
    ADL0CONLbits.SAMP = 0;
    while(!_AD1IF) {};

    ADL0CONLbits.SAMP = 1;
    temp.vbat = ADRES0;
    temp.iin = ADRES1;
}

unsigned int rawToVoltage(unsigned int input) {
    return ((input / 4096.0) * 3300); 
}