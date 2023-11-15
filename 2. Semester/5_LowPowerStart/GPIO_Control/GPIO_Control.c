/*
 * GPIO_Control.c
 *
 *  Created on: 04.10.2023
 *      Author: cosmo
 */

#include "GPIO_Control.h"

void initGPIO() {
    PM5CTL0 &= ~LOCKLPM5;        // Disable the GPIO power-on default high-impedance mode
                                  // to activate previously configured port settings

    // ---------------- Onboard LEDs - PJ6 & PJ7 ---------------------------------------
    PJOUT &= ~(BIT6 + BIT7);        // Reset OUT state of the pins
    PJDIR |= BIT6 + BIT7;           // Set to outputs
}

inline void disableAllGPIO() {
    P1OUT = 0;
    P1DIR = 0xFF;

    // exception for nmos to avoid leaking current
    P1OUT |= BIT2;
    P1DIR |= BIT2;

    P2OUT = 0;
    P2DIR = 0xFF;

    P3OUT = 0;
    P3DIR = 0xFF;

    PJOUT = 0;
    PJDIR = 0xFFFF;
}

