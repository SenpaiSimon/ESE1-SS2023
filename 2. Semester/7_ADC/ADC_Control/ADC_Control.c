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


    // ADC STUFF
    while(REFCTL0 & REFGENBUSY); // wait for reference generator
    REFCTL0 |= REFVSEL_2 | REFON; // 2.5V and on -- REFVSEL_1 for 2.0V

    // CONFIG ADC12
    ADC12CTL0 = ADC12SHT0_4 | ADC12SHT1_4 | ADC12ON; // sample for 32 cycles -- 32uS at 1Mhz Clock
    ADC12CTL1 = ADC12SSEL_3 | ADC12SHP; // smclk as source
    ADC12CTL2 |= ADC12RES_2; // 12 bit
    ADC12IER0 |= ADC12IE0;

    ADC12MCTL0 |= ADC12INCH_3 | ADC12VRSEL_1; // V+ = VREF | V- = AVSS | Channel A3

    while(!(REFCTL0 | REFGENRDY)); // wait for reference generator
}

uint16_t readExternalInput() {
    ADC12CTL0 |= ADC12ENC | ADC12SC; // enable and start conversion
    while(ADC12CTL0 & ADC12BUSY); // wait till not busy anymore
    return ADC12MEM0;
}