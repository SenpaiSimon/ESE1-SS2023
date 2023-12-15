/*
 * ADC_Control.c
 *
 *  Created on: 13.12.2023
 *      Author: cosmo
 */

#include "ADC_Control.h"


void initADC() {
    // init the pins
    // external is P1.3 A3
    P1SEL0 |= BIT3; // device datasheet s.88
    P1SEL1 |= BIT3;

    // -----------------------------------------------------------------------------
    // Reference Setup -------------------------------------------------------------
    // -----------------------------------------------------------------------------
    while(REFCTL0 & REFGENBUSY); // wait for reference generator
    REFCTL0 |= REFVSEL_1 | REFON; // REFVSEL_1 for 2.0V


    // -----------------------------------------------------------------------------
    // CONFIG ADC12 ----------------------------------------------------------------
    // -----------------------------------------------------------------------------
    ADC12CTL0 = ADC12SHT0_4 | ADC12SHT1_4 | ADC12ON; // sample for 32 cycles -- 32uS at 1Mhz Clock
    ADC12CTL1 = ADC12SSEL_3 | ADC12SHP; // smclk as source
    ADC12CTL2 |= ADC12RES_2; // 12 bit
    ADC12CTL3 |= ADC12TCMAP | ADC12BATMAP; // turn on internal sensors
    // ADC12IER0 |= ADC12IE0 | ADC12IE1 | ADC12IE2; // iinterrupts for all used channels
    ADC12IER0 |= ADC12IE2; // iinterrupt only when last channel is done --> then convert all the results at once


    // -----------------------------------------------------------------------------
    // channel setups --------------------------------------------------------------
    // -----------------------------------------------------------------------------
    // external clip is MEM0
    ADC12MCTL0 |= ADC12INCH_3 | ADC12VRSEL_1; // V+ = VREF | V- = AVSS | Channel A3
    // temperatur sens is MEM1
    ADC12MCTL1 |= ADC12INCH_30 | ADC12VRSEL_1;
    // vbat sens is MEM2
    ADC12MCTL2 |= ADC12INCH_31 | ADC12VRSEL_1 | ADC12EOS; // signal that this is end of sequence with ADC12EOS

    while(!(REFCTL0 | REFGENRDY)); // wait for reference generator
}

uint16_t readExternalInput() {
    // (2V * 100) / (2^12 - 1) = 0.049
    return (uint16_t)((long)ADC12MEM0 * 0.049f);
}

uint16_t readTemp() {
    return (uint16_t)(((((long)ADC12MEM1 - CALADC12_20V_30C) * (85 - 30)) /
           (CALADC12_20V_85C - CALADC12_20V_30C) + 30.0f) * 100);
}

uint16_t readAVCC() {
    return (uint16_t)((long)ADC12MEM2 * 0.049f);
}