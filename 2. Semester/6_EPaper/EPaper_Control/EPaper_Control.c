/*
 * EPaper_Control.c
 *
 *  Created on: 29.11.2023
 *      Author: cosmo
 */


#include "EPaper_Control.h"

DISP_STATE_t *localState;
const uint8_t numberLookup[] = {_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _A, _B, _C, _D, _E, _F};

void initEpaper(DISP_STATE_t *state) {
    localState = state;
    localState->ones.value = numberLookup[0];
    localState->tens.value = numberLookup[0];
    localState->hundred.value = numberLookup[0];
    localState->dp1 = false;
    localState->dp2 = false;
    localState->percent = false;

    // GPIO Dirs Setup
    P1DIR |= BIT0 | BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7;
    P2DIR |= BIT0 | BIT1 | BIT2;
    P3DIR |= BIT0 | BIT1 | BIT2 | BIT3 | BIT4;
    PJDIR |= BIT1 | BIT2 | BIT3 | BIT4 | BIT5 | BIT6 | BIT7;
    P4DIR |= BIT0 | BIT1 | BIT4 | BIT5 | BIT6 | BIT7;
}

void epaperShow() {
    epaperClear();
     a1(localState->ones.bits.a);
     a3(localState->ones.bits.b);
     a5(localState->ones.bits.c);
     a7(localState->ones.bits.d);
     a9(localState->ones.bits.e);
    a11(localState->ones.bits.f);
    a13(localState->ones.bits.g);
     b1(localState->tens.bits.a);
     b3(localState->tens.bits.b);
     b5(localState->tens.bits.c);
     b7(localState->tens.bits.d);
     b9(localState->tens.bits.e);
    b11(localState->tens.bits.f);
    b13(localState->tens.bits.g);
     c1(localState->hundred.bits.a);
     c3(localState->hundred.bits.b);
     c5(localState->hundred.bits.c);
     c7(localState->hundred.bits.d);
     c9(localState->hundred.bits.e);
    c11(localState->hundred.bits.f);
    c13(localState->hundred.bits.g);
    percent(localState->percent);
    dp1(localState->dp1);
    dp2(localState->dp2);

    _delay_cycles(DEFAULT_DELAY);

     a1(0);
     a3(0);
     a5(0);
     a7(0);
     a9(0);
    a11(0);
    a13(0);
     b1(0);
     b3(0);
     b5(0);
     b7(0);
     b9(0);
    b11(0);
    b13(0);
     c1(0);
     c3(0);
     c5(0);
     c7(0);
     c9(0);
    c11(0);
    c13(0);
    percent(0);
    dp1(0);
    dp2(0);
}

void setNumber(uint32_t number) {
    uint32_t localNumber = number;
    uint8_t temp;

    temp = localNumber / 100;
    localState->hundred.value = numberLookup[temp];
    localNumber -= temp * 100;

    temp = localNumber / 10;
    localState->tens.value = numberLookup[temp];
    localNumber -= temp * 10;

    localState->ones.value = numberLookup[localNumber];

    epaperShow();
}

void setMisc(bool dp1, bool dp2, bool percent) {
    localState->dp1 = dp1;
    localState->dp2 = dp2;
    localState->percent = percent;
}

void epaperClear() {
    // segments to zero
    P1OUT &= ~(BIT3 | BIT4 | BIT5 | BIT6 | BIT7);
    P2OUT &= ~(BIT0 | BIT1 | BIT2);
    P3OUT &= ~(BIT0 | BIT1 | BIT2 | BIT3 | BIT4);
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

void      a1(int x) {if(x == 1) {P3OUT |= BIT1;} else {P3OUT &= ~BIT1;}}
void      a3(int x) {if(x == 1) {P3OUT |= BIT2;} else {P3OUT &= ~BIT2;}}
void      a5(int x) {if(x == 1) {P3OUT |= BIT3;} else {P3OUT &= ~BIT3;}}
void      a7(int x) {if(x == 1) {P4OUT |= BIT7;} else {P4OUT &= ~BIT7;}}
void      a9(int x) {if(x == 1) {P1OUT |= BIT4;} else {P1OUT &= ~BIT4;}}
void     a11(int x) {if(x == 1) {P1OUT |= BIT5;} else {P1OUT &= ~BIT5;}}
void     a13(int x) {if(x == 1) {PJOUT |= BIT0;} else {PJOUT &= ~BIT0;}}
void      b1(int x) {if(x == 1) {PJOUT |= BIT2;} else {PJOUT &= ~BIT2;}}
void      b3(int x) {if(x == 1) {PJOUT |= BIT3;} else {PJOUT &= ~BIT3;}}
void      b5(int x) {if(x == 1) {P4OUT |= BIT0;} else {P4OUT &= ~BIT0;}}
void      b7(int x) {if(x == 1) {P4OUT |= BIT1;} else {P4OUT &= ~BIT1;}}
void      b9(int x) {if(x == 1) {P2OUT |= BIT0;} else {P2OUT &= ~BIT0;}}
void     b11(int x) {if(x == 1) {P2OUT |= BIT1;} else {P2OUT &= ~BIT1;}}
void     b13(int x) {if(x == 1) {P2OUT |= BIT2;} else {P2OUT &= ~BIT2;}}
void      c1(int x) {if(x == 1) {P3OUT |= BIT5;} else {P3OUT &= ~BIT5;}}
void      c3(int x) {if(x == 1) {P3OUT |= BIT6;} else {P3OUT &= ~BIT6;}}
void      c5(int x) {if(x == 1) {P3OUT |= BIT7;} else {P3OUT &= ~BIT7;}}
void      c7(int x) {if(x == 1) {P1OUT |= BIT6;} else {P1OUT &= ~BIT6;}}
void      c9(int x) {if(x == 1) {P1OUT |= BIT7;} else {P1OUT &= ~BIT7;}}
void     c11(int x) {if(x == 1) {P4OUT |= BIT4;} else {P4OUT &= ~BIT4;}}
void     c13(int x) {if(x == 1) {P4OUT |= BIT5;} else {P4OUT &= ~BIT5;}}
void percent(int x) {if(x == 1) {P4OUT |= BIT6;} else {P4OUT &= ~BIT6;}}
void     dp1(int x) {if(x == 1) {PJOUT |= BIT1;} else {PJOUT &= ~BIT1;}}
void     dp2(int x) {if(x == 1) {P3OUT |= BIT4;} else {P3OUT &= ~BIT4;}}
