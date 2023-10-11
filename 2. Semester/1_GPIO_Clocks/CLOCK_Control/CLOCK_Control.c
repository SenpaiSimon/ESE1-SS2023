/*
 * CLOCK_Control.c
 *
 *  Created on: 11.10.2023
 *      Author: cosmo
 */

#include "CLOCK_Control.h"

void initClocks() {
    // unlock clocks --> erata s.104
    CSCTL0_H = 0xA5;

    // setup DCO freq
    CSCTL1 &= ~(BIT1 + BIT2 + BIT3); // reset
    CSCTL1 |= (BIT1 + BIT2); // set DCO freq to 4mhz --> erata s.104
    CSCTL1 |= BIT6; // reset bit6 --> get 4mhz from dco

    // ACLK
    CSCTL2 &= ~(BITA + BIT9 + BIT8); // clear all for ACLK
    CSCTL2 |= BIT8; // ACLK source is VLO --> erata s.105
    CSCTL3 &= ~(BITA + BIT9 + BIT8); // divider to 1 --> erata s.106

    // SMCLK
    CSCTL2 &= ~(BIT4 + BIT5 + BIT6); // clear all for SMCLK
    CSCTL2 |= (BIT4 + BIT5); // set source to DCO --> erata s.105
    CSCTL3 &= ~(BIT4 + BIT5 + BIT6); // divider to 1 --> erata s.106
    CSCTL3 |= (BIT6); // divider to 16 --> 8Mhz/16 = 500khz

    // MCLK
    CSCTL2 &= ~(BIT0 + BIT1 + BIT2); // clear all for MCLK
    CSCTL2 |= (BIT0 + BIT1); // set source to DCO --> erata s.105
    CSCTL3 &= ~(BIT0 + BIT1 + BIT2); // divider to 1 --> erata s.106
    CSCTL3 |= (BIT0); // divider to 2 --> 8Mhz/2 = 4Mhz
}
