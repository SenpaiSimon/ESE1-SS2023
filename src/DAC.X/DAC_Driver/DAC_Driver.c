#include "DAC_Driver.h"

uint32_t sawToothFreq = 440;
uint32_t fsample = 22050;
uint32_t sawToothPeak = 256;

double increment;

void initDacDriver(void) {
    // set freq is 22050Hz --> 45,351uS
    // desired freq is 440Hz --> 2,27mS --> we want to count to 256 in that time
    // count time is --> 2,27mS/256 samples --> 8,87uS time to count per element
    // but we only trigger every 45uS so we need to count
    // 45,351uS / 8,87uS = 5.11 
    // counterVal = (1/fsample) / ((1/desiredFreq)/sampleCount)
    // simpliefied this means
    // counterVal = (desiredFreq * sampleCount) / fsample
    increment = (1.0 / ((fsample / (sawToothFreq/1.0)) / sawToothPeak));


    // shutdown pin
    ANSBbits.ANSB12 = 0; // digital
    TRISBbits.TRISB12 = 0; // output
    ODCBbits.ODB12 = 1; // open drain
    PORTBbits.RB12 = 1; // first toggle off

    // dac setup
    DAC1CONbits.DACEN = 1; // enable 
    DAC1CONbits.DACREF = 0b10; // AVDD ref

    // look up table


}

void speakerOn(bool on) {
    PORTBbits.RB12 = (on ? 0 : 1);
}   

void sawToothgenerator() {
    if(DAC1DAT > sawToothPeak) {
        DAC1DAT = 0;
    }

    DAC1DAT += (uint32_t)increment;
}
