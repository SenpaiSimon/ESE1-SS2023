/*
 * EPaper_Control.c
 *
 *  Created on: 29.11.2023
 *      Author: cosmo
 */


#include "EPaper_Control.h"

void initEpaper() {
    // GPIO Dirs Setup
    P1DIR |= BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7;
    P2DIR |= BIT0 | BIT1 | BIT2;
    P3DIR |= BIT0 | BIT1 | BIT2 | BIT3;
    PJDIR |= BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7;
    P4DIR |= BIT0 | BIT1 | BIT4 | BIT5 | BIT6 | BIT7;
}

void epaperShow() {
    P4OUT |= BIT6;

    _delay_cycles(DEFAULT_DELAY);
    P4OUT &= ~BIT6;
}

void epaperClear() {
    // segments to zero
    P1OUT &= ~(BIT3 | BIT4 | BIT5 | BIT6 | BIT7);
    P2OUT &= ~(BIT0 | BIT1 | BIT2);
    P3OUT &= ~(BIT0 | BIT1 | BIT2 | BIT3);
    PJOUT &= ~(BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7);
    P4OUT &= ~(BIT0 | BIT1 | BIT4 | BIT5 | BIT6 | BIT7);

    // top el control
    P1OUT &= ~BIT0;
    TopE_high;
    _delay_cycles(10000);
    P1OUT |= BIT0;
    _delay_cycles(DEFAULT_DELAY);

    TopE_low;
}
