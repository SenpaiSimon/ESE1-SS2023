/*
 * CLOCK_Control.c
 *
 *  Created on: 11.10.2023
 *      Author: cosmo
 */

#include "CLOCK_Control.h"

void initClocks() {
    // unlock clocks --> erata s.104
    CSCTL0_H = CSKEY_H;

    // setup DCO freq
    CSCTL1 &= ~(DCOFSEL_7); // reset
    CSCTL1 |= (DCOFSEL_6); // set DCO freq to 8mhz --> erata s.104
    CSCTL1 |= DCORSEL; // set bit6 --> get 8mhz from dco

    // ACLK
    CSCTL2 &= ~(SELA_7); // clear all for ACLK
    CSCTL2 |= SELA_2; // ACLK source is VLO --> erata s.105
    CSCTL3 &= ~(DIVA__32); // reset all bits
    CSCTL3 |= (DIVA_0); // divider to 1 --> erata s.106

    // SMCLK
    CSCTL2 &= ~(SELS_7); // clear all for SMCLK
    CSCTL2 |= (SELS_4); // set source to DCO --> erata s.105
    CSCTL3 &= ~(DIVS__32); // divider to 1 --> erata s.106
    //CSCTL3 |= (DIVS_5); // divider to 16 --> 8Mhz/16 = 500khz
    CSCTL3 |= (DIVS_4); // divider to 16 --> 8Mhz/8 = 1Mhz

    // MCLK
    CSCTL2 &= ~(SELM_7); // clear all for MCLK
    CSCTL2 |= (SELM_4); // set source to DCO --> erata s.105
    CSCTL3 &= ~(DIVM__32); // divider to 1 --> erata s.106
    //CSCTL3 |= (DIVM_1); // divider to 2 --> 8Mhz/2 = 4Mhz
    CSCTL3 |= (DIVM_4); // divider to 2 --> 8Mhz/8 = 1Mhz
}
