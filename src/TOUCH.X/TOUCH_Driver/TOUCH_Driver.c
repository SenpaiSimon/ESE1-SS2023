#include "TOUCH_Driver.h"

void initTouchDriver() {
    // CTMU module

    //enable
    CTMUCON1bits.CTMUEN = 1;

    // dont block edges
    CTMUCON1bits.EDGEN = 1;

    // edge1 must come before edge2
    CTMUCON1bits.EDGSEQEN = 1;

    // enable trigger output
    CTMUCON1bits.CTTRIG = 1;

    // OC1 as edge source
    CTMUCON2bits.EDG1SEL = 0b1;
    CTMUCON2bits.EDG2SEL = 0b1;

    // edge sense mode
    CTMUCON2bits.EDG1MOD = 1;
    CTMUCON2bits.EDG2MOD = 1;

    // polarity
    CTMUCON2bits.EDG1POL = 1;
    CTMUCON2bits.EDG2POL = 0;

    // current of source 1000 * base
    CTMUICONbits.IRNG = 0;


    // output compare module

    // double edge compare mode
    OC1CON1bits.OCM = 0b101;

    // timer2 as source
    OC1CON1bits.OCTSEL = 0;  

    // sync with source
    OC1CON2bits.OCTRIG = 0;  

    // setup compare bounds after 1/3 and 2/3 of timer counter
    OC1R  = (unsigned int)((1/3.0) * (65535));
    OC1RS = (unsigned int)((2/3.0) * (65535));
}
