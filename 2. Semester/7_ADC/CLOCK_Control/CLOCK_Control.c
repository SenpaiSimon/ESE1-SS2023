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

    // ACLK -- should be crystal
    // enable osc pins to work
    PJSEL0 |= BIT4 | BIT5;
    // setup clocks
    CSCTL2 &= ~(SELA_7); // clear all for ACLK
    CSCTL2 |= SELA__LFXTCLK; // ACLK source is LFXT
    CSCTL3 &= ~(DIVA__32); // reset all bits
    CSCTL3 |= (DIVA__1); // divider to 1 --> erata s.106

    // SMCLK
    CSCTL2 &= ~(SELS_7); // clear all for SMCLK
    CSCTL2 |= (SELS_4); // set source to DCO --> erata s.105
    CSCTL3 &= ~(DIVS__32); // divider to 1 --> erata s.106
    //CSCTL3 |= (DIVS_5); // divider to 16 --> 8Mhz/16 = 500khz
    CSCTL3 |= (DIVS_4); // divider to 8 --> 8Mhz/8 = 1Mhz

    // MCLK
    CSCTL2 &= ~(SELM_7); // clear all for MCLK
    CSCTL2 |= (SELM_4); // set source to DCO --> erata s.105
    CSCTL3 &= ~(DIVM__32); // divider to 1 --> erata s.106
    //CSCTL3 |= (DIVM_1); // divider to 2 --> 8Mhz/2 = 4Mhz
    CSCTL3 |= (DIVM_4); // divider to 2 --> 8Mhz/8 = 1Mhz
}


void initRTC() {
    RTCCTL01 = RTCTEVIE | RTCBCD | RTCHOLD | RTCTEV__MIN;
    // enable rtc, bcd mode, hold, read ready ir, time event ir, minute event ir

    // set current clock 08.11.2023 - 10:00:40 --> so we can wake up on Minute changed after 20s
    RTCYEAR = 0x2023;
    RTCMON = 0x11;
    RTCDAY = 0x08;
    RTCDOW = 0x03;
    RTCHOUR = 0x10;
    RTCMIN = 0x00;
    RTCSEC = 0x40;

        
    RTCPS1CTL |= RT1PSIE;
    // enable prescaler ir in stage 1

    // clock source for second stage is first prescaler stage
    RTCPS1CTL |= (BITE + BITF); 
    RTCPS1CTL |= RT1IP__32; // isr prescaler also set to 2^5 --> should be 4Hz

    // start RTC
    RTCCTL01 &= ~(RTCHOLD);
}
